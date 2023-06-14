#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{ 
    Vector v1(1, 2, 3);
    Vector v2;
    std::cout << "po deklaracji\n";
    v1.add(v2);
    std::cout << "po dodaniu\n";
    v1.show_vector();
    std::cout << "po pokazaniu\n";
    Vector* v3 = new Vector(1, 0, 9);
    Vector* v4 = new Vector();
    v1.add( *v3);
    v1.show_vector();
    
    std::cout <<"\nId vectora utworzonego jako pierwszy: " << v1.GetId() << "\n";
    std::cout <<"Id vectora utworzonego jako drugi: " << v2.GetId() << "\n\n";
    std::vector<Vector> *vectors = new std::vector<Vector> {v1, v2, *v3, *v4};
    

    std::cout << "Wektory:\n";
    for (auto& elem : *vectors)
    {        
        elem.show_vector();
    }
    std::cout << "\n";
    
    delete vectors;

    delete v3;
    delete v4;
    std::cout << "po delatach\n";
    
}


