//
// Created by happy on 9/16/19.
//

#include <iostream>
#include <string>
#include <array>
#include "tests.h"

void bad_declaration(int x, std::string y, std::array<std::string, 5> my_array) {
    std::cout << x << y << std::endl;
    for (std::string a_element : my_array) {
        std::cout << a_element << std::endl;
    }
}

void bad_definition(int x, std::string y, std::array<int, 5> my_array) {
    std::cout << x << y << std::endl;
    for (int a_element : my_array) {
        std::cout << a_element << std::endl;
    }
}