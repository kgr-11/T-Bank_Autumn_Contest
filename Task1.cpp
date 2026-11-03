#include<iostream>
#include<algorithm>
using namespace std;

int Task1()
{
	int n;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	sort(mas, mas + n);
	//два наименьших элемента в одном множестве, остальные в других по одному элементу
	int value = mas[0] + mas[1];
	for (int i = 2; i < n; i++)
	{
		if (value != mas[i])
		{
			cout << "NO";
			delete[]mas;
			return 0;
		}
	}
	cout << "YES";
	delete[]mas;
	return 0;
}