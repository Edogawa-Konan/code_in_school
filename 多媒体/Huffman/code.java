package Huffman;
/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/17.
 */

import java.util.*;


public class code
{
    static class node implements Comparable<node>
    {
        int val;
        node left;
        node right;
        int position; //为了保证huffman树的唯一性
        node()
        {
            this.val=-1;
            this.left=null;
            this.right=null;
        }
        node(int val)
        {
            this.val=val;
            this.left=null;
            this.right=null;
        }
        @Override
        public int compareTo(node o)
        {
            if (this.val!=o.val)
                return this.val-o.val;
            else
                return this.position-o.position;
        }
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        Queue<node> q=new PriorityQueue<>();
        int n=in.nextInt();
        for (int i=1;i<=n;i++)
        {
            node tmp=new node();
            tmp.val=in.nextInt();
            tmp.position=i;
            q.add(tmp);
        }
        while (q.size()>1)
        {
            node L=q.poll();
            node R=q.poll();
            node tmp=new node(L.val+R.val);
            tmp.left=L;
            tmp.right=R;
            tmp.position=L.position;
            q.add(tmp);
        }
        res=new HashMap<>();
        encode(q.peek(),new ArrayList<>());
        for (Integer e:res.keySet())
            System.out.println(e+"编码为:"+res.get(e));
        List<Integer> tobedecode=new ArrayList<>();
        System.out.println("请输入欲解码的编码");
        String tmp=in.next();
        for (int i=0;i<tmp.length();i++)
            tobedecode.add(tmp.charAt(i)-'0');
//        System.out.println(tobedecode);
        try
        {
            decode(q.peek(),tobedecode);
        }
        catch (AssertionError e)
        {
            System.out.println(e.getMessage());
        }

    }
    private static Map<Integer,List<Integer>> res;
    private static void encode(node root,List<Integer> prefix)
    {//回溯法打印编码
        if (root.right==null&&root.left==null)
        {
            res.put(root.val,new ArrayList<>(prefix));
        }
        else
        {
            prefix.add(0);
            encode(root.left,prefix);
            prefix.remove(prefix.size()-1);

            prefix.add(1);
            encode(root.right,prefix);
            prefix.remove(prefix.size()-1);
        }
    }
    private static void decode(node root,List<Integer> prefix)
    {//解码prefix
        if (prefix.size()==0&&root.left==null&&root.right==null)
            System.out.println("该编码表示字符的优先级为"+root.val);
        else if (prefix.size()>0&&prefix.get(0)==0&&root.left!=null)
        {
            prefix.remove(0);
            decode(root.left,prefix);
        }
        else if (prefix.size()>0&&prefix.get(0)==1&&root.right!=null)
        {
            prefix.remove(0);
            decode(root.right,prefix);
        }
        else
        {
            throw new AssertionError("未能识别的编码");
        }
    }

    private static void print(node root)
    {//先序遍历huffman树，debug用
        if (root==null)
            return;
        else
        {
            System.out.print(root.val+"  ");
            print(root.left);
            print(root.right);
        }
    }
}

