
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
            Game* _game;

        public:
            Player(Game& game, const std::string& name);
            
            //playable moves
            void income();
            void foreign_aid();
            virtual void coup(Player& player);
            
            //playable moves for certain roles
            virtual void block(Player& player);
            virtual void steal(Player& player);
            virtual void tax();
            virtual void transfer(Player& player1, Player& player2); 

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
            bool isAlive() const;
            void setAlive(const bool& flag);
            int coins() const;
            void addCoins(const int& n);
    };
}