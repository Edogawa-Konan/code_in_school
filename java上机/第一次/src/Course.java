/**
 * @author 马源 14130110069 1977786930@qq.com
 */
public class Course
{
    public static void main(String[] args)
    {

        Student yuanzhouxin = new Student(args);

    }
}

class Student
{
    private String num;
    private Book[] books=new Book[100];
    private int BookNum=0;
    public Student(String...args)
    {
        this.num=args[0];
        System.out.print(num+" choose ");
        for(int i=1;i<args.length-1;i++)
        {
            this.books[i]=new Book(args[i]);
            System.out.print(args[i]+" and ");
        }
        System.out.println(args[args.length-1]);
        this.books[args.length-1]=new Book(args[args.length-1]);
    }

}
class Book
{
    private String name;
    public Book(String name)
    {
        this.name=name;
    }
}
