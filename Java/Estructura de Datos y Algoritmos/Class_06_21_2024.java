/*
    Objetivos:
    
    - BFS (Breadth First Search): Algoritmo de búsqueda en anchura. (Queue)
    - DFS (Depth First Search): Algoritmo de búsqueda en profundidad. (Stack)
    - Aplicaciones (SSSP (Single Source Shortest Path) Djikstra, Bellman-Ford, Topological Sort, MST (Kruskal, Prim), etc).

    Grafos dispersos: Grafos con pocos aristas.
    Grafos densos: Grafos con muchos aristas.

    Matriz de adyacencia:

    - Memoria O(V^2). Donde V es el número de nodos.

    Lista de adyacencia:

    - Memoria O(V + E). Donde E es el número de aristas.
*/

import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

class Class_06_21_2024
{
    public static void main(String[] args)
    {
        Graph graph = new Graph(7);

        graph.addEdge(1,3);
        graph.addEdge(1,4);
        graph.addEdge(1,5);
        graph.addEdge(4,6);
        graph.addEdge(6,2);
        graph.addEdge(4,2);
        graph.addEdge(6,3);
        
        graph.print();       
        
        // graph.dfs(0);

        graph.bfs(2);
    }

    static class Graph
    {
        int v; // Número de nodos
        int[][] adj; // Matriz de adyacencia

        public Graph(int v)
        {
            this.v = v;
            this.adj = new int[v][v];
        }

        public void addEdge(int u, int v) // Agregar arista
        {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        public void removeEdge(int u, int v)
        {
            adj[u][v] = 0;
            adj[v][u] = 0;
        }

        public void dfs(int s)
        {
            Stack<Integer> st = new Stack<>();
            boolean[] visited = new boolean[v];
            st.push(s);
            visited[s] = true;
            while (!st.isEmpty())
            {
                int node = st.pop();
                System.out.print(node + " ");
                for (int i = 0; i < v; i++)
                {
                    // Si el nodo i no es adyacente a node o ya fue visitado, se ignora
                    if (adj[node][i] == 0 || visited[i])
                    {
                        continue;
                    }
                    st.push(i);
                    visited[i] = true;
                }
            }
            System.out.println();
        }

        public void bfs(int s)
        {
            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[v];
            q.add(s);
            visited[s] = true;
            while (!q.isEmpty())
            {
                int node = q.poll();
                System.out.print(node + " ");
                for (int i = 0; i < v; i++)
                {
                    if (adj[node][i] == 0 || visited[i] == true)
                    {
                        continue;
                    }
                    q.add(i);
                    visited[i] = true;
                }
            }
            System.out.println();
        }

        public void djikstra(int s)
        {
            int[] dist = new int[v];
            boolean[] visited = new boolean[v];
            for (int i = 0; i < v; i++)
            {
                dist[i] = Integer.MAX_VALUE;
            }
            dist[s] = 0;
            for (int i = 0; i < v; i++)
            {
                int u = minDistance(dist, visited);
                visited[u] = true;
                for (int j = 0; j < v; j++)
                {
                    if (!visited[j] && adj[u][j] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + adj[u][j] < dist[j])
                    {
                        dist[j] = dist[u] + adj[u][j];
                    }
                }
            }
            for (int i = 0; i < v; i++)
            {
                System.out.println(i + " " + dist[i]);
            }
        }

        public int minDistance(int[] dist, boolean[] visited)
        {
            int min = Integer.MAX_VALUE;
            int minIndex = -1;
            for (int i = 0; i < v; i++)
            {
                if (!visited[i] && dist[i] <= min)
                {
                    min = dist[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }

        public void print()
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    System.out.print(adj[i][j] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
