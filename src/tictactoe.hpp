#include <string>



class TTTMechanics {
private:
    char board[9];
    char currentplayerid;


public:
    TTTMechanics();

    void resetgame();
    void showboard() const;

    char getplayer() const;
    char retrievecell(int ind) const;

    bool makemove(int pos);
    bool checkifcelltaken(int pos) const;

    bool winnerofgame() const;

    bool draw() const;

    void switchcurrentplayer();

    //new code

    int firstavailableselectionongrid() const;





};