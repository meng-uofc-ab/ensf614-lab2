//
//  Rectangle.cpp
//  lab2-exerciseB
//
//  Created by Abhilash Paul on 2024-09-19.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double a, double b, double x, double y, const char* name):
Square(a, x, y, name), side_b(b) {}

const double Rectangle::area() const{
    return side_a * side_b;
}

const double Rectangle::perimeter() const{
    return 2 * (side_a+side_b);
}

void Rectangle::display() const{
    cout << "Rectangle Name: " << shapeName << endl;
    origin.display();
    cout << "Side a: " << side_a << endl;
    cout << "Side b: " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Rectangle::set_side_b(double b){
    side_b = b;
}
