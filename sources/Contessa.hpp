
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#pragma once
namespace coup{
    class Contessa:public Player{
        public:
            Contessa(Game& game, std::string name);
            void block(Player& player);
            
    };
}