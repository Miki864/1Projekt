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

int main(){
    srand(time(NULL));
    bool game=true;

    sf::Font font;
    if(!font.loadFromFile("Font.ttf")) {
        std::cout<<"loading fail!\n";}


    Room mapa[20];
        for(int i=1;i<20;i++){
            mapa[i].setid(i);
            mapa[i].inhabitant=Enemy(diceroll(3));}

    mapa[1].setneighbours(2,0,0,0);
    mapa[2].setneighbours(8,1,0,3);
    mapa[3].setneighbours(4,0,2,0);
    mapa[4].setneighbours(0,3,8,5);
    mapa[5].setneighbours(6,0,4,0);
    mapa[6].setneighbours(7,5,0,0);
    mapa[7].setneighbours(16,6,14,15);
    mapa[8].setneighbours(0,2,9,4);
    mapa[9].setneighbours(11,0,10,8);
    mapa[10].setneighbours(0,0,0,9);
    mapa[11].setneighbours(12,9,0,0);
    mapa[12].setneighbours(0,11,0,13);
    mapa[13].setneighbours(0,0,12,14);
    mapa[14].setneighbours(0,0,13,7);
    mapa[15].setneighbours(0,0,7,0);
    mapa[16].setneighbours(17,7,0,5);
    mapa[17].setneighbours(0,16,18,0);
    mapa[18].setneighbours(0,0,19,17);
    mapa[19].setneighbours(0,0,0,18);


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

    sf::Text herodisplay;
        herodisplay.setFont(font);
        herodisplay.setCharacterSize(20);
        herodisplay.setPosition(10,600);

    sf::Text enemydisplay;
        enemydisplay.setFont(font);
        enemydisplay.setCharacterSize(20);
        enemydisplay.setPosition(420,600);

    sf::Text heroinfo;
        heroinfo.setFont(font);
        heroinfo.setCharacterSize(30);
        heroinfo.setPosition(85,100);


    sf::Text enemyinfo;
        enemyinfo.setFont(font);
        enemyinfo.setCharacterSize(30);
        enemyinfo.setPosition(320,100);


    sf::Text gameover;
        gameover.setFont(font);
        gameover.setCharacterSize(60);
        gameover.setPosition(85,100);
        gameover.setString("Game Over!");

    sf::Text instruction;
        instruction.setFont(font);
        instruction.setCharacterSize(30);
        instruction.setPosition(50,100);
        instruction.setString("Moving:\n   A - move left\n   D - move right\n   W - move up\n   S - move down\nFight:\n   A - attack\n   H - healing\n   U - run to last room\n\n Press W to continue.");

    int activeroom=4;
    int previousroom=0;
    int defeated=0;
    int activity=1;

    mapa[activeroom].dispid();

    bool isfighting=false;
    bool playersturn=true;
    bool isinfo=false;

    std::string okno="Instruction";

    sf::RenderWindow window(sf::VideoMode(600,700),"Brightest Dungeon",sf::Style::Close|sf::Style::Titlebar);



    while (window.isOpen()) {

        window.clear(sf::Color::Black);

        if(okno=="Instruction"){
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type==sf::Event::Closed){
                    window.close();}
            if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::W){okno="Game";}}
                    window.draw(instruction);
                    window.display();
        }

        if(okno=="Game"){

        mapa[activeroom].drawroom(window);
        window.draw(ziom);

        if(mapa[activeroom].isalive){
            if(mapa[activeroom].inhabitant.id=="Bandit"){
            window.draw(Sbandit);}
            if(mapa[activeroom].inhabitant.id=="Dragon"){
            window.draw(Sdragon);}
            if(mapa[activeroom].inhabitant.id=="Orc"){
            window.draw(Sorc);}        }

        if(!playersturn&&isfighting&&game){
            activity=diceroll(6);
            if(mapa[activeroom].inhabitant.max_health()/2>mapa[activeroom].inhabitant.health()&&activity==1)
                    {mapa[activeroom].inhabitant.healself();enemyinfo.setString("Healing +"+std::to_string(mapa[activeroom].inhabitant.healing()));playersturn=true;}
            else if(check(mapa[activeroom].inhabitant.agil()+diceroll(2),ziom.agil()))
                {ziom.hurt(mapa[activeroom].inhabitant.deal_damage());playersturn=true;enemyinfo.setString("Hit!");heroinfo.setString("-"+std::to_string(mapa[activeroom].inhabitant.deal_damage())+" HP");}else{enemyinfo.setString("Miss!");playersturn=true;}
        isinfo=true;}

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type==sf::Event::Closed){
                window.close();}
            if(!isfighting&&game){
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::W&&mapa[activeroom].neighbours[2]!=0){previousroom=activeroom;activeroom=mapa[activeroom].neighbours[2];std::cout<<"w"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::S&&mapa[activeroom].neighbours[3]!=0){previousroom=activeroom;activeroom=mapa[activeroom].neighbours[3];std::cout<<"s"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::A&&mapa[activeroom].neighbours[1]!=0){previousroom=activeroom;activeroom=mapa[activeroom].neighbours[1];std::cout<<"a"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::D&&mapa[activeroom].neighbours[0]!=0){previousroom=activeroom;activeroom=mapa[activeroom].neighbours[0];std::cout<<"d"<<std::endl;mapa[activeroom].dispid();}//if(mapa[activeroom].isalive){fighter=mapa[activeroom].inhabitant;}};
                    }
            else if(event.type==sf::Event::KeyPressed&&isfighting&&playersturn&&game){
                std::string a;
                if(event.key.code==sf::Keyboard::A){if(check(ziom.agil(),mapa[activeroom].inhabitant.agil())){heroinfo.setString("Hit!");if(ziom.deal_damage()>mapa[activeroom].inhabitant.armor()){a=std::to_string(ziom.deal_damage()-mapa[activeroom].inhabitant.armor());}else{a="0";}enemyinfo.setString("-"+a+"HP");mapa[activeroom].inhabitant.hurt(ziom.deal_damage());}
                    else {heroinfo.setString("Miss!");};}
                if(event.key.code==sf::Keyboard::H){ziom.healself();heroinfo.setString("+"+ziom.healing());}
                playersturn=false;
                if(event.key.code==sf::Keyboard::U){if(ziom.agil()+diceroll(2)-1>mapa[activeroom].inhabitant.agil()&&previousroom!=0){heroinfo.setString("Retreat succesfull!");activeroom=previousroom;playersturn=1;}else{heroinfo.setString("Retreat failed!");};}
                isinfo=true;

}}
        if(game&&mapa[activeroom].inhabitant.health()<1&&mapa[activeroom].isalive){mapa[activeroom].isalive=false;playersturn=true;defeated++;activity=1;
            switch(diceroll(6)){
                case 1:{ziom.max_hp_plus();ziom.heal(1);}break;
                case 2:{ziom.healing_skill_plus();}break;
                case 3:{ziom.protection_plus();}break;
                case 4:{ziom.damage_given_plus();}break;}
                enemyinfo.setString("Defeated!");isinfo=1;
            }
        if(mapa[activeroom].isalive){isfighting=true;}
        else{isfighting=false;}

        herodisplay.setString("Health:   "+std::to_string(ziom.health())+"/"+std::to_string(ziom.max_health())+"\nDamage:  "+std::to_string(ziom.deal_damage())+"\nHealing:  "+std::to_string(ziom.healing())+"\nArmor:   "+std::to_string(ziom.armor())+"\nDefeated: "+std::to_string(defeated));//+"\nAgility: "+std::to_string(ziom.agil())+"\nStrength: "+std::to_string(ziom.sila())+"\nIq: "+std::to_string(ziom.inte()));
        window.draw(herodisplay);

        if(mapa[activeroom].isalive){
        enemydisplay.setString(mapa[activeroom].inhabitant.id+"\nHealth:   "+std::to_string(mapa[activeroom].inhabitant.health())+"/"+std::to_string(mapa[activeroom].inhabitant.max_health())+"\nDamage:  "+std::to_string(mapa[activeroom].inhabitant.deal_damage())+"\nHealing:  "+std::to_string(mapa[activeroom].inhabitant.healing())+"\nArmor:   "+std::to_string(mapa[activeroom].inhabitant.armor()));
        window.draw(enemydisplay);}

        if(ziom.health()<1){window.draw(gameover);game=false;}
        if(defeated==19){gameover.setString("You've won!");window.draw(gameover);}

        if(isinfo){window.draw(enemyinfo);
        window.draw(heroinfo);}
        window.display();
        if(isinfo){Sleep(1000);isinfo=false;heroinfo.setString("");enemyinfo.setString("");}
        }//end of game
        }//end of while(window.is_open)

    return 0;}
