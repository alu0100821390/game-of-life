# Algoritmos y Estructuras de Datos Avanzadas

## Práctica 1: El Juego de la Vida

### Objetivo

El objetivo de la práctica es implementar tipos de datos definidos por el usuario y utilizarlos en un programa en lenguaje C++.

### Enunciado

El juego de la vida es un ejemplo de un autómata celular, diseñado por el matemático británico John Horton Conway en 1970. Un autómata celular es un modelo matemático que modela un sistema dinámico que evoluciona en pasos discretos.

El juego de la vida es un juego de cero jugadores, lo que quiere decir que su evolución está determinada por el estado inicial y no necesita ninguna entrada de datos posterior. El tablero de juego es una malla formada por células que se extiende por el infinito en todas las direcciones.

Cada célula tiene 8 células vecinas, que son las que están próximas a ella. Las células tienen dos estados: “viva" o "muerta".

El estado de la malla evoluciona a lo largo de unidades de tiempo discretas (turnos). El estado de todas las células se tiene en cuenta para calcular el estado de las mismas al turno siguiente. Todas las células se actualizan simultáneamente.

Las transiciones dependen del número de células vecinas vivas:

* Una célula muerta con exactamente 3 células vecinas vivas "nace" (al turno siguiente
estará viva).
* Una célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere o
permanece muerta (por "soledad" o "superpoblación").

### Compilación

El ejecutable generado se guarda en *bin/*

~~~
make
~~~

### Ejecución

#### Ejecución sin parámetros

El programa pedirá los datos iniciales al usuario por teclado.

~~~
make run
~~~

#### Ejecución con parámetros

El programa tomará los datos del fichero que se le pase como primer parámetro a la hora de la ejecución (en el fichero *Makefile* se ha establecido por defecto el fichero *input/default.txt*), en el que la primera línea indica el número de filas y columnas, la segúnda línea el número de células vivas que se introducirán, y de la tercera línea en adelante, las coordenadas de las células vivas iniciales (fila y columna respectivamente).

~~~
make run-file
~~~

### A tener en cuenta

El programa realiza llamadas al sistema propias de los sistemas Windows en los ficheros *main/main.cpp:101* y *src/board_t.cpp:220*, por lo que podrían no funcionar en sistemas Unix y Mac.

### Información personal

**Autor:** [Kevin Estévez Expósito](https://alu0100821390.github.io/)

**ULL-ID:** alu0100821390
