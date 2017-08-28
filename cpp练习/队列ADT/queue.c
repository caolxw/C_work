#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*---�ֲ�����---*/
void CopyItem(Item item, Node * pn)
{
    pn -> item = item;
}

//��ʼ�����У��Ƕ���Ϊ��
void InitializerQueue(Queue * pq)
{
    pq -> items = 0;
    pq -> front = NULL;
    pq -> rear = NULL;
}

//�������Ƿ�Ϊ��
//��Ϊ�շ���1�����򷵻�0
int QueueisEmpty(const Queue * pq)
{
    if(pq -> items == 0)
        return 1;
    else return 0;
}

//�������Ƿ�����
//����������1�����򷵻�0
int QueueisFull(const Queue * pq)
{
    if(pq -> items >= MAX)
        return 1;
    else return 0;
}

//ȷ�������е���Ŀ��
int QueueCount(const Queue * pq)
{
    return (pq -> items);
}

//�����β�������Ŀ
int QueueAdd(Queue * pq, Item item)
{
    Node * pnew;

    if(QueueisFull(pq)){
        fprintf(stderr,"Queue is fulled!\n");
        return 0;
    }

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL){
        fprintf(stderr,"Unable to allocate memory!\n");
        return 0;
    }
    CopyItem(item, pnew);
    pnew -> next = NULL;
    if (QueueisEmpty(pq)){
        //�ն���
        pq -> front = pnew;
    }
    else{
        //�ǿն���
        pq -> rear -> next = pnew;
    }
    pq -> rear = pnew;
    pq -> items ++ ;
    return 1;
}

//ɾ������ͷ����Ŀ
int QueueDelete(Queue * pq)
{
    Node * pt;
    if(QueueisEmpty(pq)){
        fprintf(stderr, "Nothing to delete.");
        return 0;
    }
    pt = pq ->front;
    pq ->front = pq ->front ->next;
    free(pt);

    if(pq->items == 1){
        //����ֻ��һ����Ŀ
        pq ->rear = NULL;
    }
    pq ->items --;

    return 1;
}

//��ն���
void QueueFree(Queue * pq)
{
    if(pq ->items != 0)
        QueueDelete(pq);
}
