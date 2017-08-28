/*list.h接口文件
    构建接口*/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MAX 40

typedef struct film
{
    char title[MAX];
    int rating;
} Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct list
{
    Node * front;//记录列表头
    int sizes;
} List;


//初始化列表
void InitializerList(List * plist);

//判断列表是否为空
int ListIsEmpty(const List * plist);

//判断列表是否已满
int ListIsFull(const List * plist);

//确定列表中项目个数
int ListCount(const List * plist);

//在列表尾部添加项目
int ListAdd(List * plist, Item item);

//把函数作用于列表的每一项
void Traverse(const List * plist, void (*pfun)(Item item));

//释放分配的内存
void ListFree(List * plist);

#endif // LIST_H_INCLUDED
