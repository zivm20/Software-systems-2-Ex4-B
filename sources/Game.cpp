#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

using namespace coup;
using namespace std;

Game::Game():_players(),_coins(),_isAlive(), curr_turn(0),coin_buffer(0){
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
    _players.push_back(name);
    _isAlive.insert(pair<string,bool>(name,true));
    _coins.insert(pair<string,int>(name,0));
}
string Game::turn() const{
    return _players[curr_turn];
}
string Game::Winner(){
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


void Game::addCoins(const string& name,const int& amount){
    if(name == turn()){
        coin_buffer+=amount;
    }
    else{
        _coins[name] += amount;
    }
    
}
