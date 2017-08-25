#include <iostream>
#include <string>
#include "bird.h"
#include "Cat.h"
#include "Dog.h"
#include "Humster.h"
#include "Parrot.h"
#include "Pet.h"
//###################################################
#include "Circle.h"
#include "Parallelogram.h"
#include "Parrot.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

//Наследование
void testInheritance() {
	Cat Maks("Maks", "Ay", "Cat");
	std::cout << Maks.getType()  << std::endl;
	std::cout << Maks.getShow()  << std::endl;
	std::cout << Maks.getSound() << std::endl;
	std::cout << std::endl;

	Dog Baks("Baks", "Af", "Dog");
	std::cout << Baks.getType()  << std::endl;
	std::cout << Baks.getShow()  << std::endl;
	std::cout << Baks.getSound() << std::endl;
	std::cout << std::endl;

	Humster Graf("Graf", "frfrfr", "Humster");
	std::cout << Graf.getType()  << std::endl;
	std::cout << Graf.getShow()  << std::endl;
	std::cout << Graf.getSound() << std::endl;
	std::cout << std::endl;

	parrot Kesha("Kesha", "kesha", "Parrot");
	std::cout << Kesha.Pet::getType()  << std::endl;
	std::cout << Kesha.Pet::getShow()  << std::endl;
	std::cout << Kesha.Pet::getSound() << std::endl;
	std::cout << std::endl;
}
//####################################################
void testHierarchyOfGeometricShapes() {
	//Triangle _triangle(12.3, 21.34, (size_t)34);
	Triangle _triangle(15.34, 60, 60, 2);
	Shape* _shape = new Shape;
	Triangle* _t = &_triangle;
	std::cout << _t->getThirdSide() << std::endl;
	std::cout << _t->getSecondSide() << std::endl;
	std::cout << _t->getFirstSide() << std::endl;
	std::cout << _t->getFirstAngle() << std::endl;
	std::cout << _t->getSecondAngle() << std::endl;
	std::cout << _t->getThirdAngle() << std::endl;
	std::cout << _t->getArea() << std::endl;
	_shape->setArea(100);
	std::cout << _shape->getArea() << std::endl;
	Square _squre(12, 12, 12);
	Square* _sq = &_squre;
	std::cout << _sq->getArea() << std::endl;
}
void main()
{
	testInheritance();                // Task 1
	testHierarchyOfGeometricShapes(); // Task 2
	system("pause");
}