//Circularqueue
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
if(FRONT==-1 && REAR== MAX-1 || FRONT==0 && REAR== MAX-1 ||FRONT-REAR==1)
{
printf("\n ****OVERFLOW**** \n");
}
else
{
if(FRONT == -1 && REAR == -1)
FRONT = REAR = 0;
else if(REAR==MAX-1 && FRONT!=0)
REAR=0;
else
REAR++;
qu[REAR] = num;
}
//printf("%d %d\n",FRONT,REAR );
}
int dlt()
{
  int val;
  if(FRONT == -1 && REAR==-1)
  {
  printf("\n UNDERFLOW");
  return -1;
  }
  else
  {
  val = qu[FRONT];
  if(FRONT == REAR)
  FRONT = REAR = -1;
  else
  {
    if(FRONT==MAX-1)
    FRONT=0;
    else
    FRONT++;
  }
  return val;
  }
}
void display()
{
  int i,j;
 // printf("%d %d\n",FRONT,REAR );
if( FRONT == REAR)
printf("\n QUEUE IS EMPTY");
else if( REAR<FRONT)
{
  for (i = FRONT; i < MAX; i++) {
    printf("\t %d", qu[i]);
  }
  
	for (j = 0; j<=REAR; j++) {
    printf("\t %d", qu[j]);
  }
  
}
else{
for(i = FRONT;i <=REAR;i++){
printf("\t %d", qu[i]);
}
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
  printf("Deleted number: %d\n",v);
  break;
  case 3:
  display();
  break;
}
}while(ch!=4);
getch();
  return 0;
}