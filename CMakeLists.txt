cmake_minimum_required(VERSION 3.26)
project(newChess)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/Cellar/sfml/2.6.0/include)

link_directories(/opt/homebrew/Cellar/sfml/2.6.0/lib)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(newChess main.cpp
        window/MainMenu.h
        window/MainMenu.h
        window/PlayMenu.h
        GameLogic.h )

target_link_libraries(newChess sfml-graphics sfml-audio)
