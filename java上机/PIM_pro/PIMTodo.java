package PIM_pro;

import java.io.Serializable;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 */



public class PIMTodo extends PIMEntity implements PIMDate,Serializable
{
    private Date_ date=new Date_();
    private String todo;
    public PIMTodo(String Priority, Date_ date, String todo,String owner,boolean ispubilc)
    {
        this.Priority=Priority;
        this.date=date;
        this.todo=todo;
        this.owner=owner;
        this.ispubilc=ispubilc;
    }
    public PIMTodo(String s)
    {
        this.fromString(s);
    }

    @Override
    public String toString()
    {
        return "priority: "+Priority+" date: "+date+" todo: "+todo+" owner: "+owner+" ispublic: "+ispubilc+'\n';
    }
    @Override
    public void fromString(String s)
    {/**
    *@author 马源 1977786930@qq.com
    *@date  2017/3/11
    *@param 输入字符串，格式为 priority-year month day-todo
    *@return  void
    */
        String[] tmp = s.split("-");
        this.Priority = tmp[0];
        this.todo = tmp[2];
        String[] tmp2 = tmp[1].split(" ");
        try {
            this.date.setDate_(Integer.parseInt(tmp2[0]), Integer.parseInt(tmp2[1]), Integer.parseInt(tmp2[2]));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    @Override
    public void setdate(Date_ date)
    {
        this.date.setDate_(date);
    }
    @Override
    public void setdate(int year,int month,int day)
    {
        this.date.setDate_(year,month,day);
    }
    @Override
    public Date_ getdate()
    {
        return this.date;
    }

}
