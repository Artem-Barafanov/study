#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
mt19937 mt(time(nullptr));

// ������� �������������� � ��������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

void heapify(vector<int>& arr, int n, int i)
{
    // �������������� ���������� ������� ��� ������

    int largest = i;
    int child_1 = 1; // ������ ���
    int child_2 = 2; // ������ ���
    int child_3 = 3; // ������ ���
    
    if (i != 0) {
        child_1 = 3 * (i + 1) - 2; 
        child_2 = 3 * (i + 1) - 1; 
        child_3 = 3 * (i + 1);
    }

    // ���� ������ �������� ������� ������ �����
    if (child_1 < n && arr[child_1] > arr[largest])
        largest = child_1;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (child_2 < n && arr[child_2] > arr[largest])
        largest = child_2;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (child_3 < n && arr[child_3] > arr[largest])
        largest = child_3;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, n, largest);
    }
}

// �������� �������, ����������� ������������� ����������
void heapSort(vector<int>& arr, int n)
{
    // ���������� ���� (�������������� ������)
    for (int i = (n-2) / 3; i >= 0; i--)
        heapify(arr, n, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i >= 0; i--)
    {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // �������� ������� heapify �� ����������� ����
        heapify(arr, i, 0);
    }
}

/* ��������������� ������� ��� ������ �� ����� ������� ������� n*/
void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

// main
int main()
{
    const int n = 100000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = (mt() /* %100 */);

    vector<int> arr_copy(n);
    for (int i = 0; i < n; i++)
        arr_copy[i] = arr[i];
    
    // printArray(arr, n);

    // ������� ������� ������ ������������� ����������
    auto start1 = std::chrono::steady_clock::now();
    heapSort(arr, n);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time1 = end1 - start1;
    cout << "Time of Heap_sort - " << time1.count() << '\n';

    // std::cout << "Sorted array is \n";
    // printArray(arr, n);
    // printArray(arr_copy, n);
}
