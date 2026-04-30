#include "segments_removal.h"
#include <cassert>
#include <iostream>

using pc2::segments_removal;

void test_caso_vacio() {
    assert(segments_removal({}) == 0);
}

void test_un_elemento() {
    segments_removal({1});
}

void test_compresion_visible() {

    segments_removal({1, 1, 2, 2, 2, 1});
}

int main() {
    test_caso_vacio();
    test_un_elemento();
    test_compresion_visible();
    std::cout << "\nTests completados.\n";
    return 0;
}
