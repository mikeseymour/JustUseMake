#include "widgets/bob.h"
#include "test/catch.hpp"

TEST_CASE("bob") {
	bob b;
	CHECK(b.greet() == "Hi, I'm Bob!\n");
}
