#ifndef ROOM_H
#define ROOM_H
#include <Enemy.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Cegla.h>
#include <iostream>
#include <vector>
class Room
{
    public:
        Room(){};
        ~Room();

        void dispneighbours(){for(int i=0;i<4;i++){std::cout<<neighbours[i]<<std::endl;}std::cout<<"\n";}
        void drawroom(sf::RenderWindow &window);
        int neighbours[4]={0,0,0,0};
        void dispid(){std::cout<<"\nRoom id: "<<id<<"\n";}
        void setid(int b){id=b;}
        Enemy inhabitant=Enemy(3);//=Enemy(Enemy_kind);
        bool isalive=true;
        //void spawn(sf::RenderWindow window);
        void setneighbours(int right,int left,int up,int down){neighbours[0]=right;neighbours[1]=left;neighbours[2]=up;neighbours[3]=down;}
    protected:
        int id;
        int Enemy_kind;



};

#endif // ROOM_H
