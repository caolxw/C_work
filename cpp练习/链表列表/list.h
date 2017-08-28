/*list.h�ӿ��ļ�
    �����ӿ�*/

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
    Node * front;//��¼�б�ͷ
    int sizes;
} List;


//��ʼ���б�
void InitializerList(List * plist);

//�ж��б��Ƿ�Ϊ��
int ListIsEmpty(const List * plist);

//�ж��б��Ƿ�����
int ListIsFull(const List * plist);

//ȷ���б�����Ŀ����
int ListCount(const List * plist);

//���б�β�������Ŀ
int ListAdd(List * plist, Item item);

//�Ѻ����������б��ÿһ��
void Traverse(const List * plist, void (*pfun)(Item item));

//�ͷŷ�����ڴ�
void ListFree(List * plist);

#endif // LIST_H_INCLUDED
