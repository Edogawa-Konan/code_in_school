/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/3/3.
 */
import java.io.*;
import java.util.Scanner;

import static java.lang.System.out;


public class PIMManager implements Serializable
{
    public static void main(String[] args)
    {
        out.println("Welcome to PIM.");
        Scanner in=new Scanner(System.in);
        String buff="1";//存储输入的命令
        PIMContact[] pimcontact=new PIMContact[30];
        PIMAppointment[] pimappointment=new PIMAppointment[30];
        PIMNote[] pimnote=new PIMNote[30];
        PIMTodo[] pimtodo=new PIMTodo[30];
        int contact=0;
        int appointment=0;
        int note=0;
        int todo=0;
        int total=contact+appointment+note+todo;
        flag:
        while (!buff.equals("Quit"))
        {
            out.println("---Enter a command (suported commands are List Create Save Load Quit)---");
            buff=in.nextLine();
            switch (buff)
            {
                case "List":
                    if(contact==0&&appointment==0&&note==0&&todo==0)
                    {
                        out.println("There are 0 items.");
                    }
                    else out.println("There are "+total+" items.");
                    if(contact>0)
                    {
                        for(int i=0;i<contact;i++)
                            out.println(pimcontact[i]);
                    }
                    if(appointment>0)
                    {
                        for(int i=0;i<appointment;i++)
                            out.println(pimappointment[i]);
                    }
                    if (note>0)
                    {
                        for(int i=0;i<note;i++)
                            out.println(pimnote[i]);
                    }
                    if (todo>0)
                    {
                        for(int i=0;i<todo;i++)
                            out.println(pimtodo[i]);
                    }
                    continue flag;
                case "Create":
                    out.println("Enter an item type ( todo, note, contact or appointment )");
                    buff=in.nextLine();
                    while (!(buff.equals("todo")||buff.equals("note")||buff.equals("contact")||buff.equals("appointment")))
                    {
                        out.println("Your are wrong! Please input again!");
                        buff=in.nextLine();
                    }
                    switch (buff)
                    {
                        case "todo":
                            out.println("Please input as this formal: priority-date-todo");
                            buff=in.nextLine();
                            pimtodo[todo]=new PIMTodo(buff);
                            todo+=1;
                            break;
                        case "note":
                            out.println("Please input as this formal: priority-note");
                            buff=in.nextLine();
                            pimnote[note]=new PIMNote(buff);
                            note+=1;
                            break;
                        case "contact":
                            out.println("Please input as this formal: priority-firstname lastname-email");
                            buff=in.nextLine();
                            pimcontact[contact]=new PIMContact(buff);
                            contact+=1;
                            break ;
                        case "appointment":
                            out.println("Please input as this formal: priority-date-description");
                            buff=in.nextLine();
                            pimappointment[appointment]=new PIMAppointment(buff);
                            appointment+=1;
                            break ;
                    }
                    break;
                case  "Save":
                    try
                    {//先保存长度再保存对象
                        ObjectOutputStream op=new ObjectOutputStream(new FileOutputStream("Appointment"));
                        op.writeInt(appointment);
                        op.writeObject(pimappointment);
                        op=new ObjectOutputStream(new FileOutputStream("Note"));
                        op.writeInt(note);
                        op.writeObject(pimnote);
                        op=new ObjectOutputStream(new FileOutputStream("Todo"));
                        op.writeInt(todo);
                        op.writeObject(pimtodo);
                        op=new ObjectOutputStream(new FileOutputStream("Contact"));
                        op.writeInt(contact);
                        op.writeObject(pimcontact);
                        op.close();
                    }
                    catch (Exception ex)
                    {
                        ex.printStackTrace();
                    }
                    break;
                case "Load":
                    try
                    {
                        ObjectInputStream op=new ObjectInputStream(new FileInputStream("Note"));
                        note=(int)op.readInt();
                        pimnote=(PIMNote[])op.readObject();


                        op=new ObjectInputStream(new FileInputStream("Contact"));
                        contact=(int)op.readInt();
                        pimcontact=(PIMContact[])op.readObject();


                        op=new ObjectInputStream(new FileInputStream("Todo"));
                        todo=(int)op.readInt();
                        pimtodo=(PIMTodo[])op.readObject();


                        op=new ObjectInputStream(new FileInputStream("Appointment"));
                        appointment=(int)op.readInt();
                        pimappointment=(PIMAppointment[])op.readObject();


                        out.println(note+" "+todo+" "+appointment+" "+contact);
                    }
                    catch (Exception ex)
                    {
                        ex.printStackTrace();
                    }
                    break;
                case "Quit":break;
            }
        }
        out.println("see you next time.");
    }
}
