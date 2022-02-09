// if not define __EASYTEST__, please not use sort whose time complexity is O(n^2)
// defined in Makefile  LEVEL ?= EASY
// make LEVEL=HARD test
#ifdef __EASYTEST__
    #define maxn 10000
    #define minn 1000
#else
	#define maxn 1000000
	#define minn 10000
#endif
#define output_format   "%15s: time %7ums, %s\n"
#define bound           0, n - 1
#define str(x) 			#x
#define green(s) 		"\033[1;32m" str(s) "\033[0m"
#define red(s)   		"\033[1;31m" str(s) "\033[0m"
#define SORT(type) 		s.type ## _sort(bound)
#define sec             * 1U
#define ms              * 1000U sec
#define us              * 1000U ms
#define result			s.check(bound) ? green(Accepted) : red(Wrong)
#define rand_data                                                                           \
    do {                                                                                    \
        for (int j = 0; j < n; j++)                                                         \
        {                                                                                   \
            s.nums[j] = dice();                                                             \
            s.maximum = std::max(s.maximum, s.nums[j]);                                     \
            s.minimum = std::min(s.minimum, s.nums[j]);                                     \
        }                                                                                   \
    } while (0)
#define sort_and_check(type)																\
	do {																					\
		printf("%15s: sorting...\r", str(type ## _sort));									\
		fflush(stdout);																		\
		clock_t begin = clock(), end;														\
		SORT(type);																			\
		end = clock();																		\
		unsigned sort_time = (end - begin) * 1.0 / CLOCKS_PER_SEC * 1 ms;					\
		printf(output_format, str(type ## _sort), sort_time, result);						\
	} while (0)
