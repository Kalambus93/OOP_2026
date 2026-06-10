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

export struct GameSession
{
    GameState state = GameState::Start;
    Moves human_move = Moves::None;
    Moves pc_move = Moves::None;
    int result = -1;
    std::mt19937 generator;

    GameSession() : generator(std::random_device{}()) {}
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

export void HandleClick(GameSession &session, const auto &MouseClick, const std::unordered_map<std::string, sf::Sprite> &playerSprites)
{
    {
        if (session.state == GameState::Start)
        {
            session.state = GameState::Playing;
            std::println("LBM_Playing");
        }

        else if (session.state == GameState::Playing)
        {
            sf::Vector2i clickPos = MouseClick->position;

            if (playerSprites.at("rock").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos)))
            {
                std::println("Clicked on ROCK!");
                session.human_move = Moves::Rock;
            }

            else if (playerSprites.at("paper").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos)))
            {
                std::println("Clicked on PAPER!");
                session.human_move = Moves::Paper;
            }

            else if (playerSprites.at("scissors").getGlobalBounds().contains(static_cast<sf::Vector2f>(clickPos)))
            {
                std::println("Clicked on SCISSORS!");
                session.human_move = Moves::Scissors;
            }

            if (session.human_move != Moves::None)
            {

                session.pc_move = processRound(session.result, session.human_move, session.generator);

                session.state = GameState::Result;
            }
        }

        else
        {
            session.state = GameState::Playing;
            std::println("LBM_Result");
        }
    }
}