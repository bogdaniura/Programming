% Citirea codului numeric personal ca un șir de caractere
cod_personal = input('Introduceti codul numeric personal (13 cifre): ', 's');

% Verificarea dacă codul are exact 13 caractere
if numel(cod_personal) ~= 13
    disp('Codul numeric personal trebuie să aibă exact 13 caractere.');
else
    % Extragem cifrele corespunzătoare datei de naștere
    data_nastere_str = cod_personal(2:7);
    
    % Conversia cifrelor în numere întregi
    data_nastere = str2double(data_nastere_str);
    
    % Extragem anul, luna și ziua
    an = 1900 + data_nastere(1:2);
    luna = data_nastere(3:4);
    zi = data_nastere(5:6);
    
    % Afișăm rezultatul
    fprintf('Data de nastere este: %d-%02d-%02d\n', an, luna, zi);
end
