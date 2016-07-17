#pragma once
#include <string>

struct widget {
    virtual ~widget() {}
    virtual std::string greet() = 0;
};

