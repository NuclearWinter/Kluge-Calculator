//
// Created by 0110111 0110111 on 9/7/16.
//

#ifndef CALCULATOR_TESTFUNCTION_DOCUMENTED_HPP
#define CALCULATOR_TESTFUNCTION_DOCUMENTED_HPP

/*******************************************************************************************************************//**
 *
 **********************************************************************************************************************/

#include <iostream>
#include <string>
#include "exprtk.hpp"
#include "Utilities.hpp"

using namespace std;

void testExpertk() {

    /* This is the base equation to deal with */
    string baseEquation = "m * x + b";

    cout << "Fill in the equation: " << baseEquation << endl;

    /* This gets the new equation that has variables entered by the user */
    string enteredEquation;
    getline(cin, enteredEquation);

    /* Creates the table to hold symbols */
    symbol_table_double symbol_table;

    try {

        //symbol_table.add_variable("m", stod(value("m", baseEquation, enteredEquation)));
        //symbol_table.add_variable("x", stod(value("x", baseEquation, enteredEquation)));
        //symbol_table.add_variable("b", stod(value("b", baseEquation, enteredEquation)));

    } catch (const std::invalid_argument& ia) {

        //cerr << "Invalid arguments placed in equation: " ia.what() << endl;

    }

    symbol_table.add_constants();

    /* Holds the entered symbol table */
    expression_double expression;
    expression.register_symbol_table(symbol_table);

    parser_double parser;
    parser.compile(baseEquation, expression);

    /* This prints the value from the equation */
    cout << expression.value() << endl;

}

#endif //CALCULATOR_TESTFUNCTION_DOCUMENTED_HPP
