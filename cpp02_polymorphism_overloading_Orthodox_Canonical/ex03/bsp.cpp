#include "Fixed.hpp"
#include "Point.hpp"

 // x, y = point
 //    ax, ay = triangle[0]
 //    bx, by = triangle[1]
 //    cx, cy = triangle[2]
 //    # Segment A to B
bool	is_inside_triangle(const Point& t1, const Point& t2, const Point& t3, const Point& p)
{
	Fixed side_1, side_2, side_3 = 0;
	Fixed x, ax, bx, cx, y, ay, by, cy = 0;

	x = p.getX();
	y = p.getY();
	ax = t1.getX();
	ay = t1.getY();
	bx = t2.getX();
	by = t2.getY();
	cx = t3.getX();
	cy = t3.getY();
    side_1 = (x - bx) * ((ay - by) - (ax - bx)) * (y - by);
    // Segment B to C
    side_2 = (x - cx) * ((by - cy) - (bx - cx)) * (y - cy);
    // # Segment C to A
    side_3 = (x - ax) * ((cy - ay) - (cx - ax)) * (y - ay);
    // All the signs must be positive or all negative
    std::cout << side_1 << " " << side_2 << " " << side_3 << std::endl;
    return (side_1 < 0) && (side_2 < 0) && (side_3 < 0);
}

bool area_calc(const Point& t1, const Point& t2, const Point& t3, const Point& p)
{
	Fixed ABC, PAB , PBC , PAC = 0;
	Fixed x, ax, bx, cx, y, ay, by, cy = 0;


	x = p.getX();
	y = p.getY();
	ax = t1.getX();
	ay = t1.getY();
	bx = t2.getX();
	by = t2.getY();
	cx = t3.getX();
	cy = t3.getY();

    ABC = (ax *(by - cy) + bx *(cy - ay) + cx *(ay - by))/2;
    PAB = (x *(ay - by) + ax *(by - y) + bx *(y - ay))/2;
    PBC = (x *(by - cy) + bx *(cy - y) + cx *(y - by))/2;
    PAC = (x *(cy - ay) + ax * (cy - y) + cx *(y - ay))/2;
 	
 	if (ABC == (PAB + PBC + PAC))
 		return (1);
 	else
 		return (0);
}
