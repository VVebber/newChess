#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Shapes/Pawn.h"

class PawnWhite;

class QueenWhite:  public PawnWhite {
public:
    float WPowStart = 558.9;
    float BPowStart = 220.4;
    int StarQueen[2][2] = {7, 2};
    int quantity;

    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

public:
    QueenWhite (std::string p_TypeChess, std::vector <sf::Texture> &p_TxPawn): PawnWhite(p_TypeChess,p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }

    void  FTypeQueen(std::string LTypeChess,int a) {
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
            quantity = 2;
            StarQueen[0][0] = 8; StarQueen[0][1] = 1;
            StarQueen[1][0] = 4; StarQueen[1][1] = 4;
        } else if (TypeChess == "mini4x4"){
            quantity = 2;
            StarQueen[0][0] = 4; StarQueen[0][1] = 1;
            StarQueen[1][0] = 2; StarQueen[1][1] = 2;
        }
        TypeFigure = "queen";
        color = "white";
    }

    void CredQueen() {
        Figure.clear();
        for (int i = 0, j = 0; i < quantity; i++) {
            sf::RectangleShape Pawn2;
            Pawn2.setSize(sf::Vector2f(60, 60));
            Pawn2.setOutlineThickness(1);
            Pawn2.setOutlineColor(sf::Color(250, 150, 100));
            Pawn2.setPosition(16 + 67.7 * (StarQueen[1][0] + 1), 85 + 67.7 * StarQueen[0][0]);
            Pawn2.setTexture(TypeColor == 1 ? &TxPawn[1] :&TxPawn[0]);
            Figure.push_back(Pawn2);
        }
        //[10].setPosition(16 + 67.7 * 3, 85 + 67.7 * 5);
    }


};

class QueenBlack : public QueenWhite{
public:
    QueenBlack (std::string p_TypeChess, std::vector <sf::Texture> &p_TxPawn): QueenWhite(p_TypeChess,p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }

    void  FTypeQueen(std::string LTypeChess,int a) {
        a == 1 ? a = 0: a = 1;
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
            quantity = 2;
            StarQueen[0][0] = 1; StarQueen[0][1] = 1;
            StarQueen[1][0] = 4; StarQueen[1][1] = 4;
        } else if (TypeChess == "mini4x4"){
            quantity = 2;
            StarQueen[0][0] = 1; StarQueen[0][1] = 1;
            StarQueen[1][0] = 2; StarQueen[1][1] = 2;
        }
        TypeFigure = "queen";
        color = "bleak";
    }
};
#endif //CHESS_QUEEN_H
