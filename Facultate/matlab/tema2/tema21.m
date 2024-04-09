n = input('Introduceți un număr natural n: ');

ultimaCifra = ultimaCifra9n(n);

fprintf('Ultima cifră a lui 9^%d este: %d\n', n, ultimaCifra);

function lastDigit = ultimaCifra9n(n)
    if mod(n, 2) == 0
        lastDigit = 1;
    else
        lastDigit = 9;
    end
end


