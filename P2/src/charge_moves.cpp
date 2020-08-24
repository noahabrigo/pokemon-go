#include "charge_moves.h"

charge_move::charge_move(){
    base_power = 0;
    ch_energy  = 0;
    name = "";
    //There are 17 real move types
    //On initialization the type 18 refers to a blank type,
    //this makes it so that the type isn't a BUG type move on initialization
    type = 18;
}

charge_move::charge_move(std::string nm, unsigned short int bpwr, short int en, unsigned short int t){
    name       = nm;
    base_power = bpwr;
    ch_energy  = en;
    type       = t;
}

const unsigned short int charge_move::get_base_power()const{
    return base_power;
}
const short int charge_move::get_ch_energy()const{
    return ch_energy;
}
const std::string charge_move::get_name()const{
    return name;
}

const unsigned short int charge_move::get_type()const {
    return type;
}
