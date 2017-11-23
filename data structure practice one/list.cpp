#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"

void InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(Node));
    if(!L){
        printf("Wrong!分配空间失败。\n");
        exit(0);
    }
    L->next = NULL;
}

void DestroyList(LinkList &L)
{
    LinkList q = L->next;
    while(q){
        free(L);
        L = q;
        q = q->next;
    }
    free(L);
}

void ClearList(LinkList L)
{
    LinkList p, q;
    q = L->next;
    while(q){
        p = q->next;
        free(q);
        q = p;
    }
    L ->next = NULL;
}

int LocateElem(LinkList L, int expn)
{
    LinkList p = L->next;
    int i = 1;
    int k = 0;
    while (p){
        ElemType e = p->data;
        if(e.expn == expn)
            k = i;
        p = p->next;
        i ++;
    }
    return k;
}

void DeleteElemType(LinkList L, int i)
{
    LinkList p = L;
    int j = i-1;
    while(j){
        p = p->next;
        j --;
    }
    LinkList q = p ->next;
    p ->next = q ->next;
    free(q);
}

void InsertElem(LinkList &L, ElemType e)
{
    int coef = e.coef;
    int expn = e.expn;
    int locate = LocateElem(L, expn);
    int k = locate;
    if(k){
        LinkList p = L;
        while(k){
            p = p->next;
            k --;
        }
        int sum_coef = coef+p->data.coef;
        if(sum_coef == 0){
                //如果和为零，删除节点
            DeleteElemType(L, locate);
        }
        else p->data.coef = sum_coef;
    }
    else{
        LinkList s = (LinkList)malloc(sizeof(Node));
        if(!s){
            printf("Wrong!分配空间失败。\n");
            exit(0);
        }
        s->data = e;
        s->next = L->next;
        L->next = s;
    }
}

void ListTraverse(LinkList L, void(*fun)(LinkList,ElemType))
{
    LinkList p = L->next;
    while(p)
    {
        fun(p,p->data);
        p = p->next;
    }
}

//根据指数排序
void sort_expn(LinkList L)
{
    LinkList p, t;
    LinkList q = L->next;
    ElemType max_e;
    while(q){
        p = q->next;
        max_e = q->data;
        t = q;
        while(p){
            if(p->data.expn>max_e.expn){
                max_e = p->data;
                t = p;//记录下最大值e的位置
            }
            p = p->next;
        }

        if(t!=q){
                //把最大e放到前面的节点
            ElemType temp = q->data;
            t->data = temp;
            q->data = max_e;
        }
        q = q->next;
    }
}

void CopyList(LinkList La, LinkList &Lb)
{
    //备份链表
    if(Lb->next != NULL) ClearList(Lb);
    LinkList pa = La->next;
    while(pa){
        InsertElem(Lb,pa->data);
        pa=pa->next;
    }
    sort_expn(Lb);
}
