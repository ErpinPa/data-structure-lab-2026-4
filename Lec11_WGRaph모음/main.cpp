#include "WGraphMST.h"
#include "WGraphPrim.h"
#include "WGraphDijkstra.h"

int main()
{
    WGraphMST g1;

    g1.load("graph.txt");

    printf("입력 그래프\n");
    g1.display();

    printf("\nMST By Kruskal's Algorithm\n\n");
    g1.Kruskal();

    printf("\n\nMST By Prim's Algorithm\n\n");

    WGraphPrim g2;
    g2.load("graph.txt");
    g2.Prim(0);     // A 정점부터 시작

    WGraphDijkstra g3;
    g3.load("graph_sp.txt");
    printf("\n\nMST By Dijkstra's Algorithm\n\n");
    g3.ShortestPath(0);


    return 0;
}
