/*list.c实现接口文件*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void CopyToNode(Item item, Node * pnode);

//初始化为空列表
void InitializerList(List * plist)
{
    plist ->front = NULL;
    plist ->sizes = 0;
}

//判断列表是否为空
//若为空，返回1，若非空，返回0
int ListIsEmpty(const List * plist)
{
    if(plist ->sizes == 0)
        return 1;
    else return 0;
}

//判断列表是否已满
//若已满，返回1，否则返回0
int ListIsFull(const List * plist)
{
    Node * pnew;
    int flag = 0;

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
        flag = 1;
    else flag = 0;

    free(pnew);

    return flag;
}

//确定列表中项目数
int ListCount(const List * plist)
{
    return plist ->sizes;
}

//在列表尾部添加项目
//添加成功返回1，失败返回0
int ListAdd(List * plist, Item item)
{
    Node * pnew;
    Node * scan = plist ->front;//记录列表的头指针

    pnew = (Node *)malloc(sizeof(Node));

    if(pnew == NULL)
        return 0;

    CopyToNode(item, pnew);
    pnew -> next = NULL;

    if(scan == NULL)//空列表，新项目添加到列表头
        plist ->front = pnew;

    else{
        while (scan -> next != NULL)
            scan = scan -> next;
        scan -> next = pnew;
    }

    plist ->sizes ++;
    return 1;
}

//访问列表里的每一个项目
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist ->front;
    while (pnode != NULL){
        (*pfun)(pnode->item);
        pnode = pnode -> next;
    }
}

//释放分配的内存
void ListFree(List * plist)
{
    Node * psave;
    while (plist ->sizes != 0){
        plist ->sizes --;
        psave = plist ->front ->next;
        free(plist->front);
        plist ->front = psave;
    }
}

void CopyToNode(Item item, Node * pnode)
{
    pnode -> item = item;
}
