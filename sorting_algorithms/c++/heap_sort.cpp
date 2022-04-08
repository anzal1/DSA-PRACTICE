#include <bits/stdc++.h>
using namespace std;

// heapsort uses max heap data structure
// building a max heap or min  heap

void heap_sort(int a[], int n)
{
    build_heap(a, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int x = a[i];
        a[i] = a[0];
        a[0] = x;
        max_heapify(a, i, 0);
    }
}

void build_heap(int a[], int n)
{
    for (int i = (n - 2) / 2; i > 0; i--)
    {
        max_heapify(a, n, i);
    }
}

void max_heapify(int a[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        int x = a[i];
        a[i] = largest;
        largest = x;
        max_heapify(a, n, largest);
    }
}