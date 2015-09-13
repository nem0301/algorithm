#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000


int parent[MAX_VERTICES];
int num[MAX_VERTICES];


//////////////////  union find ///////////////////////////

void set_init(int n){
    int i;
    for(i = 0; i < n; i++)
    {
        parent[i] = -1;
        num[i] = 1;
    }
}

int set_find(int vertex)
{
    int p, s, i;
    for (i = vertex; (p = parent[i]) >= 0; i = p);
    
    s = i;
    
    for (i = vertex; (p = parent[i]) >= 0; i = p)
        parent[i] = s;

    return s;
}

void set_union(int s1, int s2)
{
    if ( num[s1] < num[s2] )
    {
        parent[s1] = s2;
        num[s2] += num[s1];
    }
    else
    {
        parent[s2] = s1;
        num[s1] += num[s2];
    }
}

////////////////// end of union find ///////////////////////////


// queue
typedef struct {
    int weight;
    int u;
    int v;
}element_t;

typedef struct {
    int size;
    element_t* elem;
}queue_t;

//compareFuntion for qsort
int compareFunction (const void* aa, const void* bb)
{
    element_t* a = (element_t*)aa;
    element_t* b = (element_t*)bb;
    
    if ( a->weight > b->weight)
        return -1;
    else if ( a->weight < b->weight)
        return 1;
    else
        return 0;
}


void insertElement(queue_t* q, int u, int v, int weight)
{
    if(q->size > 0)
    {
        q->elem = (element_t*) realloc (q->elem, (q->size + 1) * sizeof(element_t));
    }
    else
    {
        q->elem = (element_t*) malloc (sizeof(element_t));
        
    }
    
    q->elem[q->size].weight = weight;
    q->elem[q->size].u = u;
    q->elem[q->size].v = v;
    q->size++;

}

element_t deleteElement(queue_t* q)
{
    if (q->size < 1)
    {
        printf("empty queue\n");
        element_t e;
        e.weight = -1;
        return e;
    }
    else
    {
        q->size--;
        element_t e = q->elem[q->size];
        q->elem = (element_t*) realloc (q->elem, (q->size) * sizeof(element_t));

        return e;
    }

}

///////////// end of queue/////////


//////////////////// kruskal //////////////////////////
void insertAllEdges(queue_t* q)
{

    insertElement(q, 0, 1, 29);
    insertElement(q, 1, 2, 16);
    insertElement(q, 2, 3, 12);
    insertElement(q, 3, 4, 22);
    insertElement(q, 4, 5, 27);
    insertElement(q, 5, 0, 10);
    insertElement(q, 6, 1, 15);
    insertElement(q, 6, 3, 18);
    insertElement(q, 6, 4, 25);
}

void kruskal(int n)
{
    int edgeAccepted = 0;
    queue_t q;
    q.size = 0;
    int uSet, vSet;
    element_t e;
    insertAllEdges(&q);
    qsort(q.elem, q.size, sizeof(element_t), compareFunction);

    set_init(n);

    
    while (edgeAccepted < (n - 1))
    {
        e = deleteElement(&q);
        if ( e.weight == -1 )
            break;

        uSet = set_find(e.u);
        vSet = set_find(e.v);

        if ( uSet != vSet )
        {
            printf("(%d, %d) %d \n", e.u, e.v, e.weight);
            edgeAccepted++;
            set_union(uSet, vSet);
        }
    }
    


}

int main(void)
{
    kruskal(7);
    return 0;
}


























