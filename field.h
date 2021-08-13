#ifndef TESTUNIGINE_FIELD_H
#define TESTUNIGINE_FIELD_H

#include "unit.h"
#include <utility>
#include <vector>
#include <cmath>

#define SCREEN_WIDTH 301
#define SCREEN_HEIGHT 301

class field {
public:
    field(std::vector<unit> u, size_t n, double deg, double dis) :
    units(std::move(u)), sqDistance(dis * dis), cosView(cos(DEG2RAD(deg / 2))) {}
    std::vector<size_t> NumUnitsView();
    void DrawUnits(std::ofstream& iout);

private:
    std::vector<unit> units;
    bool buffer[SCREEN_HEIGHT][SCREEN_WIDTH] = {false};
    double cosView;
    double sqDistance;
};


#endif //TESTUNIGINE_FIELD_H
