#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 100
#define N2 1000
#define N3 10000
#define N4 30000

void sort1 (int *a, int n);
void sort2 (int *a, int n);
void sort3 (int *a, int low, int high);
void number(int *a, int n);
long sorttime (int *a, int n, void (*sort)(int *, int));
void print(int *a, int n);
long sorttime1(int *a, int low, int high);

int main()
{
    int a[N1] = {0};
    int b[N2] = {0};
    int c[N3] = {0};
    int d[N4] = {0};

    print(a, N1);
    print(b, N2);
    print(c, N3);
    print(d, N4);

    return 0;
}

//冒泡排序法
void sort1 (int *a, int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            if (*(a+i) > *(a+j)){
                temp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = temp;
            }
        }
    }
}

//简单插入法
void sort2 (int *a, int n)
{
    int i, p;
    int temp;

    for (i = 1; i < n; i ++){
        temp = *(a+i);
        p = i - 1;
        if(p >= 0 && temp < a[p]){
            *(a+p+1) = *(a+p);
            p --;
        }
        *(a+p+1) = temp;
    }
}

//快速排序法
void sort3 (int *a, int low, int high)
{
    int pivotkey = a[low];
    int i = low;
    int j = high;

    if(low >= high){
        return ;
    }
    while (i < j) {
        while (i < j && a[j] >= pivotkey) {
            j --;
        }
        a[i] = a[j];
        while (i < j && a[i] <= pivotkey) {
            i ++;
        }
        a[j] = a[i];
    }
    a[i] = pivotkey;
    sort3(a, low, i-1);
    sort3(a, i+1, high);
 }

//生成随机数组
void number(int *a, int n)
{

    int i = 0;
    srand((int)time(0));
    while (i < n){
        *(a+i) = rand();
        i ++;
    }
}

long sorttime (int *a, int n, void (*sort)(int *, int))
{
    long t1 = clock();
    sort (a, n);
    long t2 = clock();
    long t3 = t2 - t1;

    return t3;
}
long sorttime1 (int *a, int low, int high)
{
    long t1 = clock();
    sort3(a, low, high);
    long t2 = clock();

    return t2-t1;
}

void print (int *a, int n)
{
    printf("%d个数：\n", n);
    //冒泡排序时间
    printf("冒泡排序：");
    number(a, n);
    long t1 = sorttime(a, n, sort1);
    printf("%ld\n", t1);
    printf("再排序: ");
    long t1_1 = sorttime(a, n, sort1);
    printf("%ld\n", t1_1);
    printf("\n");
    //简单插入排序时间
    printf("简单插入法：");
    number(a, n);
    long t2 = sorttime(a, n, sort2);
    printf("%ld\n", t2);
    printf("再排序：");
    long t2_2 = sorttime(a, n, sort2);
    printf("%ld\n" , t2_2);
    printf("\n");
    //快速排序时间
    printf("快速排序：");
    number(a, n);
    long t3 = sorttime1(a, 0, n-1);
    printf("%ld\n", t3);
    printf("再排序：");
    long t3_3 = sorttime1(a, 0, n-1);
    printf("%ld\n", t3_3);
    printf("\n");
}
