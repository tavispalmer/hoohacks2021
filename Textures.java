import java.awt.image.*;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class Textures
{
    public static BufferedImage Ocean = null;
    public static BufferedImage Red = null;
    public static BufferedImage White = null;
    public static BufferedImage TwoShip = null;
    public static BufferedImage ThreeShip = null;
    public static BufferedImage FourShip = null;
    public static BufferedImage FiveShip = null;

    static
    {
        try
        {
            Ocean = ImageIO.read(new File("images/Drawing-4.sketchpad.png"));
            Red = ImageIO.read(new File("images/Drawing-4.sketchpad_1.png"));
            White = ImageIO.read(new File("images/Drawing-4.sketchpad_2.png"));
            TwoShip = ImageIO.read(new File("images/2.png"));
            ThreeShip = ImageIO.read(new File("images/3.png"));
            FourShip = ImageIO.read(new File("images/4.png"));
            FiveShip = ImageIO.read(new File("images/5.png"));
        }
        catch (IOException e)
        {
            System.err.println("Warning! Textures not found");
        }
    }
}
