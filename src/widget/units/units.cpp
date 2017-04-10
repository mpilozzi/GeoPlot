#include "units.h"

Length::Length(double value, bool useless)
{
    _value = value;
}

double Length::toMeters()
{
    return _value;
}

double Length::toYards()
{
    return _value / 0.9144;
}

double Length::toNauticalMiles()
{
    return _value / 1852;
}

// Length Operator Definitions
Length Length::operator+(Length rhs)
{
    return Length(this->_value + rhs._value, true);
}

Length Length::operator-(Length rhs)
{
    return Length(this->_value - rhs._value, true);
}

Length Length::operator*(double rhs)
{
    return Length(this->_value * rhs, true);
}

Length Length::operator/(double rhs)
{
    return Length(this->_value / rhs, true);
}

void Length::operator+=(Length rhs)
{
    this->_value += rhs._value;
}

void Length::operator-=(Length rhs)
{
    this->_value -= rhs._value;
}

void Length::operator*=(double rhs)
{
    this->_value *= rhs;
}

void Length::operator/=(double rhs)
{
    this->_value /= rhs;
}

// Angle Definitions
Angle::Angle(double value, bool useless)
{
    _value = value;
}

double Angle::toDegrees()
{
    return _value;
}

double Angle::toRadians()
{
    return qDegreesToRadians(_value);
}

// Angle Operator definitions
Angle Angle::operator+(Angle rhs)
{
    return Angle(this->_value + rhs._value, true);
}

Angle Angle::operator-(Angle rhs)
{
    return Angle(this->_value - rhs._value, true);
}

Angle Angle::operator*(double rhs)
{
    return Angle(this->_value * rhs, true);
}

Angle Angle::operator/(double rhs)
{
    return Angle(this->_value / rhs, true);
}

void Angle::operator+=(Angle rhs)
{
    this->_value += rhs._value;
}

void Angle::operator-=(Angle rhs)
{
    this->_value -= rhs._value;
}

void Angle::operator*=(double rhs)
{
    this->_value *= rhs;
}

void Angle::operator/=(double rhs)
{
    this->_value /= rhs;
}
