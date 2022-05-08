
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#pragma once
namespace coup{
    class Duke:public Player{
        public:
            Duke(Game& game, std::string name);
            void block(Player& player);
            void tax();
    };
}