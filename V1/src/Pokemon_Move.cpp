//Local Includes
#include "Pokemon_Move.h"

namespace PokemonGo
{

Pokemon_Move::Pokemon_Move()
{
    //ctor
}

//Base Pokemon_Move constructor, initializes name, type, and base_power
Pokemon_Move::Pokemon_Move(std::string moveName, int moveType, unsigned int movePower)
{
    name = moveName;
    type = moveType;
    base_power = movePower;
}

//Destructor left blank, no dynamic data used in this project
Pokemon_Move::~Pokemon_Move()
{
    //dtor
}


//Purpose: Get the variable desired.
//Preconditions: An object of this class.
//Postconditions: Returns the value of the variable requested.
std::string Pokemon_Move::get_name() const
{
    return name;
}
int Pokemon_Move::get_type() const
{
    return type;
}
unsigned int Pokemon_Move::get_base_power() const
{
    return base_power;
}

}
