#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Pawn{
public:
    float WPowStart = 558.9;
    float BPowStart = 220.4;

    const float SizeSquare = 67.7;
    
    int Sh;

    std::vector <sf::RectangleShape> Figure;
    std::vector <sf::CircleShape> shape;
    std::vector <sf::Texture> TxPawn;

    std::string TypeChess = "classic";
    std::string position = "up";
    std::string color = "";
    std::string TypeFigure = "pawn";
    std::string MarkOfDeath = "";

    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

public:
    Pawn(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}){
        position = p_position;
        TypeFigure = p_TypeFigure;

        Sh = p_Sh % 8;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
    }

    void F_event(sf::Event CL_event) {
        event = CL_event;
    }

    void F_mousePositionPres(sf::Vector2f CL_mousePosition) {
        mousePositionPres = CL_mousePosition;
    }

    void F_color(std::string Cl_color) {
        color = Cl_color;
    }

    void CredPawn() {
        Figure.clear();
        sf::RectangleShape pawn;
        pawn.setSize(sf::Vector2f(60, 60));
        pawn.setOutlineThickness(1);
        pawn.setOutlineColor(sf::Color(250, 150, 100));
       
        if (TypeFigure == "pawn")
            pawn.setPosition(56 + 67.7 * (Sh + 1), (position == "up" ? 85 + 67.7 * 2 : 85 + 67.7 * 7));
        
        else if (TypeFigure == "queen")
            pawn.setPosition(56 + 67.7 * 4, (position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));
       
        else if (TypeFigure == "king")
            pawn.setPosition(56 + 67.7 * 5, (position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));
        
        else if (TypeFigure == "rook")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 8 : 1), (position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));
        
        else if (TypeFigure == "knights")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 7 : 2), (position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));
       
        else if (TypeFigure == "bishops")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 6 : 3), (position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        pawn.setTexture(&TxPawn[color == "white" ? 1 : 0]);
        std::cout;
        Figure.push_back(pawn);
    }

    void SpawnPawn(sf::RenderWindow &win){
        for( auto &spam : Figure)
            win.draw(spam);
    }

    void SpawnShape(sf::RenderWindow &win){
        for( auto &spam : shape)
            win.draw(spam);
    }

    void CreadNewColor() {
        int integer = 100;

        sf::Color Grin(124, 252, 0, 0);
        sf::Color Red(255, 0, 0, 0);
        sf::Color Aqua(0, 255, 255, 0);

        for (auto& Shape : shape) {
            sf::Color currentColor = Shape.getFillColor();
            if(currentColor == Grin)
                Shape.setFillColor(sf::Color(124, 252, 0, integer));
            else  if (currentColor == Red)
                Shape.setFillColor(sf::Color(255, 0, 0, integer));
            else  if(currentColor == Aqua)
                Shape.setFillColor(sf::Color(0, 255, 255, integer));

            Shape.setOutlineColor(sf::Color(0, 0, 0, 255));
        }
    }
};
#endif //CHESS_PAWN_H
