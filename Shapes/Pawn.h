#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class PawnWhite {
public:
    float WPowStart = 558.9;
    float BPowStart = 220.4;
    int StarGame = 7;

    int quantity; //номер пешки(фигуры)
    int SelectedFigure;
    int TypeColor;
    const float SizeSquare = 67.7;
    std::vector <sf::RectangleShape> Figure;
    std::vector <sf::CircleShape> shape;
    std::vector <sf::Texture> TxPawn;

    std::string TypeChess;
    std::string color = "white";
    std::string TypeFigure = "pawn";

    sf::Event event;
    sf::Vector2f mousePositionPres;
    sf::Vector2f mousePositionHover;

public:
    PawnWhite (std::string p_TypeChess, std::vector<sf::Texture>& p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }

    void  FTypePawn(std::string LTypeChess,int a) {
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
           quantity = 8;
           StarGame = 7;
        } else if (TypeChess == "mini4x4"){
            quantity = 4;
            StarGame = 3;
        }

    }

    sf::Vector2f FmousePositionPres(sf::Vector2f mousePosition) {
        mousePositionPres = mousePosition;
        return mousePositionPres;
    }

    sf::Vector2f FmousePositionHover(sf::Vector2f mousePosition) {
        mousePositionHover = mousePosition;
        return mousePositionPres;
    }

    sf::Event Fevent(sf::Event Mainevent) {
        event = Mainevent;
        return event;
    }

    void CredPawn() {
        Figure.clear();
        for (int i = 0, j = 0; i < quantity; i++) {
            sf::RectangleShape Pawn2;
            Pawn2.setSize(sf::Vector2f(60, 60));
            Pawn2.setOutlineThickness(1);
            Pawn2.setOutlineColor(sf::Color(250, 150, 100));
            Pawn2.setPosition(16 + 67.7 * (i + 1), 85 + 67.7 * StarGame);
            Pawn2.setTexture(TypeColor == 1 ? &TxPawn[1] :&TxPawn[0]);
            Figure.push_back(Pawn2);
        }
    }

    void SpawnFigure(sf::RenderWindow& win){
        for(auto & lFigure: Figure)
            win.draw(lFigure);
    }

    void SpawnShape( sf::RenderWindow &win){
        for (auto &Shape: shape)
            win.draw(Shape);
    }
};

class PawnBlack : public PawnWhite{
public:
    PawnBlack (std::string p_TypeChess, std::vector <sf::Texture> &p_TxPawn): PawnWhite(p_TypeChess,p_TxPawn){
        TypeChess = p_TypeChess;
        for (auto &spam: p_TxPawn)
            TxPawn.push_back(spam);
    }
    void  FTypePawn(std::string LTypeChess,int a) {
        a == 1 ? a = 0: a = 1;
        TypeColor = a;
        TypeChess = LTypeChess;
        if (TypeChess == "classic"){
            quantity = 8;
            StarGame = 2;
        } else if (TypeChess == "mini4x4"){
            quantity = 4;
            StarGame = 2;
        }
        std::cout<<TypeColor<<"\n";
        color = "black";
        TypeFigure = "pawn";
    }
};
#endif //CHESS_PAWN_H
