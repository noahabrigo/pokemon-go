#ifndef POKEMON_H
#define POKEMON_H

#include "Fast_Move.h"
#include "Charge_Move.h"

//Standard library includes
#include <string>
#include <vector>
#include <cstdlib> // used for the randomization of iv's

namespace PokemonGo
{
	class Pokemon{
		private:
        // a vector of the fast moves the pokemon can learn
		std::vector<Fast_Move> learnable_fast_moves;
		// a vector of the charge moves the pokemon can learn
		std::vector<Charge_Move> learnable_charge_moves;

		//The pokemon's learned fast move
		Fast_Move fast_move;
		// The pokemon's learned charge move 1
		Charge_Move charge_move1;
		// The pokemon's learned charge move 2
		Charge_Move charge_move2;

		// The pokemon's name
		std::string name = "";
		// The pokemon's first type
		int type1 =18;
		 // The pokemon's second type (or, if only one, "none")
		int type2 =18;

		//Level multiplied by two, so that half-levels become full numbers.
		//   Therefore, level 26.5 = 53, level 40 = 80, etc.
		//   This is done to simplify the use of the CPM array,
		//   because levelx2 is used as an index during calculations.
		unsigned char levelx2;
		// Base stats
		// used to calculate the damage an attacker deals
		unsigned int base_atk =0;
		// used to calculate how much damage a defender takes
		unsigned int base_def =0;
		// used to compute max health
		unsigned int base_sta =0;

		// IV stats, which are between 0-15
		// used to calculate the damage an attacker deals
		unsigned char iv_atk =0;
		// used to calculate how much damage a defender takes
		unsigned char iv_def =0;
		// used to compute max health
		unsigned char iv_sta =0;

		//Automatically calculated and set by constructor, and whenever Pokemon levels up.
		//  hp is set to this value upon full restore.
		unsigned int maxhp =0;

		// Temporary/current health value.
		// Changes whenever the Pokemon takes damage,
		// and is set equal to maxhp upon full restore.
		unsigned int hp =0;

		//Array for multipliers calculation
		const static unsigned char TLM[19][19];

		//Stores the amount of energy a Pokemon has.
		//Fast moves increase energy.
		//Charge moves cost a certain amount of energy to be used.
		//(signed for comparison purposes)
		int energy = 0;

		//Amount of time a pokemon must wait to use another fast move.
		//Decrements by 0.5 per turn.
		float cooldown = 0;

		//pokedex #, for organization
		unsigned int dex = 0;
		//Pokemon Marowak and Alolan_Marowak will still be different entirely
		//- this would be entirely used for deciding dex order
		bool is_alolan = false;

	public:
	    //The array that contains all CPM multipliers,
		//indexed by levelx2, or level * 2, for simplicity.
		const static float CPM[];

		//Purpose: use a pokemon's fast attack.
		void use_fast_attack(Pokemon& defendingPokemon);

		//Purpose: use a pokemon's charge attack.
		void use_charge_attack1(Pokemon& defendingPokemon);
		void use_charge_attack2(Pokemon& defendingPokemon);

		//Teach move functions:
		//Purpose: Teach a Pokemon a new move in place of an old one, if it can learn that move.
		void replace_fast_move(Fast_Move& newMove);
		void replace_charge_move1(Charge_Move& newMove);
		void replace_charge_move2(Charge_Move& newMove);

		//Purpose: Decrease the Pokemon's cooldown by the specified amount
		void decrease_cooldown(float amount);

		//Purpose: determine if an attack should by multiplied by a same type attack bonus modifier.
		float get_stab(int attackerType1, int attackerType2, int moveType);

        //Purpose: Find how effective the attacking type is on the defending pokemon.
		float get_effectiveness(int defenderType, int attackType);

		//Purpose: calculate the damage that an attack deals.
		float calculate_damage (Pokemon& attacker, Pokemon& defender, Fast_Move& fastMove);
		float calculate_damage(Pokemon& attacker, Pokemon& defender, Charge_Move& chargeMove);

		//Purpose: Calculate and set the Pokemon's max hp.
		void calculateMaxHP();

		//Purpose: Get the Pokemon's current hp stat.
		unsigned int get_hp() const;

		//Purpose: Subtract damage from a Pokemon's health.
		void subtract_from_hp(int damage);

		//Purpose: Reset a Pokemon to its default state.
		void full_restore();

		//Purpose: add the energy amount to the Pokemon's energy
		void add_energy(int energy_amount);

		//Purpose: Give a Pokemon random iv values between 0 and 15.
		void randomizeIV();

		//Purpose: set the pokemon's level to the default level (run in constructor; default level = 10)
		void set_default_level();

		//Purpose: increase the Pokemon's level by .5
		void level_up();

		//Purpose: get the Pokemon's level, times 2 to work better with the CPM array
		int get_levelx2() const;

		//Purpose: set the Pokemon's level to the input level
		void set_level(float newLevel);

		//Purpose: set the Pokemon's levelx2 to the input level
		void set_levelx2(int newLevel);

		//Purpose: get the Pokemon's specified value.
		std::string get_name() const;
		unsigned int get_base_atk() const;
		unsigned int get_base_def() const;
		unsigned int get_base_sta() const;
		unsigned int get_iv_atk() const;
		unsigned int get_iv_def() const;
		unsigned int get_iv_sta() const;
		float get_cooldown() const;
		int get_energy() const;

		//Purpose: get the Pokemon's charge move's specified value.
		std::string get_fast_move_name() const;
		std::string get_charge_move1_name() const;
		std::string get_charge_move2_name() const;
		int get_charge_move1_energy();
		int get_charge_move2_energy();
		int get_neg_charge_move1_energy();
		int get_neg_charge_move2_energy();

		//Purpose: Set the Pokemon's variable to a new value
		void set_base_atk(unsigned int new_atk);
		void set_base_def(unsigned int new_def);
		void set_base_sta(unsigned int new_sta);
		void set_base(unsigned int new_atk, unsigned int new_def, unsigned int new_sta);
		void set_iv_atk(unsigned int new_atk);
		void set_iv_def(unsigned int new_def);
		void set_iv_sta(unsigned int new_sta);
		void set_iv(unsigned int new_atk, unsigned int new_def, unsigned int new_sta);

		void randomize_ivs();                               //Purpose: Give a Pokemon random iv values between 0 and 15.

		void give_default_moves();                          //Purpose: Teach a Pokemon its first learnable fast move and first learnable charge move.

		Pokemon();

	//The remaining definitions are just the many, many possible constructors the user may want to use when initializing Pokemon.

	//NOTE: Although Pokemon can only be taught moves on their learnable moves list,
	//      They can be initialized with moves they otherwise cannot learn.
	//      This is to account for Pokemon that know moves that they can no longer learn,
	//      Such as legacy moves.


	//1 type
		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1,                                                                           //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves); //Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1,                                                                           //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove, //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves); //Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1,                                                                           //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,    //Known Moves
				  std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves);//Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1,                                                                           //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1,                                   //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,  //Learnable moves
				 float newLevel,                                                                            //level
				 const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta            //IV stats
				 );

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1,                                                                           //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,    //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,  //Learnable moves
				 float newLevel,                                                                            //level
				 const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta            //IV stats
				 );

	//2 types
		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1, int pokemonType2,                                                         //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves); //Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
			   int pokemonType1, int pokemonType2,                                                          //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1,                                   //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves); //Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1, int pokemonType2,                                                         //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,    //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves); //Learnable moves

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				int pokemonType1, int pokemonType2,                                                         //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1,                                   //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,  //Learnable moves
				 float newLevel,                                                                            //level
				 const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta            //IV stats
				 );

		Pokemon(std::string pokemonName,                                                                    //Pokemon name
				 int pokemonType1, int pokemonType2,                                                        //Pokemon type
				 const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,        //Base stats
				 const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,    //Known Moves
				 std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,  //Learnable moves
				 float newLevel,                                                                            //level
				 const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta            //IV stats
				 );

	};
}
#endif // POKEMON_H
