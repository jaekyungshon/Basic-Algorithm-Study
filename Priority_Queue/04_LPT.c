#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int id; // 기계 번호
    int avail; // 해당 기계 사용가능 시간.
}element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size=0;
}

void insert_min_heap(HeapType* h, element item){
    int i;
    i=++(h->heap_size);

    while((i!=1) && (item.avail < h->heap[i/2].avail)){
        h->heap[i]=h->heap[i/2];
        i/=2;
    }

    h->heap[i]=item;
}

element delete_min_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    parent=1; child=2;
    item=h->heap[1];
    temp=h->heap[(h->heap_size)--];

    while(child<=h->heap_size){
        if((child<h->heap_size) && (h->heap[child].avail > h->heap[child+1].avail)){
            child++;
        }
        if(temp.avail <= h->heap[child].avail){
            break;
        }
        h->heap[parent]=h->heap[child];
        parent=child;
        child*=2;
    }
    h->heap[parent]=temp;
    return item;
}

#define JOBS 7
#define MACHINES 3

int main(void){
    int jobs[JOBS] = {8,7,6,5,3,2,1}; // 작업 정렬되 있다고 가정.
    element m={0,0};
    HeapType* h=create();
    init(h);

    // 기계의 종료시간(사용가능시간) 초기화 후, 히프에 삽입.
    for(int i=0; i<MACHINES; i++){
        m.id=i+1;
        m.avail=0;
        insert_min_heap(h,m);
    }

    // 최소 힙에서 기계 꺼내서 작업 할당 및 시간 갱신후
    // 다시 최소 힙에 삽입.
    for(int i=0; i<JOBS; i++){
        m=delete_min_heap(h);
        printf("JOB %d : Time(%d~%d) - Machine #%d\n", i, m.avail, m.avail+jobs[i]-1, m.id);
        m.avail+=jobs[i];
        insert_min_heap(h,m);
    }

    
    return 0;
}