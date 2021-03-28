import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;

public class BattleshipPanel extends JPanel
{

    private BufferedImage image;


    private class Key extends KeyAdapter
    {
        public void keyPressed(KeyEvent e)
        {
            // TODO
        }
        
        public void keyReleased(KeyEvent e)
        {
            // ToDO
        }
    }

    public void paintComponent(Graphics g)
    {
        g.drawImage(image, 0, 0, null);
    }


}
