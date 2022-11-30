/******************************************************************************
��������� ���� ������������
����1-2
������������ ������ �5 �����������
������� � 4
�������: ��������   ���������,   �������   ����������   �   ����������  �  ����  ���������  ��������  ���������   ��������   �������.
� ��������  �����������  �����  ���������  ������������  ������ ���������. 
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
    int points_count=0;//�� ����� ��������� ����� ����������� ����������
};

typedef FootBall_command* P_command; //������ ��������

void Sort�ommand(P_command p[], int n)// ����� �
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
void resize(int& n, FootBall_command*& arr)//���������� ����������� ������� ��������
{
    int newSize = n + 1;
    FootBall_command* newArr = new FootBall_command[newSize];

    copy(arr, arr + n, newArr);

    n = newSize;
    
    arr = newArr;
}
void Search(P_command p[], int n)// ����� �
{   
    cout << "������� ��� ������� ��� ������" << endl;
    string Name;
    cin >> Name;
    bool U = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i]->name == Name)
        {
            cout << "�� ������ ������� ������� �������" << endl;
            cout << "�������� ������� " << p[i]->name << ".���������� ������� " << p[i]->players_count << ".������� ������� " <<
                p[i]->coach_LastName << ".����� " << p[i]->city << ".���������� ��� " << p[i]->games_count << ".���������� ����� "
                << p[i]->points_count << " " << endl;
            U = 1;
        }
    }
    if (U == 0) 
    {
        cout << "������ 322 ������� �� �������"<<endl;
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
    FootBall_command* F = new FootBall_command[N];//�������� ������
    P_command* p = new P_command[N];
    while (true) 
    {
        cout << "������ ������� - 1" << endl;
        cout << "����� ������� �� ����� - 2" << endl;
        cout << "������������� ������� �� ���������� ����� - 3" << endl;
        cout << "������� � ���� ��� ������� - 4" << endl;
        cout << "������� � ������� ��� ������� - 5" << endl;
        cout << "��������� - 6" << endl;
        cout << "***********************************************************************************************************************" << endl;
        cin >> question;
        if (question == "1")// ��������
        {
            for (int i = count; i < count+1; i++)
            {
                cout << "������� ��� �������" << endl;
                cin >> F[i].name;
                cout << "������� ������� �������" << endl;
                cin >> F[i].coach_LastName;
                cout << "����� �������" << endl;
                cin >> F[i].city;
                cout << "���������� ���" << endl;
                cin >> F[i].games_count;
                cout << "���������� �����" << endl;
                cin >> F[i].points_count;
                cout << endl;
                resize(N, F);
                cout << "***********************************************************************************************************************" << endl;
            }
            count++;
        }
        if (question == "2")//��������
        {
            p = new P_command[N];//�������� ������
            for (int i = 0; i < N; i++)
            {
                p[i] = &F[i];//������ ������
            }
            Search(p, N);
            cout << "***********************************************************************************************************************" << endl;
        }
        if (question == "3")//�� ��������
        {
            p = new P_command[N];
            for (int i = 0; i < N-1; i++)
            {
                p[i] = &F[i];//������ ������
            }
            Sort�ommand(p, N-1);
            fout << "***********************************************************************************************************************" << endl;
            for (int i = 0; i < N - 1; i++)
            {
                fout << "�������� ������� " << p[i]->name << ".���������� ������� " << p[i]->players_count << ".������� ������� " <<
                    p[i]->coach_LastName << ".����� " << p[i]->city << ".���������� ��� " << p[i]->games_count << ".���������� ����� "
                    << p[i]->points_count << " " << endl;
            }
            fout << "***********************************************************************************************************************" << endl;
        }
        if (question == "4")// ��������
        {
            
            for (int i = 0; i < N-1; i++)
            {
                fout << "�������� ������� " << F[i].name << ".���������� ������� " << F[i].players_count << ".������� ������� " <<
                    F[i].coach_LastName << ".����� " << F[i].city << ".���������� ��� " << F[i]. games_count << ".���������� ����� "
                    << F[i].points_count << " " << endl;
            }
        }
        if (question == "5")//��������
        {
            for (int i = 0; i < N-1; i++)
            {
               cout << "�������� ������� " << F[i].name << ".���������� ������� " << F[i].players_count << ".������� ������� " <<
                    F[i].coach_LastName << ".����� " << F[i].city << ".���������� ��� " << F[i].games_count << ".���������� ����� "
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