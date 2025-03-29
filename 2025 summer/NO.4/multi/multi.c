#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    int coeff;
    int index;
}DATA;

typedef struct node{
    DATA data;
    struct node *next;
}NODE,*NodePtr;

NodePtr newNodeList(DATA data);
void freeNode(NodePtr list);
void insert(NodePtr *list,DATA data);
void input(NodePtr *list);
void multi(NodePtr LineOne,NodePtr LineTwo,NodePtr *Result);
void printList(NodePtr Result);

int main()
{
    NodePtr LineOne = NULL,LineTwo = NULL,Result = NULL;

    input(&LineOne);
    input(&LineTwo);

    multi(LineOne,LineTwo,&Result);

    printList(Result);

    return 0;
}


NodePtr newNodeList(DATA data)
{
    NodePtr p = (NodePtr)malloc(sizeof(NODE));
    p->data = data;
    p->next = NULL;
    return p;
}

void freeNode(NodePtr list)
{
    NodePtr p1 = list;
    while (list != NULL)
    {
        p1 = list->next;
        free(list);
        list = p1;
    }
}

void insert(NodePtr *list,DATA data)
{
    NodePtr new_node = newNodeList(data);
    
    // Handle empty list or insert at head
    if (*list == NULL || data.index > (*list)->data.index) {
        new_node->next = *list;
        *list = new_node;
        return;
    }

    // Find insertion point
    NodePtr current = *list;
    while (current->next != NULL && current->next->data.index >= data.index) {
        current = current->next;
    }

    // Combine like terms if same index
    if (current->data.index == data.index) {
        current->data.coeff += data.coeff;
        free(new_node);  // Free unused node
    } else {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void input(NodePtr *list)
{
    DATA data;
    char ch = ' ';
    (*list) = NULL;
    while (ch != '\n'){
        scanf("%d%d%c",&data.coeff,&data.index,&ch);
        insert(list,data);
    }
}


void multi(NodePtr LineOne,NodePtr LineTwo,NodePtr *Result)
{
    DATA x;
    (*Result) = NULL;
    for (NodePtr p = LineOne; p != NULL; p = p->next){
        for (NodePtr q = LineTwo; q != NULL; q = q->next){
            x.coeff = p->data.coeff * q->data.coeff;
            x.index = p->data.index + q->data.index;
            insert(Result,x);
        }
    }
}


void printList(NodePtr Result)
{
    NodePtr q = Result;
    for (;q != NULL; q = q->next){
        printf("%d %d ",q->data.coeff,q->data.index);
    }
    printf("\n");
}
