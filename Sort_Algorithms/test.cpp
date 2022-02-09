#include "sort.h"
#include "test.h"
#include <ctime>
using namespace std;
int main(void)
{
    random_device rd;
    default_random_engine engine(rd());
    uniform_int_distribution<> dis(0, maxn);
    auto dice = bind(dis, engine);
    int test_times = 100;
    for (int i = 1; i <= test_times; i++)
    {
        int n;
        do {
            n = dice();
        } while (n < minn);
        printf("Case: %3d, Scale: n = %d\n", i, n);
        Sort s(n);
        rand_data;
        sort_and_check(bubble);
        sort_and_check(insertion);
        sort_and_check(shell);
        sort_and_check(selection);
        sort_and_check(heap);
        sort_and_check(merge);
        sort_and_check(quick);
        sort_and_check(counting);
    }
    return 0;
}
