#include "Cegla.h"

Cegla::Cegla(char a)
{
    if(a=='l'||a=='L'){tekstura.loadFromFile("Wall.png");setTexture(tekstura);setTextureRect(sf::IntRect(0,0,200,75));}
    if(a=='p'||a=='P'){tekstura.loadFromFile("Wall.png");setTexture(tekstura);setTextureRect(sf::IntRect(0,0,75,200));}
}

Cegla::~Cegla()
{
    //dtor
}
