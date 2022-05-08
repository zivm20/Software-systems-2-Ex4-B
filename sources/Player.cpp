#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace coup;
using namespace std;

Player::Player(Game& game, const string& name): _game(game), _name(name),coup_price(DEFAULT_COUP_PRICE),_role(""),_lastMove(""),_target(""){
    _game.addPlayer(_name);
}
void Player::valid_move(const string& move, const int& price){
    if(coins() >= MAX_COINS_ALLOWED && move != "coup"){
        throw runtime_error("Must use coup with 10 or more coins");
    }
    if(coins() < price){
        throw runtime_error("Not enough coins to preform "+move);
    }
    if(_game.turn() != name()){
        throw runtime_error("It's not "+name()+"'s turn");
    }
    if(!isAlive()){
        throw runtime_error("Player "+name()+" is dead");
    }
}
void Player::income(){
    valid_move("income",0);
    addCoins(1);
    end_turn("income","");
}
void Player::foreign_aid(){
    valid_move("foreign_aid",0);
    addCoins(2);
    end_turn("foreign_aid","");
}
void Player::coup(Player& player){
    valid_move("coup",coup_price);
    if(!player.isAlive()){
        throw runtime_error("Player "+player.name()+" is already dead");
    }
    player.setAlive(false);
    addCoins(-coup_price);
    end_turn("coup",player.name());
}
void Player::block(Player& player){
    throw runtime_error("Player "+name()+" cannot block "+player.name());
}
void Player::end_turn(const string& move, const string& target){
    _target = target;
    _lastMove = move;
    _game.nextTurn();
}
void Player::addCoins(const int& n){
    _game.addCoins(name(),n);
}
