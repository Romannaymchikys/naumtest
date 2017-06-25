#include <iostream>
#include <string>
#include "Point.h"
#include "Line.h"
#include "Book.h"
#include "PrettyPrint.h"

void testFunctionLine()
{
	Point pt1, pt2;
	pt1.setX(367);
	pt1.setY(30);
	pt2.setX(2.7);
	pt2.setY(250);
	std::cout << pt1.getX() << std::endl;
	Line l1(105, 105);
	Line l2(pt1, pt2);
	std::cout << l2.checkLiesPoint(pt1) << std::endl;
	std::cout << l2.chekHigherOrBelow(pt1) << std::endl;
	std::cout << l2.chekLies(8, 315) << std::endl;
	Point intersection = pointIntersect(l1, l2);
	std::cout << intersection.getX() << std::endl;
	std::cout << intersection.getY() << std::endl;
}
void testFunctionBook()
{
	Book book("Ray Bradbury", "FAHRENHEIT 451", " Moscow: publishing house <<E>> ", "1953", 317);
	book.informatbook();
}
void testFunctionPrettyPrint()
{
	PrettyPrint str("bfhhhhtgaa", "aaaaaa;ioaaaggoootyrjooooooooooedg");
	std::string s = str.conclusion();
	std::cout << s << std::endl;
	str.substitution(s);
	str.revolString(s);
}
int main()
{
	testFunctionLine();
	testFunctionBook();
	testFunctionPrettyPrint();
	return 0;
}


