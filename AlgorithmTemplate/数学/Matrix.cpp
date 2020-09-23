//矩阵及快速幂
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
const int M=10000;
mat mul(mat &a,mat &b)
{
    mat c(a.size(),vec(b[0].size()));
    for(int i=0;i<a.size();++i)
        for(int k=0;k<b.size();++k)
            for(int j=0;j<b[0].size();++j)
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % M;
    return c;
}
//矩阵快速幂
mat pow(mat a,ll n)
{
    mat b(a.size(),vec(a.size()));
    for(int i=0;i<a.size();++i)
        b[i][i]=1;
    while (n > 0)
    {
        if (n & 1) b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}
//快速幂
long long mod_pow(long long x,long long n,long long mod)
{
    long long res=1;
    while (n>0)
    {
        if(n & 1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

//快速乘
long long int fun(long long int a ,long long int b , long long int m)
{
    int sum=0;
    int k=1;
    while(b)
    {
        if(b&1)
        {
            sum=(sum+a*k)%m;
        }
        k=(k*2)%m;
        b=b/2;
    }
}
