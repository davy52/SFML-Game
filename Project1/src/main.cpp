#include <iostream>

#include "Game.h"


int main(void)
{
    Game* game;
    game = new Game();
    game->setMaxFramerate(30);



    //Game Loop
    while (game->isRunning()){
       

        //UPDATE
        game->update();
        //RENDER
        game->render();
    }

    delete game;
    return 0;
}