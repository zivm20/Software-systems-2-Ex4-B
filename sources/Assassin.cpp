#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Assassin.hpp"

using namespace coup;
using namespace std;


Assassin::Assassin(Game& game, const string& name):Player(game,name){
    _role = "Assassin";
}
void Assassin::coup(Player& player){
    int cost = ASSASSIN_COUP_PRICE;
    string move = "coup3";
    if(coins() >= DEFAULT_COUP_PRICE){
        cost = DEFAULT_COUP_PRICE;
        move = "coup";
    }
    valid_move("coup",cost);
    if(!player.isAlive()){
        throw runtime_error("Player "+player.name()+" is already dead");
    }
    player.setAlive(false);
    addCoins(-cost);
    end_turn(move,player.name());

}