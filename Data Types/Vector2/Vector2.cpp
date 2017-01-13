/** @file Vector2.cpp
 *
 *  @note Created by william on 9/21/16.
 *
 */

#include "Vector2.hpp"

Vector2::Vector2(double X, double Y) : X(X), Y(Y) {
    /* Calculates the value of theta in radians */
    thetaRadian = (float) atan(Y/X);
    /* Calculates the value of theta in degrees (just converts thetaRadian to degrees) */
    theta = (float) RAD_TO_DEG(thetaRadian);
    /* Finds the tangent to X and Y components */
    magnitude = PYTHAG_TANGENT(X, Y);

}

Vector2::Vector2(double magnitude, float theta) : magnitude(magnitude), theta(theta) {
    /* Calculates the value of theta in radians */
    thetaRadian = (float) DEG_TO_RAD(theta);
    /* Calculates the X component of the vector */
    X = magnitude * cos(thetaRadian);
    /* Calculates the Y component of the vector */
    Y = magnitude * sin(thetaRadian);

}

Vector2 Vector2::operator+(Vector2 v) {

    return Vector2(v.X + X, v.Y + Y);

}

Vector2::Vector2() {}

void Vector2::printInfo() {

    std::cout << "Magnitude: " << magnitude << "\nTheta: " << theta << "\nX: " << X << "\nY: " << Y << std::endl;

}
