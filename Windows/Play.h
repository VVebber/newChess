#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Shapes/Pawn.h"
#include "../Shapes/Queen.h"
#include "../Shapes/King.h"

class Play : public MainMenu {
private:
    sf::RectangleShape SelectionBox[8][8];

    sf::Texture BtrWood1;
    sf::Texture BtrWood2;

    sf::Font arial;
    
    float BtnPosition[2] {720,150};
    float ChessBoardPos[2];
    
    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;


public:
    sf::RectangleShape ChessBoardMas[90][90];
    sf::Text FieldNumber[100][2];
    char TypeGame = 'w';

    std::string TypeChess;
    int iL, jL;

public:
    Play( sf::Texture p_BtrWood1, sf::Texture p_BtrWood2, sf::Font p_arial) : MainMenu(p_BtrWood1, p_BtrWood2, p_arial) {
        BtrWood1 = p_BtrWood1;
        BtrWood2 = p_BtrWood2;
        arial = p_arial;
    }

    std::string FTypeChess(std::string typeChess){
        TypeChess = typeChess;
        return TypeChess;
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

    void btrPlayStar() {
        float PositionY = BtnPosition[1];
        for (auto &buttonSch: MenuBtn) {
            buttonSch.setPosition(sf::Vector2f(BtnPosition[0], PositionY));
            PositionY += BtnHeight;
        }
    }

    void TxtPlayStar() {
        float PositionY = BtnPosition[1];
        for (auto &buttonSch: MenuText) {
            buttonSch.setPosition(sf::Vector2f(BtnPosition[0] + 10, PositionY + 10));
            PositionY += BtnHeight;
        }
    }

    void CredTxtPlay() {
        for (int i = 0; i < MenuBtn.size(); i++) {
            sf::Text text;
            text.setFont(arial);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::White);
            switch (i) {
                case 0:
                    text.setString(L"Начать белыми");
                    break;
                case 1:
                    text.setString(L"Начать черными");
                    break;
                case 2:
                    text.setString(L"тип доски");
                    break;
                case 3:
                    text.setString(L"обучение");
                    break;

            }
            MenuText.push_back(text);
        }
        TxtEndPosit();
    }

    void TypeBoard(std::string typeChess) {
        std::string spam = typeChess;
        if (spam == "classic") {
            iL = 8;
            jL = 8;
            ChessBoardPos[0] = 16;
            ChessBoardPos[1] = 85;
        } else if(spam == "mini4x4"){
            iL = 4;
            jL = 4;
        }
    }
    
    void CredChessBoardMas(char symbol){
        double y = 65;

        for (int i = 0; i < iL; i++) {
            double x = 65;

            for (int j = 0; j < jL; j++) {
                ChessBoardMas[i][j].setSize(sf::Vector2f(68, 68));
                ChessBoardMas[i][j].setPosition(15 + y, 84 + x);
                if (symbol == 'w')
                    ChessBoardMas[i][j].setFillColor((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ? sf::Color(105, 105, 105) : sf::Color(255, 239, 213));
                else ChessBoardMas[i][j].setFillColor((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ? sf::Color(255, 239, 213): sf::Color(105, 105, 105));
                x += 67.7;
            }
            y += 67.7;
        }
    }

    void SpawnChessBoard(sf::RenderWindow& win){
        for (int i =0; i< iL;i ++)
            for (int j =0; j< jL;j ++)
                win.draw(ChessBoardMas[i][j]);
    }

    void CredTxTChess(sf::RenderWindow& win,char symbol){
        int a = 49, b = a + iL - 1;
        for (int i = 0; i < iL; i++) {
            FieldNumber[i][0].setFont(arial);
            FieldNumber[i][0].setCharacterSize(40);
            FieldNumber[i][0].setFillColor(sf::Color(255, 255, 255));
            FieldNumber[i][0].setPosition(50,150 + 70 * i);
            char sp;
            symbol == 'w' ? sp = char(b - i) : sp = char(a + i);
            FieldNumber[i][0].setString(sp);
        }
        a = 65; b = a + iL - 1;
        for (int i = 0; i < iL; i++) {
            FieldNumber[i][1].setFont(arial);
            FieldNumber[i][1].setCharacterSize(40);
            FieldNumber[i][1].setFillColor(sf::Color(255, 255, 255) );
            FieldNumber[i][1].setPosition(95 + 70 * i,100);
            char sp;
            symbol == 'w' ? sp = char(a + i) : sp = char(b - i);
            FieldNumber[i][1].setString(sp);
        }
    }

    void SpawnTxTChess(sf::RenderWindow& win){
     for (int i = 0; i < 2; i++)
         for (int j = 0; j < iL; j++)
             win.draw( FieldNumber[j][i]);
    }

    void PressedPlay(sf::RenderWindow& win,std::string TypeBoard,int *mas) {
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (MenuBtn[0].getGlobalBounds().contains(mousePositionPres) && mas[13] == 0)/*PlayMenu*/
                    if (mas[11] == 0) {
                        mas[11] = 1;
                        btrEndPosit();
                        CredChessBoardMas('w');
                        CredTxTChess(win, 'w');
                        TypeGame = 'w';
                    }

                if (MenuBtn[1].getGlobalBounds().contains(mousePositionPres) && mas[13] == 0)/*PlayMenu*/
                    if (mas[11] == 0) {
                        mas[11] = 2;
                        btrEndPosit();
                        CredChessBoardMas('b');
                        CredTxTChess(win, 'b');
                        TypeGame = 'b';
                    }

                if (MenuBtn[2].getGlobalBounds().contains(mousePositionPres))/*PlayMenu*/
                    mas[13] = 1;
            }
    }

    void EndFieldNumber() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 20; j++)
                FieldNumber[j][i].setPosition(9000, 0);
    }

    void OnMenuPlay(sf::RenderWindow& win){
        btrPlayStar();
        TxtPlayStar();
        EndFieldNumber();
        SpawnBrt(win);
        SpawnTxt(win);
        CredChessBoardMas(TypeGame);
        SpawnChessBoard(win);
    }

    void OffMenuPlay(sf::RenderWindow& win){
        btrEndPosit();
        TxtEndPosit();
        SpawnChessBoard(win);
        SpawnTxTChess(win);

    }


};



#endif // CHESS_PLAY_H
