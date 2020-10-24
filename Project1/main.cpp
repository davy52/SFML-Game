#include <iostream>

#include "Game.h"


int main(void)
{
    Game game;




    //Game Loop
    while (game.isRunning()){
       


        //UPDATE
        game.update();
        //RENDER
        if (game.getFpsTime() > 32) {
            game.render();
            game.updateFpsTime();
        }
    }

    return 0;
}