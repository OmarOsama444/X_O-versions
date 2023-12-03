cmake_minimum_required(VERSION 3.5)
project(sykoo VERSION 0.1.0 LANGUAGES C CXX)

file( GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ) 

add_executable(sykoo ${MY_SOURCES}
        src/X_O_Board_game_1.cpp)

target_include_directories( sykoo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ) 
