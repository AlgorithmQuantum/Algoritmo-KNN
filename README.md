# Algoritmo-KNN
Primer algoritmo sobre machine learning desarrollado en C 

# Implementación de Algoritmo KNN en C

📋 Descripción
Este proyecto implementa el algoritmo de K-Vecinos más Cercanos (KNN) en lenguaje C. Es una solución para clasificación de puntos en un espacio tridimensional, permitiendo categorizar nuevos puntos en dos clases diferentes (A o B) basándose en la proximidad a puntos conocidos.

🔍 Características
- Clasificación binaria (clases A y B)
- Manejo de puntos en espacio 3D (x, y, z)
- Cálculo de distancia euclidiana
- Configurable para diferentes valores de K
- Dataset predefinido de 20 puntos de ejemplo

## Project Structure

```
.
├── KNN.c          # Main implementation file
├── .gitignore     # Git ignore rules
├── LICENSE        # MIT license
└── README.md      # This file
```

🛠️ Estructura del Código
Estructuras Principales
```
typedef struct punto {
    float x, y, z;
    char clase[45];
} punto;

typedef struct vecino {
    float distancia;
    int indice;
} vecino;
```

Funciones Principales
- distanciaEuclidea(): Calcula la distancia entre dos puntos
- comparar(): Función auxiliar para ordenamiento
- knn(): Implementa el algoritmo de clasificación

📥 Instalación y Uso
Clona el repositorio:
```
git clone https://github.com/AlgorithmQuantum/Algoritmo-KNN
```
Compila el programa:
```
gcc KNN.c -o knn -lm
```
Ejecuta el programa:
```
./knn
```

## ⚙️ Configuración
You can modify the following parameters in `KNN.c`:
- `N`: Total number of points in the dataset (default: 20)
- `K`: Number of neighbors to consider (default: 1)

📊 Ejemplo de Uso
El programa incluye un dataset predefinido y clasificará un punto de prueba con coordenadas (5.5, 5.5, 5.5).

📝 Requisitos
- Compilador GCC
- Biblioteca math.h
- Sistema operativo compatible con C (Windows, Linux, macOS)

👥 Contribuciones
Las contribuciones son bienvenidas. Por favor, abre un issue primero para discutir los cambios que te gustaría realizar.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.