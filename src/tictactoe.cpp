#include <string>

#include "tictactoe.hpp"
#include <iostream>
using namespace std;


TTTMechanics::TTTMechanics() {
    resetgame();
}




void TTTMechanics::resetgame() {
    board[0] = '1';
    board[1] = '2';
    board[2] = '3';
    board[3] = '4';
    board[4] = '5';
    board[5] = '6';
    board[6] = '7';
    board[7] = '8';
    board[8] = '9';

    currentplayerid = 'X';
}


void TTTMechanics::showboard() const {

    cout<<"\n";
    cout<<" "<<board[0]<<" | "<<board[1]<< " | "<<board[2]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[6]<<" | "<<board[7]<< " | "<<board[8]<<"\n";
    cout<<"\n";
}

char TTTMechanics::getplayer() const {
    return currentplayerid;
}

char TTTMechanics::retrievecell(int ind) const {
    if (ind < 0 || ind > 8) {
        return '?';
    }
    return board[ind];
}


bool TTTMechanics::checkifcelltaken(int pos) const {
    if (pos < 1 || pos > 9) {
        return true;
    }
    if (board[pos-1] =='X' || board[pos-1] =='O') {
        return true;
    }
    return false;
}

//new code

int TTTMechanics::firstavailableselectionongrid() const {
    for (int x=0; x<=9; x++) {
        if (!checkifcelltaken(x)) {
            return x;
        }
    }
    return -1;
}

bool TTTMechanics::makemove(int pos) {
    if (pos < 1 || pos > 9) {
        return false;
    }

    if (checkifcelltaken((pos))) {
        return false;
    }
    board[pos-1] = currentplayerid;
    return true;

}

void TTTMechanics::switchcurrentplayer() {
    if (currentplayerid == 'X') {
        currentplayerid = 'O';
    } else {
        currentplayerid = 'X';

    }
}


bool TTTMechanics::winnerofgame() const {
    if (board[0]==board[1] && board[1]==board[2]) {
        return true;
    }
    if (board[3] == board[4] && board[4]==board[5]) {
        return true;
    }
    if (board[6] == board[7] && board[7]==board[8]) {
        return true;
    }

    if (board[0]==board[3] && board[3]==board[6]) {
        return true;
    }

    if (board[1] == board[4] && board[4]==board[7]) {
        return true;
    }

    if (board[2] == board[5] && board[5]==board[8]) {
        return true;
    }

    if (board[0] == board[4] && board[4]==board[8]) {
        return true;
    }

    if (board[2] == board[4] && board[4]==board[6]) {
        return true;


    }
  return false;
}

bool TTTMechanics::draw() const {
    if (winnerofgame()) {
        return false;
    }

    int a;
    for (a=0; a<9;a++) {
        if (board[a] != 'X' && board[a]!= 'O') {
            return false;
        }
    }

    return true;
}