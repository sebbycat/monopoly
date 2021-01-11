#include <iostream>
#include <fstream>
#include <sstream>
#include "GameBoard.h"
#include "Square.h"
#include "Player.h"
#include "Observer.h"

using namespace std;

int main(int argc, char* argv[]) {
  shared_ptr <GameBoard> g = make_shared <GameBoard>();
  string filename;
  string str1;
  string str2;
  bool IsLoaded = false;
  if (argc > 1) {
        str1 = argv[1];
        if (str1 == "-testing") {
            g->setTestingMode();
            if (argc > 2) {
                str2 = argv[2];
                if (str2 == "-load") {
                    filename = argv[3];
                    g->loadfile(filename);
                    IsLoaded = true;
                }
            }
        } 
        else if (str1 == "-load") {
            filename = argv[2];
            g->loadfile(filename);
            IsLoaded = true;
            if (argc > 3) {
              str2 = argv[3];
              if (str2 == "-testing") {
                g->setTestingMode();
              }
            }

        }
    }
    if(IsLoaded == false){
      g->initial();
    }
    string line;
    string command;
    while(cin >> command){
      //istringstream iss{line};
     // iss >> command;
     if(command == "roll" ){
        g->roll();
      } else if(command == "next"){
        g->GoToNextPlayer();
        if (g->getCurrPlayer()->isin_jail()) {
        g->MoveOnNewLocation();
      }
        // add
      } else if(command == "trade"){
        string name;
        string give;
        string receive;
        cin >> name >> give >> receive;
        g->trade(name,give,receive);
        //dosomething
      } else if (command == "improve"){
        string property;
        string action;
        cin >> property >> action;
        if(action == "buy"){
          g->makeImprovement(property);
        } else if (action == "sell"){
          g->SellImprovement(property);
        } else {
          std::cout << "Please enter an valid command, it can only be sell/buy" << std::endl;
        }
        //dosomething
      } else if (command == "mortgage"){
        string property;
        cin >> property;
        g->mortgage(property);
        //dosomething
      } else if (command == "unmortgage"){
        string property;
        cin >> property;
        g->unmortgage(property);
        //dosomething
      } else if (command == "bankrupt"){
        //dosomething
      } else if (command == "assets"){
        auto curr = g->getCurrPlayer();
        curr->printAssets(g->getBoard());
      } else if (command == "all"){
        for(auto n : g->getPlayers()){
          n->printAssets(g->getBoard());
        }
      } else if (command == "save"){
        string filename;
        cin >> filename;
        g->savefile(filename);
      } else if (command == "q"){
        return 0;
      }
    }
}


