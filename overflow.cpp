//
// Created by Андрей on 23.06.2022.
//
#include <iostream>

bool overflow ( ){

    if (! std::cin){
        std::cout <<"Input error. Input again:";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return true;
    } else {return false;}
}