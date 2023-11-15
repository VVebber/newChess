#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Pawn{
private:
    float WPowStart = 558.9;
    float BPowStart = 220.4;

    float SizeSquare = 67.7;
    
    int Sh;

    std::vector <sf::Texture> TxPawn;

    std::string TypeChess = "classic";
    std::string Position = "up";
    std::string Color = "";
    std::string TypeFigure = "pawn";
    std::string MarkOfDeath = "";

    sf::Event event;
    sf::Vector2f MousePositionPres;
    sf::Vector2f MousePositionHover;

public:
    std::vector <sf::RectangleShape> Figure;
    std::vector <sf::CircleShape> shape;

    Pawn(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}){
        Position = p_position;
        TypeFigure = p_TypeFigure;
        if(p_TypeFigure == "rook" || p_TypeFigure == "bishops" || p_TypeFigure == "knights")
            Sh = p_Sh % 2;
        else Sh = p_Sh % 8;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
    }

    void init(int p_Sh, const std::string& p_position = "", const std::string& p_TypeFigure = "", const std::vector<sf::Texture>& p_TxPawn = {}){
        Position = p_position;
        TypeFigure = p_TypeFigure;
      
        if (p_TypeFigure == "rook" || p_TypeFigure == "bishops" || p_TypeFigure == "knights")
            Sh = p_Sh % 2;
        else Sh = p_Sh % 8;

        for (auto& spam : p_TxPawn)
            TxPawn.push_back(spam);
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

    void setPosition_F(std::string newPosition ="") {
        Position = newPosition;
    }

    void setColor(std::string newColor = "") {
        Color = newColor;
    }

    void CredPawn() {
        Figure.clear();
        sf::RectangleShape pawn;
        pawn.setSize(sf::Vector2f(60, 60));
        pawn.setOutlineThickness(1);
        pawn.setOutlineColor(sf::Color(250, 150, 100));

        if (TypeFigure == "pawn")
            pawn.setPosition(56 + 67.7 * (Sh + 1), (Position == "up" ? 85 + 67.7 * 2 : 85 + 67.7 * 7));

        else if (TypeFigure == "queen")
            pawn.setPosition(56 + 67.7 * 4, (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "king")
            pawn.setPosition(56 + 67.7 * 5, (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "rook")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 8 : 1), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

                else if (TypeFigure == "knights")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 7 : 2), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        else if (TypeFigure == "bishops")
            pawn.setPosition(56 + 67.7 * (Sh == 0 ? 6 : 3), (Position == "up" ? 85 + 67.7 * 1 : 85 + 67.7 * 8));

        pawn.setTexture(&TxPawn[Color == "white" ? 0 : 1]);
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

        sf::Color Green_1(124, 252, 0, 0);
        sf::Color Green_2(173, 255, 47, 0);
        sf::Color Red_1(255, 0, 0, 0);

        for (auto& Shape : shape) {
            sf::Color currentColor = Shape.getFillColor();
            if(currentColor == Green_1)
                Shape.setFillColor(sf::Color(124, 252, 0, integer));
            else  if (currentColor == Red_1)
                Shape.setFillColor(sf::Color(255, 0, 0, integer));
            else if (currentColor == Green_2)
                Shape.setFillColor(sf::Color(173, 255, 47, integer));
            Shape.setOutlineColor(sf::Color(0, 0, 0, 255));
        }
    }

/*    std::string ChessСoordinates(){
//x =123 y 626 A1  (конда белыми) H8 черными
        std::string result;
        if(Figure[0].get)
        result = (Color == "white") ? "A1" : "H8";
        return result;
    }*/
};
#endif //CHESS_PAWN_H
