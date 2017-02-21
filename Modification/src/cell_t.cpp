#include "../lib/cell_t.hpp"

/* Constructor por defecto */
cell_t::cell_t (void):
status_(dead),
next_status_(dead)
{
    
}


/* Constructor */
cell_t::cell_t (Status status):
status_(status),
next_status_(status)
{
    
}


/* Destructor */
cell_t::~cell_t (void)
{
    
}


/* Getter del atributo status_ */
Status cell_t::get_status (void)
{
    return status_;
}


/* Setter del atributo status_ */
void cell_t::set_status (Status status)
{
    status_ = status;
}


/* Getter del atributo next_status_ */
Status cell_t::get_next_status (void)
{
    return next_status_;
}


/* Setter del atributo next_status */
void cell_t::set_next_status (Status next_status)
{
    next_status_ = next_status;
}
