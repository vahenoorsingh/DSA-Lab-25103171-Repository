#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(vector<int> &a)
{
    buildHeap(a);
    for (int i = a.size() - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter integers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}