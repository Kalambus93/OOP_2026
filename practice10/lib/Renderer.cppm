module;

#include <SFML/Graphics.hpp>

export module Renderer;

import std;
import Assets;
import LogicGame;

void drawButton(sf::RenderWindow& window, sf::Sprite& sprite, float x, float y) {
    sprite.setScale({ 0.3f, 0.3f });
    sprite.setPosition({ x, y });
    window.draw(sprite);
}

export void renderGame(sf::RenderWindow& window, const GameState& state,
    std::unordered_map<std::string, sf::Sprite>& player,
    std::unordered_map<std::string, sf::Sprite>& pc,
    std::unordered_map<std::string, sf::Sprite>& status,
    const sf::Sprite& start, sf::Sprite& make_a_move,
    Moves human_move, Moves pc_move, int result) {

    if (state == GameState::Start) {
        window.draw(start);
    }

    else if (state == GameState::Playing) {
        make_a_move.setPosition({ 30.0f, 0.0f });
        window.draw(make_a_move);

        drawButton(window ,player.at("rock"), 10.0f, 400.0f);
        drawButton(window, player.at("paper"), 350.0f, 400.0f);
        drawButton(window, player.at("scissors"), 690.0f, 400.0f);
    }

    else if (state == GameState::Result) {

        if (human_move == Moves::Rock) {
            player.at("rock").setScale({ 0.4f, 0.4f });
            player.at("rock").setPosition({ 150.0f, 300.0f });
            window.draw(player.at("rock"));
        }
        else if (human_move == Moves::Paper) {
            player.at("paper").setScale({ 0.4f, 0.4f });
            player.at("paper").setPosition({ 150.0f, 300.0f });
            window.draw(player.at("paper"));
        }
        else if (human_move == Moves::Scissors) {
            player.at("scissors").setScale({ 0.4f, 0.4f });
            player.at("scissors").setPosition({ 150.0f, 300.0f });
            window.draw(player.at("scissors"));
        }

        if (pc_move == Moves::Rock) {
            pc.at("rock").setScale({ 0.4f, 0.4f });
            pc.at("rock").setPosition({ 550.0f, 300.0f });
            window.draw(pc.at("rock"));
        }
        else if (pc_move == Moves::Paper) {
            pc.at("paper").setScale({ 0.4f, 0.4f });
            pc.at("paper").setPosition({ 550.0f, 300.0f });
            window.draw(pc.at("paper"));
        }
        else if (pc_move == Moves::Scissors) {
            pc.at("scissors").setScale({ 0.4f, 0.4f });
            pc.at("scissors").setPosition({ 550.0f, 300.0f });
            window.draw(pc.at("scissors"));
        }

        switch (result) {
        case 0:
            status.at("draw").setPosition({ 0.0f, 0.0f });
            window.draw(status.at("draw"));
            break;
        case 1:
            status.at("win").setPosition({ 0.0f, 0.0f });
            window.draw(status.at("win"));
            break;
        case 2:
            status.at("lose").setPosition({ 0.0f, 0.0f });
            window.draw(status.at("lose"));
            break;
        }
    }
}