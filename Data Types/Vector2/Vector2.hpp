/** @file Vector2.hpp
 *
 *  @note Created by william on 9/21/16.
 *
 */

#ifndef CALCULATOR_VECTOR2_HPP
#define CALCULATOR_VECTOR2_HPP

#include <cmath>
#include <iostream>
#include "../../Functions/SimpleMath.hpp"

struct Vector2 {

    /** The X and Y components and the magnitude (the hypotinuse) */
    double X, Y, magnitude;
    /** The angle of this vector (in degrees) */
    float theta, thetaRadian;

/*******************************************************************************************************************//**
 * Constructs the Vector2 with X and Y components.
 * @param X The x-axis component of the vector.
 * @param Y The y-axis component of the vector.
 * @return A two dimentional vector with all information filled in.
 *********************************************************************************************************************/
    Vector2(double X, double Y);

/*******************************************************************************************************************//**
 * Constructs a Vector2 based off of the
 * @param magnitude The hypotinuse of the vector
 * @param theta The angle of the vector (in degrees)
 * @return A two dimentional vector with all information filled in.
 **********************************************************************************************************************/
    Vector2(double magnitude, float theta);

/*******************************************************************************************************************//**
 * Default constructor.
 **********************************************************************************************************************/
    Vector2();

/*******************************************************************************************************************//**
 * Show the information of this vector.
 **********************************************************************************************************************/
    void printInfo();

/*******************************************************************************************************************//**
 * Makes a vector point in the correct direction.
 **********************************************************************************************************************/
    void correctAngles() {
        /* The value fo theta for this vector */
        float tempTheta = (float) RAD_TO_DEG(atan(fabs(Y) / fabs(X)));

        if (NEGATIVE(X) && POSITIVE(Y)) { //Quadrant II

            theta = 180 - tempTheta;

        } else if (NEGATIVE(X) && NEGATIVE(Y)) { //Quadrant III

            theta = 180 + tempTheta;

        } else if (POSITIVE(X) && NEGATIVE(Y)) { //Quadrant IV

            theta = 360 - tempTheta;

        }

    }

/*******************************************************************************************************************//**
 * Overload +
 * Allows for the adding of two vectors.
 * @return The X and Y components of the vectors added into a new Vector2 with filled components.
 **********************************************************************************************************************/
    Vector2 operator+(Vector2 v);

/*******************************************************************************************************************//**
 * TODO Overload -
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload /
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload *
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload +=
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload -=
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload /=
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * TODO Overload *=
 **********************************************************************************************************************/


};


#endif //CALCULATOR_VECTOR2_HPP
