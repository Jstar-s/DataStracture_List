//
// Created by HP on 2020/2/25.
//
#include <cstdio>
#include <string>
#define MAXVEX 100
#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define MAX 256
typedef struct EdgeNode			// �߱���
{
    int adjvex;					// �ڽӵ��򣬴洢�ö����Ӧ���±�
    int weight;					// ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
    struct EdgeNode *next;		// ����ָ����һ���ڽӵ�
} EdgeNode;

typedef struct VertexNode		// �������
{
    char data;					// �����򣬴洢������Ϣ
    EdgeNode *firstEdge;		// �߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;	// ͼ�е�ǰ�������ͱ���
} GraphAdjList;

// ����ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;

    printf("�����붥�����ͱ�����\n");
    scanf("%d %d", &G->numVertexes,&G->numEdges);

    // ��ȡ������Ϣ�����������
    for( i=0; i < G->numVertexes; i++)
    {
        printf("���붥��");
        printf("%d %d",G->numVertexes, i);
        scanf("%s", &G->adjList[i].data);
        G->adjList[i].firstEdge = NULL;		// ��ʼ����Ϊ�ձ�
    }

    for( k=0; k < G->numEdges; k++ )
    {
        printf("�������(Vi,Vj)�ϵĶ�����ţ�\n");
        scanf("%d %d", &i, &j);

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;						// �ڽ����Ϊj
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;						// �ڽ����Ϊi
        e->next = G->adjList[j].firstEdge;
        G->adjList[j].firstEdge = e;
    }
}

typedef int Boolean;
Boolean visited[MAX];

void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c", GL.adjList[i].data);
    p = GL.adjList[i].firstEdge;
    while (p)
    {
        if(!visited[p->adjvex])
        {
            DFS(GL, p->adjvex);
        }
        p = p->next;
    }
}
void DFSTraverse(GraphAdjList GL)
{
    int i;

    for( i=0; i < GL.numVertexes; i++ )
    {
        visited[i] = FALSE;		// ��ʼ�����ж���״̬����δ���ʹ�״̬
    }

    for( i=0; i < GL.numVertexes; i++ )
    {
        if( !visited[i] )		// ������ͨͼ��ֻ��ִ��һ��
        {
            DFS(GL, i);
        }
    }
}

void BTS(GraphAdjList GL)
{
    

}
int main()
{
    GraphAdjList *G;
    CreateALGraph(G);
    return 0;
}
