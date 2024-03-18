package lab;

import java.awt.Color;
import static lab.NewJFrame.g;


public class Cerc {
    int x, y, r;
    Color c;

    public Cerc(int x, int y, int r, Color c) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.c = c;
    }
    
    void deseneaza () {
        g.drawOval(x - r, y - r, 2 * r, 2 * r);
        
    }
    
    void afiseaza() {
        g.setColor(c);
        deseneaza();
    }
    
    void sterge() {
        g.setColor(Color.white);
        deseneaza();
    }
    
    void redimensioneaza(int xm, int ym) {
        sterge();
        r = (int)Math.sqrt((x - xm) * (x - xm) + (y - ym) * (y - ym));
        afiseaza();
    }
}
