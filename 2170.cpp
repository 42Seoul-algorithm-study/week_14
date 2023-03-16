// 선 긋기

#include <algorithm>
#include <iostream>// 입출력 가능하게 하는 헤더
using namespace	std;

int	main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int	n, max_len, start, endd;

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
	start = arr[0].first;
	endd = arr[0].second;
	max_len = endd - start;
	int	t_start, t_endd, t_max_len;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first > endd)
		{
			endd = arr[i].second;
			max_len = endd - start;
		}
		else
		{
			while (i < n && arr[i].first > t_endd)
			{
				t_endd = arr[i].second; 
			}
		}

		// cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}
