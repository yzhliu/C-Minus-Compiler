int main(void)
{
	int i; int sum;
	i = 1; sum = 0;
	while (i <= 100) {
		sum = sum + i;
		i = i + 1;
	}
	output(sum);
	
	return 0;
}
