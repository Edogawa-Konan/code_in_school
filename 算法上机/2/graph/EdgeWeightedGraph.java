package graph;


import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/8.
 */
public class EdgeWeightedGraph
{
    private int E;//总边数
    private int V;//总顶点数
    private ArrayList<Bag<Edge>> adj;//邻接表，每一个元素对应一个链表


    public EdgeWeightedGraph(int V)
    {
        this.V=V;
        this.E=0;
        adj=new ArrayList<Bag<Edge>>(V);
        for (int v=0;v<V;v++)
            adj.add(v,new Bag<Edge>());
    }
    public EdgeWeightedGraph(Scanner in)
    {
        this(in.nextInt());
        System.out.println("请输入边数");
        int E=in.nextInt();
        System.out.println("请输入边的两个顶点及权重，空格分割");
        for (int i=0;i<E;i++)
        {
            int v=in.nextInt();
            int w=in.nextInt();
            double weight=in.nextDouble();
            this.addEdge(new Edge(v,w,weight));
        }
    }
    public  EdgeWeightedGraph(RandomAccessFile f) throws IOException
    {
        this(Integer.parseInt(f.readLine()));
        int E=Integer.parseInt(f.readLine());
        for (int i=0;i<E;i++)
        {
            String tmp=f.readLine();
            String[] res=tmp.split(" ");
            int v=Integer.parseInt(res[0]);
            int w=Integer.parseInt(res[1]);
            double weight=Double.parseDouble(res[2]);
            this.addEdge(new Edge(v,w,weight));
        }
    }
    public void addEdge(Edge e)
    {
        int v=e.either();
        int w=e.other(v);
        adj.get(v).add(e);
        adj.get(w).add(e);
        E++;
    }
    public int V()
    {
        return this.V;
    }
    public int E()
    {
        return this.E;
    }
    public Iterable<Edge> adj(int v)
    {
        return adj.get(v);
    }
    public Iterable<Edge> edges()
    {//返回加权无向图中所有边
        Bag<Edge> b=new Bag<>();
        for (int v=0;v<V;v++)
            for (Edge e:adj.get(v))
            {
                if (e.other(v)>v)
                    b.add(e);
            }
        return b;
    }
}
