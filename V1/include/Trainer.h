#ifndef TRAINER_H
#define TRAINER_H
//Standard library includes
#include <vector>
//Local Includes
#include "Pokemon.h"

namespace PokemonGo
{
	class Trainer{
        public:
        //Trainer constructor.
		Trainer();
        //Trainer constructor.
        Trainer(std::vector<Pokemon> ownedPokemon, std::vector<Pokemon> chosenPokemon);

        //Purpose: Start a battle between two players.
        void battle(Trainer& player2);

        //Purpose: One entire turn for the player.
        void take_turn(Trainer& enemy);

        //Purpose: Output text to the user's screen based on the current status of the player's
        //Pokemon, and show the user the available options for the turn so that he/she
        //knows what to input when prompted by take_turn
        void turn_text();

        //Purpose: Based on the user's input in reference to turn_text(), do the desired function.
        //Note: Refer to Trainer::turn_text() above to see what each action input
        //is expected to do, based on the prompts given to the user.
        //WARNING: DOES NOT PLAY NICE IF USER INPUTS A NON-NUMBER
        //(but feel free to try... it's kinda fun)
        void turn_action(unsigned int action, Trainer& enemyTrainer);

        //Purpose: Perform the Pokemon's fast attack.
        void battle_fast_attack(Pokemon& defendingPokemon);

        //Purpose: Perform the Pokemon's 1st charge attack.
        void battle_charge_attack1(Pokemon& defendingPokemon, Trainer& enemy);

        //Purpose: Perform the Pokemon's 2nd charge attack.
        void battle_charge_attack2(Pokemon& defendingPokemon, Trainer& enemy);

         //Purpose: the user switches the active pokemon.
        void switch_active_pokemon(unsigned char new_pokemon);

        //Purpose: Force the user to switch out their pokemon in the case that its hp is 0.
        void force_switch();

        //Purpose: uses a player's shield to negate a charge move, if the player wishes to.
        bool use_shield();

        //Purpose: switches which player's turn it is.
        static void switch_turn();

        //Purpose: Fully heal every pokemon on the trainer's team, and set each Pokemon's energy to 0.
        void full_restore();

        //Get and return the hp of the pokemon at the specified index of the trainer's chosen_pokemon vector.
        unsigned int get_chosen_pokemon_hp(unsigned char pokemonNumber);

        //Return the number of shields the trainer has remaining, as an integer
        int get_shield_count() const;

        //Purpose: get the player's current pokemon
        Pokemon& get_chosen_pokemon();

        private:
        //A static variable to control which player's turn it is.
        // True if it is player 1's turn.
        //False if it is player 2's turn.
		static bool player_1_turn;

        //A vector containing all the Pokemon a Trainer owns.
		std::vector<Pokemon> owned_pokemon;

        //A vector containing the Pokemon a Trainer is bringing
        // into battle from the owned_pokemon vector.
		std::vector<Pokemon> chosen_pokemon;

        //The number of shields the trainer has, which is subtracted by 1
        //  whenever one is used and set to 2 before a battle.
        //  A shield is used to negate one enemy charge attack.
        //The index at which the active Pokemon is stored
		int shield_count = 2;

        //    in the chosen_pokemon vector.
		unsigned char active_pokemon = 0;
	};
}

#endif // TRAINER_H
