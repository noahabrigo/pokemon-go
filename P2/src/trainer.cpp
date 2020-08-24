//Did not do any negative integer error checking

//Missing shield move feature

#include "trainer.h"

trainer::trainer(){
    name = "";

    c_pkmn = 0;
}

trainer::trainer(std::string nm, std::vector<pokemon> poke_init){
    name = nm;
    pkmn = poke_init;
    c_pkmn = 0;

}

void trainer::set_name(std::string nm){
    name = nm;
}
void trainer::init_pkmn(std::vector<pokemon> poke_init){
    pkmn = poke_init;
}

std::string trainer::get_name(){
    return name;
}

void trainer::has_pkmn(){
    std::cout << "Trainer " << name << " has ";
    for(unsigned short int i = 0; i < pkmn.size(); i++){
        std::cout << pkmn[i].get_name() << " ";
    }
    std::cout << std::endl;
}

pokemon &trainer::get_pkmn(unsigned short int pkmn_index){
    if(pkmn_index < 3){
        return pkmn[pkmn_index];
    }
    else{
        std::cout << "Err: may only retrieve pkmn from index 0 - 2" << std::endl;
        pokemon err(0,0);
        return err;
    }
}

void trainer::change_pkmn(unsigned short int pkmn_index){
    if(pkmn_index < 3){
    c_pkmn = pkmn_index;
    std::cout << name << " sent out " << pkmn[c_pkmn].get_name() << std::endl;
    }
}

unsigned short int trainer::in_btl(){
    return c_pkmn;
}

void trainer::use_move(trainer & opponent, unsigned short int mv_index){
    //This part of the code checks to see if the pokemon has fainted or not
    if(opponent.get_pkmn(opponent.c_pkmn).faint() == true){
        unsigned short int count = 0;
        while(opponent.get_pkmn(opponent.c_pkmn).faint() == true && opponent.loss == false){
            if(count <= 2){
                if(opponent.get_pkmn(count).faint() != true){
                opponent.change_pkmn(count);
                }else{
                count++;
                }
            }
            else{
                opponent.loss = true;
                std::cout << opponent.name << " is out of usable pokemon" << std::endl;
                std::cout << name << " is the winner" << std::endl;
            }
        }
    //If the pokemon hasn't fainted, use the move
    }else{
        get_pkmn(c_pkmn).use_move(mv_index, opponent.get_pkmn(opponent.c_pkmn));
    }
}

void trainer::bstat(){
    std::cout << std::endl;
    std::cout << get_pkmn(c_pkmn).get_name() << std::endl;
    std::cout << "LVL: " << get_pkmn(c_pkmn).get_level() << std::endl;
    std::cout << "HP: " << get_pkmn(c_pkmn).get_hp() << "/" << get_pkmn(c_pkmn).get_max_hp() << std::endl;
    std::cout << "EN: " << get_pkmn(c_pkmn).get_energy() << std::endl;
    std::cout << std::endl;
}

bool trainer::lose(){
    return loss;
}
