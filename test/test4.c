int fib(int n)
{
	int result;
	if (n < 2)
		return n;
	
	result = fib(n-1) + fib(n-2);
	return result;
}

int main(void)
{
	int n; int i;
	i = 0;
	n = input();
	while (i <= n) {
		output(fib(i));
		i = i + 1;
	}

	return 0;
}
