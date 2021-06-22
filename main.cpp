#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Entity.h>
#include <Room.h>
#include <Character.h>
#include <Windows.h>

int diceroll(int sides){
    int side;
    if(sides==0){side=0;}
    else{side=(rand()%sides)+1;}
    return side;}

bool check(int a,int b){
    int c=a-b;
    int d=-1;
    int e=1;
    if(c<-2){d=diceroll(10);}
    else if(c<0){d=diceroll(4);}
    else if(c==0){d=diceroll(2);}
    else if(c<2){e=diceroll(4);}
    else {e=diceroll(10);}
    if(d==1){return true;}
    else if(e>1){return true;}
    else {return false;}

}

int main()
{   srand(time(NULL));
    Room mapa[5];
        for(int i=1;i<5;i++){
            mapa[i].setid(i);
            mapa[i].setneighbours(i+1,i-1,0,0);
            std::cout<<"\n";
        }

        mapa[4].setneighbours(0,3,0,0);

    sf::Sprite Sbandit;
    sf::Texture teksturaB;
    teksturaB.loadFromFile("Bandit.png");Sbandit.setTexture(teksturaB);
    Sbandit.setPosition(320,200);

    sf::Sprite Sdragon;
    sf::Texture teksturaD;
    teksturaD.loadFromFile("Dragon.png");Sdragon.setTexture(teksturaD);
    Sdragon.setPosition(320,100);

    sf::Sprite Sorc;
    sf::Texture teksturaO;
    teksturaO.loadFromFile("Orc.png");Sorc.setTexture(teksturaO);
    Sorc.setPosition(320,180);

    Character ziom=Character("Warrior","Stefan");
    ziom.setPosition(200,180);

    int activeroom=1;

    mapa[activeroom].dispid();

    bool isfighting=false;
    bool playersturn=true;

    sf::RenderWindow window(sf::VideoMode(600,600),"Brightest Dungeon",sf::Style::Close|sf::Style::Titlebar);

    std::cout<<mapa[activeroom].inhabitant.id<<"\n";

    while (window.isOpen()) {


        window.clear(sf::Color::Black);
        mapa[activeroom].drawroom(window);
        window.draw(ziom);

        if(mapa[activeroom].isalive){
            if(mapa[activeroom].inhabitant.id=="Bandit"){
            window.draw(Sbandit);}
            if(mapa[activeroom].inhabitant.id=="Dragon"){
            window.draw(Sdragon);}
            if(mapa[activeroom].inhabitant.id=="Orc"){
            window.draw(Sorc);}        }

        if(!playersturn&&isfighting){
            if(check(ziom.agil(),mapa[activeroom].inhabitant.agil())){ziom.hurt(mapa[activeroom].inhabitant.deal_damage());playersturn=true;std::cout<<ziom.health()<<" zdrowie\n";}
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();}
            if(!isfighting){
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::W&&mapa[activeroom].neighbours[2]!=0){activeroom=mapa[activeroom].neighbours[2];std::cout<<"w"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::S&&mapa[activeroom].neighbours[3]!=0){activeroom=mapa[activeroom].neighbours[3];std::cout<<"s"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::A&&mapa[activeroom].neighbours[1]!=0){activeroom=mapa[activeroom].neighbours[1];std::cout<<"a"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::D&&mapa[activeroom].neighbours[0]!=0){activeroom=mapa[activeroom].neighbours[0];std::cout<<"d"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                    }
            else if(isfighting&&playersturn){
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::A){if(check(ziom.agil(),mapa[activeroom].inhabitant.agil())){mapa[activeroom].inhabitant.hurt(ziom.deal_damage());}else {std::cout<<"Pudlo\n";}playersturn=false;std::cout<<mapa[activeroom].inhabitant.health()<<"\n";}
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::H){ziom.healself();playersturn=false;}
                //if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::U){if(ziom.ag+diceroll(1)-1>mapa[activeroom].inhabitant.ag)}
}}
        if(mapa[activeroom].inhabitant.health()<1){mapa[activeroom].isalive=false;playersturn=true;}
        if(mapa[activeroom].isalive){isfighting=true;}
        else{isfighting=false;}



        window.display();

    }


    return 0;
}
