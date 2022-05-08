#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Contessa.hpp"

using namespace coup;
using namespace std;

Contessa::Contessa(Game& game, const string& name):Player(game,name){
    _role = "Contessa";
}

void Contessa::block(Player& player){
    if(player.role() == "Assassin"){
        if(player.lastMove() == "coup"){
            _game->setAlive(player.target(),true);
            player.setLastMove("");
            player.setTarget("");
        }
    }
}