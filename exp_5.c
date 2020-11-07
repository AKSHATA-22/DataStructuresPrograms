//Queueimplementation
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3
int qu[MAX];
int FRONT=-1,REAR=-1;
void insert()
{
  int num;
 printf("\n Enter the number to be inserted in the queue : ");
 scanf("%d",&num);
if(REAR== MAX-1)
printf("\n OVERFLOW");
else if(FRONT == -1 && REAR == -1)
FRONT = REAR = 0;
else
REAR++;
qu[REAR] = num;
}
int dlt()
{
  int val;
  if(FRONT == -1 || FRONT>REAR)
  {
  printf("\n UNDERFLOW");
  return -1;
  }
  else
  {
  val = qu[FRONT];
  FRONT++;
  if(FRONT > REAR)
  FRONT = REAR = -1;
  return val;
  }
}
void display()
{
  int i;
if(FRONT == -1 || FRONT > REAR)
printf("\n QUEUE IS EMPTY");
else
{
for(i = FRONT;i <=REAR;i++)
printf("\t %d", qu[i]);
}
}
int main() {
	int ch,v;
  do{
  printf("\nEnter your choice:\n1.INSERT\n2.DELETE\n3.SHOW THE QUEUE\n4.EXIT\n");
  scanf("%d",&ch);
  switch(ch){
  case 1:
  insert();
  break;
  case 2:
  v=dlt();
  if(v!=-1)
  printf("Deleted number: %d",v);
  break;
  case 3:
  display();
  break;
}
}while(ch!=4);
getch();
  return 0;
}