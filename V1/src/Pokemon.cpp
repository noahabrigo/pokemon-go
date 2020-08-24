//Standard library includes
#include <cstdlib> // used for the randomization of iv's
#include <iostream>

#include <math.h>
#include <string>
#include <vector>

//Local Includes
#include "Pokemon.h"
#include "Trainer.h"

namespace PokemonGo
{
	//0 = Normal, 1 = Fire, 2 = Water, 3 = Grass, 4 = Electric, 5 = Ice, 6 = Fighting, 7 = Poison, 8 = Ground, 9 = Flying, 10 = Physic, 11 = Bug, 12 = Rock, 13 = Ghost, 14 = Dragon, 15 = Dark, 16 = Steel, 17 = Fairy
	//o = Normal Damage(1), N = Not Very Effective(0.625) S = Super Effective(1.6) I = Immune(0.391)

	const unsigned char Pokemon::TLM[19][19] = {
	   // 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17
		{'o', 'S', 'o', 'o', 'N', 'N', 'N', 'N', 'N', 'S', 'o', 'o', 'o', 'N', 'S', 'o', 'N', 'o', 'o'}, // Row 0, Bug Match ups
		{'o', 'N', 'o', 'o', 'N', 'N', 'o', 'o', 'S', 'o', 'o', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'o'}, // Row 1, Dark Match ups
		{'o', 'o', 'S', 'o', 'I', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'N', 'o', 'o'}, // Row 2, Dragon Match ups
		{'o', 'o', 'N', 'N', 'o', 'o', 'o', 'S', 'o', 'N', 'I', 'o', 'o', 'o', 'o', 'o', 'o', 'S', 'o'}, // Row 3, Electric Match ups
		{'o', 'S', 'S', 'o', 'o', 'S', 'N', 'o', 'o', 'o', 'o', 'o', 'o', 'N', 'o', 'o', 'N', 'o', 'o'}, // Row 4, Fairy Match ups
		{'N', 'S', 'o', 'o', 'N', 'o', 'o', 'N', 'I', 'o', 'o', 'S', 'S', 'N', 'N', 'S', 'S', 'o', 'o'}, // Row 5, Fighting Match ups
		{'S', 'o', 'N', 'o', 'o', 'o', 'N', 'o', 'o', 'S', 'o', 'S', 'o', 'o', 'o', 'N', 'S', 'N', 'o'}, // Row 6, Fire Match ups
		{'S', 'o', 'o', 'N', 'o', 'S', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'o', 'o', 'N', 'N', 'o', 'o'}, // Row 7, Flying Match ups
		{'o', 'N', 'o', 'o', 'o', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'I', 'o', 'S', 'o', 'o', 'o', 'o'}, // Row 8, Ghost Match ups
		{'N', 'o', 'N', 'o', 'o', 'o', 'N', 'N', 'o', 'N', 'S', 'o', 'o', 'N', 'o', 'S', 'N', 'S', 'o'}, // Row 9, Grass Match ups
		{'N', 'o', 'o', 'S', 'o', 'o', 'S', 'I', 'o', 'N', 'o', 'o', 'o', 'S', 'o', 'S', 'S', 'o', 'o'}, // Row 10, Ground Match ups
		{'o', 'o', 'S', 'o', 'o', 'o', 'N', 'S', 'o', 'S', 'S', 'N', 'o', 'o', 'o', 'o', 'N', 'N', 'o'}, // Row 11, Ice Match ups
		{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'I', 'o', 'o', 'o', 'o', 'o', 'o', 'N', 'N', 'o', 'o'}, // Row 12, Normal Match ups
		{'o', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'N', 'S', 'N', 'o', 'o', 'N', 'o', 'N', 'I', 'o', 'o'}, // Row 13, Poison Match ups
		{'o', 'I', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'S', 'N', 'o', 'N', 'o', 'o'}, // Row 14, Physic Match ups
		{'S', 'o', 'o', 'o', 'o', 'N', 'S', 'S', 'o', 'o', 'N', 'S', 'o', 'o', 'o', 'o', 'N', 'o', 'o'}, // Row 15, Rock Match ups
		{'o', 'o', 'o', 'N', 'S', 'o', 'N', 'o', 'o', 'o', 'o', 'S', 'o', 'o', 'o', 'S', 'N', 'N', 'o'}, // Row 16, Steel Match ups
		{'o', 'o', 'N', 'o', 'o', 'o', 'S', 'o', 'o', 'N', 'S', 'o', 'o', 'o', 'o', 'S', 'o', 'N', 'o'}, // Row 17, Water Match ups
		{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'}  // Row 18, Uninitialized Pokemon Type
	};



	//Purpose: Decrease the Pokemon's cooldown by the specified amount.
	//Preconditions: A Pokemon object this is used on, and the amount to decrease the cooldown by.
	//Postconditions: the Pokemon's cooldown variable is set to its value - 0.5
	void Pokemon::decrease_cooldown(float amount){
		cooldown -= amount;
		}

	//Purpose: add the energy amount to the Pokemon's energy
	//Preconditions: a pokemon object and an energy amount
	//This energy can be positive (like when using fast moves)
	//or negative (like when using charge moves)
	//Postconditions: the pokemon's energy is increased/decreased by the desired amount.
	void Pokemon::add_energy(int energy_amount){
		energy += energy_amount;
	}

	//Teach move functions:
	//Purpose: Teach a Pokemon a new move in place of an old one, if it can learn that move.
	//Preconditions: A Pokemon with a pool of learnable moves, and the new move to teach the Pokemon.
	//Postconditions: If the Pokemon can learn the move, replace the old move with the new one. Otherwise, do nothing.
	void Pokemon::replace_fast_move(Fast_Move& newMove){
		for(int i = 0; i < learnable_fast_moves.size(); i++){
				if(learnable_fast_moves[i].get_name() == newMove.get_name()){
					fast_move = newMove;
			}
		}
	}
	void Pokemon::replace_charge_move1(Charge_Move& newMove){
		for(int i = 0; i < learnable_charge_moves.size(); i++){
				if(learnable_charge_moves[i].get_name() == newMove.get_name()){
					charge_move1 = newMove;
			}
		}
	}
	void Pokemon::replace_charge_move2(Charge_Move& newMove){
		for(int i = 0; i < learnable_charge_moves.size(); i++){
				if(learnable_charge_moves[i].get_name() == newMove.get_name()){
					charge_move2 = newMove;
				}
			}
	}

	//Purpose: get the Pokemon's charge move's specified value.
	//Preconditions: A pokemon object with the desired charge move with the desired variable.
	//Postconditions: returns the value of the variable.

	std::string Pokemon::get_fast_move_name() const {
		return fast_move.get_name();
	}

	std::string Pokemon::get_charge_move1_name() const {
		return charge_move1.get_name();
	}

	std::string Pokemon::get_charge_move2_name() const {
		return charge_move2.get_name();
	}

	int Pokemon::get_charge_move1_energy() {
		return (charge_move1.get_energy_delta() * -1);
	}

	int Pokemon::get_charge_move2_energy() {
		return (charge_move2.get_energy_delta() * -1);
	}

	int Pokemon::get_neg_charge_move1_energy() {
		return charge_move1.get_energy_delta();
	}

	int Pokemon::get_neg_charge_move2_energy() {
		return charge_move2.get_energy_delta();
	}


	//Purpose: use a pokemon's fast attack.
	//Preconditions: used on the attacking pokemon object, using defending pokemon as a parameter.
	//Postconditions: If the pokemon's cooldown is 0,
	//The energy delta is added to the pokemon's energy
	//and the damage is subtracted from the defending pokemon's hp.
	//If the cooldown is not 0, then the cooldown decriments by 0.5
	void Pokemon::use_fast_attack(Pokemon& defendingPokemon){
		if(get_cooldown() > 0){decrease_cooldown(0.5);} else {
		defendingPokemon.subtract_from_hp(calculate_damage(*this, defendingPokemon, fast_move));
		add_energy(fast_move.get_energy_delta());
		cooldown = fast_move.get_cooldown();
		}
	}

	//Purpose: use a pokemon's charge attack.
	//Preconditions: used on the attacking pokemon object, using defending pokemon as a parameter.
	//Postconditions: If the pokemon has enough energy to use the move,
	//The energy cost is subtracted from the pokemon's energy
	//and the damage is subtracted from the defending pokemon's hp.
	//Note: Shields are not involved at the Pokemon level; only at the trainer level.
	void Pokemon::use_charge_attack1(Pokemon& defendingPokemon){
		if(energy >= (charge_move1.get_energy_delta() * -1)){
			add_energy(charge_move1.get_energy_delta());
			defendingPokemon.subtract_from_hp(calculate_damage(*this, defendingPokemon, charge_move1));
		}
	}

	void Pokemon::use_charge_attack2(Pokemon& defendingPokemon){
		if(energy >= (charge_move2.get_energy_delta() * -1)){
			add_energy(charge_move2.get_energy_delta());
			defendingPokemon.subtract_from_hp(calculate_damage(*this, defendingPokemon, charge_move2));
		}
	}


	//Purpose: calculate the damage that an attack deals.
	//Preconditions: The attacking pokemon, the defending pokemon, and the move used.
	//                  can be a fast move or a charge move.
	//Postconditions: returns the amount of damage the move deals to the defending pokemon.
	float Pokemon::calculate_damage(Pokemon& attacker, Pokemon& defender, Fast_Move& fastMove) {
		//though this could be done in one line, it is divided for clarity
		float cATK_attacker = ( attacker.get_base_atk() + attacker.get_iv_atk() ) * CPM[ attacker.get_levelx2() - 1 ];
		float cDEF_defender = ( defender.get_base_def() + defender.get_iv_def() ) * CPM[ defender.get_levelx2() - 1 ];
		float effectiveness = get_effectiveness(defender.type1, fastMove.get_type()) *                              //compute for both pokemon types
								get_effectiveness(defender.type2, fastMove.get_type());
		float multiplier = get_stab(attacker.type1, attacker.type2, fastMove.get_type()) * effectiveness;
		if(effectiveness > 1){std::cout << "It's super effective!" << std::endl;}
		else if(effectiveness < 1){std::cout << "It's not very effective..." << std::endl;}
		return  floor( 0.5  * fastMove.get_base_power() * (cATK_attacker / cDEF_defender) * multiplier ) + 1;
	}

	float Pokemon::calculate_damage(Pokemon& attacker, Pokemon& defender, Charge_Move& chargeMove) {
		//though this could be done in one line, it is divided for clarity
		float cATK_attacker = ( attacker.get_base_atk() + attacker.get_iv_atk() ) * CPM[ attacker.get_levelx2() - 1 ];
		float cDEF_defender = ( defender.get_base_def() + defender.get_iv_def() ) * CPM[ defender.get_levelx2() - 1 ];
		float effectiveness = get_effectiveness(defender.type1, chargeMove.get_type()) *                            //compute for both pokemon types
		get_effectiveness(defender.type2, chargeMove.get_type());
		float multiplier = get_stab(attacker.type1, attacker.type2, chargeMove.get_type()) * effectiveness;
		if(effectiveness > 1){std::cout << "It's super effective!" << std::endl;}
		else if(effectiveness < 1){std::cout << "It's not very effective..." << std::endl;}
		return  floor( 0.5  * chargeMove.get_base_power() * (cATK_attacker / cDEF_defender) * multiplier ) + 1;
	}

	//Purpose: determine if an attack should by multiplied by a same type attack bonus modifier.
	//Preconditions: An attacking pokemon's type(s), and the move's type.
	//Note: pokemon with one type have 18 as type 2.
	//Postconditions: Return 1.2 if STAB applies; return 1 if it does not.
	float Pokemon::get_stab(int attackerType1, int attackerType2, int moveType){
		if(attackerType1 == moveType || attackerType2 == moveType){
		return 1.2;
		}
	return 1;
	}


	//Purpose: increase the Pokemon's level by .5
	//Preconditions: a Pokemon to level up
	//Postconditions: the Pokemon's level will be increased by a half (levelx2 will be increased by 1),
	//                and the hp will be calculated accordingly.
	void Pokemon::level_up(){
		levelx2++;
		calculateMaxHP();
	}

	//Purpose: set the Pokemon's level to the input level
	//Preconditions: the new level of the Pokemon, which may be a full number or a number + .5
	//Postconditions: the Pokemon's levelx2 variable will be set to double the input value,
	//                and the hp will be calculated accordingly.
	void Pokemon::set_level(float newLevel){
		levelx2 = newLevel * 2;
		calculateMaxHP();
	}

	//Purpose: set the Pokemon's levelx2 to the input level
	//Preconditions: the new level of the Pokemon x 2, which must be an int
	//Postconditions: the Pokemon's levelx2 variable will be set to the input value,
	//                and the hp will be calculated accordingly.
	void Pokemon::set_levelx2(int newLevel){
		levelx2 = newLevel;
		calculateMaxHP();
	}

	//Purpose: get the Pokemon's level, times 2 to work better with the CPM array
	//Precondition: An object of the Pokemon class
	//Postconditions: Returns the Pokemon's level, times 2, as an int
	int Pokemon::get_levelx2() const {
		return levelx2;
	}

	//Purpose: set the pokemon's level to the default level (run in constructor; default level = 10)
	//                                                          so levelx2 = 20
	//Preconditions: a pokemon object
	//Postconditions: the levelx2 variable of the pokemon is set to double the default level.
	 void Pokemon::set_default_level(){
		levelx2 = 20;
	 }

	//Purpose: Calculate and set the Pokemon's max hp.
	//Preconditions: A Pokemon to calculate the hp stat for.
	//Postconditions: The pokemon's new level will be set based on its level and sta stats.
	//                  hp will be set to maxhp.
	void Pokemon::calculateMaxHP(){
		maxhp = floor( (base_sta + iv_sta) * CPM[levelx2 - 1] );
		full_restore();
	}

	//Purpose: Get the Pokemon's current hp stat.
	//Preconditions: An object of the Pokemon class.
	//Postconditions: Returns the Pokemon's current hp value as an int.
	unsigned int Pokemon::get_hp() const {
		return hp;
	}


	//Purpose: Subtract damage from a Pokemon's health.
	//Preconditions: A Pokemon object, and how much damage to subtract from the Pokemon's hp.
	//Postconditions: The Pokemon's health is subtracted by the damage.
	//                If the hp stat would go below 0, it instead is set to 0.
	void Pokemon::subtract_from_hp(int damage){
		if(damage < hp){
		hp -= damage;
		}
		else {
		hp = 0;
		}
	}

	//Purpose: Reset a Pokemon to its default state.
	//Preconditions: A Pokemon object.
	//Postconditions: The Pokemon is at full health with no energy or cooldown.
	void Pokemon::full_restore(){
	hp = maxhp;
	energy = 0;
	cooldown = 0;
	}




	//Purpose: Find how effective the attacking type is on the defending pokemon.
	//Preconditions: The type of the Pokemon being attacked, and the type of the Attack being used.
	//Postconditions: Return the multiplier associated with the type matchup.
	float Pokemon::get_effectiveness(int defenderType, int attackType){
		double finalMultiplier = 1;
		unsigned char effect1 = TLM[attackType][defenderType];
		if(effect1 == 'o')
			finalMultiplier *= 1;
		else if(effect1 == 'N')
			finalMultiplier *= 0.625;
		else if(effect1 == 'S')
			finalMultiplier *= 1.6;
		else // Immune
			finalMultiplier *= 0.391;
		if(type2 == 18)
			return finalMultiplier;
		else
		{
			unsigned char effect2 = TLM[attackType][defenderType];
			if(effect2 == 'o')
				finalMultiplier *= 1;
			else if(effect2 == 'N')
				finalMultiplier *= 0.625;
			else if(effect2 == 'S')
				finalMultiplier *= 1.6;
			else // Immune
				finalMultiplier *= 0.391;
			return finalMultiplier;
		}

	}


		//Purpose: get the Pokemon's specified value.
		//Preconditions: A pokemon object with the desired variable.
		//Postconditions: returns the value of the variable.
	std::string Pokemon::get_name() const {
		return name;
	}



		unsigned int Pokemon::get_base_atk() const {
			return base_atk;
		}
		unsigned int Pokemon::get_base_def() const {
			return base_def;
		}
		unsigned int Pokemon::get_base_sta() const {
			return base_sta;
		}
		unsigned int Pokemon::get_iv_atk() const {
			return iv_atk;
		}
		unsigned int Pokemon::get_iv_def() const {
			return iv_def;
		}
		unsigned int Pokemon::get_iv_sta() const {
			return iv_sta;
		}

		float Pokemon::get_cooldown() const {
			return cooldown;
		}

		int Pokemon::get_energy() const {
			return energy;
		}

		//Purpose: Set the Pokemon's variable to a new value
		//Preconditions: A Pokemon object and a new value for the desired variable.
		//Postconditions: The Pokemon's variable is set to the new value,
		//                  and max health is updated appropriately if sta is affected.
		void Pokemon::set_base_atk(unsigned int new_atk){
			base_atk = new_atk;
		}
		void Pokemon::set_base_def(unsigned int new_def){
			base_def = new_def;
		}
		void Pokemon::set_base_sta(unsigned int new_sta){
			base_sta = new_sta;
			calculateMaxHP(); // configured to new stats
		}
		void Pokemon::set_base(unsigned int new_atk, unsigned int new_def, unsigned int new_sta){
			set_base_atk(new_atk);
			set_base_def(new_def);
			set_base_sta(new_sta);
			calculateMaxHP(); // configured to new stats
		}
		void Pokemon::set_iv_atk(unsigned int new_atk){
			iv_atk = new_atk;
		}
		void Pokemon::set_iv_def(unsigned int new_def){
			iv_def = new_def;
		}
		void Pokemon::set_iv_sta(unsigned int new_sta){
			iv_sta = new_sta;
			calculateMaxHP(); // configured to new stats
		}
		void Pokemon::set_iv(unsigned int new_atk, unsigned int new_def, unsigned int new_sta){
			set_iv_atk(new_atk);
			set_iv_def(new_def);
			set_iv_sta(new_sta);
			calculateMaxHP(); // configured to new stats
		}

		//Purpose: Give a Pokemon random iv values between 0 and 15.
		//          Called by constructor when Pokemon aren't assigned iv values.
		//Precondition: A Pokemon object.
		//Postconditions: The Pokemon has a random value between 0 and 15 assigned
		//              to the atk, def, and sta iv values.
		void Pokemon::randomize_ivs(){
			set_iv(rand() % 15, rand() % 15, rand() % 15);
		}

		//Purpose: Teach a Pokemon its first learnable fast move and first learnable charge move.
		//          Called by constructor when Pokemon aren't assigned a fast move and charge move.
		//Precondition: A Pokemon object with a vector of learnable fast moves and a vector of
		//          learnable charge moves.
		//Postconditions: The Pokemon is taught the first fast move in the learnable fast moves
		//          vector and the first charge move in the learnable charge moves vector.
		void Pokemon::give_default_moves(){
			fast_move = learnable_fast_moves[0];
			charge_move1 = learnable_charge_moves[0];
		}

	//The remaining definitions are just the many, many possible constructors the user may want to use when initializing Pokemon.

	//NOTE: Although Pokemon can only be taught moves on their learnable moves list,
	//      They can be initialized with moves they otherwise cannot learn.
	//      This is to account for Pokemon that know moves that they can no longer learn,
	//      Such as legacy moves.

	//one type
		//learnable moves
	//No moves:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1,                                                                           //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(18),                                                             //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();
			give_default_moves();};                                                                     //randomize iv values

	//One fast move, one charge move:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1,                                                                           //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			const Fast_Move fastMove, const Charge_Move chargeMove,                                     //Known Moves
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(18),                                                             //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			fast_move(fastMove), charge_move1(chargeMove),                                              //Known Moves
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();};                                                                          //randomize iv values

	//One fast move, two charge moves:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1,                                                                           //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,     //Known Moves
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(18),                                                             //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			fast_move(fastMove), charge_move1(chargeMove1), charge_move2(chargeMove2),                  //Known Moves
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();};                                                                          //randomize iv values

	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
				int pokemonType1,                                                                       //Pokemon type
				const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,     //Base stats
				const Fast_Move fastMove, const Charge_Move chargeMove1,                                //Known Moves
				std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,//Learnable moves
				float newLevel,                                                                         //level
				const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta)        //IV stats
			:   name(pokemonName),                                                                      //Pokemon name
				type1(pokemonType1), type2(18),                                                         //Pokemon type
				base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                //Base stats
				fast_move(fastMove), charge_move1(chargeMove1),                                         //Known Moves
				learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves), //Learnable moves
				iv_atk(ivAtk), iv_def(ivDef), iv_sta(ivSta)                                             //iv values
				{set_level(newLevel); calculateMaxHP();};                                               //calculate HP

	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
				int pokemonType1,                                                                       //Pokemon type
				const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,     //Base stats
				const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2, //Known Moves
				std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves, //Learnable moves
				float newLevel,                                                                         //level
				const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta)        //IV stats
			:   name(pokemonName),                                                                      //Pokemon name
				type1(pokemonType1), type2(18),                                                         //Pokemon type
				base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                //Base stats
				fast_move(fastMove), charge_move1(chargeMove1), charge_move2(chargeMove2),              //Known Moves
				learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves), //Learnable moves
				iv_atk(ivAtk), iv_def(ivDef), iv_sta(ivSta)                                             //iv values
				{set_level(newLevel); calculateMaxHP();};                                               //calculate HP

	//Pokemon with two types
	//learnable moves

	//No moves:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1, int pokemonType2,                                                         //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(pokemonType2),                                                   //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();
			give_default_moves();};                                                                     //randomize iv values

	//One fast move, one charge move:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1, int pokemonType2,                                                         //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			const Fast_Move fastMove, const Charge_Move chargeMove,                                     //Known Moves
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(pokemonType2),                                                   //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			fast_move(fastMove), charge_move1(chargeMove),                                              //Known Moves
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();};                                                                          //randomize iv values

	//One fast move, two charge moves:
	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
			int pokemonType1, int pokemonType2,                                                         //Pokemon type
			const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,         //Base stats
			const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2,     //Known Moves
			std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves)   //Learnable moves
		:   name(pokemonName),                                                                          //Pokemon name
			type1(pokemonType1), type2(pokemonType2),                                                   //Pokemon type
			base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                    //Base stats
			fast_move(fastMove), charge_move1(chargeMove1), charge_move2(chargeMove2),                  //Known Moves
			learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves)      //Learnable moves
			{set_default_level();                                                                       //sets level to 20
			calculateMaxHP();                                                                           //calculate HP
			randomize_ivs();};                                                                          //randomize iv values

	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
				int pokemonType1, int pokemonType2,                                                     //Pokemon type
				const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,     //Base stats
				const Fast_Move fastMove, const Charge_Move chargeMove1,                                //Known Moves
				std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves,//Learnable moves
				float newLevel,                                                                         //level
				const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta)        //IV stats
			:   name(pokemonName),                                                                      //Pokemon name
				type1(pokemonType1), type2(pokemonType2),                                               //Pokemon type
				base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                //Base stats
				fast_move(fastMove), charge_move1(chargeMove1),                                         //Known Moves
				learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves), //Learnable moves
				iv_atk(ivAtk), iv_def(ivDef), iv_sta(ivSta)                                             //ivs
				{set_level(newLevel); calculateMaxHP();};                                               //calculate HP

	Pokemon::Pokemon(std::string pokemonName,                                                           //Pokemon name
				int pokemonType1, int pokemonType2,                                                     //Pokemon type
				const unsigned int baseAtk, const unsigned int baseDef, const unsigned int baseSta,     //Base stats
				const Fast_Move fastMove, const Charge_Move chargeMove1, const Charge_Move chargeMove2, //Known Moves
				std::vector<Fast_Move> learnableFastMoves, std::vector<Charge_Move> learnableChargeMoves, //Learnable moves
				float newLevel,                                                                         //level
				const unsigned char ivAtk, const unsigned char ivDef, const unsigned char ivSta)        //IV stats
			:   name(pokemonName),                                                                      //Pokemon name
				type1(pokemonType1), type2(pokemonType2),                                               //Pokemon type
				base_atk(baseAtk), base_def(baseDef), base_sta(baseSta),                                //Base stats
				fast_move(fastMove), charge_move1(chargeMove1), charge_move2(chargeMove2),              //Known Moves
				learnable_fast_moves(learnableFastMoves), learnable_charge_moves(learnableChargeMoves), //Learnable moves
				iv_atk(ivAtk), iv_def(ivDef), iv_sta(ivSta)                                             //ivs
				{set_level(newLevel); calculateMaxHP();};                                               //calculate HP

	//The array that contains all CPM multipliers,
	//indexed by levelx2, or level * 2, for simplicity.
	const float Pokemon::CPM[] = {
	0.094,
	0.1351374318,
	0.16639787,
	0.192650919,
	0.21573247,
	0.2365726613,
	0.25572005,
	0.2735303812,
	0.29024988,
	0.3060573775,
	0.3210876,
	0.3354450362,
	0.34921268,
	0.3624577511,
	0.3752356,
	0.387592416,
	0.39956728,
	0.4111935514,
	0.4225,
	0.4329264091,
	0.44310755,
	0.4530599591,
	0.4627984,
	0.472336093,
	0.48168495,
	0.4908558003,
	0.49985844,
	0.508701765,
	0.51739395,
	0.5259425113,
	0.5343543,
	0.5426357375,
	0.5507927,
	0.5588305862,
	0.5667545,
	0.5745691333,
	0.5822789,
	0.5898879072,
	0.5974,
	0.6048236651,
	0.6121573,
	0.6194041216,
	0.6265671,
	0.6336491432,
	0.64065295,
	0.6475809666,
	0.65443563,
	0.6612192524,
	0.667934,
	0.6745818959,
	0.6811649,
	0.6876849038,
	0.69414365,
	0.70054287,
	0.7068842,
	0.7131691091,
	0.7193991,
	0.7255756136,
	0.7317,
	0.7347410093,
	0.7377695,
	0.7407855938,
	0.74378943,
	0.7467812109,
	0.74976104,
	0.7527290867,
	0.7556855,
	0.7586303683,
	0.76156384,
	0.7644860647,
	0.76739717,
	0.7702972656,
	0.7731865,
	0.7760649616,
	0.77893275,
	0.7817900548,
	0.784637,
	0.7874736075,
	0.7903,
	};

	//Just a global list of all the string name for the types. This info is aligned with the pkmn's type number 0-18, 19 is a blank type meant for initialization
	//so that the default type isn't bug on initialization
	std::string types[19] = {
		"Bug",      //0
		"Dark",     //1
		"Dragon",   //2
		"Electric", //3
		"Fairy",    //4
		"Fighting", //5
		"Fire",     //6
		"Flying",   //7
		"Ghost",    //8
		"Grass",    //9
		"Ground",   //10
		"Ice",      //11
		"Normal",   //12
		"Poison",   //13
		"Psychic",  //14
		"Rock",     //15
		"Steel",    //16
		"Water",    //17
		""          //18
	};
}
