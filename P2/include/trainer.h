#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"


class trainer
{
    public:
        trainer();
        trainer(std::string name, std::vector<pokemon> poke_init);

        //Purpose: Sets the name of the trainer
        //Precond: takes no vars
        //Postcon: returns no vars. changes private variable "name"
        void set_name(std::string nm);

        //Purpose: Initialize trainers collection of pokemon used for battle
        //         Keeps active and up to date storage of pokemon trainer has in battle
        //Precond: Takes pokemon vector
        //Postcon: returns void
        void init_pkmn(std::vector<pokemon> poke_init);

        //Purpose: Console output of all the pokemon a trainer has
        //Precond: takes no vars
        //Postcon: returns void
        void has_pkmn();

        //Purpose: Returns a referenced pokemon object from a trainers index 0-2
        //Precond: takes integer pkmn_index.
        //Postcon: returns a pokemon object that can use all of it member functions
        pokemon &get_pkmn(unsigned short int pkmn_index);

        //Purpose: Returns pokemon in trainer's index that is currently in battle
        //Precond: takes no variables
        //Postcon: returns c_pkmn variable or 'current pokemon'
        unsigned short int in_btl();

        //Purpose: Swaps out the pokemon that is currently in battle
        //Precond: takes int pkmn_index, which is an index related to the pkmn vector
        //Postcon: replaces c_pkmn with pkmn_index value
        void change_pkmn(unsigned short int pkmn_index);

        //Purpose: Uses the current pokemon in battle's select move against an opponent
        //         NOTE: this function got very bloated over time. Will fix.
        //Precond: takes reference to another trainer object, and an index of the pokemon's move it will use from 0-2
        //Postcon: returns void
        void use_move(trainer & opponent, unsigned short int mv_index);


        //Displays pokemon information during battle like name, hp, level etc.
        void bstat();

        //Purpose: Return value of private member variable 'loss'
        //Precond: none
        //Postcon: returns bool
        bool lose();

        //Returns the name of the trainer
        std::string get_name();


    private:
        std::string name;
        std::vector<pokemon> pkmn;

        //in-battle variables

        //shows the index of what pokemon the trainer is currently using in battle 0 to 2
        unsigned short int c_pkmn;

        //A bool indicator that tells whether or not the trainer has lost the battle
        // This will be checked after each turn
        bool loss = false;
};

#endif // TRAINER_H
