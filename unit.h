#ifndef TESTUNIGINE_UNIT_H
#define TESTUNIGINE_UNIT_H

#include "vec2.h"

typedef struct unit {
    point2 position;
    vector2 viewDir;

    unit(point2 p, vector2 d) : position(p), viewDir(d) {}
} unit;

#endif //TESTUNIGINE_UNIT_H
