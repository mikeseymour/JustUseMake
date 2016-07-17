#include "widgets/alice.h"
#include "test/catch.hpp"

TEST_CASE("alice") {
	alice a;
	CHECK(a.greet() == "Hi, I'm Alice!\n");
}
