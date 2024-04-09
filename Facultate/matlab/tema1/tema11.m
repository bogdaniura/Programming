numar = input('Introdu numărul: ');

cifre_impare = 0;

while numar > 0
    cifra = mod(numar, 10);
    if mod(cifra, 2) ~= 0
        cifre_impare = cifre_impare + 1;
    end
    numar = floor(numar / 10);
end

fprintf('Numărul de cifre impare este: %d\n', cifre_impare);
