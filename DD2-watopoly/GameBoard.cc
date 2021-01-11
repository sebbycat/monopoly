#include "GameBoard.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "Player.h"
#include "GooseNesting.h"
#include "AcademicBuilding.h"
#include "OSAP.h"
#include "CoopFee.h"
#include "NeedlesHall.h"
#include "Residence.h"
#include "SLC.h"
#include "Tuition.h"
#include "DCTimsLine.h"
#include "Gym.h"
#include "GoToTims.h"
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>
#include "Auction.h"
#include <sstream>

GameBoard::GameBoard(){
  //AcademicBuilding(name,index,owner, purchaseCost, monopoly,currentLevel,improvementCost,tuition);
  //Property(Name,index,Owner, PurchaseCost)
  auto osap = make_shared<OSAP> ("OSAP",0);
  board.emplace_back(osap);
  vector<int> t_for_al {2,10,30,90,160,250};
  auto al = make_shared <AcademicBuilding>("AL",1,nullptr,40,"Arts1",0,50,t_for_al);
  board.emplace_back(al);
  indexsearch["AL"] = 1;
  auto slc1 = make_shared<SLC> ("SLC",2);
  board.emplace_back(slc1);
  vector<int> t_for_ml{4,20,60,180,320,450};
  auto ml = make_shared <AcademicBuilding>("ML",3,nullptr,60,"Arts1",0,50,t_for_ml);
  board.emplace_back(ml);
  indexsearch["ML"] = 3;
  auto tuition = make_shared <Tuition> ("Tuition",4);
  board.emplace_back(tuition);
  auto mkv = make_shared<Residence>("MKV",5,nullptr,200);
  board.emplace_back(mkv);
  indexsearch["MKV"] = 5;
  vector<int> t_for_ech_pas{6,30,90,270,400,550};
  auto ech = make_shared <AcademicBuilding> ("ECH",6,nullptr,100,"Arts2",0,50,t_for_ech_pas);
  board.emplace_back(ech);
  indexsearch["ECH"] = 6;
  auto needleshall1 = make_shared<NeedlesHall>("NeddlesHall",7);
  board.emplace_back(needleshall1);
  auto pas = make_shared <AcademicBuilding> ("PAS",8,nullptr,100,"Arts2",0,50,t_for_ech_pas);
  board.emplace_back(pas);
  indexsearch["PAS"] = 8;
  vector<int> t_for_hh{8,40,100,300,450,600};
  auto hh = make_shared <AcademicBuilding> ("HH",9,nullptr,120,"Arts2",0,50,t_for_hh);
  board.emplace_back(hh);
  indexsearch["HH"] = 9;
  auto dctimesline = make_shared<DCTimsLine>("DCTimsLine",10);
  board.emplace_back(dctimesline);
  vector<int> t_for_rch_dwe{10,50,150,450,625,750};
  auto rch = make_shared <AcademicBuilding> ("RCH",11,nullptr,140,"Eng",0,100,t_for_rch_dwe);
  board.emplace_back(rch);
  indexsearch["RCH"] = 11;
  auto pac = make_shared <Gym> ("PAC",12,nullptr,150);
  board.emplace_back(pac);
  indexsearch["PAC"] = 12;
  auto dwe = make_shared <AcademicBuilding> ("DWE",13,nullptr,140,"Eng",0,100,t_for_rch_dwe);
  board.emplace_back(dwe);
  indexsearch["DWE"] = 13;
  vector<int> t_for_cph{12,60,180,500,700,900};
  auto cph = make_shared <AcademicBuilding> ("CPH",14,nullptr,160,"Eng",0,100,t_for_cph);
  board.emplace_back(cph);
  indexsearch["CPH"] = 14;
  auto uwp = make_shared<Residence>("UWP",15,nullptr,200);
  board.emplace_back(uwp);
  indexsearch["UWP"] = 15;
  vector<int> t_for_lhi_bmh{14,70,200,550,750,950};
  auto lhi = make_shared <AcademicBuilding>("LHI", 16,nullptr,180,"Health",0,100,t_for_lhi_bmh);
  board.emplace_back(lhi);
  indexsearch["LHI"] = 16;
  auto slc2 = make_shared<SLC> ("SLC",17);
  board.emplace_back(slc2);
  auto bmh = make_shared <AcademicBuilding>("BMH", 18,nullptr,180,"Health",0,100,t_for_lhi_bmh);
  board.emplace_back(bmh);
  indexsearch["BMH"] = 18;
  vector<int> t_for_opt {16,80,220,600,800,1000};
  auto opt = make_shared <AcademicBuilding>("OPT", 19,nullptr,200,"Health",0,100,t_for_opt);
  board.emplace_back(opt);
  indexsearch["OPT"] = 19;
  auto goosenesting = make_shared <GooseNesting>("GooseNesting",20);
  board.emplace_back(goosenesting);
  vector<int> t_for_ev1_ev2 {18,90,250,700,875,1050};
  auto ev1 = make_shared <AcademicBuilding>("EV1",21, nullptr,220,"Env",0,150,t_for_ev1_ev2);
  board.emplace_back(ev1);
  indexsearch["EV1"] = 21;
  auto needleshall2 = make_shared<NeedlesHall>("NeedlesHall",22);
  board.emplace_back(needleshall2);
  auto ev2 = make_shared <AcademicBuilding>("EV2",23, nullptr,220,"Env",0,150,t_for_ev1_ev2);
  board.emplace_back(ev2);
  indexsearch["EV2"] = 23;
  vector<int> t_for_ev3 {20,100,300,750,925,1100};
  auto ev3 = make_shared <AcademicBuilding>("EV3",24, nullptr,240,"Env",0,150,t_for_ev3);
  board.emplace_back(ev3);
  indexsearch["EV3"] = 24;
  auto v1 = make_shared<Residence>("V1",25,nullptr,200);
  board.emplace_back(v1);
  indexsearch["V1"] = 25;
  vector<int> t_for_phys_b1 {22,110,330,800,975,1150};
  auto phys = make_shared <AcademicBuilding>("PHYS",26,nullptr,260,"Sci1",0,150,t_for_phys_b1);
  board.emplace_back(phys);
  indexsearch["PHYS"] = 26;
  auto b1 = make_shared <AcademicBuilding>("B1",27,nullptr,260,"Sci1",0,150,t_for_phys_b1);
  board.emplace_back(b1);
  indexsearch["B1"] = 27;
  auto cif = make_shared <Gym> ("CIF",28,nullptr,150);
  board.emplace_back(cif);
  indexsearch["CIF"] = 28;
  vector<int> t_for_b2 {24,120,360,850,1025,1200};
  auto b2 = make_shared <AcademicBuilding>("B2",29,nullptr,280,"Sci1",0,150,t_for_b2);
  board.emplace_back(b2);
  indexsearch["B2"] = 29;
  auto gototims = make_shared <GoToTims> ("GoToTims",30);
  board.emplace_back(gototims);
  vector<int> t_for_eit_esc {26,130,390,900,1100,1275};
  auto eit = make_shared <AcademicBuilding>("EIT",31,nullptr,300,"Sic2",0,200,t_for_eit_esc);
  board.emplace_back(eit);
  indexsearch["EIT"] = 31;
  auto esc = make_shared <AcademicBuilding>("ESC",32,nullptr,300,"Sic2",0,200,t_for_eit_esc);
  board.emplace_back(esc);
  indexsearch["ESC"] = 32;
  auto slc3 = make_shared<SLC> ("SLC",33);
  board.emplace_back(slc3);
  vector<int> t_for_c2{28,150,450,1000,1200,1400};
  auto c2 = make_shared<AcademicBuilding>("C2",34,nullptr,320,"Sci2",200,0,t_for_c2);
  board.emplace_back(c2);
  indexsearch["C2"] = 34;
  auto rev = make_shared<Residence>("REV",35,nullptr,200);
  board.emplace_back(rev);
  indexsearch["REV"] = 35;
  auto needleshall3 = make_shared<NeedlesHall>("NeddlesHall",36);
  board.emplace_back(needleshall3);
  vector<int> t_for_mc{35,175,500,1100,1300,1500};
  auto mc = make_shared<AcademicBuilding>("MC",37,nullptr,350,"Math",0,200,t_for_mc);
  board.emplace_back(mc);
  indexsearch["MC"] = 37;
  auto coopfee = make_shared<CoopFee> ("CoopFee",38);
  board.emplace_back(coopfee);
  vector <int> t_for_dc{50,200,600,1400,1700,2000};
  auto dc = make_shared <AcademicBuilding>("DC",39,nullptr,400,"Math",0,200,t_for_dc);
  board.emplace_back(dc);
  indexsearch["DC"] = 39;
  
  //construct squres
  // 0->OASP， 10->DC Tims Line

  srand (time(NULL));
}

void GameBoard::loadfile(std::string loadfile){
  std::ifstream infile{loadfile};
  if(!infile.is_open()){
    std::cerr << "file missing!" << std::endl;
    return;
  }
  std::string line;
  std::string Pname;
  char Pchar; // if starts with P, it is a player
  int Pcups;
  int Pcash;
  int Plocation;
  int PturnsAtTims = 0;
  bool Pin_jail = 0;
  bool curr_set = false;
  std::string Bname;// if starts with B, it is a building
  std::string Bowner;
  int improvements;
  getline(infile,line);
  int numPlayer = std::stoi(line);
  while(getline(infile,line)){
    std::istringstream iss{line};
    if(numPlayer > 0){
      iss >> Pname;
      iss >> Pchar;
      iss >> Pcups;
      if(Pcups != 0){
        updateCups(Pcups);
      }
      iss >> Pcash;
      iss >> Plocation;
      if(Plocation == 10){
        iss >> Pin_jail;
        if(Pin_jail == true){
          iss >> PturnsAtTims;
        }
      }
      auto player = std::make_shared<Player>(Pname, Pchar, Pcups, Pcash, Plocation,PturnsAtTims,Pin_jail);
      players.emplace_back(player); 
      if(curr_set == false){
        currentPlayer = player;
        curr_set = true;
      }
      playersearch.emplace(Pname, player);
      numPlayer -= 1;
    }
    else {
      iss >> Bname;
      iss >> Bowner;
      iss >> improvements;
      auto temp = indexsearch.find(Bname);
      int buildingindex = temp->second;
      auto building = board.at(buildingindex);
      //casting???
      building->setImprovement(improvements);
      auto ptemp = playersearch.find(Bowner);
      auto playerptr = ptemp->second;
      building->setOwner(playerptr);
      if(playerptr != nullptr){
        playerptr->addProperty(buildingindex);
      }
    }
  }
}

std::vector<std::shared_ptr<Player>> GameBoard::getPlayers(){
  return players;
}


void GameBoard::savefile(std::string out){
  std::ofstream outfile{out};
  int numPlayer = players.size();
  outfile << numPlayer << std::endl;
  for(auto n : players){
    outfile << n->SavePlayerStatus() << std::endl;
  }
  for(auto n : board){
    auto k = std::dynamic_pointer_cast<Property>(n);
    if(k){
      
      outfile << n->SaveSquareStatus() << std::endl;
    }
  }
}


std::vector<std::shared_ptr<Square>> GameBoard::getBoard(){
  return board;
}

std::shared_ptr<Player> GameBoard::getCurrPlayer(){
  return currentPlayer;
}

std::shared_ptr<Player> GameBoard::GoToNextPlayer(){
  std::vector<std::shared_ptr<Player>>::iterator it = std::find(players.begin(), players.end(), currentPlayer);
  int index = std::distance(players.begin(), it);
  int size = players.size();
  if(index  == size - 1){
    currentPlayer = players.at(0);
  } else {
    currentPlayer = players.at(index + 1);
  }
  return currentPlayer;
}

bool GameBoard::TestingModeOn(){
  return TestingMode;
}

void GameBoard::setTestingMode(){
  TestingMode = true;
}

int GameBoard::RollDice(){
  int dice = rand() % 6 + 1;
  return dice;
}

int GameBoard::setDice1(int n){
  this->Dice1 = n;
  std::cout << "Dice1: " << this->Dice1 << std::endl;
  return this->Dice1;
}

int GameBoard::setDice2(int n){
  this->Dice2 = n;
  std::cout << "Dice2: " << this->Dice2 << std::endl;
  return this->Dice2;
}

int GameBoard::getDice1(){
  return this->Dice1;
}

int GameBoard::getDice2(){
   return this->Dice2;
}

void GameBoard::updateCups(int cup){
  this->totalcups += cup;
}

int GameBoard::getCups(){
  return totalcups;
}

bool GameBoard::rimCupRandom(){
  int random = rand() % 100 + 1;
  if(random == 1){
    return true;
  }
  return false;
}

void GameBoard::initial(){
  std::cout << "Please enter the total number of players in the game" << std::endl;
  std::cout << "Please note that this game may not support more than 7 players due to the size of the gameboard";
  std::cout << std::endl;
  int total;
  cin >> total;
  int count = 0;
  std::cout <<"Please add your player to the game in the format [player name] [char]" << std::endl;
  std::cout << "\t\tExample: Alice A" << std::endl;
  string cmd;
  string name;
  char c;
  while(cin >> cmd) {
      name = cmd;
      cin >> c;
      auto player = make_shared<Player>(name, c, 0, 1500, 0, 0, 0);
      players.emplace_back(player);
      count += 1;
      if (count == total){
        break;
      }
  }
  std::cout << "Congratulations! You may now start the game!" << std::endl;
  return;
}


void GameBoard::SellImprovement(std::string property){
std::map<std::string,int>::iterator it = indexsearch.find(property);
  if(it == indexsearch.end()){
    std::cout << "Sorry, this is not a valid property!" << std::endl;
    return;
  } else {
    int index = it->second;
    std::cout << "map index: " << index << std::endl;
    bool found = false;
    for( auto n : currentPlayer->getProperty()){
      if (n == index){
        found = true;
        break;
      }
    }
    if(found){
      auto location = board[index];
      auto building = std::dynamic_pointer_cast<AcademicBuilding>(location);
      if(building){
        building->sellImprovement(currentPlayer);
      } else {
        std::cout << "Sorry, this is not an academic building." << std::endl;
      }
    } else {
      std::cout << "Sorry, you do not own this property." << std::endl;
    }

  }

}


void GameBoard::makeImprovement(string property){
  std::map<std::string,int>::iterator it = indexsearch.find(property);
  if(it == indexsearch.end()){
    std::cout << "Sorry, this is not a valid property!" << std::endl;
    return;
  } else {
    int index = it->second;
    std::cout << "map index: " << index << std::endl;
    bool found = false;
    for( auto n : currentPlayer->getProperty()){
      if (n == index){
        found = true;
        break;
      }
    }
    if(found){
      auto location = board[index];
      auto building = std::dynamic_pointer_cast<AcademicBuilding>(location);
      if(building){
        string wanted_monopoly = building->getMonopoly();
        int MonopolyTotal = monopolycollection.find(wanted_monopoly)->second;
        int ownedmono_sofar = 0;
        for(auto n : currentPlayer->getProperty()){
          auto b = board[n];
          auto pro = dynamic_pointer_cast<Property>(b);
          auto AB = dynamic_pointer_cast<AcademicBuilding>(pro);
          if(AB){
            if(AB->getMonopoly() == wanted_monopoly){
              ownedmono_sofar += 1;
              }
          }
        } if (ownedmono_sofar == MonopolyTotal){
          building->buyImprovement(currentPlayer);
        } else {
          std::cout << "Sorry, you need to own all the properties in this monopoly before you make an improvement." << std::endl;
        }
      } else {
        std::cout << "Sorry, this is not an academic building." << std::endl;
      }
    } else {
      std::cout << "Sorry, you do not own this property." << std::endl;
    }

  }

}
void GameBoard::MoveOnNewLocation(){
  auto location = board[currentPlayer->getLocation()];
  string Bname = location->getName();
  auto p = dynamic_pointer_cast<Property>(location);
  
  shared_ptr <Player> owner;
  int MonopolyTotal;
  
  if(p) {
    owner = p->getOwner();
    if(owner && owner != currentPlayer){
      auto ad = dynamic_pointer_cast<AcademicBuilding>(p);
      if(ad) {
        string wanted_monopoly = ad->getMonopoly();
        MonopolyTotal = monopolycollection.find(wanted_monopoly)->second;
        if(ad->getCurrentLevel() > 0){
          bool paied = ad->payRent(owner, currentPlayer, false);
          if(paied == false){
            bool declared_bankrupt = bankrupt(owner, false);
            if(declared_bankrupt == false){
              paied = ad->payRent(owner, currentPlayer, false);
              if(paied == false){
                bankrupt(owner, true);
              }
            }
          }
        } else {
          int ownedmono_sofar = 0;
          for(auto n : owner->getProperty()){
            auto building = board[n];
            auto pro = dynamic_pointer_cast<Property>(building);
            auto AB = dynamic_pointer_cast<AcademicBuilding>(pro);
            if(AB){
              if(AB->getMonopoly() == wanted_monopoly){
                ownedmono_sofar += 1;
              }
            }
          }
          if(ownedmono_sofar == MonopolyTotal){
            bool paied = ad->payRent(owner, currentPlayer, true);
            if(paied == false){
              bool declared_bankrupt = bankrupt(owner, false);
              if(declared_bankrupt == false){
                paied = ad->payRent(owner, currentPlayer, false);
                if(paied == false){
                  bankrupt(owner, true);
                }
              }
            }
          } else {
            bool paied = ad->payRent(owner, currentPlayer, false);
            if(paied == false){
              bool declared_bankrupt = bankrupt(owner, false);
              if(declared_bankrupt == false){
                paied = ad->payRent(owner, currentPlayer, false);
                if(paied == false){
                  bankrupt(owner, true);
                }
              }
            }            
          }
        }
    } else {
      int money = location->Event(owner,currentPlayer,getDice1() + getDice2());
      int currentMoney = currentPlayer->getCash();
      bool mort = true;
      if(currentMoney + money >= 0) {
        std::cout << "Paying Rent to " << owner->getName() << " for " << 0 - money << " dollars." << endl;
        currentPlayer->setCash(money);
      }
      if(currentMoney + money < 0) {
        mort = bankrupt(owner,false);
      }
      if(mort == false) {
        bankrupt(owner,true);
      }
    }
    }
    // buy Property
    if (!owner) {
      int money = currentPlayer->getCash();
      int cost = p->getPurchaseCost();
      if(money >= cost ){
        cout << "Do you want to buy this land?\n" <<endl;
        cout << "Press Y if you do, press N if you don't." << endl;
        string cmd;
        cin >> cmd;
        if(cmd == "Y"){
          p->purchaseProperty(currentPlayer);
          int index = indexsearch.find(Bname)->second;
          currentPlayer->addProperty(index);
        } else if (cmd == "N"){
          Auction a{players, p, currentPlayer};
          a.startAuction();
        }
      } else {
        Auction a{players, p, currentPlayer};
        a.startAuction();
      } 
      
      }
  } else {
    int money = 0;
    auto np = dynamic_pointer_cast<NonProperty>(location);
    auto s = dynamic_pointer_cast<SLC>(np);
    auto n = dynamic_pointer_cast<NeedlesHall>(np);
    auto d = dynamic_pointer_cast<DCTimsLine>(np);
    auto g = dynamic_pointer_cast<GoToTims>(np);
    auto o = dynamic_pointer_cast<GooseNesting>(np);
    auto t = dynamic_pointer_cast<Tuition>(np);
    auto c = dynamic_pointer_cast<CoopFee>(np);
    if(s){
      if(totalcups == 4){
        money = s->Event(currentPlayer);
      } else {
        bool rimcup = this->rimCupRandom();
        if(rimcup == true){
          totalcups += 1;
          currentPlayer->setOwnedCups(1);
          std::cout << "Congratulations! You won a Rim Cup!" << std::endl;
        } else {
          money = s->Event(currentPlayer);
        }
      }
    } else if (n) {
      if(totalcups == 4){
        n->Event(currentPlayer);
      } else {
        bool rimcup = this->rimCupRandom();
        if(rimcup == true){
          totalcups += 1;
          currentPlayer->setOwnedCups(1);
          std::cout << "Congratulations! You won a Rim Cup!" << std::endl;
        } else {
          money = n->Event(currentPlayer);
        }
      }
    } else if (d) {
      // lands on DC Tims Line, nothing happens

      // otherwise
    
      if(currentPlayer->isin_jail() && currentPlayer->getturnsToTimsLine() != 0) {
        string cmd;
        cout << "You've been in DC Tims Line for " 
        << currentPlayer->getturnsToTimsLine() << " time/times." << endl;
        cout << "You have " << currentPlayer->getOwnedCups() << " Rim cup/cups." << endl;
        cout << "You have cash $" << currentPlayer->getCash() << " ." << endl;
        if(currentPlayer->getOwnedCups() == 0) {
          cout << "Press roll to roll,Press pay to pay $50." << endl;
          cin >> cmd;
          if(cmd == "roll") {
            rollOnce();
            rollTimes --;
            if(currentPlayer->getturnsToTimsLine() == 2) {
              money = d->rollthird(currentPlayer,Dice1,Dice2,false);
            }
            else {
              d->roll(currentPlayer,Dice1,Dice2);
            }
          }
          if (cmd == "pay") {
            money = d->pay50(currentPlayer);
          }
        }
        else {
          cout << "Press roll to roll,Press pay to pay $50, or press cup to use Rim cups." << endl;
          cin >> cmd;
          if(cmd == "roll") {
            rollOnce();
            rollTimes --;
            if(currentPlayer->getturnsToTimsLine() == 2) {
              money = d->rollthird(currentPlayer,Dice1,Dice2,true);
            }
            else {
              d->roll(currentPlayer,Dice1,Dice2);
            }
          }
          if (cmd == "pay") {
            money = d->pay50(currentPlayer);
          }
          if (cmd == "cup") {
            d->useCups(currentPlayer);
          }
        }
      }
    } else if (g) {
      money = g->Event(currentPlayer);
    } else if (o) {
      money = o->Event(currentPlayer);
    } else if (t) {
      int totalWorth = 0;
      totalWorth += currentPlayer->getCash();
      for(auto i:currentPlayer->getProperty()) {
        auto s = board[i];
        totalWorth += s->getPurchaseCost();
        auto ab = dynamic_pointer_cast<AcademicBuilding>(s);
        if(ab) {
          totalWorth += ab->getImprovementCost() * ab->getCurrentLevel();
        }
      }
      money = t->Event(currentPlayer,totalWorth);
    } else if (c) {
      money = c->Event(currentPlayer);
    }
    if(currentPlayer->getCash() + money < 0) {
      bankrupt(nullptr,false);
    }
    if(currentPlayer->getCash() + money < 0) {
      bankrupt(nullptr,true);
    }
    else if (money < 0) {
     currentPlayer->setCash(money);
    }
  }
}

void GameBoard::roll(){
  auto curr = getCurrPlayer();
  int steps;
  if(rollTimes == 1) {
    rollOnce();
    steps = Dice1 + Dice2;
    totalsteps += steps;
  }
  while(Dice1 == Dice2  && rollTimes<=3) {
    cout << "You rolled a double so you have to roll again." <<endl;
    if(TestingMode) {
      string r;
      cin >> r;
    }
    rollOnce();
    totalsteps += (getDice1() + getDice2());
  }
  if(Dice1 == Dice2 && rollTimes == 4) {
    curr->setin_jail(true);
    curr->setLocation(10);
  }
  if(Dice1 != Dice2 || rollTimes < 3){
    curr->updateLocation(totalsteps);
  }
  rollTimes = 1;
  totalsteps = 0;
  MoveOnNewLocation();
}

 void GameBoard::rollOnce(){
        int d1 = 0;
        int d2 = 0;
        int diceNum = 0;
        if(TestingMode){
          if(!(cin >> d1)){
            diceNum = RollDice();
            setDice1(diceNum);
            diceNum = RollDice();
            setDice2(diceNum);
            cin.clear();
          }else{
            setDice1(d1);
            cin >> d2;
            setDice2(d2);
          }
        } else {
          diceNum = RollDice();
          setDice1(diceNum);
          diceNum = RollDice();
          setDice2(diceNum);
        }
        rollTimes ++;
 }

void GameBoard::mortgage(string p) {
   auto index = indexsearch.find(p);
   if (index != indexsearch.end()) {
     auto s = board[index->second];
     std::string n = s->getName();
     auto p = dynamic_pointer_cast<Property>(s);
     currentPlayer->addMortgaged(index->second, p);
     } else {
       std::cout << "This is a not valid property." << std::endl;
     }
} 


 void GameBoard::unmortgage(string p) {
   auto find = indexsearch.find(p);
   if(find != indexsearch.end()) {
     auto s = board[find->second];
     std::string n = s->getName();
     auto p = dynamic_pointer_cast<Property>(s);
     bool unmortgaged = currentPlayer->removeMortgaged(find->second, p);
     if(unmortgaged) {
       p->setOwner(currentPlayer);
     }
   } else {
     std::cout << "This is a not valid property." << std::endl;
   }
 }



 void GameBoard::trade(std::string name, std::string give,std::string receive) {
   int money_give = 0;
   int money_receive = 0;
   bool give_int = false;
   bool receive_int = false;
   shared_ptr<Property> find_give = nullptr;
   shared_ptr<Property> find_receive = nullptr;
   auto it = playersearch.find(name);
   shared_ptr <Player> receiver;
  if (it != playersearch.end()) {
    receiver = it->second;
  }
  else {
    return;
  }
   stringstream converted_give(give);
   stringstream converted_receive(receive);
   if(converted_give >> money_give) {
     give_int = true;
   }
   if(converted_receive >> money_receive) {
     receive_int =true;
   }
   for(auto i: currentPlayer->getProperty()) {
     auto s = board[i];
       if(s->getName() == give) {
         find_give = dynamic_pointer_cast<Property>(s);
         break;
   }
   }
   for(auto i: receiver->getProperty()) {
     auto s = board[i];
       if(s->getName() == receive) {
         find_receive = dynamic_pointer_cast<Property>(s);
         break;     
   }
   }
   
   if ((currentPlayer->getName() == name)||(!give_int && !find_give) ||(!receive_int && !find_receive)||(give_int && receive_int)) {
     return;
   }
   else {
     cout << name << ", would you like to receive the trade from " << currentPlayer->getName() << "?" << endl;
     cout << "Press accept to accept the trade, otherwise press reject." << endl;
     string cmd;
     cin >> cmd;
     if(cmd == "accept") {
       if(give_int) {
         if(receive_int) {
         }
         else {
           int p = indexsearch.at(receive);
           currentPlayer->setCash(0 - money_give);
           find_receive->setOwner(currentPlayer);
           currentPlayer->addProperty(p);
           receiver->setCash(money_give);
           receiver->removeProperty(p);
         }
       }
       else { 
         if(receive_int) {
           int p = indexsearch.at(give);
           currentPlayer->setCash(money_receive);
           currentPlayer->removeProperty(p);
           find_give->setOwner(receiver);
           receiver->setCash(0 - money_receive);
           receiver->addProperty(p);
         }
         else {
           int g = indexsearch.at(give);
           int r = indexsearch.at(receive);
           currentPlayer->addProperty(r);
           currentPlayer->removeProperty(g);
           find_give->setOwner(receiver);
           receiver->addProperty(g);
           receiver->removeProperty(r);
           find_receive->setOwner(currentPlayer);
         }
       }
     }
   }  
 }
 
bool GameBoard::bankrupt(std::shared_ptr<Player> owner, bool force_bankrupt) {
  if(force_bankrupt == false){
    std::cout << "You are unable to pay the fee since you do not have enough money, " << std::endl;
    std::cout << "You can choose to either declare bankruptcy or sell all your improvements and mortgage ";
    std::cout << "all your properties to raise money. Press \"bankrupt\" to declare bankruptcy or \"raise\" to raise money.";
    std::cout << std::endl;
  } else{
    std::cout << "You did not collect enough money, and you are forced to leave the game, press any letter to let this happen.";
    std::cout << std::endl;
  }
  std::string cmd;
  cin >> cmd;
  if(cmd == "bankrupt" || force_bankrupt == true){
    if(owner == nullptr){
      //then recipient is BANK, 
      // cash:
      // owned properties:
      std::cout << "Since you declared bankruptcy and the owner is BANK, all your properties go to the bank." << std::endl;
      for(auto i: currentPlayer->getProperty()) {
        board[i]->setOwner(nullptr);
        auto p = std::dynamic_pointer_cast<Property>(board[i]);
        Auction a{players, p, currentPlayer};
        a.startAuction();
      }
      totalcups -= currentPlayer->getOwnedCups();

      // owned mortgaged:
    } else {
      // cash:
      int money = currentPlayer->getCash();
      owner->setCash(money);
      //owned properties:
      for(auto i: currentPlayer->getProperty()) {
        board[i]->setOwner(owner);
        owner->addProperty(i);

      }
      // owned mortgaged:
      for(auto i: currentPlayer->getMortgaged()) {
        auto p = dynamic_pointer_cast<Property>(board[i]);
        owner->addMortgaged(i,p);
      }
      owner->setOwnedCups(currentPlayer->getOwnedCups());
      // then recipient is a player, give all assets to that player.
    }
    string pname = currentPlayer->getName();
    std::shared_ptr<Player> a = currentPlayer;
    GoToNextPlayer();
    auto it = find(players.begin(),players.end(),a);
    players.erase(it);
    cout << "Player " << pname << " declared bankruptcy and left the game." << std::endl;
    if(players.size() == 1) {
    cout << "Congratulations! " << currentPlayer->getName() << "! We have the final winner!" << endl;
    cout << "You can now press 'q' to end this game." << endl;
  }

    return true;
  } else if (cmd == "raise"){
    for(auto n : currentPlayer->getProperty()){
      auto location = board[n];
      auto building = std::dynamic_pointer_cast<AcademicBuilding>(location);
      if(building){
        int level = building->getCurrentLevel();
        while(level > 0){
          building->sellImprovement(currentPlayer);
        }
      }
    }
    for(auto n : currentPlayer->getProperty()){
      auto location = board[n];
      auto building = std::dynamic_pointer_cast<Property>(location);
      std::string Bname = location->getName();
      auto temp = indexsearch.find(Bname);
      int buildingindex = temp->second;
      currentPlayer->addMortgaged(buildingindex,building);
    }
  }
  return false;
}
