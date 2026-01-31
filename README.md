# Sistema de Descuentos

Sistema de gestión de clientes y descuentos implementado en C++ usando el patrón de diseño Strategy.

## 📋 Descripción

Este sistema permite gestionar clientes con diferentes tipos de descuentos (A, B, C) y procesar sus ventas de forma automática. Utiliza archivos binarios `.dat` para almacenar la información de clientes y ventas.

## 🏗️ Arquitectura

El sistema implementa el **Patrón Strategy** para manejar diferentes tipos de descuentos:

- **Cliente**: Clase principal que representa a un cliente
- **EstrategiaDescuento**: Interfaz abstracta para las estrategias de descuento
- **DescuentoA, DescuentoB, DescuentoC**: Implementaciones concretas de diferentes estrategias
- **Gestor**: Clase que maneja la lectura de archivos y procesamiento de datos

## 📦 Archivos del Proyecto

### Archivos Fuente Principales
- `main.cpp` - Programa principal con datos de prueba
- `gestor.cpp/h` - Gestión de clientes y ventas
- `cliente.cpp/h` - Clase Cliente
- `estrategiadescuento.cpp/h` - Interfaz de estrategia
- `descuentoa.cpp/h` - Estrategia de descuento tipo A
- `descuentob.cpp/h` - Estrategia de descuento tipo B
- `descuentoc.cpp/h` - Estrategia de descuento tipo C

### Archivos de Datos (Generados automáticamente)
- `cliente.dat` - Datos binarios de clientes
- `ventas.dat` - Datos binarios de ventas

## 🚀 Compilación y Ejecución

### Opción 1: Usar el script batch (Recomendado en Windows)

```bash
compilar_y_ejecutar.bat
```

### Opción 2: Compilación manual con g++

```bash
g++ -o SistemaDescuentos.exe main.cpp gestor.cpp cliente.cpp descuentoa.cpp descuentob.cpp descuentoc.cpp estrategiadescuento.cpp -std=c++11
SistemaDescuentos.exe
```

### Opción 3: Usar Qt Creator

1. Abrir `SistemaDescuentos.pro` en Qt Creator
2. Configurar el proyecto
3. Compilar y ejecutar (Ctrl+R)

## 📊 Datos de Prueba

El programa `main.cpp` crea automáticamente archivos de prueba con los siguientes datos:

### Clientes Ficticios (10 clientes)

| ID | Nombre           | Tipo |
|----|------------------|------|
| 1  | Juan Perez       | A    |
| 2  | Maria Rodriguez  | B    |
| 3  | Carlos Gomez     | C    |
| 4  | Ana Martinez     | A    |
| 5  | Pedro Lopez      | B    |
| 6  | Laura Fernandez  | C    |
| 7  | Juan Perez       | A    |
| 8  | Sofia Garcia     | B    |
| 9  | Diego Silva      | C    |
| 10 | Maria Rodriguez  | A    |

**Nota**: Los clientes 1 y 7 tienen el mismo nombre (Juan Perez), igual que los clientes 2 y 10 (Maria Rodriguez), para probar la funcionalidad de detección de nombres repetidos.

### Ventas Ficticias (20 registros)

El sistema incluye 20 ventas distribuidas entre diferentes clientes, con algunos clientes realizando múltiples compras para acumular cantidades y montos.

## 🔧 Funcionalidades Implementadas

El programa ejecuta y muestra los siguientes reportes:

1. **Cliente con Mayor Cantidad Acumulada**: Identifica qué cliente ha comprado la mayor cantidad de productos
2. **Monto Total de Ventas**: Calcula el monto total acumulado de todas las ventas
3. **Clientes con Nombres Repetidos**: Detecta y muestra clientes que tienen el mismo nombre

## 💡 Ejemplo de Salida

```
========================================
  SISTEMA DE DESCUENTOS - PRUEBA
========================================

PASO 1: Creando archivos de datos ficticios...
✓ Archivo cliente.dat creado con 10 clientes ficticios
✓ Archivo ventas.dat creado con 20 registros de ventas ficticias

PASO 2: Cargando datos en el sistema...
✓ Clientes cargados desde cliente.dat
✓ Ventas procesadas desde ventas.dat

========================================
PASO 3: Resultados de las consultas
========================================

1. Cliente con mayor cantidad acumulada:
   ----------------------------------------
   [Nombre del cliente]
   [Cantidad acumulada]

2. Monto total de todas las ventas:
   ----------------------------------------
   El monto total de la empresa es: [monto]

3. Clientes con nombres repetidos:
   ----------------------------------------
   -- Clientes con nombres repetidos --
   Nombre: Juan Perez - Aparece: 2 veces...
   Nombre: Maria Rodriguez - Aparece: 2 veces...

========================================
  PRUEBA COMPLETADA EXITOSAMENTE
========================================
```

## 📝 Notas Importantes

- Los archivos `.dat` se generan automáticamente al ejecutar el programa
- El programa usa estructuras binarias para lectura/escritura eficiente
- Las estrategias de descuento pueden ser modificadas en las clases correspondientes
- El sistema es extensible para agregar nuevos tipos de descuento

## 🎯 Requisitos

- Compilador C++ con soporte para C++11 o superior
- Windows (para usar el script .bat) o cualquier SO con g++
- Qt Creator (opcional, si se prefiere usar el IDE)

## 👨‍💻 Autor

Sistema desarrollado por Axel Irribarren como proyecto de práctica del patrón Strategy.
