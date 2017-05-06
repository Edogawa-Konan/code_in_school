/*
 * Created by JFormDesigner on Sat May 06 15:01:04 CST 2017
 */

package PIM_pro;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

/**
 * @author prime
 */
public class DelShow extends JFrame
{
    public DelShow(PIMFileEngine data)
    {
        //接管数据控制权
        this.core=data;
        notes=core.getNotes(core.current_account()).toArray(new PIMNote[core.getNotes(core.current_account()).size()]);
        contacts=core.getContacts(core.current_account()).toArray(new PIMContact[core.getContacts(core.current_account()).size()]);
        System.out.println("喵喵喵？");
        initComponents();
    }


    private void okButtonActionPerformed(ActionEvent e) {
        if (radioButton2.isSelected())
        {//删除note
            int index=comboBox1.getSelectedIndex();//要删除的note的索引
            core.del(notes[index]);
        }
        if (radioButton3.isSelected())
        {
            core.del(contacts[comboBox2.getSelectedIndex()]);
        }
        if (radioButton4.isSelected())
        {
            String day=textField1.getText();
            String[] tmp=day.split("-");
            core.delItemsForDate(new Date_(Integer.parseInt(tmp[0]),Integer.parseInt(tmp[1]),Integer.parseInt(tmp[2])),core.current_account());
            System.out.println("删除日期"+day);
        }
        core.save();
        dispose();
    }
    private void cancelButtonActionPerformed(ActionEvent e) {
        dispose();
    }

    private void initComponents()
    {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        dialogPane = new JPanel();
        buttonBar = new JPanel();
        okButton = new JButton();
        cancelButton = new JButton();
        panel1 = new JPanel();
        panel2 = new JPanel();
        radioButton1 = new JRadioButton();
        radioButton2 = new JRadioButton();
        radioButton3 = new JRadioButton();
        radioButton4 = new JRadioButton();
        comboBox1 = new JComboBox(notes);
        comboBox2 = new JComboBox(contacts);
        panel3 = new JPanel();
        label2 = new JLabel();
        textField1 = new JTextField();
        buttonGroup=new ButtonGroup();

        //======== this ========
        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());

        //======== dialogPane ========
        {
            dialogPane.setBorder(new EmptyBorder(12, 12, 12, 12));
            dialogPane.setLayout(new BorderLayout());

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

            //======== panel1 ========
            {
                panel1.setLayout(new GridLayout(4, 0));

                //======== panel2 ========
                {
                    panel2.setBorder(null);
                    panel2.setLayout(new FlowLayout());

                    //---- radioButton1 ----
                    radioButton1.setText("\u67e5\u770b");
                    radioButton1.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                    panel2.add(radioButton1);

                    //---- radioButton2 ----
                    radioButton2.setText("\u5220\u9664note");
                    radioButton2.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                    panel2.add(radioButton2);

                    //---- radioButton3 ----
                    radioButton3.setText("\u5220\u9664contack");
                    radioButton3.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                    panel2.add(radioButton3);

                    //---- radioButton4 ----
                    radioButton4.setText("\u5220\u9664\u67d0\u4e00\u65e5\u671f");
                    radioButton4.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                    panel2.add(radioButton4);

                    /*单选*/
                    buttonGroup.add(radioButton1);
                    buttonGroup.add(radioButton2);
                    buttonGroup.add(radioButton3);
                    buttonGroup.add(radioButton4);
                }
                panel1.add(panel2);

                //---- comboBox1 ----
                comboBox1.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                panel1.add(comboBox1);

                //---- comboBox2 ----
                comboBox2.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                panel1.add(comboBox2);

                //======== panel3 ========
                {
                    panel3.setLayout(new FlowLayout());

                    //---- label2 ----
                    label2.setText("\u6b32\u5220\u9664\u7684\u65e5\u671f");
                    label2.setFont(new Font("\u6977\u4f53", Font.BOLD, 18));
                    panel3.add(label2);

                    //---- textField1 ----
                    textField1.setColumns(30);
                    textField1.setText("\u793a\u4f8b:2017-5-6");
                    textField1.setFont(new Font("\u5b8b\u4f53", Font.BOLD, 18));
                    panel3.add(textField1);
                }
                panel1.add(panel3);
            }
            dialogPane.add(panel1, BorderLayout.NORTH);
        }
        contentPane.add(dialogPane, BorderLayout.CENTER);
        pack();
        setVisible(true);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(getOwner());

        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    private JPanel dialogPane;
    private JPanel buttonBar;
    private JButton okButton;
    private JButton cancelButton;
    private JPanel panel1;
    private JPanel panel2;
    private JRadioButton radioButton1;
    private JRadioButton radioButton2;
    private JRadioButton radioButton3;
    private JRadioButton radioButton4;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JPanel panel3;
    private JLabel label2;
    private JTextField textField1;
    // JFormDesigner - End of variables declaration  //GEN-END:variables

    private ButtonGroup buttonGroup;
    private PIMFileEngine core;
    private PIMNote[] notes;
    private PIMContact[] contacts;
}
