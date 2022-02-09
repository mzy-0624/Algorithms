#include <bits/stdc++.h>
using namespace std;

class Prime {
private:
	const int default_value = 1000000;
	vector<bool> is_not_prime;
	vector<int> primes;
	void sieve(int N)
	{
		is_not_prime[1] = true;
		for (int i = 4; i <= N; i += 2)
			is_not_prime[i] = true;
		for (int i = 3; (i * i) <= N; i += 2)
			if (!is_not_prime[i])
				for (int j = i * i; j <= N; j += (2 * i))
					is_not_prime[j] = true;
		for (int i = 2; i <= N; i++)
			if (!is_not_prime[i])
				primes.push_back(i);
	}
public:
	Prime (int N)
	{
		is_not_prime.resize(N + 1);
		sieve(N);
	}
	Prime ()
	{
		is_not_prime.resize(default_value + 1);
		sieve(default_value + 1);
	}
	int nr_prime(void)
	{
		return primes.size();
	}
	bool is_prime(int N)
	{
		return !is_not_prime[N];
	}
	int the_Nth_prime(int N)
	{
		return primes[N];
	}
};
int main(void)
{
	int N;
	cin >> N;
	Prime P(N);
	for (int i = 1; i <= N; i++)
		cout << i << ": " << (P.is_prime(i) ? "YES\n" : "NO\n");
	for (int i = 0; i < P.nr_prime(); i++)
		cout << P.the_Nth_prime(i) << " ";
	return 0;
}
