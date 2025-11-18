# README.md — Cálculo de Masa y Centro de Masa mediante Integración Triple en C

Este proyecto implementa un sistema optimizado en C para calcular la masa total y el centro de masa de un sólido tridimensional, utilizando integración numérica por el método de Monte Carlo. El código está organizado modularmente y optimizado para ser rápido y eficiente.

---

## 📁 Estructura del Proyecto

```
tripleintegral/
├── src/
│   ├── main.c
│   ├── densidades.c
│   └── integracion.c
├── include/
│   ├── densidades.h
│   └── integracion.h
├── obj/               ← generado automáticamente
├── programa_vectorial ← ejecutable
└── Makefile
```

---

## 🧠 Conceptos Implementados

### ✔️ Masa

```
M = ∭ ρ(x, y, z) \, dV
```

### ✔️ Centro de masa

```
x̄ = (1/M) ∭ xρ \, dV
ȳ = (1/M) ∭ yρ \, dV
z̄ = (1/M) ∭ zρ \, dV
```

### ✔️ Densidades disponibles

* **Constante** → ρ = 1
* **Lineal** → ρ = x + y + z
* **Gaussiana** → ρ = exp(-(x² + y² + z²))

### ✔️ Método de integración implementado

* **Monte Carlo 3D optimizado**

---

## ▶️ Cómo Compilar

En la terminal, ejecutar:

```
make
```

Esto generará el ejecutable:

```
./programa_vectorial
```

Para limpiar objetos y ejecutable:

```
make clean
```

Para compilar y ejecutar automáticamente:

```
make run
```

---

## ▶️ Cómo Ejecutar el Programa

```
./programa_vectorial
```

El programa solicitará:

* Límites en X
* Límites en Y
* Límites en Z
* Número de muestras N
* Tipo de densidad (1–3)

---

## 📊 Archivo de Salida

El programa genera:

```
resultados.csv
```

Con el formato:

```
Metodo,Densidad,N,M,x_bar,y_bar,z_bar,Tiempo
```

Ejemplo:

```
MonteCarlo,Gaussiana,100000,100000,100000,12.5831,0.1020,-0.0030,0.2210,0.0872
```

---

## ❓ Preguntas a ChatGPT como orientación

Estas fueron algunas de las preguntas realizadas durante el desarrollo del proyecto:

* ¿Cómo organizar el proyecto en múltiples archivos .c y .h?
* ¿Cómo optimizar el algoritmo Monte Carlo sin alterar la estructura del programa?
* ¿Cómo compilar correctamente usando VS Code con MinGW?
* ¿Cómo modificar funciones para que acepten densidades variables?
* ¿Cómo crear un Makefile rápido y con directorio obj/?
* ¿Cómo mejorar la velocidad manteniendo la misma lógica?
* ¿Cómo guardar resultados en CSV sin sobrescribirlos?

---

## 🔷 Diagrama de Flujo del Programa

```mermaid
flowchart TD
    Start((Inicio)) --> Init[Declarar Variables]

    Init --> Inputs1[Solicitar al Usuario]
    Inputs1 --> Inputs2[Limites (x,y,z)]
    Inputs2 --> Inputs3[Metodo: Riemann o MonteCarlo]
    Inputs3 --> Inputs4[Tipo de Densidad]
    Inputs4 --> Inputs5[Pasos o Muestras N]

    Inputs5 --> TimerStart[Iniciar Cronometro]

    %% Densidades
    subgraph Densidades [densidades.c Modelos]
        direction TB
        D_Const[Densidad Constante 1]
        D_Lin[Densidad Lineal ax+by+cz]
        D_Gaus[Densidad Gaussiana exp(-r^2)]
    end

    %% Integracion
    subgraph Integracion [integracion.c Nucleo de Calculo]
        DecideMethod{Metodo Seleccionado?}

        DecideMethod --> |Riemann| LoopR[Bucle Triple i j k]
        LoopR --> SumR[Sumar Volumen * rho]

        DecideMethod --> |MonteCarlo| LoopMC[Bucle 0 a N]
        LoopMC --> Rand[Generar Puntos Aleatorios]
        Rand --> SumMC[Acumular Promedio * Volumen]
    end

    %% Masa
    TimerStart --> CallM[Calcular Masa Total M]
    CallM --> Int_Logic_M[Ejecutar Integracion]
    Int_Logic_M -.-> Densidades
    Int_Logic_M --> ResM[Guardar M]

    %% Momento X
    ResM --> CallX[Calcular Momento X]
    CallX --> Int_Logic_X[Ejecutar Integracion]
    Int_Logic_X -.-> Densidades
    Int_Logic_X --> ResX[Guardar Mx]

    %% Momento Y
    ResX --> CallY[Calcular Momento Y]
    CallY --> Int_Logic_Y[Ejecutar Integracion]
    Int_Logic_Y -.-> Densidades
    Int_Logic_Y --> ResY[Guardar My]

    %% Momento Z
    ResY --> CallZ[Calcular Momento Z]
    CallZ --> Int_Logic_Z[Ejecutar Integracion]
    Int_Logic_Z -.-> Densidades
    Int_Logic_Z --> ResZ[Guardar Mz]

    %% Resultados
    subgraph Main [main.c Resultados]
        ResZ --> Center1[Centro de Masa]
        Center1 --> Center2[xbar = Mx/M]
        Center2 --> Center3[ybar = My/M]
        Center3 --> Center4[zbar = Mz/M]

        Center4 --> TimerStop[Detener Cronometro]
        TimerStop --> PrintScreen[Imprimir Resultados]
        PrintScreen --> FileWrite[Escribir resultados.csv]
    end

    FileWrite --> End((Fin))

    %% Estilos
    style Main fill:#e1f5fe,stroke:#01579b,stroke-width:2px
    style Integracion fill:#fff3e0,stroke:#e65100,stroke-width:2px
    style Densidades fill:#e8f5e9,stroke:#1b5e20,stroke-width:2px

```

## 🧑‍💻 Autor

Juan Fernando Martinez Cabrera
