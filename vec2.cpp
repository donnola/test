#include "vec2.h"
#include <cmath>
#include <cfloat>

#define CMP(x, y)  (fabs(x - y) <= FLT_EPSILON * fmax(1.0, fmax(fabs(x), fabs(y))))


vector2 operator+(const vector2 &l, const vector2 &r) {
    return {l.x + r.x, l.y + r.y};
}

vector2 operator-(const vector2 &l, const vector2 &r) {
    return {l.x - r.x, l.y - r.y};
}

vector2 operator*(const vector2 &l, const vector2 &r) {
    return {l.x * r.x, l.y * r.y};
}

vector2 operator*(const vector2 &l, double r) {
    return {l.x * r, l.y * r};
}

vector2 operator*(double l, const vector2& r) {
    return r * l;
}

vector2 operator/(const vector2 &l, double r) {
    return {l.x / r, l.y / r};
}

bool operator==(const vector2& l, const vector2& r) {
    return CMP(l.x, r.x) && CMP(l.y,r.y);
}

bool operator!=(const vector2& l, const vector2& r) {
    return !(l == r);
}

inline double Dot(const vector2& l, const vector2& r) {
    return l.x * r.x + l.y * r.y;
}

double Magnitude(const vector2& vec) {
    return sqrt(Dot(vec, vec));
}

double MagnitudeSq(const vector2& vec) {
    return Dot(vec, vec);
}

void Normalize(vector2& vec) {
    double c = Magnitude(vec);
    vec /= c;
}

vector2 Normalized(const vector2& vec) {
    double c = Magnitude(vec);
    return vec / c;
}

double Angle(const vector2& l, const vector2& r) {
    double m = sqrt(MagnitudeSq(l) * MagnitudeSq(r));
    return acos(Dot(l, r) / m);
}

double CosBetweenVec(const vector2& l, const vector2& r) {
    return Dot(l, r) / sqrt(MagnitudeSq(l) * MagnitudeSq(r));
}


double Distance(const vector2& l, const vector2& r) {
    vector2 t = l - r;
    return Magnitude(t);
}

vector2 Project(const vector2& length, const vector2& direction) {
    double dot = Dot(length, direction);
    double magSq = MagnitudeSq(direction);
    return direction * (dot / magSq);
}

inline vector2 Perpendicular(const vector2& len, const vector2& dir) {
    return len - Project(len, dir);
}

vector2 Reflection(const vector2& vec, const vector2& normal) {
    double d = Dot(vec, normal);
    return vec - normal * (d * 2.0f);
}

inline std::ostream& operator<<(std::ostream &out, const vector2 &v) {
    return out << v.x << ' ' << v.y;
}
