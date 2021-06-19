#ifndef CEGLA_H
#define CEGLA_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Cegla : public sf::Sprite
{
    public:
        Cegla(char a);
        virtual ~Cegla();

    protected:
        sf::Texture tekstura;
    private:
};

#endif // CEGLA_H
