//This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN 
#include "catch.hh"

#include "fact.hh"

TEST_CASE( "Factorials are computed", "[fact]" ) {
	REQUIRE( fact(0) == 1 );
    REQUIRE( fact(1) == 1 );
    REQUIRE( fact(2) == 2 );
    REQUIRE( fact(3) == 6 );
    REQUIRE( fact(10) == 3628800 );
}

