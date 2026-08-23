#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento() {
    Carrito c;
    carrito_init(&c);

    Producto pan;
    pan.precio = 200;
    pan.cantidad = 3;
    carrito_agregar(&c, pan);

    Producto leche;
    leche.precio = 350;
    leche.cantidad = 2;
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);

    int total_con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, total_con_descuento);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar() {
    Carrito c;
    carrito_init(&c);
    
    Producto p;
    p.precio = 50;
    p.cantidad = 1;

    // 1. Llenar el carrito hasta su capacidad máxima (4 productos)
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);

    // 2. Verificar que el conteo es MAX_ITEMS (que sabemos que es 4)
    ASSERT_IGUAL(4, carrito_contar(&c));

    // 3. Verificar que intentar agregar uno más devuelve 0 (falla porque está lleno)
    int resultado = carrito_agregar(&c, p);
    ASSERT_IGUAL(0, resultado);

    // 4. Verificar que el conteo sigue siendo 4 (no cambió por el intento fallido)
    ASSERT_IGUAL(4, carrito_contar(&c));
}
int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
