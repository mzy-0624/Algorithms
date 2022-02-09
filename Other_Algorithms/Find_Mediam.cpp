#include <bits/stdc++.h>
using namespace std;
class Mediam {
	priority_queue<int>                            qmin;	// <= mediam
	priority_queue<int, vector<int>, greater<int>> qmax;	// >  mediam
public:
	Mediam() {}
	void AddNum(int num)
	{
		if (qmin.empty() || num <= qmin.top())
		{
			qmin.push(num);
			if (qmax.size() + 1 < qmin.size())
			{
				qmax.push(qmin.top());
				qmin.pop();
			}
		}
		else
		{
			qmax.push(num);
			if (qmax.size() > qmin.size())
			{
				qmin.push(qmax.top());
				qmax.pop();
			}
		}
	}
	double FindMediam(void)
	{
		if (qmin.size() - 1 == qmax.size())
			return qmin.top();
		return (qmin.top() + qmax.top()) / 2.0;
	}
};
int main(void)
{
	Mediam m;
	int op, num;
	while (cin >> op)
		switch (op)
		{
			case 0:			// add num
				cin >> num;
				m.AddNum(num);
				break;
			case 1:
				cout << m.FindMediam() << endl;
				break;
		}
	return 0;

}
