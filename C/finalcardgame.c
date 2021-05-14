#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct card card;
#define SIZE 13
 //person queue
int front = -1;
int rear = -1;
struct card
{
    int color, type, number;
};
card primary[52];
void genrate()
{
    printf("genrating card deck\n");
    for (int i = 0; i < 52; i++)
    {

        primary[i].number = i % 13 + 1;
        if (i < 26)
        {
            primary[i].color = 0;
            if (i < 13)
            {
                primary[i].type = 0;
            }
            else
            {
                primary[i].type = 1;
            }
        }
        else
        {
            primary[i].color = 1;
            if (i < 39)
            {
                primary[i].type = 2;
            }
            else
            {
                primary[i].type = 3;
            }
        }

        
    }
    front = 0;
    rear = 51;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void primaryshuffle() //apply card contraints
{
    
    printf("shuffling.......\n\n");
    
    int t; //, c, n = 0;
    srand(time(0));
    for (int i = 0; i < 52; i++)
    {

        t = rand() % (52 - i) + i;
        swap(&primary[i].color, &primary[t].color);
        swap(&primary[i].number, &primary[t].number);
        swap(&primary[i].type, &primary[t].type);
    }
}    
card pop_main()
{
    card element;
    if (front == -1)
    {
        printf("queue empty\n");
        return element;
    }
    else
    {
        element = primary[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1);
        }
     
        return (element);
    }
}
void win(int k,int bc,int rc,int** wing)
{
    if(k==4)
    {
        **wing = 1;
    }
}
void push(card* a,int *f,int *r,card element,int* k,int* bc,int* rc,int* wing)
{
    
        if ((*f == *r + 1) || (*f == 0 && *r == 13 - 1))
        {
            printf("full .. \n");
        }
        else
        {

            if (*f == -1)
                *f = 0;
            *r = *r + 1;
            a[*r] = element;
        }
        if(element.number==12)
        {
            *k = *k + 1;
        }
        if(element.color==0)
        {
            *bc = 1;
        }
        else
        {
            *rc = 1;
        }
        win(*k,*bc,*rc,&wing);
    
}
void dislay_card(card e)
{
    if(e.color==1)
    {
        printf("color->black\n");
    }
    else
    {
        printf("color->red\n");
    }
    if(e.type==0)
    {
        printf("type->club\n");
    }
    else if (e.type==1)
    {
        printf("type->diamond\n");
    }
    else if (e.type==2)
    {
        printf("type->heart\n");
    }
    else
    {
        printf("type->spade\n");
    }
    printf("number->%d\n",e.number);
    
}



void main()
{
    int wing = -1;
    int ctr=0;
    genrate();
    do{
        /* queue intialization */

        card a1[13];
        card a2[13];
        card a3[13];
        card a4[13];
        int f1 = -1;
        int r1 = -1;
        int bc1;
        int rc1;
        int kc1 = 0;
        int f2 = -1;
        int r2 = -1;
        int bc2;
        int rc2;
        int kc2 = 0;

        int f3 = -1;
        int r3 = -1;
        int bc3;
        int rc3;
        int kc3 = 0;

        int f4 = -1;
        int r4 = -1;
        int bc4, rc4;
        int kc4 = 0;

        
        primaryshuffle();
        printf("distributiing--\n");
        for (int i = 0; i < 13; i++)
        {
            push(a1, &f1, &r1, pop_main(), &kc1, &bc1, &rc1,&wing);
            push(a2, &f2, &r2, pop_main(), &kc2, &bc2, &rc2, &wing);
            push(a3, &f3, &r3, pop_main(), &kc3, &bc3, &rc3, &wing);
            push(a4, &f4, &r4, pop_main(), &kc4, &bc4, &rc4, &wing);
        }
        front=0;
        rear=51;
    if(wing==-1)
    {
        printf("sorry didnot win...\n");
    }
    else 
    {
        printf("won\n");
    }
    ctr++;
} while (wing==-1);
    
    printf("won after ===== %d steps",ctr);

}