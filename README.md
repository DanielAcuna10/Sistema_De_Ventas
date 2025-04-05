# 🛒 Sistema de Inventario y Ventas en C++

Este proyecto es un sistema de gestión de productos e inventario simple, desarrollado en C++ como práctica de aprendizaje. Permite agregar productos, realizar compras, generar reportes de ventas y ver un historial de transacciones. Todo esto se realiza desde la consola, con una interfaz basada en menús interactivos.

## 📌 Funcionalidades

- **Agregar productos** al inventario (hasta 200).
- **Comprar productos** del inventario.
- **Ver el inventario** completo, con nombre, precio y cantidad.
- **Buscar productos por nombre**.
- **Actualizar precios** de productos existentes.
- **Visualizar reporte de ventas totales**.
- **Historial de compras** con detalles de cada transacción.
- **Manejo básico de errores de entrada** (como caracteres inválidos o selección fuera de rango).

## 💻 Tecnologías utilizadas

- Lenguaje: **C++**
- Entrada/Salida: `iostream`
- Manejo de texto: `string`
- Control de errores de entrada: `limits`

## 📚 Qué aprendí

✅ Estructuras en C++  
✅ Uso de arreglos para almacenar datos  
✅ Implementación de menús interactivos con `switch`  
✅ Validación de entradas con `cin.fail()` y `cin.ignore()`  
✅ Operaciones básicas con cadenas (`string`)  
✅ Cálculo de totales, manejo de flujo de caja y reportes  
✅ Cómo crear sistemas con múltiples funcionalidades de forma ordenada

## 🚀 Cómo usar

1. Compila el archivo:
   ```bash
   g++ inventario.cpp -o inventario
