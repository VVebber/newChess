#ifndef NEWCHESS_FIGURES_H
#define NEWCHESS_FIGURES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Figures{
private:
    float WPowStart = 558.9;
    float BPowStart = 220.4;

    float SizeSquare = 67.7;

    int Sh;

    std::vector <sf::Texture> TxFigure;

    std::string TypeChess = "classic";
    std::string Position = "up";
    std::string Color = "";
    std::string TypeFigure = "pawn";
    std::string MarkOfDeath = "";

    sf::Event event;
    sf::Vector2f MousePositionPres;
    sf::Vector2f MousePositionHover;

public:
    sf::RectangleShape Figure;
    std::vector <sf::CircleShape> Moves;

    Figures(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", std::vector<sf::Texture> p_TxFigure = {}){
        Position = p_position;
        TypeFigure = p_TypeFigure;
        if(p_TypeFigure == "rook" || p_TypeFigure == "bishops" || p_TypeFigure == "knights")
            Sh = p_Sh % 2;
        else Sh = p_Sh % 8;

        for (auto& spam : p_TxFigure)
            TxFigure.push_back(spam);
    }

    void init(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxFigure = {}){
        Position = p_position;
        TypeFigure = p_TypeFigure;

        if (p_TypeFigure == "rook" || p_TypeFigure == "bishops" || p_TypeFigure == "knights")
            Sh = p_Sh % 2;
        else Sh = p_Sh % 8;

        for (auto& spam : p_TxFigure)
            TxFigure.push_back(spam);
    }

    void F_event(sf::Event CL_event) {
        event = CL_event;
    }

    void F_mousePositionPres(sf::Vector2f CL_mousePosition) {
        MousePositionPres = CL_mousePosition;
    }


    std::string getPosition_F() {
        return Position;
    }

    std::string getColor_F() {
        return Color;
    }

    sf::Vector2f getMousePositionPres() {
        return MousePositionPres;
    }

    std::string getTypeFigure_F() {
        return TypeFigure;
    }

    std::string getCord() {
        if (TypeFigure == "pawn") {
            return "p ";
        } else if (TypeFigure == "rook") {
            return "R ";
        } else if (TypeFigure == "knight") {
            return "N ";
        } else if (TypeFigure == "bishop") {
            return "B ";
        } else if (TypeFigure == "queen") {
            return "Q ";
        } else if (TypeFigure == "king") {
            return "K ";
        } else {
            return "0";
        }
    }

    void setPosition_F(std::string newPosition ="") {
        Position = newPosition;
    }

    void setColor(std::string newColor = "") {
        Color = newColor;
    }

    void CredPawn() {
        Figure.setSize(sf::Vector2f(60, 60));
        Figure.setOutlineThickness(1);
        Figure.setOutlineColor(sf::Color(250, 150, 100));

        if (TypeFigure == "pawn")
            Figure.setPosition(56 + 67.7 * (Sh + 1), (Position == "up" ? 85 + 67.7 * 2 : 85 + 67.7 * 7));

        else if (TypeFigure == "queen")
            Figure.setPosition(56 + 67.7 * 4, (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "king")
            Figure.setPosition(56 + 67.7 * 5, (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "rook")
            Figure.setPosition(56 + 67.7 * (Sh == 0 ? 8 : 1), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "knights")
            Figure.setPosition(56 + 67.7 * (Sh == 0 ? 7 : 2), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "bishops")
            Figure.setPosition(56 + 67.7 * (Sh == 0 ? 6 : 3), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        Figure.setTexture(&TxFigure[Color == "white" ? 0 : 1]);
    }

    void AllWin(sf::RenderWindow& win){
        win.draw(Figure);
        if(Moves.size() > 0)
            for(auto mover: Moves)
                win.draw(mover);
    }

    void CreadNewColor() {
        int integer = 100;

        sf::Color Green_1(124, 252, 0, 0);
        sf::Color Green_2(173, 255, 47, 0);
        sf::Color Red_1(255, 0, 0, 0);

        for (auto& mover : Moves) {
            sf::Color currentColor = mover.getFillColor();
            if(currentColor == Green_1)
                mover.setFillColor(sf::Color(124, 252, 0, integer));
            else  if (currentColor == Red_1)
                mover.setFillColor(sf::Color(255, 0, 0, integer));
            else if (currentColor == Green_2)
                mover.setFillColor(sf::Color(173, 255, 47, integer));
            mover.setOutlineColor(sf::Color(0, 0, 0, 255));
        }
    }
};

#endif //NEWCHESS_FIGURES_H
