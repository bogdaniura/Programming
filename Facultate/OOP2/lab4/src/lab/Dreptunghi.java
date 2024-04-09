
package lab;

import java.awt.Color;
import static lab.NewJFrame.g;


public class Dreptunghi extends Figura{
    int h, w;

    public Dreptunghi(int x, int y, int w, int h, Color c) {
        super(x,y,c);
        this.h = h;
        this.w = w;
    }
    
    void deseneaza () {
        g.drawRect(x-w/2, y-h/2, w, h);
    }
    
    void redimensioneaza(int xm, int ym) {
        sterge();
        w = 2 * Math.abs(xm - x);
        h = 2 * Math.abs(ym - y);
        afiseaza();
    }
}
