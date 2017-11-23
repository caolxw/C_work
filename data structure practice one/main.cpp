#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list.cpp"

void startup()
{
    int i;
    for(i=0; i<20; i++){
        printf("*");
    }
    printf("\n输入数字选择功能：\n");
    printf("1.显示多项式\n");
    printf("2.多项式相加\n");
    printf("3.多项式相减\n");
    printf("4.多项式相乘\n");
    printf("5.多项式取反\n");
    printf("6.构建新的多项式\n");
    printf("7.退出程序\n");
    for(i=0; i<20; i++){
        printf("*");
    }
    printf("\n");
}

void show(LinkList p,ElemType e)
{
    if(p->next){
        printf("(%dx^%d)+",e.coef,e.expn);
    }
    else{
        if(e.expn == 0)
            printf("(%d)",e.coef);
        else printf("(%dx^%d)",e.coef,e.expn);
    }
}

void AddPolyn(LinkList La, LinkList Lb, LinkList &Lc)
{
    if(Lc->next != NULL) ClearList(Lc);//若Lc不为空，则清空lc
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    while(pa){
        InsertElem(Lc, pa->data);
        pa = pa->next;
    }
    while(pb){
        InsertElem(Lc, pb->data);
        pb = pb->next;
    }
    sort_expn(Lc);
}

void OppositePolyn(LinkList L)
{
    LinkList p = L->next;
    while(p){
        p->data.coef *= -1;
        p=p->next;
    }
}

void MinusPolyn(LinkList La, LinkList Lb, LinkList &Lc)
{
    int n;
    printf("请按序号输入你要进行的操作\n");
    printf("1.多项式1-多项式2\n2.多项式2-多项式1\n");
    scanf("%d",&n);
    while(n != 1 && n != 2){
        printf("输入有误,请重新输入:\n");
        scanf("%d",&n);
    }
    if(n == 1){
        OppositePolyn(Lb);
        AddPolyn(La,Lb,Lc);
    }
    else if(n == 2){
        OppositePolyn(La);
        AddPolyn(La,Lb, Lc);
    }
}

void MultiplyPolyn(LinkList La, LinkList Lb, LinkList &Lc)
{
    if(Lc->next!=NULL) ClearList(Lc);

    LinkList pa = La->next;
    LinkList pb = Lb->next;

    while(pa){
        pb = Lb->next;
        while(pb){
            ElemType e;
            e.expn = pa->data.expn + pb->data.expn;
            e.coef = pa->data.coef * pb->data.coef;
            InsertElem(Lc, e);
            pb = pb->next;
        }
        pa = pa->next;
    }
    sort_expn(Lc);
}

void input(LinkList &L)
{
    if(L->next!=NULL) ClearList(L);
    printf("请按照“系数，次数”的形式输入，并以0 0表示输入完成。\n例如：2x^3+3x+1\n应输入：2 3 3 1 1 0 0 0\n");
    int coef, expn;
    printf("请输入多项式：\n");
    scanf("%d%d",&coef,&expn);
    if(coef != 0 || expn != 0){
        while(coef != 0 || expn != 0){
            ElemType e;
            e.coef = coef;
            e.expn = expn;
            InsertElem(L,e);
            scanf("%d%d",&coef,&expn);
        }
    }
    sort_expn(L);
}

int main()
{
    LinkList L1,L2;
    InitList(L1);InitList(L2);

    input(L1);
    printf("多项式1输入完成\n\n");
    input(L2);
    printf("多项式2输入完成\n\n");

    LinkList La,Lb,Lc;//对多项式进行备份
    InitList(La); InitList(Lb); InitList(Lc);

    startup();
    int n;
    scanf("%d",&n);
    while(n<7 && n>0){
        switch(n)
        {
            case 1:{
                printf("多项式1：");
                ListTraverse(L1,show); printf("\n");
                printf("多项式2：");
                ListTraverse(L2,show); printf("\n");
                break;
            }
            case 2:{
                CopyList(L1,La);
                CopyList(L2,Lb);
                AddPolyn(La, Lb, Lc);
                ListTraverse(Lc,show); printf("\n");
                break;
            }
            case 3:{
                CopyList(L1,La);
                CopyList(L2,Lb);
                MinusPolyn(La, Lb, Lc);
                ListTraverse(Lc,show); printf("\n");
                break;
            }
            case 4:{
                CopyList(L1,La);
                CopyList(L2,Lb);
                MultiplyPolyn(La, Lb, Lc);
                ListTraverse(Lc,show); printf("\n");
                break;
            }
            case 5:{
                int n;
                CopyList(L1,La);
                CopyList(L2,Lb);
                printf("请按序号输入你要进行的操作\n");
                printf("1.多项式1取反\n2.多项式2取反\n3.两个多项式均取反\n");
                scanf("%d",&n);
                OppositePolyn(La);
                OppositePolyn(Lb);
                while(n!=1&&n!=2&&n!=3){
                    printf("输入有误,请重新输入:\n");
                    scanf("%d",&n);
                }
                if(n==1) {ListTraverse(La,show); printf("\n");}
                if(n==2) {ListTraverse(Lb, show);printf("\n");}
                if(n==3) {
                    ListTraverse(La,show); printf("\n");
                    ListTraverse(Lb, show);printf("\n");
                }
                break;
            }
            case 6:{
                input(L1);
                input(L2);
                break;
            }
        }
        startup();
        scanf("%d",&n);
    }
    return 0;
}
