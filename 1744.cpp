// 수 묶기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int	n, zero = 0,res = 0, plus_idx = -1;

	cin >> n;
	vector<int>	plus, minus;

	for (int i = 0; i < n; i++)
	{
		int	num;
		cin >> num;
		if (num == 1) // 1은 곱하면 쌉손해
			res++;
		else if (num == 0) // 0은 음수가 홀수일때 하나 처리해 주기 위해 필요
			zero = 1;
		else if (num < 0)
			minus.push_back(num);
		else if (num > 0)
			plus.push_back(num);
	}
	if (minus.size())
		sort(minus.begin(), minus.end());
	if (plus.size())
		sort(plus.begin(), plus.end());
	if (minus.size() % 2)
	{
		if (zero == 0)
			res += minus.back();
		minus.pop_back();
	}
	for (int i = 0; i < minus.size(); i += 2)
		res += minus[i] * minus[i + 1];
	int i = 0;
	if (plus.size() % 2)
	{
		res += plus.front();
		i = 1;
	}
	while (i < plus.size())
	{
		res += plus[i] * plus[i + 1];
		i += 2;
	}
	cout << res;
}

