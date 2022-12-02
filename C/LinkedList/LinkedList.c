#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct data1
{
    int i;
    int j;
}Data1;

void displayData(Data1 *data){

    printf("i = %d\nj = %d\n", data->i, data->j);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////



typedef struct LinkedList
{
    void *data;
    struct LinkedList * next;

    struct LinkedList *(*add)(struct LinkedList **,struct  LinkedList **, void*, size_t); //add node
    void(*removeNode)(struct LinkedList **,struct  LinkedList **,struct  LinkedList *); //remove node
    void(*displayList)(struct LinkedList *, void(*)(void*)); //display linked list
}LinkedList;

void removeNode(LinkedList ** Head, LinkedList ** Last, LinkedList *node){
    if(node != NULL){
        LinkedList * temp = (*Head);
        LinkedList * prev = NULL;

        assert(temp != NULL);

        while(temp != NULL){

            if(temp == node)
                break;

            prev = temp;
            temp = temp->next;
        }

        if(temp != NULL){
            if(temp != (*Head))
            {
                if(temp != (*Last))
                    prev->next = temp->next;
                else{
                    prev->next = NULL;
                    (*Last) = prev;
                }
            }
            else{
                (*Head) = temp->next;
            }
            printf("\nThe node with this data has been removed: \n");
            void(*display)(void *);
            free(temp);
            return;
        }
        printf("\nNo such node!\n");
    }
}

LinkedList * add(LinkedList ** Head, LinkedList ** Last, void * data, size_t data_size){
    LinkedList * node = (LinkedList *)malloc(sizeof(LinkedList));

    node->data = malloc(data_size);
    node->next = NULL;

    for(int i=0; i<data_size; i++)
        *(char *)(node->data + i) = *(char *)(data + i);

    if((*Head)==NULL){
        (*Head) = (*Last) = node;
    }
    else{
        (*Last)->next = node;
        (*Last) = node;
    }
    printf("Node added!!\n");
    return node;
}

void displayList(LinkedList * List, void(*func)(void*)){

    LinkedList * temp = List;
    int i=1;
    while(temp != NULL){
        printf("\nData %d: \n", i++);
        func(temp->data);
        temp = temp->next;
    }

}

LinkedList * LinkedListInit(void * data){
    LinkedList * List = (LinkedList*)malloc(sizeof(LinkedList));

    List->data = data;
    List->add = &add;
    List->removeNode = &removeNode;
    List->displayList = &displayList;
}



int main(){

    LinkedList * Head = LinkedListInit(NULL);
    LinkedList * Last = LinkedListInit(NULL);
    Data1  data1 = {.i = 10, .j = 100};
    Data1  data2 = {.i = 20, .j = 200};
    Data1  data3 = {.i = 30, .j = 300};

    Head->add(&Head, &Last, &data1, sizeof(Data1));
    LinkedList * node = Head->add(&Head, &Last, &data2, sizeof(Data1));
    Head->add(&Head, &Last, &data3, sizeof(Data1));


    //Head->displayList(Head, &displayData);

    Head->removeNode(&Head, &Last, node);

  //  Head->displayList(Head, &displayData);




    return 0;
}
