#include "segments_removal.h"
#include <list>
#include <queue>
#include <unordered_map>

namespace pc2 {

int segments_removal(const std::vector<int>& arr) {
    if (arr.empty()) return 0;

    // Comprimimos el arreglo en segmentos.
    // Donde cada grupo de elementos iguales consecutivos forma un solo Segment.
    std::list<Segment> segs;
    int next_id = 0;

    for (int i = 0; i < (int)arr.size(); ) {
        int j = i;
        while (j < (int)arr.size() && arr[j] == arr[i]) ++j;
        segs.push_back({arr[i], j - i, next_id++});
        i = j;
    }

    // mapear id -> iterador que nos permite acceder a cualquier segmento en O(1)  
    std::unordered_map<int, std::list<Segment>::iterator> iter_map;

    for (auto it = segs.begin(); it != segs.end(); ++it) {
      iter_map[it->id] = it;
    }
    // Prioridad al mayor length, mismo length entonces menor id gana (más a la izquierda)
    using Entry = std::pair<int, int>;
    
    auto cmp = [](Entry a, Entry b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    };

    std::priority_queue<Entry, std::vector<Entry>, decltype(cmp)> pq(cmp);

    for (auto& seg : segs) {
        pq.push({seg.length, seg.id});
    }
    int ops = 0;

    while (!pq.empty()) {
        auto [len, id] = pq.top();
        pq.pop();

        // Verifica que el segmento no esta vacio
        if (iter_map.find(id) == iter_map.end()) continue;
        auto it = iter_map[id];

        // Verifica que la longitud no cambio por una fusion anterior
        if (it->length != len) continue;

        // Obtiene vecinos antes de eliminar
        bool tiene_prev = (it != segs.begin());
        auto next_it = std::next(it);
        bool tiene_next = (next_it != segs.end());

        auto prev_it = tiene_prev ? std::prev(it) : segs.end();

        // Se elimina el segmento de la lista y del mapa
        iter_map.erase(id);
        segs.erase(it);
        ++ops;

        // Se fusionan los vecinos si tienen el mismo valor
        if (tiene_prev && tiene_next && prev_it->value == next_it->value) {
            prev_it->length += next_it->length;
            iter_map.erase(next_it->id);
            segs.erase(next_it);
            pq.push({prev_it->length, prev_it->id});
        }
    }   

    return ops;
}

} // namespace pc2