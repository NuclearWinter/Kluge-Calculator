/** @file SignifigantDigits.hpp
 *  @note Created by william on 9/20/16.
 *
 */

#ifndef CALCULATOR_SIGNIFIGANTDIGITS_HPP
#define CALCULATOR_SIGNIFIGANTDIGITS_HPP

#include <cmath>
#include <string>

/** This can be used to move @var places number of decimal places over for whatever this is used to multiply.
 *  It can also be used to divided an integer that is the result of multiplying to only get the signifigant digits */
#define DECIMAL_MOVE_NUMBER std::pow(10, places)

/** @warning THIS DOES NOT WORK IN ANY WAY RIGHT NOW AND IS ABSOLUTE CRAP
 *
 */
typedef double S;
class SignifigantDigits {

private:

    /** The amount of places to round numbers to */
    int places;

public:

    SignifigantDigits(S number) {

        initialize(number);

    }

    /** Finds if the specified number has a deminal place.
    *   This is used to count how many decimals a number has. @see initialize()
    *   @param num The number to check.
    *   @return Whether or not the number has a number after the decimal
     *  @warning Works with numbers with 6 or less decimal places
    */
/*    bool hasDeminal(S num) {

        std::string represent = std::to_string(num);

        string decimal = ".";

        bool otherNumbers = false;

        // Checks if any of the numbers past the decimal point are not 0
        for (std::string::iterator i = std::find_first_of(represent.begin(), represent.end(),
                                                          decimal.begin(), decimal.end()) + 1;
             i != represent.end(); ++i) {

            if (*i != '0') {

                otherNumbers = true;

                break;

            }

        }

        return otherNumbers;

    }*/

    /** Initializes the struct with a number to round based off of.
     *  The number put in here will determine all the rounding of digits. This can be set again at any time.
     *  @param number The number to base the signifigant digits off of
     */
    void initialize(S number) {
        /* The multiple is used to move decimal places over. Each time the decimal needs to be moved 1 place the places
         * variable is incremented by one */

        frexp(number, &places);

    }

    /** Formats a number to the number of places specified by the initializing number.
     *
     *  @param number The number to format
     *  @return The number with @var places dec
     */
    S round(S number) {

        int newNumber = (int) (number * DECIMAL_MOVE_NUMBER);

        return newNumber / DECIMAL_MOVE_NUMBER;

    }

    int getPlaces() const {
        return places;
    }


};

#endif //CALCULATOR_SIGNIFIGANTDIGITS_HPP
