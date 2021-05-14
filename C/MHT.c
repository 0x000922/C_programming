#include<stdio.h>
#include<stdlib.h>
#define SIZE 25
int a1[25];
int f1 = -1;
int r1 = -1;
int a2[25];
int f2 = -1;
int r2 = -1;
int a3[25];
int f3 = -1;
int r3 = -1;
int a4[25];
int f4 = -1;
int r4 = -1;
int arr[100];
int front = -1;
int rear = -1;

void main_array_filler()
{
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 900 + 100;
        
    }
    front = 0;
    rear = 99;
}
int pop_main()
{
    int element;
    if (front == -1)
    {
        printf("queue full\n");
        return -1;
    }
    else
    {
        element = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        } 
        else
        {
            front = (front + 1);
        }
        //printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}
void push(int *a, int *f, int *r, int element)
{
    if ((*f == *r + 1) || (*f == 0 && *r == 25 - 1))
    {
        printf("full .. \n");
    }
    else
    {

        if (*f == -1)
            *f = 0;
        *r = *r + 1 % SIZE;
        a[*r] = element;
    }
}

void display(int *a, int f, int r)
{
    int i;
    if (f == -1)
        printf(" \n Empty Queue\n");
    else
    {

        printf("\n Items -> ");
        for (i = f; i != r; i = (i + 1) % SIZE)
        {
            printf("%d ", a[i]);
        }
        printf("%d ", a[i]);
    }
}
void main()
{
    int win = 0;

    main_array_filler();
    for (int i = 0; i < 25; i++)
    {
        push(a1, &f1, &r1, pop_main());
        push(a2, &f2, &r2, pop_main());
        push(a3, &f3, &r3, pop_main());
        push(a4, &f4, &r4, pop_main());
    }
    printf("players arrays before applying heapify function....\n");
    display(a1, f1, r1);
    printf("\n");
    display(a2, f2, r2);
    printf("\n");
    display(a3, f3, r3);
    printf("\n");
    display(a4, f4, r4);
    printf("\n");
}