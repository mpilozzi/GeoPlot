#ifndef UNITS_H
#define UNITS_H

#include <qmath.h>

// Length Definitions
#define MeterLength(X)            Length(X, true) // Meter is the base unit
#define KilometerLength(X)        Length(1000 * X, true) // A Kilometer is 1000 meters
#define YardLength(X)             Length(0.9144 * X, true) // Yard defined as .9144 meters
#define NauticalMileLength(X)     Length(1852 * X, true) // Nautical mile defined as 1852 meters

// Angle Definitions
#define DegreeAngle(X)               Angle(-X, true) // Degree is the base unit, -X to counterbalance the coordinate systems inverted y
#define RadianAngle(X)               Angle(qRadiansToDegrees(-X), true)

class Length
{
    public:
        Length(double value, bool useless); // Bool not used. Is an argument to prevent default conversion from other scalar types to Length

        double toMeters();
        double toYards();
        double toNauticalMiles();

        Length operator+(Length rhs);
        Length operator-(Length rhs);
        Length operator*(double rhs);
        Length operator/(double rhs);

        void operator+=(Length rhs);
        void operator-=(Length rhs);
        void operator*=(double rhs);
        void operator/=(double rhs);

    private:
        double _value;
};

class Angle
{
    public:
        Angle(double value, bool useless); // Bool not used. Is an argument to prevent default conversion from other scalar types to Angle

        double toDegrees();
        double toRadians();

        Angle operator+(Angle rhs);
        Angle operator-(Angle rhs);
        Angle operator*(double rhs);
        Angle operator/(double rhs);

        void operator+=(Angle rhs);
        void operator-=(Angle rhs);
        void operator*=(double rhs);
        void operator/=(double rhs);

    private:
        double _value;
};

#endif // UNITS_H
