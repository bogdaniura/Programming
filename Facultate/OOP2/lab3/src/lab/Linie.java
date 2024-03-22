package lab;

import java.awt.Color;
import static lab.NewJFrame.g;

public class Linie extends Figura{
    int x2, y2;
    
    public Linie(int x, int y, int x2, int y2, Color c) {
        super(x, y, c);
        this.x2 = x2;
        this.y2 = y2;
    }

    void deseneaza() {
        g.drawLine(x, y, x2, y2);
    }

    void redimensioneaza(int xm, int ym) {
        x = x2;
        y = y2;
        x2 = xm;
        y2 = ym;
        afiseaza();
    }
}
