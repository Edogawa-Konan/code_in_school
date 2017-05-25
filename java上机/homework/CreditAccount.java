package HW2;
/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/25.
 */

import java.io.Serializable;
import java.util.ArrayDeque;


public class CreditAccount extends account implements Serializable
{
    public CreditAccount(String name)
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
        if (this.balance-amount<-1000)
            throw new IllegalArgumentException("信用卡账户透支超过1000，取钱操作失败");
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
