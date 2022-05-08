#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Captain.hpp"

using namespace coup;
using namespace std;

Captain::Captain(Game& game, const string& name):Player(game,name){
    _role = "Captain";
}

void Captain::block(Player& player){
    if(player.role() == "Captain"){
        if(player.lastMove() == "steal"){
            _game.addCoins(player.target(),2);
            player.addCoins(-2);
            player.setTarget("");
            player.setLastMove("");
            return;
        }
    }
    throw runtime_error("Invalid Block!");
}
void Captain::steal(Player& player){
    valid_move("steal",0);
    if(!player.isAlive()){
        throw runtime_error("Cannot steal from a dead player");
    }
    if(player.coins()<2){
        throw runtime_error(player.name() + " doesn't have enough coins to steal!");
    }
    player.addCoins(-2);
    addCoins(2);
    end_turn("steal",player.name());
}


