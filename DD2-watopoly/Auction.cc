#include "Auction.h"
#include "GameBoard.h"
#include "Player.h"
#include "Property.h"

#include <string>
#include <vector>
#include <memory>
// int bidAmount;
// std::shared_ptr<Player> currentHighestBidder;
// std::shared_ptr<Property> building;
// std::vector<std::shared_ptr<Player>> participants;

Auction::Auction(std::vector<std::shared_ptr<Player>> players, std::shared_ptr<Property> building, std::shared_ptr<Player> currPlayer): building{building} {
  //set starting bid amount
  bidAmount = building->getPurchaseCost();
  //setting the valid participants
  for (unsigned int i = 0;i<players.size();i++) {
    std::shared_ptr<Player> p = players.at(i);
    if (p->getCash()>=bidAmount && p != currPlayer) {
      participants.emplace_back(p);
    }
    
  }
  
}

void Auction::startAuction(){
  unsigned int i = 0;
  while (participants.size()>1) {
    if (i==participants.size()) {
      i = 0;
    }
    std::shared_ptr<Player> bidder = participants.at(i);
    if (bidder->getCash()<bidAmount) {
      std::cout << "Player " <<participants.at(i)->getName()<<" has withdrawn due to lack of funds."<<std::endl;
      participants.erase(participants.begin()+i);
      continue;
    }
    std::cout << "Player: "<<bidder->getName()<<". Bidding price is: "<<bidAmount<<std::endl<<"Enter a number to raise the bid, or withdraw." <<std::endl;
    std::string choice;
    std::cin>>choice;
    if (choice=="withdraw") {
      std::cout << "Player " <<participants.at(i)->getName()<<" has withdrawn."<<std::endl;
      participants.erase(participants.begin()+i);
    } else {
      int bid = 0;
      try {
        bid = std::stoi(choice);
        if (bid>bidder->getCash()) {
          std::cout << "You cannot bid more than your total amount of money"<<std::endl;
        } else if (bid<=bidAmount) {
          std::cout << "You must bid more than the bidding price"<<std::endl;
        } else {
          bidAmount = bid;
          currentHighestBidder = bidder;
          i++;
          if (i==participants.size()) {
            i = 0;
          }
        }
      } catch (...) {
        std::cout << "Sorry you did not enter a valid number"<<std::endl;
      }
    }
  }
  if (participants.empty()) {
     std::cout << "No one could afford this property"<<std::endl;
     return;
   } else if (participants.size()==1&&bidAmount==building->getPurchaseCost()) {
     std::cout << "Player: "<<participants.at(0)->getName()<<". Bidding price is: "<<bidAmount<<std::endl<<"Enter a number to raise the bid, or withdraw." <<std::endl;
      std::string choice;
      std::cin>>choice;
      if (choice=="withdraw") {
        std::cout << "Player " <<participants.at(0)->getName()<<" has withdrawn."<<std::endl;
        participants.erase(participants.begin()+0);
        std::cout << "All players have withdrawn."<<std::endl;
      } else {
        int bid = 0;
        try {
          bid = std::stoi(choice);
          if (bid>participants.at(0)->getCash()) {
            std::cout << "You cannot bid more than your total amount of money"<<std::endl;
          } else if (bid<bidAmount) {
            std::cout << "You must pay at least the minimum price of the building"<<std::endl;
          } else {
            bidAmount = bid;
            currentHighestBidder = participants.at(0);
          }
        } catch (...) {
          std::cout << "Sorry you did not enter a valid number"<<std::endl;
        }
        std::cout << "And the property goes to: "<<currentHighestBidder->getName()<<std::endl;
        currentHighestBidder->setCash(-bidAmount);
        building->setOwner(currentHighestBidder);
        currentHighestBidder->addProperty(building->getIndex());
        
      }
   } else {
    std::cout << "And the property goes to: "<<currentHighestBidder->getName()<<std::endl;
    currentHighestBidder->setCash(-bidAmount);
    building->setOwner(currentHighestBidder);
    currentHighestBidder->addProperty(building->getIndex());
  }
  
}
