/** @file SimpleMath.hpp
 *
 *  @note Created by william on 9/21/16.
 *
 *  @note This file contains math functions so simple that they can be fully contained within a pre-processor directive.
 *
 */

#ifndef CALCULATOR_SIMPLEMATH_HPP
#define CALCULATOR_SIMPLEMATH_HPP

/** Gives the tangent of a triangle given the x and y components */
#define PYTHAG_TANGENT(x, y) sqrt(pow(x, 2) + pow(y, 2))

/** Tested 0-360 degrees (ints) */
#define RAD_TO_DEG(a) (a * (180 / M_PI))

/** Tested 0-360 degrees (ints) */
#define DEG_TO_RAD(a) (a * (M_PI / 180))

#define POSITIVE(a) (a > 0)

#define NEGATIVE(a) (a < 0)

#endif //CALCULATOR_SIMPLEMATH_HPP
