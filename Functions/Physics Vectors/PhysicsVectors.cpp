/** @file PhysicsVectors.hpp
 *
 *  @note Created by william on 9/21/16.
 *
 */

#include "PhysicsVectors.hpp"

PhysicsVectors::PhysicsVectors() {}

void PhysicsVectors::getVectors() {

    std::cout << "What type of vectors are you using? The current options are...\na) 2D Vectors" << std::endl;

    char answer;
    std::cin >> answer;

    switch (answer) {

        case 'a': { //User has selected 2D vectors

            collect2DVectors();

            compute2DEquilibrant();

            break;

        } default: { //The user's i input was not properly interpreted.

            std::cout << "Could not interpret the input. Please try again." << std::endl;

            getVectors();

            return;

        }

    }

}

void PhysicsVectors::collect2DVectors() {
    /* Determines if another vector should be added to the collection for the current calculation.
     * The first time through a vector will always be added. */
    bool enterVector = true;

    while (enterVector) { //TODO make a multiple choice class to handle this shit

        std::cout << "Do you have...\na) The X and Y components of a vector\nb) The magnitude and angle"
                  <<std::endl;

        char answer;
        std::cin >> answer;

        switch (answer) {

            case 'a': { //The user has selected to input the X and Y components of a vector

                std::cout << "Please enter the X component, than a space, followed by the Y component."
                          << std::endl;

                double tempX, tempY;
                std::cin >> tempX >> tempY;

                twoDVectors.push_back(Vector2(tempX, tempY));

                break;

            } case 'b': { //The user has selected to input the magnitude and angle of the vector

                std::cout << "Please enter the magnitude of the vector, followed by a space, followed by theta"
                          << std::endl;

                double tempMag;
                float tempTheta;
                std::cin >> tempMag >> tempTheta;

                twoDVectors.push_back(Vector2(tempMag, tempTheta));

                break;

            } default: { //The user's input could not be interpreted

                std::cerr << "Could not interpret input. Please try again." << std::endl;

                collect2DVectors();

                return;

            }

        }

        std::cout << "Your vector has been added. Would you like to add another? (Y/N)" << std::endl;

        char yesno;
        std::cin >> yesno; //TODO make yes or no function

        if (yesno != 'y' && yesno != 'Y')
            enterVector = false;

    }

}

void PhysicsVectors::compute2DEquilibrant() {
    /* This will be the resultant vector of anything the user added to the program. This is initialized to the first
     * vector entered */
    Vector2 newVector = twoDVectors[0];
    /* Prints the information about the first vector entered */
    twoDVectors[0].printInfo();

    /* Loops through all of the vectors entered and adds them */
    for (std::vector<Vector2>::iterator i = twoDVectors.begin() + 1; i != twoDVectors.end(); ++i) {

        (*i).printInfo(); //Prints the info on the vector to be added

        newVector = newVector + *i;

        newVector.printInfo(); //Prints the info on the new resultant

    }

    newVector.correctAngles(); //Corrects angles of the vector

    newVector.theta += 180; //Equilibrant is + 180

    std::cout << "The new vector has a magnitude of " << newVector.magnitude << " and an angle of "
              << newVector.theta << std::endl;

}
