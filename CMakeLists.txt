
cmake_minimum_required( VERSION 3.13 )
project( Kalculator )

find_package( FLEX )
find_package( BISON )

FLEX_TARGET( KalcLexer ${CMAKE_SOURCE_DIR}/Sources/Lexel.l
    "${CMAKE_BINARY_DIR}/kLexer.cpp"
    COMPILE_FLAGS --header=${CMAKE_BINARY_DIR}/kLexer.h )

BISON_TARGET( KalcParser ${CMAKE_SOURCE_DIR}/Sources/Bison.y
    "${CMAKE_BINARY_DIR}/kParser.cpp"
    VERBOSE )

add_executable( Kalculator
    Sources/Main.cpp
    ${FLEX_KalcLexer_OUTPUTS}
    ${BISON_KalcParser_OUTPUTS} )

target_include_directories( Kalculator PRIVATE ${CMAKE_BINARY_DIR} )


enable_testing()

file( GLOB test_samples "Samples/*" )
foreach( file ${test_samples} )
    get_filename_component( nn ${file} NAME )

    add_test( NAME Print_${nn} COMMAND ${CMAKE_BINARY_DIR}/Kalculator print ${file} )
    add_test( NAME Parser_${nn} COMMAND ${CMAKE_BINARY_DIR}/Kalculator parse ${file} )

endforeach( file ${test_samples} )

set_tests_properties( Print_First PROPERTIES PASS_REGULAR_EXPRESSION "NUMBERPLUSNUMBER" )
