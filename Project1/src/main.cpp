#include <iostream>

#include "Game.h"


int main(void)
{
    Game game;
    game.setMaxFramerate(30);



    //Game Loop
    while (game.isRunning()){
       

        //UPDATE
        game.update();
        //RENDER
        game.render();
    }

    return 0;
}