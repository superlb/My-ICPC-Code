#include <iostream>
using namespace std;
int main()
{
  int n;
  int a1,b1,a2,b2,a3,b3;
  int beishu,min;
  cin>>n>>a1>>b1>>a2>>b2>>a3>>b3;
  beishu=n/a1;
  if(n==a1*beishu)
  {
    min=b1*beishu;
  }
  else
  {
    min=b1*(beishu+1);
  }
  beishu=n/a2;
  if(n==a2*beishu)
  {
    min=(b2*beishu<min)?(b2*beishu):min;
  }
  else
  {
    min=(b2*(beishu+1)<min)?(b2*(beishu+1)):min;
  }
  beishu=n/a3;
  if(n==a3*beishu)
  {
    min=(b3*beishu<min)?(b3*beishu):min;
  }
  else
  {
    min=(b3*(beishu+1)<min)?(b3*(beishu+1)):min;
  }
  cout<<min;
  return 0;
}
