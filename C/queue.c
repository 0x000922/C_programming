typedef struct node node;
struct node
{
    int data;
    node * next;
};
node * front = NULL;
node * rear = NULL;
node * createnode()
{
    node *temp = malloc(sizeof(node));
    printf("enter data to be insert::");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}
void enqu()
{
    node * temp = createnode();
    if(front==NULL)
    {
        front = temp;
        rear = temp;
        rear->next=front;
    }
    else
    {
        rear->next=temp;
        rear = temp;
        rear->next=front;
    }
}
void deq()
{
    node * temp = malloc(sizeof(node));
    temp=front;
    if (front == NULL)
    {
        printf("empty qu nothing to delete\n");
    }
    else if(front==rear)
    {
            rear = NULL;
            front = NULL;
            free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        temp->next = NULL;
        free(temp);
    }
    
}
void disp()
{
    struct node *temp = malloc(sizeof(struct node));
    temp = front;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }while (temp!=front)
        printf("null\n");
}
void main()
{
    for(int i=0;i<5;i++)
    {
        enqu();
    }
    disp();
    deq();
    disp();
}
