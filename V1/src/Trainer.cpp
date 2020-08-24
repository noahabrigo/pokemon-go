//Standard library includes
#include <iostream>
#include <vector>

//Local Includes
#include "Trainer.h"

using std::cout;
using std::endl;

namespace PokemonGo
{
	Trainer::Trainer(){}
	//Trainer constructor.
	Trainer::Trainer(std::vector<Pokemon> ownedPokemon, std::vector<Pokemon> chosenPokemon)
			:owned_pokemon(ownedPokemon), chosen_pokemon(chosenPokemon) {}

	bool Trainer::player_1_turn = true; //A static variable to control which player's turn it is.


	//Purpose: Fully heal every pokemon on the trainer's team, and set each Pokemon's energy to 0.
	//Reset shield count to 2.
	//Preconditions: a trainer with a vector of 3 chosen pokemon
	//Postconditions: The each pokemon in the trainer's chosen_pokemon vector has its hp set to its maxhp,
	//they have their energy set to 0, and the trainer now has 2 shields.
	void Trainer::full_restore(){
		shield_count = 2;
		for(int i = 0; i < 3; i++){
	chosen_pokemon[i].full_restore();
		}
	}

	//Get and return the hp of the pokemon at the specified index of the trainer's chosen_pokemon vector.
	unsigned int Trainer::get_chosen_pokemon_hp(unsigned char pokemonNumber) {
	return chosen_pokemon[pokemonNumber].get_hp();
	}

	//Purpose: get the player's current pokemon
	//Preconditions: the pokemon's index in the chosen_pokemon vector
	//Postconditions: the pokemon at that index is returned
	Pokemon& Trainer::get_chosen_pokemon() {
	return chosen_pokemon[active_pokemon];
	}

	//Purpose: Start a battle between two players.
	//Preconditions: Two trainers, each with a vector of 3 chosen pokemon.
	//Postconditions: A battle is initiated between the two players.
	void Trainer::battle(Trainer& player2){
	full_restore(); // The player's teams are fully healed and their shields reset before the battle.
	player2.full_restore(); //^
			//Repeat the following until a player has no pokemon remaining.
	while((chosen_pokemon[0].get_hp() > 0 || chosen_pokemon[1].get_hp() > 0 || chosen_pokemon[2].get_hp() > 0) &&
		   (player2.get_chosen_pokemon_hp(0) > 0 || player2.get_chosen_pokemon_hp(1) > 0 || player2.get_chosen_pokemon_hp(2) > 0)){
			//Decide who's turn it is, and have them take the turn.
	if(player_1_turn){(*this).take_turn(player2);}
	else{player2.take_turn(*this);}
	}
	}

	//Purpose: One entire turn for the player.
	//Preconditions: A player, and their enemy player.
	//Postconditions: The player gets to make a choice for the turn based on the availible inputs
	//prompted to the user.
	void Trainer::take_turn(Trainer& enemy){
		if(chosen_pokemon[active_pokemon].get_hp() == 0 &&
			(chosen_pokemon[0].get_hp() > 0 || chosen_pokemon[1].get_hp() > 0 || chosen_pokemon[2].get_hp() > 0))
				{force_switch(); switch_turn();} //If the pokemon is at 0 hp, it must be switched out.
	turn_text(); //Show the player his/her options
	unsigned int turn_choice; //Take the user's response
	std::cin >> turn_choice;
	turn_action(turn_choice, enemy); //Do something with the user's response
	}


	//Purpose: Output text to the user's screen based on the current status of the player's
	//Pokemon, and show the user the available options for the turn so that he/she
	//knows what to input when prompted by take_turn
	//Preconditions: A trainer, with a vector of 3 pokemon named chosen_pokemon, and an active
	//Pokemon at index active_pokemon of chosen_pokemon
	//Postconditions: The information for the turn is output to the screen.
	void Trainer::turn_text(){
	if(player_1_turn){cout << "Player 1's Turn. ";}
	else{cout << "Player 2's Turn. ";}
	cout << endl << "Current Pokemon: " << chosen_pokemon[active_pokemon].get_name() << endl;
	cout << "Health: " << chosen_pokemon[active_pokemon].get_hp() << endl;
	cout << "Cooldown: " << chosen_pokemon[active_pokemon].get_cooldown() << endl;
	cout << "Energy: " << chosen_pokemon[active_pokemon].get_energy() << endl;
	cout << "Shields: " << get_shield_count() << endl;
	//The enemy's stats are not shown because the user can simply scroll up to see the enemy stats,
	//and printout out the stats for both each turn is incredibly reduntant and annoying for the user.

	//Next, the available inputs for the various commands are shown to the player so that he/she may
	// decide what to do with his/her turn.
	//Notably, the user is only given the option to use a charge move 2 if the active pokemon has one.
	//If he/she tries to use a charge move 2 when there is none available, an error is outputted and
	//and are prompted to enter a new command.
	cout << "Enter:" << "0 to use fast attack, " << chosen_pokemon[active_pokemon].get_fast_move_name() << endl;
	cout << "      1 to use charge attack, ";
	if(chosen_pokemon[active_pokemon].get_energy() < chosen_pokemon[active_pokemon].get_charge_move1_energy()){
    //Displays the current pokemon's energy status compared to the energy required for the specific charge move
    cout << chosen_pokemon[active_pokemon].get_charge_move1_name()
         << " [Energy Charged: "
         << chosen_pokemon[active_pokemon].get_energy()
         << "/"
         << chosen_pokemon[active_pokemon].get_charge_move1_energy()
         << "]";
	}
	else{
        //If the current pokemon has power greater than or equal to the power required for the charge move, display [FULLy CHARGED]
        cout << "[FULLY CHARGED]";
	}
    cout << endl;
	if(chosen_pokemon[active_pokemon].get_charge_move2_energy() > 0){
	cout << "      2 to use charge attack 2, ";
	     if(chosen_pokemon[active_pokemon].get_energy() < chosen_pokemon[active_pokemon].get_charge_move2_energy()){
    //Displays the current pokemon's energy status compared to the energy required for the specific charge move
    cout << chosen_pokemon[active_pokemon].get_charge_move2_name()
         << " [Energy Charged: "
         << chosen_pokemon[active_pokemon].get_energy()
         << "/"
         << chosen_pokemon[active_pokemon].get_charge_move2_energy()
         << "]";
	}
	else{
	    //If the current pokemon has power greater than or equal to the power required for the charge move, display [FULLy CHARGED]
        cout << "[FULLY CHARGED]";
	}
    cout << endl;
	}
	cout << "      3 to switch to Pokemon 1, " << chosen_pokemon[0].get_name() << endl;
	cout << "      4 to switch to Pokemon 2, " << chosen_pokemon[1].get_name() << endl;
	cout << "      5 to switch to Pokemon 3, " << chosen_pokemon[2].get_name() << endl;

	}

	//Purpose: Based on the user's input in reference to turn_text(), do the desired function.
	//Preconditions: A trainer to use this on, an enemy trainer, and an input integer that tells
	//this function which operation to perform (the user knowns what to input from turn_text()
	//Postconditions: The desired action is performed, or, if the number is invalid, the turn restarts.
	//Note: Refer to Trainer::turn_text() above to see what each action input
	// is expected to do, based on the prompts given to the user.
	//WARNING: DOES NOT PLAY NICE IF USER INPUTS A NON-NUMBER
	//(but feel free to try... it's kinda fun)
	void Trainer::turn_action(unsigned int action, Trainer& enemyTrainer){
	if(action == 0){battle_fast_attack(enemyTrainer.get_chosen_pokemon());}
	else if(action == 1){battle_charge_attack1(enemyTrainer.get_chosen_pokemon(), enemyTrainer);}
	else if(action == 2){
			if(chosen_pokemon[active_pokemon].get_charge_move2_energy() > 0){battle_charge_attack2(enemyTrainer.get_chosen_pokemon(), enemyTrainer);
		} else {cout << "This Pokemon doesn't have a second charge move!" << endl;}
	 }
	else if(action == 3){switch_active_pokemon(0);}
	else if(action == 4){switch_active_pokemon(1);}
	else if(action == 5){switch_active_pokemon(2);}
	else{
		cout << "Invalid Input." << endl;
	}
	}

	//Purpose: Force the user to switch out their pokemon in the case that its hp is 0.
	//Preconditions: A Pokemon that has hit 0 hp, and the user will be prompted for a number
	//to change the active pokemon based on information output to screen.
	//Postconditions: The function repeats until the user enters a valid number, and the
	//desired pokemon will become the active pokemon.
	void Trainer::force_switch(){
		while(chosen_pokemon[active_pokemon].get_hp() == 0){
	cout << chosen_pokemon[active_pokemon].get_name() << " fainted. Choose a new pokemon to send out:" << endl;
	cout <<               "      3 to switch to Pokemon 1, " << chosen_pokemon[0].get_name() << endl;
	cout <<               "      4 to switch to Pokemon 2, " << chosen_pokemon[1].get_name() << endl;
	cout <<               "      5 to switch to Pokemon 3, " << chosen_pokemon[2].get_name() << endl;
	unsigned int choice;
	std::cin >> choice;
	if(choice == 3 || choice == 4 || choice == 5){
		switch_active_pokemon(choice - 3);
	} else {
	cout << "Invalid input." << endl;
			}
		}
	}

	//Purpose: Perform the Pokemon's fast attack.
	//Preconditions: A trainer with an active pokemon, and an enemy Pokemon
	//Postconditions: The fast attack of the active pokemon is used, so energy is increased,
	//enemy hp decreases, and cooldown increased.
	//OR
	//If cooldown is active, decrease cooldown.
	//
	//Then switch to the next player's turn.
	void Trainer::battle_fast_attack(Pokemon& defendingPokemon){
	chosen_pokemon[active_pokemon].use_fast_attack(defendingPokemon);
	switch_turn();
	}


	//Purpose: Perform the Pokemon's 1st charge attack.
	//Preconditions: A trainer with an active pokemon, and an enemy Pokemon
	//Postconditions: The charge attack of the active pokemon is used, so energy is decreased,
	//enemy hp decreases, and the enemy is prompted to shield.
	//If the enemy shields, the damage is negated, and the enemy loses one shield.
	//OR
	//If the active pokemon doesn't have enough energy, the turn restarts.
	//
	//Then switch to the next player's turn.
	void Trainer::battle_charge_attack1(Pokemon& defendingPokemon, Trainer& enemy){
		if(chosen_pokemon[active_pokemon].get_energy() >= chosen_pokemon[active_pokemon].get_charge_move1_energy() ){
			if(!enemy.use_shield()){
			chosen_pokemon[active_pokemon].use_charge_attack1(defendingPokemon);
			}
			else{
            chosen_pokemon[active_pokemon].add_energy(chosen_pokemon[active_pokemon].get_neg_charge_move1_energy());
			}
			switch_turn();
		} else {
		cout << "You don't have enough energy to use the move! It costs " << chosen_pokemon[active_pokemon].get_charge_move1_energy()
		<< " energy to use " << chosen_pokemon[active_pokemon].get_charge_move1_name() << ", and you only have "
		<< chosen_pokemon[active_pokemon].get_energy() << endl;
		}
	}


	//Purpose: Perform the Pokemon's 2nd charge attack.
	//Preconditions: A trainer with an active pokemon, and an enemy Pokemon
	//Postconditions: The charge attack of the active pokemon is used, so energy is decreased,
	//enemy hp decreases, and the enemy is prompted to shield.
	//If the enemy shields, the damage is negated, and the enemy loses one shield.
	//OR
	//If the active pokemon doesn't have enough energy, the turn restarts.
	//
	//Then switch to the next player's turn.
	void Trainer::battle_charge_attack2(Pokemon& defendingPokemon, Trainer& enemy){
		if(chosen_pokemon[active_pokemon].get_energy() >= chosen_pokemon[active_pokemon].get_charge_move2_energy() ){
			if(!enemy.use_shield()){
			chosen_pokemon[active_pokemon].use_charge_attack1(defendingPokemon);
			}
			else{
            chosen_pokemon[active_pokemon].add_energy(chosen_pokemon[active_pokemon].get_neg_charge_move2_energy());
			}
			switch_turn();
		} else {
		cout << "You don't have enough energy to use the move! It costs " << chosen_pokemon[active_pokemon].get_charge_move2_energy()
		<< " energy to use " << chosen_pokemon[active_pokemon].get_charge_move2_name() << ", and you only have "
		<< chosen_pokemon[active_pokemon].get_energy() << endl;
		}
	}


	//Purpose: the user switches the active pokemon.
	//Preconditions: a trainer with a chosen_pokemon vector.
	//Postconditions: the trainer's new active pokemon is set to the input desire.
	//Doesn't switch pokemon if the requested pokemon is already active,
	//or if its hp = 0.
	//Switches turn upon completion.
	void Trainer::switch_active_pokemon(unsigned char new_pokemon){
	if(chosen_pokemon[new_pokemon].get_hp() == 0){
		cout << chosen_pokemon[new_pokemon].get_name() << " is too weak to fight!" << endl;
	} else if(new_pokemon == active_pokemon){
		cout << chosen_pokemon[new_pokemon].get_name() << " is already out!" << endl;
	} else {
		cout << chosen_pokemon[active_pokemon].get_name() << " was switched out with ";
		active_pokemon = new_pokemon;
		cout << chosen_pokemon[active_pokemon].get_name() << endl;
		switch_turn();
	}
	}


	//Purpose: switches which player's turn it is.
	//Preconditions: player_1_turn, a static bool.
	//Postconditions: the active player is switched (the turn ends).
	void Trainer::switch_turn(){
	if(player_1_turn){
		player_1_turn = false;
	} else {
		player_1_turn = true;
	}
	}


	//Purpose: uses a player's shield to negate a charge move, if the player wishes to.
	//Preconditions: a trainer with variable shield_count, and the user is prompted whether or not they wish to use a shield.
	//Postconditions: if the player choses to use a shield, their hp does not go down, and their shield count goes down by 1.
	bool Trainer::use_shield(){
		if(shield_count == 0){cout << "No shields remaining." << endl; return false;}
		while(1 > 0){
	cout << "Would you like to use a shield? You have: " << get_shield_count() << " remaining. (y or n)" << endl;
	std::string answer;
	std::cin >> answer;
	if(answer == "y"){shield_count--; return true;}
	if(answer == "n"){return false;}
	cout << "Invalid input." << endl;
	}
	}

	//Return the number of shields the trainer has remaining, as an integer
	int Trainer::get_shield_count() const{
	return shield_count;
	}
}
