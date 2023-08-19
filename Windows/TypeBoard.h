#ifndef CHESS_TYPEBOARD_H
#define CHESS_TYPEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Shapes/Pawn.h"

class TypeBoard : public  MainMenu {
private:
    const float BtnHeight = 80;
    const float BtnWidth = 80;

    float PosBackground[2]{50,15};
    float BtrPosition[2]{70, 45};

    std::string TypeChessBoard = "classic";

    sf::RectangleShape Background;
    sf::RectangleShape Close;

    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

    sf::Texture BtrWood1;
    sf::Texture BtrWood2;

    sf::Font arial;
public:
    void gitTypeChessBoard(std::string *TypeBoard){
        *TypeBoard = TypeChessBoard;
    }

    TypeBoard( sf::Texture p_BtrWood1, sf::Texture p_BtrWood2, sf::Font p_arial) : MainMenu(p_BtrWood1, p_BtrWood2, p_arial) {
        BtrWood1 = p_BtrWood1;
        BtrWood2 = p_BtrWood2;
        arial = p_arial;
    }

    sf::Vector2f FmousePositionPres(sf::Vector2f mousePosition) {
        mousePositionPres = mousePosition;
        return mousePositionPres;
    }

    sf::Vector2f FmousePositionHover(sf::Vector2f mousePosition) {
        mousePositionHover = mousePosition;
        return mousePositionPres;
    }

    sf::Event Fevent(sf::Event Mainevent) {
        event = Mainevent;
        return event;
    }


    void CredBackgAndClose() {
        Close.setSize(sf::Vector2f(20, 20));
        Close.setFillColor(sf::Color(255, 0, 0));
        Close.setPosition(9000, 0);

        Background.setSize(sf::Vector2f(600, 690));
        Background.setFillColor(sf::Color(255, 215, 0));
        Background.setPosition(9000, 0);

    }

    void CredBtn(int NumMenuButtons) {
        for (int i = 0, i2 = 0; i < NumMenuButtons; i++, i2++) {
            sf::RectangleShape button(sf::Vector2f(BtnHeight, BtnWidth));
            button.setFillColor(sf::Color::Green);
            button.setPosition(9000, 0);
            MenuBtn.push_back(button);
        }
    }

    void StartAllPos() {
        Background.setPosition(PosBackground[0], PosBackground[1]);
        Close.setPosition(PosBackground[0], PosBackground[1]);


        int j = 0;
        float x = BtrPosition[0], y = BtrPosition[1];
        for (int i = 0, i2 = 0; i < MenuBtn.size(); i++, i2++) {
            MenuBtn[i].setPosition(x + BtnWidth * i2, y + BtnHeight * j);
            x += 15;
            if (i == 5) {
                x = BtrPosition[0];
                y += 40;
                j++;
                i2 = -1;
            }
        }
    }

    void EndAllPos() {
        Background.setPosition(9000, 0);
        Close.setPosition(9000, 0);
        for (int i = 0, i2 = 0; i < MenuBtn.size(); i++, i2++) {
            MenuBtn[i].setPosition(9000, 0);
        }
    }

   void PressedType(int * mas, std::string *TypeChess) {
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.mouseButton.button == sf::Mouse::Left) {
                if ((Close.getGlobalBounds().contains(mousePositionPres)))
                    mas[13] = 0;

                if(MenuBtn[0].getGlobalBounds().contains(mousePositionPres)) {
                    TypeChessBoard = "classic";
                    *TypeChess = "classic";
                }

                if(MenuBtn[1].getGlobalBounds().contains(mousePositionPres)) {
                    TypeChessBoard = "mini4x4";
                    *TypeChess = "mini4x4";
                }
            }
    }

    void SpawnAll(sf::RenderWindow &win){
        StartAllPos();
        win.draw(Background);
        win.draw(Close);
        SpawnBrt(win);
    }

};


#endif //CHESS_TYPEBOARD_H
