/**
 * @author Nhat M. Nguyen
 * @since  12-12-2018
 */

import java.io.*;
import java.util.*;

public class Main {
    static InputReader in = new InputReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        new Solution().solve();
        out.close();
    }

    static class Solution {
        final int INF = Integer.MAX_VALUE;
        int nV;
        int nE;
        ArrayList<Edge>[] adj;
        boolean[] visited;
        int[] dist;
        int[] parent;
        long mstWeight;

        void solve() {
            nV = in.nextInt();
            nE = in.nextInt();
            adj = new ArrayList[nV + 1];
            for (int u = 1; u <= nV; u++) {
                adj[u] = new ArrayList<>();
            }
            for (int i = 0; i < nE; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                adj[u].add(new Edge(v, w));
                adj[v].add(new Edge(u, w));
            }
            prim(1);
            out.println(mstWeight);
        }

        /**
         * This implementation largely based on Dijkstra
         * Tested with SPOJ-MST: https://www.spoj.com/problems/MST/
         * @param src source vertex
         */
        void prim(int src) {
            visited = new boolean[nV + 1];
            dist = new int[nV + 1];
            parent = new int[nV + 1];
            for (int u = 1; u <= nV; u++) {
                visited[u] = false;
                dist[u] = INF;
                parent[u] = -1;
            }
            PriorityQueue<Edge> priorityQueue = new PriorityQueue<>();
            priorityQueue.add(new Edge(src, 0));
            while (!priorityQueue.isEmpty()) {
                Edge minEdge = priorityQueue.poll();
                int u = minEdge.v;
                visited[u] = true;
                for (Edge e : adj[u]) {
                    if (!visited[e.v] && dist[e.v] > e.w) {
                        dist[e.v] = e.w;
                        parent[e.v] = u;
                        priorityQueue.add(e);
                    }
                }
            }
            mstWeight = 0;
            for (int u = 1; u <= nV; u++) {
                if (parent[u] == -1) continue; // handle src
                mstWeight += (long) dist[u];
            }
        }

        class Edge implements Comparable<Edge> {
            int v;
            int w;

            public Edge(int v, int w) {
                this.v = v;
                this.w = w;
            }

            @Override
            public int compareTo(Edge other) {
                return Integer.compare(this.w, other.w);
            }
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream inStream) {
            this.reader = new BufferedReader(new InputStreamReader(inStream));
            this.tokenizer = null;
        }

        /**
         * @return String the whole line (including all whitespaces)
         *         or null line is empty
         */
        String nextLine() {
            this.tokenizer = null;
            String line = null;
            try {
                line = this.reader.readLine();
            }
            catch (Exception e) {
                e.printStackTrace();
            }
            return line;
        }

        /**
         * @return String next token, or null if the current line is empty
         */
        String next() {
            while (this.tokenizer == null || !this.tokenizer.hasMoreTokens()) {
                String line = nextLine();
                if (line == null) return null;
                this.tokenizer = new StringTokenizer(line);
            }
            return this.tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        char nextChar() {
            return next().charAt(0);
        }
    }
}
