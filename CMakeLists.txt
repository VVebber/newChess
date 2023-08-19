cmake_minimum_required(VERSION 3.25)
project(chess)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(chess main.cpp Gameplay.h spam.h Shapes/Pawn.h
              Windows/Play.h Windows/MainMenu.h Windows/MenuESC.h Shapes/Rook.h Shapes/knight.h Shapes/Brishop.h Shapes/Queen.h Shapes/King.h Windows/TypeBoard.h Logic.h)

target_link_libraries(chess sfml-graphics sfml-audio)
