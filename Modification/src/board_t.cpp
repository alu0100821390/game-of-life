#include "../lib/cell_t.hpp"
#include "../lib/board_t.hpp"


/***** MÉTODOS PÚBLICOS *****/

/* Constructor por defecto */
board_t::board_t (void):
rows_(2),
columns_(2),
turn_(0),
population_(0),
end_(false)
{
    mesh_.resize(rows_, vector<cell_t>(columns_));  /* Se redimensiona la malla a 2x2 (todo bordes) */
}


/* Constructor */
board_t::board_t (int rows, int columns):
rows_(rows+2),
columns_(columns+2),
turn_(0),
population_(0),
end_(false)
{
	mesh_.clear();
    mesh_.resize(rows_, vector<cell_t>(columns_));  /* Se redimensiona la malla */
    for (int i=0; i<columns_; i++){
        mesh_[0][i].set_status(edge);
        mesh_[rows_-1][i].set_status(edge);
    }
    for (int i=0; i<rows_; i++){
        mesh_[i][0].set_status(edge);
        mesh_[i][columns_-1].set_status(edge);
    }
}


/* Destructor */
board_t::~board_t (void)
{

}


/* Redimensiona el tablero */
void board_t::resize_board(int rows, int columns)
{
	rows_ = rows+2;
	columns_ = columns+2;
	mesh_.clear();
	mesh_.resize(rows_, vector<cell_t>(columns_));  /* Se redimensiona la malla */
    for (int i=0; i<columns_; i++){
        mesh_[0][i].set_status(edge);
        mesh_[rows_-1][i].set_status(edge);
    }
    for (int i=0; i<rows_; i++){
        mesh_[i][0].set_status(edge);
        mesh_[i][columns_-1].set_status(edge);
    }
}


/* Getter del atributo rows_ */
int board_t::get_rows (void)
{
    return rows_;
}


/* Getter del atributo columns */
int board_t::get_columns (void)
{
    return columns_;
}


/* Cambia el estado de la célula especificada a viva */
void board_t::set_cell_alive (int i, int j)
{
	if (in_range(i, j))  /* Si se trata de una cálula de la malla, se establece como viva */
		mesh_[i][j].set_status(alive);
}


/* Cambia el estado de la célula especificada a muerta */
void board_t::set_cell_dead (int i, int j)
{
	if (in_range(i, j))  /* Si se trata de una célula de la malla, se establece como muerta */
		mesh_[i][j].set_status(dead);
}


/* Getter del atributo turn_ */
int board_t::get_turn (void)
{
    return turn_;
}


/* Getter del atributo population_ */
int board_t::get_population (void)
{
    return population_;
}


/* Getter del atributo end_ */
bool board_t::get_end (void)
{
    return end_;
}


/* Comprueba si la célula especificada está viva */
bool board_t::alive_cell (int i, int j)
{
    if (in_range(i, j))  /* Si se trata de una célula de la malla... */
        if (mesh_[i][j].get_status() == alive)  /* Si la célula está viva, se devuelve 'true' */
            return true;

	return false;
}


/* Ejecuta El Juego de la Vida sobre el tablero */
void board_t::game_of_life (void)
{
    while (!end_){  /* Mientras el juego no haya terminado... */
		getchar();  /* Se espera a que el usuario presione 'Enter' */
        calculate_population();  /* Se recalcula la población actual del tablero */
        write(cout);  /* Se imprime el tablero por la salida estándar */
		next_turn();  /* Se actualiza el estado de las células del tablero y se avanza un turno */
    }

	cout << "GAME OVER x_x\n" << endl;
}


/***** MÉTODOS PRIVADOS *****/

/* Setter del atributo turn_ */
void board_t::set_turn (int turn)
{
    turn_ = turn;
}


/* Recalcula la población del tablero */
void board_t::calculate_population (void)
{
    population_ = 0;

    for (int i=0; i<rows_; i++)
        for (int j=0; j<columns_; j++)
            if (mesh_[i][j].get_status() == alive)
                population_++;
}


/* Setter del atributo end_ */
void board_t::set_end (bool end)
{
    end_ = end;
}


/* Comprueba que las coordenadas dadas pertenecen al tablero */
bool board_t::in_range (int i, int j)
{
    if ((i>=1) && (i<rows_-1) && (j>=1) && (j<columns_-1))
        return true;

	return false;
}


/* Actualiza el tablero y pasa un turno */
void board_t::next_turn (void)
{
	int count;  /* Número de células vecinas vivas de la célula examinada */
	end_ = true;

    for (int i=1; i<rows_-1; i++){  /* Se recorre la malla célula a célula */
        for (int j=1; j<columns_-1; j++){
            count = 0;  /* Se empieza con 0 células vecinas vivas */
            for (int a=-1; a<=1; a++){  /* Se recorre las células vecinas de la célula examinada */
                for (int b=-1; b<=1; b++){
                    if (!((a==0) && (b==0))){  /* No se recorre la propia célula examinada */
                        if (alive_cell(i+a, j+b)){  /* Si la célula vecina está viva, se aumenta la cuenta */
                            count++;
                        }
                    }
                }
            }
            if (mesh_[i][j].get_status() == dead){  /* Si la célula examinada está muerta... */
				if (count == 3){  /* Si tiene exactamente 3 células vecinas vivas... */
					mesh_[i][j].set_next_status(alive);  /* Se resucitará la célula examinada en el siguiente turno */
					end_ = false;  /* La célula ha cambiado de estado, así que el juego no ha terminado */
				}
				else{
					mesh_[i][j].set_next_status(dead);  /* La célula examinada permanecerá muerta en el siguiente turno */
				}
            }
            else{
                if (mesh_[i][j].get_status() == alive){  /* Si la célula examinada está viva... */
					if (count == 2){  /* Si tiene exactamente 2 células vecinas vivas... */
						mesh_[i][j].set_next_status(alive);  /* La célula examinada permanecerá viva en el siguiente turno */
					}
					else{
						if (count == 3){  /* Si la célula tiene exactamente 3 células vecinas vivas... */
							mesh_[i][j].set_next_status(alive);  /* La célula examinada permanecerá viva en el siguiente turno */
						}
						else{  /* Si la célula no tiene ni 2 ni 3 células vecinas vecinas vivas... */
							mesh_[i][j].set_next_status(dead);  /* Se matará la célula examinada en el siguiente turno */
							end_ = false;  /* La célula ha cambiado de estado, así que el juego no ha terminado */
						}
					}
                }
            }
        }
    }

    for (int i=1; i<rows_-1; i++){  /* Se vuelve a recorrer la malla célula a célula */
        for (int j=1; j<columns_-1; j++){
            mesh_[i][j].set_status(mesh_[i][j].get_next_status());  /* Se van actualizando las células al siguiente estado */
        }
    }

    turn_++;  /* Se pasa al siguiente turno */
}


/* Imprime la tabla por la salida especificada */
ostream& board_t::write (ostream& os)
{
    system("cls");

	if (turn_==0){
		os << "Initial board." << endl;
	}
	else{
		os << "Turn: " << turn_ << endl;
	}

    os << "Population: " << population_ << endl;

	os << " ";
    for (int i=0; i<columns_; i++)
        os << "-";
    os << endl;

    for (int i=0; i<rows_; i++){
        os << "|";
        for (int j=0; j<columns_; j++){
            if (mesh_[i][j].get_status() == alive)
                os << "X";
            else{
                if (mesh_[i][j].get_status() == edge)
                    os << "O";
                else
                    os << " ";
            }
        }
        os << "|" << endl;
    }

	os << " ";
    for (int i=0; i<columns_; i++)
        os << "-";
    os << endl;

	os << "Press 'Enter' for the next turn." << endl;

    return os;
}
