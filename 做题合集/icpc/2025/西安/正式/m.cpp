#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
inline long long qpow(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long fl = 0, num1 = 0, numi = 0, tn = 0, mi = 0, ans = 1, num, n, m;
	cin >> n >> m;
	vector<vector<int>> fi(n + 1, vector<int>(2));
	vector<int> a(n);
	num = m - n + 1;
	fi[1][0] = num;
	fi[1][1] = 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] == -1)
		{
			numi++;
			tn++;
		}
		else
		{
			mi = max(mi, tn);
			tn = 0;
			if (a[i] == 1)
				num1++;
		}
	}
	for (int i = 2; i <= mi; i++)
	{
		fi[i][0] = (fi[i - 1][1] + fi[i - 1][0]) * num % MOD;
		fi[i][1] = fi[i - 1][0];
		fi[i][0]=(fi[i][0]+fi[i][1])%MOD;
	}
	fi[1][0]=num+1;
	tn = 0;
	if (num <= 0)
	{
		fl = 1;
	}
	for (int i = 0; i < n && !fl; ++i)
	{
		if (a[i] == -1)
		{
			if (i == 0 || i == n - 1 || a[i - 1] == 1 || a[i + 1] == 1)
			{
				if (tn)
				{
					ans = (ans * (fi[tn][0])) % MOD;
				}
				ans = (ans * num) % MOD;
				tn = 0;
			}
			else
			{
				tn++;
			}
		}
		else
		{
			if (tn)ans = (ans * (fi[tn][0])) % MOD;
			tn = 0;
			if (a[i] == 1)
			{
				if (i > 0 && a[i - 1] == 1)
					fl = 1;
			}
			else if (1 < a[i] && a[i] <= n - 1)
				fl = 1;
		}
	}
	if (tn)ans = (ans * (fi[tn][0])) % MOD;
	if (a[0] == 1 || a[n - 1] == 1) fl = 1;
	if (fl == 1)
	{
		if (num1 + numi == n && n % 2 == 1)ans = 1;
		else ans = 0;
	}
	else if (!numi)
	{
		cout<<0;
		return 0;
	}
	else if (num1 + numi == n && n % 2 == 1)ans = (ans + 1) % MOD;
	cout << (qpow(m, numi) - ans + MOD) % MOD;
	return 0;
}