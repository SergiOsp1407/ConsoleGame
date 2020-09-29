#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapSet.h"
class GameMap
{
    public:
        GameMap();
        MapSet* PlayerCell;
        MapSet cells[15][10] ;

        void DrawIntro();
        void DrawVictory();

        void Draw();
        //Esta funcion obtiene las coordenada de player y actualiza el mapa
        bool SetPlayerCell(int PlayerX, int PlayerY);
        bool isGameOver = false;

    protected:
        void LoadMapFromFile();

    private:
};

#endif // GAMEMAP_H
