
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#pragma once
namespace coup{
    class Ambassador:public Player{
        public:
            Ambassador(Game& game, const std::string& name);
            void block(Player& player);
            void transfer(Player& player1, Player& player2);
    };
}