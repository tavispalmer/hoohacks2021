import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;

public class BattleshipPanel extends JPanel
{
    public static final int TILE_SIZE = 160;
    public static final int BOARD_WIDTH = 10;
    public static final int BOARD_HEIGHT = 10;
    public static final int WINDOW_WIDTH = TILE_SIZE * BOARD_WIDTH;
    public static final int WINDOW_HEIGHT = TILE_SIZE * BOARD_HEIGHT;
    private BufferedImage image;
    private Input input;

    private Board board;

    public BattleshipPanel()
    {
        getPanelGraphics();

        board = new Board();

        input = new Input();
        Thread mainThread = new Thread()
        {
            public void run()
            {
                try
                {
                    SwingUtilities.invokeAndWait(
                        new Runnable()
                        {
                            public void run()
                            {
                                mainLoop();
                                try
                                {
                                    Thread.sleep(10);
                                }
                                catch (InterruptedException e)
                                {
                                    Thread.currentThread().interrupt();
                                }
                            }
                        }
                    );
                } catch (Exception e)
                {
                    e.printStackTrace();
                }
            }
        };
        mainThread.start();
        addKeyListener(input.key);
        addMouseListener(input.mouse);
        setFocusable(true);
    }

    public void mainLoop()
    {        
        Graphics graphics = getPanelGraphics();

        input.isKeyPressed(KeyEvent.VK_DOWN);
        input.isKeyPressed(KeyEvent.VK_UP);
        input.isKeyPressed(KeyEvent.VK_RIGHT);
        input.isKeyPressed(KeyEvent.VK_LEFT);
        board.draw(graphics);

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
