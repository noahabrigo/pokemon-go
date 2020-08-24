//Was not sure if I should have made this entire thing static and a member of the pokemon class or just keep it global
//I am keeping it global for right now

//This structure is useful in initializing basic pokemon info like base_atk base_def and base_sta
struct base_pokemon;

struct base_pokemon{
    std::string name;
    unsigned short int base_atk;
    unsigned short int base_def;
    unsigned short int base_sta;
    unsigned short int type[2];
    unsigned short int can_learn_f[3];
    unsigned short int can_learn_ch[5];
};

//Order of data is as follows: Name, Stats(atk,def,sta), Type, learnable Fast Moves, learnable Charge Moves.
//Within Type values 18 is a blank placeholder value in types array (replaced with pt)
//Within Fast Move Values pf is a blank placeholder value at end of f_move_list array (replaced with pf)
//Within Fast Move Values pc is a blank placeholder value at end of ch_move_list array (replaced with pc)

unsigned short int pt = 18;
unsigned short int pf = 66;
unsigned short int pc = 142;
const base_pokemon poke_db[18] = {
    //The first pokemon is for initialization in the pokemon constructor. The name is just a reference to
    //a famous glitch in one of the first games. Just for gags

    //Name            Stats          Type      Fast Moves  Charge Moves
    {"MissingNo."    ,1,1,1         ,{pt,pt}  ,{pf,pf,pf} ,{pc,pc,pc,pc,pc} },
    {"Wobbuffet"     ,60,106,382    ,{14,pt}  ,{9,11,50}  ,{77,pc,pc,pc,pc} },
    {"Cyndaquil"     ,116,93,118    ,{6,pt}   ,{15,54,pf} ,{43,125,45,pc,pc} },
    {"Charizard"     ,223,173,186   ,{6,7}    ,{19,1,pf}  ,{31,40,86,pc,pc} },
    {"Umbreon"       ,126,240,216   ,{1,pt}   ,{17,48,pf} ,{24,48,pc,pc,pc} },
    {"Totodile"      ,117,109,137   ,{17,pt}  ,{61,45,pf} ,{4,23,132,pc,pc} },
    {"Sandslash"     ,182,175,181   ,{10,pt}  ,{31,32,pf} ,{18,38,104,pc,pc} },
    {"Vulpix"        ,96,109,116    ,{6,pt}   ,{15,41,pf} ,{11,43,45,pc,pc} },
    {"Alolan Vulpix" ,96,109,116    ,{11,pt}  ,{38,65,pf} ,{10,24,65,pc,pc} },
    {"Slowpoke"      ,109,98,207    ,{14,17}  ,{10,61,pf} ,{96,98,132,pc,pc} },
    {"Snorlax"       ,190,169,330   ,{12,pt}  ,{29,65,pf} ,{38,57,63,85,114} },
    {"Marowak"       ,144,186,155   ,{10,pt}  ,{33,43,pf} ,{12,26,38,pc,pc} },
    {"Wailord"       ,175,87,347    ,{17,pt}  ,{61,65,pf} ,{10,63,124,pc,pc} },
    {"Squirtle"      ,94,121,127    ,{17,pt}  ,{4,54,pf}  ,{4,5,132,pc,pc} },
    {"Articuno"      ,192,236,207   ,{7,11}   ,{20,25,pf} ,{3,10,65,67,pc} },
    {"Vaporeon"      ,205,161,277   ,{17,pt}  ,{61,pf,pf} ,{5,61,132,pc,pc} },
    {"Pikachu"       ,112,96,111    ,{3,pt}   ,{39,41,57} ,{28,129,137,pc,pc} },
    {"Medicham"      ,121,152,155   ,{5,14}   ,{11,40,pf} ,{36,66,93,96,pc} }
};
