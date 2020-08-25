#ifndef _LINKED_LIST
#define _LINKED_LIST
struct node{
    int data;
    struct node* next;
};

int checkEmpty(struct node* start);
struct node* createList(struct node*);
struct node* insertAtEnd(struct node*);
struct node* insertAtBegin(struct node*);
struct node* insertAfter(struct node*);
struct node* insertBefore(struct node*);
struct node* deleteList(struct node*);
struct node* deleteAtEnd(struct node*);
struct node* deleteAtBegin(struct node*);
struct node* deleteAfter(struct node*);
struct node* deleteBefore(struct node*);
struct node* deleteNode(struct node*);
void displayList(struct node*);


struct node* createList(struct node* start){
    struct node* ptr,*temp;
    int data;
    char response='\0';
    printf("Enter y and then data for entering the node data or q to exit\n");
    while(1){
        scanf("%c",&response);
        if(response == 'y' ||  response == 'Y'){
            printf("Enter data");
            scanf("%d",&data);
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = NULL;
            if(start == NULL){
                start = temp;     
            }else{
                ptr = start;
                while(ptr->next != NULL){
                    ptr=ptr->next;
                }
                ptr->next = temp; 
            }
        }else if(response == 'Q' ||  response == 'q'){
            break;
        }else{
            //printf("Enter the correct response\n");
        }
    }
    return start;    
}
struct node* insertAtEnd(struct node* start){
    struct node *ptr,*temp;
    int data;
    ptr = start;
    if(checkEmpty(ptr))
        return start;
    printf("Enter data");
    scanf("%d",&data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = temp; 
    return start;
}
struct node* insertAtBegin(struct node* start){
    struct node* temp;
    int data;
    if(checkEmpty(start))
        return start;
    printf("Enter data");
    scanf("%d",&data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start = temp;
    return start;
}
int checkEmpty(struct node* start){
    if(start == NULL){
        printf("List is empty\n");
        return 1;
    }else{
        return 0;
    }
}
struct node* insertAfter(struct node* start){
    struct node *ptr = start;
    struct node *temp;
    int nodeData,data;
    if(checkEmpty(ptr))
        return start;
    printf("Enter the node value after which the data has to insert\n");
    scanf("%d",&nodeData);
    while(ptr->data != nodeData){
        if(ptr == NULL){
            printf("not in the list\n");
            return start;
        }
        ptr = ptr->next;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
    return start;      
}
struct node* insertBefore(struct node* start){
    struct node* ptr = start;
    struct node* temp,*preptr;
    int nodeData,data;
    if(checkEmpty(ptr))
        return start;
    printf("Enter the node value before which the data has to insert\n");
    scanf("%d",&nodeData);
    if(ptr->data == nodeData){
        ptr = insertAtBegin(ptr);
        return ptr;
    }
    while(ptr->data != nodeData){
        if(ptr == NULL){
            printf("not in the list or last element.\n");
            return start;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data = data;
    temp->next = ptr;
    preptr->next = temp;
    return start;      
}
struct node* deleteList(struct node* start){
    struct node* ptr = start;
    struct node* preptr;
    if(checkEmpty(ptr))
        return start;
    while(ptr != NULL){
        preptr = ptr;
        printf("%d being deleted...\n",ptr->data);
        ptr = ptr->next;
        free(preptr);
    }
    start = NULL;
    return start;
}
struct node* deleteAtEnd(struct node* start){
    struct node* ptr = start;
    struct node* preptr;
    if(checkEmpty(ptr))
        return start;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node* deleteAtBegin(struct node* start){
    if(checkEmpty(start))
        return start;
    struct node* ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node* deleteAfter(struct node* start){
    struct node* ptr,*postptr;
    ptr = start;
    int nodeData;
    printf("Enter the node data after which data has to be deleted\n");
    scanf("%d",&nodeData);
    if(checkEmpty(start))
        return start;
    while(ptr->data != nodeData){
        ptr = ptr->next;
        if(ptr == NULL){
            printf("entered data is not in the list\n");
            return start;
        }
    }
    printf("%d is being deleted\n",ptr->next->data);
    postptr = ptr->next;
    ptr->next = ptr->next->next;
    free(postptr);
    return start;
}
struct node* deleteBefore(struct node* start){
}
void displayList(struct node* start){
    struct node* ptr = start;
    if(checkEmpty(ptr))
        return;
    printf("\n\nList values are : ");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
struct node* deleteNode(struct node* start){
}
#endif
