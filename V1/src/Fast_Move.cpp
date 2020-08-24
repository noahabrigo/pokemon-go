//Standard library includes
#include <string.h>

//Local Includes
#include "Fast_Move.h"

namespace PokemonGo
{
    //Fast_Move blank constructor
	Fast_Move::Fast_Move(){}
    //Charge move constructor, uses part of the Pokemon_Move constructor
	Fast_Move::Fast_Move(std::string moveName, int moveType, unsigned int movePower,               //Fast Move constructor.
				  float moveDuration, unsigned int moveEnergyDelta, float moveCooldown)
				  : Pokemon_Move(moveName, moveType, movePower)
				  {
				      duration = moveDuration;
				      energy_delta = moveEnergyDelta;
				      cooldown = moveCooldown;
				  }

	//Purpose: Get the variable desired.
	//Preconditions: An object of this class.
	//Postconditions: Returns the value of the variable requested.

	float Fast_Move::get_duration() const {
		return duration;
	}

	float Fast_Move::get_cooldown() const {
		return cooldown;
	}

    //Within this function, energy delta is returned as a positive value
	unsigned int Fast_Move::get_energy_delta(){
	    return energy_delta;
	}
}
