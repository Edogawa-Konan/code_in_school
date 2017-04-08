package graph;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/8.
 */
public class Edge implements Comparable<Edge>
{
    @Override
    public int compareTo(Edge that)
    {
        if (that.weight()>this.weight())
            return -1;
        else if (that.weight()==this.weight())
            return 0;
        else
            return 1;

    }
    private final int v;//起点
    private final int w;//终点
    private final double weight;//权重
    public Edge(int v,int w,double weight)
    {
        this.v=v;
        this.w=w;
        this.weight=weight;
    }
    public double weight()
    {
        return this.weight;
    }
    public int either()
    {
        return this.v;
    }
    public int other(int v)
    {
        if (v==this.v) return this.w;
        else if (v==this.w) return this.v;
        else throw new RuntimeException("该顶点不属于此边");
    }
    @Override
    public String toString()
    {
        return String.format("%d-%d %.2f",v,w,weight);
    }
}
