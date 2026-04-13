#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE( "First player (x) begins" ) {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.getplayer() == 'X' );
}

TEST_CASE("Good move reshapes the board") {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.makemove(1) == true);
    REQUIRE(tictactoe.retrievecell(0)== 'X');

}

TEST_CASE( "After game restarts, the numbers and board restores successfully" ) {
    TTTMechanics tictactoe;
    tictactoe.makemove(1);
    tictactoe.switchcurrentplayer();
    tictactoe.makemove(2);
    tictactoe.resetgame();

    REQUIRE(tictactoe.getplayer() == 'X' );
    REQUIRE(tictactoe.retrievecell(0)== '1');
    REQUIRE(tictactoe.retrievecell(1) == '2');
    REQUIRE(tictactoe.retrievecell(2) == '3');
    REQUIRE(tictactoe.retrievecell(3)=='4');
    REQUIRE(tictactoe.retrievecell(4)=='5');
    REQUIRE(tictactoe.retrievecell(5)=='6');
    REQUIRE(tictactoe.retrievecell(6)=='7');
    REQUIRE(tictactoe.retrievecell(7)=='8');
    REQUIRE(tictactoe.retrievecell(8)=='9');
}



TEST_CASE("Once a cell is used, the user sees an error if reattempting to place their mark on it") {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.makemove(1)==true);
    REQUIRE(tictactoe.makemove(1)==false);
}