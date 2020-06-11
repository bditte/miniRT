#include "miniRT.h"

t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	t_vector result;
	
	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

t_vector	vec_multiply_t(float t, t_vector vec)
{
	t_vector result;

	result.x = t * vec.x;
	result.y = t * vec.y;
	result.z = t * vec.z;
	return (result);
}

void		vec_display(t_vector vec)
{
	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);
}

float		dot(t_vector vec1, t_vector vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vector	vec_sub(t_vector vec1, t_vector vec2)
{
	t_vector result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}
