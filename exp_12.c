//GraphTraversal
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 10
int qu[MAX], adj[5][5];
int st[MAX], top = -1;
int status[5];
int FRONT = -1, REAR = -1;
void insert(int num)
{
    status[num] = 2;
    if (REAR == MAX - 1)
        printf("\n OVERFLOW");
    else if (FRONT == -1 && REAR == -1)
        FRONT = REAR = 0;
    else
        REAR++;
    qu[REAR] = num;
}
int dlt()
{
    int val;
    if (FRONT == -1 || FRONT > REAR)
    {
        return -1;
    }
    else
    {
        val = qu[FRONT];
        FRONT++;
        if (FRONT > REAR)
            FRONT = REAR = -1;
        return val;
    }
}
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
    for (int i = 0; i < 5; i++)
    {
        status[i]=1;
    }
    printf("\n DEPTH FIRST SEARCH: \n");
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
void bfs(int adj[5][5])
{
     for (int i = 0; i < 5; i++)
    {
        status[i]=1;
    }
    printf("\n BREADTH FIRST SEARCH: \n");
    int t = 0;
    status[0] = 2;
    while (t != -1)
    {
        for (int j = 0; j < 5; j++)
        {
            if (adj[t][j] == 1 && status[j] == 1)
            {
                insert(j);
            }
        }
        printf("%c ", 65 + t);
        t = dlt();
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
    bfs(adj);
    dfs(adj);
    return 0;
}
