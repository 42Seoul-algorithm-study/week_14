// 선 긋기

#include <algorithm>
#include <iostream>// 입출력 가능하게 하는 헤더
using namespace	std;

int	main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int	n, res = 0, start = -1000000000, endd = -1000000000;

	cin >> n;
	pair<int, int>	arr[n];
	for (int i = 0; i < n; i++)
	{
		int	a, b;
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i].first <= endd)
			endd = max(endd, arr[i].second);
		else
		{
			res += endd - start;
			start = arr[i].first;
			endd = arr[i].second;
		}
		// cout << start << " " << res << " " << endd << '\n';
	}
	res += endd - start;
	cout << res;
}
