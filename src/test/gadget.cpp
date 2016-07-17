#include "gadget.h"
#include "test/catch.hpp"

namespace {
	struct test_widget : widget {
		test_widget(std::string greeting) : greeting(greeting) {}
		std::string greet() override {return greeting;}
		std::string greeting;
	};
}

TEST_CASE("gadget") {
	test_widget w1("w1");
	test_widget w2("w2");
	gadget g;
	g.add(w1);
	g.add(w2);

	CHECK(g.greet() == "w1w2");
}
