/**
 *  Author: Nhat M. Nguyen
 *  Date: 09-11-17
 **/

import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
    private static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        // Create a graph with given number of vertices
        System.out.print("Number of vertices: ");
        int nVertices = in.nextInt();
        Graph graph = new Graph(nVertices);

        // ... and edges
        System.out.print("Number of edges: ");
        int nEdges = in.nextInt();

        // Add all edges to the graph
        System.out.println("Input edges: ");
        for (int i = 0; i < nEdges; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            graph.addEdge(u, v);
        }

        // DFS
        graph.dfs(0);
    }
}

class Graph {
    public int nVertices = 0;
    public ArrayList<Integer>[] adjList;

    public Graph(int nVertices) {
        this.nVertices = nVertices;
        this.adjList = new ArrayList[nVertices];
        for (int i = 0; i < nVertices; i++) {
            this.adjList[i] = new ArrayList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjList[u].add(v);
        adjList[v].add(u);
    }

    public void dfs(int s) {
        // Set all vertices to not visited
        boolean[] isVisited = new boolean[nVertices];
        for (int i = 0; i < nVertices; i++) {
            isVisited[i] = false;
        }

	// Visit each vertex recursively
        dfsVisit(s, isVisited);
    }

    private void dfsVisit(int u, boolean[] isVisited) {
        isVisited[u] = true;
        System.out.print(u + " ");

        for (int i = 0; i < adjList[u].size(); i++) {
            int adjVertex = adjList[u].get(i);
            if (!isVisited[adjVertex]) {
                dfsVisit(adjVertex, isVisited);
            }
        }
    }
}