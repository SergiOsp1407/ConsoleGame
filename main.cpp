#include <iostream>
#include "Player.h"
#include "MapSet.h"
#include "GameMap.h"
using namespace std;

int main()
{
    GameMap Map;
    Player Hero;
    Map.DrawIntro();
    Map.Draw();
    while(Map.isGameOver==false){
        //Aqui es el loop de nuestro juego
        cout<<"Introduce el comando de movimiento 'w''a''s''d'"<<endl;
        Hero.CallInput();
        //Actualizado de informacion heroe a mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y)){
           Map.Draw();
        }else{
            Hero.ResetToSafePosition();
            Map.Draw();
        }
    }
    return 0;
}
