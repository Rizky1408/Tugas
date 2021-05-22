#include <iostream>
using namespace std;

// struct untuk simpul daftar kedekatan
struct AdjListNode
{
    int data;
    AdjListNode *next;
};

// struct untuk daftar kedekatan
struct AdjList
{
    AdjListNode *head; // penunjuk ke simpul kepala dari daftar
};

// struct untuk grafik. Grafik sebagai susunan daftar kedekatan
// Ukuran array akan menjadi V (total simpul)
struct Graph
{
    int V;
    AdjList *arr;
};

AdjListNode *newAdjListNode(int);
Graph *createGraph(int);
void addEdge(Graph *, int, int);
void printGraph(Graph *);

int main()
{
    system("clear");
    // buat grafik baru
    int totalVertices = 4;
    Graph *graph;
    graph = createGraph(totalVertices);
    // hubungkan tepi
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    /*
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    */
    // cetak representasi daftar kedekatan dari grafik
    printGraph(graph);
}

//buat node baru
AdjListNode *newAdjListNode(int data)
{
    AdjListNode *nptr = new AdjListNode;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
}

// berfungsi untuk membuat grafik V - simpul
Graph *createGraph(int V)
{
    Graph *graph = new Graph;
    graph->V = V;
    // buat larik daftar kedekatan. ukuran array - V
    graph->arr = new AdjList[V];
    // inisialisasi dengan NULL (misalnya root = NULL)
    for (int i = 0; i < V; i++)
    {
        graph->arr[i].head = NULL;
    }
    return graph;
}

// tambahkan tepi ke Grafik yang tidak diarahkan
void addEdge(Graph *graph, int src, int dest)
{
    // Tambahkan tepi dari src ke tujuan. Node baru ditambahkan ke daftar adjacency dari src
    // node ditambahkan di awal
    AdjListNode *nptr = newAdjListNode(dest);
    nptr->next = graph->arr[src].head;
    graph->arr[src].head = nptr;
    // terhubung dari dest ke src (karena tidak diarahkan)
    nptr = newAdjListNode(src);
    nptr->next = graph->arr[dest].head;
    graph->arr[dest].head = nptr;
}

//function untuk print  graph
void printGraph(Graph *graph)
{
    //loop node
    for (int i = 0; i < graph->V; i++)
    {
        AdjListNode *root = graph->arr[i].head;
        cout << "Adjacency list of vertex " << i << endl;
        //loop node dalam list
        while (root != NULL)
        {
            cout << root->data << " -> ";
            root = root->next;
        }
        cout << endl;
    }
}