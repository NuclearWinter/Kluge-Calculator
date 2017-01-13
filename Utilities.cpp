//
// Created by william on 9/7/16.
//

#include "Utilities.hpp"

vector <string> wordFinder(string findIn) {

    vector<string> returnThis;

    string holderString = "";

    for (string::iterator i = findIn.begin(); i != findIn.end(); ++i) {

        if (*i != ' ') {

            holderString += *i;


        }

        if (*i == ' ' || i + 1 == findIn.end()) {

            returnThis.push_back(holderString);

            holderString = "";

        }

    }


    return returnThis;

}

string value(string find, string original, string search) {

    vector<string> searchedStrings = wordFinder(search);

    vector<string> equationStrings = wordFinder(original);

    for (int i = 0; i < equationStrings.size(); ++i) {

        if (equationStrings[i] == find)
            return searchedStrings[i];

    }

    return "valuenotfound";

}
