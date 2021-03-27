cmake_minimum_required(VERSION 3.0.0)
project(hoohacks2021 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_executable(hoohacks2021
                battleship/Board.hpp
                battleship/Board.cpp
                battleship/Controller.hpp
                battleship/Cursor.hpp
                battleship/Cursor.cpp
                battleship/Ship.hpp
                battleship/Ship.cpp
                main.cpp)

target_include_directories(hoohacks2021 PUBLIC "/usr/local/include")

target_link_libraries(hoohacks2021 "/usr/local/lib/libsfml-system.2.5.1.dylib")
target_link_libraries(hoohacks2021 "/usr/local/lib/libsfml-window.2.5.1.dylib")
target_link_libraries(hoohacks2021 "/usr/local/lib/libsfml-graphics.2.5.1.dylib")
target_link_libraries(hoohacks2021 "/usr/local/lib/libsfml-audio.2.5.1.dylib")
target_link_libraries(hoohacks2021 "/usr/local/lib/libsfml-network.2.5.1.dylib")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
