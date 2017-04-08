package graph;

import java.util.Iterator;


/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/8.
 */
public class Bag<Item> implements Iterable<Item>
{
    private Node first;//起始节点
    private class Node
    {
        Item item;
        Node next;
    }
    public void add(Item item)
    {//头插法
        Node oldfirst=first;
        first=new Node();
        first.item=item;
        first.next=oldfirst;
    }
    @Override
    public Iterator<Item> iterator()
    {
        return new ListIterator();
    }
    private class ListIterator implements Iterator<Item>
    {
        private Node current=first;
        @Override
        public boolean hasNext()
        {
            return current!=null;
        }
        @Override
        public Item next()
        {
            Item item=current.item;
            current=current.next;
            return item;
        }
    }
}








