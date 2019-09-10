#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum=0;
	int num1[9000];
	int num2[9000];
	int num3[9000];
	int num4[9000];
	int num5[9000];
	int num6[9000];
	int num7[9000];
	int num8[9000];
	int num9[9000];
	int num10[9000];
	cin >> n;
	if(n>=10 && n<=30)
	{
		for (int d1 = 1; d1 <= 3; ++d1)
		{
			for (int d2 = 1; d2 <= 3; ++d2)
			{
				for (int d3 = 1; d3 <= 3; ++d3)
				{
					for (int d4 = 1; d4 <= 3; ++d4)
					{
						for (int d5 = 1; d5 <= 3; ++d5)
						{
							for (int d6 = 1; d6 <= 3; ++d6)
							{
								for (int d7 = 1; d7 <= 3; ++d7)
								{
									for (int d8 = 1; d8 <= 3; ++d8)
									{
										for (int d9 = 1; d9 <= 3; ++d9)
										{
											for (int d10 = 1; d10 <= 3; ++d10)
											{
												if (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 == n)
												{
													num1[sum] = d1;
													num2[sum] = d2;
													num3[sum] = d3;
													num4[sum] = d4;
													num5[sum] = d5;
													num6[sum] = d6;
													num7[sum] = d7;
													num8[sum] = d8;
													num9[sum] = d9;
													num10[sum] = d10;
													++sum;
												}

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << sum <<endl;
	for (int i = 0; i < sum; ++i)
	{
		cout << num1[i] << " " << num2[i] << " " << num3[i] << " " << num4[i] << " " << num5[i] << " " << num6[i] << " " << num7[i] << " " << num8[i] << " " << num9[i] << " " << num10[i] << endl;
	}
	return 0;
}
