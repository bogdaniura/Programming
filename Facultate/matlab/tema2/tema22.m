n = input('Introduceți un număr natural n: ');

ultimaCifra = ultimaCifra2n(n);

fprintf('Ultima cifră a lui 2^%d este: %d\n', n, ultimaCifra);

function ultimaCifra = ultimaCifra2n(n)
  % Determinați ultima cifră a lui n
  if rem(n, 2) == 0
    ultimaCifra = n;
  else
    ultimaCifra = rem(n + 1, 2);
  end
  
  % Calculați ultima cifră a lui 2^n folosind ciclicitatea
  powersOf2 = [2, 4, 8, 6];
  if n >= 8
    ultimaCifra = powersOf2(rem(n - 8, 4) + 1);
  end
end
