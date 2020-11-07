//infixtopostfix
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
char st[MAX];
int top=-1,tp=-1;
char out[MAX];
void push(char);
void pop(char);
int prec(char);
char postfix(char iexp[]);

int main()
{

  char iexp[100],pexp[100];	
  printf("Enter the infix expression: ");
  gets(iexp);
  postfix(iexp);
  for(int r=top;r>=0;r--)
  {
	tp++;
    out[tp]=st[r];
    //printf("\nforfrommain%c ",out[tp]);
  }
  for(int b=0;b<=tp;b++)
  {
    printf("%c",out[b]);
    }
return(0);
   
}
void push (char p)
{
  if (top==MAX-1)
  {
    printf("\nStack Overflow");
  }
  else
  {
  	//printf("\nthisispush%c",p);
	top++;
    st[top]=p;
  }
}
void pop(char q)
{
  if (top==-1)
  {
    printf("\nStack Underflow");
  }
  else
  {
    //printf("\npop: %c top=%d ",q,top);
    tp++;
    out[tp]=q;
    top--;
  }
}

int prec(char op)
{
	//printf("\npreec");
  if(op=='|')
  return 1;
  if(op=='&')
  return 2;
  if (op=='+'|| op=='-')
  return 3;
  if (op=='*'||op=='/')
  return 4;
  if(op=='^')
  return 5;

}
char postfix(char iexp[])
{
   for(int i=0;iexp[i]!='\0';i++)
  {
    int cou=0;
    if(iexp[i]=='(')
    {
	  // printf("\ncon(");
       push(iexp[i]);
     }
	else if(iexp[i]=='+'||iexp[i]=='-'||iexp[i]=='*'||iexp[i]=='/'||iexp[i]=='|'||iexp[i]=='&')
      {
        if(st[top]=='(' || top==-1)
          {
        //  	printf("\ntop==-1");
		   push(iexp[i]);
		   }

        else
        {
        //	printf("\nelsewhichhaswhile");
          while(cou==0)
          {
          //	printf("\nhifromwhile");
          int p=prec(iexp[i]);
          int q=prec(st[top]);
          if(p>q||top==-1||st[top]=='(')
            {
			      push(iexp[i]);
                   cou=1;
          }
          else
             pop(st[top]);
           } 

         }
   }
   else if(iexp[i]==')')
      {
      	
		 // printf("\ncon)");
        while(st[top]!='(')
        {
          //printf("\ncon()while");
		       pop(st[top]);
          
        }
          char temp=st[top];
         top--;
        
      }
    else
     {

     	//printf("\nout%c %d ",iexp[i],i);
       tp++;
       out[tp]=iexp[i];
     }

}
}
