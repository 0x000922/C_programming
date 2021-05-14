#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef char StackItem;
typedef struct stack {
  int top;
  StackItem in [MAXSIZE];
}Stack;
Stack * createstack(){
  Stack * n = (Stack*)malloc(sizeof (Stack));
  n->top = 0;
  return n;
}
bool EmptyStack(Stack * s){
  bool exp = s->top == 0;
  return exp;
}
bool FullStack(Stack * s){
  bool exp = s->top >=MAXSIZE;
  return exp;
}
void push(char a,Stack * s){
  if(FullStack (s))
    {
      printf("stack is full");
    }
  else
    {
      s->in[s->top++] = a;
    }
}
void pop(char * n,Stack * s){
  if (EmptyStack (s))
    {
      printf("empty stack\n ");
    }
  else
    {
      *n = s->in[s->top];
      s->top--;
    }
}
void PrintStack(Stack * s)
{
  
}
int main()
{
  Stack * s = createstack();
  char l ;
  push('a',s);
  pop(&l,s);
  pop(&l,s);
  return 0;
  
}
