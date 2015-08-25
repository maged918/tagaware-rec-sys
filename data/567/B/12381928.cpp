//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
int main()
{
	int n;
	si(n)
	int i, num, count=0, maxc=0;
	int arr[1000010] = {0};
	char sign;
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c", &sign);
		si(num);
		if(sign == '+'){
			count += 1;
			arr[num] = 1;
			maxc = max(maxc, count);
		}
		else {
			if(arr[num] == 0)
				maxc += 1;
			else {
				arr[num] = 0;
				count -= 1;
			}
		}
	}
	pi(maxc);
	return 0;
}

