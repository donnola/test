#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include <iostream>

typedef struct vector2 {
    double x;
    double y;

    vector2() : x(0), y(0){}
    vector2(double a, double b) : x(a), y(b){}

    vector2& operator+=(const vector2& r) {
        x += r.x;
        y += r.y;
        return *this;
    }
    vector2& operator-=(const vector2& r) {
        x -= r.x;
        y -= r.y;
        return *this;
    }
    vector2& operator*=(const vector2& r) {
        x *= r.x;
        y *= r.y;
        return *this;
    }
    vector2& operator*=(double r) {
        x *= r;
        y *= r;
        return *this;
    }
    vector2& operator/=(double r) {
        x /= r;
        y /= r;
        return *this;
    }

} vector2;

vector2 operator+(const vector2 &l, const vector2 &r);

vector2 operator-(const vector2 &l, const vector2 &r);

vector2 operator*(const vector2 &l, const vector2 &r);

vector2 operator*(const vector2 &l, double r);

vector2 operator*(double l, const vector2& r);

vector2 operator/(const vector2 &l, double r);

bool operator==(const vector2& l, const vector2& r);

bool operator!=(const vector2& l, const vector2& r);

inline double Dot(const vector2& l, const vector2& r);

double Angle(const vector2& l, const vector2& r);

double CosBetweenVec(const vector2& l, const vector2& r);

double Distance(const vector2& l, const vector2& r);

vector2 Project(const vector2& length, const vector2& direction);

vector2 Perpendicular(const vector2& len, const vector2& dir);

vector2 Reflection(const vector2& vec, const vector2& normal);

double Magnitude(const vector2& vec);
double MagnitudeSq(const vector2& vec);
void Normalize(vector2& vec);
vector2 Normalized(const vector2& vec);

std::ostream& operator<<(std::ostream &out, const vector2 &v);

using point2 = vector2;

#endif //RAYTRACER_VECTOR_H
