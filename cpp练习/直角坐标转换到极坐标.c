/*
CС��ϰ:ֱ�����굽�������ת��
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)

struct Rectangular //ֱ������ϵ
{
    double x;
    double y;
};

struct Polar //������ϵ
{
    double r;
    double angle;
};

struct Polar changefun(struct Rectangular a)
{
    struct Polar b;

    double x = a.x;
    double y = a.y;

    b.r = sqrt(x*x + y*y);
    b.angle = atan2(x,y)*180/PI;

    return b;
};
int main()
{
    printf("ֱ������ϵ��������ϵ��ת����\n");

    struct Rectangular p1;
    struct Polar p2;

    printf("����ֱ������ϵ�����꣺\n");
    while((scanf("%lf,%lf",&p1.x, &p1.y)) == 2){
        p2 = changefun(p1);

        printf("��%lf,%lf��",p1.x, p1.y);
        printf("ת��Ϊ������Ϊ��(%.2lf,%.2lf��)\n\n", p2.r, p2.angle);

        printf("����ֱ������ϵ�����꣺\n");
    }

    printf("�������\n");
    return 0;
}
