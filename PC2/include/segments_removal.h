#pragma once

#include <vector>

namespace pc2 {

// Representa un segmento de elementos iguales consecutivos.
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