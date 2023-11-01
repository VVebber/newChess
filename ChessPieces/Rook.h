#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Pawn.h"

class Rook : public Pawn {
    /*public:
      std::stirng ="";
      */
public:
    Rook(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}) : Pawn(p_Sh, p_position, p_TypeFigure, p_TxPawn) {
        position = p_position;
        TypeFigure = p_TypeFigure;

        Sh = p_Sh % 2;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
    }
};

#endif //CHESS_QUEEN_H
#pragma once
