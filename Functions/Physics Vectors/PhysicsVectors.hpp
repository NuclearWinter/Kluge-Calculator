/** @file PhysicsVectors.hpp
 *
 *  @note Created by william on 9/21/16.
 *
 */

#ifndef CALCULATOR_PHYSICSVECTORS_HPP
#define CALCULATOR_PHYSICSVECTORS_HPP

#include <vector>
#include <iostream>
#include "../../Data Types/Vector2/Vector2.hpp"

/***********************************************************************************************************************
 * Allows for calculations to be made regarding the function of mathematical vectors applied to physics.
 * @see ../../Data Types/Vector2
 **********************************************************************************************************************/
class PhysicsVectors {

private:
    /** Holds any 2D vectors to be used in the program  */
    std::vector<Vector2> twoDVectors;

/*******************************************************************************************************************//**
 *  Handles user input of vectors in their 2D form.
 *  This will give the option for users to enter ther X and Y components of a vector or enter the magnitude and theta.
 **********************************************************************************************************************/
    void collect2DVectors();

/*******************************************************************************************************************//**
 * Computes the equilibrant of all the forces in twoDVectors.
 **********************************************************************************************************************/
    void compute2DEquilibrant();

public:

/*******************************************************************************************************************//**
 *  Default constructor for the PhysicsVectors Class.
 **********************************************************************************************************************/
    PhysicsVectors();

/*******************************************************************************************************************//**
 *  Sends the user to the correct function to input vectors.
 *  Above (in the private section) there may be various dimentions of vectors to be dealbt with. This sends the user
 *  to the type of vector that they need to deal with. (Currently this program only supports 2D vectors)
 **********************************************************************************************************************/
    void getVectors();

};


#endif //CALCULATOR_PHYSICSVECTORS_HPP
