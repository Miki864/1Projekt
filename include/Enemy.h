#ifndef ENEMY_H
#define ENEMY_H

#include <Entity.h>


class Enemy : public Entity
{
    public:
        Enemy(int i);
        ~Enemy();
        void action(){};
    protected:

    private:
};

#endif // ENEMY_H
