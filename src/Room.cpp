#include "Room.h"

void Room::drawroom(sf::RenderWindow &window){

    Cegla _1=Cegla('L');
    _1.setPosition(0,0);
    window.draw(_1);
    _1.setPosition(400,0);
    window.draw(_1);
    _1.setPosition(0,525);
    window.draw(_1);
    _1.setPosition(400,525);
    window.draw(_1);
    if(neighbours[3]<1){_1.setPosition(200,525);window.draw(_1);}
    if(neighbours[2]<1){_1.setPosition(200,0);window.draw(_1);}
    _1.rotate(90);
    _1.setPosition(75,0);
    window.draw(_1);
    _1.setPosition(75,400);
    window.draw(_1);
    _1.setPosition(600,0);
    window.draw(_1);
    _1.setPosition(600,400);
    window.draw(_1);
    if(neighbours[1]<1){_1.setPosition(75,200);window.draw(_1);}
    if(neighbours[0]<1){_1.setPosition(600,200);window.draw(_1);}
}

    /*void Room::spawn(sf::RenderWindow window){

        &inhabitant.setPosition(320,200);
        window.draw(&inhabitant);


        }
*/
Room::~Room()
{
    //delete inhabitant;
}
