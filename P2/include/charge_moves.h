//Could have used class inheritance for both fast moves and charge moves

//Did not use mutator functions to change variables of the fast_moves or charge_moves, this was unnecessary
//for the way I set up my code. The variables should not be able to change once initialized

//Did not do any negative integer error checking

#ifndef CHARGE_MOVES_H
#define CHARGE_MOVES_H


#include <string>

class charge_move{
public:
    charge_move();
    //Constructor initializes all of the variables
    charge_move(std::string nm, unsigned short int bpwr, short int en, unsigned short int t);

    //Purpose: get private member data
    //Precond: none
    //Postcon: returns data value and type of private member variable
    const unsigned short int get_base_power()const;
    const short int get_ch_energy()const;
    const std::string get_name() const;
    const unsigned short int get_type() const;

private:
    unsigned short int base_power;
    unsigned short int type;
    short int ch_energy;
    std::string name;
};

#endif // CHARGE_MOVES_H
