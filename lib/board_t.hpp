#pragma once

using namespace std;

#include "cell_t.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


class board_t
{
private:
	int rows_;  /* Número de filas del tablero */
	int columns_;  /* Número de columnas del tablero */
	vector<vector<cell_t> > mesh_;  /* Vector de vectores que simula una matriz que simula el tablero */
	int turn_;  /* Turno actual del juego */
	int population_;  /* Población actual presente en el tablero */
	bool end_;  /* Establece si el juego ha terminado */

public:
	board_t (void);  /* Constructor por defecto */
	board_t (int rows, int columns);  /* Constructor */
	~board_t (void);  /* Destructor */

	void resize_board (int rows, int columns);  /* Redimensiona el tablero */

	int get_rows (void);  /* Getter del atributo rows_ */

	int get_columns (void);  /* Getter del atributo columns */

	void set_cell_alive (int i, int j);  /* Cambia el estado de la célula especificada a viva */
	void set_cell_dead (int i, int j);  /* Cambia el estado de la célula especificada a muerta */

	int get_turn (void);  /* Getter del atributo turn_ */

	int get_population (void);  /* Getter del atributo population_ */

	bool get_end (void);  /* Getter del atributo end_ */

	bool alive_cell (int i, int j);  /* Comprueba si la célula especificada está viva */

	void game_of_life (void);  /* Ejecuta El Juego de la Vida sobre el tablero */

private:
	void set_turn (int turn);  /* Setter del atributo turn_ */

	void calculate_population (void);  /* Recalcula la población del tablero */

	void set_end (bool end);  /* Setter del atributo end_ */

	bool in_range (int i, int j);  /* Comprueba que las coordenadas dadas pertenecen al tablero */

	void next_turn (void);  /* Actualiza el tablero y pasa un turno */

	ostream& write (ostream& os);  /* Imprime la tabla por la salida especificada */
};
