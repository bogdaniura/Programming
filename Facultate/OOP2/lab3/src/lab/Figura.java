package lab;

import java.awt.Color;
import static lab.NewJFrame.g;

public abstract class Figura {
    int x,y;
    Color c;

    public Figura(int x, int y, Color c) {
        this.x = x;
        this.y = y;
        this.c = c;
    }
    
    void afiseaza() {
        g.setColor(c);
        deseneaza();
    }
    
    void sterge() {
        g.setColor(Color.white);
        deseneaza();
    }
    
    abstract void deseneaza();
    abstract void redimensioneaza(int xm, int ym);
}
