#include "Enemy.h"

Enemy::Enemy(int i)
{
    switch (i){
        case 1:{id="Dragon";protection_plus(2);max_hp_plus(10);damage_given_plus(2);tekstura.loadFromFile("Dragon.png");setTexture(tekstura);}break;
        case 2:{id="Bandit";tekstura.loadFromFile("Bandit.png");setTexture(tekstura);}break;
        case 3:{id="Orc";tekstura.loadFromFile("Orc.png");setTexture(tekstura);protection_plus();max_hp_plus(5);}break;

}}

Enemy::~Enemy()
{
    //dtor
}
