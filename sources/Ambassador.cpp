#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Ambassador.hpp"

using namespace coup;
using namespace std;

Ambassador::Ambassador(Game& game, const string& name):Player(game,name){
    _role = "Ambassador";
}
void Ambassador::block(Player& player){
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

void Ambassador::transfer(Player& player1, Player& player2){
    valid_move("transfer",0);
    if(!player1.isAlive() || !player2.isAlive()){
        throw runtime_error("Cannot transfer to or from a dead player");
    }
    if(player1.coins()<1){
        throw runtime_error(player1.name() + " doesn't have enough coins to transfer!");
    }
    
    player1.addCoins(-1);
    player2.addCoins(1);
    end_turn("transfer","");
}



