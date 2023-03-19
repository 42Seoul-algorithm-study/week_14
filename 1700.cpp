// 멀티탭 스케줄링

#include <algorithm>
#include <vector>
#include <iostream>// 입출력 가능하게 하는 헤더
using namespace	std;

vector<int>	plug, input;
int	n, k;
int	cnt = 0;

int	find_device(int	target)
{
	int	res = 0;

	for (int i = 0; i < plug.size(); i++)
		if (plug[i] == target)
			res = 1;
	return (res);
}

void	take_out_low_use_device(int out_idx)
{
	vector <int> tmp(plug); // 그대로 복사
	int	low_use_dev = -1;

	for (int i = out_idx; i < k && tmp.size() > 1; i++) // 전부 다 돌고, 제일 오래 안쓰는 놈 찾음
	{
		for (int j = 0; tmp.size() > 1 && j < tmp.size(); j++)
			if (input[i] == tmp[j])
				tmp.erase(tmp.begin() + j); // tmp 의 바로 또 사용하는 기기 뺌
	}
	// for (int i = 0; i < tmp.size(); i++)
	// 	cout << tmp[i] << ' ';
	for (int i = 0; i < plug.size(); i++)
		if (tmp[0] == plug[i])
			plug.erase(plug.begin() + i); // 플러그 뺌
	cnt++;
}

int	main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int	num;
		cin >> num;
		input.push_back(num);
	}
	for (int i = 0; i < k; i++)
	{
		if (find_device(input[i]) == 0) // 플러그에 꽃힌 디바이스가 아닐때
		{
			if (plug.size() >= n) // 플러그에 공간이 없을때
				take_out_low_use_device(i);
			plug.push_back(input[i]); // 꽂음
		}
		// for (int i = 0; i < plug.size(); i++)
		// 	cout << plug[i] << ' ';
		// cout << '\n';
	}
	cout << cnt;
}
