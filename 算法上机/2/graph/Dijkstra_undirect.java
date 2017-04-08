package graph;



import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayDeque;
import java.util.Scanner;


/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/8.
 */

public class Dijkstra_undirect
{
    private Edge[] edgeTo;//edgeTo[v]表示最短路径树中连接v和它父节点的边
    private double[] distTo;//distTo[v]表示从原点s到v的已知最短路径的长度
    private IndexMinPQ<Double> pq;

    public Dijkstra_undirect(EdgeWeightedGraph G,int s)
    {
        edgeTo=new Edge[G.V()];
        distTo=new double[G.V()];
        pq=new IndexMinPQ<>(G.V());

        for (int v=0;v<G.V();v++)
        {
            distTo[v]=Double.POSITIVE_INFINITY;
        }
        distTo[s]=0.0;

        pq.insert(s,0.0);

        while (!pq.isEmpty())
        {
            relax(G,pq.delMin());
        }
    }
    private void relax(EdgeWeightedGraph G,int v)
    {
        for (Edge e:G.adj(v))
        {
            int w=e.other(v);
            if(distTo[w]>distTo[v]+e.weight())
            {
                distTo[w]=distTo[v]+e.weight();
                edgeTo[w]=e;
                if (pq.contains(w))
                    pq.changeKey(w,distTo[w]);

                else pq.insert(w,distTo[w]);
            }
        }
    }
    public boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }
    public Iterable<Edge> pathTo(int v)
    {
        if (!hasPathTo(v)) return null;
        ArrayDeque<Edge> path=new ArrayDeque<>();
        int x = v;
        for (Edge e = edgeTo[v]; e != null; e = edgeTo[x]) {
            path.addFirst(e);
            x = e.other(x);
        }
        return path;
    }
    public static void main(String[] args) throws IOException
    {
//        Scanner in=new Scanner(System.in);

        RandomAccessFile f=new RandomAccessFile("E:\\intellij\\oj\\src\\graph\\node","r");
//       EdgeWeightedGraph G=new EdgeWeightedGraph(in);

        EdgeWeightedGraph G=new EdgeWeightedGraph(f);
        f.close();
        Dijkstra_undirect sp=new Dijkstra_undirect(G,0);

        for (int t = 0; t < G.V(); t++)
        {
            if (sp.hasPathTo(t))
            {
                System.out.printf("%d -> %d (weight:%.2f)  ", 0, t, sp.distTo[t]);

                for (Edge e : sp.pathTo(t))
                {
                    System.out.print(e + "   ");
                }
                System.out.println();
            } else {
                System.out.printf("%d to %d         no path\n", 0, t);
            }
        }
    }
}

