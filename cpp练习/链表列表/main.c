#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showItem(Item item);


int main()
{
    List movies;
    Item temp;

    InitializerList(&movies);//��ʼ���б�

    //printf("�б��ʼ���ɹ���\n");

    if(ListIsFull(&movies)){
        fprintf(stderr,"No memory available!");
        exit(0);
    }

    puts("Enter first movie title:");
    while (gets(temp.title) != NULL && temp.title[0] != '\0'){

        puts("Enter your rating<1-10>:");
        scanf("%d",&temp.rating);

        while (getchar() != '\n')//���������
            continue;
        if(!ListAdd(&movies, temp)){
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }

        if(ListIsFull(&movies)){
            puts("The list is now full.\n");
            break;
        }

        //printf("%s����ɹ���\n",temp.title);

        puts("Enter next movie title:");
    }

    if(ListIsEmpty(&movies)){
        printf("No data entered.\n");
    }

    else{
        printf("Here is the movie list:\n");
        Traverse(&movies, showItem);

    }

    printf("You enter %d movies.\n",ListCount(&movies));

    ListFree(&movies);
    printf("Done!\n");

    return 0;
}

void showItem(Item item)
{
    printf("%s : %d\n",item.title, item.rating);
}
