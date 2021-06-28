#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Entity : public sf::Sprite
{
    public:
        Entity(){}
        virtual ~Entity(){}
        void st_plus(int bonus=1){st+=bonus;}
        void ag_plus(int bonus=1){ag+=bonus;}
        void iq_plus(int bonus=1){iq+=bonus;}
        int  agil(){return ag;}
        int  sila(){return st;}
        int  inte(){return iq;}
        void healing_skill_plus(int bonus=1){healing_skill+=bonus;}
        void damage_given_plus(int bonus=1){damage_given+=bonus;}
        void protection_plus(int bonus=1){protection+=bonus;}
        void hurt(int dmg){if(dmg>protection){hp=hp-dmg+protection;}}
        void heal(int healing){if(hp+healing>max_hp){hp=max_hp;}else{hp=hp+healing;}}
        void max_hp_plus(int bonus=1){max_hp+=bonus;heal(bonus);}
        void healself(){heal(healing_skill);}
        int  health(){return hp;}
        int  max_health(){return max_hp;}
        int  armor(){return protection;}
        int  healing(){return healing_skill;}
        void setid(std::string i){id=i;};
        std::string id;
        virtual void action()=0;
        int deal_damage(){return damage_given;}
    protected:
        int st=4, ag=4, iq=4;
        int hp=10,max_hp=10,healing_skill=1,damage_given=3,protection=0;
        sf::Texture tekstura;

};

#endif
