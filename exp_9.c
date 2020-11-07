//stackusinglinkedlist
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct stack{
  int data;
  struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *top)
{
    struct stack *new_node;  
    new_node= (struct stack*)malloc(sizeof(struct stack));
    printf("\nEnter the data : ");
    scanf("%d",&new_node->data);
    if(top==NULL)
      new_node->next=NULL;
    else
      new_node->next=top;
    top=new_node;
    return top;
}
struct stack *pop(struct stack *top)
{
  struct stack *p;
  if(top==NULL)
    printf("\nStack Underflow. ");
  else
  {
   p=top;
   if(p->next==NULL)
     top=NULL;
   else  
     top=p->next;
     printf("\n%d is poped from the stack.",p->data);
   free(p);
  }
  return top;
}
struct stack *display(struct stack *top)
 {
  struct stack *temp;
  if(top==NULL)
  {
    printf("\nStack is empty.");
    return top;
  }
  else
  {
  temp=top;
  printf("\n");
  while(temp->next!=NULL)
  {
    printf(" %d\n",temp->data);
    temp=temp->next;
  }
   printf(" %d\n",temp->data);  
  return top;
  }
}
struct stack *peek(struct stack *top)
 {
  if(top==NULL)
  {
    printf("\nStack is empty.");
    return top;
  }
  else
  {
   printf(" %d is the top of the stack\n",top->data);  
   return top;
  }
}

int main()
{
    int ch;
    do
    {
    printf("\nChoose an operation for stack: \n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEK\n5. EXIT\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        top=push(top);
        break;
    case 2:
        top=pop(top);
        break;
    case 3:
        top=display(top);
        break;
    case 4:
        top=peek(top);
        break;
    case 5:
        break;
    default:
        printf("\nEnter the valid option.");
        break;
    }
    }while(ch!=5);
    return 0;
}