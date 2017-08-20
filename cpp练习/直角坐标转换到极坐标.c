/*
C小练习:直角坐标到极坐标的转换
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)

struct Rectangular //直角坐标系
{
    double x;
    double y;
};

struct Polar //极坐标系
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
    printf("直角坐标系到极坐标系的转换。\n");

    struct Rectangular p1;
    struct Polar p2;

    printf("输入直角坐标系的坐标：\n");
    while((scanf("%lf,%lf",&p1.x, &p1.y)) == 2){
        p2 = changefun(p1);

        printf("（%lf,%lf）",p1.x, p1.y);
        printf("转换为极坐标为：(%.2lf,%.2lf°)\n\n", p2.r, p2.angle);

        printf("输入直角坐标系的坐标：\n");
    }

    printf("程序结束\n");
    return 0;
}
