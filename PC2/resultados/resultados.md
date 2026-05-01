./build/demo_segments
Arreglo original: 13 13 7 7 7 2 2 2 
Segmentos comprimidos:
  id=0 value=13 length=2
  id=1 value=7 length=3
  id=2 value=2 length=3

Operaciones: 3

Arreglo original: 4 4 4 100 100 2 2 
Segmentos comprimidos:
  id=0 value=4 length=3
  id=1 value=100 length=2
  id=2 value=2 length=2

Operaciones: 3

Arreglo original: 2 2 5 5 5 2 2 2 
Segmentos comprimidos:
  id=0 value=2 length=2
  id=1 value=5 length=3
  id=2 value=2 length=3

Operaciones: 2

./build/test_segments
segments_removal({}) == 0
segments_removal({5}) == 1
segments_removal({3, 3, 3, 3}) == 1
segments_removal({13, 13, 7, 7, 7, 2, 2, 2}) == 3
segments_removal({1, 1, 2, 2, 3, 3}) == 3
segments_removal({1, 1, 2, 2, 2, 1}) == 2

./build/bench_segments
Benchmark: Codeforces 899E - Segments Removal
----------------------------------------------

Caso: pocos valores distintos (k=3), muchas fusiones
  n=1000 -> 1146 us
  n=10000 -> 11560 us
  n=50000 -> 52494 us
  n=100000 -> 106187 us

Caso: muchos valores distintos (k=n), pocas fusiones
  n=1000 -> 1043 us
  n=10000 -> 11388 us
  n=50000 -> 60803 us
  n=100000 -> 128742 us

Caso: todos iguales (1 segmento, 1 operacion)
  n=1000 -> 9 us
  n=10000 -> 43 us
  n=100000 -> 484 us

Caso: alternado 1,2,1,2,... (maximo numero de segmentos)
  n=1000 -> 1055 us
  n=10000 -> 11483 us
  n=100000 -> 128161 us