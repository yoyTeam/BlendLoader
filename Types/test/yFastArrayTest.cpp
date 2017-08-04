#ifdef TEST
#include <iostream>
#include "catch.hpp"
#include "../yFastArray.h"

TEST_CASE( "yFastArray", "[yFastArray]" ) {

    const int dataLimit = 100000;
    yFastArray<int*> data;

    for( size_t i = 0; i < dataLimit; ++i ) {
        data.addData( std::to_string(i), new int(i) );
    }

    SECTION( "get data" ) {
        int number = 15697;
        REQUIRE( *data.getData( std::to_string(number) ) == number );
        REQUIRE( data.getName( number ) == std::to_string(number) );
        REQUIRE( *data[number] == number );
    }

    SECTION( "size" ) {
        REQUIRE( data.size() == dataLimit );
    }
}

#endif
