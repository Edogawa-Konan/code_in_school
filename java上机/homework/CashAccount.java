package HW2;
/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/25.
 */

import java.io.Serializable;
import java.util.ArrayDeque;


public class CashAccount extends account implements Serializable
{
    public CashAccount(String name)
    {
        this.name=name;
        trac=new ArrayDeque<>();
    }
    @Override
    public void deposit(float amount)
    {
        if (amount<0)
            throw new IllegalArgumentException("存款金额小于0");
        this.balance+=amount;
        record(amount);
    }
    @Override
    public float withdraw(float amount)
    {
        if (this.balance<amount)
            throw new IllegalArgumentException("现金卡账户余额不足");
        this.balance-=amount;
        record(-amount);
        return amount;
    }
    private void record(float amount)
    {
        if (trac.size()==6)
        {
            trac.pollLast();
        }
        trac.offerFirst(new transaction(amount));
    }
}
