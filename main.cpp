#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Entity.h>
#include <Room.h>
#include <Character.h>
#include <Windows.h>
int main()
{   Room mapa[5];
        for(int i=1;i<5;i++){
            mapa[i].setid(i);
            mapa[i].setneighbours(i+1,i-1,0,0);
            std::cout<<"\n";
        }
        mapa[4].setneighbours(0,3,0,0);



    Character ziom=Character("Warrior","Stefan");
    ziom.setPosition(200,180);

    int activeroom=1;

    mapa[activeroom].dispid();
    ///Enemy* fighter;
    bool isfighting=false;

    sf::RenderWindow window(sf::VideoMode(600,600),"Brightest Dungeon",sf::Style::Close|sf::Style::Titlebar);

    while (window.isOpen()) {
        if(mapa[activeroom].isalive){isfighting=true;}

        window.clear(sf::Color::Black);
        mapa[activeroom].drawroom(window);
        window.draw(ziom);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();}
            if(!isfighting){
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::W&&mapa[activeroom].neighbours[2]!=0){activeroom=mapa[activeroom].neighbours[2];std::cout<<"w"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::S&&mapa[activeroom].neighbours[3]!=0){activeroom=mapa[activeroom].neighbours[3];std::cout<<"s"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::A&&mapa[activeroom].neighbours[1]!=0){activeroom=mapa[activeroom].neighbours[1];std::cout<<"a"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::D&&mapa[activeroom].neighbours[0]!=0){activeroom=mapa[activeroom].neighbours[0];std::cout<<"d"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                    }}
        if(mapa[activeroom].isalive){
                window.draw(mapa[activeroom].inhabitant);
        }

        window.display();

    }


    return 0;
}
