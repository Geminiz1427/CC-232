#pragma once

#include <vector>
#include <list>              
#include <queue>              
#include <unordered_map>       

namespace pc2 {

struct Segment {
    int value;
    int length;
    int id;
};

// Retorna el numero de operaciones para vaciar el arreglo.
// En cada operacion se elimina el segmento mas largo
// (el mas a la izquierda en caso de empate).
int segments_removal(const std::vector<int>& arr);

} // namespace pc2