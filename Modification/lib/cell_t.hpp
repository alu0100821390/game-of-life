#pragma once

using namespace std;

enum Status { dead, alive, edge };


class cell_t
{
private:
	Status status_;  /* Estado actual de la célula */
	Status next_status_;  /* Estado de la célula en el siguiente turno */

public:
	cell_t (void);  /* Constructor por defecto */
	cell_t (Status status);  /* Constructor */
	~cell_t (void);  /* Destructor */

	Status get_status (void);  /* Getter del atributo status_ */
	void set_status (Status status);  /* Setter del atributo status_ */

	Status get_next_status (void);  /* Getter del atributo next_status_ */
	void set_next_status (Status next_status);  /* Setter del atributo next_status */
};
