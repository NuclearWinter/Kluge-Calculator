//
// Created by william on 9/2/16.
//

#ifndef CALCULATOR_UTILITIES_HPP
#define CALCULATOR_UTILITIES_HPP

#include "exprtk.hpp"

using namespace std;

/* This type of table table holds symbols to be called by the expression */
typedef exprtk::symbol_table<double> symbol_table_double;
/* This type of expression is used for double precision numbers */
typedef exprtk::expression<double>     expression_double;
/* This type of parser is used for double precision parsing */
typedef exprtk::parser<double>             parser_double;

/** @def GIVE_ANSWER
 *  @param a The variable being volved for
 *  @param b The answer
 */
#define GIVE_ANSWER(a, b) std::cout << "Answer: " << a << " = " << b << std::endl

#define ERROR(a, b) std::cerr << "ERROR IN PROGRAM " << a << ": " << b << std::endl

/*******************************************************************************************************************//**
 * Finds words within larger strings.
 * This is used to compare pieces of an original function to those in one entered by a user
 **********************************************************************************************************************/
vector<string> wordFinder(string findIn);

/*******************************************************************************************************************//**
 * Determines the value of a variable find within the string search based on the original equation original
 **********************************************************************************************************************/
string value(string find, string original, string search);

#endif //CALCULATOR_UTILITIES_HPP
