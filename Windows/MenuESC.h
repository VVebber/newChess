#ifndef CHESS_MENUESC_H
#define CHESS_MENUESC_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Shapes/Pawn.h"

class MainMenu;

class MenuESC : public MainMenu {
private:
    const float BtnHandW = 60;
    sf::RectangleShape board;

    sf::Texture BtrWood1;
    sf::Texture BtrWood2;

    sf::Font arial;

public:
    std::vector<sf::RectangleShape> MenuESCBtn;

public:
    MenuESC( sf::Texture p_BtrWood1, sf::Texture p_BtrWood2, sf::Font p_arial) : MainMenu(p_BtrWood1, p_BtrWood2, p_arial) {
        BtrWood1 = p_BtrWood1;
        BtrWood2 = p_BtrWood2;
        arial = p_arial;
    }

    void CredBtnESC(int NumMenuButtons) {
        for (int i = 0; i < NumMenuButtons; i++) {
            sf::RectangleShape button(sf::Vector2f(BtnHandW, BtnHandW));
            board.setFillColor(sf::Color::Green);
            MenuESCBtn.push_back(button);
        }
    }

    void startESC(){
        float BtnPosition = 450;
        for (auto &buttonSch: MenuESCBtn) {
            buttonSch.setPosition(sf::Vector2f(BtnPosition,240));
            BtnPosition += BtnHeight+50;
        }
    }
    void Fboard(){
        board.setSize(sf::Vector2f(300, 120));
        board.setFillColor(sf::Color(255, 215, 0));
        board.setPosition(440, 210);
    }

    void menuESC(sf::RenderWindow& win) {
        win.draw(board);
        for (auto &button: MenuESCBtn) {
            win.draw(button);
        }
    }
};
#endif //CHESS_MENUESC_H
