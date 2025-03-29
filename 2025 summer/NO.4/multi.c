#include <stdio.h>
#include <stdlib.h>
//系数和指数
typedef struct _X
{
    int c;
    int p;
} X;
//结点
typedef struct _node
{
    X data;
    struct _node *link;
} node, *nodeptr;
//创建结点
nodeptr createnode(X x);
//插入有序链表，合并同类项
void insert(nodeptr list,X x);
//释放空间
nodeptr destroy(nodeptr list);

int main()
{
    X x;
    char ch;
    nodeptr list1, list2;
    x.c = 0;
    x.p = 0;
    list1 = createnode(x);
    list2 = createnode(x);
    while (ch != '\n')
    {
        scanf("%d%d%c", &x.c, &x.p, &ch);
        insert(list1, x);
    }
    ch = '\0';
    while (ch != '\n')
    {
        scanf("%d%d%c", &x.c, &x.p, &ch);
        for (nodeptr t = list1->link; t != NULL; t = t->link)
        {
            X temp;
            temp.c = t->data.c * x.c;
            temp.p = t->data.p + x.p;
            insert(list2, temp);
        }
    }
    for (nodeptr t = list2->link; t != NULL; t = t->link)
    {
        if (t->data.c != 0)
            printf("%d %d ", t->data.c, t->data.p);
    }
    list1 = destroy(list1);
    list2 = destroy(list2);
    return 0;
}

void insert(nodeptr list, X x)
{
    nodeptr p1, q, r;
    for (q = list, p1 = list->link; p1 != NULL && p1->data.p > x.p; q = p1, p1 = p1->link);
    if (p1 == NULL)
    {
        r = createnode(x);
        q->link = r;
    }
    else
    {
        if (p1->data.p == x.p)
            p1->data.c += x.c;
        else
        {
            r = createnode(x);
            r->link = p1;
            q->link = r;
        }
    }
}

nodeptr createnode(X x)
{
    nodeptr p1;
    p1 = (nodeptr)malloc(sizeof(node));
    p1->data.p = x.p;
    p1->data.c = x.c;
    p1->link = NULL;
    return p1;
}

nodeptr destroy(nodeptr list)
{
    nodeptr p1 = list;
    while (list != NULL)
    {
        p1 = list->link;
        free(list);
        list = p1;
    }
    return NULL;
}