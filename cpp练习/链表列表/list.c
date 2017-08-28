/*list.cʵ�ֽӿ��ļ�*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void CopyToNode(Item item, Node * pnode);

//��ʼ��Ϊ���б�
void InitializerList(List * plist)
{
    plist ->front = NULL;
    plist ->sizes = 0;
}

//�ж��б��Ƿ�Ϊ��
//��Ϊ�գ�����1�����ǿգ�����0
int ListIsEmpty(const List * plist)
{
    if(plist ->sizes == 0)
        return 1;
    else return 0;
}

//�ж��б��Ƿ�����
//������������1�����򷵻�0
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

//ȷ���б�����Ŀ��
int ListCount(const List * plist)
{
    return plist ->sizes;
}

//���б�β�������Ŀ
//��ӳɹ�����1��ʧ�ܷ���0
int ListAdd(List * plist, Item item)
{
    Node * pnew;
    Node * scan = plist ->front;//��¼�б��ͷָ��

    pnew = (Node *)malloc(sizeof(Node));

    if(pnew == NULL)
        return 0;

    CopyToNode(item, pnew);
    pnew -> next = NULL;

    if(scan == NULL)//���б�����Ŀ��ӵ��б�ͷ
        plist ->front = pnew;

    else{
        while (scan -> next != NULL)
            scan = scan -> next;
        scan -> next = pnew;
    }

    plist ->sizes ++;
    return 1;
}

//�����б����ÿһ����Ŀ
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist ->front;
    while (pnode != NULL){
        (*pfun)(pnode->item);
        pnode = pnode -> next;
    }
}

//�ͷŷ�����ڴ�
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
