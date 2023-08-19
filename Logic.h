#ifndef CHESS_LOGIC_H
#define CHESS_LOGIC_H

#include "Shapes/Pawn.h"
#include "Shapes/Queen.h"
#include "Shapes/King.h"

void LetsGoUp(PawnWhite& pawn, std::vector<float>& WhitePos, std::vector<float>& BlackPos);
void LetsGoDown(PawnWhite& pawn, std::vector<float>& WhitePos, std::vector<float>& BlackPos);
void FigureGo(PawnWhite& pawn);
void CredShape(float x,float y,float j,PawnWhite& pawn,sf::CircleShape spam);

    void FigureLogic(sf::RenderWindow& win,std::vector<float> WhitePos,std::vector<float> BlackPos,KingWhite& kingWhite, PawnWhite& pawnWhite, QueenWhite& queenWhite) {
        pawnWhite.SpawnFigure(win);
        queenWhite.SpawnFigure(win);
        kingWhite.SpawnFigure(win);

        if (pawnWhite.color == "white")
            LetsGoUp(pawnWhite, WhitePos,BlackPos);

        if (pawnWhite.color == "black")
            LetsGoDown(pawnWhite, WhitePos,BlackPos);


        //FigureGo(pawnWhite);
        pawnWhite.SpawnShape(win);
    }

    void LetsGoUp(PawnWhite & pawn, std::vector<float>& WhitePos, std::vector<float>& BlackPos) {
        if (pawn.event.type == sf::Event::MouseButtonPressed)
            if (pawn.event.mouseButton.button == sf::Mouse::Left) {
                pawn.shape.clear();

                for (int i = 0; i < pawn.Figure.size(); i++) {
                    if (pawn.Figure[i].getGlobalBounds().contains(pawn.mousePositionPres)) {
                        pawn.SelectedFigure = i;

                        for (int j = 1; j < 8; j++) {
                            float x = pawn.Figure[i].getPosition().x;
                            float y = pawn.Figure[i].getPosition().y;
                            sf::CircleShape spam(30,10);
                            spam.setFillColor(sf::Color(124, 252, 0,100));
                            spam.setOutlineThickness(2);
                            spam.setOutlineColor(sf::Color(178, 34, 34,100));
                            spam.setPosition(x, y - pawn.SizeSquare * j);
                            pawn.shape.push_back(spam);
                        }
                    }
                }
                if(pawn.TypeFigure == "pawn") {
                    if (pawn.Figure[pawn.SelectedFigure].getPosition().y == pawn.WPowStart)
                        for (int i = 0; i < pawn.shape.size(); i++)
                            if (i == 2) {
                                pawn.shape.erase(pawn.shape.begin() + i);
                                i = 0;
                            }
                }
            }
    }

    void LetsGoDown(PawnWhite & pawn, std::vector<float>& WhitePos, std::vector<float>& BlackPos) {
    if (pawn.event.type == sf::Event::MouseButtonPressed)
        if (pawn.event.mouseButton.button == sf::Mouse::Left) {
            pawn.shape.clear();

            for (int i = 0; i < pawn.Figure.size(); i++) {
                if (pawn.Figure[i].getGlobalBounds().contains(pawn.mousePositionPres)) {
                    pawn.SelectedFigure = i;

                    for (int j = 1; j < 8; j++) {
                        float x = pawn.Figure[i].getPosition().x;
                        float y = pawn.Figure[i].getPosition().y;
                        sf::CircleShape spam(30,10);
                        spam.setFillColor(sf::Color(124, 252, 0,100));
                        spam.setOutlineThickness(2);
                        spam.setOutlineColor(sf::Color(178, 34, 34,100));
                        spam.setPosition(x, y + pawn.SizeSquare * j);
                        pawn.shape.push_back(spam);
                    }
                }
            }

            if(pawn.TypeFigure == "pawn")
                if(pawn.Figure[pawn.SelectedFigure].getPosition().y == pawn.BPowStart)
                    for( int i = 0; i < pawn.shape.size(); i++)
                        if(i == 2) {
                            pawn.shape.erase(pawn.shape.begin() + i);
                            i = 0;
                        }
        }
}

    void FigureGo(PawnWhite & pawn) {
       for (int i = 0; i < pawn.shape.size(); i++)
           if (pawn.shape[i].getGlobalBounds().contains(pawn.mousePositionPres))
               if (pawn.shape.size() > 0) {
                   pawn.Figure[pawn.SelectedFigure].setPosition(pawn.shape[i].getPosition().x,pawn.shape[i].getPosition().y);
                   pawn.shape.clear();
               }

   }


#endif //CHESS_LOGIC_H
