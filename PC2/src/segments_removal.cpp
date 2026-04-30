#include "segments_removal.h"
#include <list>
#include <queue>
#include <unordered_map>

namespace pc2 {

int segments_removal(const std::vector<int>& arr) {
    if (arr.empty()) return 0;

    // Comprime el arreglo en segmentos consecutivos.
    // Cada grupo de elementos iguales consecutivos forma un solo Segment.
    std::list<Segment> segs;
    int next_id = 0;

    for (int i = 0; i < (int)arr.size(); ) {
        int j = i;
        while (j < (int)arr.size() && arr[j] == arr[i]) ++j;
        segs.push_back({arr[i], j - i, next_id++});
        i = j;
    }
    /* Aun en desarrollo.
       Mapear id -> iterador para acceder a cualquier segmento en O(1)
       max-heap para seleccionar siempre el segmento mas largo
       Simulacion con fusion de vecinos
       Se implementará en el siguiente commit.*/

    return 0;
}

} // namespace pc2