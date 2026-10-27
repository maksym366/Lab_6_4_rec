#include <iostream>
#include <iomanip>
using namespace std;

// Рекурсивне введення елементів масиву
void inputArray(double* a, int n, int i)
{
    if (i >= n)
        return;

    cout << "a[" << i << "] = ";
    cin >> a[i];

    inputArray(a, n, i + 1);
}

// Рекурсивне виведення масиву
void printArray(const double* a, int n, int i)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(10) << fixed << setprecision(2) << a[i];

    printArray(a, n, i + 1);
}

// Рекурсивний пошук мінімального елемента
double findMin(const double* a, int n, int i)
{
    if (i == n - 1)
        return a[i];

    double minRest = findMin(a, n, i + 1);

    return (a[i] < minRest) ? a[i] : minRest;
}

// Пошук індексу першого додатного елемента
int findFirstPositive(const double* a, int n, int i)
{
    if (i >= n)
        return -1;

    if (a[i] > 0)
        return i;

    return findFirstPositive(a, n, i + 1);
}

// Пошук індексу останнього додатного елемента
int findLastPositive(const double* a, int n, int i)
{
    if (i < 0)
        return -1;

    if (a[i] > 0)
        return i;

    return findLastPositive(a, n, i - 1);
}

// Рекурсивне обчислення суми елементів між індексами
double sumBetween(const double* a, int i, int last)
{
    if (i >= last)
        return 0;

    return a[i] + sumBetween(a, i + 1, last);
}

// Рекурсивне підрахування нульових елементів
int countZeros(const double* a, int n, int i)
{
    if (i >= n)
        return 0;

    return (a[i] == 0 ? 1 : 0) + countZeros(a, n, i + 1);
}

// Рекурсивне копіювання нулів у новий масив
void copyZeros(const double* a, double* b, int n,
    int i, int& j)
{
    if (i >= n)
        return;

    if (a[i] == 0)
        b[j++] = a[i];

    copyZeros(a, b, n, i + 1, j);
}

// Рекурсивне копіювання ненульових елементів
void copyNonZeros(const double* a, double* b, int n,
    int i, int& j)
{
    if (i >= n)
        return;

    if (a[i] != 0)
        b[j++] = a[i];

    copyNonZeros(a, b, n, i + 1, j);
}

int main()
{
    int n;

    cout << "Enter number of elements n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be greater than 0." << endl;
        return 1;
    }

    double* a = new double[n];
    double* b = new double[n];

    cout << "Enter array elements:" << endl;
    inputArray(a, n, 0);

    cout << "\nOriginal array:" << endl;
    printArray(a, n, 0);

    // 1. Мінімальний елемент
    cout << "\nMinimum element: "
        << fixed << setprecision(2)
        << findMin(a, n, 0) << endl;

    // 2. Сума між першим і останнім додатними елементами
    int first = findFirstPositive(a, n, 0);
    int last = findLastPositive(a, n, n - 1);

    if (first == -1 || last == -1 || first >= last)
    {
        cout << "Sum between the first and last positive "
            << "elements: 0" << endl;
    }
    else
    {
        cout << "Sum between the first and last positive "
            << "elements: "
            << sumBetween(a, first + 1, last) << endl;
    }

    // 3. Переставлення: спочатку нулі, потім інші елементи
    int j = 0;

    copyZeros(a, b, n, 0, j);
    copyNonZeros(a, b, n, 0, j);

    cout << "\nModified array:" << endl;
    printArray(b, n, 0);

    delete[] a;
    delete[] b;

    return 0;
}