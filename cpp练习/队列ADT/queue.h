/*����ģ���г��˿��Ŷ���ѯ
    queue.hͷ�ļ�
    �����ӿ�
*/

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX 10

typedef struct item
{
    long arrive;//�˿͵���ʱ��
    int processtime;//��Ѷʱ��
} Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node * front;//ָ��������׵�ָ��
    Node * rear;//ֻ�������β��ָ��
    int items;//�����е���Ŀ��
} Queue;

//��ʼ������
void InitializerQueue(Queue * pq);

//�������Ƿ�Ϊ��
int QueueisEmpty(const Queue * pq);

//�������Ƿ�����
int QueueisFull(const Queue * pq);

//ȷ�������е���Ŀ��
int QueueCount(const Queue * pq);

//�����β�������Ŀ
int QueueAdd(Queue * pq, Item item);

//�Ѷ���ͷ��ɾ��
int QueueDelete(Queue * pq);

//��ն���
void QueueFree(Queue * pq);

#endif // QUEUE_H_INCLUDED
