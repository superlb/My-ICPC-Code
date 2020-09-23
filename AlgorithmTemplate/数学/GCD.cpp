//辗转相除法
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b, a % b);
}
int qGCD(int a, int b)
{
	if(a == 0) return b;
	if(b == 0) return a;
	if(!(a & 1) && !(b & 1))
		return qGCD(a >> 1, b >> 1) << 1;
	else if(!(b & 1))
		return qGCD(a, b >> 1);
	else if(!(a & 1))
		return qGCD(a >> 1, b);
	else
		return qGCD(abs(a - b), min(a, b));
}
//拓展欧几里得算法
int extgcd(int a, int b, int& x, int& y)
{
    int d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;y = 0;
    }
    return d;
}
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extgcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}
//线性求逆元，p是质数
int inv[MAXN];
inv[1] = 1;
for(int i = 2; i < p; ++ i)
    inv[i] = (p - p / i) * inv[p % i] % p;
