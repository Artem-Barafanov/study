#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
mt19937 mt(time(nullptr));

// Функция преобразования в тернарную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(vector<int>& arr, int n, int i)
{
    // Инициализируем наибольший элемент как корень

    int largest = i;
    int child_1 = 1; // первый сын
    int child_2 = 2; // второй сын
    int child_3 = 3; // третий сын
    
    if (i != 0) {
        child_1 = 3 * (i + 1) - 2; 
        child_2 = 3 * (i + 1) - 1; 
        child_3 = 3 * (i + 1);
    }

    // Если первый дочерний элемент больше корня
    if (child_1 < n && arr[child_1] > arr[largest])
        largest = child_1;

    // Если второй дочерний элемент больше, чем самый большой элемент на данный момент
    if (child_2 < n && arr[child_2] > arr[largest])
        largest = child_2;

    // Если третий дочерний элемент больше, чем самый большой элемент на данный момент
    if (child_3 < n && arr[child_3] > arr[largest])
        largest = child_3;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(vector<int>& arr, int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = (n-2) / 3; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем функцию heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

/* Вспомогательная функция для вывода на экран массива размера n*/
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

    // подсчёт времени работы пирамидальной сортировки
    auto start1 = std::chrono::steady_clock::now();
    heapSort(arr, n);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time1 = end1 - start1;
    cout << "Time of Heap_sort - " << time1.count() << '\n';

    // std::cout << "Sorted array is \n";
    // printArray(arr, n);
    // printArray(arr_copy, n);
}
