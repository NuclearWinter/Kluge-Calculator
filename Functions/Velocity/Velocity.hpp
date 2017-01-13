//
// Created by william on 9/8/16.
//

#ifndef CALCULATOR_VELOCITY_HPP
#define CALCULATOR_VELOCITY_HPP

#include <iostream>
#include <string>
#include "../../exprtk.hpp"
#include "../../Utilities.hpp"

using namespace std;

struct equation_variable {

    double value = 0;
    bool filled = false;

};

#define FILL(n, v, b) n = v; b = true;
#define INPUT_DOUBLE(n) string holder; cin >> holder; n = stod(holder)
#define GET_Y_N(b) string response; cin >> response; if (response == "Y" || response == "y") b = true; else b = false;

class Velocity {
private:
    /* Creates the table to hold symbols (exprtk dependency) */
    symbol_table_double symbol_table;
    /**/
    expression_double deltaX;
    /**/
    expression_double deltaT;
    /* Solving for the change in x distance */
    const string deltaX_equation = "V0x * t";
    /* Time is equal to the change in y divided by the vertical velocity times 1/2 */
    const string t_equation = "sqrt(dY / (Vy * 0.5))";
    /* The initial x velocity equals delta x divided by time */
    const string V0x_equation = "dX / t";

    /* The variables used in solving these types of equations */
    equation_variable V0x, dY, Vy, dX, t;

    void solveDeltaT() {

        parser_double deltaTParser;
        deltaTParser.compile(t_equation, deltaT);

        //Account for different ways of solving for t

    }

    void solveDeltaX() {

        string enteredEquation = "";

        try {

            if (!V0x.filled && !t.filled) {
            //Neither has been filled
                cout << "Fill in the equation: " << deltaX_equation << endl;
                std::getline(std::cin, enteredEquation);

                FILL(V0x.value, stod(value("V0x", deltaX_equation, enteredEquation)), V0x.filled);
                FILL(t.value, stod(value("t", deltaX_equation, enteredEquation)), t.filled);

            } else if (!V0x.filled) {
            //V0x has not been filled
                cout << "Please enter the initial velocity for the x axis (V0x): " <<endl;
                INPUT_DOUBLE(V0x.value);
                V0x.filled = true;

            } else if (!t.filled) {
            //t has not bee filled
                if (dY.filled && Vy.filled) {
                //The program can get a number for time from known variables
                    cout << "I can now solve for t based on ΔY and Vy, is this okay?" << endl;

                    bool solve;
                    GET_Y_N(solve);

                    if (solve) {

                        solveDeltaT();

                    } else {
                    //Ask the user for inputs to solve with
                        double temp_velocity, temp_distance;

                        { //Local scope so that the macro works
                            cout << "Please enter the constant velocity to use for solving time: ";
                            INPUT_DOUBLE(temp_velocity);
                        }

                        { //Local scope so that the macro works
                            cout << "Please enter the change in distance to use for solving time: ";
                            INPUT_DOUBLE(temp_distance);
                        }

                        t.value = (double) sqrt(temp_distance / (temp_velocity * 0.5));

                    }

                }

                t.filled = true; //!!!THIS DOESN'T WORK RIGHT NOW

            }

        } catch (const std::invalid_argument& ia) {

            cerr << "Invalid arguments placed in equation: Could not convert doubles properly (program exit)" << endl;
            return;

        } //End of variable filling

        /* This is used to parse equations and compile all the references needed to get a value */
        parser_double parser;
        parser.compile(deltaX_equation, deltaX);

        dX.value = deltaX.value();
        dX.filled = true;

        cout << "ΔX = " << dX.value << endl;

    }

public:

    Velocity() {

        symbol_table.add_variable("V0x", V0x.value);
        symbol_table.add_variable("dY", dY.value);
        symbol_table.add_variable("Vy", Vy.value);
        symbol_table.add_variable("dX", dX.value);
        symbol_table.add_variable("t", t.value);

        deltaX.register_symbol_table(symbol_table);
        deltaT.register_symbol_table(symbol_table);

    }

    void solveVariable() {

        cout << "Which variables would you like to solve for? V₀x(V0x), ΔX(dX), or t?" << endl;

        string solve;
        getline(cin, solve);

        if (solve == "V0x") {

            cout << "not done yet";

        } else if (solve == "t") {

            cout << "not done yet";

        } else if (solve == "dX") {

            solveDeltaX();

        } else {

            cerr << "Unknown variable entered, please try again." << endl;

            solveVariable();

            return;

        }

    }


}; //End class Velocity


#endif //CALCULATOR_VELOCITY_HPP
