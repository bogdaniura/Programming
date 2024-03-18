% Citirea numărului
numar = input('Introdu numărul: ');

% Inițializarea numărătorului de cifre impare
cifre_impare = 0;

% Determinarea numărului de cifre impare
while numar > 0
    cifra = mod(numar, 10);
    if mod(cifra, 2) ~= 0
        cifre_impare = cifre_impare + 1;
    end
    numar = floor(numar / 10);
end

% Afișarea rezultatului
fprintf('Numărul de cifre impare este: %d\n', cifre_impare);
