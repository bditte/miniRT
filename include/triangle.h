#ifndef TRIANGLE_H
# define TRIANGLE_H

typedef	struct	s_triangle
{
	t_vector a;
	t_vector b;
	t_vector c;
	t_vector color;
}		t_triangle;

t_triangle      create_triangle(t_vector x, t_vector y, t_vector z, t_vector color);
# endif
