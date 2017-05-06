package PIM_pro;

/**
 *
 * @author 马源 14130110069 email:1977786930@qq.com on 2017/4/23.
 */



import java.awt.*;
import java.awt.event.*;


import javax.swing.*;



public class editFrame
{
    public editFrame(PIMFileEngine core)
    {
        this.core=core;
        initComponents();
    }

    private void button9ActionPerformed(ActionEvent e)
    {
        if (Authority.getSelectedIndex()==0)
            this.ispublic=true;
        else
            this.ispublic=false;
        if (radioButton2.isSelected())
        {
            String[] time=textField3.getText().split("-");
            Date_ date=new Date_(Integer.parseInt(time[0]),Integer.parseInt(time[1]),Integer.parseInt(time[2]));
            PIMTodo tmp=new PIMTodo(textField1.getText(),date,textField2.getText(),current_account,this.ispublic);
            this.core.add(tmp);

//            System.out.println(textField1.getText());
//            System.out.println(date);
//            System.out.println(textField2.getText());
//            System.out.println(this.ispublic);
        }
        else if (radioButton3.isSelected())
        {
            String[] time=textField3.getText().split("-");
            Date_ date=new Date_(Integer.parseInt(time[0]),Integer.parseInt(time[1]),Integer.parseInt(time[2]));
            PIMAppointment tmp=new PIMAppointment(textField1.getText(),date,textField2.getText(),current_account,this.ispublic);
            this.core.add(tmp);
        }
        else if (radioButton4.isSelected())
        {
            String[] name=textField5.getText().split("-");
            PIMContact tmp=new PIMContact(textField1.getText(),name[0],name[1],textField4.getText(),current_account,this.ispublic);
            this.core.add(tmp);
        }
        else if (radioButton5.isSelected())
        {
            PIMNote tmp=new PIMNote(textField1.getText(),textField2.getText(),current_account,this.ispublic);
            this.core.add(tmp);
        }
        else
            System.out.println("未命中");
        this.core.save();
        this.mainFrame.dispose();
    }

    private void button10ActionPerformed(ActionEvent e) {
        mainFrame.dispose();
    }


    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        mainFrame = new JFrame();
        panel1 = new JPanel();
        button9 = new JButton();
        button10 = new JButton();
        panel5 = new JPanel();
        panel10 = new JPanel();
        radioButton2 = new JRadioButton();
        radioButton3 = new JRadioButton();
        radioButton4 = new JRadioButton();
        radioButton5 = new JRadioButton();
        panel9 = new JPanel();
        panel6 = new JPanel();
        label4 = new JLabel();
        textField1 = new JTextField();
        panel7 = new JPanel();
        label5 = new JLabel();
        textField2 = new JTextField();
        panel8 = new JPanel();
        label6 = new JLabel();
        textField3 = new JTextField();
        panel12 = new JPanel();
        label8 = new JLabel();
        textField5 = new JTextField();
        panel11 = new JPanel();
        label7 = new JLabel();
        textField4 = new JTextField();
        panel13 = new JPanel();
        Authority = new JComboBox();

        buttonGroup=new ButtonGroup();

        current_account=core.current_account();//当前账户

        //============= 改变LAF ====================

        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            SwingUtilities.updateComponentTreeUI(mainFrame);
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }




        //======== mainFrame ========
        {
            Container mainFrameContentPane = mainFrame.getContentPane();
            mainFrameContentPane.setLayout(new BorderLayout());

            //======== panel1 ========
            {
                panel1.setLayout(new FlowLayout());

                //---- button9 ----
                button9.setText("\u786e\u5b9a");
                button9.addActionListener(e -> button9ActionPerformed(e));
                panel1.add(button9);

                //---- button10 ----
                button10.setText("\u53d6\u6d88");
                button10.addActionListener(e -> button10ActionPerformed(e));
                panel1.add(button10);
            }
            mainFrameContentPane.add(panel1, BorderLayout.SOUTH);

            //======== panel5 ========
            {
                panel5.setLayout(new GridLayout(8, 0));

                //======== panel10 ========
                {
                    panel10.setLayout(new FlowLayout());

                    //---- radioButton2 ----
                    radioButton2.setText("todo");
                    radioButton2.setFont(new Font("Arial", Font.PLAIN, 18));
                    buttonGroup.add(radioButton2);
                    panel10.add(radioButton2);

                    //---- radioButton3 ----
                    radioButton3.setText("appintment");
                    radioButton3.setFont(new Font("Arial", Font.PLAIN, 18));
                    buttonGroup.add(radioButton3);
                    panel10.add(radioButton3);

                    //---- radioButton4 ----
                    radioButton4.setText("contact");
                    radioButton4.setFont(new Font("Arial", Font.PLAIN, 18));
                    buttonGroup.add(radioButton4);
                    panel10.add(radioButton4);

                    //---- radioButton5 ----
                    radioButton5.setText("note");
                    radioButton5.setFont(new Font("Arial", Font.PLAIN, 18));
                    buttonGroup.add(radioButton5);
                    panel10.add(radioButton5);


                }
                panel5.add(panel10);

                //======== panel9 ========
                {
                    panel9.setLayout(new FlowLayout());

                    //======== panel6 ========
                    {
                        panel6.setLayout(new FlowLayout(FlowLayout.LEFT));

                        //---- label4 ----
                        label4.setText("priority:");
                        label4.setFont(new Font("Arial", Font.PLAIN, 18));
                        panel6.add(label4);

                        //---- textField1 ----
                        textField1.setColumns(40);
                        textField1.setFont(new Font("Consolas", Font.PLAIN, 20));
                        textField1.setText("relax|normal|urgent");
                        panel6.add(textField1);
                    }
                    panel9.add(panel6);
                }
                panel5.add(panel9);

                //======== panel7 ========
                {
                    panel7.setLayout(new FlowLayout());

                    //---- label5 ----
                    label5.setText("content:");
                    label5.setFont(new Font("Arial", Font.PLAIN, 18));
                    panel7.add(label5);

                    //---- textField2 ----
                    textField2.setColumns(40);
                    textField2.setFont(new Font("Consolas", Font.PLAIN, 20));
                    textField2.setText("fill with todo|appintment|note");
                    panel7.add(textField2);
                }
                panel5.add(panel7);

                //======== panel8 ========
                {
                    panel8.setLayout(new FlowLayout());

                    //---- label6 ----
                    label6.setText("time:");
                    label6.setFont(new Font("Arial", Font.PLAIN, 18));
                    panel8.add(label6);

                    //---- textField3 ----
                    textField3.setColumns(42);
                    textField3.setFont(new Font("Consolas", Font.PLAIN, 20));
                    textField3.setText("eg:2017-4-23");
                    panel8.add(textField3);
                }
                panel5.add(panel8);

                //======== panel12 ========
                {
                    panel12.setLayout(new FlowLayout());

                    //---- label8 ----
                    label8.setText("name:");
                    label8.setFont(new Font("Arial", Font.PLAIN, 18));
                    panel12.add(label8);

                    //---- textField5 ----
                    textField5.setColumns(40);
                    textField5.setText("eg:ma-yuan");
                    textField5.setFont(new Font("Consolas", Font.PLAIN, 20));
                    panel12.add(textField5);
                }
                panel5.add(panel12);

                //======== panel11 ========
                {
                    panel11.setLayout(new FlowLayout());

                    //---- label7 ----
                    label7.setText("email:");
                    label7.setFont(new Font("Arial", Font.PLAIN, 18));
                    panel11.add(label7);

                    //---- textField4 ----
                    textField4.setColumns(40);
                    textField4.setText("eg:1977786960@qq.com");
                    textField4.setFont(new Font("Consolas", Font.PLAIN, 20));
                    panel11.add(textField4);
                }
                panel5.add(panel11);

                //======== panel13 ========
                {
                    panel13.setLayout(new FlowLayout());

                    //---- Authority ----
                    Authority.setFont(new Font("Arial", Font.PLAIN, 18));
                    Authority.addItem("public");
                    Authority.addItem("private");
                    Authority.setMaximumRowCount(2);
                    panel13.add(Authority);
                }
                panel5.add(panel13);


            }
            mainFrameContentPane.add(panel5, BorderLayout.NORTH);
            mainFrame.pack();
            mainFrame.setLocationRelativeTo(mainFrame.getOwner());
            mainFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            mainFrame.setVisible(true);
        }
        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JFrame mainFrame;
    private JPanel panel1;
    private JButton button9;
    private JButton button10;
    private JPanel panel5;
    private JPanel panel10;
    private JRadioButton radioButton2;
    private JRadioButton radioButton3;
    private JRadioButton radioButton4;
    private JRadioButton radioButton5;
    private JPanel panel9;
    private JPanel panel6;
    private JLabel label4;
    private JTextField textField1;
    private JPanel panel7;
    private JLabel label5;
    private JTextField textField2;
    private JPanel panel8;
    private JLabel label6;
    private JTextField textField3;
    private JPanel panel12;
    private JLabel label8;
    private JTextField textField5;
    private JPanel panel11;
    private JLabel label7;
    private JTextField textField4;
    private JPanel panel13;
    private JComboBox Authority;
    // JFormDesigner - End of variables declaration  //GEN-END:variables

    private ButtonGroup buttonGroup;//单选

    private PIMFileEngine core;
    /*当前账户*/
    private static String current_account;


    private boolean ispublic;


    public static void main(String[] args)
    {
        PIMFileEngine core=new PIMFileEngine("E:\\intellij\\Personal Information Manager\\data");
        editFrame ui=new editFrame(core);
//        core.save();
//        core.load();
//        System.out.println(core.getAll());
    }
}
