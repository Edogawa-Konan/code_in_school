package PIM_pro;

/**
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/10.
 */

import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.border.LineBorder;
import javax.swing.border.SoftBevelBorder;
import java.awt.*;
import java.awt.Color;
import java.awt.event.*;
import java.awt.font.FontRenderContext;
import java.awt.geom.Rectangle2D;
import java.util.Calendar;


import static java.lang.System.out;

/**
 * @author 马源 14130110069 1977786930@qq.com
 */


public class cal
{
    public PIMFileEngine railgun;//核心数据结构，担任数据库的功能

    private JButton upmonth=new JButton("month+");
    private JButton dowwnmonth=new JButton("month-");
    private JButton upyear=new JButton("year+");
    private JButton downyear=new JButton("year-");

    private JMenuBar tools=new JMenuBar();/*添加菜单条*/
    private JMenu operation=new JMenu("operations");/*添加菜单*/
    private JMenuItem  add=new JMenuItem("add");/*添加菜单项*/
    private JMenuItem del_show=new JMenuItem("show&&del");
    private JMenu account=new JMenu("account");
    private JMenuItem choose=new JMenuItem("switch accounts");

    /*定义框架*/
    private SizedFrame mainFrame=new SizedFrame();

    /*定义容器*/
    private JPanel button=new JPanel();/*四个按钮的容器*/
    private JPanel showday=new JPanel();/*日期显示屏*/
    private JPanel top=new JPanel();/*用于显示年和月*/
    private FontComponent[] display=new FontComponent[49];
    private FontComponent yearandmonth=new FontComponent("");


    final static String[] MONTHS={"January","February","March","April","May","June","July","August","September",
            "October","November","December"};
    final static String[] DAYS ={ "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday" };


    /*欲显示的年和月*/
    public static int year;
    public static int month;


    private void fresh()
    {/*自己造轮子实现屏幕刷新*/
        for (int i=0;i<49;i++)
        {
            if (i<7)
                display[i].setmessage(DAYS[i]);
            else
            {
                display[i].setmessage("");
                display[i].clear();//清除边框，麻烦卧槽啊。
            }
        }
        yearandmonth.setmessage("");
    }


    public void engine()
    {

        Calendar calendar=Calendar.getInstance();

        int current_year=calendar.get(Calendar.YEAR);
        int current_month=calendar.get(Calendar.MONTH);
        int current_day=calendar.get(Calendar.DATE);

        System.out.println("当前年: "+current_year+"当前月: "+current_month+"当前日: "+current_day);

        calendar.set(year,month-1,1);//临时日期，定位这个月的1号，用于下面计算之用

        //不减一时，结果1对应星期天，2对应星期一，以此类推
        int weekday=calendar.get(Calendar.DAY_OF_WEEK)-1;
        int space=0;//记录空格数
        switch (DAYS[weekday])
        {

            case "Sunday":
                space=0;
                break;
            case "Monday":
                space=1;
                break;
            case "Tuesday":
                space=2;
                break;
            case "Wednesday":
                space=3;
                break;
            case "Thursday":
                space=4;
                break;
            case "Friday":
                space=5;
                break;
            case "Saturday":
                space=6;
                break;
        }

        int numofday=calendar.getActualMaximum(Calendar.DAY_OF_MONTH);//计算这个月一共多少天

        out.println(MONTHS[month-1]+"  "+year);

        this.fresh();/*刷新屏幕，为了下面的重写*/

        yearandmonth.setmessage(MONTHS[month-1]+"        "+year);

        railgun.load();//初始化

        int times=1;//记录日期
        for (int i=space+7;i<49&&times<=numofday;i++)
        {//日历布局及交互
            if (current_month==month-1&&current_year==year&&times==current_day)
            {
                this.display[i].setmessage(times+"",true);
            }

            else
            {
                this.display[i].setmessage(times+"");
            }
            if (!railgun.getItemsForDate(new Date_(year,month,times)).isEmpty())
            {
                this.display[i].mark();
                this.display[i].havething(true,railgun.getItemsForDate(new Date_(year,month,times)));
            }
            times++;
        }
    }

    public cal()
    {
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            SwingUtilities.updateComponentTreeUI(mainFrame);
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }

        /*文件驱动系统初始化*/
        railgun=new PIMFileEngine("E:\\intellij\\Personal Information Manager\\data");
//        /*启动先加载*/
//        railgun.load();


        /*按钮添加响应*/
        upmonth.addActionListener(new myaction());
        dowwnmonth.addActionListener(new myaction());
        upyear.addActionListener(new myaction());
        downyear.addActionListener(new myaction());


        /*按钮放置在容器中*/
        button.add(upmonth);
        button.add(dowwnmonth);
        button.add(upyear);
        button.add(downyear);


        /*菜单有关操作*/
        add.addActionListener(obj->{
            new editFrame(railgun);
            engine();  //添加完赶紧刷新
        });
        choose.addActionListener(obj->{
            new accountFrame(railgun.get_account());
        });
        del_show.addActionListener(obj->{
            new DelShow(railgun.getdata());
            engine();
        });


        operation.add(add);
        operation.add(del_show);
        account.add(choose);
        tools.add(operation);
        tools.add(account);

        /*美化一下字体*/
        account.setFont(new Font("Arial", Font.PLAIN, 18));
        choose.setFont(new Font("Arial", Font.PLAIN, 18));
        operation.setFont(new Font("Arial", Font.PLAIN, 18));
        add.setFont(new Font("Arial", Font.PLAIN, 18));
        del_show.setFont(new Font("Arial", Font.PLAIN, 18));


        /*设置背景颜色*/
        showday.setBorder(new LineBorder(new Color(0x09F709),5,true));
        showday.setBackground(new Color(0xFFFF66));
        /*添加键盘响应*/
        showday.addKeyListener(new keyaction());
        showday.setFocusable(true);//使其可以获得焦点，很关键。。

         /*容器分割布局*/
        showday.setLayout(new GridLayout(7,7,0,0));

        /*设置按钮大小*/
        /* 因为JButen是属于小器件类型的，所以一般的setSize不能对其惊醒大小的设置，所以一般我们用
         button.setPreferredSize(new Dimension(30,30));无fuck可说*/
        Dimension tmp=new Dimension(120,80);
        upmonth.setPreferredSize(tmp);
        dowwnmonth.setPreferredSize(tmp);
        downyear.setPreferredSize(tmp);
        upyear.setPreferredSize(tmp);
        /*美化一下按钮的字体*/
        upmonth.setFont(new Font("Arial", Font.PLAIN, 18));
        dowwnmonth.setFont(new Font("Arial", Font.PLAIN, 18));
        downyear.setFont(new Font("Arial", Font.PLAIN, 18));
        upyear.setFont(new Font("Arial", Font.PLAIN, 18));

        /*按钮布局*/
        button.setLayout(new GridLayout(1,4,0,0));
        /*年和月的布局*/
        top.setLayout(new GridLayout(1,1,0,0));
        yearandmonth=new FontComponent("");
        top.add(yearandmonth);
        top.setBorder(new LineBorder(new Color(0x09F709),5,true));
        top.setBackground(new Color(0x3AF9F9));

        /*容器归位*/
        mainFrame.add(button,BorderLayout.SOUTH);
        mainFrame.add(top,BorderLayout.NORTH);
        mainFrame.add(showday);
        /*设置菜单条*/
        mainFrame.setJMenuBar(tools);


        /*主框架的一点设置~~~~~*/
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setTitle("PIM powered by mayuan 14130110069");

        for (int i=0;i<49;i++)
        {
            display[i]=new FontComponent("");
            showday.add(display[i]);
            display[i].addMouseListener(new thing());//为每个日历单元格添加消息框事件
        }
        mainFrame.pack();
        mainFrame.setVisible(true);
    }

    public static void main(String[] args)
    {/**
     *@author 马源 1977786930@qq.com
     *@date 2017 3 5 20:30
     *@param
     *@return
     */
        cal gui=new cal();
        if (args.length==2)
        {
            cal.year=Integer.parseInt(args[1]);
            cal.month=Integer.parseInt(args[0]);
        }
        else
        {
            cal.year=2017;
            cal.month=5;
        }
        gui.engine();
    }

    /*三个事件监听器类*/
    class myaction implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            try
            {
                if (e.getSource()==upmonth)
                {
                    if (month+1>12)
                    {
                        year++;
                        month=1;
                    }
                    else
                        month++;
                    System.out.println("按下了upmonth");
                }
                else if (e.getSource()==dowwnmonth)
                {
                    if (month==1)
                    {
                        year--;
                        month=12;
                    }
                    else
                        month--;
                    System.out.println("按下了downmonth");
                }
                else if (e.getSource()==downyear)
                {
                    year--;
                    System.out.println("按下了downyear");
                }
                else if (e.getSource()==upyear)
                {
                    year++;
                    System.out.println("按下了upyear");
                }
                else
                {
                    throw new Exception("未知操作");
                }
                engine();
                showday.repaint();
                top.repaint();
                //mainFrame.repaint();

            }
            catch (Exception a)
            {
                System.out.println(a.getMessage());
            }

        }
    }

    class keyaction extends KeyAdapter
    {
        @Override
        public void keyPressed(KeyEvent e)
        {
            try
            {
                if (e.getKeyCode()==KeyEvent.VK_DOWN)
                {
                    if (month+1>12)
                    {
                        year++;
                        month=1;
                    }
                    else
                        month++;
                    System.out.println("下个月");
                }
                else if (e.getKeyCode()==KeyEvent.VK_UP)
                {
                    if (month==1)
                    {
                        year--;
                        month=12;
                    }
                    else
                        month--;
                    System.out.println("上个月");
                }
                else if (e.getKeyCode()==KeyEvent.VK_LEFT)
                {
                    year--;
                    System.out.println("前一年");
                }
                else if (e.getKeyCode()==KeyEvent.VK_RIGHT)
                {
                    year++;
                    System.out.println("后一年");
                }
                else
                {
                    throw new Exception("未知操作");
                }
                engine();
                showday.repaint();
                top.repaint();
                //mainFrame.repaint();
            }
            catch (Exception a)
            {
                System.out.println(a.getMessage());
            }
        }
    }
    class thing extends MouseAdapter
    {
        @Override
        public void mouseClicked(MouseEvent e)
        {
            FontComponent component=(FontComponent)e.getSource();
            if (e.getButton()==e.BUTTON1&&component.check())
            {
                String tmp="您今天要做的是:\n"+component.getthing().toString();
                JOptionPane.showMessageDialog(mainFrame,tmp);
                System.out.println(e.getX()+"   "+e.getY());
            }
        }
    }
}

class SizedFrame extends JFrame
{
    public SizedFrame()
    {
        Toolkit kit=Toolkit.getDefaultToolkit();
        Dimension screensize=kit.getScreenSize();
//        int height=screensize.height;
//        int width=screensize.width;

        /*设置窗口的位置和大小*/
        setSize(400,500);
        setLocationByPlatform(true);
    }
}

class FontComponent extends JComponent
{
    private static final int DEFAULT_WDITH=170;
    private static final int DEFAULT_HEiGHT=100;

    private static final Font f=new Font("Serif",Font.BOLD,36);//定义字体属性
    private boolean mark=false;//用于标记当前日期

    private boolean hastodo=false;
    private PIMCollection buf;

    private String message="";
    public FontComponent(String message)
    {
        this.message=message;
    }
    @Override
    public void paintComponent(Graphics g)
    {
        Graphics2D g2=(Graphics2D)g;
        g2.setFont(f);

        /*居中显示*/
        FontRenderContext context=g2.getFontRenderContext();
        Rectangle2D bounds=f.getStringBounds(message,context);

        double x=(getWidth()-bounds.getWidth())/2;
        double y=(getHeight()-bounds.getHeight())/2;

        double ascent =-bounds.getY();
        double baseY=y+ascent;

        g2.drawString(message,(int)x,(int)baseY);

        if (mark)
        {
            this.setBorder();
            mark=false;
        }
    }
    @Override
    public Dimension getPreferredSize()
    {
        return new Dimension(DEFAULT_WDITH,DEFAULT_HEiGHT);
    }
    public void setmessage(String message)
    {
        this.message=message;
    }
    public void setmessage(String message,boolean flag1)
    {
        if (flag1)
            this.mark=true;
        this.message=message;

    }
    public void havething(boolean flag,PIMCollection buf)
    {
        this.hastodo=flag;
        this.buf=buf;
    }
    public boolean check()
    {
        return this.hastodo;
    }
    public PIMCollection getthing()
    {//得到事件的集合
        return this.buf;
    }
    public void setBorder()
    {
        super.setBorder(new LineBorder(Color.red,5,true));
    }
    public void mark()
    {
        super.setBorder(new SoftBevelBorder(BevelBorder.LOWERED,Color.red,Color.blue));
    }
    public void clear()
    {
        super.setBorder(new LineBorder(Color.WHITE));
    }
}
