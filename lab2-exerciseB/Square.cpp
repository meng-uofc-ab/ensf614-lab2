//
//  Square.cpp
//  lab2-exerciseB
//
//  Created by Abhilash Paul on 2024-09-19.
//

#include "Square.h"
#include <iostream>

using namespace std;


Square::Square(double a, double x, double y, const char* name): Shape(x, y, name), side_a(a) {}

const double Square::area() const {
    return side_a * side_a;
}

const double Square::perimeter() const {
    return 4 * side_a;
}

void Square::display() const{
    cout << "Square Name: " << shapeName << endl;
    origin.display();
    cout << "Side a: " << side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Square::set_side_a(double a){
    side_a = a;
}
