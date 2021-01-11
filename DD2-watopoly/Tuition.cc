#include "Tuition.h"

Tuition::Tuition (string Name,int Index) : NonProperty{Name,Index} {}

int Tuition::Event(std::shared_ptr<Player> p,int totalWorth){
  cout << "Are you ready to pay your tuition?" << endl;
  cout << "Press 300 if you like to pay $300 tuition, press 10% if you like to pay 10% of your total worth, which is $"<< 0.1*totalWorth <<" tuition." << endl;
  string cmd;
  cin >> cmd;
  if(cmd == "300"){
    return (0 - tuition);
  }
  if(cmd == "10%") {
    return (0 - percentage*totalWorth);
  }
  cout << "Payment has been received." << endl;
  return 0;
}
