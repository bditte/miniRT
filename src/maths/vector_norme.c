#include "miniRT.h"

float getNorme2(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vector vec_normalize(t_vector vec)
{
	float norme;
	t_vector result;

	norme = sqrt(getNorme2(vec));
	result.x = vec.x / norme;
	result.y = vec.y / norme;
	result.z = vec.z / norme;
	return (result);
}


