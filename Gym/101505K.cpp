#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    string alp[26];
    alp[0]=".-";
    alp[1]="-...";
    alp[2]="-.-.";
    alp[3]="-..";
    alp[4]=".";
    alp[5]="..-.";
    alp[6]="--.";
    alp[7]="....";
    alp[8]="..";
    alp[9]=".---";
    alp[10]="-.-";
    alp[11]=".-..";
    alp[12]="--";
    alp[13]="-.";
    alp[14]="---";
    alp[15]=".--.";
    alp[16]="--.-";
    alp[17]=".-.";
    alp[18]="...";
    alp[19]="-";
    alp[20]="..-";
    alp[21]="...-";
    alp[22]=".--";
    alp[23]="-..-";
    alp[24]="-.--";
    alp[25]="--..";
    while(cin>>str)
    {
        int last=0;
        int q=str.find("/",last);
        string str1;
        while(q!=-1)
        {
            str1=str.substr(last,q-last);
            if(str1=="")
            {
                cout<<" ";
            }
            else
            {
                for(int i=0;i<26;++i)
                {
                    if(alp[i]==str1)
                    {
                        char c='A'+i;
                        cout<<c;
                        break;
                    }
                }
            }
            last=q+1;
            q=str.find("/",last);
        }
        str1=str.substr(last,str.length()-last);
        for(int i=0;i<26;++i)
        {
            if(alp[i]==str1)
            {
                char c='A'+i;
                cout<<c;
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
