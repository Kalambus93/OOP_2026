module;

#include <SFML/Graphics.hpp>

export module Renderer;

import std;
import Assets;
import LogicGame;

export class Sprites
{
private:
    std::unordered_map<std::string, sf::Sprite> _player;
    std::unordered_map<std::string, sf::Sprite> _pc;
    std::unordered_map<std::string, sf::Sprite> _status;
    sf::Sprite _start;
    sf::Sprite _make_a_move;

public:
    Sprites(std::unordered_map<std::string, sf::Sprite> player,
            std::unordered_map<std::string, sf::Sprite> pc,
            std::unordered_map<std::string, sf::Sprite> status,
            sf::Sprite start,
            sf::Sprite make_a_move)
        : _player(std::move(player)),
          _pc(std::move(pc)),
          _status(std::move(status)),
          _start(std::move(start)),
          _make_a_move(std::move(make_a_move)) {}

    std::unordered_map<std::string, sf::Sprite> &getPlayerSprites()
    {
        return _player;
    }

    std::unordered_map<std::string, sf::Sprite> &getPcSprites()
    {
        return _pc;
    }

    std::unordered_map<std::string, sf::Sprite> &getStatusSprites()
    {
        return _status;
    }

    sf::Sprite &getStartSprite()
    {
        return _start;
    }

    sf::Sprite &getMakeAMoveSprite()
    {
        return _make_a_move;
    }
};

void drawButton(sf::RenderWindow &window, sf::Sprite &sprite, sf::Vector2f scale, sf::Vector2f position)
{
    sprite.setScale(scale);
    sprite.setPosition(position);
    window.draw(sprite);
}

// Сделайте параметр константным, это хорошая практика
export void renderGame(sf::RenderWindow &window, const GameSession &session, Sprites &all_sprites)
{
    if (session.state == GameState::Start)
    {
        window.draw(all_sprites.getStartSprite());
    }
    else if (session.state == GameState::Playing)
    {
        all_sprites.getMakeAMoveSprite().setPosition({30.0f, 0.0f});
        window.draw(all_sprites.getMakeAMoveSprite());

        drawButton(window, all_sprites.getPlayerSprites().at("rock"), {0.3f, 0.3f}, {10.0f, 400.0f});
        drawButton(window, all_sprites.getPlayerSprites().at("paper"), {0.3f, 0.3f}, {350.0f, 400.0f});
        drawButton(window, all_sprites.getPlayerSprites().at("scissors"), {0.3f, 0.3f}, {690.0f, 400.0f});
    }
    else if (session.state == GameState::Result)
    {
        // Используем switch для чистоты кода (как мы договаривались)
        switch (session.human_move)
        {
        case Moves::Rock:
            drawButton(window, all_sprites.getPlayerSprites().at("rock"), {0.4f, 0.4f}, {150.0f, 300.0f});
            break;
        case Moves::Paper:
            drawButton(window, all_sprites.getPlayerSprites().at("paper"), {0.4f, 0.4f}, {150.0f, 300.0f});
            break;
        case Moves::Scissors:
            drawButton(window, all_sprites.getPlayerSprites().at("scissors"), {0.4f, 0.4f}, {150.0f, 300.0f});
            break;
        default:
            break;
        }

        switch (session.pc_move)
        {
        case Moves::Rock:
            drawButton(window, all_sprites.getPcSprites().at("rock"), {0.4f, 0.4f}, {550.0f, 300.0f});
            break;
        case Moves::Paper:
            drawButton(window, all_sprites.getPcSprites().at("paper"), {0.4f, 0.4f}, {550.0f, 300.0f});
            break;
        case Moves::Scissors:
            drawButton(window, all_sprites.getPcSprites().at("scissors"), {0.4f, 0.4f}, {550.0f, 300.0f});
            break;
        default:
            break;
        }

        // Используем drawButton и для статуса для единообразия
        switch (session.result)
        {
        case 0:
            drawButton(window, all_sprites.getStatusSprites().at("draw"), {1.0f, 1.0f}, {0.0f, 0.0f});
            break;
        case 1:
            drawButton(window, all_sprites.getStatusSprites().at("win"), {1.0f, 1.0f}, {0.0f, 0.0f});
            break;
        case 2:
            drawButton(window, all_sprites.getStatusSprites().at("lose"), {1.0f, 1.0f}, {0.0f, 0.0f});
            break;
        }
    }
}