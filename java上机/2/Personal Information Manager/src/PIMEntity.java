import java.io.Serializable;

public abstract class PIMEntity implements Serializable
{
    String Priority; // every kind of item has a priority

    // default constructor sets priority to "normal"
    PIMEntity() {
        Priority = "normal";
    }

    // priority can be established via this constructor.
    PIMEntity(String priority) {
        Priority =  priority;
    }

    // accessor method for getting the priority string
    public String getPriority() {
        return Priority;
    }
    // method that changes the priority string
    public void setPriority(String p) {
        Priority = p;
    }

    // Each PIMEntity needs to be able to set all state information
    // (fields) from a single text string.
    abstract public void fromString(String s);

    // This is actually already defined by the super class
    // Object, but redefined here as abstract to make sure
    // that derived classes actually implement it
    abstract public String toString();
}

class Date_ implements Serializable,Comparable<Date_>
{
    private int year;
    private int month;
    private int day;
    public Date_()
    {
        this.year=2017;
        this.month=1;
        this.day=1;
    }
    public Date_(int year,int month,int day)
    {
        this.year=year;
        this.month=month;
        this.day=day;
    }
    public void setDate_(int year,int month,int day)
    {
        this.year=year;
        this.month=month;
        this.day=day;
    }
    public void setDate_(Date_ date)
    {
        this.year=date.year;
        this.month=date.month;
        this.day=date.day;
    }
    public String toString()
    {
        return year+" "+month+" "+day;
    }
    public int getyear()
    {
        return this.year;
    }
    public int getmonth()
    {
        return this.month;
    }
    public int getday()
    {
        return this.day;
    }
    @Override
     public int compareTo(Date_ o)
     {
         if (o.getyear()==this.getyear()&&o.getmonth()==this.getmonth()&&o.getday()==this.getday())
             return 0;
         if (this.getyear()>o.getyear())
             return 1;
         else if (this.getmonth()>o.getmonth())
             return 1;
         else if (this.getday()>o.getday())
             return 1;
         else return -1;
     }
}


