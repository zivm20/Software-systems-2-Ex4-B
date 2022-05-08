
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#pragma once
namespace coup{
    class Captain:public Player{
        public:
            Captain(Game& game, const std::string& name);
            void block(Player& player);
            void steal(Player& player);
    };
}