#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

using namespace coup;
using namespace std;

Game::Game():playerCount(0), curr_turn(0),coin_buffer(0),started(false){
}
vector<string> Game::players(){
    vector<string> names;
    for(size_t i = 0; i < _players.size(); i++){
        if(isAlive(_players[i])){
            names.push_back(_players[i]);
        }
    }
    return names;
}
void Game::addPlayer(const string& name){
    if(started){
        throw runtime_error("can't add players mid game!");
    }
    if(playerCount + 1> MAX_PLAYERS){
        throw runtime_error("Too many players!");
    }
    _players.push_back(name);
    _isAlive.insert(pair<string,bool>(name,true));
    _coins.insert(pair<string,int>(name,0));
    playerCount++;
    
}

string Game::winner(){
    if(!started){
        throw runtime_error("Game hasn't started yet!");
    }
    vector<string> active_players = players();
    if(active_players.size() != 1){
        throw runtime_error("Game hasn't ended yet!");
    }
    return active_players[0];
}

void Game::nextTurn(){
    _coins[_players[curr_turn]] += coin_buffer; 
    coin_buffer = 0;
    do{
        curr_turn = (curr_turn+1)%_players.size();
    }
    while(!isAlive(_players[curr_turn]));
    
}
//we need to track the amount of coins we had at the start of the turn and correctly add
//it at the end of the turn
int Game::coins(const std::string& name) const{
    if(name == turn()){
        return coin_buffer+_coins.at(name);
    }
    return _coins.at(name);
}
void Game::addCoins(const string& name,const int& amount){
    if(name == turn()){
        coin_buffer+=amount;
    }
    else{
        _coins[name] += amount;
    }
    
}
