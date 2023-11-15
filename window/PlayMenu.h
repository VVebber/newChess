#ifndef CHESS_PLAYMENU_H
#define CHESS_PLAYMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "MainMenu.h"

#include "../ChessPieces/Pawn.h"

class PlayMenu : public MainMenu {
private:
    std::vector<sf::Texture> TxChessBoard;
    std::vector<sf::RectangleShape> ChessBoard;

    std::vector<sf::Text> ChessCoordWhite;
    std::vector<sf::Text> ChessCoordBlack;

    sf::RectangleShape Background_Timer;
    sf::RectangleShape Background_Stopwatch;
    sf::RectangleShape Background_ChessCord;
public:
    PlayMenu(std::vector<sf::Texture> p_Texture = {}, int p_quantli = 0, std::vector<sf::Font> p_font = {},
             std::vector<sf::Texture> p_TxChessBoard = {}) : MainMenu(
            p_Texture, p_quantli, p_font) {

        for (int i = 0; i < p_Texture.size(); i++)
            Texture[i] = p_Texture[i];

        for (auto spam: p_font)
            font.push_back(spam);

        for (auto sp: p_TxChessBoard)
            TxChessBoard.push_back(sp);

        quantity = p_quantli;
    }

    void CreatBrtPlayMenu() {
        float PositionY = 10;
        float Percent_X = 75;
        getSizeButton();
        for (int i = 0; i < quantity; i++) {
            sf::RectangleShape button(sf::Vector2f(SizeY, SizeX));
            button.setFillColor(sf::Color(211, 211, 211));
            button.setPosition(sf::Vector2f(Percent_X * MaxWinSizeX / 100, (12 * MaxWinSizeY) / 100 + PositionY));
            PositionY += SizeX + 10;

            button.setOutlineThickness(1);
            button.setOutlineColor(sf::Color(128, 128, 128));
            Buttons.push_back(button);
        }
        if (false)
            CreatTxtPlayMenu();
    }

    void CreatChessBoard(int i) {
        ChessBoard.clear();
        float Percent_X = 7, Percent_Y = 12.5;
        sf::RectangleShape Sp_ChessBoard;
        Sp_ChessBoard.setSize(sf::Vector2f(600, 600));
        Sp_ChessBoard.setPosition(sf::Vector2f(Percent_X * MaxWinSizeX/100, Percent_Y * MaxWinSizeY / 100));
        Sp_ChessBoard.setTexture(&TxChessBoard[i]);
        ChessBoard.push_back(Sp_ChessBoard);
    }

    void TimeWin(sf::RenderWindow &win){
        win.draw(Background_Timer);
        win.draw(Background_Stopwatch);
        win.draw(Background_ChessCord);
    }

    void TimeCreat(){
        Timer();
        Stopwatch();
        ChessCord();
    }

    void Timer(){
        Background_Timer = CreatBackground(Background_Timer,0);
    }

    void Stopwatch(){
        Background_Stopwatch = CreatBackground(Background_Stopwatch,1);
    }

    void ChessCord(){
        Background_ChessCord = CreatBackground(Background_ChessCord, 0,1,2,4);
    }

    sf::RectangleShape CreatBackground( sf::RectangleShape Background, int x,int y = 0, int b = 1, int c = 1) const{
        float Percent_X = 17, Percent_Y = 9;
        float Percent_X_Pos = 60, Percent_Y_Pos = 12.5;
        Background.setSize(sf::Vector2f((Percent_X * MaxWinSizeX / 100) * b, (Percent_Y * MaxWinSizeY / 100) * c));
        Background.setPosition(sf::Vector2f(Percent_X_Pos * MaxWinSizeX / 100 + Background_Timer.getSize().x * x, (Percent_Y_Pos * MaxWinSizeY / 100) + Background_Timer.getSize().y * y));
        Background.setFillColor(sf::Color(169, 169, 169));
        Background.setOutlineThickness(1);
        Background.setOutlineColor(sf::Color(0, 0, 0));


        return Background;
    }

    void SpawnChessBoard(sf::RenderWindow &win) {
        for (auto &CB: ChessBoard) {
            win.draw(CB);
        }
    }

    void CreatTxtPlayMenu() {
        float PositionY = 150;
        for (int i = 0; i < Buttons.size(); i++) {
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
            Texts.push_back(text);
        }
    }

    void AllClear() {
        Buttons.clear();
        Texts.clear();
    }

    void PressedPlayMenu(bool *ptr_PlayLogic, std::vector<Pawn> &Pawns) {
        bool Temporary = false;
        if (Buttons.size() != 0) {
            if (Buttons[0].getGlobalBounds().contains(MousePositionPres)) {
                CreatChessBoard(1);
                TimeCreat();
                *ptr_PlayLogic = true;
                for (auto &figure: Pawns) {
                    if (figure.getPosition_F() == "down")
                        figure.setColor("white");
                    if (figure.getPosition_F() == "up")
                        figure.setColor("black");
                }
                Temporary = true;
                AllClear();
            } else if (Buttons[1].getGlobalBounds().contains(MousePositionPres)) {
                CreatChessBoard(0);
                TimeCreat();
                *ptr_PlayLogic = true;
                for (auto &figure: Pawns) {
                    if (figure.getPosition_F() == "down")
                        figure.setColor("black");
                    if (figure.getPosition_F() == "up")
                        figure.setColor("white");

                }
                Temporary = true;
                AllClear();
            }
            if (Temporary)
                for (auto &figure: Pawns) {
                    figure.CredPawn();
                }
        }
    }

    void getSizeButton() {
        float Percent_X = 5, Percent_Y = 29;
        SizeX = (Percent_X * MaxWinSizeX) / 100;
        SizeY = (Percent_Y * MaxWinSizeY) / 100;
    }
};
#endif //CHESS_PLAYMENU_H
