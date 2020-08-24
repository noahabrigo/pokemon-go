//All of the available combinations of attack multipliers and defense multipliers

//Multiplier Value Array
//           0    1     2      3     4
float mv[5] {1, 0.39, 0.391, 0.625, 1.6};

//Attack Multiplier
const float pokemon::am[19][19]
{
    //Bug Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[4], mv[0], mv[0], mv[3], mv[3], mv[3], mv[3], mv[3], mv[4], mv[0], mv[0], mv[0], mv[3], mv[4], mv[0], mv[3], mv[0], mv[0]},

    //Dark Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[3], mv[0], mv[0], mv[3], mv[3], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0]},

    //Dragon Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[4], mv[0], mv[2], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0]},

    //Electric Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[3], mv[3], mv[0], mv[0], mv[0], mv[4], mv[0], mv[3], mv[2], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0]},

    //Fairy Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[4], mv[4], mv[0], mv[0], mv[4], mv[3], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[3], mv[0],mv[0]},

    //Fighting Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[4], mv[0], mv[0], mv[3], mv[0], mv[0], mv[3], mv[2], mv[0], mv[0], mv[4], mv[4], mv[3], mv[3], mv[4], mv[4], mv[0], mv[0]},

    //Fire Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[0], mv[3], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[4], mv[0], mv[4], mv[0], mv[0], mv[0], mv[3], mv[4], mv[3], mv[0]},

    //Flying Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[0], mv[0], mv[3], mv[0], mv[4], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0], mv[0]},

    //Ghost Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[3], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[2], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0]},

    //Grass Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[3], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0], mv[3], mv[4], mv[0], mv[0], mv[3], mv[0], mv[4], mv[3], mv[4], mv[0]},

    //Ground Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[0], mv[4], mv[0], mv[0], mv[4], mv[2], mv[0], mv[3], mv[0], mv[0], mv[0], mv[4], mv[0], mv[4], mv[4], mv[0], mv[0]},

    //Ice Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[3], mv[4], mv[0], mv[4], mv[4], mv[3], mv[0], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0]},

    //Normal Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[2], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0], mv[0]},

    //Poison Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[3], mv[4], mv[3], mv[0], mv[0], mv[3], mv[0], mv[3], mv[2], mv[0], mv[0]},

    //Psychic Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[2], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[3], mv[0], mv[3], mv[0], mv[0]},

    //Rock Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[0], mv[0], mv[0], mv[0], mv[3], mv[4], mv[4], mv[0], mv[0], mv[3], mv[4], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0]},

    //Steel Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[3], mv[4], mv[0], mv[3], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[4], mv[3], mv[3], mv[0]},

    //Water Type Attack Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[3], mv[4], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[3], mv[0]},

    //Extra multiplier for blank type. should just be a 1x multiplier. No effect.
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0]}

};



//Defense Multiplier
const float pokemon::dm[19][19]
{
    //Bug Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[4], mv[4], mv[0], mv[3], mv[3], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0]},

    //Dark Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[3], mv[0], mv[0], mv[4], mv[4], mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[0], mv[0], mv[1], mv[0], mv[0], mv[0], mv[0]},

    //Dragon Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[4], mv[3], mv[4], mv[0], mv[3], mv[0], mv[0], mv[3], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0]},

    //Electric Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0]},

    //Fairy Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[3], mv[1], mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[4], mv[0], mv[0]},

    //Fighting Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[3], mv[0], mv[0], mv[4], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[3], mv[0], mv[0], mv[0]},

    //Fire Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[0], mv[0], mv[3], mv[0], mv[3], mv[0], mv[0], mv[3], mv[4], mv[3], mv[0], mv[0], mv[0], mv[4], mv[3], mv[4], mv[0]},

    //Flying Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[0], mv[4], mv[0], mv[3], mv[0], mv[0], mv[0], mv[3], mv[1], mv[4], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0]},

    //Ghost Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[4], mv[0], mv[0], mv[0], mv[1], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[1], mv[3], mv[0], mv[0], mv[0], mv[0], mv[0]},

    //Grass Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[0], mv[0], mv[3], mv[0], mv[0], mv[4], mv[4], mv[0], mv[3], mv[3], mv[4], mv[0], mv[4], mv[0], mv[0], mv[0], mv[3], mv[0]},

    //Ground Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[1], mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[4], mv[0], mv[3], mv[0], mv[3], mv[0], mv[4], mv[0]},

    //Ice Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[4], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[4], mv[4], mv[0], mv[0]},

    //Normal Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[1], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0]},

    //Poison Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0], mv[0], mv[0], mv[3], mv[4], mv[0], mv[0], mv[3], mv[4], mv[0], mv[0], mv[0], mv[0]},

    //Psychic Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[4], mv[4], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[4], mv[0], mv[0], mv[0], mv[0], mv[0], mv[3], mv[0], mv[0], mv[0], mv[0]},

    //Rock Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[4], mv[3], mv[3], mv[0], mv[4], mv[4], mv[0], mv[3], mv[3], mv[0], mv[0], mv[4], mv[0], mv[0]},

    //Steel Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[3], mv[0], mv[3], mv[0], mv[3], mv[4], mv[4], mv[3], mv[0], mv[3], mv[4], mv[3], mv[3], mv[1], mv[3], mv[3], mv[3], mv[0], mv[0]},

    //Water Type Defense Multiplier
    //Bug   Dark   Drag   Elec   Fair   Figh   Fire   Fly    Ghos   Gras   Grou   Ice    Norm   Pois   Psyc   Rock   Stee   Watr
    {mv[0], mv[0], mv[0], mv[4], mv[0], mv[0], mv[3], mv[0], mv[0], mv[4], mv[0], mv[3], mv[0], mv[0], mv[0], mv[0], mv[3], mv[3], mv[0]},

    //Extra multiplier for blank type. should just be a 1x multiplier. No effect.
    {mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0], mv[0]}

};
