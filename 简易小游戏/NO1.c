/*
CÓïÑÔÐ¡ÓÎÏ·1£ºÊµÏÖµ¯ÌøÐ¡Çò¡£
ÊµÏÖ²½Öè£º
1.ÔÚÆÁÄ»ÉÏÊä³öÐ¡Çò
2.¸Ä±äÐ¡ÇòµÄÎ»ÖÃ¡££¨ÔËÓÃÇåÆÁº¯Êý System("cls");)
3.Ê¹Ð¡Çòµ¯Ìø¡££¨ÔÚx,yÁ½¸ö·½ÏòÉÏÔö¼ÓËÙ¶È±äÁ¿£©
4.¿ØÖÆÐ¡Çòµ¯ÌøµÄËÙ¶È¡££¨Ê¹ÓÃsleepº¯Êý£©
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int i, j;
    int x = 0;
    int y = 5;

    int high = 10;//Ð¡Çòµ¯ÌøµÄ±ß½ç
    int bottom = 0;
    int right = 10;
    int left =0;

    int v_x = 1;//Ð¡ÇòµÄËÙ¶È
    int v_y = 1;

    while(1){
        x = x + v_x;
        y = y + v_y;
        system("cls");//ÇåÆÁº¯Êý

        //Êä³öÐ¡ÇòÉÏ·½µÄ¿ÕÐÐ
        for (i = 0; i < x; i++)
            printf("\n");
        //Êä³öÐ¡Çò×ó±ßµÄ¿Õ¸ñ
        for (j = 0; j < y; j ++)
            printf(" ");
        printf ("o");//Êä³öÐ¡Çò
        //printf ("\n");
        Sleep(500);//µÈ´ýÈô¸ÉÃë

        if(x == high || x == bottom){
            v_x = -v_x;
            printf("\a");
        }
        if(y == left || y ==right){
            v_y = -v_y;
            printf("\a");
        }
    }

    return 0;
}
