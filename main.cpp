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
#include "Data Types/Choice Menu/ChoiceMenu.hpp"

using namespace std;

string help = "If there are () around a character in an equation, you do not need to add that variable";

/*******************************************************************************************************************//**
 *
 **********************************************************************************************************************/
int main() {

    ChoiceMenu<std::string> mainChoices = ChoiceMenu<std::string>("Please select the main program to run");

    mainChoices.addChoice("A", "Physics Vectors", "Run the physics vectors program");
    mainChoices.addChoice("B", "other", "test");

    mainChoices.printChoices();
    std::string selection = mainChoices.getChoice();

    if (selection == "Physics Vectors") {

        PhysicsVectors physicsVectors = PhysicsVectors();
        physicsVectors.getVectors();

    } else {
        cout << "ERROR: No valid selection was made\n";
    }

    return 0;
}