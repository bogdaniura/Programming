package lab;

import java.awt.Color;
import java.util.ArrayList;
import static lab.NewJFrame.g;

public class Linie extends Figura{
    
    ArrayList<Punct> puncte = new ArrayList();
    
    public Linie(int x, int y, Color c) {
        super(x, y, c);
        puncte.add(new Punct(x, y));
    }

    @Override
    void deseneaza() {
        g.setColor(c);
        for (int i = 0; i < puncte.size() - 1; i++) {
            Punct p1 = puncte.get(i);
            Punct p2 = puncte.get(i + 1);
            g.drawLine(p1.x, p1.y, p2.x, p2.y);
        }
    }
    
    @Override
    void redimensioneaza(int xm, int ym) {
        Punct p = puncte.getLast();
        g.setColor(c);
        g.drawLine(p.x, p.y, xm, ym);
        puncte.add(new Punct(xm, ym));
    }
    

}
