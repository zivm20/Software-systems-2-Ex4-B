
#include <string>
#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#pragma once
namespace coup{
    const int DEFAULT_COUP_PRICE = 7;
    const int ASSASSIN_COUP_PRICE = 3;
    const int MAX_COINS_ALLOWED = 10;
    class Player{
        
        protected:
            std::string _role;
            std::string _name;
            std::string _lastMove;
            std::string _target;
            int coup_price;
            Game* _game;

        public:
            Player(Game& game, const std::string& name);
            
            //playable moves
            void income();
            void foreign_aid();
            void coup(Player& player);
            virtual void block(Player& player);

            //helpers
            void valid_move(const std::string& move, const int& price);
            void end_turn(const std::string& move, const std::string& target);
            
            //getters and setters
            inline std::string role() const{ 
                return _role;
            }
            inline std::string name() const{
                return _name;
            }
            inline std::string lastMove() const{
                return _lastMove;
            }
            inline void setLastMove(const std::string& s){
                _lastMove = s;
            }
            inline Game game() const{
                return (*_game);
            }
            inline std::string target() const{
                return _target;
            }
            inline void setTarget(const std::string& s){
                _target = s;
            }
            inline bool isAlive() const{
                return _game->isAlive(_name);
            }
            inline void setAlive(const bool& flag){
                _game->setAlive(_name,flag);
            }
            inline int coins() const{
                return _game->coins(_name);
            }
            void addCoins(const int& n);
    };
}