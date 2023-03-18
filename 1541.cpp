// 잃어버린 괄

#include <iostream>
#include <cstring>
using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	char	s[51];
	int	n = 0, res = 0, minus = 1, tmp = 0;

	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		while (s[i] && s[i] <= '9' && s[i] >= '0')
			n = n * 10 + s[i++] - '0';
		if (s[i] == '+')
		{
			tmp += n;
			n = 0;
		}
		else if (s[i] == '-' || s[i] == '\0')
		{
			tmp += n;
			res += minus * tmp; // 처음 한번만 더하고 그 후부턴 빼기만 해야함
			tmp = 0;
			n = 0;
			minus = -1;
		}
		if (s[i] == '\0')
		{
			cout << res;
			return 0;
		}
		// cout << "i: " << i << " n: " << n << " tmp: " << tmp << " res:" << res << '\n';

	}
}

