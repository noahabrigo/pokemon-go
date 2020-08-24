//Changed Charge_Move constructor to all positive integer values

//Standard library includes
#include <iostream>
#include <vector>

//Local Includes
#include "Charge_Move.h"
#include "Fast_Move.h"
#include "Trainer.h"

using namespace std; using namespace PokemonGo;

int main()
{
//Initialize the pool of all fast moves

    Fast_Move mud_slap("Mud Slap", 10, 15, 2, 8, 1.5);
    Fast_Move rock_smash("Rock Smash", 5, 9, 2, 6, 1.5);
    Fast_Move tackle("Tackle", 12, 3, 0, 2, 0.5);
    Fast_Move bubble("Bubble", 17, 8, 2, 11, 1.5);
    Fast_Move fire_spin("Fire Spin", 6, 9, 2, 10, 1.5);
    Fast_Move air_slash("Air Slash", 7, 9, 2, 9, 1.5);
    Fast_Move ember("Ember", 6, 6, 1, 6, 1);
    Fast_Move counter("Counter", 5, 8, 1, 7, 1);
    Fast_Move splash("Splash", 17, 0, 3, 12, 2);
    Fast_Move charm("Charm", 4, 16, 2, 6, 1.5);
    Fast_Move feint_attack("Feint Attack", 1, 6, 1, 6, 1);
    Fast_Move snarl("Snarl", 1, 5, 2, 13, 1.5);

    //Initialize the pool of all charge moves

    Charge_Move bone_club("Bone Club", 10, 40, 35);
    Charge_Move dig("Dig", 10, 100, 80);
    Charge_Move earthquake("Earthquake", 10, 120, 65);
    Charge_Move aqua_jet("Aqua Jet", 17, 45, 45);
    Charge_Move aqua_tail("Aqua Tail", 17, 50, 35);
    Charge_Move water_pulse("Water Pulse", 17, 70, 60);
    Charge_Move dragon_claw("Dragon Claw", 2, 50, 35);
    Charge_Move fire_blast("Fire Blast", 6, 140, 80);
    Charge_Move overheat("Overheat", 6, 150, 80);
    Charge_Move flame_charge("Flame Charge", 6, 70, 50);
    Charge_Move swift("Swift", 12, 60, 55);
    Charge_Move flamethrower("Flamethrower", 6, 90, 55);
    Charge_Move mirror_coat("Mirror Coat", 14, 60, 55);
    Charge_Move dark_pulse("Dark Pulse", 1, 80, 50);
    Charge_Move foul_play("Foul Play", 1, 70, 45);

    //Initialize pool of Pokemon

    Pokemon marowak("Marowak", 10, 144, 186, 155, mud_slap, bone_club,
                    {mud_slap, rock_smash}, {bone_club, dig, earthquake}, 20, 4, 4, 4 );
    Pokemon squirtle("Squirtle", 17, 94, 121, 127, tackle, aqua_jet,
                     {tackle, bubble}, {aqua_jet, aqua_tail, water_pulse}, 20, 4, 4, 4 );
    Pokemon charizard("Charizard",6, 9, 223, 173, 186, fire_spin, dragon_claw, fire_blast,
                      {fire_spin, air_slash}, {dragon_claw, fire_blast, overheat}, 20, 4, 4, 4 );
    Pokemon cyndaquil("Cyndaquil", 6, 116, 93, 118, ember, swift,
                      {ember, tackle}, {flame_charge, swift, flamethrower}, 20, 4, 4, 4 );
    Pokemon wobbuffet("Wobbuffet",14, 60, 106, 382, counter, mirror_coat,
                      {counter, splash, charm}, {mirror_coat}, 20, 4, 4, 4 );
    Pokemon umbreon("Umbreon", 1, 1, 1, 1, feint_attack, dark_pulse, foul_play,
                    {feint_attack, snarl}, {dark_pulse, foul_play}, 20, 4, 4, 4 ); //set base stats correctly in a later test case

//Test for fast attacks
    //Error case 1 tests fast attacks to make sure they do the amount of damage expected.
    //      The four values are the same in between attacks to show that the attacks don't do damage while cooldown goes down.
    //Error case 2 tests that energy goes up as expected using fast attacks.
    //      The four values are the same in between attacks to show that the attacks don't add energy while cooldown goes down.
    //Error case 3 tests that cooldown goes down as expected using fast attacks.
if(squirtle.get_hp() != 79){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 0){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 0){cout << "ERROR Case 3" << endl;}

    marowak.use_fast_attack(squirtle);
if(squirtle.get_hp() != 68){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 8){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 1.5){cout << "ERROR Case 3" << endl;}

    marowak.use_fast_attack(squirtle);
if(squirtle.get_hp() != 68){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 8){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 1){cout << "ERROR Case 3" << endl;}

    marowak.use_fast_attack(squirtle);
if(squirtle.get_hp() != 68){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 8){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 0.5){cout << "ERROR Case 3" << endl;}

    marowak.use_fast_attack(squirtle);
if(squirtle.get_hp() != 68){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 8){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 0){cout << "ERROR Case 3" << endl;}

    marowak.use_fast_attack(squirtle); //cooldown done, this one actually hits
if(squirtle.get_hp() != 57){cout << "ERROR Case 1" << endl;}
if(marowak.get_energy() != 16){cout << "ERROR Case 2" << endl;}
if(marowak.get_cooldown() != 1.5){cout << "ERROR Case 3" << endl;}

//Test that editor functions work
    //Make sure setting base functions works.
    //Output an error if they are not set as expected.
    umbreon.set_base(126, 240, 216);
    if(umbreon.get_base_atk() != 126 || umbreon.get_base_def() != 240 || umbreon.get_base_sta() != 216){
        cout << "ERROR case 4";
    }

    //Make sure Umbreon can't learn a move that isn't on its learnable move list.
    //Output an error if the move is successfully taught without being on learnable move list.
    umbreon.replace_fast_move(ember);
if(umbreon.get_fast_move_name() == "ember"){
    cout << "ERROR Case 5" << endl;
}

    //Make sure Umbreon can learn a move that is on its learnable move list.
    //Output an error if the move isn't successfully changed.
    umbreon.replace_fast_move(feint_attack);
if(umbreon.get_fast_move_name() != "Feint Attack"){
    cout << "ERROR Case 6" << endl;
}

    //Make sure Umbreon can use its newly learned move.
    //Output an error message if the move doesn't work as expected.
    umbreon.use_fast_attack(wobbuffet); //Expected output: "It's super effective!"
if(wobbuffet.get_hp() != 226){cout << "ERROR Case 7" << endl;}
if(umbreon.get_energy() != 6){cout << "ERROR Case 8" << endl;}
if(umbreon.get_cooldown() != 1){cout << "ERROR Case 9" << endl;}

//Test for charge attacks
    //These tests will not involve shields, because there are no trainers involved here.
    //To test shields, please use the battle simulator.
//Charizard is given enough energy to perform two charge attacks, one 1 and one 2, on wobbuffet.
//Output an error message if these don't do the expected amount of damage.
charizard.add_energy(115);
charizard.use_charge_attack1(wobbuffet);
if(wobbuffet.get_hp() != 174){cout << "ERROR Case 10" << endl;}
charizard.use_charge_attack2(wobbuffet);
if(wobbuffet.get_hp() != 0){cout << "ERROR Case 11" << endl;}

//Now, charizard will attempt to use a charge attack on squirtle without enough energy to do so.
//output an error if squirtle's health changes.
charizard.use_charge_attack1(squirtle);
if(squirtle.get_hp() != 57){cout << "ERROR Case 12" << endl;}

//Level up squirtle.
//If squirtle's level isnt increased to the expected level, output an error message.
squirtle.level_up();
if(squirtle.get_levelx2() != 41){cout << "ERROR Case 13" << endl;}

//Use the battle simulator to test battle mechanics, such as shields and switching pokemon.

Trainer ash({marowak, squirtle, charizard}, {marowak, squirtle, charizard});
Trainer oak({cyndaquil, wobbuffet, umbreon}, {cyndaquil, wobbuffet, umbreon});


cout << "Test for errors: complete! Starting battle simulator..." << endl;


ash.battle(oak);
//Note: If a Pokemon is swapped while it has a cooldown, it will retain that cooldown when it comes back out.
//      This is done by design to avoid cheezing cooldowns by simply swapping Pokemon.

cout << "Battle complete!" << endl;
return 0;
}
