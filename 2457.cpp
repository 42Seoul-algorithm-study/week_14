// 공주님의 정원

#include <iostream>
#include <algorithm>
using namespace	std;

int	start, e_nd, max_end;

bool	ft_cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first < b.first);
}

int	f(pair<int, int> *date, int *i, int n)
{
	int	flag = 0;

	while (date[*i].first <= start) // start보다 date[i] start가 작으면 통과
	{
		if (max_end < date[*i].second) // 최고로 오래살아있는애 maxend 에 넣어줌
			max_end = date[*i].second;
		(*i)++;
		flag = 1;
		if (*i >= n) // 인덱스 초과시
			return (1);
	}
	return (flag);
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int	n, res = 0;

	cin >> n;

	start = 301;
	e_nd = 301;
	pair<int, int> date[n];
	for (int i = 0; i < n; i++)
	{
		int month, day;
		cin >> month >> day;
		date[i].first = month * 100 + day;
		cin >> month >> day;
		date[i].second = month * 100 + day;
	}
	sort(date, date + n, ft_cmp);
	// for (int i = 0; i < n; i++)
		// cout << "start: " << date[i].first << " e_nd: " << date[i].second << '\n';
	int i = 0;
	while (e_nd <= 1130) // 1130 초과야여함
	{
		if (i >= n)
		{
			cout << '0';
			return 0;
		}
		if (f(date, &i, n))
		{
			res++;
			start = max_end;
			e_nd = max_end;
			max_end = 0;
			//  cout << "res: " << res << " i: " << i << " start: " << start << " end: " << e_nd << '\n';
		}
		else
		{
			cout << '0';
			return 0;
		}
	}
	cout << res;
}

