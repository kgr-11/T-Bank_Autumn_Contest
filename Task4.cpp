#include<iostream>
using namespace std;

void foo(int* mas, int n, int k)
{
    //двигаем большее число влево
    for (int s = 0; s < n - 1; s++)//
    {
        for (int i = n - 1; i > s; i--)
        {
            swap(mas[i], mas[i - 1]);
            k--;
            if (k == 0)
                return;
        }
    }
}

int Task4()
{
    int n, k;
    cin >> n >> k;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
        mas[i] = i + 1;
    if (k != 0)
    {
        foo(mas, n, k);
    }
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    delete[]mas;
    return 0;
}