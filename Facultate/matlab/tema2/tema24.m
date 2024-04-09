n = input('Introduceți dimensiunea pătratului: ');
x = input('Introduceți coordonata x: ');
y = input('Introduceți coordonata y: ');
val = input('Introduceți valoarea căutată: ');

[V, i, j] = valoare_si_pozitie(n, x, y, val);
fprintf('Valoarea V de la poziția (%d, %d) este: %d\n', x, y, V);
fprintf('Valoarea %d se află la poziția (%d, %d) în pătratul %d x %d.\n', val, i, j, n, n);

function [V, i, j] = valoare_si_pozitie(n, x, y, val)
    if x < 1 || x > n || y < 1 || y > n
        error('Poziție invalidă');
    end
    
    V = (x - 1) * n + y;
    
    i = ceil(val / n);
    j = mod(val - 1, n) + 1;
end

