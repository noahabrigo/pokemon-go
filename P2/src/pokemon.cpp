/*
Errors and missing features/semantic problems

use_move() function is bloated and needs to be divided into separate functions. I was on a time crunch so was unable to split it up.
Since use_move is the only battle function all of the battle checking is done through it which is not good.
This means that when a pokemon faints it is beating up a poor defenseless pokemon :(


Did not do any negative integer error checking



*/

#include "pokemon.h"

#include "cp.cpp"
#include "types.cpp"
#include "move_list.cpp"
#include "battle_multipliers.cpp"
#include "poke_db.cpp"

pokemon::pokemon(){
    //Takes info from poke_db based on index number
    name  = poke_db[0].name;

    //Takes info from poke_db based on index number
    base_atk = poke_db[0].base_atk;
    base_def = poke_db[0].base_def;
    base_sta = poke_db[0].base_sta;

    //Sets iv values randomly from 0 - 15
    iv_atk = rand() % 15;
    iv_def = rand() % 15;
    iv_sta = rand() % 15;

    //Takes pokemon types 1 and 2 from the poke_db
    type[0] = poke_db[0].type[0];
    type[1] = poke_db[0].type[1];
}

pokemon::pokemon(unsigned short int poke_num, unsigned short int lvl){
    //Takes info from poke_db based on index number
    name  = poke_db[poke_num].name;
    level = lvl;

    //Takes info from poke_db based on index number
    base_atk = poke_db[poke_num].base_atk;
    base_def = poke_db[poke_num].base_def;
    base_sta = poke_db[poke_num].base_sta;

    iv_atk = rand() % 15;
    iv_def = rand() % 15;
    iv_sta = rand() % 15;

    update_stats();

    hp = max_hp;

    //Takes info from poke_db based on index number
    type[0] = poke_db[poke_num].type[0];
    type[1] = poke_db[poke_num].type[1];

    //Checks if the index number is anything but the blank pokemon index
    if(poke_num != 0){
    //Temporary move struct to help with initializing move vector
    move temp_move;
    for (int j = 0; j < 3; j++) {
        //Finds fast moves that the pokemon can learn poke_db and pushes them into the learnable moves vector
        if (poke_db[poke_num].can_learn_f[j] != pf) {
        temp_move.name = f_move_list[poke_db[poke_num].can_learn_f[j]].get_name();
        temp_move.id = poke_db[poke_num].can_learn_f[j];
        temp_move.type = 0;
        moves.push_back(temp_move);
        }
    }
    for (int j = 0; j < 5; j++) {
        //Finds charge moves that the pokemon can learn from poke_db and pushes them into the learnable moves vector
        if (poke_db[poke_num].can_learn_ch[j] != pc) {
        temp_move.name = ch_move_list[poke_db[poke_num].can_learn_ch[j]].get_name();
        temp_move.id = poke_db[poke_num].can_learn_ch[j];
        temp_move.type = 1;
        moves.push_back(temp_move);
        }
    }

    //Auto initializes default move set with one fast move and two charge moves
    moveset.push_back(moves[0]);
    unsigned short int counter = 0;
    for(unsigned short int i = 0; i < moves.size(); i++){
        if(moves[i].type == 1 && counter < 2){
            counter++;
            moveset.push_back(moves[i]);
        }
    }
    }
}

pokemon::pokemon(std::string nm, unsigned short int lvl){
    //Searches through the entire poke_db
    for(unsigned short int i = 0; i < sizeof(poke_db)/sizeof(poke_db[0]); i++){
        //If the name in poke_db is equal to the name declared
        if (poke_db[i].name == nm) {

            //Initialize pkmn just like before
            name = nm;
            level = lvl;
            base_atk = poke_db[i].base_atk;
            base_def = poke_db[i].base_def;
            base_sta = poke_db[i].base_sta;

            iv_atk = rand() % 15;
            iv_def = rand() % 15;
            iv_sta = rand() % 15;

            type[0] = poke_db[i].type[0];
            type[1] = poke_db[i].type[1];

            update_stats();
            hp = max_hp;

            //Basically checks to see if the name doesn't equal MissingNo.
            //Does not push_back any moves from this placeholder pokemon
            if(name != poke_db[0].name){
            move temp_move;
            for (int j = 0; j < 3; j++) {
                if (poke_db[i].can_learn_f[j] != pf) {
                temp_move.name = f_move_list[poke_db[i].can_learn_f[j]].get_name();
                temp_move.id = poke_db[i].can_learn_f[j];
                temp_move.type = 0;
                moves.push_back(temp_move);
                }
            }
            for (int j = 0; j < 5; j++) {
                if (poke_db[i].can_learn_ch[j] != pc) {
                temp_move.name = ch_move_list[poke_db[i].can_learn_ch[j]].get_name();
                temp_move.id = poke_db[i].can_learn_ch[j];
                temp_move.type = 1;
                moves.push_back(temp_move);
                }
            }

            //Auto initializes default move set with one fast move and two charge moves
            moveset.push_back(moves[0]);
            unsigned short int counter = 0;
            for(unsigned short int i = 0; i < moves.size(); i++){
                if(moves[i].type == 1 && counter < 2){
                    counter++;
                    moveset.push_back(moves[i]);
                }
            }
            }

        }
    }
}

pokemon::~pokemon(){
}

void pokemon::set_pkmn(unsigned short int poke_num, unsigned short int lvl){
    name  = poke_db[poke_num].name;
    level = lvl;

    base_atk = poke_db[poke_num].base_atk;
    base_def = poke_db[poke_num].base_def;
    base_sta = poke_db[poke_num].base_sta;

    iv_atk = rand() % 15;
    iv_def = rand() % 15;
    iv_sta = rand() % 15;

    update_stats();

    hp = max_hp;

    energy = 0;

    type[0] = poke_db[poke_num].type[0];
    type[1] = poke_db[poke_num].type[1];

    if(poke_num != 0){

    moves.clear();
    moveset.clear();
    move temp_move;

    for (int j = 0; j < 3; j++) {
        if (poke_db[poke_num].can_learn_f[j] != pf) {
        temp_move.name = f_move_list[poke_db[poke_num].can_learn_f[j]].get_name();
        temp_move.id = poke_db[poke_num].can_learn_f[j];
        temp_move.type = 0;
        moves.push_back(temp_move);
        }
    }
    for (int j = 0; j < 5; j++) {
        if (poke_db[poke_num].can_learn_ch[j] != pc) {
        temp_move.name = ch_move_list[poke_db[poke_num].can_learn_ch[j]].get_name();
        temp_move.id = poke_db[poke_num].can_learn_ch[j];
        temp_move.type = 1;
        moves.push_back(temp_move);
        }
    }

    //Auto initializes default move set with one fast move and two charge moves
    moveset.push_back(moves[0]);
    unsigned short int counter = 0;
    for(unsigned short int i = 0; i < moves.size(); i++){
        if(moves[i].type == 1 && counter < 2){
            counter++;
            moveset.push_back(moves[i]);
        }
    }
    }
}

void pokemon::set_pkmn(std::string nm, unsigned short int lvl){
    for(unsigned short int i = 0; i < sizeof(poke_db)/sizeof(poke_db[0]); i++){
        if (poke_db[i].name == nm) {
            name = nm;
            level = lvl;
            base_atk = poke_db[i].base_atk;
            base_def = poke_db[i].base_def;
            base_sta = poke_db[i].base_sta;

            iv_atk = rand() % 15;
            iv_def = rand() % 15;
            iv_sta = rand() % 15;

            type[0] = poke_db[i].type[0];
            type[1] = poke_db[i].type[1];

            update_stats();
            hp = max_hp;

            if(name != poke_db[0].name){

            moves.clear();
            moveset.clear();
            move temp_move;

            for (int j = 0; j < 3; j++) {
                if (poke_db[i].can_learn_f[j] != pf) {
                temp_move.name = f_move_list[poke_db[i].can_learn_f[j]].get_name();
                temp_move.id = poke_db[i].can_learn_f[j];
                temp_move.type = 0;
                moves.push_back(temp_move);
                }
            }
            for (int j = 0; j < 5; j++) {
                if (poke_db[i].can_learn_ch[j] != pc) {
                temp_move.name = ch_move_list[poke_db[i].can_learn_ch[j]].get_name();
                temp_move.id = poke_db[i].can_learn_ch[j];
                temp_move.type = 1;
                moves.push_back(temp_move);
                }
            }

            //Auto initializes default move set with one fast move and two charge moves
            moveset.push_back(moves[0]);
            unsigned short int counter = 0;
            for(unsigned short int i = 0; i < moves.size(); i++){
                if(moves[i].type == 1 && counter < 2){
                    counter++;
                    moveset.push_back(moves[i]);
                }
            }
            }

        }
    }
}

void pokemon::update_stats(){
    //Calculation for c_atk and c_def
    c_atk = (base_atk + iv_atk)*cp[level-1];
    c_def = (base_def + iv_def)*cp[level-1];

    //If user attempts to set level higher than 40
    //Ignore them and set it to 40
    //Also set up calculation for max_hp for each level
    if (level <= 40) {
        max_hp = floor((base_sta + iv_sta)*cp[level-1]);
    }
    else{
        level = 40;
        max_hp = floor((base_sta + iv_sta)*cp[39]);
    }
}

const void pokemon::can_learn(){
    std::string text = "";
    //Iterates through the learnable moves vector
    for (unsigned short int i = 0; i < moves.size(); i++) {
        if (moves[i].type == 0) {
            text += moves[i].name;
            //The (f) next to the move indicates that it is a fast move
            text += "(f) ";
        }
        else{
            text += moves[i].name;
            //the (ch) next to the move indicates that it is a charge move
            text += "(ch) ";
        }
    }

    std::cout << name << " can learn: " << text << std::endl;
    std::cout<< std::endl;
    std::cout << "f: fast move, ch: charge move" << std::endl;
    std::cout<< std::endl;
}

const void pokemon::has_moves(){
    std::string text = "";
    //Iterates through the moveset vector
    for (unsigned short int i = 0; i < moveset.size(); i++) {
        //type is fast move or 0
        if (moveset[i].type == 0) {
            text += moveset[i].name;
            text += "(f) ";
        }
        //type is charge move or 1
        else{
            text += moveset[i].name;
            text += "(ch) ";
        }
    }

    std::cout << name << " has moves: " << text << std::endl;
    std::cout<< std::endl;
    std::cout << "f: fast move, ch: charge move" << std::endl;
    std::cout<< std::endl;
}

void pokemon::set_level(unsigned short int lvl){
    level = lvl;
    //After level change stats like c_atk and c_def needs to be updated
    update_stats();
}

void pokemon::use_move(unsigned short int move_index, pokemon &opponent){
    if(idle_frames > 0 && move_index == last_used){
        wait();
        //std::cout << idle_frames << std::endl;
    }
    else{
    unsigned short int power;
    unsigned short int damage;
    //Same type bonus multiplier
    float stb = 1;
    //The attack multipliers which increase points taken off of hp
    float am1 = am[type[0]][opponent.type[0]];
    float am2 = am[type[1]][opponent.type[1]];
    //The defense multipliers which dampens the attack multipliers
    float dm1 = dm[opponent.type[0]][type[0]];
    float dm2 = dm[opponent.type[1]][type[1]];

    last_used = move_index;

    //Checks if the pokemon is able to battle or not
    if(fnt == false){
    //If the move type is fast move
    if(moveset[move_index].type == 0){
        first_time = false;
        //Gets base power
        power = f_move_list[moveset[move_index].id].get_base_power();

        //Adds energy to pkmn from move
        //Makes sure that energy does not go over 500
        if(energy < 500){
            energy += f_move_list[moveset[move_index].id].get_energy_delta();
        }else if(energy >= 500){
            energy = 500;
        }else{
            energy = 500;
        }

        //Figures out duration of attack and cooldown
        idle_frames += f_move_list[moveset[move_index].id].get_duration();
        idle_frames += f_move_list[moveset[move_index].id].get_cooldown();

        //Checks for same type bonus
        if(f_move_list[moveset[move_index].id].get_type() == type[0] || f_move_list[moveset[move_index].id].get_type() == type[1]){
            stb = 1.2;
        }

        //Damage equation
        damage = floor(0.5*power*(c_atk/opponent.c_def) * ((am1 * am2) * (dm1 * dm2)) * stb) + 1;

        //Checks to see if opponent damage taken is more than available hp.
        if(opponent.hp < damage){
            opponent.fnt = true;
            opponent.hp = 0;
            std::cout << name << "(HP: " << hp << " EN: " << energy << ")" << " used " << moveset[move_index].name << " on " << opponent.name << std::endl;
            std::cout << opponent.name << " has fainted" << std::endl;
            std::cout << std::endl;
        }else{
            opponent.hp -= damage;
            std::cout << name << "(HP: " << hp << " EN: " << energy << ")" << " used " << moveset[move_index].name << " on " << opponent.name << std::endl;
            std::cout << std::endl;
        }

    }

    //If the move type is a charge move
    else{
        //Gets base power
        power = ch_move_list[moveset[move_index].id].get_base_power();

        if(energy >= -ch_move_list[moveset[move_index].id].get_ch_energy()){

            energy += ch_move_list[moveset[move_index].id].get_ch_energy();

            //Checks for same type bonus
            if(ch_move_list[moveset[move_index].id].get_type() == type[0] || ch_move_list[moveset[move_index].id].get_type() == type[1]){
                stb = 1.2;
            }

            //Just delaying the time on charge moves so it is not instant
            idle_frames += 5;

            //Damage equation
            damage = floor(0.5*power*(c_atk/opponent.c_def) * ((am1 * am2) * (dm1 * dm2)) * stb) + 1;

            //Checks to see if opponent damage taken is more than available hp.
            if(opponent.hp < damage){
                opponent.fnt = true;
                opponent.hp = 0;
                std::cout << name << "(HP: " << hp << " EN: " << energy << ")" << " used " << moveset[move_index].name << " on " << opponent.name << std::endl;
                std::cout << opponent.name << " has fainted" << std::endl;
                std::cout << std::endl;
            }else{
                opponent.hp -= damage;
                std::cout << name << "(HP: " << hp << " EN: " << energy << ")" << " used " << moveset[move_index].name << " on " << opponent.name << std::endl;
                std::cout << std::endl;
            }

        }
        else{
            std::cout << ch_move_list[moveset[move_index].id].get_name() << " requires "  << -ch_move_list[moveset[move_index].id].get_ch_energy() << " energy from " << name << std::endl;
        }

    }


    }
    else{
        std::cout << name << " is unable to battle" << std::endl;
    }
    }
}

void pokemon::swap_f_move(unsigned short int move){
    //Checks if move type is a fast move
    if(moves[move].type == 0){
        std::cout << "Swapped " << name << "'s " << moves[0].name << " with " << moves[move].name << std::endl;
        //At the first index, will always be fast move, so we can always set it to a new fast move
        moveset[0] = moves[move];
        has_moves();
    }
    else{
        std::cout << "You tried to swap " << name <<"'s fast move with a charge move" << std::endl;
    }
}

void pokemon::swap_ch_move(unsigned short int slot, unsigned short int move){
    //Checks what slot to put the move in and sees if the user entered a big slot
    if(slot < 2 && slot >= 0){
    //Checks if move type if charge move
    if(moves[move].type == 1){
        std::cout << "Swapped " << name << "'s " << moves[slot].name << " with " << moves[move].name << std::endl;
        moveset[slot] = moves[move];
        has_moves();
    }
    else{
        std::cout << "You tried to swap " << name <<"'s charge move with a fast move" << std::endl;
        can_learn();
    }
    }
    else{
        std::cout << "The slot number for charge moves must be 0 or 1 when swapping moves error at pokemon " << name << std::endl;
    }
}



//The get functions are all pretty straight forward
//They return private member variables
std::string pokemon::get_name(){
    return name;
}
unsigned short int pokemon::get_base_atk(){
    return base_atk;
}
unsigned short int pokemon::get_base_def(){
    return base_def;
}
unsigned short int pokemon::get_base_sta(){
    return base_sta;
}
unsigned short int pokemon::get_iv_atk(){
    return iv_atk;
}
unsigned short int pokemon::get_iv_def(){
    return iv_def;
}
unsigned short int pokemon::get_iv_sta(){
    return iv_sta;
}
unsigned short int pokemon::get_level(){
    return level;
}
unsigned short int pokemon::get_max_hp(){
    return max_hp;
}
unsigned short int pokemon::get_hp(){
    return hp;
}
unsigned short int pokemon::get_type_1(){
    return type[0];
}
unsigned short int pokemon::get_type_2(){
    return type[1];
}
unsigned short int pokemon::get_energy(){
    return energy;
}

bool pokemon::faint(){
    return fnt;
}
void pokemon::wait(){
    idle_frames--;
}




