import javax.swing.JFrame;

public class BattleshipFrame {

    public static void main(String[] args) {
        JFrame frame = new JFrame("battleship");
        frame.setSize(1000, 1000);
        frame.setLocation(0, 0);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setContentPane(new BattleshipPanel());
        frame.setVisible(true);
    }
    
}


