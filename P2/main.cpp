/*
Errors and missing features in the main.cpp

within the battle loop. when there is more than one move being used they execute at the same time.
I believe this is because the last_used and idle_frames variable is insufficient when calculating. What I think
I will do differently in the future is create an unsigned integer array of 3 idle-time objects, one for each move
so that it will have a delay for each move once each move has been used, and in the use move
calculate the idle time with the move_index. I think that would work


*/


#include <iostream>
#include <chrono>
#include <thread>


#include "trainer.h"

using namespace std::chrono;
using namespace std::this_thread;
using namespace std;

//Clock runs at about 1fps or somewhere around there
void clk(){
sleep_for(nanoseconds(10));
sleep_until(system_clock::now() + seconds(1) );
}

int main() {

    //Demonstrating some features of the pokemon class
    pokemon p1;
    p1.set_pkmn("Squirtle",11);
    p1.has_moves();
    p1.can_learn();

    pokemon p2(4,11);
    p2.has_moves();
    p2.can_learn();

    p2.swap_ch_move(0,2);
    p2.swap_f_move(1);

    /*
    Here is a sort of working example of a battle between two trainers. Not
    perfect but will hopefully improve in the next project or in my free time.
    */


    trainer t1("Noah Abrigo", {pokemon(3,10),pokemon(4,10),pokemon(5,10)});
    trainer t2("Bob Dylan", {pokemon(7,10),pokemon(9,10),pokemon(11,10)});
    t1.has_pkmn();
    t2.has_pkmn();

    cout << endl;
    t1.change_pkmn(0);
    t2.change_pkmn(0);
    cout << endl;

    cout << endl;
    cout << "Get Ready Trainers" << endl;
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1) );
    cout << "3" << endl;
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1) );
    cout << "2" << endl;
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1) );
    cout << "1" << endl;
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1) );
    cout << "GO!" << endl;

    while(true){
            clk();


            if(t1.lose() || t2.lose()){
                return false;
            }
            else{
                //For right now we are just going to spam the use_move function
                //Some of the features in the use_move functions need to be put into their own
                //functions and be more accessible in the main
                //I was going for simplistic code, but it makes more of a mess on the
                //inside
                //Testing out fast moves
                t1.use_move(t2,0);
                t2.use_move(t1,0);
            }

            if(t1.lose() || t2.lose()){
                return false;
            }
            else{

                //Testing out charge moves
                t1.use_move(t2,1);
                t2.use_move(t1,1);
            }

    }

    return 0;
}
