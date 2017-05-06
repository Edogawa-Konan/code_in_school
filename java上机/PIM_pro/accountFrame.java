/*
 * Created by JFormDesigner on Wed May 03 19:16:23 CST 2017
 */

package PIM_pro;

import java.awt.*;
import java.awt.event.*;

import java.util.*;
import java.util.List;
import javax.swing.*;
import javax.swing.border.*;



/**
 * @author prime
 */
public class accountFrame extends JFrame {
    public accountFrame(List<String> account) {
        this.account=account;
//        load();
        initComponents();
    }
//    private void load()
//    {
//        try
//        {
//            Fin=new ObjectInputStream(new FileInputStream("E:\\intellij\\Personal Information Manager\\account"));
//            account=(List<String>) Fin.readObject();
//        }
//        catch (Exception ex)
//        {
//            out.println("加载失败");
//            ex.printStackTrace();
//            out.println(ex.getMessage());
//        }
//        finally
//        {
//            if (Fin!=null)
//                try
//                {
//                    Fin.close();
//                }
//                catch (IOException e)
//                {
//                    out.println(e.getMessage());
//                }
//        }
//    }
//    private void save()
//    {
//        try
//        {
//            Fout=new ObjectOutputStream(new FileOutputStream("E:\\intellij\\Personal Information Manager\\account"));
//            Fout.writeObject(account);
//        }
//        catch (IOException e)
//        {
//            out.println("保存失败");
//            out.println(e.getMessage());
//        }
//        finally
//        {
//            if (Fin!=null)
//            {
//                try
//                {
//                    Fin.close();
//                }
//                catch (IOException e)
//                {
//                    out.println(e.getMessage());
//                }
//            }
//        }
//    }


    private void okButtonActionPerformed(ActionEvent e) {
        if (radioButton1.isSelected())
        {
            String name=textField1.getText();
            if (!account.contains(name))
            {//账户列表第一个表示当前正在使用的账户
                account.add(name);
                if (account.size()>1)
                    Collections.swap(account,0,account.indexOf(name));
            }
        }
        if (radioButton2.isSelected())
        {
            int index=comboBox1.getSelectedIndex();
            Collections.swap(account,index,0);
        }
        if (radioButton3.isSelected())
        {
            int index=comboBox2.getSelectedIndex();
            account.remove(index);
        }
//        save();
        dispose();
    }



    private void cancelButtonActionPerformed(ActionEvent e) {
        dispose();
    }
    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        dialogPane = new JPanel();
        contentPanel = new JPanel();
        panel3 = new JPanel();
        radioButton1 = new JRadioButton();
        radioButton2 = new JRadioButton();
        radioButton3 = new JRadioButton();
        scrollPane1 = new JScrollPane();
        panel2 = new JPanel();
        label2 = new JLabel();
        comboBox1 = new JComboBox(account.toArray(new String[account.size()]));
        panel4 = new JPanel();
        label3 = new JLabel();
        comboBox2 = new JComboBox(account.toArray(new String[account.size()]));
        panel1 = new JPanel();
        label1 = new JLabel();
        textField1 = new JTextField();
        buttonBar = new JPanel();
        okButton = new JButton();
        cancelButton = new JButton();

        buttonGroup=new ButtonGroup();

        //======== this ========
        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());

        //======== dialogPane ========
        {
            dialogPane.setBorder(new EmptyBorder(12, 12, 12, 12));
            dialogPane.setLayout(new BorderLayout());

            //======== contentPanel ========
            {
                contentPanel.setLayout(new GridLayout(4, 0));

                //======== panel3 ========
                {
                    panel3.setLayout(new FlowLayout());

                    //---- radioButton1 ----
                    radioButton1.setText("\u6dfb\u52a0\u8d26\u6237");

                    panel3.add(radioButton1);

                    //---- radioButton2 ----
                    radioButton2.setText("\u9009\u62e9\u5df2\u6709\u8d26\u6237");
                    panel3.add(radioButton2);

                    //---- radioButton3 ----
                    radioButton3.setText("\u5220\u9664\u8d26\u6237");
                    panel3.add(radioButton3);

                    /*单选*/
                    buttonGroup.add(radioButton1);
                    buttonGroup.add(radioButton2);
                    buttonGroup.add(radioButton3);
                }
                contentPanel.add(panel3);

                //======== scrollPane1 ========
                {

                    //======== panel2 ========
                    {
                        panel2.setLayout(new FlowLayout());

                        //---- label2 ----
                        label2.setText("\u9009\u62e9\u5df2\u6709\u8d26\u6237");
                        label2.setFont(new Font("\u534e\u6587\u6977\u4f53", Font.BOLD, 18));
                        panel2.add(label2);
                        panel2.add(comboBox1);
                    }
                    scrollPane1.setViewportView(panel2);
                }
                contentPanel.add(scrollPane1);

                //======== panel4 ========
                {
                    panel4.setLayout(new FlowLayout());

                    //---- label3 ----
                    label3.setText("\u5220\u9664\u5df2\u6709\u8d26\u6237");
                    label3.setFont(new Font("\u534e\u6587\u6977\u4f53", Font.BOLD, 18));
                    panel4.add(label3);
                    panel4.add(comboBox2);
                }
                contentPanel.add(panel4);

                //======== panel1 ========
                {
                    panel1.setLayout(new FlowLayout());

                    //---- label1 ----
                    label1.setText("\u65b0\u6dfb\u52a0\u8d26\u6237");
                    label1.setFont(new Font("\u534e\u6587\u6977\u4f53", Font.BOLD, 18));
                    panel1.add(label1);

                    //---- textField1 ----
                    textField1.setColumns(20);
                    textField1.setFont(new Font("\u5b8b\u4f53", Font.PLAIN, 18));
                    textField1.setText("\u8bf7\u5728\u6b64\u952e\u5165\u65b0\u7684\u8d26\u6237\u540d");
                    panel1.add(textField1);
                }
                contentPanel.add(panel1);
            }
            dialogPane.add(contentPanel, BorderLayout.CENTER);

            //======== buttonBar ========
            {
                buttonBar.setBorder(new EmptyBorder(12, 0, 0, 0));
                buttonBar.setLayout(new GridBagLayout());
                ((GridBagLayout)buttonBar.getLayout()).columnWidths = new int[] {0, 85, 80};
                ((GridBagLayout)buttonBar.getLayout()).columnWeights = new double[] {1.0, 0.0, 0.0};

                //---- okButton ----
                okButton.setText("OK");
                okButton.addActionListener(e -> okButtonActionPerformed(e));
                buttonBar.add(okButton, new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0,
                    GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                    new Insets(0, 0, 0, 5), 0, 0));

                //---- cancelButton ----
                cancelButton.setText("Cancel");
                cancelButton.addActionListener(e -> cancelButtonActionPerformed(e));
                buttonBar.add(cancelButton, new GridBagConstraints(2, 0, 1, 1, 0.0, 0.0,
                    GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                    new Insets(0, 0, 0, 0), 0, 0));
            }
            dialogPane.add(buttonBar, BorderLayout.SOUTH);
        }
        contentPane.add(dialogPane, BorderLayout.CENTER);
        pack();
        setVisible(true);
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JPanel dialogPane;
    private JPanel contentPanel;
    private JPanel panel3;
    private JRadioButton radioButton1;
    private JRadioButton radioButton2;
    private JRadioButton radioButton3;
    private JScrollPane scrollPane1;
    private JPanel panel2;
    private JLabel label2;
    private JComboBox comboBox1;
    private JPanel panel4;
    private JLabel label3;
    private JComboBox comboBox2;
    private JPanel panel1;
    private JLabel label1;
    private JTextField textField1;
    private JPanel buttonBar;
    private JButton okButton;
    private JButton cancelButton;
    // JFormDesigner - End of variables declaration  //GEN-END:variables

    private ButtonGroup buttonGroup;
    private java.util.List<String> account;
}
