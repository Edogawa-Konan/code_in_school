package HW2;
/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/5/25.
 */

import java.io.*;
import java.util.ArrayList;

import java.util.List;
import java.util.Scanner;

import static java.lang.System.out;

public class Main
{
    private List<account> data;
    private ObjectInputStream Fin;
    private ObjectOutputStream Fout;
    public int getnumber()
    {
        return this.data.size();
    }
    public account getaccount(String name)
    {
        for (int i=0;i<this.data.size();i++)
        {
            if (this.data.get(i).getName().equals(name))
                return this.data.get(i);
        }
        return createaccount(1,name);
    }
    public account createaccount(int choice,String name)
    {
        if (choice==1)
        {
            this.data.add(new CashAccount(name));
        }
        else
        {
            this.data.add(new CreditAccount(name));
        }
        return this.data.get(this.data.size()-1);
    }
    public Main()
    {
        load();
        if (this.data==null)
            this.data=new ArrayList<>();
    }
    private void load()
    {
        try {
            Fin=new ObjectInputStream(new FileInputStream("E:\\intellij\\homework\\src\\data"));
            data=(List<account>)Fin.readObject();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        catch (ClassNotFoundException e)
        {
            out.println(e.getMessage());
        }
        finally
        {
            try
            {
                Fin.close();
            }
            catch (IOException e)
            {
                out.println(e.getMessage());
            }
        }
    }
    private void save()
    {
        try
        {
            Fout=new ObjectOutputStream(new FileOutputStream("E:\\intellij\\homework\\src\\data"));
            Fout.writeObject(this.data);
        }
        catch (Exception e)
        {
            out.println(e.getMessage());
        }
        finally
        {
            try {
                Fout.close();
            }
            catch (Exception e)
            {
                out.println(e.getMessage());
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        Main it=new Main();
        out.println("Welcome!");
        out.println("请选择login或create");
        account a;
        if (in.next().equals("login"))
        {
            String name=in.next();
            a=it.getaccount(name);
        }
        else
        {
            out.println("请选择1-现金账户,2-信用账户，并输入用户名");
            a=it.createaccount(in.nextInt(),in.next());
        }
        String input="Y";
        while (input.equals("Y"))
        {
            float num;
            out.println("选择操作代号: 1-存钱 2-取钱 3-修改名字 4-打印最近6笔交易");
            try {
                switch (in.nextInt())
                {
                    case 1:
                        out.print("输入待存金额:");
                        num=in.nextFloat();
                        a.deposit(num);
                        out.printf("已经存了%.1f元，剩余%.1f元\n",num,a.remain());
                        break;
                    case 2:
                        out.print("输入待取金额:");
                        num=in.nextFloat();
                        out.printf("已经取了%.1f元，剩余%.1f元\n", a.withdraw(num),a.remain());
                        break;
                    case 3:
                        out.print("输入欲修改的名字:");
                        String name=in.next();
                        a.changename(name);
                        out.printf("已经修改为%s",name);

                    case 4:
                        a.print_transaction();
                        break;
                    default:
                        out.println("mdzz");
                        break;
                }
            }
            catch (IllegalArgumentException e)
            {
                out.println(e.getMessage());
                out.println("请重新操作");
                continue;
            }

            out.println("是否继续操作? Y/N");
            input=in.next();
        }
        it.save();
        out.println("Bye!");
    }
}
