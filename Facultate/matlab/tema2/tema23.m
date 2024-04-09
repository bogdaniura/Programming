% Exemplu de utilizare:
a = input('Introduceti primul numar: ');
b = input('Introduceti al doilea numar: ');
operatie = input('Introduceti operatia (+, -, *, /): ', 's');

rezultat = calculeazaOperatie(a, b, operatie);
fprintf('Rezultatul operatiei %d %s %d este: %.2f\n', a, operatie, b, rezultat);


function rezultat = calculeazaOperatie(a, b, operatie)
    switch operatie
        case '+'
            rezultat = a + b;
        case '-'
            rezultat = a - b;
        case '*'
            rezultat = a * b;
        case '/'
            if b ~= 0
                rezultat = a / b;
            else
                error('Impartire la zero!'); 
            end
        otherwise
            error('Operatie nevalida!'); 
    end
end

