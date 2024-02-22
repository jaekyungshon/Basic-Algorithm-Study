/*
* Max Heap
* tree height : log(2)n
* insert and delete : O(log n)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct elmeent {
    int key;
}element;

typedef struct HeapType {
    element heap[MAX_ELEMENT]; // Heap by Array
    int heap_size; // Current Heap Size
}HeapType;

// Create Function
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// Initial Function
void init(HeapType* h){
    h->heap_size=0;
}

// Insert Function
void insert_max_heap(HeapType* h, element item){
    int i;
    i=++(h->heap_size);

    // [Comparing to Parent-Node]
    // Current target isnt parent index
    // and
    // current target data priority > target's parent data priority
    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2]; // parent node go to current node (overriding)
        i/=2; // current go to the parent
    }
    h->heap[i]=item; // insert to new node
}

// Delete Function
element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item=h->heap[1]; // root node (after return)
    temp=h->heap[(h->heap_size)--]; // last node
    parent=1; child=2; // index

    while(child <= h->heap_size){
        // [Find to maximum child node]
        // Who's the maximum data left or right?
        if((child<h->heap_size) && (h->heap[child].key < h->heap[child+1].key)){
            child++; // right bigger than left
        }
        // last node(initial location : root) >= child
        // current idx is alright location
        if(temp.key >= h->heap[child].key){
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

    insert_max_heap(heap,e1);
    insert_max_heap(heap,e2);
    insert_max_heap(heap,e3);

    e4=delete_max_heap(heap);
    e5=delete_max_heap(heap);
    e6=delete_max_heap(heap);

    printf("%d -> %d -> %d\n",e4.key, e5.key, e6.key);

    free(heap);
    return 0;
}