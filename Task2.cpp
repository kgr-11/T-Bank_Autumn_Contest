#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

bool comp(string s1, string s2)
{
	int len = s1.size() < s2.size() ? s1.size() : s2.size();
	for (int i = 0; i < len; i++)
	{
		if (s1[i] != s2[i])
			return s1[i] < s2[i];
	}
	return s1.size() < s2.size();
}

int Task2()
{
	int n;
	cin >> n;
	unordered_map<string, int>map;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (map.count(str) == 0)
		{
			map[str] = 1;
		}
		else
		{
			map[str] = map[str] + 1;
		}
	}
	//ищем максимальное кол-во 
	int max_count = -1;
	for (auto iter = map.cbegin(); iter != map.cend(); iter++)
	{
		if (max_count < iter->second)
			max_count = iter->second;
	}
	//сохраняем строки с макс кол-во вхождений в вектор
	vector<string>vec;
	for (auto iter = map.cbegin(); iter != map.cend(); iter++)
	{
		if (max_count == iter->second)
		{
			vec.push_back(iter->first);
		}
	}
	//сортируем и выводим
	sort(vec.begin(), vec.end(), comp);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
	return 0;
}