% Exemplu de utilizare:
k = input('Introduceți poziția dorită: ');
cifra = cifraLaPozitie(k);
fprintf('Cifra de la poziția %d este: %d\n', k, cifra);

function cifra = cifraLaPozitie(k)
    % Determinăm lungimea maximă a numerelor din intervalul curent
    lungimeMaxima = 2;
    while k > lungimeMaxima * (10^(lungimeMaxima - 1))
        k = k - lungimeMaxima * (10^(lungimeMaxima - 1));
        lungimeMaxima = lungimeMaxima + 1;
    end
    
    % Determinăm numărul și poziția cifrei în intervalul curent
    numar = ceil(k / lungimeMaxima) + 9 * (lungimeMaxima - 1);
    pozitieInNumar = mod(k - 1, lungimeMaxima) + 1;
    
    % Extragerea cifrei la poziția dorită
    cifra = str2double(char(num2str(numar)(pozitieInNumar)));
end

