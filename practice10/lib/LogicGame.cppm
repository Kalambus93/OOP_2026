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

export Moves processRound(int &result, const Moves &human, std::mt19937 &gen)
{
    std::uniform_int_distribution<> dis(1, 3);
    Moves pc = static_cast<Moves>(dis(gen));

    if (human == pc)
    {
        result = 0;
    }
    else if ((human == Moves::Rock && pc == Moves::Scissors) ||
             (human == Moves::Paper && pc == Moves::Rock) ||
             (human == Moves::Scissors && pc == Moves::Paper))
    {
        result = 1;
    }
    else
    {
        result = 2;
    }

    return pc;
}

Moves getClickedMove(const sf::Vector2i &clickPos, const std::unordered_map<std::string, sf::Sprite> &player)
{
    sf::Vector2f posF(static_cast<float>(clickPos.x), static_cast<float>(clickPos.y));

    if (player.at("rock").getGlobalBounds().contains(posF))
        return Moves::Rock;
    if (player.at("paper").getGlobalBounds().contains(posF))
        return Moves::Paper;
    if (player.at("scissors").getGlobalBounds().contains(posF))
        return Moves::Scissors;

    return Moves::None;
}

export void HandleClick(GameState &state, const auto &MouseClick,
                        Moves &human_move, Moves &pc_move,
                        std::mt19937 &generator, int &result,
                        const std::unordered_map<std::string, sf::Sprite> &player)
{

    if (state == GameState::Start || state == GameState::Result)
    {
        state = GameState::Playing;
        human_move = Moves::None;
        std::println("LBM_Playing");
        return;
    }

    if (state == GameState::Playing)
    {
        sf::Vector2i clickPos = MouseClick->position;
        Moves clicked = getClickedMove(clickPos, player);

        if (clicked != Moves::None)
        {
            human_move = clicked;
            pc_move = processRound(result, human_move, generator);
            state = GameState::Result;
        }
    }
}