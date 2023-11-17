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
    std::vector<sf::Text> ChessCords_Win;
    std::vector<std::string> ChessCords_txt;

    std::string Time;
    std::string ChessCordStart =" ";
    std::string ChessCordEnd =" ";
    float MoverCounter = 0;

    sf::RectangleShape Background_Timer;
    sf::RectangleShape Background_Stopwatch;
    sf::RectangleShape Background_ChessCord;
    sf::Text Time_Win;

    sf::Clock Stopwatch;
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

    void CreatMenuPlay() {
        Buttons.clear();
        Texts.clear();
        CreatBrtPlayMenu();
        CreatTxtPlay(Texts, 13, 76,Buttons.size(),30,1);
        CreadChessCords_txt();
        if (Texts.size() > 0)
            WordsPlayMenu();
    }

    void CreatPlay() {
        Background_Timer = CreatBackground(Background_Timer, 0, 1, 2);
        Background_ChessCord = CreatBackground(Background_ChessCord, 0, 1, 2, 4);
        Time_Win = CreatTime(Time_Win);
        CreatTxtPlay(ChessCords_Win, 20, 62, 5,30, 3);
    }

    void WinMenuPlay(sf::RenderWindow &win) {
        win.draw(Background_Timer);
        win.draw(Background_ChessCord);

        Time = NewTime();
        Time_Win.setString(Time);
        win.draw(Time_Win);

        WinCordChess_txt();
        for(auto &Chesscoord : ChessCords_Win)
            win.draw(Chesscoord);

        for (auto &CB: ChessBoard) {
            win.draw(CB);
        }
    }

    void CreadChessCords_txt() {
        ChessCords_txt.clear();
        for (int i = 0; i < 200; i++) {
            std::string sp = std::to_string(i + 1) +") ";
            ChessCords_txt.push_back(sp);
        }
    }

    sf::Text CreatTime(sf::Text text){
        float Percent_Y = 10;
        float Percent_X = 68;
        text.setFont(font[0]);
        text.setCharacterSize(60);
        text.setFillColor(sf::Color(128, 128, 128));
        text.setPosition(sf::Vector2f(Percent_X * MaxWinSizeX / 100, (12 * MaxWinSizeY) / 100 + Percent_Y));
        text.setOutlineThickness(2);
        text.setOutlineColor(sf::Color(0, 0, 0));
        return text;
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
    }

    std::vector<sf::Text> CreatTxtPlay(std::vector<sf::Text> &txt, float Percent_Y,float Percent_X, int size,int SizeTxt, int SizeStroke) {
        float CoordY = 10;
        for (int i = 0; i < size; i++) {
            sf::Text text;
            text.setFont(font[0]);
            text.setCharacterSize(SizeTxt);
            text.setFillColor(sf::Color(128, 128, 128));
            text.setPosition(sf::Vector2f(Percent_X * MaxWinSizeX / 100, (Percent_Y * MaxWinSizeY) / 100 + CoordY));
            CoordY += SizeX + 10;

            text.setOutlineThickness(SizeStroke);
            text.setOutlineColor(sf::Color(0, 0, 0));
            txt.push_back(text);
        }
        return txt;
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

    void DownChessCords_txt(int i) {
        i--;

        if (ChessCords_txt.size() > 0) {
            ChessCords_txt[i] = ChessCords_txt[i] + ChessCordStart + ChessCordEnd + (MoverCounter == 0?" | ": " ");
            std::cout<<ChessCords_txt[i]<<"\n";
            //std::cout<<ChessCordStart<<" | "<<ChessCordEnd<<"\n";
        }
        MoverCounter += 0.5;
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

    void AllClear() {
        Buttons.clear();
        Texts.clear();
    }

    void WordsPlayMenu(){
        for (int i = 0; i < Buttons.size(); i++) {
            switch (i) {
                case 0:
                    Texts[i].setString(L"Начать белыми");
                    break;
                case 1:
                    Texts[i].setString(L"Начать черными");
                    break;
                case 2:
                    Texts[i].setString(L"Тип доски");
                    break;
                case 3:
                    Texts[i].setString(L"Обучение");
                    break;
                case 4:
                    Texts[i].setString(L"История");
                    break;
            }
        }
    }

    void WinCordChess_txt(int i = 0) {
        if (ChessCords_Win.size() > 0) {
            ChessCords_Win[0].setString(ChessCords_txt[0]);
            ChessCords_Win[1].setString(ChessCords_txt[i + 1]);
            ChessCords_Win[2].setString(ChessCords_txt[i + 2]);
            ChessCords_Win[3].setString(ChessCords_txt[i + 3]);
            ChessCords_Win[4].setString(ChessCords_txt[i + 4]);
        }

    }

    void PressedPlayMenu(bool *ptr_PlayLogic, std::vector<Pawn> &Pawns) {
        bool Temporary = false;
        if (Buttons.size() != 0) {
            if (Buttons[0].getGlobalBounds().contains(MousePositionPres)) {
                CreatChessBoard(1);
                CreatPlay();
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
                CreatPlay();
                *ptr_PlayLogic = true;
                for (auto &figure: Pawns) {
                    if (figure.getPosition_F() == "down")
                        figure.setColor("black");
                    if (figure.getPosition_F() == "up")
                        figure.setColor("white");

                }
                Temporary = true;
                AllClear();
            } else if (Buttons[2].getGlobalBounds().contains(MousePositionPres)) {
                Texts[2].setString(L"error");
            } else if (Buttons[3].getGlobalBounds().contains(MousePositionPres)) {
                Texts[3].setString(L"error");
            }
            if (Temporary)
                for (auto &figure: Pawns) {
                    figure.CredPawn();
                }
        }
    }

    std::string NewTime() {
        float time_f;
        time_f = setStopwatch().asSeconds();
        int time_i = time_f;
        std::string make = "";
        make =  ((time_i / 60) / 60 < 10? "0" : "") + std::to_string((time_i / 60) / 60) +
                ((time_i / 60) % 60 < 10?":0": ":") + std::to_string((time_i / 60) % 60) +
                (time_i % 60 < 10?":0": ":") + std::to_string(time_i % 60);
        return make;
    }
    int setMoverCounter_int(){
        if(MoverCounter == 1) {
            int i = MoverCounter;
            MoverCounter = 0;
            return i;
        } else return 0;
    }

    sf::Time setStopwatch(){
        return Stopwatch.getElapsedTime();
    }

    void getSizeButton() {
        float Percent_X = 5, Percent_Y = 29;
        SizeX = (Percent_X * MaxWinSizeX) / 100;
        SizeY = (Percent_Y * MaxWinSizeY) / 100;
    }

    void getChessCordStart(std::string newChessCordStart){
        ChessCordStart = newChessCordStart;
    }

    void getChessCordEnd(std::string newChessCordEnd){
        ChessCordEnd = newChessCordEnd;
    }

    template<class T1>
    std::string Cord(T1 &figure) {
        std::string cord ="";

        if (int(figure.Figure[0].getPosition().x) == 123) {
            cord = figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "A" : "H");
        } else if (int(figure.Figure[0].getPosition().x) == 191) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "B" : "G");
        } else if (int(figure.Figure[0].getPosition().x) == 259) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "C" : "F");
        } else if (int(figure.Figure[0].getPosition().x) == 326) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "D" : "E");
        } else if (int(figure.Figure[0].getPosition().x) == 394) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "E" : "D");
        } else if (int(figure.Figure[0].getPosition().x) == 462) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "F" : "C");
        } else if (int(figure.Figure[0].getPosition().x) == 529) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "G" : "B");
        } else if (int(figure.Figure[0].getPosition().x) == 597) {
            cord =  figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "H" : "A");
        }

        if (int(figure.Figure[0].getPosition().y) == 626) {
            cord = figure.getCord() + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "1" : "8");
        } else if (int(figure.Figure[0].getPosition().y) == 558) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "2" : "7");
        } else if (int(figure.Figure[0].getPosition().y) == 491) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "3" : "6");
        } else if (int(figure.Figure[0].getPosition().y) == 423) {
            cord = cord +  (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "4" : "5");
        } else if (int(figure.Figure[0].getPosition().y) == 355) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "5" : "4");
        } else if (int(figure.Figure[0].getPosition().y) == 288) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "6" : "3");
        } else if (int(figure.Figure[0].getPosition().y) == 220) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "7" : "2");
        } else if (int(figure.Figure[0].getPosition().y) == 152) {
            cord = cord + (figure.getColor_F() == "white" && figure.getPosition_F() == "down" ||  figure.getColor_F() == "black" && figure.getPosition_F() == "up"? "8" : "1");
        }
        return cord;
    }
};
#endif //CHESS_PLAYMENU_H
