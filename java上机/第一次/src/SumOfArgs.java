import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author 马源 14130110069 1977786930@qq.com
 *
 */

public class SumOfArgs {
    public static boolean isNum(String s)
    {
        Pattern pat=Pattern.compile("[0-9]*");
        Matcher is=pat.matcher(s);
        return is.matches();
    }
    public static void main(String[] args)
    {
        Integer result=0;
        for(int i=0;i<args.length;i++)
        {
            if(isNum(args[i]))
            {
                result+=Integer.parseInt(args[i]);
            }
        }
        System.out.println(result);
    }
}
