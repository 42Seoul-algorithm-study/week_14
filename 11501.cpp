// 주식

#include <iostream>
using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int	n;
	cin >> n;
	while (n--)
	{
		int	arrlen;
		long long res = 0;
		cin >> arrlen;
		int	arr[arrlen];
		for (int i = 0; i < arrlen; i++)
			cin >> arr[i];
		int max = arr[arrlen - 1];
		for (int i = arrlen - 1; i >= 0; i--)
		{
			if (max > arr[i])
				res += max - arr[i];
			else if (max < arr[i])
				max = arr[i];
		}
		cout <<  res << '\n';
	}
}
