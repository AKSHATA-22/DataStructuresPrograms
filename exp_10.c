//queueusinglinkedlist
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;
struct node *insert(struct node *front)
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data : ");
  scanf("%d",&new_node->data);
  if(front==NULL)
  {
  	front=new_node;
    new_node->next=NULL;
    rear=front;
  }
  else
  {
  front->next=new_node;
  new_node->next=NULL;
  front=new_node;
}
printf("data added: %d",front->data);
return front;
}
struct node *delete(struct node *rear)
{
  struct node *p;
  p=rear;
  if(p==NULL)
    printf("\nThe queue is empty. ");
    
  else
  {
   if(p->next==NULL)
     rear=front=NULL;
   else  
     rear=rear->next;
   free(p);
  }
  return rear;
}
struct node *display(struct node *rear) {
  struct node *p;
  if(rear==NULL)
  {
    printf("\nQueue is empty.");
    return rear;
  }
  else
  {
  p=rear;
  while(p!=front)
  {
    //  printf("while");
    printf(" %d ",p->data);
    p=p->next;
  }
   printf(" %d \n",p->data);  
  return rear;
    }
}
int main()
{
    int ch;
    do
    {
      printf("\nEnter your choice:\n1.INSERT\n2.DELETE\n3.SHOW THE QUEUE\n4.EXIT\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
          front=insert(front);
          break;
        case 2:
           rear=delete(rear);
           break;
        case 3:
           rear=display(rear);
           break;
      }
       }while (ch!=4);
    return 0;
}