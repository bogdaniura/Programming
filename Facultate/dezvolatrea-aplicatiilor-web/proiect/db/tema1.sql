-- Creează baza de date
CREATE DATABASE IF NOT EXISTS biblioteca;
USE biblioteca;

-- 1. Tabela Autori
CREATE TABLE autori (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    nationalitate VARCHAR(50)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 2. Tabela Edituri
CREATE TABLE edituri (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    adresa VARCHAR(200)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 3. Tabela Categorii
CREATE TABLE categorii (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 4. Tabela Cărți (relație 1:n cu Autori, Edituri și Categorii)
CREATE TABLE carti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    titlu VARCHAR(100) NOT NULL,
    autor_id INT,
    editura_id INT,
    categorie_id INT,
    an_publicare YEAR,
    FOREIGN KEY (autor_id) REFERENCES autori(id) ON DELETE SET NULL,
    FOREIGN KEY (editura_id) REFERENCES edituri(id) ON DELETE SET NULL,
    FOREIGN KEY (categorie_id) REFERENCES categorii(id) ON DELETE SET NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 5. Tabela Cititori
CREATE TABLE cititori (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    data_inregistrare DATE NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 6. Tabela Copii Cărți (relație 1:n cu Cărți)
CREATE TABLE copii_carti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    carte_id INT NOT NULL,
    status ENUM('disponibil', 'imprumutat', 'în reparație') DEFAULT 'disponibil',
    conditie VARCHAR(50),
    data_achizitie DATE,
    FOREIGN KEY (carte_id) REFERENCES carti(id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 7. Tabela Împrumuturi (relație m:n între Cititori și Copii Cărți)
CREATE TABLE imprumuturi (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cititor_id INT NOT NULL,
    copie_id INT NOT NULL,
    data_imprumut DATE NOT NULL,
    data_returnare DATE,
    FOREIGN KEY (cititor_id) REFERENCES cititori(id) ON DELETE CASCADE,
    FOREIGN KEY (copie_id) REFERENCES copii_carti(id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 8. Tabela Recenzii (relație m:n între Cititori și Cărți)
CREATE TABLE recenzii (
    id INT PRIMARY KEY AUTO_INCREMENT,
    carte_id INT NOT NULL,
    cititor_id INT NOT NULL,
    nota INT CHECK (nota BETWEEN 1 AND 5),
    comentariu TEXT,
    FOREIGN KEY (carte_id) REFERENCES carti(id) ON DELETE CASCADE,
    FOREIGN KEY (cititor_id) REFERENCES cititori(id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Autori
INSERT INTO autori (nume, nationalitate) VALUES
('Albert Camus', 'Franceză'),
('Agatha Christie', 'Engleză'),
('Haruki Murakami', 'Japoneză'),
('Stephen King', 'Americană'),
('Tudor Arghezi', 'Română');

-- Edituri
INSERT INTO edituri (nume, adresa) VALUES
('Editura Polirom', 'Iași, România'),
('Editura Corint', 'București, România'),
('Gallimard', 'Paris, Franța'),
('Random House', 'New York, SUA');

-- Categorii
INSERT INTO categorii (nume) VALUES
('Thriller'),
('Filozofie'),
('Biografie'),
('Horror'),
('Roman');

-- Cărți
INSERT INTO carti (titlu, autor_id, editura_id, categorie_id, an_publicare) VALUES
('Străinul', 3, 3, 6, 1942),         -- Albert Camus (Filozofie)
('Crima din Orient Express', 4, 4, 5, 1934), -- Agatha Christie (Thriller)
('Kafka pe malul mării', 5, 2, 9, 2002),    -- Haruki Murakami (Roman)
('The Shining', 6, 4, 8, 1977),             -- Stephen King (Horror)
('Cimitirul animalelor', 6, 4, 8, 1983),    -- Stephen King (Horror)
('Flori de mucigai', 7, 2, 9, 1931);        -- Tudor Arghezi (Roman)

-- Copii Cărți (cu date suplimentare: status, condiție, data achiziției)
INSERT INTO copii_carti (carte_id, status, conditie, data_achizitie) VALUES 
(1, 'disponibil', 'excelentă', '2020-05-10'),
(1, 'imprumutat', 'bună', '2021-02-15'),
(2, 'disponibil', 'uzură moderată', '2019-11-20');

-- Cititori
INSERT INTO cititori (nume, email, data_inregistrare) VALUES
('Andrei Vasile', NULL, '2023-03-10'),       -- Fără email (pentru DELETE cu IS NULL)
('Elena Popa', 'elena.popa@example.com', '2023-04-12'),
('Mihai Ionescu', 'mihai.ionescu@example.com', '2023-05-01'),
('Ana Marinescu', NULL, '2022-12-15'),        -- Fără email
('Cristina Moldovan', 'cristina.m@example.com', '2023-06-20');

-- Împrumuturi (legătura m:n între cititori și copii_carti)
INSERT INTO imprumuturi (cititor_id, copie_id, data_imprumut, data_returnare) VALUES
(2, 2, '2023-05-01', NULL),     -- Împrumut activ (fără dată returnare)
(3, 3, '2023-05-10', '2023-05-20'),
(4, 5, '2023-04-15', '2023-04-30'),
(5, 6, '2023-06-01', NULL),     -- Împrumut activ
(1, 4, '2023-03-01', '2023-03-15');

-- Recenzii
INSERT INTO recenzii (carte_id, cititor_id, nota, comentariu) VALUES
(3, 2, 4, 'O lectură profundă, dar puțin abstractă.'),
(4, 3, 5, 'Captivant! Recomand pentru iubitorii de mister.'),
(6, 4, 3, NULL),                -- Recenzie fără comentariu (pentru DELETE cu IS NULL)
(7, 5, 2, 'Prea înfricoșător pentru gustul meu.'),
(5, 1, 5, 'O experiență literară unică.');

-- Modificăm numele unui autor folosind o condiție compusă
UPDATE autori SET nume = 'Mihai Eminescu (Modificat)' 
WHERE id = 1 AND nationalitate = 'Română';

-- Modificăm anul publicării unei cărți folosind operatori relaționali
UPDATE carti SET an_publicare = 1950 
WHERE an_publicare < 1950;

-- Modificăm data de returnare a unui împrumut folosind IS NULL
UPDATE imprumuturi SET data_returnare = '2023-03-20' 
WHERE data_returnare IS NULL;

-- Modificăm genul unei cărți folosind IN
UPDATE carti SET categorie_id = 3 
WHERE categorie_id IN (1, 2);

-- Modificăm data de înregistrare a unui cititor folosind BETWEEN
UPDATE cititori SET data_inregistrare = '2023-01-01' 
WHERE data_inregistrare BETWEEN '2023-01-01' AND '2023-01-31';

-- Ștergem un cititor folosind o condiție compusă
DELETE FROM cititori 
WHERE id = 2 AND email LIKE '%popescu%';

-- Ștergem cărți publicate într-un anumit interval folosind BETWEEN
DELETE FROM carti 
WHERE an_publicare BETWEEN 1900 AND 1950;

-- Ștergem recenzii care nu au comentarii folosind IS NULL
DELETE FROM recenzii 
WHERE comentariu IS NULL;

-- Ștergem autori din anumite naționalități folosind IN
DELETE FROM autori 
WHERE nationalitate IN ('Engleză', 'Franceză');

-- Ștergem cărți care conțin un anumit cuvânt în titlu folosind LIKE
DELETE FROM carti 
WHERE titlu LIKE '%Poezii%';

-- Schimbă starea copiilor cu uzură achiziționate înainte de 2022
UPDATE copii_carti 
SET status = 'în reparație' 
WHERE conditie LIKE '%uzur%' AND data_achizitie < '2022-01-01';

-- Șterge împrumuturile din prima jumătate a anului 2023
DELETE FROM imprumuturi 
WHERE data_imprumut BETWEEN '2023-01-01' AND '2023-06-30';

-- Setează email pentru cititorii fără adresă
UPDATE cititori 
SET email = 'necunoscut@example.com' 
WHERE email IS NULL;

-- Șterge cărțile din categoria Horror sau Thriller
DELETE FROM carti 
WHERE categorie_id IN (5, 8);

























