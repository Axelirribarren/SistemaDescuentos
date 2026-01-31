# Datos de Prueba - Sistema de Descuentos

## 📋 Descripción General

Este documento detalla todos los datos ficticios que el programa `main.cpp` crea automáticamente para probar el sistema de descuentos.

## 👥 Archivo: cliente.dat

Contiene **10 clientes ficticios** con diferentes tipos de descuento.

### Detalle de Clientes

| ID | Nombre              | Tipo Descuento | Descripción |
|----|---------------------|----------------|-------------|
| 1  | Juan Perez          | A              | Cliente estándar |
| 2  | Maria Rodriguez     | B              | Cliente premium |
| 3  | Carlos Gomez        | C              | Cliente VIP |
| 4  | Ana Martinez        | A              | Cliente estándar |
| 5  | Pedro Lopez         | B              | Cliente premium |
| 6  | Laura Fernandez     | C              | Cliente VIP |
| 7  | Juan Perez          | A              | Cliente estándar (nombre duplicado) |
| 8  | Sofia Garcia        | B              | Cliente premium |
| 9  | Diego Silva         | C              | Cliente VIP |
| 10 | Maria Rodriguez     | A              | Cliente estándar (nombre duplicado) |

### Notas sobre Clientes

- **Nombres Repetidos**: 
  - "Juan Perez" aparece 2 veces (clientes #1 y #7)
  - "Maria Rodriguez" aparece 2 veces (clientes #2 y #10)
  - Esto permite probar la funcionalidad `obtenerClientesRepetidos()`

- **Tipos de Descuento**:
  - **Tipo A**: Descuento estándar (clientes 1, 4, 7, 10)
  - **Tipo B**: Descuento premium (clientes 2, 5, 8)
  - **Tipo C**: Descuento VIP (clientes 3, 6, 9)

## 💰 Archivo: ventas.dat

Contiene **20 registros de ventas** distribuidos entre los clientes.

### Detalle de Ventas

| # | Cliente ID | Cliente Nombre      | Cantidad | Monto Total | Observaciones |
|---|------------|---------------------|----------|-------------|---------------|
| 1 | 1          | Juan Perez          | 15       | $1,500.50   | Primera compra |
| 2 | 2          | Maria Rodriguez     | 8        | $800.00     | Primera compra |
| 3 | 3          | Carlos Gomez        | 25       | $2,500.75   | Primera compra |
| 4 | 1          | Juan Perez          | 10       | $1,000.00   | Segunda compra |
| 5 | 4          | Ana Martinez        | 30       | $3,000.00   | Primera compra |
| 6 | 5          | Pedro Lopez         | 5        | $500.25     | Primera compra |
| 7 | 6          | Laura Fernandez     | 12       | $1,200.50   | Primera compra |
| 8 | 2          | Maria Rodriguez     | 7        | $700.00     | Segunda compra |
| 9 | 7          | Juan Perez          | 20       | $2,000.00   | Primera compra |
| 10| 8          | Sofia Garcia        | 18       | $1,800.30   | Primera compra |
| 11| 9          | Diego Silva         | 22       | $2,200.80   | Primera compra |
| 12| 10         | Maria Rodriguez     | 9        | $900.00     | Primera compra |
| 13| 3          | Carlos Gomez        | 14       | $1,400.60   | Segunda compra |
| 14| 1          | Juan Perez          | 5        | $500.00     | Tercera compra |
| 15| 4          | Ana Martinez        | 11       | $1,100.00   | Segunda compra |
| 16| 6          | Laura Fernandez     | 16       | $1,600.00   | Segunda compra |
| 17| 7          | Juan Perez          | 13       | $1,300.00   | Segunda compra |
| 18| 9          | Diego Silva         | 8        | $800.00     | Segunda compra |
| 19| 10         | Maria Rodriguez     | 19       | $1,900.50   | Segunda compra |
| 20| 4          | Ana Martinez        | 25       | $2,500.00   | Tercera compra |

### Resumen de Ventas por Cliente

| Cliente ID | Nombre              | # Compras | Cant. Total | Monto Total |
|------------|---------------------|-----------|-------------|-------------|
| 1          | Juan Perez          | 3         | 30          | $3,000.50   |
| 2          | Maria Rodriguez     | 2         | 15          | $1,500.00   |
| 3          | Carlos Gomez        | 2         | 39          | $3,901.35   |
| 4          | Ana Martinez        | 3         | 66          | $6,600.00   |
| 5          | Pedro Lopez         | 1         | 5           | $500.25     |
| 6          | Laura Fernandez     | 2         | 28          | $2,800.50   |
| 7          | Juan Perez (dup)    | 2         | 33          | $3,300.00   |
| 8          | Sofia Garcia        | 1         | 18          | $1,800.30   |
| 9          | Diego Silva         | 2         | 30          | $3,000.80   |
| 10         | Maria Rodriguez (dup)| 2        | 28          | $2,800.50   |

### Cliente con Mayor Cantidad

**Ana Martinez (ID: 4)** es el cliente con mayor cantidad acumulada:
- **Cantidad Total**: 66 unidades
- **Monto Total**: $6,600.00
- **Tipo de Descuento**: A (Estándar)
- **Número de Compras**: 3

### Monto Total del Sistema

**Monto Total de Todas las Ventas**: $29,203.20

## 🔍 Casos de Prueba

### 1. Cliente con Mayor Cantidad Acumulada
**Función**: `gestor.obtenerMayorCantidad()`

**Resultado Esperado**:
```
Ana Martinez
66
```

### 2. Monto Total de Ventas
**Función**: `gestor.obtenerMontoTotal()`

**Resultado Esperado**:
```
El monto total de la empresa es: 29203.2
```

### 3. Clientes con Nombres Repetidos
**Función**: `gestor.obtenerClientesRepetidos()`

**Resultado Esperado**:
```
-- Clientes con nombres repetidos --
Nombre: Juan Perez - Aparece: 2 veces...
Nombre: Maria Rodriguez - Aparece: 2 veces...
```

## 📝 Notas de Implementación

### Estructura de Cliente (strClientes)
```cpp
struct strClientes {
    int nro;           
    char nombre[200];  
    char tipo;         
};
```

### Estructura de Ventas (strVentas)
```cpp
struct strVentas {
    int nro_cliente;   
    int cantidad;      
    double montoTotal; 
};
```

## 🎯 Propósito de los Datos

Estos datos ficticios permiten:

1. ✅ Probar el patrón Strategy con los tres tipos de descuento (A, B, C)
2. ✅ Validar la lectura/escritura de archivos binarios `.dat`
3. ✅ Verificar la acumulación correcta de cantidades y montos
4. ✅ Probar la detección de nombres repetidos
5. ✅ Identificar el cliente con mayor actividad
6. ✅ Calcular totales del sistema
7. ✅ Simular un escenario realista de ventas múltiples

## 🚀 Modificación de Datos

Si deseas modificar los datos de prueba, edita las funciones en `main.cpp`:

- `crearArchivoClientes()` - Para modificar clientes
- `crearArchivoVentas()` - Para modificar ventas

Luego recompila y ejecuta el programa.
