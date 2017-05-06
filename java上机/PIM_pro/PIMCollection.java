package PIM_pro;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import static java.lang.System.out;


/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/9.
 */


public class PIMCollection extends ArrayList<PIMEntity> implements PIMCollect,Serializable
{
    transient private Iterator<PIMEntity> it;

    @Override
    public PIMCollection getNotes()
    {//仅仅获取公开信息
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMNote"))
                if (tmp.getowner().equals("")||tmp.ispubilc)
                    res.add(tmp);
        }
        return res;
    }
    @Override
    public PIMCollection getNotes(String owner)
    {//获取全部信息
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMNote"))
            {
                if(tmp.getowner().equals(owner))
                    res.add(tmp);
            }
        }
        return res;
    }

    @Override
    public PIMCollection getTodos()
    {//获取公开信息
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMTodo"))
                if (tmp.getowner().equals("")||tmp.ispubilc)
                    res.add(tmp);
        }
        return res;
    }
    @Override
    public PIMCollection getTodos(String owner)
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMTodo"))
                if (tmp.getowner().equals(owner))
                    res.add(tmp);
        }
        return res;
    }

    @Override
    public PIMCollection getAppointments()
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMAppointment"))
            {
                if (tmp.getowner().equals("")||tmp.ispubilc)
                    res.add(tmp);
            }
        }
        return res;
    }
    @Override
    public PIMCollection getAppointments(String owner)
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMAppointment"))
            {
                if (tmp.getowner().equals(owner))
                    res.add(tmp);
            }
        }
        return res;
    }

    @Override
    public PIMCollection getContacts()
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMContact"))
                if (tmp.getowner().equals("")||tmp.ispubilc)
                res.add(tmp);
        }
        return res;
    }
    @Override
    public PIMCollection getContacts(String owner)
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        while (it.hasNext())
        {
            PIMEntity tmp=it.next();
            if (tmp.getClass().getName().equalsIgnoreCase("PIM_pro.PIMContact"))
                if (tmp.getowner().equals(owner))
                    res.add(tmp);
        }
        return res;
    }


    @Override
    public PIMCollection getItemsForDate(Date_ d)
    {
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if(obj instanceof PIMAppointment&&(obj.ispubilc||obj.getowner().equals("")))
            {
                if(((PIMAppointment) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
            if(obj instanceof PIMTodo&&(obj.ispubilc||obj.getowner().equals("")))
            {
                if (((PIMTodo) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
        });
        return res;
    }

    @Override
    public PIMCollection getItemsForDate(Date_ d,String owner)
    {
        it=this.iterator();
        PIMCollection res=new PIMCollection();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if(obj instanceof PIMAppointment&&obj.getowner().equals(owner))
            {
                if(((PIMAppointment) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
            if(obj instanceof PIMTodo&&obj.getowner().equals(owner))
            {
                if (((PIMTodo) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
        });
        return res;
    }

    public void delItemsForDate(Date_ d)
    {
        this.removeAll(this.getItemsForDate(d));
    }

    public void delItemsForDate(Date_ d,String owner)
    {
        this.removeAll(this.getItemsForDate(d,owner));
    }



    public PIMCollection getAll()
    {
        return this;
    }
    @Override
    public PIMCollection getAllByOwner(String owner)
    {
        it=this.iterator();
        PIMCollection res=new PIMCollection();
        it.forEachRemaining(obj->{
            if(obj.getowner().equals(owner))
                res.add(obj);
        });
        return res;
    }

    public boolean add(PIMEntity entity)
    {
        return super.add(entity);
    }

    public boolean del(PIMEntity entity)
    {
        return super.remove(entity);
    }



    public static void main(String[] args)
    {
        PIMCollection tmp=new PIMCollection();
        for (int i=0;i<2;i++)
        {
            tmp.add(new PIMNote("relax","java上机完善"+i,"prime",true));
            tmp.add(new PIMAppointment("normal",new Date_(2017,4,24),"见朱光明"+i,"prime",true));
            tmp.add(new PIMTodo("normal",new Date_(2017,4,22),"找导师"+i,"prime",true));
            tmp.add(new PIMContact("normal","ma","yuan","1977786930@qq.com","prime",true));
        }


        tmp.add(new PIMNote("relax","私有note","prime",false));
        tmp.add(new PIMTodo("relax",new Date_(2017,4,2),"私有todo","prime",false));
        tmp.add(new PIMAppointment("normal",new Date_(2017,4,24),"私有appointment","prime",false));

        out.println("公有note");
        out.println(tmp.getNotes());

        out.println("prime's note");
        out.println(tmp.getNotes("prime"));

        out.println("公有appointment");
        out.println(tmp.getAppointments());
        out.println("prime's appointment");
        out.println(tmp.getAppointments("prime"));

        out.println("公有contact");
        out.println(tmp.getContacts());
        out.println("prime's contact");
        out.println(tmp.getContacts("prime"));

        out.println("公有todo");
        out.println(tmp.getTodos());
        out.println("prime's todo");
        out.println(tmp.getTodos("prime"));

        out.println("get all prime's items");
        out.println(tmp.getAllByOwner("prime"));

        out.println("get 2017 4 24 belong prime");
        out.println(tmp.getItemsForDate(new Date_(2017,4,24),"prime"));
    }
}
