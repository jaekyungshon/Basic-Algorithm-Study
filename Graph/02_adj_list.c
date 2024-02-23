#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g){
    g->n=0;
    for(int v=0; v<MAX_VERTICES; v++){
        g->adj_list[v]=NULL;
    }
}

void insert_vertex(GraphType* g, int v){
    if(((g->n)+1) > MAX_VERTICES){
        return;
    }
    g->n++;
}

// 연결 리스트 맨 처음 삽입 기준
void insert_edge(GraphType* g, int u, int v){
    GraphNode* node;
    if(u>=g->n || v>=g->n){
        return;
    }
    
    node=(GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u];
    g->adj_list[u]=node;
}

void print_adj_list(GraphType* g){
    for(int i=0; i<g->n; i++){
        GraphNode* p=g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while(p!=NULL){
            printf("-> %d ", p->vertex);
            p=p->link;
        }
        puts("");
    }
}

// 정점의 차수 반환
int get_degree(GraphType* g, int v){
    GraphNode* p = g->adj_list[v];
    int tmp=0;

    while(p!=NULL){
        tmp++;
        p=p->link;
    }

    return tmp;
}

int main(void){
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for(int i=0; i<4; i++){
        insert_vertex(g,i);
    }

    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,3);
    insert_edge(g,3,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,3,2);

    print_adj_list(g);

    printf("%d의 정점 차수 : %d\n", 0, get_degree(g,0));
    
    free(g);
    return 0;
}