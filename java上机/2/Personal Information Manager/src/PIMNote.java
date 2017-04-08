import java.io.Serializable;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 */
public class PIMNote extends PIMEntity implements Serializable
{
    private String note;
    public PIMNote(String priority,String note)
    {
        this.Priority=priority;
        this.note=note;
    }
    public PIMNote(String s)
    {
        this.fromString(s);
    }
    @Override
    public String toString()
    {
        return this.Priority+"-"+this.note;
    }
    @Override
    public void fromString(String s)
    {
        String[] tmp=s.split("-");
        this.Priority=tmp[0];
        this.note=tmp[1];
    }

}
