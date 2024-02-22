/*
*** Max Heap Sorting ***
*
* [시간복잡도]
* => n개의 요소 탐색 + 삭제 연산 속도
* => 즉, n개의 요소를 히프에서 삭제한다.
* => n*트리의 높이만큼 탐색
* => O(n*log n)
* => 가장 효율적인 상황 : 가장 큰값 몇개만 필요할 경우.(또는 작은값)
*
* [과정]
* 1. 정렬되지 않은 1차원 배열, 새로운 배열 준비.
* 2. Max Heap에 차례로 삽입.
* 3. len(arr)만큼 원소 삭제 및 새 배열에 삽입.
*
* [Note]
* => 최대 히프를 통한 오름차순 정렬 : 새 배열의 뒤부터 삽입.
* => 최대 히프를 통한 내림차순 정렬 : 새 배열의 앞부터 삽입.
* => 최소 히프를 통한 오름차순 정렬 : 새 배열의 앞부터 삽입.
* => 최소 히프를 통한 내림차순 정렬 : 새 배열의 뒤부터 삽입.
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

void insert_heap(HeapType* h, element item){
    int i;
    i=++(h->heap_size);

    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i]=h->heap[i/2];
        i/=2;
    }

    h->heap[i]=item;
}

element delete_heap(HeapType* h){
    int parent,child;
    element item,temp;

    parent=1; child=2;
    item=h->heap[1];
    temp=h->heap[(h->heap_size)--];

    while(child<=h->heap_size){
        if((child<h->heap_size) && (h->heap[child].key < h->heap[child+1].key)){
            child++;
        }
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

// 우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n){
    HeapType* h;

    h=create();
    init(h);

    // 정렬되지 않은 배열의 원소들 히프에 삽입
    for(int i=0; i<n; i++){
        insert_heap(h,a[i]);
    }
    // 히프의 원소들을 차례로 새 배열에 삽입.(오름차순 기준)
    for(int i=(n-1); i>=0; i--){
        a[i]=delete_heap(h);
    }

    free(h);
}

int main(void){
    element list[8] = {23,56,11,9,56,99,27,34};
    heap_sort(list,8);

    for(int i=0; i<8; i++){
        printf("%d ", list[i].key);
    }   
    puts("");
    return 0;
}