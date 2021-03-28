import java.awt.*;
import java.awt.image.*;
import javax.swing.*;
import java.util.*;

public class Board
{
    private BufferedImage board;
    private java.util.List<Ships> ships;

    public Board()
    {
        initializeBoardImage();
        ships = new ArrayList<Ships>();
    }

    public void draw(Graphics g)
    {
        g.drawImage(
            board, 0, 0,
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_WIDTH,
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_HEIGHT,
            null
        );
    }

    private void initializeBoardImage()
    {
        board = new BufferedImage(
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_WIDTH,
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_HEIGHT,
            BufferedImage.TYPE_INT_ARGB
        );
        
        Graphics boardGraphics = board.getGraphics();
        boardGraphics.setColor(Color.BLACK);
        boardGraphics.drawRect(0, 0,
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_WIDTH,
            BattleshipPanel.TILE_SIZE * BattleshipPanel.BOARD_HEIGHT);

        for (int i = 0; i < BattleshipPanel.BOARD_WIDTH; i++)
        {
            for (int j = 0; j < BattleshipPanel.BOARD_HEIGHT; j++)
            {
                boardGraphics.drawImage(
                    Textures.Ocean, 
                    i * BattleshipPanel.TILE_SIZE,
                    j * BattleshipPanel.TILE_SIZE,
                    null);
            }
        }
    }
}
