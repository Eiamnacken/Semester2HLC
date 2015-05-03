#include <queue.h>
#include <stdlib.h>
#include <string.h>

const char error[][50]={{"Keinen Speicher freigegeben"},{"Liste ist Leer"}};


QueuePtr initQueue(){
    QueuePtr queue = malloc(sizeof(Queue));
    if(queue==NULL){
        printf("%s",error[0]);
        exit(-1);
    }
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}

void enqueue(QueuePtr queue, Task task, char *taskName){
    TaskListNodePtr newTask = malloc(sizeof(TaskListNode));
    if(newTask==NULL){
        printf("%s",error[0]);
        exit(-1);
    }else{
        newTask->task=task;
        strcpy(newTask->taskname,taskName);
        newTask->next=NULL;
    }
    if(queue->head==NULL){
        queue->head=newTask;
        queue->tail=newTask;
    }else{
        queue->tail->next=newTask;
        queue->tail=newTask;
    }
}

void dequeue(QueuePtr queue, char *taskName){
    TaskListNodePtr * save;
    if(queue->head!=NULL){
        save=&queue->head;
        queue->head=queue->head->next;

        free(save);
    }else{
        printf("%s",error[1]);
    }
}

void printQueue(QueuePtr queue){
    TaskListNodePtr  task=malloc(sizeof(TaskListNode));
    if(queue->head!=NULL){
        task=queue->head;
        while(task!=NULL){
            printf("%s\n",task->taskname);
            task=task->next;
        }
    }else{
        printf("%s\n",error[1]);
    }
}



void destroyQueue(QueuePtr queue){
    free(queue);
}



