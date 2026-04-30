#pragma once

#include <vector>
#include <list>                 // para std::list (lista doblemente enlazada)
#include <queue>                // para std::priority_queue (max-heap)
#include <unordered_map>        // para mapear id 

namespace pc2 {

// Representa un segmento de elementos iguales consecutivos.

struct Segment {
    int value;      // Invariante: value es el mismo para todos los elementos del segmento.
    int length;     // length >= 1. id identifica univocamente este segmento.
    int id;
};

/* Retorna el numero de operaciones para vaciar el arreglo, en cada operacion se elimina el segmento mas largo
El mas a la izquierda en caso de empate.*/

int segments_removal(const std::vector<int>& arr);

} // namespace pc2