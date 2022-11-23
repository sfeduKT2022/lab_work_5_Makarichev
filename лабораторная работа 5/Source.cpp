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
    for (int i = 0; i < n - 1; i++)
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
    int N = 3;
    string question;
    system("chcp 1251");
    setlocale(LC_ALL, "russian");
    ofstream fout("F1.txt");
    FootBall_command* F =new FootBall_command[N];//выделяем память
    P_command* p = new P_command[N];//выделяем память
    //заполнить структуру
    cout << "***********************************************************************************************************************" << endl;
    for (int i = 0; i < N; i++)
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
    }
    for (int i = 0; i < N; i++)
    {
        p[i] = &F[i];//взятие адреса
    }
    
    cout << "***********************************************************************************************************************" << endl;
    cout << "Вы хотите найти какую-то команду ? (да/нет)" << endl;
    cin >> question;
    if (question == "да")
    {
        FootBall_command* P = new FootBall_command[N ];
        for (int i = 0; i < N; i++)
        {
            p[i] = &F[i];//взятие адреса
        }
        Search(p, N);
    }
    else {}
    cout << "***********************************************************************************************************************" << endl;
    cout << "Вы хотите добавить команду ? (да, нет)"<<endl;
    cin >> question;
    int G;
    if (question == "yes" || question == "да") 
    {
        cout << "Сколько команд вы желаете добавить ?" << endl;
        cin >> G;
        int u = 0;
        for (int i = 3;u!=G; i++) 
        {
            resize(N, F);
            cout << "Введите имя команды" << endl;
            cin >>F[i].name;
            cout << "Введите фамилию тренера" << endl;
            cin >>F[i].coach_LastName;
            cout << "Город команды" << endl;
            cin >> F[i].city;
            cout << "Количество игр" << endl;
            cin >>F[i].games_count;
            cout << "Количество очков" << endl;
            cin >> F[i].points_count;
            cout << endl;
            u++;
        }
        cout << "***********************************************************************************************************************" << endl;
    }
    else
    {
        cout << "***********************************************************************************************************************" << endl;
        
    }
    for (int i = 0; i < N; i++)//пункт В
    {
        fout << "Название команды " << F[i].name << ".Количество игроков " << F[i].players_count << ".Фамилия тренера " <<
            F[i].coach_LastName << ".Город " << F[i].city << ".Количество игр " << F[i].games_count << ".Количество очков "
            << F[i].points_count << " " << endl;
    }
    fout << endl;
    P_command* P = new P_command[N];//выделяем память
    for (int i = 0; i < N; i++)
    {
        P[i] = &F[i];//взятие адреса
    }
    SortСommand(P, N);// пункт Г
    for (int i = 0; i < N; i++)//пункт В
    {
        fout << "Название команды " << P[i]->name << ".Количество игроков " << P[i]->players_count << ".Фамилия тренера " <<
            P[i]->coach_LastName << ".Город " << P[i]->city << ".Кодичество игр " << P[i]->games_count << ".Количество очков "
            << P[i]->points_count << " " <<endl;
    }
    //очистка памяти
    delete[]F;
    delete[]p;
    fout.close();
    return 0;
}