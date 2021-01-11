#ifndef ___AUCTION___
#define ___AUCTION___
#include <memory>
#include <vector>
#include <iostream>

class GameBoard;
class Player;
class Property;
class Auction{
    friend class ChangeConcreteCreator;
    int bidAmount;
    std::shared_ptr<Player> currentHighestBidder;
    std::shared_ptr<Property> building;
    std::vector<std::shared_ptr<Player>> participants;

    public:
    Auction(std::vector<std::shared_ptr<Player>> players, std::shared_ptr<Property> building, std::shared_ptr<Player> currPlayer);
    void startAuction();

};

#endif
