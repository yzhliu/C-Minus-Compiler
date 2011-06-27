int gcd(int u, int v)
{
    if (v == 0)
        return u;
    else
        return gcd(v, u-u/v*v);
}

int main(void)
{
    int x; int y;
    x = 100; y = 50;
    output(gcd(x, y));

    return 0;
}
