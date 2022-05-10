#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace coup;
using namespace std;

Player::Player(Game& game, const string& name): _game(&game), _name(name),_role(""),_lastMove(""),_target(""){
    _game->addPlayer(_name);
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
    valid_move("coup",DEFAULT_COUP_PRICE);
    if(!player.isAlive()){
        throw runtime_error("Player "+player.name()+" is already dead");
    }
    player.setAlive(false);
    addCoins(-DEFAULT_COUP_PRICE);
    end_turn("coup",player.name());
}
void Player::block(Player& player){
    throw runtime_error("Player "+name()+" cannot block "+player.name());
}
void Player::steal(Player& player){
    throw runtime_error(_role + " cannot use steal");
}
void Player::tax(){
    throw runtime_error(_role + " cannot use tax");
}
void Player::transfer(Player& player1, Player& player2){
    throw runtime_error(_role + " cannot use transfer");
}
//hadle all the events that should happen at the end of each turn
void Player::end_turn(const string& move, const string& target){
    _target = target;
    _lastMove = move;
    _game->nextTurn();
}
//check that the current palyer can execute the move
void Player::valid_move(const string& move, const int& price){
    if(_game->getPlayerCount() < 2){
        throw runtime_error("Not enough players");
    }
    if(coins() >= MAX_COINS_ALLOWED && move != "coup"){
        throw runtime_error("Must use coup with 10 or more coins");
    }
    if(coins() < price){
        throw runtime_error("Not enough coins to preform "+move);
    }
    if(_game->turn() != name()){
        throw runtime_error("It's not "+name()+"'s turn");
    }
    if(!isAlive()){
        throw runtime_error("Player "+name()+" is dead");
    }
    _game->startGame();
}

void Player::addCoins(const int& n){
    _game->addCoins(name(),n);
}

