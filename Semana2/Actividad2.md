### Actividad 2 - Semana 2
### Nombre: Renzo Jesús Magno Muro
### Código:20202176G 
#### Objetivo

Consolidar lo trabajado en la Semana 2 a partir de código, demos, pruebas y una defensa escrita breve.

La meta es distinguir con claridad qué aporta la memoria contigua, por qué un arreglo dinámico necesita `resize()`, cómo se justifica el costo amortizado, qué mejora `FastArrayStack` respecto a `ArrayStack`, y por qué `RootishArrayStack` reduce desperdicio espacial sin abandonar la interfaz de lista.

Además, se busca conectar la implementación tipo `Vector` con las estructuras basadas en arreglos vistas en clase. Esto coincide con el enfoque oficial de la semana 2 del curso. :contentReference[oaicite:1]{index=1}

#### Material de trabajo

##### Código de la semana
- `Semana2/README.md`
- `Semana2/include/array.h`
- `Semana2/include/ArrayStack.h`
- `Semana2/include/ArrayStackExplicado.h`
- `Semana2/include/FastArrayStack.h`
- `Semana2/include/RootishArrayStack.h`
- `Semana2/include/RootishArrayStackExplicado.h`
- `Semana2/include/DengVector.h`
- `Semana2/demos/demo_array_basico.cpp`
- `Semana2/demos/demo_arraystack.cpp`
- `Semana2/demos/demo_arraystack_explicado.cpp`
- `Semana2/demos/demo_fastarraystack.cpp`
- `Semana2/demos/demo_rootisharraystack.cpp`
- `Semana2/demos/demo_rootisharraystack_explicado.cpp`
- `Semana2/demos/demo_deng_vector.cpp`
- `Semana2/demos/demo_stl_vector_contraste.cpp`
- `Semana2/pruebas_publicas/README.md`
- `Semana2/pruebas_publicas/test_public_week2.cpp`
- `Semana2/pruebas_internas/resize_stress_week2.cpp`
- `Semana2/pruebas_internas/test_internal_week2.cpp`
- `Semana2/sustentacion/preguntas_semana2.md`
- `Semana2/sustentacion/rubrica_semana2.md`

#### Lecturas obligatorias
- **Lectura4-Deng**
- **Lectura5-Morin**

#### Bloque 1 - Núcleo conceptual de la semana

Revisen:
- `Semana2/README.md`
- **Lectura4-Deng**
- **Lectura5-Morin**
- `Semana2/include/ArrayStack.h`
- `Semana2/include/FastArrayStack.h`
- `Semana2/include/RootishArrayStack.h`
- `Semana2/include/DengVector.h`

Respondan:

1. Expliquen con sus palabras qué significa que un arreglo use **memoria contigua**.

Los elementos están almacenados uno al lado del otro en un bloque continuo de memoria, no hay saltos ni punteros entre ellos.

2. Expliquen por qué acceder a `A[i]` es una operación de costo `O(1)`.

Porque la dirección del elemento i se calcula directamente: dirección_base + i * tamaño_elemento.

3. Expliquen la diferencia entre `size` y `capacity`.

size es cuántos elementos hay actualmente. capacity es cuántos elementos caben sin necesitar más memoria.

4. Expliquen por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.

Porque no hay garantía de que los bytes siguientes en memoria estén disponibles — otro programa o variable puede estar ahí. Por eso resize() pide un bloque nuevo más grande, copia todos los elementos, y libera el bloque viejo.

5. Expliquen por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.

Si cada vez que se necesita más espacio se duplica la capacidad, los resize ocurren cada vez menos frecuentemente. El costo total de n inserciones es O(n), así que el costo promedio por inserción es O(1). Si se creciera de 1 en 1, cada inserción podría desencadenar un resize y el costo total sería O(n²).

6. Comparen `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?

Ambos son arreglos dinámicos con resize al crecer. La diferencia es de intención: ArrayStack está orientado a operaciones de pila, mientras que DengVector es más completo como vector general, con expand, shrink, traverse. Comparten la idea de capacidad duplicada.

7. Expliquen qué mejora `FastArrayStack` respecto a `ArrayStack`.

El desplazamiento de elementos. ArrayStack usa un bucle manual elemento por elemento. FastArrayStack usa std::copy y std::copy_backward, que internamente usan memmove — mucho más rápido en la práctica. La complejidad asintótica es la misma O(n), pero la constante es menor.

8. Expliquen cuál es la idea espacial central de `RootishArrayStack`.

En vez de un solo bloque grande, usa varios bloques de tamaños crecientes: bloque 0 tiene 1 elemento, bloque 1 tiene 2, bloque 2 tiene 3, etc. En cualquier momento, solo el último bloque puede estar parcialmente vacío. 

9. Expliquen por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.

Porque con r bloques la capacidad total es 1+2+3+...+r = r(r+1)/2. Cuando necesitas encontrar en qué bloque está el elemento i, se resuelve con la fórmula cuadrática inversa en i2b(i). Bloques de tamaño uniforme desperdiciarían más espacio o harían el mapeo más costoso.

10. Expliquen qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.


#### Bloque 2 - Demostración y trazado guiado

Revisen:
- `Semana2/demos/demo_array_basico.cpp`
- `Semana2/demos/demo_arraystack.cpp`
- `Semana2/demos/demo_arraystack_explicado.cpp`
- `Semana2/demos/demo_fastarraystack.cpp`
- `Semana2/demos/demo_rootisharraystack.cpp`
- `Semana2/demos/demo_rootisharraystack_explicado.cpp`
- `Semana2/demos/demo_deng_vector.cpp`
- `Semana2/demos/demo_stl_vector_contraste.cpp`

Construyan una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo o espacio

Luego respondan:

1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?
2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?
3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?
4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?
5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?
6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?
7. ¿Qué demo sirve mejor para defender **amortización** y cuál sirve mejor para defender **uso de espacio**?

#### Bloque 3-Pruebas públicas, stress y correctitud

Revisen:
- `Semana2/pruebas_publicas/README.md`
- `Semana2/pruebas_publicas/test_public_week2.cpp`
- `Semana2/pruebas_internas/test_internal_week2.cpp`
- `Semana2/pruebas_internas/resize_stress_week2.cpp`

Respondan:

1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?
2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?
3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?
4. ¿Qué sí demuestra una prueba pública sobre una estructura?
5. ¿Qué no demuestra una prueba pública?
6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?
7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

#### Bloque 4-Vector como puente entre teoría y código

Revisen:
- `Semana2/include/DengVector.h`
- `Semana2/demos/demo_deng_vector.cpp`
- **Lectura4-Deng**

Respondan:

1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?
2. ¿Cuándo debe ejecutarse `expand()`?
3. ¿Por qué `insert(r, e)` necesita desplazar elementos?
4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?
5. ¿Qué evidencia de copia profunda aparece en la demo?
6. ¿Por qué `traverse()` es una buena interfaz didáctica?
7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?

#### Bloque 5 - RootishArrayStack: espacio y mapeo

Revisen:
- `Semana2/include/RootishArrayStack.h`
- `Semana2/include/RootishArrayStackExplicado.h`
- `Semana2/demos/demo_rootisharraystack.cpp`
- `Semana2/demos/demo_rootisharraystack_explicado.cpp`
- **Lectura5-Morin**

Respondan:

1. ¿Cómo se distribuyen los elementos entre bloques?
2. ¿Por qué con `r` bloques la capacidad total es `r(r+1)/2`?
3. ¿Qué problema resuelve `i2b(i)`?
4. ¿Qué información produce `locate(i)` en la versión explicada?
5. ¿Qué se gana en espacio frente a `ArrayStack`?
6. ¿Qué se conserva igual respecto a la interfaz?
7. ¿Qué parte les parece más difícil de defender oralmente: el mapeo, el análisis espacial o el costo amortizado de `grow/shrink`?

#### Bloque 6-Refuerzo de lectura

Revisen:
- **Lectura4-Deng**

Respondan brevemente:

1. ¿Qué aporta `operator[]` a la idea de vector?
2. ¿Qué supone `find(e)` sobre igualdad entre elementos?
3. ¿Qué muestra `traverse()` sobre procesamiento uniforme de toda la estructura?
4. ¿Por qué esta lectura sirve como refuerzo natural de `DengVector` aunque no sea el centro exclusivo de la semana?

#### Bloque 7 - Cierre comparativo

Respondan esta pregunta final:

**¿Qué cambia cuando pasamos de "usar un arreglo" a "diseñar una estructura dinámica basada en arreglo"?**

La respuesta debe incluir obligatoriamente:
- una afirmación sobre representación
- una afirmación sobre correctitud
- una afirmación sobre costo amortizado
- una afirmación sobre uso de espacio
- una comparación entre `ArrayStack`, `FastArrayStack` y `RootishArrayStack`.
