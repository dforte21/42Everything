#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){

	float pa, a1, a2, a3;
	float px, x1, x2, x3, py, y1, y2, y3;

	if (point == a || point == c || point == b)
		return (false);

	px = point.getX();
	x1 = a.getX();
	x2 = b.getX();
	x3 = c.getX();

	py = point.getY();
	y1 = a.getY();
	y2 = b.getY();
	y3 = c.getY();

	pa = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	a1 = abs((px * (y2 - y3) + x2 * (y3 - py) + x3 * (py - y2)) / 2);
	a2 = abs((x1 * (py - y3) + px * (y3 - y1) + x3 * (y1 - py)) / 2);
	a3 = abs((x1 * (y2 - py) + x2 * (py - y1) + px * (y1 - y2)) / 2);

	if (pa == (a1 + a2 + a3))
		return (true);
	return (false);
}