#pragma once
#include "widget.h"
#include <vector>

class gadget : public widget {
public:
    void add(widget&);
    std::string greet() override;
private:
    std::vector<widget*> widgets;
};

