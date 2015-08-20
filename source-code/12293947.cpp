//Language: GNU C++11


//In the name of god

#include <bits/stdc++.h>

using namespace std;

int a[3], b[3], situation[3];

void next()
{
	int i = 0;

	situation[i]++;
	swap(a[i], b[i]);

	while(situation[i] == 2)
	{
		situation[i] = 0;

		i++;

		situation[i]++;

		swap(a[i], b[i]);
	}
}

bool check()
{
	if((a[1] + a[2] <= a[0] && b[0] >= max(b[1], b[2])) || (b[1] + b[2] <= b[0] && a[0] >= max(a[1], a[2])))
		return 1;

	return 0;
}

int main()
{
	bool mk = 0;

	for (int i = 0; i < 3; i++)
		cin >> a[i] >> b[i];

	for (int i = 0; i < 8; i++)
	{
		if(check())
		{
			mk = 1;
			break;
		}

		next();
	}

	if (mk)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
