#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

//Wondows
#include "window/MainMenu.h"
#include "window/PlayMenu.h"
#include "window/Settings.h"

//Fige

#include "GameLogic.h"
#include "Figures.h"


void DownTX(std::vector <sf::Texture> &, std::vector <std::string>);
void DownFont(std::vector <sf::Font> &, std::vector <std::string>);
void F_CreatOject(std::vector<Figures>&,  std::vector <sf::Texture>&,std::string, int, int);

int main() {
    Senttings settings;
#if defined(__ANDROID__)
    settings.setTypeDevise("Android");
#elif defined(SFML_SYSTEM_WINDOWS)
    settings.setTypeDevise("Windows");
#elif defined(SFML_SYSTEM_LINUX)
    settings.setTypeDevise("Linux");
#elif defined(SFML_SYSTEM_MACOS)
    settings.setTypeDevise("macOS");
#else
    settings.setTypeDevise("Unknown OS");
#endif

    sf::RenderWindow win(sf::VideoMode(1280, 960), L"Chess");

    int Quant_Players = 2;
    int NPDGT = 16; // number of pieces depending on game type(кол-во фигур от тира игры классика - 16)
    int Quant_Pawn = 8, Quant_Knight = 2, Quant_Bishop = 2,
            Quant_Rook = 2, Quant_Queen = 1, Quant_King = 1;

    int NombeFigure = -1;
    int *prt_NombeFigure = &NombeFigure; //идет в функию logic

    int MoverCounter = 1;
    int *ptr_MoverCounter = &MoverCounter;

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
    settings.setTxBackground(TxBekgraund);
    settings.CreatBackground();

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

    std::vector<sf::Font> Fonts;
    std::vector<std::string> FileNamesFont = {"Font/Arial/arialmt.ttf"};
    DownFont(Fonts,FileNamesFont);

    //cread button
    MainMenu mainMenu({}, 3, Fonts); //|0 - textur| 3 - button| 0 - font|
    PlayMenu playMenu({}, 4, Fonts, TxChessBoard);//

    mainMenu.getMaxWin(settings.getMaxWinSizeX(),settings.getMaxWinSizeY());
    playMenu.getMaxWin(settings.getMaxWinSizeX(),settings.getMaxWinSizeY());

    mainMenu.CreatBrtMainMenu();

    //cread Figure
    std::vector <Figures> figures;
    F_CreatOject(figures,TxPawn,"pawn",Quant_Players,Quant_Pawn);
    F_CreatOject(figures,TxQueen,"queen",Quant_Players,Quant_Queen);
    F_CreatOject(figures,TxKing,"king",Quant_Players,Quant_King);
    F_CreatOject(figures,TxRook,"rook",Quant_Players,Quant_Rook);
    F_CreatOject(figures,TxKnight,"knights",Quant_Players,Quant_Knight);
    F_CreatOject(figures,TxBishop,"bishops",Quant_Players,Quant_Bishop);


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

                    for (auto &figure: figures)
                        figure.F_mousePositionPres(mousePosition);
                    //нажатия
                    mainMenu.PressedMainMenu(win, ptr_CreadPlayMenu);
                    playMenu.PressedPlayMenu(ptr_PlayLogic, figures);
                }
        }
        //создание кнопок в меню PlayMenu
        if (CreadPlayMenu && (mainMenu.setSizeButtons() == 0)) {
            CreadPlayMenu = false;
            playMenu.CreatMenuPlay();
        }
  
        win.clear();
        win.draw(settings.getBackground());

        mainMenu.WinButton(win);
        playMenu.WinButton(win);
        playMenu.WinMenuPlay(win);

        if (PlayLogic) {
            Logic(prt_NombeFigure, prt_TypeFigure, ptr_Press, ptr_Color, ptr_StrokeLock,ptr_MoverCounter,figures,playMenu);
        }

        for (auto &figure: figures)
            figure.AllWin(win);

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

void DownFont(std::vector <sf::Font> &Fonts, std::vector <std::string> FileNames) {
    for (const auto &fileName: FileNames) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            Fonts.push_back(font);
           }
    }
}

void F_CreatOject(std::vector<Figures> &figures,  std::vector <sf::Texture> &TxFigure,
                  std::string TypeFigure, int Quant_Players, int Quant_Figur){
    for (int i = 0, i_Fi = 0, i_; i < Quant_Figur * Quant_Players; i++) {
        Figures figure{0,"","",{}};
        if (i_Fi < Quant_Figur * 1 && Quant_Players <= 2) {
            std::string posit = "up";
            figure.init(i, posit, TypeFigure, TxFigure);
            i_Fi++;
        } else if (i_Fi < Quant_Figur * 2 && Quant_Players <= 2) {
            std::string posit = "down";
            figure.init(i, posit, TypeFigure, TxFigure);
            i_Fi++;
        }
        figures.push_back(figure);
    }
}
