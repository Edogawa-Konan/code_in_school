package PIM_pro;

import java.io.Serializable;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 */
public class PIMContact extends PIMEntity implements Serializable
{
    private String firstname;
    private String lastname;
    private String email;

    public PIMContact(String s)
    {
        this.fromString(s);
    }

    public PIMContact(String priority,String firstname,String lastname,String email,String owner,boolean ispublic)
    {
        super(priority);
        this.firstname=firstname;
        this.lastname=lastname;
        this.email=email;
        this.owner=owner;
        this.ispubilc=ispublic;
    }
    @Override
    public String toString() {
        return "priority: "+this.Priority+" name: "+this.firstname+" "+this.lastname+" email: "+this.email+" owner: "+this.owner+" ispublic: "+this.ispubilc+'\n';
    }

    @Override
    public void fromString(String s)
    {
        /**
        *@author 马源 1977786930@qq.com
        *@date 2017 3 11
        *@param priority-name-email
        *@return void
        */
        String[] tmp=s.split("-");
        this.Priority=tmp[0];
        this.email=tmp[2];
        String[] tmp2=tmp[1].split(" ");
        this.firstname=tmp2[0];
        this.lastname=tmp2[1];
    }
}
