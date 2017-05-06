package PIM_pro;

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import static java.lang.System.out;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/9.
 */


public class PIMFileEngine implements RemotePIMCollection
{
    private String filename;//保存数据的文件名
    private ObjectInputStream Fin;
    private ObjectOutputStream Fout;
    private PIMCollection data;//用于缓存数据的数组
    private Iterator<PIMEntity> it;
    private List<String> account;
    public PIMFileEngine(String filename)
    {
        this.filename=filename;
        data=new PIMCollection();
    }
    String current_account()
    {
        if (account==null||account.size()==0)
            return "";
        else
            return account.get(0);
    }
    List<String> get_account()
    {
        if (account==null)
            account=new ArrayList<>();
        return this.account;
    }
    PIMFileEngine getdata()
    {
        return this;
    }
    @Override
    public PIMCollection getNotes()
    {
        return data.getNotes();
    }
    @Override
    public PIMCollection getNotes(String owner)
    {
        return data.getNotes(owner);
    }
    @Override
    public PIMCollection getTodos()
    {
        return data.getTodos();
    }
    @Override
    public PIMCollection getTodos(String owner)
    {
        return data.getTodos(owner);
    }
    @Override
    public PIMCollection getAppointments()
    {
        return data.getAppointments();
    }
    @Override
    public PIMCollection getAppointments(String owner)
    {
        return data.getAppointments(owner);
    }
    @Override
    public PIMCollection getContacts()
    {
        return data.getContacts();
    }
    public PIMCollection getContacts(String owner)
    {
        return data.getContacts(owner);
    }
    @Override
    public PIMCollection getItemsForDate(Date_ d)
    {
        return data.getItemsForDate(d);
    }
    @Override
    public PIMCollection getItemsForDate(Date_ d,String owner)
    {
        return data.getItemsForDate(d,owner);
    }
    @Override
    public PIMCollection getAll()
    {
        return data.getAll();
    }
    @Override
    public PIMCollection getAllByOwner(String owner)
    {
        return data.getAllByOwner(owner);
    }

    public void delItemsForDate(Date_ d,String owner)
    {
        data.delItemsForDate(d);
    }
    public void delItemsForDate(Date_ d)
    {
        data.delItemsForDate(d);
    }
    public void save()
    {
        try
        {
            Fout=new ObjectOutputStream(new FileOutputStream(filename));
            Fout.writeObject(data);
            Fout=new ObjectOutputStream(new FileOutputStream("E:\\intellij\\Personal Information Manager\\account"));
            Fout.writeObject(account);
        }
        catch (IOException e)
        {
            out.println("保存失败");
            out.println(e.getMessage());
        }
        finally
        {
            if (Fin!=null)
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
    }
    public void load()
    {
        try
        {
            Fin=new ObjectInputStream(new FileInputStream(filename));
            data=(PIMCollection) Fin.readObject();
            Fin=new ObjectInputStream(new FileInputStream("E:\\intellij\\Personal Information Manager\\account"));
            account=(List<String>) Fin.readObject();
        }
        catch (Exception ex)
        {
            out.println("加载失败");
            ex.printStackTrace();
            out.println(ex.getMessage());
        }
        finally
        {
            if (Fin!=null)
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
    @Override
    public boolean add(PIMEntity item)
    {
        return data.add(item);
    }


    public boolean del(PIMEntity item)
    {
        return data.del(item);
    }



    public static void main(String[] args)
    {
        PIMFileEngine core=new PIMFileEngine("E:\\intellij\\Personal Information Manager\\data");
        core.load();
        System.out.println(core.getItemsForDate(new Date_(2017,5,7)));
        core.delItemsForDate(new Date_(2017,5,7));
        System.out.println(core.getItemsForDate(new Date_(2017,5,7)));
    }
}
