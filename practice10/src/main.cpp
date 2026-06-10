#include <SFML/Graphics.hpp>

import std;
import Assets;
import LogicGame;
import Renderer;

int main()
{
    const int FRAME = 1024;

    sf::RenderWindow window(sf::VideoMode({FRAME, FRAME}), "RPS Game");

    sf::Texture tMoves;
    LoadingTexture(tMoves, "pictures/Moves.png");
    sf::Texture tStart;
    LoadingTexture(tStart, "pictures/Start.png");
    sf::Texture tStatus;
    LoadingTexture(tStatus, "pictures/Status.png");

    std::unordered_map<std::string, sf::Sprite> player;
    std::unordered_map<std::string, sf::Sprite> pc;
    std::unordered_map<std::string, sf::Sprite> status;

    sf::Sprite start = CreateSprite(tStart, {0, 0}, {FRAME, FRAME});
    sf::Sprite make_a_move = CreateSprite(tStatus, {0, 816}, {FRAME, 200});

    player.insert_or_assign("rock", CreateSprite(tMoves, {0, FRAME}, {FRAME, FRAME}));
    pc.insert_or_assign("rock", CreateSprite(tMoves, {0, 0}, {FRAME, FRAME}));
    player.insert_or_assign("paper", CreateSprite(tMoves, {FRAME, FRAME}, {FRAME, FRAME}));
    pc.insert_or_assign("paper", CreateSprite(tMoves, {FRAME, 0}, {FRAME, FRAME}));
    player.insert_or_assign("scissors", CreateSprite(tMoves, {2 * FRAME, FRAME}, {FRAME, FRAME}));
    pc.insert_or_assign("scissors", CreateSprite(tMoves, {2 * FRAME, 0}, {FRAME, FRAME}));

    status.insert_or_assign("win", CreateSprite(tStatus, {0, 0}, {FRAME, 256}));
    status.insert_or_assign("lose", CreateSprite(tStatus, {0, 256}, {FRAME, 256}));
    status.insert_or_assign("draw", CreateSprite(tStatus, {0, 540}, {FRAME, 284}));

    Sprites all_sprites(player, pc, status, start, make_a_move);

    GameSession session;

    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
            {
                std::println("Window closed");
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>())
            {

                auto MouseClick = event->getIf<sf::Event::MouseButtonPressed>();

                if (MouseClick && MouseClick->button == sf::Mouse::Button::Left)
                {
                    HandleClick(session, MouseClick, all_sprites.getPlayerSprites());
                }
            }
        }

        window.clear(sf::Color::White);

        renderGame(window, session, all_sprites);

        window.display();
    }

    return 0;
}