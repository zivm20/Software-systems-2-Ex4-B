#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#pragma once
namespace coup{
    
    class Game{
        private:
            std::vector<std::string> _players;
            std::map<std::string,bool> _isAlive;
            std::map<std::string,int> _coins;
            int coin_buffer;
            size_t curr_turn;
        
        public:
            //actions
            Game();
            std::vector<std::string> players();
            std::string winner();

            //helpers
            void addPlayer(const std::string& name);
            void nextTurn();
            
            
            //getters and setters
            inline bool isAlive(const std::string& name) const{
                return _isAlive.at(name);
            }
            inline void setAlive(const std::string& name,const bool& flag){
                _isAlive[name] = flag;
            }
            inline std::string turn() const{
                return _players[curr_turn];
            }

            inline int coins(const std::string& name) const{
                return _coins.at(name);
            }

            void addCoins(const std::string& name,const int& amount);
            
            
    };
}

