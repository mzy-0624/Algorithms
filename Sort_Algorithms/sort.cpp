#include "sort.h"
void Sort::max_heapify(int root, int l, int r)
{
    int node = l, left = node * 2 + 1 - root;
    while (left <= r)
    {
        if (left + 1 <= r && nums[left] < nums[left + 1])
            left++;
        if (nums[node] > nums[left])
            return;
        else
        {
            std::swap(nums[node], nums[left]);
            node = left;
            left = node * 2 + 1 - root;
        }
    }
}
void Sort::merge(int l, int m, int r)
{
    std::vector<int> t(r - l + 1);
    int p = l, q = m + 1, s = 0;
    while (p <= m && q <= r)
        t[s++] = nums[p] > nums[q] ? nums[q++] : nums[p++];
    while (p <= m)
        t[s++] = nums[p++];
    while (q <= r)
        t[s++] = nums[q++];
    for (int i = 0; i < r - l + 1; i++)
        nums[l + i] = t[i];
}
Sort::Sort(int n)
{
    this->n = n;
    this->maximum = 0;
    this->minimum = 0x7f7f7f7f;
    this->nums.resize(n);
}
Sort::~Sort(void)
{
    nums.clear();
}
// Comparison sort
void Sort::bubble_sort(int l, int r) // bubble_sort      O(n^2)
{
    for (int i = l; i <= r; i++)
        for (int j = r - 1; j >= l; j--)
            if (nums[j + 1] < nums[j])
                std::swap(nums[j + 1], nums[j]);
}
void Sort::insertion_sort(int l, int r) // insert_sort      O(n^2)
{
    for (int i = l; i <= r; i++)
    {
        int key = nums[i], j = i - 1;
        while (j >= l && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
void Sort::shell_sort(int l, int r) // shell_sort       O(n^1.3)
{
    int length = r - l + 1;
    int h = 1;
    while (h < length / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h + l; i <= r; i++)
            for (int j = i; j >= h + l && nums[j] < nums[j - h]; j -= h)
                std::swap(nums[j], nums[j - h]);
        h = h / 3;
    }
}
void Sort::selection_sort(int l, int r) // select_sort      O(n^2)
{
    for (int i = l; i <= r; i++)
    {
        int index = i;
        for (int j = i + 1; j <= r; j++)
            if (nums[index] > nums[j])
                index = j;
        std::swap(nums[index], nums[i]);
    }
}
void Sort::heap_sort(int l, int r) // heap_sort        O(nlogn)
{
    for (int i = (l + r - 1) / 2; i >= l; i--)
        max_heapify(l, i, r);
    for (int i = r; i > l; i--)
    {
        std::swap(nums[l], nums[i]);
        max_heapify(l, l, i - 1);
    }
}
void Sort::merge_sort(int l, int r) // merge_sort       O(nlogn)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;        // (l + r) / 2 = l + (r - l) / 2
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge(l, m, r);
    }
}
void Sort::quick_sort(int l, int r) // quick_sort       O(nlogn)
{
    if (l >= r)
        return;
    int i = l, j = r, base = nums[l];
    while (i < j)
    {
        while (nums[j] >= base && i < j)
            j--;
        while (nums[i] <= base && i < j)
            i++;
        if (i < j)
            std::swap(nums[i], nums[j]);
    }
    nums[l] = nums[i];
    nums[i] = base;
    quick_sort(l, i - 1);
    quick_sort(i + 1, r);
}
// Linear time sort
void Sort::counting_sort(int l, int r) // counting_sort    O(n)
{
    std::vector<int> cnt(maximum + 1, 0);
    std::vector<int> tmp(n + 1);
    for (int i = l; i <= r; i++)
        cnt[nums[i]]++;
    for (int i = minimum; i <= maximum; i++)
        cnt[i] += cnt[i - 1];
    for (int i = r; i >= l; i--)
        tmp[cnt[nums[i]]--] = nums[i];
    nums = tmp;
}
bool Sort::check(int l, int r) // increase
{
    for (int i = l; i < r; i++)
        if (nums[i] > nums[i + 1])
            return false;
    return true;
}
