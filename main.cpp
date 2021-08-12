#include <iostream>
#include <vector>
#include "vec2.h"
#include "field.h"
#include "unit.h"


int main() {
    std::vector<unit> units;
    units.emplace_back(unit(point2(1,1), vector2(0, 1)));
    units.emplace_back(unit(point2(1,2), vector2(1, 0)));
    units.emplace_back(unit(point2(-5,- 1), vector2(0.707, 0.707)));
    field f(units, units.size(), 135.5, 2);
    std::vector<size_t> amount = f.NumUnitsView();
    for (size_t i : amount) {
        std::cout << i << std::endl;
    }
    return 0;
}
