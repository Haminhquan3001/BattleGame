/* ----------------------12/3/2020-----------

The program is a game where we have 4 different types of creatures
humans, cyberdemons, balrogs, elves. These 4 types of creatures were
inherited from the Creature and Demon classes.
Each type of creature have different characteristic of damage,
and we calculate the damage to see who is the winner.

*/


#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

 //Base class
class Creature
{
private:

    string Species;
    int strength; 
    // How much damage we can inflict
    int hitpoints; 
    // How much damage we can sustain    
    virtual string getSpecies() const;
    // Returns type of species, for Creature class

public:
    // Initialize to human, 10 strength, 10 hit points
    Creature();
  
    // Initialize creature to new type, strength, hit points
    Creature(string newSpceices,int newStrength, int newHit);
    
    // add appropriate accessor and mutator functions
    // for type, strength, and hit points
    void setStrength(int newStrength);
    int getStrength() const;
    void setHitpoints(int hp);
    int getHitpoints() const ;
    void setSpecies(string n);
    
   
    virtual int getDamage() const;
   
};

void Creature::setStrength(int s) {
    strength = s;
}
int Creature::getStrength() const  {
    return strength;
}

void Creature::setHitpoints(int hp) {
    hitpoints = hp;
}
int Creature::getHitpoints() const  {
    return hitpoints;
}

void Creature::setSpecies(string n) {
    Species = n;
}
string Creature::getSpecies() const {
    return Species;
}

// Returns amount of damage this creature
// inflicts in one round of combat

int Creature::getDamage() const
{
    int damage;
    damage = (rand() % strength) + 1;
    return damage;
}

//Constructors
Creature::Creature():Species("Human"),strength (10), hitpoints(10){}
Creature::Creature(string newSpeices, int newStrength, int newHit):
  Species (newSpeices), strength(newStrength), hitpoints(newHit){}

//Demon is a child class and inherit the base class Creature
class Demon : public Creature {
public:
    Demon() : Creature() {
        setSpecies("Demon");
    }
    Demon(string name,int str, int hp) :Creature("Demon",str, hp) {}
    /*
    Demon getDamage() can inflict damage of 50 with a 5% chance
    It returns the damage
    */
   int getDamage() const override {
       int damage = (rand()% Creature::getStrength())+1;
       if ((rand() % 100) < 5)
       {
          damage = damage + 50;
           cout << "Demonic attack inflicts 50 "
               << " additional damage points!" << endl;
       }
       return damage;
    }

};

//Elf is a child class and inherit the base class Creature
class Elf : public Creature {
private:
   const string ESpecies = "Elf"; 
public: 
    Elf() :Creature() {}
    Elf(int str, int hp) : Creature("Elf", str, hp) {}


    /*
    getSpeices() is a virtual function, when it is called, 
    The override function will
    be called instead of the base class' function
    It returns a string which indicate the name of the speices.
    */
    string getSpecies() const override {
        return ESpecies;
    }

    /*
    Elves getDamage() inflict 
    double magical damage with a 10% chance
    It returns the damage. 
    
    */
    int getDamage() const override  {
        int damage= (rand() % Creature::getStrength()) + 1;
        cout << getSpecies() << " attack for " << 
            damage << " points!" << endl;
            if ((rand() % 10) == 0)
            {
                cout << "Magical attack inflicts " << damage <<
                    " additional damage points!" << endl;
                damage = damage * 2;
            }
        return damage;
    
    }    
};

//Human is a child class and inherit the base class Creature
class Human : public Creature {
private: 
    const string Species = "Human";
public: 
    Human() :Creature() {}
    Human(int str, int hp) :Creature("Human", str,hp) {}

   /*
   getSpeices() is a virtual function, when it is called,
   The override function will
   be called instead of the base class' function
   It returns a string which indicate the name of the speices.
   */
    string getSpecies() const override {
        return Species;
    }

    /*
    Human getDamage() inflict the damage
    depend on their strength
    It returns the damage
    */
    int getDamage() const override {
        int damage = (rand() % Creature::getStrength()) + 1;
        cout << getSpecies() << " attack for "
            << damage << " points!" << endl;
        return damage;
    }
  
};


//Cyberdemon is a child class and inherit the Demon class
class Cyberdemon : public Demon {
private:
    const string Species = "Cyberdemon";
public: 
    Cyberdemon() : Demon(){}
    Cyberdemon(int str, int hp) : Demon("Cyberdemon", str, hp) {}
   

    /* 
    Cyberdemon getDamage() inflict damage of 50 with a 5% chance
    It returns the damage
    */
   int getDamage() const override  {
        int damage= (rand() % Creature::getStrength()) + 1;
        cout << getSpecies() << " attack for " <<
            damage << " points." << endl;
        if ((rand() % 100) < 5)
        {
           damage = damage + 50;
            cout << "Demonic attack inflicts 50 "
                << " additional damage points!" << endl;
        }
        return damage;
        
   }

   /*
  getSpeices() is a virtual function, when it is called,
  The override function will
  be called instead of the base class' function
  It returns a string which indicate the name of the speices.
  */
   string getSpecies() const override {
       return Species;
   }
};

//Balrog is a child class and inherit the Demon class
class Balrog : public Demon {
private:
    const string Species = "Balrog";
public:
    Balrog() : Demon(){}
    Balrog(int str, int hp) : Demon("Balrog" , str, hp) {}
    /*

    Balrog getDamge() get to attack twice
    It return the total damage

    */
    int getDamage() const override {
        int damage= (rand() % Creature::getStrength()) + 1;
        cout << getSpecies() << " attack for " <<
            damage << " points!" << endl;

        int damage2 = (rand() % Creature::getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 <<
            " additional damage points!" << endl;
        damage = damage + damage2;
       
        return damage;
    }
    /*
    getSpeices() is a virtual function, when it is called,
    The override function will
    be called instead of the base class' function
    It returns a string which indicate the name of the speices.
    */
    string getSpecies() const override {
        return Species;
    }
};


/*
battalArena is a function where it receives two creature objects
pass by references and started calculate
the hitpoints of these two creatures.

If one creature has positive hitpoints while the other do not 
then the battle is over, and the creature who has
the positive hitpoints win

If one creature have zero hitpoints 
and the other have positive hitpoints,
then the creature have positive hitpoints win

If one creature have zero hitpoints 
and the other have negative hitpoints, 
then it will be tie

If they both have zero or negative hitpoints, it will be tie 

It return nothing.
*/
void battleArena(Creature &creature1, Creature &creature2) {
    cout << "-----------Battle Begin------------" << endl;
    int result, result1;
    bool Check = true;
    //result represent the hitpoints of the creature 2
    result = creature2.getHitpoints() - creature1.getDamage();
    cout << "Creature 2 has " << result << " hit points." << endl;

    //result1 represent the hitpoints of creature 1 
    result1 = creature1.getHitpoints() - creature2.getDamage();
    cout << "Creature 1 has " << result1 << " hit points." << endl;

    while (Check) {
        if (result > 0 && result1 > 0) {
     
                result = result - creature1.getDamage();
                cout << "Creature 2 has " << 
                    result << " hit points." << endl;
                result1 = result1 - creature2.getDamage();
                cout << "Creature 1 has " <<
                    result1 << " hit points." << endl;
                
        }

        if (result < 0 && result1 > 0) {
            cout << "\nCreature 1 wins! " << endl;
            Check = false;
        
        }
        else if (result > 0 && result1 < 0) {
            cout << "\nCreature 2 wins! " << endl;
            Check = false;
           
        }
        else if (result > 0 && result1 == 0) {
            cout << "\nCreature 2 wins!" << endl;
            Check = false;
     
        }
        else if (result == 0 && result1 > 0) {
            cout << "\nCreature 1 wins!" << endl;
            Check = false;
    
        }
        else if (result == 0 && result1 < 0) {
            cout << "\nTie!! " << endl;
            Check = false;
   
        }
        else if (result < 0 && result1 == 0) {
            cout << "\nTie!!" << endl;
            Check = false;
 
        }

        else if (result == 0 && result1 == 0) {
            cout << "\nTie!!" << endl;
            Check = false;
        }
        else if (result < 0 && result1 < 0) {
            cout << "\nTie!!" << endl;
            Check = false;
        }
    }
}


int main()
{
    srand(static_cast<int>(time(NULL)));
    Human human1(30, 10);
    human1.getDamage();
    cout << endl;
    Elf elf1;
    elf1.getDamage();
    cout << endl;
    Balrog balrog1(50, 50);
    balrog1.getDamage();
    cout << endl;
    Cyberdemon cdemon(30, 40);
    cdemon.getDamage();
    cout << endl;
    Elf elf2(50, 50);
    cout << endl;
    Balrog balrog2(50, 50);
    cout << endl;
    battleArena(elf2, balrog2);
}


/*================SAMPLE RUN====================
RESULT: TIE 

Human attack for 8 points!

Elf attack for 10 points!

Balrog attack for 1 points!
Balrog speed attack inflicts 18 additional damage points!

Cyberdemon attack for 4 points.



-----------Battle Begin------------
Elf attack for 29 points!
Creature 2 has 21 hit points.
Balrog attack for 32 points!
Balrog speed attack inflicts 1 additional damage points!
Creature 1 has 17 hit points.
Elf attack for 33 points!
Creature 2 has -12 hit points.
Balrog attack for 35 points!
Balrog speed attack inflicts 45 additional damage points!
Creature 1 has -63 hit points.

Tie!!

D:\CIS 22 B\Assignment 7\Project1\Debug\Project1.exe (process 52136) exited with code 0.
Press any key to close this window . . .



RESULT: Creature 2 wins 

Human attack for 9 points!

Elf attack for 5 points!

Balrog attack for 22 points!
Balrog speed attack inflicts 6 additional damage points!

Cyberdemon attack for 18 points.



-----------Battle Begin------------
Elf attack for 34 points!
Creature 2 has 16 hit points.
Balrog attack for 50 points!
Balrog speed attack inflicts 50 additional damage points!
Creature 1 has -50 hit points.

Creature 2 wins!

D:\CIS 22 B\Assignment 7\Project1\Debug\Project1.exe (process 19776) exited with code 0.
Press any key to close this window . . .


RESULT: Creature 1 wins 

Human attack for 25 points!

Elf attack for 8 points!

Balrog attack for 23 points!
Balrog speed attack inflicts 34 additional damage points!

Cyberdemon attack for 18 points.



-----------Battle Begin------------
Elf attack for 27 points!
Magical attack inflicts 27 additional damage points!
Creature 2 has -4 hit points.
Balrog attack for 18 points!
Balrog speed attack inflicts 9 additional damage points!
Creature 1 has 23 hit points.

Creature 1 wins!

D:\CIS 22 B\Assignment 7\Project1\Debug\Project1.exe (process 15388) exited with code 0.
Press any key to close this window . . .



*/