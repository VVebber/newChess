#ifndef CHESS_MAINMENU_H
#define CHESS_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MainMenu {
protected:
    float SizeX = 60;
    float SizeY = 300;

    std::vector<sf::RectangleShape> Buttons;
    std::vector<sf::Texture> Texture;
    std::vector<sf::Text> Texts;
    std::vector<sf::Font> font;

    sf::Event event;

    sf::Vector2f MousePositionPres;
    sf::Vector2f MousePositionHover;

    int quantity;

    int MaxWinSizeX = 0;
    int MaxWinSizeY = 0;
public:
    MainMenu(std::vector<sf::Texture> p_Texture = {}, int p_quantli = 0, std::vector<sf::Font> p_font = {}) {

        for (int i = 0; i < p_Texture.size(); i++)
            Texture[i] = p_Texture[i];

        for (auto spam: p_font)
            font.push_back(spam);

        quantity = p_quantli;
    }

    void WinButton(sf::RenderWindow &win){
        for (auto &button: Buttons) {
            win.draw(button);
        }
        for (auto &text: Texts) {
            win.draw(text);
        }
    }

    void CreatBrtMainMenu() {
        float PositionY = 10;
        getSizeButton();
        for (int i = 0; i < quantity; i++) {
            sf::RectangleShape button(sf::Vector2f(SizeY, SizeX));
            button.setFillColor(sf::Color(211, 211, 211));
            button.setPosition(sf::Vector2f((MaxWinSizeX / 2.1) - (SizeX / 2), (12 * MaxWinSizeY) / 100 + PositionY));
            PositionY += SizeX + 10;

            button.setOutlineThickness(1);
            button.setOutlineColor(sf::Color(128, 128, 128));
            Buttons.push_back(button);
        }
        if(true)
        CreatTxtMainMenu();
    }

    void CreatTxtMainMenu() {
        float PositionY = 10;
        for (int i = 0; i < Buttons.size(); i++) {
            sf::Text text;
            text.setFont(font[0]);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color(128, 128, 128));
            text.setPosition(sf::Vector2f((MaxWinSizeX / 2) - (SizeX / 2), (13 * MaxWinSizeY) / 100 + PositionY));
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

            Texts.push_back(text);
        }
    }

    void hover(sf::Event event) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
            for (int i = 0; i < Buttons.size(); i++)
                Buttons[i].getGlobalBounds().contains(mousePosition) ? Buttons[i].setFillColor(sf::Color(112, 128, 144))
                                                                     : Buttons[i].setFillColor(sf::Color(211, 211, 211));
        }
    }

    int setSizeButtons(){
        return Buttons.size();
    }

    void getEvent(sf::Event newEvent) {
        event = newEvent;
    }

    void getSizeButton(){
        float Percent_X = 5, Percent_Y = 29;
        SizeX = (Percent_X * MaxWinSizeX) / 100;
        SizeY = (Percent_Y * MaxWinSizeY) / 100;
    }

    void getMaxWin(int newMaxWinSizeX, int newMaxWinSizeY){
        MaxWinSizeX = newMaxWinSizeX;
        MaxWinSizeY = newMaxWinSizeY;

    }

    void getMousePositionPres(sf::Vector2f newMousePosition) {
        MousePositionPres = newMousePosition;
    }

    void PressedMainMenu(sf::RenderWindow& win, bool *CreadPlayMenu) {
        if (Buttons.size() != 0) {
            if (Buttons[0].getGlobalBounds().contains(MousePositionPres)) {//Играть
                *CreadPlayMenu = true;
                Buttons.clear();
                Texts.clear();
            } else if (Buttons[2].getGlobalBounds().contains(MousePositionPres))//выход
                win.close();
        }
    }
};

#endif //CHESS_MAINMENU_H
