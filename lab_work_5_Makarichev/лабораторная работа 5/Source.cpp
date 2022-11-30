/******************************************************************************
Макаричев Семён Вячеславович
КТбо1-2
Лабораторная работа №5 «структуры»
Вариант № 4
Задание: Написать   программу,   которая   записывает   с   клавиатуры  в  файл  структуру  согласно  выданному   варианту   задания.
В качестве  разделителя  полей  структуры  использовать  символ табуляции. 
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

struct FootBall_command
{
    string name;
    string city;
    string coach_LastName;
    int players_count = 11;
    int games_count=0;
    int points_count=0;//по этому эллементу будет происходить сортировка
};

typedef FootBall_command* P_command; //создаём симноним

void SortСommand(P_command p[], int n)// пункт Г
{
    P_command temp;
    for (int i = 0; i < n-1 ; i++)
    {
        for (int j = n - 2; j >= i; j--)
        {
            if (p[j + 1]->points_count < p[j]->points_count)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void resize(int& n, FootBall_command*& arr)//увеличение размерности массива структур
{
    int newSize = n + 1;
    FootBall_command* newArr = new FootBall_command[newSize];

    copy(arr, arr + n, newArr);

    n = newSize;
    
    arr = newArr;
}
void Search(P_command p[], int n)// пункт Б
{   
    cout << "Введите имя команды для поиска" << endl;
    string Name;
    cin >> Name;
    bool U = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i]->name == Name)
        {
            cout << "По вашему запросу найдена команда" << endl;
            cout << "Название команды " << p[i]->name << ".Количество игроков " << p[i]->players_count << ".Фамилия тренера " <<
                p[i]->coach_LastName << ".Город " << p[i]->city << ".Кодичество игр " << p[i]->games_count << ".Количество очков "
                << p[i]->points_count << " " << endl;
            U = 1;
        }
    }
    if (U == 0) 
    {
        cout << "ошибка 322 Команда не найдена"<<endl;
    }
}
int main()
{
    int N = 1;
    int count=0;
    string question;
    system("chcp 1251");
    cout << "***********************************************************************************************************************" << endl;
    ofstream fout("F1.txt");
    FootBall_command* F = new FootBall_command[N];//выделяем память
    P_command* p = new P_command[N];
    while (true) 
    {
        cout << "Ввести команду - 1" << endl;
        cout << "Найти команды по имени - 2" << endl;
        cout << "Отсортировать команды по количеству очков - 3" << endl;
        cout << "Вывести в файл все команды - 4" << endl;
        cout << "Вывести в консоль все команды - 5" << endl;
        cout << "Закончить - 6" << endl;
        cout << "***********************************************************************************************************************" << endl;
        cin >> question;
        if (question == "1")// работает
        {
            for (int i = count; i < count+1; i++)
            {
                cout << "Введите имя команды" << endl;
                cin >> F[i].name;
                cout << "Введите фамилию тренера" << endl;
                cin >> F[i].coach_LastName;
                cout << "Город команды" << endl;
                cin >> F[i].city;
                cout << "Количество игр" << endl;
                cin >> F[i].games_count;
                cout << "Количество очков" << endl;
                cin >> F[i].points_count;
                cout << endl;
                resize(N, F);
                cout << "***********************************************************************************************************************" << endl;
            }
            count++;
        }
        if (question == "2")//работает
        {
            p = new P_command[N];//выделяем память
            for (int i = 0; i < N; i++)
            {
                p[i] = &F[i];//взятие адреса
            }
            Search(p, N);
            cout << "***********************************************************************************************************************" << endl;
        }
        if (question == "3")//не работает
        {
            p = new P_command[N];
            for (int i = 0; i < N-1; i++)
            {
                p[i] = &F[i];//взятие адреса
            }
            SortСommand(p, N-1);
            fout << "***********************************************************************************************************************" << endl;
            for (int i = 0; i < N - 1; i++)
            {
                fout << "Название команды " << p[i]->name << ".Количество игроков " << p[i]->players_count << ".Фамилия тренера " <<
                    p[i]->coach_LastName << ".Город " << p[i]->city << ".Кодичество игр " << p[i]->games_count << ".Количество очков "
                    << p[i]->points_count << " " << endl;
            }
            fout << "***********************************************************************************************************************" << endl;
        }
        if (question == "4")// работает
        {
            
            for (int i = 0; i < N-1; i++)
            {
                fout << "Название команды " << F[i].name << ".Количество игроков " << F[i].players_count << ".Фамилия тренера " <<
                    F[i].coach_LastName << ".Город " << F[i].city << ".Кодичество игр " << F[i]. games_count << ".Количество очков "
                    << F[i].points_count << " " << endl;
            }
        }
        if (question == "5")//работает
        {
            for (int i = 0; i < N-1; i++)
            {
               cout << "Название команды " << F[i].name << ".Количество игроков " << F[i].players_count << ".Фамилия тренера " <<
                    F[i].coach_LastName << ".Город " << F[i].city << ".Кодичество игр " << F[i].games_count << ".Количество очков "
                    << F[i].points_count << " " << endl;
               cout << "***********************************************************************************************************************" << endl;
            }
        }
        if (question == "6")
        {
            delete[]F;
            
            fout.close();
           exit(1);
        }
    }
    
}