#include "segments_removal.h"
#include <iostream>
#include <vector>
#include <list>

void mostrar_segmentos(const std::vector<int>& arr) {
    std::cout << "Arreglo original: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Segmentos comprimidos:\n";
    int id = 0;
    for (int i = 0; i < (int)arr.size(); ) {
        int j = i;
        while (j < (int)arr.size() && arr[j] == arr[i]) ++j;
        std::cout << "  id=" << id++
                  << " value=" << arr[i]
                  << " length=" << (j - i) << "\n";
        i = j;
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> casos = {
        {13, 13, 7, 7, 7, 2, 2, 2},
        {4, 4, 4, 100, 100, 2, 2},
        {2, 2, 5, 5, 5, 2, 2, 2}
    };

    for (auto& arr : casos) {
        mostrar_segmentos(arr);
        std::cout << "Operaciones: " << pc2::segments_removal(arr) << "\n\n";
    }

    return 0;
}