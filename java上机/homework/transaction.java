package HW2;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/25.
 */

import java.io.Serializable;
import java.util.Scanner;

class transaction implements Comparable<transaction>,Serializable
{
    private float balance;
    transaction(float balance)
    {
        this.balance=balance;
    }
    public transaction()
    {
        this.balance=0;
    }
    float getBalance()
    {
        return this.balance;
    }
    @Override
    public int compareTo(transaction o)
    {
        return (int)(this.getBalance()-o.getBalance());
    }
    @Override
    public String toString()
    {
        return "balance:"+this.balance;
    }
}
