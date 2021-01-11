#ifndef ___GAMEBOARD___
#define ___GAMEBOARD___
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <iostream>
using namespace std;
class Square;
class Player;
class Observer;
class GameBoard{
    std::vector<std::shared_ptr<Square>> board;
    std::map<std::string, int> monopolycollection = {
      {"Arts1",2}, {"Arts2", 3}, {"Eng", 3},{"Health",3} ,{"Env",3},{"Sci1",3}, {"Sci2",3}, {"Math",2}
    };
    std::map<std::string, int> indexsearch;
    std::map<std::string, std::shared_ptr<Player>> playersearch;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::string> Monopolies;
    std::vector<std::shared_ptr<Observer>> observers;
    std::shared_ptr<Player> currentPlayer;
    int Dice1;
    int Dice2;
    bool TestingMode = false;
    int totalcups;
    int totalsteps = 0;
    int rollTimes = 1;

    public:
    GameBoard();
    void mortgage(string p);
    void unmortgage(string p);
    void MoveOnNewLocation();
    void makeImprovement(std::string property);
    void SellImprovement(std::string property);
    std::vector<std::shared_ptr<Square>> getBoard();
    std::shared_ptr<Player> getCurrPlayer();
    std::vector<std::shared_ptr<Player>> getPlayers();
    std::shared_ptr<Player> GoToNextPlayer();
    bool TestingModeOn();
    void setTestingMode();
    int RollDice();
    int setDice1(int);
    int setDice2(int);
    int getDice1();
    int getDice2();
    void updateCups(int cup);
    int getCups();
    bool rimCupRandom();
    void initial();
    void roll();
    void rollOnce();
    void loadfile(std::string loadfile);
    void savefile(std::string out);
    void trade(std::string name, std::string give,std::string receive);
    bool bankrupt(std::shared_ptr<Player> owner, bool force_bankrupt);
};

#endif
