#include "Fixed.hpp"
#include "Point.hpp"

/*

 	a, b, c: The vertices of our beloved triangle.
	
	point: The point to check.

	Returns: True if the point is inside the triangle. False otherwise.

	Thus, if the point is a vertex or on edge, it will return False.

	ref: https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle#:~:text=A%20simple%20way%20is%20to,point%20is%20inside%20the%20triangle.

*/

bool	point_is_a_vertex(Point point, Point vertex)
{
	if ( (point.getX() == vertex.getX()) && (point.getY() == vertex.getY()))
		return (1);
	else
		return (0);
}

bool	is_a_triangle(Point const a, Point const b, Point const c)
{
	Fixed ax, bx, cx, x = 0;
	Fixed ay, by, cy, y = 0;

	ax = a.getX();
	ay = a.getY();
 	bx = b.getX();
 	by = b.getY();
 	cx = c.getX();
 	cy = c.getY();

 	if ((ax == bx) && (bx == cx))
 		return (0);
 	if ((ay == by) && (by == cy))
 		return (0);
 	if ((ax == bx) && (ay == by))
 		return (0);
  	if ((ax == cx) && (ay == cy))
 		return (0);
   	if ((bx == cx) && (by == cy))
 		return (0);
 	return (1);
}

bool	on_the_edge(Fixed side_1, Fixed side_2, Fixed side_3)
{
	if (side_1 == 0 || side_2 == 0 || side_3 == 0)
		return (1);
	return (0);
}

bool	is_inside_triangle(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ax, bx, cx, x = 0;
	Fixed ay, by, cy, y = 0;
	Fixed side_1, side_2 , side_3 = 0;

	x = point.getX();
	y = point.getY();
	ax = a.getX();
	ay = a.getY();
 	bx = b.getX();
 	by = b.getY();
 	cx = c.getX();
 	cy = c.getY();

   	side_1 = (x - bx) * (ay - by) - (ax - bx) * (y - by);
    side_2 = (x - cx) * (by - cy) - (bx - cx) * (y - cy);
    side_3 = (x - ax) * (cy - ay) - (cx - ax) * (y - ay);
    if (on_the_edge(side_1, side_2, side_3))
    {
    	std::cerr << "Point is on an edge." << std::endl;
    	return (0);
    }
 	if ((side_1 < 0) && (side_2 < 0) && (side_3 < 0))
 		return (1);
 	else if ((side_1 > 0) && (side_2 > 0) && (side_3 > 0))
 		return (1);
 	else
 	{
 		std::cerr << "Point is outside of the triangle." << std::endl;
 		return(0);
 	}
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (!is_a_triangle(a, b, c))
 	{
 		std::cerr << "Points do not depict a triangle." << std::endl;
 		return (0);
 	}
	if (point_is_a_vertex(point, a) || point_is_a_vertex(point, b) || point_is_a_vertex(point, c))	
	{
		std::cerr << "Point is a vertex." << std::endl;
 		return (0);
	}
 	if (is_inside_triangle(a, b, c, point))
 		return (1);
 	return (0);
}
