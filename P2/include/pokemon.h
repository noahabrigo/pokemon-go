#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>


#include "fast_moves.h"
#include "charge_moves.h"

class pokemon{
public:
    //Default pokemon constructor
    pokemon();

    //Purpose: Initialize pokemon object based on its index number
    //Precond: take int poke_num which is the number related to the index of base_pokemon struct array in poke_db.cpp,
    //         takes int lvl which sets the level and the calculated hp and stats of the pokemon
    //Postcon: does not return any value, only initializes the object
    pokemon(unsigned short int poke_num, unsigned short int lvl);

    //Purpose: Initialize pokemon object based on its name
    //Precond: Takes string nm which will find the pokemon based on that name,
    //         takes int lvl which sets the level and the calculated hp and stats of the pokemon
    //Postcon: does not return any value, only initializes the object
    pokemon(std::string nm, unsigned short int lvl);

    //Pokemon destructor
    ~pokemon();

    //Purpose: Initialize pokemon object based on its index number. Sets up the pokemon, this is used if a pokemon object was created but not initialized
    //         optional purpose would be to change a pokemon on the fly if needed
    //Precond: take int poke_num which is the number related to the index of base_pokemon struct array in poke_db.cpp,
    //         takes int lvl which sets the level and the calculated hp and stats of the pokemon
    //Postcon: does not return any value, only initializes the object
    void set_pkmn(unsigned short int poke_num, unsigned short int lvl);


    //Purpose: Initialize pokemon object based on its name. Sets up the pokemon, this is used if a pokemon object was created but not initialized
    //         optional purpose would be to change a pokemon on the fly if needed
    //Precond: Takes string nm which will find the pokemon based on that name,
    //         takes int lvl which sets the level and the calculated hp and stats of the pokemon
    //Postcon: does not return any value, only initializes the object
    void set_pkmn(std::string nm, unsigned short int lvl);


    //Purpose: get private member data
    //Precond: none
    //Postcon: returns data of private member variable
    std::string get_name();
    unsigned short int get_base_atk();
    unsigned short int get_base_def();
    unsigned short int get_base_sta();

    unsigned short int get_iv_atk();
    unsigned short int get_iv_def();
    unsigned short int get_iv_sta();

    unsigned short int get_level();
    unsigned short int get_max_hp();
    unsigned short int get_hp();

    unsigned short int get_type_1();
    unsigned short int get_type_2();

    unsigned short int get_energy();

    //returns the fnt variable to check if the pkmn has fainted or not
    //This could've been arranged better. I thought of the variable first, then the function later
    //In the future I will rewrite it just to use the function
    bool faint();

    //Purpose: Sets the level of the pkmn and updates stats of the pkmn involving HP and other calculated variables
    //Precond: takes integer lvl
    //Postcon: returns void, assigns lvl value to private member variable level
    void set_level(unsigned short int lvl);

    //Purpose: This allows interaction between two pkmn objects. The pokemon "fight" each other.
    //Precond: Takes the index of the attacker pokemon's useable moves. This can be found by using has_moves() function.
    //         Takes a reference of a pokemon object. This is so that the attacker pokemon can take damage of the defender pokemon
    //Postcon:  returns void. Takes away hp from opponent. This damage is calculated through various algorithms and multipliers of both pokemon
    void use_move(unsigned short int move_index, pokemon &opponent);

    //Purpose: updates the stats of the pokemon. These stats are c_atk, c_def, and max_hp
    //Precond: Takes no variables, this function is used only within other functions
    //Postcon: returns void
    void update_stats();

    //Purpose: Output all the moves a certain pokemon can learn
    //Precond: takes no vars
    //Postcon: returns no vars
    const void can_learn();

    //Purpose: Output all the moves a certain pokemon has in its moveset
    //Precond: takes no vars
    //Postcon: returns no vars
    const void has_moves();

    //Purpose: swap the moves of the fast moves and charge moves of the pokemon respectively
    //Precond: take the index of the pokemon's move from its learnable move list as a non-negative integer
    //Postcon: function returns void. Uses cout for debugging.
    void swap_f_move(unsigned short int move);
    void swap_ch_move(unsigned short int slot, unsigned short int move);


    //Purpose: swap the moves of the fast moves and charge moves of the pokemon respectively
    //Precond: take the index of the pokemon's move from its learnable move list as a string
    //Postcon: function returns void. Uses cout for debugging.
    void swap_f_move(std::string move);
    //the slot variable is used for which index number of the ch move to swap. 0 for the first charge move 1 for the other charge move
    void swap_ch_move(unsigned short int slot, std::string move);


    //Purpose: Make it so that the pokemon has to wait before using the same move multiple times
    //         idle_frames value is incremented by fast_move duration
    //Precond: takes no variables
    //Postcon: decrements idle_frames variable by 1 every frame in the program
    void wait();


private:
    //Base variables the pkmn takes from the pkmn databse in poke_db.cpp
    unsigned short int base_atk = 0;
    unsigned short int base_def = 0;
    unsigned short int base_sta = 0;

    //Independent special advantage points the pkmn can receive on creation. CANNOT be changed once created
    unsigned short int iv_atk = 0;
    unsigned short int iv_def = 0;
    unsigned short int iv_sta = 0;

    //The calculated attack and defense of the pkmn after base and IVs have been calculated with CP
    unsigned short int c_atk = 0;
    unsigned short int c_def = 0;

    //The current level of the pkmn
    unsigned short int level = 0;

    //Vars for the maximum health the pkmn can have and the active health it currently has
    unsigned short int max_hp = 0;
    unsigned short int hp = 0;

    //Available energy of the pkmn. For right now, the max number of this variable is 500
    unsigned short int energy = 500;

    //A bool type to check if pkmn has fainted or not. This means the pkmn is unable to fight or be used out of battle
    bool fnt = false;

    //The name of the pkmn
    std::string name = "";

    //A pokemon can have 1 or two types, this is stored as a 2x1 array
    unsigned short int type[2] = {18,18};

    //Amount of frames the pkmn needs to be idle before able to use again
    unsigned short int idle_frames = 0;

    //Checks whether the pokemon is fighting for the first time
    bool first_time = true;

    //A Static list of fast moves and charge moves shared by all pokemon
    static const fast_move f_move_list[67];
    static const charge_move ch_move_list[143];

    //List structure to simplify code
    struct move{
        //The id is the index of the move in the actual f_move_list and ch_move_list
        unsigned short int id;
        //The actual name of the move
        std::string name;
        //0 for fast move 1 for charge move
        bool type;
    };


    //A vector of the moves a pokemon can learn
    std::vector<move> moves;
    //Moves the pokemon currently has in their moveset
    std::vector<move> moveset;


    //Index value of the move of the pokemon that was last used,
    //this is useful in trying to calculate cooldown
    //last used is out of index on purpose on initialization
    unsigned short int last_used = 5;


    //Static CP multiplier shared by all pokemon
    static const float cp[40];

    //Static Attack and Defense multiplier shared by all pokemon
    static const float am[19][19];
    static const float dm[19][19];
};

#endif // POKEMON_H
