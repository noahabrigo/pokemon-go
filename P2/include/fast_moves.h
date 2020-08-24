//Could have used class inheritance for both fast moves and charge moves

//Did not use mutator functions to change variables of the fast_moves or charge_moves, this was unnecessary
//for the way I set up my code. The variables should not be able to change once initialized

//Did not do any negative integer error checking

#ifndef FAST_MOVES_H
#define FAST_MOVES_H


#include <string>



class fast_move{
public:
    fast_move();
    //Constructor initializes all of the variables
    fast_move(std::string nm, unsigned short int bpwr, unsigned short int endelta, float dur, float cool, unsigned short int t);

    //Purpose: get private member data
    //Precond: none
    //Postcon: returns data value and type of private member variable
    const unsigned short int get_base_power() const;
    const unsigned short int get_energy_delta() const;
    const float get_duration() const;
    const float get_cooldown() const;
    const std::string get_name() const;
    const unsigned short int get_type() const;
private:
    unsigned short int  base_power;
    unsigned short int  energy_delta;
    unsigned short int  type;
    float     duration;
    float     cooldown;
    std::string name;

};

#endif // FAST_MOVES_H
