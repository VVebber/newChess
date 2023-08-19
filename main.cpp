#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <thread>
#include <chrono>
#include <string>

#include "Windows/MainMenu.h"
#include "Windows/Play.h"
#include "Windows/MenuESC.h"
#include "Windows/TypeBoard.h"

#include "Shapes/Pawn.h"
#include "Shapes/Rook.h"
#include "Shapes/Queen.h"
#include "Shapes/King.h"

#include "Logic.h"

    using namespace sf;
    using namespace std;

void FCredVectorFigure(vector<float> WhiteFigure, PawnWhite& pawnWhite, QueenWhite & queenWhite);

int MasChForshapes[20]{0,0,0,0,0,0,0,0,0,0};
string TypeChess = "classic";
string *sTypeChess = &TypeChess;//тип доски
// MasChForshapes[0] - пешки
// MasChForshapes[1] - ладья
// MasChForshapes[9] - Menu
// MasChForshapes[10] - BtrMenu
// MasChForshapes[11] - BtrPlay
// MasChForshapes[12] - Escape
// MasChForshapes[12] - typeBoard

    int main() {
        RenderWindow win;
        win.create(sf::VideoMode(1280, 720), L"Шахматы+", sf::Style::Default);

        vector <Texture> TxBackground;
        vector <string> FileNamesBackground = {"image/Background.jpg"};
        for (const auto &fileName: FileNamesBackground) {
            sf::Texture spam;
            if (spam.loadFromFile(fileName)) {
                TxBackground.push_back(spam);
            }
        }

        vector <Texture> TxButton;
        vector <string> FileNamesBtn = {"image/wood1.jpg", "image/wood2.jpg"};
        for (const auto &fileName: FileNamesBtn) {
            sf::Texture spam;
            if (spam.loadFromFile(fileName)) {
                TxButton.push_back(spam);
            }
        }

        vector <Texture> TxPawn;
        vector <string> FileNamesPaw = {"image/figure/Pawn/BleakPawn.png", "image/figure/Pawn/WhitePawn.png"};
        for (const auto &fileName: FileNamesPaw) {
            sf::Texture spam;
            if (spam.loadFromFile(fileName)) {
                TxPawn.push_back(spam);
            }
        }

        vector<Texture> TxQueen;
        vector<string> FileNamesQueen = {"image/figure/Queen/BleakQueen.png", "image/figure/Queen/WhiteQueen.png"};
        for (const auto &fileName : FileNamesQueen) {
            sf::Texture queenTexture;
            if (queenTexture.loadFromFile(fileName)) {
                TxQueen.push_back(queenTexture);
            }
        }

        std::vector<sf::Texture> TxKing;
        std::vector<std::string> FileNamesKing = {"image/figure/King/BleakKing.png", "image/figure/King/WhiteKing.png"};
        for (const auto &fileName : FileNamesKing) {
            sf::Texture kingTexture;
            if (kingTexture.loadFromFile(fileName)) {
                TxKing.push_back(kingTexture);
            }
        }


        sf::Font arial;
        if (!arial.loadFromFile("Font/Arial/arialmt.ttf")) {
            printf("arial");
            return 0;
        }


        MainMenu BtrMenu(TxButton[0], TxButton[1], arial);
        BtrMenu.CreatBrt(3);
        BtrMenu.CreatTxtMenu();

        Play BtrPlay(TxButton[0], TxButton[1], arial);
        BtrPlay.CreatBrt(4);
        BtrPlay.CredTxtPlay();

        MenuESC BtrESC(TxButton[0], TxButton[1], arial);
        BtrESC.CredBtnESC(3);
        BtrESC.Fboard();
        BtrESC.startESC();

        TypeBoard typeBoard(TxButton[0], TxButton[1], arial);
        typeBoard.CredBackgAndClose();
        typeBoard.CredBtn(12);

        PawnWhite pawnWhite(TypeChess,TxPawn);
        PawnBlack pawnBlack(TypeChess,TxPawn);
        QueenWhite queenWhite(TypeChess,TxQueen);
        QueenBlack queenBlack(TypeChess,TxQueen);

        KingWhite kingWhite(TypeChess,TxKing);
        KingBlack kingBlack(TypeChess,TxKing);

        RectangleShape background;
        background.setSize(Vector2f(1280, 720));
        background.setPosition(0, 0);
        background.setTexture(&TxBackground[0]);

        vector<float> WhiteFigure;
        vector<float> BlackFigure;
        bool CredVectorFigure = true;

        while (win.isOpen()) {
            Event event;

            pawnWhite.Fevent(event);
            pawnBlack.Fevent(event);

            queenWhite.Fevent(event);
            queenBlack.Fevent(event);

            BtrMenu.Fevent(event);
            BtrPlay.Fevent(event);
            typeBoard.Fevent(event);

            while (win.pollEvent(event)) {  //start while event
                if (event.type == Event::Closed)
                    win.close();

                BtrMenu.hover(event);
                BtrPlay.hover(event);

                BtrMenu.PressedMenu(win, MasChForshapes);
                BtrPlay.PressedPlay(win,TypeChess, MasChForshapes);
                typeBoard.PressedType(MasChForshapes, sTypeChess);

                if (event.type == sf::Event::KeyPressed && MasChForshapes[11] != 0) {

                    if (event.key.code == sf::Keyboard::Key::Escape) {
                        MasChForshapes[12] = 1;
                    } else MasChForshapes[12] = 0;
                }

                if (event.type == sf::Event::MouseButtonPressed)
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                        //if (MasChForshapes[12] == 0)
                        pawnWhite.FmousePositionPres(mousePosition);
                        pawnBlack.FmousePositionPres(mousePosition);

                        queenWhite.FmousePositionPres(mousePosition);
                        queenBlack.FmousePositionPres(mousePosition);

                        BtrMenu.FmousePositionPres(mousePosition);
                        BtrPlay.FmousePositionPres(mousePosition);
                        typeBoard.FmousePositionPres(mousePosition);
                        typeBoard.gitTypeChessBoard(sTypeChess);

                        if (BtrESC.MenuESCBtn[2].getGlobalBounds().contains(mousePosition)) {
                            MasChForshapes[12] = 0;
                        }

                        if (BtrESC.MenuESCBtn[2].getGlobalBounds().contains(mousePosition)) {
                            for (int i = 0; i < sizeof(MasChForshapes); i++) {
                                if (i == 10 || i == 9)
                                    continue;
                                MasChForshapes[i] = 0;
                            }
                            CredVectorFigure = true;
                            BtrPlay.btrPlayStar();
                        }

                    }
            } //end while event

            if (CredVectorFigure && MasChForshapes[11] != 0){
                pawnWhite.FTypePawn(TypeChess,MasChForshapes[11]);
                pawnBlack.FTypePawn(TypeChess,MasChForshapes[11]);

                queenWhite.FTypeQueen(TypeChess,MasChForshapes[11]);
                queenBlack.FTypeQueen(TypeChess,MasChForshapes[11]);

                kingWhite.FTypeKing(TypeChess,MasChForshapes[11]);
                kingBlack.FTypeKing(TypeChess,MasChForshapes[11]);

                pawnWhite.CredPawn();
                pawnBlack.CredPawn();

                queenWhite.CredQueen();
                queenBlack.CredQueen();

                kingWhite.CredKing();
                kingBlack.CredKing();

                FCredVectorFigure(WhiteFigure,pawnWhite,queenWhite);
                FCredVectorFigure(BlackFigure,pawnBlack,queenBlack);
                CredVectorFigure = false;
            }

            BtrPlay.TypeBoard(TypeChess);

            win.clear();

            win.draw(background);

            if (!MasChForshapes[9]) //Menu
                BtrMenu.OnMenu(win);
            else if (MasChForshapes[9])
                BtrMenu.OffMenu(win);

            if (MasChForshapes[10] == 1) { // если нажали start
                BtrPlay.OffMenuPlay(win);

                MasChForshapes[11] == 0 ? BtrPlay.OnMenuPlay(win) : BtrPlay.OffMenuPlay(win);
                if (MasChForshapes[12] != 0)
                    BtrESC.menuESC(win);

                MasChForshapes[13] != 0 ? typeBoard.SpawnAll(win) : typeBoard.EndAllPos();
                if (MasChForshapes[11] != 0) {//star game

                    FigureLogic(win,WhiteFigure,BlackFigure,kingWhite, pawnWhite, queenWhite);
                    FigureLogic(win,WhiteFigure,BlackFigure,kingBlack, pawnBlack,queenBlack);
                }

                if (MasChForshapes[12] == 1) //esc
                    BtrESC.menuESC(win);
            }

            win.display();
            //std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    void FCredVectorFigure(vector<float> WhiteFigure, PawnWhite& pawnWhite, QueenWhite& queenWhite){
        WhiteFigure.clear();
        for(auto & spam: pawnWhite.Figure){
            WhiteFigure.push_back(spam.getPosition().y);
            WhiteFigure.push_back(spam.getPosition().x);
        }
        cout<<pawnWhite.color<<"|"<<WhiteFigure.size()<<"\n";
    }

