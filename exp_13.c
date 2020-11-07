//Graphtraversal_2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
int st[MAX], top = -1, adj[5][5];
int status[5] = {1, 1, 1, 1, 1};
void push(int val)
{
	status[val] = 2;
	if (top == MAX - 1)
	{
		printf("\n STACK OVERFLOW");
	}
	else
	{
		top++;
		st[top] = val;
	}
}
int pop()
{
	int val;
	if (top == -1)
	{
		//printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		val = st[top];
		top--;
		return val;
	}
}
void dfs(int adj[5][5])
{
	int t = 0;
	status[0] = 2;
	while (t != -1)
	{
		for (int j = 0; j < 5; j++)
		{
			if (adj[t][j] == 1 && status[j] == 1)
			{
				push(j);
			}
		}
		printf("%c ", 65 + t);
		t = pop();
		status[t] = 3;
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf("%d", &adj[i][j]);
	}
	dfs(adj);
	return 0;
}