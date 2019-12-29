#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/** Checks
 *  int a[n] head == tail == 0
 *  insert head; a[head] = v;  head = head ? --head : n - 1
 *  add tail ; a[tail] = v; tail = tail == n? 0 : ++tail
 * 
 * */

typedef struct {
    int *payload;
    int size;
    int head;
    int tail;
    
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    if(k <= 0) return NULL;
    MyCircularDeque *ret = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    ret->size = k;
    ret->payload = malloc(sizeof(int) * (ret->size + 1));
    ret->head = ret->tail = 0;
    return ret;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size) {
        if(obj->head) {
            if(obj->tail != obj->head - 1) {
                obj->payload[obj->head--] = value;
            } else{
                return false;
            }
        } else {
            if(obj->tail == obj->size) {
                return false;
            } else {
                obj->payload[obj->head] = value;
                obj->head = obj->size;
            }
        }
    } else {
        return false;
    }
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size) {
        if(obj->head) {
            if(obj->tail != obj->head - 1) {
                obj->payload[obj->tail++] = value;
                if(obj->tail > obj->size) {
                    obj->tail = 0;
                }
            } else {
                return false;
            }
        } else {
            if(obj->tail != obj->size) {
                obj->payload[obj->tail++] = value;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) 
{
    if(obj->size) {
        if(obj->head != obj->tail) {
            if(obj->head == obj->size) {
                obj->head = 0;
            } else {
                ++obj->head;
            }
            return true;
        }
    }
    return false;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size) {
        if(obj->head != obj->tail) {
            if(obj->tail) {
                --obj->tail;
                if(obj->tail < 0) {
                    obj->tail = obj->size;
                }
            } else {
                obj->tail = obj->size;
            }
            return true;
        }
    }
    return false;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) 
{
    printf("%s head %d\n", __func__, obj->head);
    if(obj->head == obj->size) {
        printf("%d\n",obj->payload[0]);
        return obj->payload[0];
    }
    return obj->payload[obj->head + 1];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) 
{
    printf("%s tail %d\n", __func__, obj->tail);
    if(obj->tail)
        return obj->payload[obj->tail - 1];
    return obj->payload[obj->size];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) 
{
    return obj->head == obj->tail;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->head) {
        return (obj->head - obj->tail) == 1;
    } else {
        return (obj->tail == obj->size);
    }
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(obj->payload) {
        free(obj->payload);
    }
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/


int main(int argc, char *argv[])
{
bool param_1 = myCircularDequeInsertFront(obj, value);
bool param_2 = myCircularDequeInsertLast(obj, value);
bool param_3 = myCircularDequeDeleteFront(obj);
bool param_4 = myCircularDequeDeleteLast(obj);
int param_5 = myCircularDequeGetFront(obj);
int param_6 = myCircularDequeGetRear(obj);
bool param_7 = myCircularDequeIsEmpty(obj);
bool param_8 = myCircularDequeIsFull(obj);
myCircularDequeFree(obj);
    return 0;
}