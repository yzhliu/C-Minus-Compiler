int gcd(int u, int v)
{
	if (v == 0)
		return u;
	else
		return gcd(v, u - u / v * v);
}

int main(void)
{
	int x;
	int y;
	x = input();
	y = input();
	output(gcd(x, y));

	return 0;
}
