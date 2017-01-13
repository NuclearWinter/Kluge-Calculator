/*******************************************************************************************************************//**
 * @file main.cpp
 *
 * @note If you are looking for the portion of this program that solves vector equilibrates,
 * @see Functions/PhysicsVectors
 **********************************************************************************************************************/

#include <iostream>
#include <cstdio>
#include "exprtk.hpp"
#include "Utilities.hpp"
#include "Functions/Velocity/Velocity.hpp"
#include "Functions/Physics Vectors/PhysicsVectors.hpp"
#include "Functions/SimpleMath.hpp"

using namespace std;

string help = "If there are () around a character in an equation, you do not need to add that variable";

/*******************************************************************************************************************//**
 *
 **********************************************************************************************************************/

int main() {

    PhysicsVectors physicsVectors = PhysicsVectors();

    physicsVectors.getVectors();

    return 0;
}