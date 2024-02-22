/*
* Min Heap
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
}element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size=0;
}

void insert_min_heap(HeapType* h, element item){
    int i;
    i=++(h->heap_size);

    while((i!=1) && (item.key < h->heap[i/2].key)){
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i]=item;
}

element delete_min_heap(HeapType* h){
    int parent,child;
    element item,temp;

    parent=1; child=2; // init: root, left child by root
    item=h->heap[1]; // return item
    temp=h->heap[(h->heap_size)--]; // target of comparing

    while(child<=h->heap_size){
        if((child<h->heap_size) && (h->heap[child].key > h->heap[child+1].key)){
            child++;
        }
        if(temp.key <= h->heap[child].key){
            break;
        }
        h->heap[parent]=h->heap[child];
        parent=child;
        child*=2;
    }
    
    h->heap[parent]=temp;
    return item;
}

int main(void){
    /* Example Using*/
    element e1={10}, e2={5}, e3={30};
    element e4,e5,e6;
    HeapType* heap;

    heap=create();
    init(heap);

    insert_min_heap(heap,e1);
    insert_min_heap(heap,e2);
    insert_min_heap(heap,e3);

    e4=delete_min_heap(heap);
    e5=delete_min_heap(heap);
    e6=delete_min_heap(heap);

    printf("%d -> %d -> %d\n",e4.key, e5.key, e6.key); // 결과 출력

    free(heap);
    return 0;
}