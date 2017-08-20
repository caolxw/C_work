/*
CС��ϰ:����Ŀ�������
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM 40

void fillarray(double a[], int n)
{
    int i;
    double p;
    for (i = 0; i < n; i ++){
        p = (double)rand()/((double)rand()+0.1);
        a[i] = p;
    }
}

void showarray(const double a[], int n)
{
    int i;
    for (i = 0; i < n; i ++){
        printf("%-10.4lf  ",*(a+i));

        if((i+1)%4 == 0)
            printf("\n");
    }

    printf("\n");
}

int camp(const void *p1, const void *p2)
{
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if(*a1 < *a2)
        return -1;
    else if(*a1 == *a2)
        return 0;
    else return 1;
}
int main()
{

	double array[NUM];

	fillarray(array,NUM);
	printf("������飺\n");
	showarray(array, NUM);
	qsort(array, NUM, sizeof(double), camp);
	printf("\n��������飺\n");
	showarray(array, NUM);


    return 0;
}

