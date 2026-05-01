#include "segments_removal.h"
#include <cassert>
#include <iostream>

using pc2::segments_removal;

void test_caso_vacio() {
    assert(segments_removal({}) == 0);
    std::cout << "segments_removal({}) == 0\n";
}

void test_un_elemento() {
    assert(segments_removal({5}) == 1);
    std::cout << "segments_removal({5}) == 1\n";
}

void test_todos_iguales() {
    assert(segments_removal({3, 3, 3, 3}) == 1);
    std::cout << "segments_removal({3, 3, 3, 3}) == 1\n";
}

void test_fusion_visible() {
    assert(segments_removal({1, 1, 2, 2, 2, 1}) == 2);
    std::cout << "segments_removal({1, 1, 2, 2, 2, 1}) == 2\n";
}

void test_ejemplo_enunciado1() {
    assert(segments_removal({13, 13, 7, 7, 7, 2, 2, 2}) == 3);
    std::cout << "segments_removal({13, 13, 7, 7, 7, 2, 2, 2}) == 3\n";
}

void test_empate_izquierda() {
    assert(segments_removal({1, 1, 2, 2, 3, 3}) == 3);
    std::cout << "segments_removal({1, 1, 2, 2, 3, 3}) == 3\n";
}

int main() {
    test_caso_vacio();
    test_un_elemento();
    test_todos_iguales();
    test_ejemplo_enunciado1();
    test_empate_izquierda();
    test_fusion_visible();
    std::cout << "\nTests completados.\n";
    return 0;
}
