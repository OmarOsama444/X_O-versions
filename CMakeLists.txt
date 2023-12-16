cmake_minimum_required(VERSION 3.5)

project(Sykoo)

# Find SFML components

set( CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules" )

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories( c:/SFML/include )

file( GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp )

add_executable(Sykoo main.cpp ${MY_SOURCES})

target_include_directories( Sykoo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_package( SFML REQUIRED system window graphics )

if( SFML_FOUND )
    include_directories( ${SFML_INCLUDE_DIR} )
    target_link_libraries( Sykoo ${SFML_LIBRARIES} )
endif()

if ( WIN32 )
    file( GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file( COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()


# Link SFML libraries
