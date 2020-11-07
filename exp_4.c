//postfixevaluation
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50
char opstk[MAX];
int top=-1;
void push(int a);
int pop();
void evalu(char iexp[]);
int main()
{
  int ans;
  char iexp[30];
  printf("Enter the postfix expression:");
  gets(iexp);
  evalu(iexp);
  ans=pop();
  printf("\nThe answer is %d",ans);
  return(0);
}
void push (int a)
{
  if (top==MAX-1)
  {
    printf("\nStack Overflow");
  }
  else
  {
    top++;
    opstk[top]=a;
    }

  }
int pop()
{
  if (top==-1)
  {
    printf("\nStack Underflow");
  }
  else
  {
    int p=opstk[top];
    top--;
    return(p);
}
}
void evalu(char iexp[])
{
	int i;
  for(i=0;iexp[i]!='\0';i++)
  {
  if(iexp[i]=='+'||iexp[i]=='-'||iexp[i]=='*'||iexp[i]=='/'||iexp[i]=='|'||iexp[i]=='&'||iexp[i]=='^')
  {
    int op2=pop();
    int op1=pop();
    switch(iexp[i])
    {
      case '+':
      push(op1+op2);
      break;
      case '-':
      push(op1-op2);
      break;
      case '*':
      push(op1*op2);
      break;
      case '/':
      push(op1/op2);
      break;
      case '|':
      push(op1||op2);
      break;
      case '&':
      push(op1&&op2);
      break;
      case '^':
      push(pow(op1,op2));
      break;
    }
  }
  else{
    push(iexp[i]-'0');
  }
  }
}
