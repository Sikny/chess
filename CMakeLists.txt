cmake_minimum_required(VERSION 3.14)
project(chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SFML_LIBRARIES C:/Users/pamar/Documents/Libs/SFML-2.5.1/lib)
set(SFML_INCLUDE_DIR C:/Users/pamar/Documents/Libs/SFML-2.5.1/include)

add_executable(chess
        include/bishop.h
        include/case.h
        include/chesspieces.h
        include/game.h
        include/king.h
        include/knight.h
        include/pawn.h
        include/piece.h
        include/queen.h
        include/rook.h
        src/bishop.cpp
        src/case.cpp
        src/game.cpp
        src/king.cpp
        src/knight.cpp
        src/pawn.cpp
        src/piece.cpp
        src/queen.cpp
        src/rook.cpp
        main.cpp src/PieceFactory.cpp include/PieceFactory.h)

find_package(SFML REQUIRED graphics window system)
include_directories(include ${SFML_INCLUDE_DIR})
link_directories(chess ${SFML_LIBRARIES})
target_link_libraries(chess sfml-graphics sfml-system sfml-window)
