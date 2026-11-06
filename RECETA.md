# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

Receta: Programa principal (main)

Receta: Ticket de compra


<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text
1. Mostrar bienvenida.
2. Pedir los datos.
3. Calcular los importes.
4. Mostrar el ticket de compra.
```

## Recetas de los módulos
Receta: calcularSubtotal
1. Recibir precio y cantidad.
2. Multiplicar precio por cantidad.
3. Devolver subtotal.

Receta: calcularDescuento
1. Recibir subtotal y porcentaje.
2. Calcular descuento.
3. Devolver descuento.

Receta: calcularIVA
1. Recibir subtotal menos descuento.
2. Calcular IVA.
3. Devolver IVA.

Receta: calcularTotal
1. Recibir subtotal, descuento e IVA.
2. Calcular total.
3. Devolver total.

Receta: imprimirTicket
1. Recibir los datos de la compra.
2. Mostrar los resultados
<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(subtotal, descuento)

    iva ← (subtotal - descuento) * 0.16

    REGRESAR iva
FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, subtotal, descuento, iva, total)
 Mostrar nombre
    Mostrar subtotal
    Mostrar descuento
    Mostrar iva
    Mostrar total
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(cantidad, total)
 porcentaje ← (cantidad * 100) / total

    REGRESAR porcentaje
FIN MODULO
```
No se agregaron módulos adicionales.

```text

```
