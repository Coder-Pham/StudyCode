/**
 *  Author: Nhat M. Nguyen
 *  Date: 09-11-17
**/

import java.util.Scanner;
import java.util.ArrayList;

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
            int w = in.nextInt();
            graph.addEdge(u, v, w);
        }

		// Dijkstra
        graph.dijkstra(0);
    }
}

class Graph {
    public int nVertices = 0;
    public ArrayList<Integer>[] adjList;
    public ArrayList<Integer>[] adjListWeight;
    public int dist[];
    private final int INF = (int) 1e6; // Do not use Integer.MAXVALUE (overflow)

    public Graph(int nVertices) {
        // Get the number of vertices
        this.nVertices = nVertices;

        // Create adjList and list of weights
        this.adjList = new ArrayList[nVertices];
        this.adjListWeight = new ArrayList[nVertices];
        for (int i = 0; i < nVertices; i++) {
            this.adjList[i] = new ArrayList<>();
            this.adjListWeight[i] = new ArrayList<>();
        }

        // Initialize dist for every vertex
        this.dist = new int[nVertices];
        for (int i = 0; i < nVertices; i++) {
            this.dist[i] = INF;
        }
    }

    public void addEdge(int u, int v, int w) {
        adjList[u].add(v);
        adjList[v].add(u);
        adjListWeight[u].add(w);
        adjListWeight[v].add(w);
    }

    private void relax(int u, int v, int w) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
        }
    }

    void dijkstra(int s) {
        // Set all vertices to not visited
        boolean[] isVisited = new boolean[nVertices];
        for (int i = 0; i < nVertices; i++) {
            isVisited[i] = false;
        }

        // Set the distance from the starting vertex to itself to 0
        dist[s] = 0;

        // Start visiting each vertex
        for (int i = 0; i < nVertices; i++) {
            // Find the vertex which has the minimum dist currently
            int u = -1;
            int minDist = Integer.MAX_VALUE;

            for (int j = 0; j < nVertices; j++) {
                if (!isVisited[j] && dist[j] <= minDist) {
                    u = j;
                    minDist = dist[j];
                }
            }

            // "Relax" the adjacent vertices
            isVisited[u] = true;
            for (int j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u].get(j);
                int w = adjListWeight[u].get(j);
                relax(u, v, w);
            }
        }

        // Output
        System.out.println("Shortest distance to each vertex:");
        for (int i = 0; i < nVertices; i++) {
            System.out.println("dist[" + i + "] = " + dist[i]);
        }
    }
}