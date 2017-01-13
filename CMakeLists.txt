cmake_minimum_required(VERSION 3.6)
project(Calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp exprtk.hpp
        Utilities.hpp Utilities.cpp
        TestFunction_Documented.hpp
        Functions/Velocity/Velocity.cpp Functions/Velocity/Velocity.hpp
        EquationBase/Equation.cpp EquationBase/Equation.hpp
        SignifigantDigits.hpp "Functions/Physics Vectors/PhysicsVectors.cpp" "Functions/Physics Vectors/PhysicsVectors.hpp" "Data Types/Vector2/Vector2.cpp" "Data Types/Vector2/Vector2.hpp" Functions/SimpleMath.hpp)
add_executable(Calculator ${SOURCE_FILES})