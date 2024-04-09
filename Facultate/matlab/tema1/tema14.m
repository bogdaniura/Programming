P = input('Introduceti cifra de pornire (P): ');
K = input('Introduceti numarul termenului cautat (K): ');

termeni_cu_9 = floor((K - 1) / 10);
termeni_fara_9 = K - termeni_cu_9;
termen = P + (termeni_cu_9 * 100) + (termeni_fara_9 - 1) * 10;

if mod(termen, 10) == 9
    termen = termen + 1;
end

fprintf('Termenul cautat este: %d\n', termen);
