package PIM_pro;

import java.io.Serializable;

/**
 *@author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 *
 */


public class PIMAppointment extends PIMEntity implements PIMDate,Serializable
{
    private Date_ date=new Date_();
    private String des;


    public PIMAppointment(String priority,Date_ date,String des,String owner,boolean ispublic)
    {
        this.Priority=priority;
        this.date.setDate_(date);
        this.des=des;
        this.owner=owner;
        this.ispubilc=ispublic;
    }
    public PIMAppointment(String s)
    {
        this.fromString(s);
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
    @Override
    public String toString()
    {
        return "priority: "+this.Priority+" date: "+this.date+" description: "+this.des+" owner: "+this.owner+" ispublic: "+this.ispubilc+'\n';
    }
    @Override
    public void fromString(String s)
    {/**
    *@author 马源 1977786930@qq.com
    *@date 2017 3 11
    *@param priority-year month day-description
    *@return void
    */
        String[] tmp=s.split("-");
        this.Priority=tmp[0];
        this.des=tmp[2];
        String[] tmp2=tmp[1].split(" ");
        this.date.setDate_(Integer.parseInt(tmp2[0]),Integer.parseInt(tmp2[1]),Integer.parseInt(tmp2[2]));
    }
}
