// atm

#include <iostream>
using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int	n, res = 0;

	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) // 싹다 어레이에 넣어주고 정렬
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			res += arr[j];
	}
	cout << res;
}
