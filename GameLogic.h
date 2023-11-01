#ifndef CHESS_GAMELOGIC_H
#define CHESS_GAMELOGIC_H

#include "ChessPieces/Pawn.h"
#include "ChessPieces/King.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/Knight.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Rook.h"
#include <iostream>

struct KillFigure {
    std::string Color = "";
    std::string TypeFigure = "";
    std::vector<float> CoordinatesFigure;

    void down(std::string* p_Color, float x, float y) {
        Color = *p_Color;
        CoordinatesFigure.push_back(x);
        CoordinatesFigure.push_back(y);
    }
};

template <typename T1, typename T2>
void DownloadFigure(std::vector<T1>& , std::vector<T2>& );

template <class T1, class T2>
void LogicUp(std::vector<T1>&, std::vector<T2>&);

template <class T1, class T2>
void LogicUpLeft(std::vector<T1>&, std::vector<T2>&);

template <class T1, class T2>
void LogicUpRight(std::vector<T1>&, std::vector<T2>&);

template <class T1, class T2>
void LogicDownLeft(std::vector<T1>&, std::vector<T2>&);

template <class T1, class T2>
void LogicDownRight(std::vector<T1>&, std::vector<T2>&);

template <class T1, class T2>
void LogicDown(std::vector<T1>&, std::vector<T2>&);

template <typename T1>
void FigureGo(std::vector<T1>& , int* , std::string*, bool *, std::string *, KillFigure&, bool*);

template <class T1, class T2>
void LogicLeft(std::vector<T1>& ALLFigure, std::vector<T2>& Figure);

template <class T1, class T2>
void LogicRight(std::vector<T1>& ALLFigure, std::vector<T2>& Figure);

template <typename T1, typename T2>
void LogicKing(std::vector<T1>&, std::vector<T2>&, bool*);

template <class T1, class T2>
void LogicKnights(std::vector<T1>& ALLFigure, std::vector<T2>& Figure);

template <class T1>
void killing(std::vector<T1>& Figure, KillFigure kill);
    
void CreadShape(sf::CircleShape&);
void CreadShapeTest(sf::CircleShape&);


struct ALLFigure {
    std::string Position = "";    //up or down
    std::string Color = "";       // white or black
    std::string TypeFigure = "";  //тип фигруры

    std::vector<float> CoordinatesFigure;  // кординаты фигуры. не чет x, чет y
    std::vector<float> CoordinatesShape;   // кординаты все ходов. не чет x, чет y

    const float SizeSquare = 67.7; //размер поля

    int MasCord[2] = { 0,0 };   // пока не ястно(забыл)

    ALLFigure(std::string p_position = "", std::string p_color = "", std::string p_TypeFigure = "",
        std::vector<float> p_CoordinatesFigure = {}, std::vector<float> p_CoordinatesShape = {}) {
        Position = p_position;
        Color = p_color;
        TypeFigure = p_TypeFigure;

        for (auto& coordinatesFigure : p_CoordinatesFigure)
            CoordinatesFigure.push_back(coordinatesFigure);

        for (auto& coordinatesShape : p_CoordinatesShape)
            CoordinatesShape.push_back(coordinatesShape);
    }
};


void Logic(int* NombeFigure, std::string* TypeFigure, bool* Press, std::string* Color, bool* StrokeLock,
    std::vector<Pawn>& Pawns, std::vector<Queen>& Queens, std::vector<King>& Kings,
    std::vector<Rook>& Rooks, std::vector<Bishop>& Bishops, std::vector<Knight>& Knights) {
    
    KillFigure killFigure;
    std::vector<ALLFigure> AllFigur;
    AllFigur.clear();
    //отчистка shape
    for (auto& pawn : Pawns)
        pawn.shape.clear();

    for (auto& queen : Queens)
        queen.shape.clear();

    for (auto& king : Kings)
        king.shape.clear();

    for (auto& rook : Rooks)
        rook.shape.clear();
    
    for (auto& bishop : Bishops)
        bishop.shape.clear();

    for (auto& knights : Knights)
        knights.shape.clear();



    DownloadFigure(Pawns, AllFigur);
    DownloadFigure(Queens, AllFigur);
    DownloadFigure(Kings, AllFigur);
    DownloadFigure(Rooks, AllFigur);
    DownloadFigure(Knights, AllFigur);
    DownloadFigure(Bishops, AllFigur);

    LogicUp(AllFigur, Pawns);
    LogicUp(AllFigur, Queens);
    LogicUp(AllFigur, Kings);
    LogicUp(AllFigur, Rooks);

    LogicUpLeft(AllFigur, Queens);
    LogicUpLeft(AllFigur, Bishops);
    LogicUpLeft(AllFigur, Kings);
    LogicUpRight(AllFigur, Queens);
    LogicUpRight(AllFigur, Bishops);
    LogicUpRight(AllFigur, Kings);

    LogicDown(AllFigur, Pawns);
    LogicDown(AllFigur, Queens);
    LogicDown(AllFigur, Kings);
    LogicDown(AllFigur, Rooks);

    LogicDownLeft(AllFigur, Queens);
    LogicDownLeft(AllFigur, Bishops);
    LogicDownLeft(AllFigur, Kings);
    LogicDownRight(AllFigur, Queens);
    LogicDownRight(AllFigur, Bishops);
    LogicDownRight(AllFigur, Kings);

    LogicLeft(AllFigur, Queens);
    LogicLeft(AllFigur, Kings);
    LogicLeft(AllFigur, Rooks);

    LogicRight(AllFigur, Queens);
    LogicRight(AllFigur, Kings);
    LogicRight(AllFigur, Rooks);

    LogicKnights(AllFigur, Knights);

    AllFigur.clear();
    DownloadFigure(Pawns, AllFigur);
    DownloadFigure(Queens, AllFigur);
    DownloadFigure(Kings, AllFigur);
    DownloadFigure(Rooks, AllFigur);
    DownloadFigure(Knights, AllFigur);
    DownloadFigure(Bishops, AllFigur);

    FigureGo(Bishops, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    FigureGo(Pawns, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    FigureGo(Queens, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    FigureGo(Kings, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    FigureGo(Rooks, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    FigureGo(Knights, NombeFigure, TypeFigure, Press, Color, killFigure, StrokeLock);
    
    killing(Pawns, killFigure);
    killing(Queens, killFigure);
    killing(Rooks, killFigure);
    killing(Knights, killFigure);
    killing(Bishops, killFigure);
    killing(Knights, killFigure);

    LogicKing(Kings, AllFigur, StrokeLock);
}

template <class T1, class T2>
void LogicUp(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "up" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x,figure.Figure[0].getPosition().y - 67.7 * (i + 1));
                    
                if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 558) && i == 1 ||
                    figure.TypeFigure == "king" && i == 1)
                    break;

                if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 558 && i == 2)
                    break;



                CreadShape(shape);
                for (int j = 0; j < ALLFigure.size(); j++) {
                    if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                        int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                        ALLFigure[j].Position == "up") {
                        shape.setFillColor(sf::Color(255, 0, 0, 0));
                        Continue = true;
                    }
                    if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                        int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                        ALLFigure[j].Position == "down") {
                        shape.setFillColor(sf::Color(0, 255, 255, 0));
                        Continue = true;
                    }
                }

                if (shape.getPosition().y < 150) {//150 y
                    break;
                }

                if (Continue && figure.TypeFigure == "pawn") {
                    Continue = false;
                    break;
                }

                figure.shape.push_back(shape);

                if (Continue) {
                    Continue = false;
                    break;
                }
        }
    }
}

template <class T1, class T2>
void LogicUpLeft(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "up" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x - 67.7 * (i + 1), figure.Figure[0].getPosition().y - 67.7 * (i + 1));

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 558) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 558 && i == 2)
                break;



            CreadShape(shape);
            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().y < 150 || shape.getPosition().x < 100) {//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicUpRight(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "up" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x + 67.7 * (i + 1), figure.Figure[0].getPosition().y - 67.7 * (i + 1));

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 558) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 558 && i == 2)
                break;



            CreadShape(shape);
            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().y < 150 || shape.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicDown(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "down" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x, figure.Figure[0].getPosition().y + 67.7 * (i + 1));

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 220) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 220 && i == 2)
                break;

            CreadShape(shape);

            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().y > 650) {
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicDownLeft(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "up" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x - 67.7 * (i + 1), figure.Figure[0].getPosition().y + 67.7 * (i + 1));

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 558) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 558 && i == 2)
                break;



            CreadShape(shape);
            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }
            
            if (shape.getPosition().y > 650 || shape.getPosition().x < 100){//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicDownRight(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "up" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x + 67.7 * (i + 1), figure.Figure[0].getPosition().y + 67.7 * (i + 1));

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 558) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 558 && i == 2)
                break;



            CreadShape(shape);
            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().y > 650 || shape.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicLeft(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "down" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x - 67.7 * (i + 1), figure.Figure[0].getPosition().y);

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 220) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 220 && i == 2)
                break;

            CreadShape(shape);

            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().x < 100) {//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicRight(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
    for (auto& figure : Figure) {
        bool Continue = false;
        if (figure.position == "down" && figure.TypeFigure == "pawn")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape shape(30, 10);
            shape.setPosition(figure.Figure[0].getPosition().x + 67.7 * (i + 1), figure.Figure[0].getPosition().y);

            if ((figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) != 220) && i == 1 ||
                figure.TypeFigure == "king" && i == 1)
                break;

            if (figure.TypeFigure == "pawn" && int(figure.Figure[0].getPosition().y) == 220 && i == 2)
                break;

            CreadShape(shape);

            for (int j = 0; j < ALLFigure.size(); j++) {
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "up") {
                    shape.setFillColor(sf::Color(255, 0, 0, 0));
                    Continue = true;
                }
                if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                    int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                    ALLFigure[j].Position == "down") {
                    shape.setFillColor(sf::Color(0, 255, 255, 0));
                    Continue = true;
                }
            }

            if (shape.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.TypeFigure == "pawn") {
                Continue = false;
                break;
            }

            figure.shape.push_back(shape);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

void CreadShape(sf::CircleShape& shape) {
    shape.setFillColor(sf::Color(124, 252, 0, 0));
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(0, 0, 0, 0));
}

void CreadShapeTest(sf::CircleShape& shape) {
    shape.setFillColor(sf::Color(124, 252, 0));
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(0, 0, 0));
}
template <class T1>
void killing(std::vector<T1>& Figure, KillFigure kill) {
    for (auto& dead : Figure) {
        if (kill.Color != dead.color)
            continue;
        if (kill.Color == dead.color && (int(kill.CoordinatesFigure[0]) == int(dead.Figure[0].getPosition().x)
            && int(kill.CoordinatesFigure[1]) == int(dead.Figure[0].getPosition().y))) {
            dead.Figure[0].setPosition(0,0);
            dead.MarkOfDeath == "dead";
        }
    }
}

template <typename T1, typename T2>
void DownloadFigure(std::vector<T1>& Figur, std::vector<T2>& AllFigure) {
    std::string position = "";
    std::string color = "";
    std::string TypeFigure = "";

    std::vector<float> CoordinatesFigure;
    std::vector<float> CoordinatesShape;

    float x1 = 0, y1 = 0;
    float x2 = 0, y2 = 0;
    for (auto& figure : Figur) {
        if (figure.MarkOfDeath == "dead")
            continue;
        CoordinatesFigure.clear();
        CoordinatesShape.clear();

        position = figure.position;
        color = figure.color;
        TypeFigure = figure.TypeFigure;
        x1 = figure.Figure[0].getPosition().x;
        y1 = figure.Figure[0].getPosition().y;
        CoordinatesFigure.push_back(x1);
        CoordinatesFigure.push_back(y1);
        if (figure.shape.size() != 0)
            for (auto& Shape : figure.shape) {
                x2 = Shape.getPosition().x;
                y2 = Shape.getPosition().y;
                CoordinatesShape.push_back(x2);
                CoordinatesShape.push_back(y2);
            }
        ALLFigure Al(position, color, TypeFigure, CoordinatesFigure, CoordinatesShape);
        AllFigure.push_back(Al);
    }
}

template <typename T1>
void FigureGo(std::vector<T1>& figure, int* sh, std::string* TypeFigure, bool* Press, std::string* Color, KillFigure& kill, bool *StrokeLock) {
    std::string LocalTypeFigure;
    if (figure[0].TypeFigure == "king" || *StrokeLock)
        std::cout;
    else return;

    if (figure.size() != 0)
        LocalTypeFigure = figure[0].TypeFigure;
    else return;

    for (int i = 0; i < figure.size(); i++) {
        if (*Color == figure[i].color)
            continue;

        if (figure[i].Figure[0].getGlobalBounds().contains(figure[i].mousePositionPres)) {
            *sh = i;
            *TypeFigure = figure[i].TypeFigure;
            *Press = true;

            break;
        }
    }
    if (*Press) {
        if (*TypeFigure == LocalTypeFigure) {
            figure[*sh].CreadNewColor();
            for (int i = 0; i < figure[*sh].shape.size(); i++)
                if (figure[*sh].shape[i].getGlobalBounds().contains(figure[*sh].mousePositionPres)) {
                    figure[*sh].Figure[0].setPosition(figure[*sh].shape[i].getPosition().x, figure[*sh].shape[i].getPosition().y);
                    *Press = false;
                    *StrokeLock = true;
                    kill.down(Color, figure[*sh].shape[i].getPosition().x, figure[*sh].shape[i].getPosition().y);

                    if (*Color == "white")
                        *Color = "black";
                    else if (*Color == "black")
                        *Color = "white";

                }
        }
    }
}

template <class T1, class T2>
void LogicKnights(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {
   
    if (Figure[0].TypeFigure == "knights") {
        for (auto& figure : Figure) {
            bool Continue = false;
            for (int i = 0; i < 8; i++) {
                sf::CircleShape shape(30, 10);
                switch (i)
                {
                case 0: shape.setPosition(figure.Figure[0].getPosition().x + 67.7 * 2, figure.Figure[0].getPosition().y + 67.7); break;
                case 1: shape.setPosition(figure.Figure[0].getPosition().x + 67.7 * 2, figure.Figure[0].getPosition().y - 67.7); break;
                case 2: shape.setPosition(figure.Figure[0].getPosition().x - 67.7 * 2, figure.Figure[0].getPosition().y + 67.7); break;
                case 3: shape.setPosition(figure.Figure[0].getPosition().x - 67.7 * 2, figure.Figure[0].getPosition().y - 67.7); break;
                case 4: shape.setPosition(figure.Figure[0].getPosition().x + 67.7, figure.Figure[0].getPosition().y + 67.7 * 2); break;
                case 5: shape.setPosition(figure.Figure[0].getPosition().x + 67.7, figure.Figure[0].getPosition().y - 67.7 * 2); break;
                case 6: shape.setPosition(figure.Figure[0].getPosition().x - 67.7, figure.Figure[0].getPosition().y + 67.7 * 2); break;
                case 7: shape.setPosition(figure.Figure[0].getPosition().x - 67.7, figure.Figure[0].getPosition().y - 67.7 * 2); break;
                }
                CreadShape(shape);

                for (int j = 0; j < ALLFigure.size(); j++) {
                    if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                        int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                        ALLFigure[j].Position == "up") {
                        shape.setFillColor(sf::Color(255, 0, 0, 0));
                    }
                    if (int(shape.getPosition().x) == int(ALLFigure[j].CoordinatesFigure[0]) &&
                        int(shape.getPosition().y) == int(ALLFigure[j].CoordinatesFigure[1]) &&
                        ALLFigure[j].Position == "down") {
                        shape.setFillColor(sf::Color(0, 255, 255, 0));
                    }
                }
                if (shape.getPosition().y > 650 || shape.getPosition().x > 665 ||
                    shape.getPosition().y < 150 || shape.getPosition().x < 150) {
                    continue;
                }

                figure.shape.push_back(shape);

                if (Continue) {
                    Continue = false;
                    break;
                }
            }
        }
    }
} 

template <typename T1, typename T2>
void LogicKing(std::vector<T1>& Figur, std::vector<T2>& AllFigure, bool* StrokeLock) {
    for (auto& king : Figur)
        for (int i = 0; i < AllFigure.size(); i++) {
            if (king.color != AllFigure[i].Color)
                for (int j = 0; j < AllFigure[i].CoordinatesShape.size(); j += 2)
                    if (int(king.Figure[0].getPosition().x) == int(AllFigure[i].CoordinatesShape[j]) &&
                        int(king.Figure[0].getPosition().y) == int(AllFigure[i].CoordinatesShape[j + 1]))
                        *StrokeLock = false;
        }

}
#endif //CHESS_GAMELOGIC_H


