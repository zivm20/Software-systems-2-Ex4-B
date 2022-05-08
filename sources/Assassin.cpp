#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Assassin.hpp"

using namespace coup;
using namespace std;

Assassin::Assassin(Game& game, string name):Player(game,name){
    _role = "Assassin";
}
void Assassin::coup(Player& player){    
    valid_move("coup",3);
    if(!player.isAlive()){
        throw runtime_error("Player "+player.name()+" is already dead");
    }
    player.setAlive(false);
    addCoins(-3);
    end_turn("coup",player.name());
}