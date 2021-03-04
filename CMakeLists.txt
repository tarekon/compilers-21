
cmake_minimum_required( VERSION 3.13 )
project( Kalculator )

find_package( FLEX )

FLEX_TARGET( KalcLexer ${CMAKE_SOURCE_DIR}/Sources/Lexel.l
    "${CMAKE_BINARY_DIR}/kLexer.cpp"
    COMPILE_FLAGS --header=${CMAKE_BINARY_DIR}/kLexer.h )

add_executable( Kalculator
    Sources/Main.cpp
    ${FLEX_KalcLexer_OUTPUTS} )

target_include_directories( Kalculator PRIVATE ${CMAKE_BINARY_DIR} )