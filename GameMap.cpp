#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver=false;
}

void GameMap::Draw(){
for(int i=0;i<15;i++){
    for(int p=0;p<10;p++){
        cout<<cells[i][p].id;
        }
        cout<<endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY){

    if(cells[PlayerX][PlayerY].IsBlocked()==false){
            if(cells[PlayerX][PlayerY].id== '$'){
                    DrawVictory();
                    isGameOver = true;
                    return true;
            }else{
                 if(PlayerCell != NULL){
                    PlayerCell->id = 0;
                    }
                    PlayerCell = &cells[PlayerX][PlayerY];
                    PlayerCell->id = '3';
            }
            return true;
            //cout<<"Las coordenadas del jugador estan en:"<<PlayerX<<","<<PlayerY;
    }else{
        return false;
    }
}

void GameMap::DrawIntro(){

    string line;
    int row=0;
    ifstream MyFile("Intro.txt");

    if(MyFile.is_open()){
            while(getline(MyFile, line)){
                    cout<<line<<endl;
            }
            cin>>line;
    }else{
        cout<<"FATAL ERROR: INTRO COULD NOT BE LOADED!"<<endl;
    }


}

void GameMap::DrawVictory(){

    string line;
    int row=0;
    ifstream MyFile("Victory.txt");

    if(MyFile.is_open()){
            while(getline(MyFile, line)){
                    cout<<line<<endl;
            }
            cin>>line;
    }else{
        cout<<"FATAL ERROR: VICTORY COULD NOT BE LOADED!"<<endl;
    }
}


void GameMap::LoadMapFromFile(){
    /*ofstream FileCreated("Map.txt");
    if(FileCreated.is_open()){

    }else{
        cout<<"FATAL ERROR: MAP FILE COULD NOT BE CREATED!"<<endl;
    }*/
    string line;
    int row=0;
    ifstream MyFile("Map.txt");
    if(MyFile.is_open()){
        while(getline(MyFile,line)){
            for(int p=0;p<line.length();p=p+1){
                if(line[p]=='0'){
                    cells[row][p].id = 0;
                }else{
                    cells[row][p].id=line[p];
                }
            }
            row++;
        }
    }else{
        cout<<"FATAL ERROR: MAP FILE COULD NOT BE LOADED!"<<endl;
    }
}




