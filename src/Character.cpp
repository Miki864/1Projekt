#include "Character.h"

Character::Character(std::string _class,std::string _name){id=_class;name=_name;ag_plus();
    if(_class=="Wizard"){iq_plus(4);healing_skill_plus(2);tekstura.loadFromFile("Wizard.png");setTexture(tekstura);}
    else if(_class=="Rouge"){ag_plus(3);healing_skill_plus(2);iq_plus();tekstura.loadFromFile("Rouge.png");setTexture(tekstura);}
    else if(_class=="Warrior"){st_plus(5);protection_plus(2);damage_given_plus(2);max_hp_plus(5);tekstura.loadFromFile("Warrior.png");setTexture(tekstura);}
}

Character::~Character()
{
    //dtor
}

//tekstura.loadFromFile("Wall.png");setTexture(tekstura);setTextureRect(sf::IntRect(0,0,200,75));
