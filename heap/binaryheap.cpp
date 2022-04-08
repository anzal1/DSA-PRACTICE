#include <bits/stdc++.h>
using namespace std;

// heap implementation

class Minheap
{
    int *harr;
    int capacity;
    int heap_size;

    Minheap(int cap)
    {
        capacity = cap;
        heap_size = 0;
        harr = new int[cap];
    }

    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(Minheap *h, int k)
    {
        if (heap_size == capacity)
        {
            cout << "Overflow: Could not insertKey" << endl;
            return;
        }
        heap_size++;
        harr[heap_size - 1] = k;
        for (int i = heap_size - 1; i > 0 && harr[parent(i)] > harr[i]; i = parent(i))
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void min_heapify(Minheap *h, int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            min_heapify(h, smallest);
        }
    }

    void build_min_heap(Minheap *h)
    {
        for (int i = heap_size / 2 - 1; i >= 0; i--)
            min_heapify(h, i);
    }

    int extract_min(Minheap *h)
    {
        if (heap_size <= 0)
        {
            cout << "Underflow: Could not extractKey" << endl;
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        min_heapify(h, 0);
        return root;
    }

    void decrease_key(Minheap *h, int i, int new_val)
    {
        harr[i] = new_val;
        while (i > 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void delete_key(Minheap *h, int i)
    {
        decrease_key(h, i, INT_MIN);
        extract_min(h);
    }

  
};