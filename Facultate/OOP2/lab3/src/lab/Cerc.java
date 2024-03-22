package lab;

import java.awt.Color;
import static lab.NewJFrame.g;


public class Cerc extends Figura{
    int r;

    public Cerc(int x, int y, int r, Color c) {
        super(x,y,c);
        this.r = r;
    }
    
    void deseneaza () {
        g.drawOval(x - r, y - r, 2 * r, 2 * r);
        
    }
    
    void redimensioneaza(int xm, int ym) {
        sterge();
        r = (int)Math.sqrt((x - xm) * (x - xm) + (y - ym) * (y - ym));
        afiseaza();
    }
}
