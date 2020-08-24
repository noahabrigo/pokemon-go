#include "Pokemon_Move.h"

#ifndef CHARGE_MOVE_H
#define CHARGE_MOVE_H
//Standard library includes
#include <string>

namespace PokemonGo
{
	class Charge_Move : public Pokemon_Move
	{
	public:
	    //Charge Move constructor.
		Charge_Move();
		//Charge Move constructor.
		Charge_Move(std::string moveName, int moveType, unsigned int movePower, unsigned int moveEnergyDelta);

        //Purpose: Get the variable desired.
        //This function is overriding the pure virtual function from the Pokemon_Move abstract class
		unsigned int get_energy_delta();

    protected:

	private:
	};
}
#endif // CHARGE_MOVE_H

