#include "Pokemon_Move.h"

#ifndef FAST_MOVE_H
#define FAST_MOVE_H
//Standard library includes
#include <string>

namespace PokemonGo
{
	class Fast_Move : public Pokemon_Move
	{
    public:
        //Fast Move constructor.
		Fast_Move();

        //Fast Move constructor.
		Fast_Move(std::string moveName, int moveType, unsigned int movePower,
				  float moveDuration, unsigned int moveEnergyDelta, float moveCooldown);

        //Purpose: Get the variable desired.
        unsigned int get_energy_delta();
		float get_duration () const;
		float get_cooldown () const;

    private:
        //Duration doesn't hold a current purpose.
		//It is the length of time a fast move's animation takes to complete.
		float duration = 0;

        //A non-negative floating point number that stores the amount of time following
		//the attack animation before the move can be used again.]
		float cooldown = 0;
	};
}
#endif // FAST_MOVE_H
