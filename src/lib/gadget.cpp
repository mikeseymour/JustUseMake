#include "gadget.h"

void gadget::add(widget & w) {
    widgets.push_back(&w);
}
std::string gadget::greet() {
	std::string greeting;
    for (widget * w : widgets) {
        greeting += w->greet();
    }
    return greeting;
}
