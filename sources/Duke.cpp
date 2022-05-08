#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"

using namespace coup;
using namespace std;

Duke::Duke(Game& game, const string& name):Player(game,name){
    _role = "Duke";
}

void Duke::block(Player& player){
    
    if(player.lastMove() == "foreign_aid"){
        player.addCoins(-2);
        player.setTarget("");
        return;
    }

    throw runtime_error("Invalid Block!");
}

void Duke::tax(){
    valid_move("tax",0);
    addCoins(3);
    end_turn("transfer","");
}