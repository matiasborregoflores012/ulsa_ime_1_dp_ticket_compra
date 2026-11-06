# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
Este programa permite capturar el nombre de un producto, su precio unitario, la cantidad comprada y el porcentaje de descuento que se aplicará. Con estos datos, calcula el subtotal multiplicando el precio por la cantidad. Después obtiene el monto del descuento y lo resta al subtotal para conocer el importe con descuento. Posteriormente calcula el IVA del 16 % y lo suma al resultado anterior para obtener el total a pagar. Finalmente, muestra toda la información organizada en forma de ticket de compra.

En la vida real, este programa podría utilizarse en pequeños negocios, tiendas o supermercados para calcular automáticamente el importe de las ventas. Además, ayuda a evitar errores en los cálculos y facilita la generación de comprobantes para los clientes.<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

_____

## 2. Entradas y salidas (Fase 1)
Entrada: Precio

Tipo: double
Se lee con leerDecimal()
Guarda el precio del producto.

Entrada: Cantidad

Tipo: int
Se lee con leerEntero()
Guarda la cantidad de productos comprados.

Salida: Total

Tipo: double
Muestra la cantidad final a pagar después del descuento y el IVA.
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| nombreProducto | string | leerCadena |
| precio | double | leerDecimal |
| cantidad | int | leerEntero |
| porcentajeDescuento | double | leerDecimal |

**Salida** (¿qué datos muestra el ticket?):
Nombre del producto
Precio unitario
Cantidad comprada
Subtotal
Descuento aplicado
IVA (16 %)
Total a pagar

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
El IVA se calcula sobre lo que queda después del descuento, porque esa es la cantidad que realmente va a pagar el cliente por el producto.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto no vacío | Para identificar el producto correctamente. |
| Precio | Mayor que 0 | Un producto no puede tener precio negativo o cero. |
| Cantidad | Entero mayor que 0 | Debe comprarse al menos una unidad. |
| Descuento (%) | Entre 0 y 100 | Un descuento no puede ser negativo ni mayor al 100 %. |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Si el usuario escribe un dato fuera de rango, el programa seguirá ejecutándose y realizará los cálculos con ese valor, lo que puede generar resultados incorrectos en el ticket.

**¿Puede el total salir negativo? ¿Por qué?**
No, el total no puede salir negativo si se cumplen las restricciones del programa. Como el precio y la cantidad son mayores que 0 y el descuento está entre 0 % y 100 %, el subtotal con descuento nunca será menor que cero. Además, el IVA siempre suma una cantidad positiva o cero, por lo que el total final será mayor o igual a cero.

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
Después de terminar el ciclo de validación, la variable precio siempre contiene un valor mayor que 0.

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
El total siempre se obtiene sumando el IVA al subtotal después de aplicar el descuento.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Cuaderno | 50.00 | 2 | 0 | 100.00 | 0.00 | 16.00 | 116.00 |
| 2 (con descuento) | Mochila | 500.00 | 1 | 10 | 500.00 | 50.00 | 72.00 | 522.00 |
| 3 (precio con centavos) | Pluma | 4 | 20 | 50.00 | 10.00 | 6.40 | 6.40 | 46.40 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio, cantidad | calcular su subtotal |
| Ticket | subtotal, descuento, IVA, total | calcular y mostrar el total de la compra |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, ambos son productos porque se venden y tienen nombre y precio. Lo que cambia es la forma de medirlos: uno se vende por cantidad de piezas y el otro por peso.

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que sea mayor que 0)
│     ├── 2.3 Pedir la cantidad (y validar que sea mayor que 0)
│     └── 2.4 Pedir el porcentaje de descuento (y validar que esté entre 0 y 100)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 Calcular el descuento
│     ├── 3.3 Calcular el IVA
│     └── 3.4 Calcular el total
└── 4.  Mostrar el ticket de compra
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Ya estaban resueltas las tareas de capturar datos mediante las funciones leerCadena(), leerDecimal() y leerEntero(). Los cálculos y la generación del ticket deben implementarse dentro del programa.

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
Sí. La parte "Calcular los importes" hacía más de una cosa, porque incluía varios cálculos diferentes. Por eso se dividió en:

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | subtotal con descuento | el IVA | Función |
| `imprimirTicket` | nombre, subtotal, descuento, IVA, total | nada | Procedimiento |
| calcularTotal | subtotal, descuento, IVA | el total | Función |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí 
**¿Tuve que corregirla? ¿Qué cambié?** no

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** _____

## 9. Ejemplo de ejecución (Fase 3)
=========================================
                    ticket               
=========================================
producto: cuaderno
=========================================
subtotal: 100
=========================================
descuento: 10
=========================================
descuento total: 90
=========================================
iva: 14.4
=========================================
lo que te toca pagar prro xd: 104.4
=========================================
=========================================<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```
_____
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | std::cout |
| 2. Pedir nombre del producto | leerCadena |
| 3. Pedir precio y validar | leerDecimal + while + if |
| 4. Pedir cantidad y validar | leerEntero + while + if |
| 5. Pedir descuento y validar | leerDecimal + while + if |
|6. Calcular subtotal|calcularSubtotal|
|7. Calcular descuento|calcularDescuento|
|8. Calcular total con descuento|calcularTotal|
|9. Calcular IVA|ivasolo|
|10. Calcular total a pagar|suma del total con descuento e IVA|
|11. Imprimir ticket|cout|


**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
hacer que calcule el descuento y el iva

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
Usé un ancho de 15 caracteres para mantener alineadas las columnas del ticket

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
Sí. Convertí el ancho del ticket en una constante llamada ANCHO_TICKET. Esto evita usar números mágicos y facilita modificar el formato del ticket en el futuro.

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Precio = 200, cantidad = 2, descuento = 10%. El total después del descuento salía 240 en lugar de 360. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | Revisé las variables y observé que porcentaje cambiaba de 10 a 40. |
| 3. Explica: ¿cuál era la causa? | Estaba guardando el monto del descuento dentro de la variable porcentaje, perdiendo el porcentaje original. |
| 4. Corrige: ¿qué cambiaste? | Creé una variable separada para guardar el descuento y dejé porcentaje con su valor original. |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | Sí, eliminé los mensajes de depuración después de comprobar que el cálculo era correcto. |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Que no basta con probar un solo caso. Debo usar varios casos de prueba, incluyendo descuentos de 0 %, 10 %, 20 % y 100 %, para detectar errores que podrían quedar ocultos con datos muy simples.

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
Tuve que cambiar una línea donde estaba el valor del IVA. Mejoraría usando una constante para el IVA, por ejemplo IVA, para modificarlo en un solo lugar.

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
Revisé que el texto del ticket coincidiera con el porcentaje utilizado en el cálculo para evitar información incorrecta.

**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
No. La variable de main() no cambió porque la función recibe una copia del valor (paso por valor). Los cambios dentro de la función solo afectan a esa copia.

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [m ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
es facil de usar

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
en un mensaje de bienvenida

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
en un solo lugar donde defini la constante

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
unicamente la parte de donde se obtiene el nombre

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | 100.00 / 0.00 / 16.00 / 116.00 | si |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | 100.00 / 10.00 / 14.40 / 104.40 | si |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | 600.00 / 90.00 / 81.60 / 591.60 | si |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | 19.99 / 0.00 / 3.20 / 23.19 | si |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | 90.00 / 90.00 / 0.00 / 0.00 | si |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | 40.00 / 0.00 / 6.40 / 46.40  | si |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | 20.00 / 0.00 / 3.20 / 23.20 | si |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | 100.00 / 20.00 / 12.80 / 92.80 | si |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | marca error y vuelve a pedir | si |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 |chcharrones salsa negra | si |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | solo se pasa al siguiente | no |
| 12 | Caso propio 1: compra grande | 1400.00 / 350.00 / 168.00 / 1218.00  |  1400.00 / 350.00 / 168.00 / 1218.00 | si |
| 13 | Caso propio 2: producto con decimales | 99.00 / 9.90 / 14.26 / 103.36 | 99.00 / 9.90 / 14.26 / 103.36 | 99.00 / 9.90 / 14.26 / 103.36 |  si |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
Porque el valor fue redondeado a dos decimales al mostrarse en pantalla.

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
Sí, el ticket siguió alineado porque utilicé std::setw para mantener un ancho fijo al imprimir los datos.

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
Ambas funciones calculan un porcentaje de una cantidad. La diferencia es que calcularDescuento calcula el porcentaje que se resta al subtotal, mientras que calcularIVA calcula el porcentaje de impuesto que se agrega al total.

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
MODULO calcularPorcentaje(cantidad, porcentaje)

    resultado <- cantidad * porcentaje / 100

    devolver resultado

FIN MODULO
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
Ambos quedaron utilizando la misma lógica de cálculo de porcentaje. Solo cambia el porcentaje aplicado y el valor sobre el que se realiza el cálculo.

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
Sí. Volví a ejecutar todos los casos de prueba y los resultados siguieron siendo correctos.

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí 

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
En una calculadora de propinas, un sistema de comisiones, un programa de intereses bancarios, un sistema de calificaciones o cualquier aplicación que necesite calcular porcentajes

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | Sí | Pasó todos los casos de la tabla de pruebas. |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | Sí | Valida precio, cantidad y descuento inválidos antes de continuar. |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | Sí | Utiliza nombres descriptivos y el ticket está alineado con setw. |
| Modular | ¿Cada función hace una sola cosa? | Sí | Cada función realiza una tarea específica (calcularSubtotal, calcularDescuento, calcularIVA, etc.). |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | Sí | Se usaron constantes para valores como el ancho del ticket y el porcentaje de IVA.|
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | Sí | Si cambia el IVA o el ancho del ticket, solo se modifica una constante.| |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | Sí | Funciones como calcularPorcentaje, calcularDescuento y calcularIVA pueden utilizarse en otros programas. |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) Validar las entradas del usuario.

**¿Por qué lo elegí?**
Porque evita que el programa trabaje con datos incorrectos, como precios negativos, cantidades negativas o descuentos inválidos.

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
Agregué validaciones utilizando ciclos while e instrucciones if para verificar que el precio y la cantidad fueran mayores que cero y que el descuento estuviera dentro del rango permitido antes de continuar con los cálculos.

**¿Hice algún otro reto opcional? ¿Cuál?**
Sí. Mejoré el formato del ticket utilizando std::setw para alinear los datos y hacer más legible la salida.

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | El total con descuento salía incorrecto porque sobrescribía la variable porcentaje. | Creé una variable separada para guardar el monto del descuento y conservé el porcentaje original. | si |
| 2 | El programa aceptaba precios, cantidades y descuentos inválidos. | Agregué validaciones con while e if para volver a pedir los datos cuando fueran incorrectos. | Sí |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| no | _____ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
a usar mejor los whiles y encontrar errores

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
nada

**¿Qué fue lo más difícil y cómo lo resolví?**
corregir el error de descuento

**¿Qué pregunta me quedó sin responder?**
ninguna

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
fscilito

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
usando descuento y no no lo hubiera encontradp

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** 5

**Si hice menos de 3, ¿por qué?**
no

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
