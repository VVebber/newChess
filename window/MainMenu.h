#ifndef CHESS_MAINMENU_H
#define CHESS_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MainMenu {
public:
    const float SizeX = 60;
    const float SizeY = 300;

    std::vector<sf::RectangleShape> Btr;
    std::vector<sf::Texture> Texture;
    std::vector<sf::Text> Text;
    std::vector<sf::Font> font;

    sf::Event event;

    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

    int quantity;
public:
    MainMenu(std::vector<sf::Texture> p_Texture = {}, int p_quantli = 0, std::vector<sf::Font> p_font = {}) {

        for (int i = 0; i < p_Texture.size(); i++)
            Texture[i] = p_Texture[i];

        for (auto spam: p_font)
            font.push_back(spam);

        quantity = p_quantli;
    }

    void F_event(sf::Event CL_event) {
        event = CL_event;
    }

    void F_mousePositionPres(sf::Vector2f CL_mousePosition) {
        mousePositionPres = CL_mousePosition;
    }

    void CreatBrtMainMenu() {
        float PositionY = 150;
        for (int i = 0; i < quantity; i++) {
            sf::RectangleShape button(sf::Vector2f(SizeY, SizeX));
            button.setFillColor(sf::Color(211, 211, 211));
            button.setPosition(sf::Vector2f(540, PositionY));

            PositionY += SizeX + 10;

            button.setOutlineThickness(1);
            button.setOutlineColor(sf::Color(128, 128, 128));
            Btr.push_back(button);
        }
        if(Text.size() != 0)
        CreatTxtMainMenu();
    }

    void CreatTxtMainMenu() {
        float PositionY = 150;
        for (int i = 0; i < Text.size(); i++) {
            sf::Text text;
            text.setFont(font[0]);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color(128, 128, 128));
            text.setPosition(sf::Vector2f(540 + 10, PositionY + 10));

            text.setOutlineThickness(1);
            text.setOutlineColor(sf::Color(0, 0, 0));
            PositionY += SizeX + 10;
            switch (i) {
                case 0:
                    text.setString(L"Играть");
                    break;
                case 1:
                    text.setString(L"Настройки");
                    break;
                case 2:
                    text.setString(L"Выход");
                    break;
            }

            Text.push_back(text);
        }
    }

    void SpawnBrt(sf::RenderWindow &win) {
        for (auto &button: Btr) {
            win.draw(button);
        }
    }

    void SpawnText(sf::RenderWindow &win) {
        for (auto &text: Text) {
            win.draw(text);
        }
    }

    void hover(sf::Event event) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);

            for (int i = 0; i < Btr.size(); i++) {
                Btr[i].getGlobalBounds().contains(mousePosition) ? Btr[i].setFillColor(sf::Color(128, 128, 128))
                                                                 : Btr[i].setFillColor(sf::Color(211, 211, 211));
                if(i < Text.size())
                Btr[i].getGlobalBounds().contains(mousePosition) ? Text[i].setFillColor(sf::Color(211, 211, 211))
                                                                 : Text[i].setFillColor(sf::Color(128, 128, 128));

            }
        }
    }

    void PressedMainMenu(sf::RenderWindow& win, bool *CreadPlayMenu) {
        if(Btr.size() != 0)
        if (Btr[0].getGlobalBounds().contains(mousePositionPres)) {//Играть
            *CreadPlayMenu = true;
            Btr.clear();
            Text.clear();
        }
        else if (Btr[2].getGlobalBounds().contains(mousePositionPres))//выход
            win.close();
    }

};

#endif //CHESS_MAINMENU_H
