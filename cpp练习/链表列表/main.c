#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showItem(Item item);


int main()
{
    List movies;
    Item temp;

    InitializerList(&movies);//初始化列表

    //printf("列表初始化成功。\n");

    if(ListIsFull(&movies)){
        fprintf(stderr,"No memory available!");
        exit(0);
    }

    puts("Enter first movie title:");
    while (gets(temp.title) != NULL && temp.title[0] != '\0'){

        puts("Enter your rating<1-10>:");
        scanf("%d",&temp.rating);

        while (getchar() != '\n')//清空输入流
            continue;
        if(!ListAdd(&movies, temp)){
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }

        if(ListIsFull(&movies)){
            puts("The list is now full.\n");
            break;
        }

        //printf("%s储存成功。\n",temp.title);

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
