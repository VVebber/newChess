#ifndef CHESS_GAMELOGIC_H
#define CHESS_GAMELOGIC_H

#include "window/PlayMenu.h"
#include "Figures.h"
#include <iostream>

template <typename T1>
void DownloadFigure(std::vector<T1>& );

template <class T1>
void LogicUp(std::vector<T1>&);

template <class T1>
void LogicUpLeft(std::vector<T1>&);

template <class T1>
void LogicUpRight(std::vector<T1>&);

template <class T1>
void LogicDownLeft(std::vector<T1>&);

template <class T1>
void LogicDownRight(std::vector<T1>&);

template <class T1>
void LogicDown(std::vector<T1>&);

template <typename T1>
void FigureGo(PlayMenu&,std::vector<T1>& , int* , std::string*, bool *, std::string *, bool*,int*);

template <class T1>
void LogicLeft(std::vector<T1>& Figure);

template <class T1>
void LogicRight(std::vector<T1>& Figure);

template <typename T1, typename T2>
void LogicKing(std::vector<T1>&, std::vector<T2>&, bool*);

template <class T1>
void LogicKnights(std::vector<T1>& Figure);
    
template <class T1>
bool ColorShape(Figures figure,std::vector<T1>&, sf::CircleShape&);
void CreadShape(sf::CircleShape&);
void CreadShapeTest(sf::CircleShape&);

template <class T1, class T2>
int Killing(std::vector<T1>&,T2, int, int);

void Logic(int* NombeFigure, std::string* TypeFigure, bool* Press, std::string* Color, bool* StrokeLock,int *MoverCounter,
    std::vector<Figures>& figures, PlayMenu &playMenu) {

    //отчистка shape
    for (auto& figure : figures)
        figure.Moves.clear();

    LogicUp(figures);
    LogicUpLeft(figures);
    LogicUpRight(figures);

    LogicLeft(figures);
    LogicRight(figures);
    LogicDown(figures);
    LogicDownLeft(figures);
    LogicDownRight(figures);
    LogicKnights(figures);
    FigureGo(playMenu, figures, NombeFigure, TypeFigure, Press, Color, StrokeLock,MoverCounter);
}

void CreadShape(sf::CircleShape& Move) {
    Move.setFillColor(sf::Color(124, 252, 0, 0));
    Move.setOutlineThickness(2);
    Move.setOutlineColor(sf::Color(0, 0, 0, 0));
}

void CreadShapeTest(sf::CircleShape& Move) {
    Move.setFillColor(sf::Color(124, 252, 0));
    Move.setOutlineThickness(2);
    Move.setOutlineColor(sf::Color(0, 0, 0));
}

template <class T1>
bool ColorShape(Figures figure, std::vector<T1>& figures, sf::CircleShape& Move) {
    for (int j = 0; j < figures.size(); j++) {
        if (int(Move.getPosition().x) == int(figures[j].Figure.getPosition().x) &&
            int(Move.getPosition().y) == int(figures[j].Figure.getPosition().y)) {
            figure.getPosition_F() == figures[j].getPosition_F() ? Move.setFillColor(sf::Color(173, 255, 47, 0)) :
                                                                   Move.setFillColor(sf::Color(255, 0, 0, 0));
            return true;
        }
    }
    return false;
}

template <class T1>
void LogicUp(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getPosition_F() == "up" && figure.getTypeFigure_F() == "pawn" || 
            figure.getTypeFigure_F() =="knights" || figure.getTypeFigure_F() == "bishops")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x,figure.Figure.getPosition().y - 67.7 * (i + 1));
                    
                if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 558) && i == 1 ||
                    figure.getTypeFigure_F() == "king" && i == 1)
                    break;

                if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 558 && i == 2)
                    break;

                CreadShape(Move);
                Continue = ColorShape(figure,figures, Move);

                if (Move.getPosition().y < 150) {//150 y
                    break;
                }

                if (Continue && figure.getTypeFigure_F() == "pawn") {
                    Continue = false;
                    break;
                }

                figure.Moves.push_back(Move);

                if (Continue) {
                    Continue = false;
                    break;
                }
        }
    }
}

template <class T1>
void LogicUpLeft(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "pawn" || figure.getTypeFigure_F() =="rook" ||
            figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x - 67.7 * (i + 1), figure.Figure.getPosition().y - 67.7 * (i + 1));

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 558) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 558 && i == 2)
                break;



            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().y < 150 || Move.getPosition().x < 100) {//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicUpRight(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "pawn" || figure.getTypeFigure_F() =="rook" ||
            figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x + 67.7 * (i + 1), figure.Figure.getPosition().y - 67.7 * (i + 1));

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 558) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 558 && i == 2)
                break;



            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().y < 150 || Move.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicDown(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getPosition_F() == "down" && figure.getTypeFigure_F() == "pawn" ||
            figure.getTypeFigure_F() == "knights" || figure.getTypeFigure_F() == "bishops")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x, figure.Figure.getPosition().y + 67.7 * (i + 1));

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 220) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 220 && i == 2)
                break;

            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().y > 650) {
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicDownLeft(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "pawn" || figure.getTypeFigure_F() == "rook" ||
        figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x - 67.7 * (i + 1), figure.Figure.getPosition().y + 67.7 * (i + 1));

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 558) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 558 && i == 2)
                break;

            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().y > 650 || Move.getPosition().x < 100){//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicDownRight(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "pawn" || figure.getTypeFigure_F() == "rook" ||
            figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x + 67.7 * (i + 1), figure.Figure.getPosition().y + 67.7 * (i + 1));

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 558) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 558 && i == 2)
                break;



            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().y > 650 || Move.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicLeft(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "bishops" || figure.getTypeFigure_F() == "pawn" ||
            figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x - 67.7 * (i + 1), figure.Figure.getPosition().y);

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 220) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 220 && i == 2)
                break;

            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().x < 100) {//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1>
void LogicRight(std::vector<T1>& figures) {
    for (auto& figure : figures) {
        bool Continue = false;
        if (figure.getTypeFigure_F() == "bishops" || figure.getTypeFigure_F() == "pawn" ||
            figure.getTypeFigure_F() == "knights")
            continue;

        for (int i = 0; i < 8; i++) {
            sf::CircleShape Move(30, 10);
            Move.setPosition(figure.Figure.getPosition().x + 67.7 * (i + 1), figure.Figure.getPosition().y);

            if ((figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) != 220) && i == 1 ||
                figure.getTypeFigure_F() == "king" && i == 1)
                break;

            if (figure.getTypeFigure_F() == "pawn" && int(figure.Figure.getPosition().y) == 220 && i == 2)
                break;

            CreadShape(Move);
            Continue = ColorShape(figure,figures, Move);

            if (Move.getPosition().x > 650) {//150 y
                break;
            }

            if (Continue && figure.getTypeFigure_F() == "pawn") {
                Continue = false;
                break;
            }

            figure.Moves.push_back(Move);

            if (Continue) {
                Continue = false;
                break;
            }
        }
    }
}

template <class T1, class T2>
void LogicKnights(std::vector<T1>& ALLFigure, std::vector<T2>& Figure) {

        for (auto& figure : Figure) {
            if (figure.getTypeFigure_F() != "knights")
                continue;
            bool Continue = false;
            for (int i = 0; i < 8; i++) {
                sf::CircleShape shape(30, 10);
                switch (i)
                {
                case 0: shape.setPosition(figure.Figure.getPosition().x + 67.7 * 2, figure.Figure.getPosition().y + 67.7); break;
                case 1: shape.setPosition(figure.Figurz.getPosition().x + 67.7 * 2, figure.Figure.getPosition().y - 67.7); break;
                case 2: shape.setPosition(figure.Figure.getPosition().x - 67.7 * 2, figure.Figure.getPosition().y + 67.7); break;
                case 3: shape.setPosition(figure.Figure.getPosition().x - 67.7 * 2, figure.Figure.getPosition().y - 67.7); break;
                case 4: shape.setPosition(figure.Figure.getPosition().x + 67.7, figure.Figure.getPosition().y + 67.7 * 2); break;
                case 5: shape.setPosition(figure.Figure.getPosition().x + 67.7, figure.Figure.getPosition().y - 67.7 * 2); break;
                case 6: shape.setPosition(figure.Figure.getPosition().x - 67.7, figure.Figure.getPosition().y + 67.7 * 2); break;
                case 7: shape.setPosition(figure.Figure.getPosition().x - 67.7, figure.Figure.getPosition().y - 67.7 * 2); break;
                }
                CreadShape(shape);
                Continue = ColorShape(figure,Figure, shape);

                if (shape.getPosition().y > 650 || shape.getPosition().x > 665 ||
                    shape.getPosition().y < 150 || shape.getPosition().x < 150) {
                    continue;
                }

                figure.shape.push_back(shape);

                if (Continue) {
                    Continue = false;
                }
            }
        }
    }

template <typename T1>
void FigureGo(PlayMenu &playMenu,std::vector<T1>& figure, int* sh, std::string* TypeFigure, bool* Press, std::string* Color, bool *StrokeLock,int *MoverCounter) {
    int l = -1;
    std::string S = " -> ";
    for (int i = 0; i < figure.size(); i++) {
        if (*Color == figure[i].getColor_F())
            continue;

        if (figure[i].Figure.getGlobalBounds().contains(figure[i].getMousePositionPres())) {
            *sh = i;
            *TypeFigure = figure[i].getTypeFigure_F();
            playMenu.getChessCordStart(playMenu.Cord(figure[*sh]));
            std::cout<<figure[*sh].getColor_F()<<" | "<<figure[*sh].getPosition_F()<<"\n";
            std::cout<<"x="<<figure[*sh].Figure.getPosition().x<<"y="<<figure[*sh].Figure.getPosition().y<<"\n";
            *Press = true;
            break;
        }
    }
    if (*Press)
        if (*TypeFigure == figure[*sh].getTypeFigure_F()) {
            figure[*sh].CreadNewColor();
            for (int i = 0; i < figure[*sh].Moves.size(); i++)
                if (figure[*sh].Moves[i].getGlobalBounds().contains(figure[*sh].getMousePositionPres())) {
                    figure[*sh].Figure.setPosition(figure[*sh].Moves[i].getPosition().x,figure[*sh].Moves[i].getPosition().y);
                    playMenu.getChessCordEnd(S + playMenu.Cord(figure[*sh]));
                    *Press = false;
                    *StrokeLock = true;
                    if (*Color == "white")
                        *Color = "black";
                    else if (*Color == "black")
                        *Color = "white";
                    l = Killing(figure, figure[*sh], i, *sh);
                    playMenu.DownChessCords_txt(*MoverCounter);
                    *MoverCounter += playMenu.setMoverCounter_int();
                }
        }
    if(l != -1)
        figure.erase(figure.begin() + l);
}

template <class T1, class T2>
int  Killing(std::vector<T1>& Figure,T2 figure, int chShape, int chFigure) {
    for (int i = 0; i < Figure.size(); i++) {
        if(i == chFigure)
            continue;
        if (int(figure.Moves[chShape].getPosition().x) == int(Figure[i].Figure.getPosition().x) &&
            int(figure.Moves[chShape].getPosition().y) == int(Figure[i].Figure.getPosition().y))
            return i;
    }
    return -1;
}

template <typename T1, typename T2>
void LogicKing(std::vector<T1>& Figur, std::vector<T2>& AllFigure, bool* StrokeLock) {
    for (auto& king : Figur)
        for (int i = 0; i < AllFigure.size(); i++) {
            if (king.color != AllFigure[i].Color)
                for (int j = 0; j < AllFigure[i].CoordinatesShape.size(); j += 2)
                    if (int(king.Figure.getPosition().x) == int(AllFigure[i].CoordinatesShape[j]) &&
                        int(king.Figure.getPosition().y) == int(AllFigure[i].CoordinatesShape[j + 1]))
                        *StrokeLock = false;
        }
}


#endif //CHESS_GAMELOGIC_H