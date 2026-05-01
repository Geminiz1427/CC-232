#include "segments_removal.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// Genera un arreglo aleatorio de n elementos con valores entre 1 y k
std::vector<int> generar_arreglo(int n, int k, unsigned seed = 42) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, k);
    std::vector<int> arr(n);
    for (int& x : arr) x = dist(rng);
    return arr;
}

// Mide el tiempo de ejecucion de segments_removal en microsegundos
long long medir(const std::vector<int>& arr) {
    auto inicio = std::chrono::high_resolution_clock::now();
    pc2::segments_removal(arr);
    auto fin = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
}

int main() {
    std::cout << "Benchmark: Codeforces 899E - Segments Removal\n";
    std::cout << "----------------------------------------------\n\n";

    // Caso 1: pocos valores distintos (muchas fusiones)
    std::cout << "Caso: pocos valores distintos (k=3), muchas fusiones\n";
    for (int n : {1000, 10000, 50000, 100000}) {
        auto arr = generar_arreglo(n, 3);
        long long t = medir(arr);
        std::cout << "  n=" << n << " -> " << t << " us\n";
    }

    std::cout << "\n";

    // Caso 2: muchos valores distintos (pocas fusiones)
    std::cout << "Caso: muchos valores distintos (k=n), pocas fusiones\n";
    for (int n : {1000, 10000, 50000, 100000}) {
        auto arr = generar_arreglo(n, n);
        long long t = medir(arr);
        std::cout << "  n=" << n << " -> " << t << " us\n";
    }

    std::cout << "\n";

    // Caso 3: todos iguales (un solo segmento, 1 operacion)
    std::cout << "Caso: todos iguales (1 segmento, 1 operacion)\n";
    for (int n : {1000, 10000, 100000}) {
        std::vector<int> arr(n, 7);
        long long t = medir(arr);
        std::cout << "  n=" << n << " -> " << t << " us\n";
    }

    std::cout << "\n";

    // Caso 4: alternado 1,2,1,2,... (n segmentos, sin fusiones)
    std::cout << "Caso: alternado 1,2,1,2,... (maximo numero de segmentos)\n";
    for (int n : {1000, 10000, 100000}) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = (i % 2) + 1;
        long long t = medir(arr);
        std::cout << "  n=" << n << " -> " << t << " us\n";
    }

    return 0;
}