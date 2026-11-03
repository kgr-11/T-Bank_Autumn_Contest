#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool checkWin(vector<int>v1, vector<int>v2, int diag1, int diag2, int n)
{
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] == n || v2[i] == n)
            return true;
    }
    if (diag1 == n || diag2 == n)
        return true;
    return false;
}
int Task3()
{
    int n, t;
    cin >> n >> t;
    vector<int>vec_row(n, 0);
    vector<int>vec_col(n, 0);
    int diag1 = 0;
    int diag2 = 0;

    int ans = -1;
    //дальше логика следующая: делаем ход -  проверяем победу
    for (int i = 0; i < t; i++)
    {
        int step;
        cin >> step;
        //сейчас определяем координаты клетки, которую закрашиваем
        int x = step % n == 0 ? (step / n) : step / n + 1;//номер строки
        int y = step - n * (x - 1);//номер столбца
        //индексы матрицы
        x--;
        y--;
        //записываем ход
        vec_row[x] += 1;
        vec_col[y] += 1;
        if (x == y)
            diag1++;
        if (x + y + 1 == n)
            diag2++;

        //проверяем победу
        if (checkWin(vec_col, vec_row, diag1, diag2, n))
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}