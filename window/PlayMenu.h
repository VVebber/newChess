#ifndef CHESS_PLAYMENU_H
#define CHESS_PLAYMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "MainMenu.h"

#include "../ChessPieces/Pawn.h"

class PlayMenu : public MainMenu {
public:
    std::vector<sf::Texture> TxChessBoard;
    std::vector<sf::RectangleShape> ChessBoard;
public:

    PlayMenu(std::vector<sf::Texture> p_Texture = {}, int p_quantli = 0, std::vector<sf::Font> p_font = {}, std::vector<sf::Texture> p_TxChessBoard = {}) : MainMenu(
            p_Texture, p_quantli, p_font) {

        for (int i = 0; i < p_Texture.size(); i++)
            Texture[i] = p_Texture[i];

        for (auto spam: p_font)
            font.push_back(spam);

        for (auto sp : p_TxChessBoard)
            TxChessBoard.push_back(sp);

        quantity = p_quantli;
    }

    void CreatBrtPlayMenu() {
        float PositionY = 150;
        for (int i = 0; i < quantity; i++) {
            sf::RectangleShape button(sf::Vector2f(SizeY, SizeX));
            button.setFillColor(sf::Color(211, 211, 211));
            button.setPosition(sf::Vector2f(950, PositionY - SizeX));

            PositionY += SizeX + 10;

            button.setOutlineThickness(1);
            button.setOutlineColor(sf::Color(128, 128, 128));
            Btr.push_back(button);
        }
        if(Text.size() != 0)
        CreatTxtPlayMenu();
    }

    void CreatChessBoard(int i) {
        ChessBoard.clear();
        sf::RectangleShape Sp_ChessBoard;
        Sp_ChessBoard.setSize(sf::Vector2f(600, 600));
        Sp_ChessBoard.setPosition(sf::Vector2f(91, 120));
        Sp_ChessBoard.setTexture(&TxChessBoard[i]);
        ChessBoard.push_back(Sp_ChessBoard);
    }

    void SpawnChessBoard(sf::RenderWindow& win) {
        for (auto& CB : ChessBoard) {
            win.draw(CB);
        }
    }

    void CreatTxtPlayMenu() {
        float PositionY = 150;
        for (int i = 0; i < Btr.size(); i++) {
            sf::Text text;
            text.setFont(font[0]);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color(128, 128, 128));
            text.setPosition(sf::Vector2f(950 + 10, PositionY - SizeX + 10));

            text.setOutlineThickness(1);
            text.setOutlineColor(sf::Color(0, 0, 0));
            PositionY += SizeX + 10;
            switch (i) {
                case 0:
                    text.setString(L"Начать белыми");
                    break;
                case 1:
                    text.setString(L"Начать черными");
                    break;
                case 2:
                    text.setString(L"Тип доски");
                    break;
                case 3:
                    text.setString(L"Обучение");
                    break;
                case 4:
                    text.setString(L"История");
                    break;
            }
            Text.push_back(text);
        }
    }

    void AllClear() {
        Btr.clear();
        Text.clear();
    }

    void PressedPlayMenu(bool* ptr_PlayLogic, std::vector<Pawn> &Pawns) {
        bool Temporary = false;
        if (Btr.size() != 0) {
            if (Btr[0].getGlobalBounds().contains(mousePositionPres)) {
                CreatChessBoard(1);
                *ptr_PlayLogic = true;
                for (auto& figure : Pawns) {
                    if (figure.getPosition_F() == "down")
                        figure.setColor("white");
                    if (figure.getPosition_F() == "up")
                        figure.setColor("black");
                }
                Temporary = true;
                AllClear();
            }
            else if (Btr[1].getGlobalBounds().contains(mousePositionPres)) {
                CreatChessBoard(0);
                *ptr_PlayLogic = true;

                for (auto& figure : Pawns) {
                    if (figure.getPosition_F() == "down")
                        figure.setColor("blcak");
                    if (figure.getPosition_F() == "up")
                        figure.setColor("white");

                }
                Temporary = true;
                AllClear();
            }
            if (Temporary)
                for (auto& figure : Pawns) {
                    figure.CredPawn();
                }
        }
    }
};
#endif //CHESS_PLAYMENU_H
