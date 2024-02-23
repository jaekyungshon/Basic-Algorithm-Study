#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphType {
    int n; // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init(GraphType* g){
    g->n=0;
    for(int r=0; r<MAX_VERTICES; r++){
        for(int c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c]=0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    if(((g->n)+1) > MAX_VERTICES){
        return;
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end){
    if(start>=g->n || end>=g->n){
        return;
    }
    // 무방향 그래프 기준 : 대칭 행렬
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

//인접 행렬 출력 함수
void print_adj_mat(GraphType* g){
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%2d ",g->adj_mat[i][j]);
        }
        puts("");
    }
}

// 정점 차수 반환
int get_degree(GraphType* g, int v){
    int tmp=0;
    for(int i=0; i<g->n; i++){
        tmp+=g->adj_mat[v][i];
    }
    return tmp;
}

int main(){
    GraphType* g=(GraphType*)malloc(sizeof(GraphType));
    init(g);

    for(int i=0; i<4; i++){
        insert_vertex(g,i);
    }

    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);

    print_adj_mat(g);

    printf("%d의 정점 차수 : %d\n",0,get_degree(g,0));
    
    free(g);
}