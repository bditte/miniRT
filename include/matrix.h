#ifndef MATRIX_H
# define MATRIX_H

typedef	struct	s_matrix
{
	t_vector u;
	t_vector v;
	t_vector w;
	float	m11;
	float	m12;
	float	m21;
	float	m22;
	float	det;
	float	beta;
}		t_matrix;

# endif
