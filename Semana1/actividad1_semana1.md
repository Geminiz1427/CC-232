### Actividad 1 - Semana 1 
### Nombre: Renzo Jesús Magno Muro
### Código:20202176G 
#### Objetivo

Consolidar la Semana 1 a partir de código, demos, pruebas y una defensa escrita breve. La meta es distinguir con claridad problema, algoritmo, ADT e implementación, justificar correctitud básica, identificar qué se mide realmente cuando hablamos de costo 
y empezar a separar evidencia conceptual de evidencia experimental.

#### Archivos a usar

##### Núcleo principal

* `Semana1/README.md`
* `Semana1/src/bubble_sort.cpp`
* `Semana1/src/power.cpp`
* `Semana1/src/fibonacci.cpp`
* `Semana1/src/count_ones.cpp`
* `Semana1/demos/demo_bubblesort.cpp`
* `Semana1/demos/demo_power.cpp`
* `Semana1/demos/demo_fibonacci.cpp`
* `Semana1/demos/demo_countones.cpp`
* `Semana1/demos/demo_adt_secuencia.cpp`
* `Semana1/pruebas_publicas/README.md`
* `Semana1/pruebas_publicas/test_public_week1.cpp`
* `Semana1/pruebas_publicas/test_public_week1_extra.cpp`
* `Semana1/sustentacion/preguntas_semana1.md`
* `Semana1/sustentacion/rubrica_semana1.md`

##### Enlace común

* `Proyecto0/apps/demo_const_refs.cpp`
* `Proyecto0/bench/bench_vector_growth.cpp`
* `Proyecto0/bench/bench_vector_ops.cpp`
* `Proyecto0/bench/bench_cache_effects.cpp`

#### Extensión breve

* `Ejercicios0.md`
* `INSTRUCCIONES_Ejercicios0_v4.2.md`
* `stl_optimizacion_demostracion.cpp`
* `resolver_ejercicios0_v4.2.sh`

#### Bloque 1 - Núcleo conceptual de Semana1

Revisen:

* `Semana1/README.md`
* `Semana1/src/bubble_sort.cpp`
* `Semana1/src/power.cpp`
* `Semana1/src/fibonacci.cpp`
* `Semana1/src/count_ones.cpp`
* `Semana1/demos/demo_adt_secuencia.cpp`

Respondan:

1. Expliquen con sus palabras la diferencia entre **problema**, **algoritmo**, **ADT** e **implementación**.

Problema: Es lo que se quiere resolver. 
Algoritmo: Es la estrategia paso a paso para resolver el problema. 
ADT : Define qué operaciones ofrece una estructura, sin decir cómo están implementadas internamente, en el curso se suelen encontrar en la carpeta include.
Implementación: Es el uso del ADT y el algoritmo para resolver problema en cuestión. El código concreto que realiza esas operaciones.

2. En `bubble_sort.cpp`, expliquen qué observable conecta correctitud y costo.

El observable es el número de swaps e intercambios (stats.swaps, stats.comparisons). La correctitud se demuestra con isSortedNonDecreasing — verifica que el arreglo quedó ordenado, mientras que el costo se demuestra contando cuántas comparaciones e intercambios hizo. 

3. En `power.cpp`, expliquen por qué `power` mejora la idea de una versión ingenua.

powerBF multiplica "a" por sí mismo n veces(costo O(n)) mientras que  power usa exponenciación rápida, divide el exponente a la mitad en cada paso (n >>= 1) → costo O(log n). Para n=30, la versión ingenua hace 30 multiplicaciones; la rápida hace solo 5.

4. En `fibonacci.cpp`, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.

fib(n) recursivo es correcto, produce el número correcto, pero tiene costo O(2ⁿ) porque recalcula los mismos subproblemas muchas veces; mientras que fibI iterativo produce el mismo resultado en O(n). Lo cual una vez más demuestra que correctitud no implica eficiencia.

5. En `count_ones.cpp`, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.

La función recibe un unsigned int. El valor del número puede ser grande (ej: 1000000), pero el tamaño de entrada es fijo: 32 bits. Lo que importa para el costo es cuántos bits tiene el número, no cuánto vale.

6. En `demo_adt_secuencia.cpp`, expliquen por qué la misma interfaz puede convivir con representaciones distintas.

En demo_adt_secuencia.cpp: FixedArraySequence y VectorSequence implementan la misma interfaz IntSequence (size, get, set, add, remove). El cliente llama seq.add(0, 10) sin saber si por adentro hay un arreglo fijo o un std::vector. Eso es el ADT: separa qué hace de cómo lo hace.

#### Bloque 2 - Demos y trazado guiado

Revisen:

* `Semana1/demos/demo_bubblesort.cpp`
* `Semana1/demos/demo_power.cpp`
* `Semana1/demos/demo_fibonacci.cpp`
* `Semana1/demos/demo_countones.cpp`

Construyan una tabla con cuatro columnas:

* archivo,
* salida u observable importante,
* idea algorítmica,
* argumento de costo.

|       Archivo        |Salido u observable importante|Idea algorítmica|Argumento de costo|
|----------------------|------------------------------|----------------|------------------|
|demo_bubblesort.cpp|comparaciones = 14, intercambios = 7, ultimo swap = 0|Ordena comparando pares adyacentes|O(n²) comparaciones en peor caso|
|demo_power.cpp|powerBF(3, 5)= 243, power(3, 5)= 243,power2BF_I(5) = 32,power2_I(5)= 32,power2BF(5)= 32,power2(5)= 32|exponenciación por cuadrados|O(log n) vs O(n)|
|demo_fibonacci.cpp|fibI(10)= 55,fib(10)= 55,fib(10, prev)= 55, prev = 34, Primeros 8 Fibonacci desde la clase Fib: 0 1 1 2 3 5 8 13|fib() tarda más que fibI()|Recursión vs iteración|O(2ⁿ) vs O(n)|
|demo_countones.cpp|x = 361 = 0000000101101001, countOnes1(x) = 5,mismo resultado con dos métodos|Contar bits en 1|O(k) donde k = bits activos|

Luego respondan:

1. En `demo_bubblesort.cpp`, ¿qué salida sirve para defender costo y no solo resultado?

Es el conteo de swaps y comparaciones. Eso muestra cuánto trabajo hizo.

2. En `demo_power.cpp`, ¿qué comparación concreta muestra una mejora algorítmica?

En demo_power, la comparación concreta es el resultado de powerBF(2,30) vs power(2,30) ,mismo resultado, pero uno hace 30 operaciones y el otro 5.

3. En `demo_fibonacci.cpp`, ¿qué crecimiento se vuelve defendible?

En demo_fibonacci, el crecimiento defendible es que fib(n) recursivo se vuelve inusable cuando n es muy grande, mientras fibI sigue siendo instantáneo.

4. En `demo_countones.cpp`, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?

En demo_countones, el ejemplo que más ayuda es un número con pocos bits en 1 (ej: 256 = 100000000) — countOnes1 hace solo 1 iteración porque n &= (n-1) apaga el único bit de golpe.

#### Bloque 3 - Pruebas públicas y preparación de sustentación

Revisen:

* `Semana1/pruebas_publicas/README.md`
* `Semana1/pruebas_publicas/test_public_week1.cpp`
* `Semana1/pruebas_publicas/test_public_week1_extra.cpp`
* `Semana1/sustentacion/preguntas_semana1.md`
* `Semana1/sustentacion/rubrica_semana1.md`

Respondan:

1. ¿Qué funciones o ideas están verificando las pruebas públicas?

Las pruebas públicas verifican que bubbleSortBasic, power, fib y countOnes producen los resultados correctos en casos conocidos.

2. ¿Qué sí demuestra una prueba pública?

Una prueba pública demuestra que el código produce la salida esperada para los casos probados, es evidencia de correctitud observable.

3. ¿Qué no demuestra una prueba pública?

Una prueba pública no demuestra que el algoritmo es eficiente, ni que maneja todos los casos borde, ni que el invariante se mantiene en todos los estados intermedios.

4. Elijan **una** pregunta de `preguntas_semana1.md` y respóndanla bien.
5. Usen la rúbrica para autoevaluarse en:

   * comprensión conceptual,
   * sustentación de correctitud,
   * análisis de eficiencia.


#### Bloque 4 - Puente corto con Proyecto0

Revisen:

* `Proyecto0/apps/demo_const_refs.cpp`
* `Proyecto0/bench/bench_vector_growth.cpp`
* `Proyecto0/bench/bench_vector_ops.cpp`
* `Proyecto0/bench/bench_cache_effects.cpp`

Respondan brevemente:

1. ¿Qué diferencia observable deja `demo_const_refs.cpp` entre lectura, modificación y copia?
2. En `bench_vector_growth.cpp`, ¿qué cambia con `reserve`?
3. En `bench_vector_ops.cpp`, ¿por qué `push_back`, `insert(begin())` e `insert(middle)` no cuestan lo mismo?
4. En `bench_cache_effects.cpp`, ¿qué intuición deja sobre localidad de memoria?

#### Bloque 5 - Extensión breve con Ejercicios0

Revisen:

* `Ejercicios0.md`
* `INSTRUCCIONES_Ejercicios0_v4.2.md`
* `stl_optimizacion_demostracion.cpp`
* `resolver_ejercicios0_v4.2.sh`

Respondan:

1. Según `Ejercicios0.md`, ¿cuál es el orden correcto antes de optimizar?
2. ¿Qué quiere mostrar `stl_optimizacion_demostracion.cpp` con `reserve`, `nth_element`, `partial_sort` y `lower_bound`?
3. ¿Qué tipo de evidencia puede producir `resolver_ejercicios0_v4.2.sh`?
4. ¿Qué limitaciones de entorno menciona `INSTRUCCIONES_Ejercicios0_v4.2.md`?
5. ¿Por qué esta parte no reemplaza la discusión de correctitud de Semana1?

### Bloque 6 - Cierre comparativo

Respondan esta pregunta final:

**¿Qué cambia cuando pasamos de defender correctitud básica en Semana1 a comparar implementaciones con evidencia experimental?**

La respuesta debe incluir obligatoriamente:

* una afirmación de especificación,
* una afirmación de correctitud,
* una afirmación de costo,
* una afirmación de representación o memoria,
* una advertencia metodológica.

