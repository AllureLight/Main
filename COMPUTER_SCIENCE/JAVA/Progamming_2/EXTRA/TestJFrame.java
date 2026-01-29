package COMPUTER_SCIENCE.JAVA.Progamming_2.EXTRA;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;

public class TestJFrame {
    //final indica o valor final do atributo
    public static final int COD = 20;

    public static void main(String[] args){

        //Scanner sc = new Scanner(System.in);
        //String titulo = sc.nextLine();

        JFrame frame = new JFrame();

        //frame.setTitle(titulo);
        frame.setTitle("Test");
        frame.setSize(600, 600);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //frame.add(); 
        //adiciona componentes na janela

        JButton btn_Add = new JButton("Add");
        frame.add(btn_Add);

        JTextField text_camp = new JTextField("Text Field");
        frame.add(text_camp);

        System.out.println(Math.PI);
        System.out.println(COD);
    }
}
