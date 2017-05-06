package PIM_pro;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/9.
 */
public interface PIMCollect
{
    public PIMCollection getNotes();
    public PIMCollection getNotes(String owner);
    public PIMCollection getTodos();
    public PIMCollection getTodos(String owner);
    public PIMCollection getAppointments();
    public PIMCollection getAppointments(String owner);
    public PIMCollection getContacts();
    public PIMCollection getContacts(String owner);
    public PIMCollection getItemsForDate(Date_ d);
    public PIMCollection getItemsForDate(Date_ d, String owner);
    public PIMCollection getAll();
    public PIMCollection getAllByOwner(String owner);
    public boolean add(PIMEntity entity);
}
