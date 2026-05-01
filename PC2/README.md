## PC2 - CC232

### Estudiante
- Nombre: Renzo Jesús Magno Muro
- Código: 20202176G
- Problema asignado: Codeforces 899E - Segments Removal
- Enlace: https://codeforces.com/problemset/problem/899/E

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana:
- Estructura o técnica principal:

### Resumen de la solución
- Estructura o técnica principal: Lista doblemente enlazada (`std::list`) + Max-heap (`std::priority_queue`) + Mapa de iteradores (`std::unordered_map`)

### Resumen de la solución
El arreglo se comprime en segmentos de elementos iguales consecutivos,
representados en una lista doblemente enlazada. Un max-heap selecciona
siempre el segmento más largo (el más a la izquierda en caso de empate
de longitud). Al eliminar un segmento se revisan sus vecinos — si tienen
el mismo valor se fusionan en uno solo, manteniendo el invariante de que
no existen dos segmentos adyacentes con el mismo valor. Las entradas
obsoletas del heap se descartan verificando id y longitud antes de operar.

### Complejidad
- Tiempo: O(n log n) — cada segmento se inserta y extrae del heap a lo sumo una vez
- Espacio: O(n) — la lista y el mapa almacenan a lo sumo n segmentos

### Invariante
No existen dos segmentos adyacentes con el mismo valor en la lista.
Cada entrada activa en el mapa corresponde a un segmento vivo y no modificado.

### Solución ingenua y por qué no basta
La solución ingenua sería recorrer el arreglo en cada turno buscando el
segmento más largo — O(n) por turno — y con hasta O(n) turnos el costo
total sería O(n²). Para n=200000 eso es inviable. La solución con heap
reduce el costo a O(n log n).

### Estructuras usadas y por qué
- `std::list` (lista doblemente enlazada): permite eliminar y fusionar
  segmentos vecinos en O(1) dado el iterador, sin desplazar elementos.
- `std::priority_queue` (max-heap): selecciona el segmento más largo
  en O(log n) por extracción.
- `std::unordered_map`: mapea el id de cada segmento a su iterador
  en la lista, permitiendo acceso directo en O(1).

### Operación más importante
La fusión de vecinos: cuando se elimina un segmento y sus vecinos
tienen el mismo valor, se combinan en uno solo y se reinserta en el
heap con la nueva longitud. Sin esto el invariante se rompe.

### Casos borde
1. Arreglo vacío → 0 operaciones
2. Un solo elemento → 1 operación
3. Todos iguales → 1 operación 
4. Empate de longitud → se elimina el que esta "más" a la izquierda 
5. Fusión de vecinos → [2,2,5,5,5,2,2,2] → elimina [5,5,5], fusiona ambos segmentos → 2 operaciones

### Archivos relevantes
- `include/segments_removal.h` — define `Segment` y la firma de la función
- `src/segments_removal.cpp` — implementa los 4 pasos de la solución
- `demos/demo_segments.cpp` — muestra visualmente la compresión y el resultado
- `tests/test_segments.cpp` — verifica casos conocidos con assert
- `benchmark/bench_segments.cpp` — mide tiempo de ejecución para entradas grandes

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
./build/demo_segments
./build/test_segments
./build/bench_segments
```

### Casos de prueba
1. `{}` → 0 operaciones (arreglo vacío)
2. `{5}` → 1 operación (un solo elemento)
3. `{3,3,3,3}` → 1 operación (todos iguales, un segmento)
4. `{2,2,5,5,5,2,2,2}` → 2 operaciones (fusión de vecinos tras eliminar [5,5,5])
5. `{13,13,7,7,7,2,2,2}` → 3 operaciones (caso del enunciado)
6. `{1,1,2,2,3,3}` → 3 operaciones (empate, gana el más a la izquierda)

### Historial de commits
El historial de commits puede verse en el video y en el repositorio.

### Nota 
Este trabajo se encuentra incompleto y no cumple con los requisitos minimos. Aún asi realizo la presentación del repositorio para cumplir con la entrega.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo,
compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
