#include <queue.h>
#include <stdlib.h>
#include <string.h>

// Char Array fuer Fehler ausgaben nicht verwenden nur fuer Ausgabe!!
const char error[][50]={{"Keinen Speicher freigegeben"},{"Liste ist Leer"}};


QueuePtr initQueue(){
    QueuePtr queue = malloc(sizeof(Queue));
    if(queue==NULL){
        printf("%s\n",error[0]);
        exit(-1);
    }
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}

void enqueue(QueuePtr queue, Task task, char *taskName){
    TaskListNodePtr newTask = malloc(sizeof(TaskListNode));
    if(newTask==NULL){//Falls Speicher zu weisen fehl schlägt
        printf("%s",error[0]);
        exit(-1);
    }else{
        newTask->task=task;
        strcpy(newTask->taskname,taskName);
        newTask->next=NULL;
    }
    //Erstes zu weisen Sonderfall
    if(queue->head==NULL){
        queue->head=newTask;
        queue->tail=newTask;
    //Normalfall
    }else{
        queue->tail->next=newTask;
        queue->tail=newTask;
    }
}

void dequeue(QueuePtr queue, char *taskName){
    TaskListNodePtr save = queue->head;
    if(queue->head!=NULL){
        save->task(42);//Ausfuehren des Tasks
        strcpy(taskName,save->taskname);//Speicher des Tasknamen
        queue->head=queue->head->next;
        free(save);
        save=NULL;
    }else{
        //Falls die Liste leer ist.
        printf("%s\n",error[1]);
        taskName[0]='\0';
    }
}

void printQueue(QueuePtr queue){
    TaskListNodePtr  task=malloc(sizeof(TaskListNode));
    if(queue->head!=NULL){
        /*
         * Falls die iste leer ist muss nicht die Liste durchsucht werden
         * kann aber auch fehler sein wenn head leer ist.
         * */
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
    TaskListNodePtr tasks;
    if(queue==NULL){
        printf("%s\n",error[1]);
        return;
    }
    while (queue->head!=NULL) {
        //Gehe die Liste durch bis head NULL ist und gib den Speicher frei
        tasks=queue->head;
        queue->head=queue->head->next;
        free(tasks);
    }
    free(queue);
    queue=NULL;
}



