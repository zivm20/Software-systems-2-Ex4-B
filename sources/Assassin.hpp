
#include <string>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#pragma once
namespace coup{
    class Assassin:public Player{
        public:
            Assassin(Game& game, const std::string& name);
    };
}