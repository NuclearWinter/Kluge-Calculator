/***********************************************************************************************************************
 * @file ChoiceMenu.hpp
 *
 * @note Created by william on 9/22/16.
 *
 **********************************************************************************************************************/

#ifndef CALCULATOR_CHOICEMENU_HPP
#define CALCULATOR_CHOICEMENU_HPP

#include <utility>
#include <map>
#include <vector>
#include <string>
#include <iostream>

typedef std::pair<char, void(*)()> voidMapType;

/***********************************************************************************************************************
 * This class allows for choice menus to be generated and direct users to the correct function.
 *
 * The template must be filled with A being the type of key that the user will enter to select function type B, which
 * must be the same for any function to be called from this class. Each choice B must have a coresponding description to
 * be printed to the user.
 *
 **********************************************************************************************************************/
template<typename A, typename B> class ChoiceMenu {

public:
/***********************************************************************************************************************
 * Default constructor for the ChoiceMenu class.
 **********************************************************************************************************************/
    ChoiceMenu() {}

/***********************************************************************************************************************
 * Construct the ChoiceMenu class with description of the choice the user is making.
 **********************************************************************************************************************/
    ChoiceMenu(const std::string &mainDescription) : mainDescription(mainDescription) {}

/***********************************************************************************************************************
 * Add a new choice to the map.
 * @param key The key for the new choice.
 * @param function The function to be ran if the user chooses key.
 * @param description The description of what the function deals with (to be printed to the user).
 **********************************************************************************************************************/
    void addChoice(A key, B function, std::string description) {

        choices.emplace(key, function);
        choiceDescriptions.emplace(key, description);

    }

/***********************************************************************************************************************
 * Print choices.
 **********************************************************************************************************************/
    void printChoices() {

        std::cout << mainDescription << std::endl;

        for (std::map<A, B>::iterator i = choiceDescriptions.begin(); i < choiceDescriptions.size(); ++i)
            std::cout << i->first << ") " << i->second << std::endl;

    }

/***********************************************************************************************************************
 * Get the user's chocie
 **********************************************************************************************************************/
    void

private:
    /** This describes the choice that the user is making */
    std::string mainDescription;
    /** The map of choices for for the user to choose from */
    std::map<A, B> choices;
    /** Descriptions of each of the choices within the choices map.
     *  These should line up so that choiceDecriptions[0] is the description for choices[0] */
    std::map<A, std::string> choiceDescriptions;

};


#endif //CALCULATOR_CHOICEMENU_HPP
