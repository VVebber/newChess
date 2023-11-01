#ifndef CHESS_Knight_H
#define CHESS_Knight_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Pawn.h"

class Knight : public Pawn {
    /*public:
      std::stirng ="";
      */
public:
    Knight(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}) : Pawn(p_Sh, p_position, p_TypeFigure, p_TxPawn) {
        position = p_position;
        TypeFigure = p_TypeFigure;

        Sh = p_Sh % 2;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
    }
};

#endif 
