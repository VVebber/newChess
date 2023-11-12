#include <SFML/Graphics.hpp>

//Wondows
#include "window/MainMenu.h"
#include "window/PlayMenu.h"

//Fige
#include "ChessPieces/Pawn.h"
#include "ChessPieces/King.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/Knight.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Rook.h"

#include "GameLogic.h"


void DownTX(std::vector <sf::Texture> &, std::vector <std::string>);

void CreatePawn(std::vector <Pawn> &, int, sf::Texture &);

template<typename T1>
void F_CreadFigure(std::vector <T1> &, std::string ColorPlayr);

int main() {

    sf::RenderWindow win(sf::VideoMode(1280, 960), L"Chess");
    sf::RectangleShape Bekgraund;

    Bekgraund.setSize(sf::Vector2f(1290, 960));

    int Quant_Players = 2;
    int Quant_Pawn = 8, Quant_Knight = 2, Quant_Bishop = 2,
            Quant_Rook = 2, Quant_Queen = 1, Quant_King = 1;

    int NombeFigure = -1;
    int *prt_NombeFigure = &NombeFigure; //идет в функию logic

    bool Play = false;

    bool Press = false;
    bool *ptr_Press = &Press; //идет в функию logic

    bool StrokeLock = true; //идет в функию logic
    bool *ptr_StrokeLock = &StrokeLock;

    bool CreadPlayMenu = false;
    bool *ptr_CreadPlayMenu = &CreadPlayMenu;

    bool CreadFigure = false;
    bool *ptr_CreadFigure = &CreadFigure;

    std::string ColorPlayr;
    std::string *ptr_ColorPlayr = &ColorPlayr;

    std::string Color = "white";
    std::string *ptr_Color = &Color; // идут в функию logic

    std::string TypeFigure;
    std::string *prt_TypeFigure = &TypeFigure;//идет в функию logic


    //Cread and Downlaud TX in vector
    std::vector <std::string> FileNamesBekgr = {"images/background.png"};
    std::vector <sf::Texture> TxBekgraund;
    DownTX(TxBekgraund, FileNamesBekgr);

    std::vector <std::string> FileNamesChessBoard = {"images/ChessBoard/WhiteBlack_1.png",
                                                     "images/ChessBoard/WhiteBlack_2.png"};
    std::vector <sf::Texture> TxChessBoard;
    DownTX(TxChessBoard, FileNamesChessBoard);

    std::vector <sf::Texture> TxPawn;
    std::vector <std::string> FileNamesPaw = {"images/Pawns/WhitePawn.png", "images/Pawns/BlackPawn.png"};
    DownTX(TxPawn, FileNamesPaw);

    std::vector <sf::Texture> TxQueen;
    std::vector <std::string> FileNamesQueens = {"images/Queens/WhiteQueen.png", "images/Queens/BlackQueen.png"};
    DownTX(TxQueen, FileNamesQueens);

    std::vector <sf::Texture> TxKing;
    std::vector <std::string> FileNamesKings = {"images/Kings/WhiteKing.png", "images/Kings/BlackKing.png"};
    DownTX(TxKing, FileNamesKings);

    std::vector <sf::Texture> TxRook;
    std::vector <std::string> FileNamesRooks = {"images/Rooks/WhiteRook.png", "images/Rooks/BlackRook.png"};
    DownTX(TxRook, FileNamesRooks);

    std::vector <sf::Texture> TxKnight;
    std::vector <std::string> FileNamesKnights = {"images/Knights/WhiteKnight.png", "images/Knights/BlackKnight.png"};
    DownTX(TxKnight, FileNamesKnights);

    std::vector <sf::Texture> TxBishop;
    std::vector <std::string> FileNamesBishops = {"images/Bishops/WhiteBishop.png", "images/Bishops/BlackBishop.png"};
    DownTX(TxBishop, FileNamesBishops);

    //Dunlaud TX in Ojeck
    Bekgraund.setTexture(&TxBekgraund[0]);

    //cread button
    MainMenu mainMenu({}, 3, {}); //|0 - textur| 3 - button| 0 - font|
    PlayMenu playMenu({}, 3, {}, TxChessBoard);// 

    mainMenu.CreatBrtMainMenu();

    //cread Figure
    std::vector <Pawn> Pawns;
    for (int i = 0, i_Pw = 0, i_; i < 8; i++) {
        Pawn pawn
        if (i_Pw < Quant_Playr * 1 && Quant_Playrs <= 2) {
            std::string posit = "up";
            pawn(i, posit, "pawn", TxPawn);
        } else if (i_Pw < Quant_Playr * 2 && Quant_Playrs <= 2) {
            std::string posit = "down";
            pawn(i, posit, "pawn", TxPawn);
        }

        Pawns.push_back(pawn);
    }

    while (win.isOpen()) {
        sf::Event event{};

        mainMenu.F_event(event);
        playMenu.F_event(event);

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();


            mainMenu.hover(event);
            playMenu.hover(event);
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    //копирование нажотой позиции в классы 
                    mainMenu.F_mousePositionPres(mousePosition);
                    playMenu.F_mousePositionPres(mousePosition);

                    for (auto &pawn: Pawns)
                        pawn.F_mousePositionPres(mousePosition);
                    for (auto &queen: Queens)
                        queen.F_mousePositionPres(mousePosition);
                    for (auto &king: Kings)
                        king.F_mousePositionPres(mousePosition);
                    for (auto &rook: Rooks)
                        rook.F_mousePositionPres(mousePosition);
                    for (auto &knight: Knights)
                        knight.F_mousePositionPres(mousePosition);
                    for (auto &bishop: Bishops)
                        bishop.F_mousePositionPres(mousePosition);
                    //нажатия
                    mainMenu.PressedMainMenu(win, ptr_CreadPlayMenu);
                    playMenu.PressedPlayMenu(ptr_CreadFigure, ptr_ColorPlayr);
                }
        }
        //создание кнопок в меню PlayMenu
        if (CreadPlayMenu && (mainMenu.Btr.size() == 0)) {
            CreadPlayMenu = false;
            playMenu.CreatBrtPlayMenu();
        }
        // Создание фигур
        if (CreadFigure && (playMenu.Btr.size() == 0)) {
            CreadFigure = false;
            F_CreadFigure(Pawns, ColorPlayr);
            F_CreadFigure(Queens, ColorPlayr);
            F_CreadFigure(Kings, ColorPlayr);
            F_CreadFigure(Rooks, ColorPlayr);
            F_CreadFigure(Knights, ColorPlayr);
            F_CreadFigure(Bishops, ColorPlayr);

            Play = true;
        }


        win.clear();
        win.draw(Bekgraund);

        mainMenu.SpawnBrt(win);
        mainMenu.SpawnText(win);

        playMenu.SpawnBrt(win);
        playMenu.SpawnText(win);
        playMenu.SpawnChessBoard(win);

        for (auto &pawn: Pawns)
            pawn.SpawnPawn(win);

        for (auto &queen: Queens)
            queen.SpawnPawn(win);

        for (auto &king: Kings)
            king.SpawnPawn(win);

        for (auto &rook: Rooks)
            rook.SpawnPawn(win);

        for (auto &knight: Knights)
            knight.SpawnPawn(win);

        for (auto &bishop: Bishops)
            bishop.SpawnPawn(win);

        if (Pawns.size() != 0 && Play) {
            Logic(prt_NombeFigure, prt_TypeFigure, ptr_Press, ptr_Color, ptr_StrokeLock,
                  Pawns, Queens, Kings, Rooks, Bishops, Knights);
        }

        for (auto &pawn: Pawns)
            pawn.SpawnShape(win);

        for (auto &queen: Queens)
            queen.SpawnShape(win);

        for (auto &king: Kings)
            king.SpawnShape(win);

        for (auto &rook: Rooks)
            rook.SpawnShape(win);

        for (auto &knight: Knights)
            knight.SpawnShape(win);

        for (auto &bishop: Bishops)
            bishop.SpawnShape(win);
        win.display();
    }
    return 0;
}




// ФУНКЦИИ

void DownTX(std::vector <sf::Texture> &TxVector, std::vector <std::string> FileNames) {
    for (const auto &fileName: FileNames) {
        sf::Texture Textur;
        if (Textur.loadFromFile(fileName)) {
            TxVector.push_back(Textur);
        }
    }
}

void DownFont(std::vector <sf::Font> &TxVector, std::vector <std::string> FileNames) {
    for (const auto &fileName: FileNames) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            TxVector.push_back(font);
        }
    }
}

template<typename T1>
void F_CreadFigure(std::vector <T1> &figure, std::string ColorPlayr) {
    for (int i = 0; i < figure.size(); i++) {
        if (i < figure.size() / 2)
            figure[i].F_color(ColorPlayr == "white" ? "white" : "black");
        else if (i > figure.size() / 2 - 1 && i < figure.size())
            figure[i].F_color(ColorPlayr == "white" ? "black" : "white");
        figure[i].CredPawn();
    }
}