module;

#include <SFML/Graphics.hpp>

export module LogicGame;

import std;
import Assets;

export enum class Moves {
    None = 0,
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

export enum class GameState {
    Start,
    Playing,
    Result
};

export Moves processRound(int& result, const Moves & human, std::mt19937& gen) {
    std::uniform_int_distribution<> dis(1, 3);
    Moves pc = static_cast<Moves>(dis(gen));

    if (human == pc) {
        result = 0;
    }

    else if ((human == Moves::Rock && pc == Moves::Scissors) ||
        (human == Moves::Paper && pc == Moves::Rock) ||
        (human == Moves::Scissors && pc == Moves::Paper)) {
        result = 1;
    }

    else {
        result = 2;
    }

    return pc;
}

export void HandleClick(GameState & state, const auto & MouseClick, Moves& human_move, Moves &pc_move, std::mt19937& generator, int& result, const std::unordered_map<std::string, sf::Sprite> &player) {
    {
        if (state == GameState::Start) {
            state = GameState::Playing;
            std::println("LBM_Playing");
        }

        else if (state == GameState::Playing) {
            sf::Vector2i clickPos = MouseClick->position;

            if (player.at("rock").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos))) {
                std::println("Clicked on ROCK!");
                human_move = Moves::Rock;
            }

            else if (player.at("paper").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos))) {
                std::println("Clicked on PAPER!");
                human_move = Moves::Paper;
            }

            else if (player.at("scissors").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos))) {
                std::println("Clicked on SCISSORS!");
                human_move = Moves::Scissors;
            }

            if (human_move != Moves::None) {

                pc_move = processRound(result, human_move, generator);

                state = GameState::Result;
            }
        }

        else {
            state = GameState::Playing;
            std::println("LBM_Result");
        }
    }
}