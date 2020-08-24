//Standard library includes
#include <string>

//Local Includes
#include "Charge_Move.h"

namespace PokemonGo
{
	Charge_Move::Charge_Move(){}
    //Charge move constructor, uses part of the Pokemon_Move constructor
	Charge_Move::Charge_Move(std::string moveName, int moveType, unsigned int movePower, unsigned int moveEnergyDelta):
	    //Using part of the constructor inherited from the Pokemon_Move class
	    Pokemon_Move(moveName, moveType, movePower)
	{
	    energy_delta = moveEnergyDelta;
	}

	//Purpose: Get the variable desired.
	//Preconditions: An object of this class.
	//Postconditions: Returns the value of the variable requested.
	//Within this function, energy delta is returned as a negative value
	unsigned int Charge_Move::get_energy_delta()
	{
        return -energy_delta;
	}
}
