#include <vector>
#include <random>
#include <iostream>
#include <functional>
#define sort_type(sort_name)    void sort_name(int l, int r)
class Sort {
private:
    void max_heapify(int root, int l, int r);
    void merge(int l, int m, int r);
public:
    int n, maximum, minimum;
    std::vector<int> nums;
    Sort (int n);
    ~Sort(void);
    // Comparison sort
    sort_type(bubble_sort);         // bubble_sort      O(n^2)
    sort_type(insertion_sort);      // insert_sort      O(n^2)
    sort_type(shell_sort);          // shell_sort       O(n^1.3)
    sort_type(selection_sort);      // select_sort      O(n^2)
    sort_type(heap_sort);           // heap_sort        O(nlogn)
    sort_type(merge_sort);          // merge_sort       O(nlogn)
    sort_type(quick_sort);          // quick_sort       O(nlogn)
    // Linear time sort
    sort_type(counting_sort);       // counting_sort    O(n)
    // Other functions
    bool check(int l, int r);
};