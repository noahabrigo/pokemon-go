#ifndef POKEMON_MOVE_H
#define POKEMON_MOVE_H
//Standard library includes
#include <string>

namespace PokemonGo
{

class Pokemon_Move
{
    public:
        //Pokemon Move Base Constructor
        Pokemon_Move();
        //Pokemon Move Base Constructor
        Pokemon_Move(std::string moveName, int moveType, unsigned int movePower);
        //Pokemon Move Base Destructor
        virtual ~Pokemon_Move();

        //Return private member variables name, type, base_power, and protected member energy delta
        std::string get_name() const;
        int get_type() const;
        unsigned int get_base_power() const;
        //get_energy_delta is defined as a pure virtual function,
        //the children of the Pokemon_Move class decide what to do with this function
        //Having at least one abstract method makes it necessary for the base class
        //to be used only for children of the base class.
        virtual unsigned int get_energy_delta() = 0;

    protected:
        //energy_delta is protected because it is defined differently by each child of the Pokemon_Move class
        unsigned int energy_delta = 0;

    private:
        //Initializing private member variables
        std::string name = "";
        int type = 18;
        unsigned int base_power = 0;
};

}
#endif // POKEMON_MOVE_H
