/**
 * Created by 19777 on 2017/3/4.
 */
public class Substring
{
    public static void main(String[] args)
    {
        if (args.length<3)
            System.out.println("input wrong!");
        else
        {
            System.out.println(args[0].substring(Integer.parseInt(args[1]),Integer.parseInt(args[2])));
        }
    }

}
