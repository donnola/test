#ifndef TESTUNIGINE_FIELD_H
#define TESTUNIGINE_FIELD_H

#include "unit.h"
#include <utility>
#include <vector>
#include <cmath>

#define DEG2RAD(x) ((x) * 0.0174533f)

class field {
public:
    field(std::vector<unit> u, size_t n, double deg, double dis) :
    units(std::move(u)), sqDistance(dis * dis), cosView(cos(DEG2RAD(deg / 2))),
    state(n, std::vector<size_t> (n, 0)) {}
    std::vector<size_t> NumUnitsView();
    void DrawUnits();

private:
    std::vector<unit> units;
    // 0 - расстаяние не измерено, 1 - меньше или равно дистанции видимости, 2 - больше
    std::vector<std::vector<size_t>> state;
    double cosView;
    double sqDistance;

};


#endif //TESTUNIGINE_FIELD_H
