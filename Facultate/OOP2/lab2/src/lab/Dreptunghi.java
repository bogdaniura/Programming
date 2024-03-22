
package lab;

import java.awt.Color;
import static lab.NewJFrame.g;


public class Dreptunghi {
    int x, y, h, w;
    Color c;

    public Dreptunghi(int x, int y, int w, int h, Color c) {
        this.x = x;
        this.y = y;
        this.h = h;
        this.w = w;
        this.c = c;
    }
    
    void deseneaza () {
        g.drawRect(x, y, w, h);
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
        w = xm - x;
        h = ym - y;
        afiseaza();
    }
}
