//LinkedList
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start)
{
  struct node *new_node,*ptr;
  int n;
  printf("\nEnter -1 to end");
  printf("\nEnter the data for the node : ");
  scanf("%d",&n);
  while(n!=-1)
  {
    new_node= (struct node*)malloc(sizeof(struct node));
    new_node->data=n;
    if(start==NULL)
    {
      start=new_node;
      new_node->next=NULL;
    }
    else
    {
      ptr=start;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->next=NULL;
    }
    //printf("cr:%d",new_node->data);
    printf("\nEnter the data for the node : ");
    scanf("%d",&n);
  }
  return start;
}
struct node *display(struct node *start) {
  struct node *ptr;
  if(start==NULL)
  {
    printf("\nLinked list is empty.");
    return start;
  }
  else
  {
  ptr=start;
  printf("\n");
  while(ptr->next!=NULL)
  {
    printf(" %d ",ptr->data);
    printf("->");
    ptr=ptr->next;
  }
   printf(" %d \n",ptr->data);  
  return start;
  }
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;  
    new_node= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&new_node->data);
    if(start==NULL)
      new_node->next=NULL;
    else
      new_node->next=start;
    start=new_node;
    return start;
}
struct node *insert_en(struct node *start)
{
  struct node *new_node,*ptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data : ");
  scanf("%d",&new_node->data);
  if(start==NULL)
  {
  	start=new_node;
    new_node->next=NULL;
    return start;
  }
  else
  {
  ptr=start;
  while(ptr->next!=NULL)
  ptr=ptr->next;
  ptr->next=new_node;
  new_node->next=NULL;
  return start;
}
}
struct node *insert_af(struct node *start)
{
  int a;
  struct node *new_node,*ptr;
  if(start==NULL)
  {
    printf("\nLinked List is empty. ");
  }
  else
  {
   printf("\nEnter the number after which the new number is to be inserted : ");
   scanf("%d",&a);
   new_node=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter the new data : ");
   scanf("%d",&new_node->data);
   ptr=start;
   while(ptr->next!=NULL)
   {
     if(ptr->data==a)
       break;
     ptr=ptr->next;  
   }
   if(ptr->data!=a)
    {
       printf("\nThis number is not present. ");
       return start;
    }
   if(ptr->next==NULL)
   {
     new_node->next=NULL;
   }
   else
   {
     new_node->next=ptr->next;  
   }
   ptr->next=new_node;
  }
   return start;
}
struct node *insert_bef(struct node *start)
{
  int a;
  struct node *new_node,*ptr,*preptr;
  if(start==NULL)
  {
  	printf("\nLinked List is empty. ");
    return start;
  }
  else
  {
    printf("\nEnter the number before which the new number is to be inserted : ");
    scanf("%d",&a);
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the new data : ");
    scanf("%d",&new_node->data);
    printf("..");
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL)
    {
      if(ptr->data==a)
        break;
      preptr=ptr;
      ptr=ptr->next;
    }
    if(ptr->data!=a)
    {
       printf("\nThis number is not present. ");
       return start;
    }
    if(ptr==start)
    {
    	new_node->next=ptr; 
      start=new_node;
    }
    else
    {
      preptr->next=new_node;
      new_node->next=ptr;
    }
  }
   return start;
}
struct node *del_beg(struct node *start)
{
  struct node *ptr;
  if(start==NULL)
    printf("\nThe linked list is empty. ");
  else
  {
   ptr=start;
   if(ptr->next==NULL)
     start=NULL;
   else  
     start=ptr->next;
   free(ptr);
  }
  return start;
}
struct node *del_en(struct node *start)
{
  struct node *ptr,*preptr;
  if(start==NULL)
    printf("\nThe linked list is empty. ");
  else
  {
   ptr=start;
   preptr=ptr;
   while(ptr->next!=NULL)
   {
     preptr=ptr;
     ptr=ptr->next;
   }
   if(ptr==start)
     start=NULL;
   else  
     preptr->next=NULL;
   free(ptr);
  }
  return start;
}
struct node *del_af(struct node *start)
{
  int a;
  struct node *ptr,*preptr;
  if(start==NULL)
    printf("\nThe linked list is empty. ");
  else
  {  
   printf("\nEnter the number after whom the node has to be Deleted : ");
   scanf("%d",&a);
   ptr=start;
   preptr=ptr;
   while(ptr->next!=NULL)
   {
      if(ptr->data==a)
        break;
      preptr=ptr;
      ptr=ptr->next;
   }
   if(ptr->data!=a)
      printf("\nThe number is not present in the Linked List. ");
   else if(ptr->next==NULL)
     {
        printf("\nThis is the last node. ");
     }  
   else
   {
     preptr=ptr;
     ptr=ptr->next;
     preptr->next=ptr->next;
     free(ptr);
   } 
  } 
  return start;
}
struct node *del_bef(struct node *start)
{
  int i,a;
  i=0;
  struct node *p,*p1,*p2;
  if(start==NULL)
    printf("\nThe linked list is empty. ");
  else
  {
   printf("\nEnter the node before whom the node has to be Deleted : ");
   scanf("%d",&a);
   p=start;
   p1=p;
   p2=p1;
   while(p->next!=NULL)
   {
     if(p->data==a)
       break;
     p2=p1;
     p1=p;
     p=p->next;
   }
   if(p->data!=a)
     printf("\nThis number is not present in the Linked List. ");
   if(p==start)
    	printf("\nThis is the first node. ");
   else if(p1==start)
   {
     start=p;
     free(p1);
   }
   else
   {
     p2->next=p;
     free(p1);
   }
  }
  return start;
}
struct node *del_n(struct node *start)
{
  int a;
  struct node *ptr,*preptr;
  if(start==NULL)
    printf("\nThe linked list is empty. ");
  else
  {
   ptr=start;
   preptr=ptr;
   printf("\nEnter the node to be deleted : ");
   scanf("%d",&a);
   while(ptr->next!=NULL)
   {
     if(ptr->data==a)
        break;
     preptr=ptr;
     ptr=ptr->next;
    }
   if(ptr->data!=a)
     printf("\nThis number is not present in the linked list. ");
   else if(ptr==start)
     {
       if(ptr->next==NULL)
         start=NULL;
       else
         start=ptr->next;
         printf("..");
     }
   else
     preptr->next=ptr->next;
   free(ptr);
  }
  return start;
}
struct node *search(struct node *start)
{
  int flag,a;
  flag=0;
  struct node *ptr;
  if(start==NULL)
    printf("\nThe Linked List is empty. ");
  else 
  { 
   printf("\nEnter the node to be searched : ");
   scanf("%d",&a);
   ptr=start;
   while(ptr->next!=NULL)
   {
     if(ptr->data==a)
       break;
     ptr=ptr->next;
   }
   if(ptr->data==a)
      printf("\nYes, the node is present in the linked list");
   else
     printf("\nThe node is not present in the linked list");
  }
  return start;
}
int main()
{
  int ch,a;
  do {
    printf("\n-----ENTER YOUR CHOICE-----\n1 Create a Linked List\n2 Display the Linked List\n3 Insert\n4 Delete\n5 Search for a node\n6 Exit\n");
    scanf("%d",&ch);
    if(ch==3)
    {
      printf(" 31 Insert at Beginning\n 32 Insert at end\n 33 Insert After\n 34 Insert Before\n");
      scanf("%d",&a);
      ch=a;
    }
    else if(ch==4)
    {
      printf(" 41 Delete Beginning\n 42 Delete End\n 43 Delete After\n 44 Delete Before\n 45 Delete Node\n");
      scanf("%d",&a);
      ch=a;
    }
    switch (ch) {
      case 1:
      start= create(start);
      printf("\nLinked list created\n");
      break;
      case 2:
      start=display(start);
      break;
      case 31:
      start=insert_beg(start);
      break;
      case 32:
      start=insert_en(start);
      break;
      case 33:
      start=insert_af(start);
      break;
      case 34:
      start=insert_bef(start);
      break;
      case 41:
      start=del_beg(start);
      break;
      case 42:
      start=del_en(start);
      break;
      case 43:
      start=del_af(start);
      break;
      case 44:
      start=del_bef(start);
      break;
      case 45:
      start=del_n(start);
      break;
      case 5:
      start=search(start);
      break;
    }
  } while(ch!=6);
  return 0;
}
