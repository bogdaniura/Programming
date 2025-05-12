#!/bin/bash

# Script pentru compilarea prezentării LaTeX Beamer

echo "Compilare prezentare Scheduler..."

# Compilare LaTeX (rulează pdflatex de două ori pentru a rezolva referințele)
pdflatex -interaction=nonstopmode prezentare_scheduler.tex
pdflatex -interaction=nonstopmode prezentare_scheduler.tex

# Verifică dacă compilarea a reușit
if [ -f "prezentare_scheduler.pdf" ]; then
    echo "Prezentarea a fost compilată cu succes: prezentare_scheduler.pdf"
    echo "Poți deschide fișierul PDF cu un vizualizator de PDF sau îl poți prezenta direct."
else
    echo "Eroare: Compilarea nu a reușit."
    echo "Verifică fișierul log pentru detalii: prezentare_scheduler.log"
fi

# Curăță fișierele temporare
echo "Curățare fișiere temporare..."
rm -f prezentare_scheduler.aux prezentare_scheduler.log prezentare_scheduler.nav prezentare_scheduler.out prezentare_scheduler.snm prezentare_scheduler.toc prezentare_scheduler.vrb

echo "Proces finalizat." 