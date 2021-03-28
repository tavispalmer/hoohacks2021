import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;

public class BattleshipPanel extends JPanel
{
    private static final int TILE_SIZE = 160;
    private static final int WINDOW_WIDTH = TILE_SIZE * 10;
    private static final int WINDOW_HEIGHT = TILE_SIZE * 10;
    private BufferedImage image;
    private Input input;

    public BattleshipPanel()
    {
        getPanelGraphics();

        input = new Input();
        Thread mainThread = new Thread()
        {
            public void run()
            {
                while (true)
                {
                    input.update();
                    mainLoop();
                }
            }
        };
        mainThread.start();
        addKeyListener(input.key);
        setFocusable(true);
    }

    public void mainLoop()
    {
        Graphics graphics = getPanelGraphics();

        // code...

        repaint();
    }

    public void paintComponent(Graphics g)
    {
        g.drawImage(image, 0, 0, null);
    }

    private Graphics getPanelGraphics()
    {
        if (null == image)
        {
            image = new BufferedImage(WINDOW_WIDTH, WINDOW_HEIGHT, BufferedImage.TYPE_INT_RGB);
        }
        
        Graphics g = image.getGraphics();
        g.setColor(Color.BLACK);

        g.fillRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        return g;
    }
}
