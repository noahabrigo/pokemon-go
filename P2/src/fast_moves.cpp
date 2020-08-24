#include "fast_moves.h"

fast_move::fast_move(){
        base_power   = 0;
        energy_delta = 0;
        duration     = 0;
        cooldown     = 0;
        name         = "";
        //There are 17 real move types
        //On initialization the type 18 refers to a blank type,
        //this makes it so that the type isn't a BUG type move on initialization
        type         = 18;
    }

    fast_move::fast_move(std::string nm, unsigned short int bpwr, unsigned short int endelta, float dur, float cool, unsigned short int t){
        base_power   = bpwr;
        energy_delta = endelta;
        duration     = dur;
        cooldown     = cool;
        name         = nm;
        type         = t;
    }



    const unsigned short int fast_move::get_base_power()const{
        return base_power;
    }
    const unsigned short int fast_move::get_energy_delta()const{
        return energy_delta;
    }
    const float fast_move::get_duration()const{
        return duration;
    }
    const float fast_move::get_cooldown()const{
        return cooldown;
    }
    const std::string fast_move::get_name()const{
        return name;
    }
    const unsigned short int fast_move::get_type() const{
        return type;
    }
