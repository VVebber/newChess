#ifndef CHESS_MAINMENU_H
#define CHESS_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class WindowPc;

class MainMenu {
public:
    std::vector <sf::RectangleShape> MenuBtn;
    std::vector <sf::Text> MenuText;

    sf::Texture BtrWood1;
    sf::Texture BtrWood2;

    const float BtnHeight = 60;
    const float BtnWidth = 300;
    float BtnPositionMenu[2]{540, 150};
private:
    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

    sf::Font arial;

public:

    MainMenu( sf::Texture p_BtrWood1, sf::Texture p_BtrWood2, sf::Font p_arial){
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

    sf::Font Ffont(sf::Font font) {
        arial = font;
        return arial;
    }

    void CreatBrt(int NumMenuButtons) {
        for (int i = 0; i < NumMenuButtons; i++) {
            sf::RectangleShape button(sf::Vector2f(BtnWidth, BtnHeight));
            button.setOutlineThickness(1);
            button.setOutlineColor(sf::Color(255, 215, 0));
            i % 2 == 0 ? button.setTexture(&BtrWood1) : button.setTexture(&BtrWood2);
            MenuBtn.push_back(button);
        }
        btrEndPosit();
    }

    void CreatTxtMenu() {
        for (int i = 0; i < MenuBtn.size(); i++) {
            sf::Text text;
            text.setFont(arial);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::White);
            switch (i) {
                case 0:
                    text.setString(L"Начать");
                    break;
                case 1:
                    text.setString(L"Настройки");
                    break;
                case 2:
                    text.setString(L"Выход");
                    break;

            }
            MenuText.push_back(text);
        }
        TxtEndPosit();
    }

    void btrMeneStarPosit() {
        float PositionY = BtnPositionMenu[1];
        for (auto &buttonSch: MenuBtn) {
            buttonSch.setPosition(sf::Vector2f(BtnPositionMenu[0], PositionY));
            PositionY += BtnHeight;
        }
    }

    void btrEndPosit() {
        for (auto &buttonSch: MenuBtn) {
            buttonSch.setPosition(sf::Vector2f(54000, 0));
        }
    }

    void TxtMeneStarPosit() {
        float PositionY = BtnPositionMenu[1];
        for (auto &buttonSch: MenuText) {
            buttonSch.setPosition(sf::Vector2f(BtnPositionMenu[0] + 10, PositionY + 10));
            PositionY += BtnHeight;
        }
    }

    void TxtEndPosit() {
        for (auto &buttonSch: MenuText) {
            buttonSch.setPosition(sf::Vector2f(54000, 0));
        }
    }

    void hover(sf::Event event) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);

            for (auto &buttonSch: MenuBtn) {
                buttonSch.getGlobalBounds().contains(mousePosition) ? buttonSch.setFillColor(sf::Color(255, 0, 0))
                                                                    : buttonSch.setFillColor(sf::Color(210, 180, 140));
            }
        }
    }

    void SpawnTxt(sf::RenderWindow &win) {
        for (auto &txt: MenuText) {
            win.draw(txt);
        }
    }

    void SpawnBrt(sf::RenderWindow &win) {
        for (auto &button: MenuBtn) {
            win.draw(button);
        }
    }

    void PressedMenu(sf::RenderWindow& win, int *mas) {
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.mouseButton.button == sf::Mouse::Left) {

                if (MenuBtn[0].getGlobalBounds().contains(mousePositionPres)) {/*MainMenu*/
                    mas[10] = 1;
                    mas[9] = 1;
                }

                if (MenuBtn[2].getGlobalBounds().contains(mousePositionPres))/*MainMenu*/
                    win.close();
            }
    }


    void OnMenu(sf::RenderWindow& win){
        btrMeneStarPosit();
        TxtMeneStarPosit();
        SpawnBrt(win);
        SpawnTxt(win);
    }

    void OffMenu(sf::RenderWindow& win){
        btrEndPosit();
        TxtEndPosit();
    }

};
#endif //CHESS_MAINMENU_H
