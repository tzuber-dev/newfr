#include <iostream>
#include <string>
#include "src/tictactoe.hpp"


bool validinputformovement(const std::string& inputuser) {
    if (inputuser.length() !=1) {

        return false;

    }

    if (inputuser[0] < '1' || inputuser[0] > '9') {
        return false;
    }
    return true;
}


bool validinputformovement(const std::string inputuser) {
    if (inputuser.length() !=1) {
        return false;
    }
    if (inputuser[0] == 'Y' || inputuser[0] == 'n' || inputuser[0] == 'N' || inputuser[0] == 'n' ) {
        return true;
    }
    return false;
}




int main() {
    TTTMechanics tictactoe;
    std::string inputuserfield;
    bool playonemoretime = true;

    std::cout<<"Welcome to the Tic-Tac-Toe game!";
    std::cout<<"A Player is letter X and B Player is letter O";


    while (playonemoretime) {

        tictactoe.showboard();
        tictactoe.resetgame();


        while (true){
            std::cout<<"Player"<<tictactoe.getplayer()<<" enter a move (1-9): ";
            std::getline(std::cin,inputuserfield);

            //if (invalidinput)
            int usermove = inputuserfield[0] - '0';
            if (!tictactoe.makemove(usermove)) {
                std::cout<<"Invalid move from the user. Cell taken or not in range. Reattempt \n";
                continue;
            }

            tictactoe.showboard();
            if (tictactoe.winnerofgame()) {
                tictactoe.showboard();
                std::cout<<"Player "<<tictactoe.getplayer()<<" wins the match!\n";
                break;
            }
            if (tictactoe.draw()) {
                tictactoe.showboard();
                std::cout<<"Draw! \n";
                break;
            }
            tictactoe.switchcurrentplayer();
        }


        while (true){
            std::cout<<"Play again? (y/n)";
            std::getline(std::cin,inputuserfield);

            ///add anms

            if (inputuserfield[0] == 'Y' && inputuserfield[0] == 'y') {

                playonemoretime = true;



            } else {
                playonemoretime = false;
            }
            break;

        }
        std::cout<<"Thanks for playing the game!";
        return 0;
    }
};