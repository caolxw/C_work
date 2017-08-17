#include <stdio.h>

char * itobs(int,char*);
void show(const char*);

int main()
{
    int number;
    printf("Please input an integer:\n");
    scanf("%d", &number);

    char str[8*sizeof(int)+1];
    itobs(number,str);
    printf("%d is: ",number);
    show(str);

}

char * itobs(int n ,char *ps)
{
    int i;
    int size = 8*sizeof(int);

    for(i = size-1; i >= 0; i --){
        ps[i] = (1 & n) + '0';
        n >>= 1;
    }
    ps[size] = '\0';

    return ps;
}

void show(const char*ps)
{
    int count = 0;
    int i = 0;

    while(ps[i] != '\0'){
        count ++;
        i++;
        if(count == 4){
            printf(" ");
            count = 0;
        }
        putchar(ps[i]);
    }
}
