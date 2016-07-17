#include "gadget.h"
#include "widgets/alice.h"
#include "widgets/bob.h"
#include <iostream>

int main() {
	alice a;
	bob b;
	gadget g;
	g.add(a);
	g.add(b);
	std::cout << g.greet();
}
