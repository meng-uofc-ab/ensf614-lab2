//
//  GraphicsWorld.cpp
//  lab2-exerciseB
//
//  Created by Abhilash Paul on 2024-09-19.
//

#include "GraphicsWorld.h"
#include "Point.h"
#include "Square.h"
#include "Square.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

void GraphicsWorld::run() {
    cout << "Authored by Abhilash Paul & Seethal Elias\n" << endl;
#if 1 // Change 0 to 1 to test Point
    Point m(6, 8);
    Point n(6, 8);
    n.set_x(9);
    cout << "Distance between m and n is: "
         << m.distance(n) << endl;
    
    Point p(3, 4);
    cout << "Distance between m and p is: "
         << Point::distance(m, p) << endl;
    
    Point q(5, 6);
    cout << "\nTesting the assignment operator in class Point:" << endl;
    q = p;
    cout << "The new coordinates of q are: " << q.get_x() << ", " << q.get_y() << endl;
    
    cout << "\nTesting the copy constructor in class Point:" << endl;
    Point r = p;
    cout << "The coordinates of r are: " << r.get_x() << ", " << r.get_y() << endl;
    
    cout << "\nTesting Point::counter:" << endl;
    cout << "Number of Point objects: " << Point::counter() << endl;
#endif // end of block to test Point

#if 1 // Change 0 to 1 to test Square
    cout << "\nTesting class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
#endif // end of block to test Square

#if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting class Rectangle:" << endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    
    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();
    
    double d = a.distance(b);
    cout << "Distance between rectangles a and b is: " << d << endl;
    
    Rectangle rec1 = a;
    rec1.display();
    
    cout << "\nTesting assignment operator in class Rectangle:" << endl;
    Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    cout << "\nRectangle a after changes:" << endl;
    a.display();
    cout << "\nRectangle rec2 after assignment:" << endl;
    rec2.display();
#endif // end of block to test Rectangle

#if 1 // Change 0 to 1 to test using array of pointers and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" << endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh[2] = &rec1;
    sh[3] = &rec2;
    
    for (int i = 0; i < 4; i++)
        sh[i]->display();
#endif // end of block to test array of pointers and polymorphism
    
}
