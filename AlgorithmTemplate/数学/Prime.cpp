//质数相关算法
bool is_prime(int a)
{
    for (int i = 2;i * i <= a;i++)
    {
        if (a % i == 0)return false;
    }
    return n != 1;
}
//埃氏筛数，1~n
int prime[MAXN];
int is_prime[MAXN+1];
int sieve(int n)
{
    int p=0;
    memset(is_prime, 0, sizeof(is_prime));
    is_prime[0] = 1;is_prime[1] = 1;
    for(int i = 2;i <= n;++i)
    {
        if(is_prime[i] == 0)
        {
            prime[p++] = i;
            for(int j = 2 * i;j <= n;j+=i)
                is_prime[j] = 1;
        }
    }
    return p;
}
//筛质数，a~b
typedef long long ll;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];
void segment_sieve(ll a,ll b)
{
    for(ll i = 0;i * i < b;++i)
        is_prime_small[i] = true;
    for(ll i = 0;i * i < b - a;++i)
        is_prime[i] = true;
    for(ll i = 2;i * i< b;++i)
    {
        if(is_prime_small[i])
        {
            for(ll j=2*i;j*j<b;j+=i)
                is_prime_small[j]=false;
            for(ll j = max(2LL, (a+i-1)/i) * i; j < b;j += i)
                is_prime[j-a] = false;
        }
    }
}
