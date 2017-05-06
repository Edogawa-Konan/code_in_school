/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 */

package PIM_pro;

public interface PIMDate
{
    abstract void setdate(Date_ date);
    abstract void setdate(int year,int month,int day);
    abstract Date_ getdate();
}
