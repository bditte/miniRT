float	ft_min(float a, float b)
{
	if (b > a)
		return (a);
	return (b);
}

float	ft_max(float a, float b)
{
	if (b < a)
		return (a);
	return (b);
}

float	sqr(float t)
{
	return (t*t);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||c == '\r' 
			||c == ' ')
		return (1);
	return (0);
}
/*
int main(void)
{
	float b;

	b = 100000.00;
	printf("%f\n", ft_min(255, 10000));
}*/
