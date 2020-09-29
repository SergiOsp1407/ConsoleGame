#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    x=1;
    y=1;
}

void Player::CallInput(){
    char UserInput=' ';
    cin>>UserInput;
    switch(UserInput){
    case 'w':
        lastX=x;
        x=x-1;

        break;
    case 'a':
        lastY=y;
        y=y-1;

        break;
    case 's':
        lastX=x;
        x=x+ 1;

        break;
    case 'd':
        lastY=y;
        y=y+1;

        break;

    }
    cout<<"Mi jugador esta en las coordenadas: ("<<x<<","<<y<<")"<<endl;
}

void Player::ResetToSafePosition()
{
    x=lastX;
    y=lastY;
}
