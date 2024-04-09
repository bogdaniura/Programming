S = input('Introdu suma de bani disponibilă (S): ');
c = input('Introdu prețul ciocolatei (c): ');
n = input('Introdu prețul napolitanei (n): ');

if S >= c && S >= n
    disp('CN');
elseif S >= c
    disp('C');
elseif S >= n
    disp('N');
else
    disp('nimic');
end
