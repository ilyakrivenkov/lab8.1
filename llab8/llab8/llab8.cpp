#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <queue>
#include <iostream>

int n;

int M[4][4] = { 0, 1, 1, 0, 
				1, 0, 0, 1, 
			    1, 0, 0, 0, 
			    0, 1, 0, 0 };
int** G;
int* num;

void makeGraf()
{
	srand(time(NULL));
	printf("������� ���������� ������ = ");
	scanf_s("%d", &n);
	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}
}

void printGraf()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}
}


void BFS(int v)
{
	int* num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
	}
	printf("�������\n");
	std::queue <int> q;
	num[v] = 1;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf("%d ", v + 1);
		for (int i = 0; i < n; i++)
		{
			if (G[v][i] == 1 && num[i] == 0)
			{
				q.push(i);
				num[i] = num[v] + 1;
			}
		}
	}
	printf("\n");
	printf("����������\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
}


int main(void)
{
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	makeGraf();
	printGraf();
	int v;
	printf("������� ������� ");
	scanf_s("%d", &v);
	v--;
	BFS(v);
}