package HW2;
/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/25.
 */


import java.io.Serializable;
import java.util.Deque;

abstract public class account implements Serializable
{
    String name;
    float balance;

    abstract public void deposit(float amount);
    abstract public float withdraw(float amount);
    public String getName()
    {
        return this.name;
    }
    public void changename(String newname)
    {
        this.name=newname;
    }
    public float remain()
    {
        return this.balance;
    }
    Deque<transaction> trac;
    public void print_transaction()
    {
        for (transaction e:trac)
            System.out.println(e);
    }
}
