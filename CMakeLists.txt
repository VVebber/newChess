cmake_minimum_required(VERSION 3.26)
project(chess)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(chess main.cpp
        window/MainMenu.h
        window/MainMenu.h
        window/PlayMenu.h
        ChessPieces/Pawn.h
        GameLogic.h
)

target_link_libraries(chess sfml-graphics sfml-audio)
