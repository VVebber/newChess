#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Pawn.h"

class King : public Pawn{
public:
    King(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}) : Pawn(p_Sh, p_position, p_TypeFigure, p_TxPawn) {
        position = p_position;
        TypeFigure = p_TypeFigure;

        Sh = p_Sh;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
    }
};

#endif //CHESS_KING_H
