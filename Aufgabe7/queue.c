#include <queue.h>
#include <stdlib.h>
void dequeue(QueuePtr queue, char *taskName){

}


void enqueue(QueuePtr queue, Task task, char *taskName){

}


void destroyQueue(QueuePtr queue){

}


QueuePtr initQueue(){
    QueuePtr queue = malloc(sizeof(Queue));
    if(queue==NULL){
        exit(-1);
    }
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}

printQueue(QueuePtr queue){

}
