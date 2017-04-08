import java.util.ArrayList;
import java.util.Iterator;


import static java.lang.System.out;


/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/11.
 */
public class PIMCollection extends ArrayList<PIMEntity>
{
    private Iterator<PIMEntity> it;
    public ArrayList<PIMNote> getNotes()
    {
        ArrayList<PIMNote> res=new ArrayList<>();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if (obj instanceof PIMNote)
                res.add((PIMNote)obj);
        });
        return res;
    }
    public ArrayList<PIMTodo> getTodos()
    {
        ArrayList<PIMTodo> res=new ArrayList<>();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if(obj instanceof PIMTodo)
                res.add((PIMTodo)obj);
        });
        return res;
    }
    public ArrayList<PIMAppointment> getAppointments()
    {
        ArrayList<PIMAppointment> res=new ArrayList<>();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if (obj instanceof PIMAppointment)
                res.add((PIMAppointment)obj);
        });
        return res;
    }
    public ArrayList<PIMContact> getContact()
    {
        ArrayList<PIMContact> res=new ArrayList<>();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if(obj instanceof PIMContact)
                res.add((PIMContact) obj);
        });
        return res;
    }
    public ArrayList<PIMEntity>  getItemsForDate(Date_ d)
    {
        ArrayList<PIMEntity> res=new ArrayList<>();
        it=this.iterator();
        it.forEachRemaining(obj->{
            if(obj instanceof PIMAppointment )
            {
                if(((PIMAppointment) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
            if(obj instanceof PIMTodo)
            {
                if (((PIMTodo) obj).getdate().compareTo(d)==0)
                    res.add(obj);
            }
        });
        return res;
    }

    public static void main(String args[])
    {
        PIMCollection tmp=new PIMCollection();
        for (int i=0;i<5;i++)
        {
            tmp.add(new PIMNote("note-"+i));
            tmp.add(new PIMAppointment("appointment-2017 3 11-"+i));
            tmp.add(new PIMTodo("todo-2017 3 12-"+i));
            tmp.add(new PIMContact("contact-ma yuan-"+i));
        }
        out.println(tmp.getNotes());
        out.println(tmp.getAppointments());
        out.println(tmp.getContact());
        out.println(tmp.getTodos());
        out.println(tmp.getItemsForDate(new Date_(2017,3,11)));
    }
}

