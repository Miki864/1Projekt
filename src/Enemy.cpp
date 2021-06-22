#include "Enemy.h"

Enemy::Enemy(int i)
{
    switch (i){
        case 1:{setid("Dragon");protection_plus(2);max_hp_plus(10);damage_given_plus(2);}break;
        case 2:{setid("Bandit");}break;
        case 3:{setid("Orc");protection_plus();max_hp_plus(5);}break;

}}

Enemy::~Enemy()
{
    //dtor
}
