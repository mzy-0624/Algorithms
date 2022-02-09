#include <stdio.h>
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// Example1:	n = 13
// number		1	2	3	4	5	6	7	8	9	10	11	12	13
// count of 1	1	0	0	0	0	0	0	0	0	1	2	1	1	total: 6
int num_of_digit_one(int n)
{
	int digit = 1, res = 0, high = n / 10, cur = n % 10, low = 0;
	while (high || cur)
	{
		if (cur == 0)
			res += high * digit;
		else if (cur == 1)
			res += high * digit + low + 1;
		else
			res += (high + 1) * digit;
		low += cur * digit;
		cur = high % 10;
		high /= 10;
		digit *= 10;
	}
	return res;
}
// Example2:	n = 105
// digit = 1 	--> current digit
// res = 0	 	--> the result
// high = 10	--> the high bit
// cur = 5		--> current bit
// low = 0		--> the low bit
//
// cur == 5		--> res += (high + 1) * digit = 11
// low += cur * digit = 5
// cur = high % 10 = 0
// high /= 10 	--> high = 1
// digit *= 10  --> digit = 10
//
// cur == 0		--> res += high * digit = 11 + 10 = 21
// low += cur * digit = 5
// cur = high % 10 = 1
// high /= 10	--> high = 0
// digit *= 10	--> digit = 100
//
// cur == 1		--> res += high * digit + low + 1 = 21 + 6 = 37
// low += cur * digit = 105
// cur = high % 10 = 0
// high /= 10   --> high = 0
// digit *= 10  --> digit = 1000
//
// return res = 27

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", num_of_digit_one(n));
	return 0;
}
