#include<iostream>
#include<algorithm>
using namespace std;

int Task5()
{
    long long n, k;
    cin >> n >> k;
    int* mas = new int[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    //решение
    //формируем множество S
    long long  m = (long long)(n * (n - 1)) / 2;
    int* S = new int[m];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            S[count] = mas[i] * mas[j];
            count++;
        }
    }
    sort(S, S + m);
    cout << S[k - 1];
    delete[]mas;
    delete[]S;
    return 0;
}