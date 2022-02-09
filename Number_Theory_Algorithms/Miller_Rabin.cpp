#include <bits/stdc++.h>
using namespace std;
#define Prime			false
#define Probably_Prime 	false
#define One				true
#define Composite	   	true
#define witness			true
#define nonwitness		false
class Miller_Rabin {
	long long n;
public:
	Miller_Rabin(long long n)
	{
		this->n = n;
	}
	long long pow_mod(long long a, long long b, long long m)
	{
		long long res = 1;
		a %= m;
		while (b)
		{
			if (b & 1)
				res = (a * res) % m;
			b >>= 1;
			a = (a * a) % m;
		}
		res %= m;
		return res;
	}
	bool Witness(long long a, int s, long long d)
	{
		a = pow_mod(a, d, n);
		long long y = 0;
		for (int i = 0; i < s; i++)
		{
			y = pow_mod(a, 2, n);
			if (y == 1 && a != 1 && a != (n - 1))
				return witness;
			a = y;
		}
		if (y != 1)
			return witness;
		return nonwitness;
	}
	bool Miller_Rabin_Test(int k)
	{
		if (n == 2 || n == 3)
			return Prime;
		if (n & 1 == 0)
			return Composite;
		if (n == 1)
			return One;
		srand((unsigned)time(NULL));
		long long d = n - 1;
		int s = 0;
		while (!(d & 1))
		{
			s++;
			d >>= 1;
		}
		while (k--)
		{
			long long a = rand() % (n - 3) + 2;
			if (Witness(a, s, d) == witness)
				return Composite;
		}
		return Probably_Prime;
	}
};
int main(void)
{
	int k;
	cin >> k;
	while (k--)
	{
		long long n;
		cin >> n;
		// Check whether n is prime
		Miller_Rabin MR(n);
		if (MR.Miller_Rabin_Test(1) == Composite)
			cout << "False\n";
		else
			cout << "True\n";
	}
	return 0;
}
