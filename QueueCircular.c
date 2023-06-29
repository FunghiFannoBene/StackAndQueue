typedef struct {
    int* queue;
    int head;
    int tail;
    int size;
    int max_size;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return(obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return(obj->size == obj->max_size);
}


MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* list = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
     list->queue = (int*)malloc(sizeof(int)*k);
    list->head = -1;
    list->tail = -1;
    list->size=0;
    list->max_size=k;
    return list;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if(myCircularQueueIsFull(obj))
      return false;
    if(myCircularQueueIsEmpty(obj))
      obj->head=0;
    
    obj->tail=(obj->tail+1) % obj->max_size;
    obj->queue[obj->tail] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
  if(myCircularQueueIsEmpty(obj))
      return false;
    if(obj->head == obj->tail) //reset
    {
        obj->head = -1;
        obj->tail = -1;
    }
    else
    {
        obj->head = (obj->head+1) % obj->max_size;
    }
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
      return -1;
    return obj->queue[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
      return -1;
    return obj->queue[obj->tail];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}


/*When removing an element from the front of a circular queue using obj->head = (obj->head + 1) % obj->capacity;
, the element is not physically deleted from the underlying array. Instead, the front pointer 
is updated to effectively skip over the previous front element, marking it as logically removed.

The circular queue implementation typically uses the front and rear 
pointers to track the positions of the front and rear elements, respectively. 
By updating the front pointer to the next position in the circular manner, 
the previous front element is logically removed from the queue.*/

