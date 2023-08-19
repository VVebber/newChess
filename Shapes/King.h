//
// Created by Danil Malyshev on 19.07.2023.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Shapes/Pawn.h"

class PawnWhite;

class KingWhite : public PawnWhite {
public:
    float WPowStart = 558.9;
    float BPowStart = 220.4;
    int StarKing[2][2] = {7, 2};
    int quantity;

    std::string TypeFigure = "King";

    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

public:
    KingWhite (std::string p_TypeChess, std::vector <sf::Texture> &p_TxPawn): PawnWhite(p_TypeChess,p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }

    void  FTypeKing(std::string LTypeChess,int a) {
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
            quantity = 2;
            StarKing[0][0] = 8; StarKing[0][1] = 1;
            StarKing[1][0] = 3; StarKing[1][1] = 3;
        } else if (TypeChess == "mini4x4"){
            quantity = 2;
            StarKing[0][0] = 4; StarKing[0][1] = 1;
            StarKing[1][0] = 3; StarKing[1][1] = 3;
        }
        TypeFigure = "king";
        color = "white";
    }

    void CredKing() {
        Figure.clear();
        for (int i = 0, j = 0; i < 1; i++) {
            sf::RectangleShape Pawn2;
            Pawn2.setSize(sf::Vector2f(60, 60));
            Pawn2.setOutlineThickness(1);
            Pawn2.setOutlineColor(sf::Color(250, 150, 100));
                Pawn2.setPosition(16 + 67.7 * (StarKing[1][0] + 1), 85 + 67.7 * StarKing[0][0]);
                Pawn2.setTexture(TypeColor == 1 ? &TxPawn[1] :&TxPawn[0]);

            Figure.push_back(Pawn2);
        }
    }


};

class KingBlack : public KingWhite{
public:
    KingBlack (std::string p_TypeChess, std::vector <sf::Texture> &p_TxPawn): KingWhite(p_TypeChess,p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }

    void  FTypeKing(std::string LTypeChess,int a) {
        a == 1 ? a = 0: a = 1;
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
            quantity = 2;
            StarKing[0][0] = 1; StarKing[0][1] = 1;
            StarKing[1][0] = 3; StarKing[1][1] = 3;
        } else if (TypeChess == "mini4x4"){
            quantity = 2;
            StarKing[0][0] = 1; StarKing[0][1] = 1;
            StarKing[1][0] = 3; StarKing[1][1] = 3;
        }
        TypeFigure = "king";
        color = "black";
    }

};
#endif //CHESS_KING_H
