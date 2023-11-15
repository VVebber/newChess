#ifndef NEWCHESS_SETTINGS_H
#define NEWCHESS_SETTINGS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "MainMenu.h"

class Senttings : public MainMenu{
private:
    std::vector <sf::Texture> TxBackground;

    std::string TypeDevise = "";
    sf::RectangleShape Background;
    int MinWinSizeX = 1290;
    int MinWinSizeY = 960;
private:
    void SizeWin() {
        MinWinSizeX = 1290;
        MinWinSizeY = 960;
        MaxWinSizeX = 1290;
        MaxWinSizeY = 960;
    }

public:
    void CreatBackground(){
        Background.setSize(sf::Vector2f(MaxWinSizeX,MaxWinSizeY));
        Background.setFillColor(sf::Color(240, 255, 255));
        Background.setTexture(&TxBackground[0]);
    }

    void setTypeDevise(std::string NewTypeDevise) {
        TypeDevise = NewTypeDevise;
        SizeWin();
    }

    void setTxBackground(std::vector <sf::Texture> newTxBekgraund){
        for(auto& texture: newTxBekgraund)
            TxBackground.push_back(texture);

    }

    std::string getTypeDevise(){
        return TypeDevise;
    }

    sf::RectangleShape getBackground() const{
        return Background;
    };

    int getMinWinSizeX(){
        return MinWinSizeX;
    }

    int getMinWinSizeY(){
        return MinWinSizeY;
    }

    int getMaxWinSizeX(){
        return MaxWinSizeX;
    }

    int getMaxWinSizeY(){
        return MaxWinSizeY;
    }
};


#endif //NEWCHESS_SETTINGS_H
