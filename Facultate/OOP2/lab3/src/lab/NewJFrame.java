package lab;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JColorChooser;

public class NewJFrame extends javax.swing.JFrame {
    
static Graphics g;
private Color selectedColor = Color.black;
Figura figura;

    public NewJFrame() {
        initComponents();
        g = jPanel1.getGraphics();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        buttonColorChooser = new javax.swing.JButton();
        toggleButtonDreptunghi = new javax.swing.JToggleButton();
        toggleButtonCerc = new javax.swing.JToggleButton();
        PickedColor = new javax.swing.JPanel();
        toggleButtonLinieCurba = new javax.swing.JToggleButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));
        jPanel1.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                jPanel1MouseDragged(evt);
            }
        });
        jPanel1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                jPanel1MousePressed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 457, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        buttonColorChooser.setText("Culoare");
        buttonColorChooser.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonColorChooserActionPerformed(evt);
            }
        });

        buttonGroup1.add(toggleButtonDreptunghi);
        toggleButtonDreptunghi.setText("Dreptunghi");

        buttonGroup1.add(toggleButtonCerc);
        toggleButtonCerc.setText("Cerc");

        PickedColor.setBackground(getBackground());
        PickedColor.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        javax.swing.GroupLayout PickedColorLayout = new javax.swing.GroupLayout(PickedColor);
        PickedColor.setLayout(PickedColorLayout);
        PickedColorLayout.setHorizontalGroup(
            PickedColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        PickedColorLayout.setVerticalGroup(
            PickedColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 23, Short.MAX_VALUE)
        );

        buttonGroup1.add(toggleButtonLinieCurba);
        toggleButtonLinieCurba.setText("Linie curba");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(toggleButtonCerc, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(buttonColorChooser)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(PickedColor, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(toggleButtonDreptunghi, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(toggleButtonLinieCurba, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(0, 11, Short.MAX_VALUE)))
                        .addContainerGap())))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(toggleButtonCerc)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(toggleButtonDreptunghi)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(toggleButtonLinieCurba)
                .addGap(11, 11, 11)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(buttonColorChooser)
                    .addComponent(PickedColor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(257, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    public boolean isCercSelected() {
        return toggleButtonCerc.isSelected();
    }
    
    public boolean isDreptunghiSelected() {
        return toggleButtonDreptunghi.isSelected();
    }
    
    public boolean isLinieCurbaSelected() {
        return toggleButtonLinieCurba.isSelected();
    }
    
    public void openColorChooser() {
        Color newColor = JColorChooser.showDialog(this, "Choose a Color", PickedColor.getBackground());
        if (selectedColor != null) {
            selectedColor = newColor;
            PickedColor.setBackground(selectedColor);
        }
        
    }
    
    private void jPanel1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jPanel1MousePressed
        // TODO add your handling code here:
        int x = evt.getX();
        int y = evt.getY();
        if(isCercSelected()) {
            figura = new Cerc(x, y, 50, selectedColor);
        } else if(isDreptunghiSelected()) {
            figura = new Dreptunghi(x, y, 20, 5, selectedColor);
        } else if(isLinieCurbaSelected()) {
            figura = new Linie(x, y, x, y, selectedColor);
        }
    }//GEN-LAST:event_jPanel1MousePressed

    private void jPanel1MouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jPanel1MouseDragged
        // TODO add your handling code here:
        int x = evt.getX();
        int y = evt.getY();
        figura.redimensioneaza(x, y);
    }//GEN-LAST:event_jPanel1MouseDragged

    private void buttonColorChooserActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonColorChooserActionPerformed
        // TODO add your handling code here:
        openColorChooser();
    }//GEN-LAST:event_buttonColorChooserActionPerformed
    

    public static void main(String args[]) {
        
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NewJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel PickedColor;
    private javax.swing.JButton buttonColorChooser;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JToggleButton toggleButtonCerc;
    private javax.swing.JToggleButton toggleButtonDreptunghi;
    private javax.swing.JToggleButton toggleButtonLinieCurba;
    // End of variables declaration//GEN-END:variables
}
