import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Point;
import java.util.Arrays;

public class Input
{
    public Key key = new Key();
    public Mouse mouse = new Mouse();

    public int getX()
    {
        return mouseX;
    }

    public int getY()
    {
        return mouseY;
    }

    public Point getPoint()
    {
        return mousePoint;
    }

    public boolean isKeyPressed(int keyCode)
    {
        switch (keyCode)
        {
            case KeyEvent.VK_LEFT:
                return keyPressed[0];
            case KeyEvent.VK_UP:
                return keyPressed[1];
            case KeyEvent.VK_RIGHT:
                return keyPressed[2];
            case KeyEvent.VK_DOWN:
                return keyPressed[3];
            default:
                return false;
        }
    }

    public boolean isKeyDown(int keyCode)
    {
        switch (keyCode)
        {
            case KeyEvent.VK_LEFT:
                return keyDown[0];
            case KeyEvent.VK_UP:
                return keyDown[1];
            case KeyEvent.VK_RIGHT:
                return keyDown[2];
            case KeyEvent.VK_DOWN:
                return keyDown[3];
            default:
                return false;
        }
    }

    public void update()
    {
        Arrays.fill(keyPressed, false);
        mousePressed = false;
    }

    private class Mouse extends MouseAdapter
    {
        public void mousePressed(MouseEvent e)
        {
            mouseDown = true;
            mousePressed = true;
           
        }

        public void mouseReleased(MouseEvent e)
        {
            mouseDown = false;
            mousePressed = false;
        }

        public void mouseMoved(MouseEvent e)
        {
            mouseX = e.getX();
            mouseY = e.getY();
            mousePoint = e.getPoint();
        }
    }

    private class Key extends KeyAdapter
    {
        public void keyPressed(KeyEvent e)
        {
            if (e.getKeyCode() == KeyEvent.VK_LEFT)
            {
                keyDown[0] = true;
                keyPressed[0] = true;
            }
            else if (e.getKeyCode() == KeyEvent.VK_UP)
            {
                keyDown[1] = true;
                keyPressed[1] = true;
            }
            else if (e.getKeyCode() == KeyEvent.VK_RIGHT)
            {
                keyDown[2] = true;
                keyPressed[2] = true;
            }
            else if (e.getKeyCode() == KeyEvent.VK_DOWN)
            {
                keyDown[3] = true;
                keyPressed[3] = true;
            }
        }

        public void keyReleased(KeyEvent e)
        {
            if (e.getKeyCode() == KeyEvent.VK_LEFT)
            {
                keyDown[0] = false;
                keyPressed[0] = false;
            }
            else if (e.getKeyCode() == KeyEvent.VK_UP)
            {
                keyDown[1] = false;
                keyPressed[1] = false;
            }
            else if (e.getKeyCode() == KeyEvent.VK_RIGHT)
            {
                keyDown[2] = false;
                keyPressed[2] = false;
            }
            else if (e.getKeyCode() == KeyEvent.VK_DOWN)
            {
                keyDown[3] = false;
                keyPressed[3] = false;
            }
        }
    }

    private boolean[] keyDown = new boolean[4];
    private boolean[] keyPressed = new boolean[4];

    private boolean mouseDown;
    private boolean mousePressed;

    private int mouseX;
    private int mouseY;
    private Point mousePoint;
}
