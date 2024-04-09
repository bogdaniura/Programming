nume_luni = {'Ianuarie', 'Februarie', 'Martie', 'Aprilie', 'Mai', 'Iunie', 'Iulie', 'August', 'Septembrie', 'Octombrie', 'Noiembrie', 'Decembrie'};

n = input('Introdu numărul lunii (1-12): ');

if n < 1 || n > 12
    fprintf('Numărul trebuie să fie între 1 și 12.\n');
else
    fprintf('Luna corespunzătoare numărului %d este: %s\n', n, nume_luni{n});
end
