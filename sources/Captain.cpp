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
            string target = player.target().substr(1,player.target().size()-1);
            int amount = min(stoi(player.target().substr(0,1)),player.coins());
            _game->addCoins(target,amount);
            player.addCoins(-amount);
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
    int _amount = min(2,player.coins());
    player.addCoins(-_amount);
    addCoins(_amount);
    end_turn("steal",to_string(_amount)+player.name());
}


