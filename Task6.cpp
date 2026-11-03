#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int Task6()
{
    int N; //кол-во раундов в турнире 
    cin >> N;

    int m = (int)pow(2, N);//кол-во участников

    int** data = new int* [m];//призовые i-участника за j-побед
    for (int i = 0; i < m; i++)
    {
        data[i] = new int[N];
    }
    //считываем призовые
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> data[i][j];
        }
    }

    //решение 
    vector<int>choicePlayers;//каждый вектор внутри содержит выиграшного участника,
    //один и тот же может содержаться несколько раз, потом просто считаем сколько раз он встретился,
    //значит столько раз и выиграл

    int degreeCountNode = 0;//степень двойки на каждом раунде для кол-ва человек
    //начиная со старшего раунда, на каждом раунде надо выбрать 2 в какой-то степени человек
    int n = N;
    while (n > 0)//пока не закончатся все раунды, начинаем с последнего раунда
    {
        int countPlayers = (int)pow(2, degreeCountNode);//сколько участников надо выбрать на текущем раунде
        for (size_t i = 0; i < countPlayers; i++)//перебор кол-ва групп
        {
            vector<int> numberChoicePlayer;//запомним подходящих участников из группы, если их несколько потом просто выберем одного
            //если в группе есть участник, который выиграл в раунде выше, то он должен выиграть здесь
            bool flag = true;
            for (auto player : choicePlayers)
            {
                if (player >= i * m / countPlayers && player < (i + 1) * m / countPlayers)
                {
                    numberChoicePlayer.push_back(player);//этот игрок сразу считается подходящим 
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                long long maxMoney = -1;
                //сначала определим максимальный балл в группе
                for (size_t j = i * m / countPlayers; j < (i + 1) * m / countPlayers; j++)//перебор участников среди определенной группы
                {
                    if (maxMoney < data[j][n - 1])
                    {
                        maxMoney = data[j][n - 1];
                    }

                }
                //после цикла выше определили какой максимальный балл в группе за раунд

                //перебор участников - цикл устроен так, что участники делятся на такое кол-во групп, сколько надо выбрать людей на текущем раунде
                for (size_t j = i * m / countPlayers; j < (i + 1) * m / countPlayers; j++)//перебор участников среди определенной группы
                {
                    //участников может оказаться несколько потом будем выбирать
                    if (maxMoney == data[j][n - 1])//если у участника максимальный балл для этой группы запоминаем его
                    {
                        numberChoicePlayer.push_back(j);//запоминаем номер участника
                    }
                }
            }
            //теперь, если среди выбранных участников оказалось их больше 1, надо выбрать подходящего
            if (numberChoicePlayer.size() > 1)
            {

                //алгоритм выбора подходящего участника:
                //если выгоднее(в рамках этой задачи), чтобы участник не прошел дальше предыдушего раунда, то он не подходит на текущем

                long long diff = n - 2 >= 0 ? data[numberChoicePlayer[0]][n - 1] - data[numberChoicePlayer[0]][n - 2] : data[numberChoicePlayer[0]][n - 1];//разница очков, на текущем и предыдущем, у кого она больше, того и оставляем
                int indexBestPlayer = 0;
                for (size_t p = 1; p < numberChoicePlayer.size(); p++)
                {
                    long long currDiff = n - 2 >= 0 ? data[numberChoicePlayer[p]][n - 1] - data[numberChoicePlayer[p]][n - 2] : data[numberChoicePlayer[p]][n - 1];
                    if (currDiff > diff)
                    {
                        indexBestPlayer = p;
                        diff = currDiff;
                    }
                }
                //в итоге выбрали indexBestPlayer Игрока
                choicePlayers.push_back(numberChoicePlayer[indexBestPlayer]);
            }
            else
            {
                //просто запонимаем этого участника
                choicePlayers.push_back(numberChoicePlayer[0]);
            }
        }
        degreeCountNode++;
        n--;
    }
    //теперь надо правильно посчитать деньги
    unordered_map<int, int> dict;//каждому игроку из списка, который хоть раз выигрывал соответсвует сколько-то очков
    for (auto player : choicePlayers)
    {
        if (dict.count(player) == 0)
        {
            dict[player] = 1;
        }
        else
        {
            dict[player] = dict[player] + 1;
        }
    }
    long long countMoney = 0;//кол-во всех денег
    //перебор словаря и подсчет итоговых очков-денег
    for (auto pair : dict)
    {
        countMoney += data[pair.first][pair.second - 1];
    }
    cout << countMoney;
    //очищаем память
    for (int i = 0; i < m; i++)
    {
        delete[]data[i];
    }
    delete[]data;
    return 0;
}