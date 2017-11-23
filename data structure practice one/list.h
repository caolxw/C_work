#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct ElemType
{
    int coef;//系数
    int expn;//指数
} ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *LinkList;


#endif // LIST_H_INCLUDED
