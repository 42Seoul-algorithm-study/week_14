// 잃어버린 괄

#include <iostream>
#include <cstring>
using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	char	s[51];
	int	n = 0, res = 0;

	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] <= '9' || s[i] >= '0')
			n = n * 10 + s[i] - '0';
		else if (s[i] == '+' || s[i] == '-')
		{
			res += n;
			n = 0;
		}
		cout << "i: " << i << " n: " << n << " res: " << res << '\n';
		if (s[i] == '-')
		{
			i++;
			while (s[i] && s[i] != '-') // 숫자가아니면
			{
				int	tmp = 0;
				i++;
				while (s[i] && s[i] <= '9' && s[i] >= '0')
					tmp = tmp * 10 + s[i++] - '0';
				res -= tmp;
			}
		}
	}
	cout << res;
}

