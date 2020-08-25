#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"


int main(int argc, char* argv[]){
    struct node* start = NULL;
    int option;
    do{
        printf("############### MENU ###############\n");
        printf("Choose the correct option or enter -1 to exit:\n");
        printf("1.Create a list\n");
        printf("2.insertAtEnd\n");
        printf("3.insertAtBegin\n");
        printf("4.insertAfter\n");
        printf("5.insertBefore\n");
        printf("7.deleteList\n");
        printf("8.deleteAtEnd\n");
        printf("9.deleteAtBegin\n");
        printf("10.deleteAfter\n");
        printf("11.deleteBefore\n");
        printf("12.display the list\n");
        printf("13.deleteNode\n");
        printf("####################################\n");
        scanf("%d",&option);
        switch(option){
            case 1:start = createList(start);
                   break;
            case 2:start = insertAtEnd(start);
                   break;
            case 3:start = insertAtBegin(start);
                   break;
            case 4:start = insertAfter(start);
                   break;
            case 5:start = insertBefore(start);
                   break;
            case 7:start = deleteList(start);
                   break;
            case 8:start = deleteAtEnd(start);
                   break;
            case 9:start = deleteAtBegin(start);
                   break;
            case 10:start = deleteAfter(start);
                   break;
            case 11:start = deleteBefore(start);
                    break;
            case 12:displayList(start);
                    break;
            case 13:start = deleteNode(start);
                    break;
            case -1:printf("Exited\n");
                    break;
            default:printf("Choose the correct option\n");
                    break;
        }
    }while(option != -1);

	return 0;
}

