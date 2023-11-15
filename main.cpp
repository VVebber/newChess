#include <SFML/Graphics.hpp>

//Wondows
#include "window/MainMenu.h"
#include "window/PlayMenu.h"

//Fige
#include "ChessPieces/Pawn.h"

#include "GameLogic.h"


void DownTX(std::vector <sf::Texture> &, std::vector <std::string>);

void CreatePawn(std::vector <Pawn> &, int, sf::Texture &);

void F_CreatOject(std::vector<Pawn>&,  std::vector <sf::Texture>&,std::string, int, int);

int main() {

    sf::RenderWindow win(sf::VideoMode(1280, 960), L"Chess");
    sf::RectangleShape Bekgraund;

    Bekgraund.setSize(sf::Vector2f(1290, 960));

    int Quant_Players = 2;
    int NPDGT = 16; // number of pieces depending on game type(кол-во фигур от тира игры классика - 16)
    int Quant_Pawn = 8, Quant_Knight = 2, Quant_Bishop = 2,
            Quant_Rook = 2, Quant_Queen = 1, Quant_King = 1;

    int NombeFigure = -1;
    int *prt_NombeFigure = &NombeFigure; //идет в функию logic

    bool Press = false;
    bool *ptr_Press = &Press; //идет в функию logic

    bool StrokeLock = true; //идет в функию logic
    bool *ptr_StrokeLock = &StrokeLock;

    bool CreadPlayMenu = false;
    bool *ptr_CreadPlayMenu = &CreadPlayMenu;

    bool PlayLogic = false;
    bool *ptr_PlayLogic = &PlayLogic;

    std::string Color = "black";
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
    F_CreatOject(Pawns,TxPawn,"pawn",Quant_Players,Quant_Pawn);
    F_CreatOject(Pawns,TxQueen,"queen",Quant_Players,Quant_Queen);
    F_CreatOject(Pawns,TxKing,"king",Quant_Players,Quant_King);
    F_CreatOject(Pawns,TxRook,"rook",Quant_Players,Quant_Rook);
    F_CreatOject(Pawns,TxKnight,"knights",Quant_Players,Quant_Knight);
    F_CreatOject(Pawns,TxBishop,"bishops",Quant_Players,Quant_Bishop);

    std::cout<<"\n2|"<<Pawns.size();

    while (win.isOpen()) {
        sf::Event event{};

        mainMenu.getEvent(event);
        playMenu.getEvent(event);

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();


            mainMenu.hover(event);
            playMenu.hover(event);
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    //копирование нажотой позиции в классы 
                    mainMenu.getMousePositionPres(mousePosition);
                    playMenu.getMousePositionPres(mousePosition);

                    for (auto &pawn: Pawns)
                        pawn.F_mousePositionPres(mousePosition);
                    //нажатия
                    mainMenu.PressedMainMenu(win, ptr_CreadPlayMenu);
                    playMenu.PressedPlayMenu(ptr_PlayLogic, Pawns);
                }
        }
        //создание кнопок в меню PlayMenu
        if (CreadPlayMenu && (mainMenu.setSizeButtons() == 0)) {
            CreadPlayMenu = false;
            playMenu.CreatBrtPlayMenu();
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




        if (PlayLogic) {
            Logic(prt_NombeFigure, prt_TypeFigure, ptr_Press, ptr_Color, ptr_StrokeLock,Pawns);
        }


        for (auto &pawn: Pawns)
            pawn.SpawnShape(win);
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

void F_CreatOject(std::vector<Pawn> &Pawns,  std::vector <sf::Texture> &TxFigure,
                  std::string TypeFigure, int Quant_Players, int Quant_Figur){
    for (int i = 0, i_Fi = 0, i_; i < Quant_Figur * Quant_Players; i++) {
        Pawn pawn{0,"","",{}};
        if (i_Fi < Quant_Figur * 1 && Quant_Players <= 2) {
            std::string posit = "up";
            pawn.init(i, posit, TypeFigure, TxFigure);
            i_Fi++;
        } else if (i_Fi < Quant_Figur * 2 && Quant_Players <= 2) {
            std::string posit = "down";
            pawn.init(i, posit, TypeFigure, TxFigure);
            i_Fi++;
        }
        Pawns.push_back(pawn);
    }
    std::cout<<"\n|"<<Quant_Figur * Quant_Players;
}
