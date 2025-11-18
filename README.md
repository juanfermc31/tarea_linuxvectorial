# README.md — Cálculo de Masa y Centro de Masa mediante Integración Triple en C

Este proyecto implementa un sistema en C para calcular la masa total y el centro de masa de un sólido tridimensional mediante integración numérica usando los métodos de Riemann 3D y Monte Carlo. El usuario puede seleccionar el tipo de densidad, el método numérico y los límites del dominio.

---

## 📁 Estructura del Proyecto

```
tripleintegral/
├── src/
│   ├── main.c
│   ├── integracion.c
│   └── densidades.c
├── include/
│   ├── integracion.h
│   └── densidades.h
├── Makefile
└── README.md
```

---

## 🧠 Conceptos Principales

### ✔️ Masa total

```
M = ∭ ρ(x, y, z) dV
```

### ✔️ Centro de masa

```
x̄ = (1/M) ∭ x·ρ dV
ȳ = (1/M) ∭ y·ρ dV
z̄ = (1/M) ∭ z·ρ dV
```

### ✔️ Densidades disponibles

* **Constante** → ρ = 1
* **Lineal** → ρ = ax + by + cz
* **Gaussiana** → ρ = exp(-(x² + y² + z²))

### ✔️ Métodos de integración

* **Riemann 3D**
* **Monte Carlo 3D**

---

## ▶️ Compilación del Proyecto

Ejecutar en la terminal:

```
make
```

Esto generará el ejecutable:

```
./triple_integral
```

Para limpiar archivos generados:

```
make clean
```

---

## ▶️ Ejecución del Programa

Ejecutar:

```
./triple_integral
```

El programa solicitará:

* xmin, xmax
* ymin, ymax
* zmin, zmax
* Método (1 = Riemann, 2 = Monte Carlo)
* Densidad (1, 2 o 3)
* Parámetros a, b, c si la densidad es lineal
* Número de subdivisiones/puntos

---

## 📊 Archivo de Salida

Se generará:

```
resultado.csv
```

Formato:

```
Metodo,Densidad,N,M,x_bar,y_bar,z_bar,Tiempo
```

Ejemplo:

```
1,2,40,5.0231,0.1200,0.1200,0.1200,0.054
```

---

## 🔧 Requisitos (Windows)

1. Instalar **MinGW** desde:
   [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)
2. Agregar al PATH:

```
C:\MinGW\bin
```

3. Verificar:

```
gcc --version
```

---

## 🚀 Subir a GitHub

```
git init
git add .
git commit -m "Proyecto integrales triples"
git branch -M main
git remote add origin <tu_repo_url>
git push -u origin main
```

---

## 📌 Mejoras Futuras

* Independizar Nx, Ny y Nz
* Añadir parámetros avanzados para la gaussiana
* Validación completa de entradas
* Guardar múltiples ejecuciones en el CSV
* Añadir visualización con Python

---

## ❓ Preguntas a ChatGPT como orientación

Estas fueron algunas de las preguntas realizadas durante el desarrollo del proyecto para guiar la implementación:

* ¿Cómo organizar el proyecto con archivos `main.c`, `integracion.c`, `densidades.c` y sus headers?
* ¿Cómo adaptar el código para que el usuario ingrese los valores por consola?
* ¿Cómo compilar y ejecutar el proyecto en Visual Studio Code?
* ¿Cómo estructurar el Makefile para compilar automáticamente todos los módulos?
* ¿Qué método de integración es más eficiente entre Riemann y Monte Carlo?
* ¿Cómo generar y guardar resultados en un archivo CSV?
* ¿Cómo subir el proyecto a GitHub desde VS Code?

## 🧑‍💻 Autor

Juan Fernando Martinez Cabrera
