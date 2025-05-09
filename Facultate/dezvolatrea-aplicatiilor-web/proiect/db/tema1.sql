-- Structura bazei de date fără diacritice
DROP DATABASE IF EXISTS biblioteca;
CREATE DATABASE biblioteca;
USE biblioteca;

-- Tabele
CREATE TABLE autori (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    nationalitate VARCHAR(50)
) ENGINE=InnoDB;

CREATE TABLE edituri (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    adresa VARCHAR(200)
) ENGINE=InnoDB;

CREATE TABLE categorii (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE carti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    titlu VARCHAR(100) NOT NULL,
    autor_id INT,
    editura_id INT,
    categorie_id INT,
    an_publicare YEAR,
    FOREIGN KEY (autor_id) REFERENCES autori(id),
    FOREIGN KEY (editura_id) REFERENCES edituri(id),
    FOREIGN KEY (categorie_id) REFERENCES categorii(id)
) ENGINE=InnoDB;

CREATE TABLE cititori (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nume VARCHAR(100) NOT NULL,
    email VARCHAR(100),
    data_inregistrare DATE NOT NULL
) ENGINE=InnoDB;

CREATE TABLE copii_carti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    carte_id INT NOT NULL,
    status ENUM('disponibil', 'imprumutat', 'in reparatie') DEFAULT 'disponibil',
    conditie VARCHAR(50),
    data_achizitie DATE,
    FOREIGN KEY (carte_id) REFERENCES carti(id)
) ENGINE=InnoDB;

CREATE TABLE imprumuturi (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cititor_id INT NOT NULL,
    copie_id INT NOT NULL,
    data_imprumut DATE NOT NULL,
    data_returnare DATE,
    FOREIGN KEY (cititor_id) REFERENCES cititori(id),
    FOREIGN KEY (copie_id) REFERENCES copii_carti(id)
) ENGINE=InnoDB;

CREATE TABLE recenzii (
    id INT PRIMARY KEY AUTO_INCREMENT,
    carte_id INT NOT NULL,
    cititor_id INT NOT NULL,
    nota INT CHECK (nota BETWEEN 1 AND 5),
    comentariu TEXT,
    FOREIGN KEY (carte_id) REFERENCES carti(id),
    FOREIGN KEY (cititor_id) REFERENCES cititori(id)
) ENGINE=InnoDB;

-- Datele (fără diacritice)
INSERT INTO autori (nume, nationalitate) VALUES
('Albert Camus', 'Franceza'),
('Agatha Christie', 'Engleza'),
('Haruki Murakami', 'Japoneza'),
('Stephen King', 'Americana'),
('Tudor Arghezi', 'Romana');

INSERT INTO edituri (nume, adresa) VALUES
('Editura Polirom', 'Iasi, Romania'),
('Editura Corint', 'Bucuresti, Romania'),
('Gallimard', 'Paris, Franta'),
('Random House', 'New York, SUA');

INSERT INTO categorii (nume) VALUES
('Thriller'),
('Filozofie'),
('Biografie'),
('Horror'),
('Roman');

INSERT INTO carti (titlu, autor_id, editura_id, categorie_id, an_publicare) VALUES
('Strainul', 1, 3, 2, 1942),
('Crima din Orient Express', 2, 4, 1, 1934),
('Kafka pe malul marii', 3, 2, 5, 2002),
('The Shining', 4, 4, 4, 1977),
('Cimitirul animalelor', 4, 4, 4, 1983),
('Flori de mucigai', 5, 2, 5, 1931);

INSERT INTO cititori (nume, email, data_inregistrare) VALUES
('Andrei Vasile', NULL, '2023-03-10'),
('Elena Popa', 'elena.popa@example.com', '2023-04-12'),
('Mihai Ionescu', 'mihai.ionescu@example.com', '2023-05-01'),
('Ana Marinescu', NULL, '2022-12-15'),
('Cristina Moldovan', 'cristina.m@example.com', '2023-06-20');

INSERT INTO copii_carti (carte_id, status, conditie, data_achizitie) VALUES 
(1, 'disponibil', 'excelenta', '2020-05-10'),
(1, 'imprumutat', 'buna', '2021-02-15'),
(2, 'disponibil', 'uzura moderata', '2019-11-20');

INSERT INTO imprumuturi (cititor_id, copie_id, data_imprumut, data_returnare) VALUES
(2, 2, '2023-05-01', NULL),
(3, 3, '2023-05-10', '2023-05-20'),
(4, 1, '2023-04-15', '2023-04-30'),
(5, 2, '2023-06-01', NULL);

INSERT INTO recenzii (carte_id, cititor_id, nota, comentariu) VALUES
(3, 2, 4, 'O lectura profunda'),
(4, 3, 5, 'Captivant!'),
(6, 4, 3, NULL),
(5, 1, 5, 'Un clasic');

-- Comenzi INSERT/UPDATE/DELETE
INSERT INTO autori (nume, nationalitate) VALUES ('George Orwell', 'Engleza');

UPDATE cititori SET email = 'contact@biblioteca.ro' 
WHERE email IS NULL AND data_inregistrare BETWEEN '2022-01-01' AND '2023-01-01';

DELETE FROM recenzii WHERE comentariu IS NULL OR nota IN (1, 2);

-- Interogari SELECT (exemple)
-- a. UNION
SELECT nume FROM autori WHERE nationalitate = 'Romana'
UNION
SELECT nume FROM cititori WHERE email LIKE '%example.com';

SELECT titlu FROM carti 
WHERE an_publicare < 2000 OR categorie_id = 5;

-- b. INTERSECT (emulat cu IN)
SELECT nume FROM cititori 
WHERE id IN (SELECT cititor_id FROM imprumuturi WHERE data_returnare IS NULL);

-- c. EXCEPT (emulat cu NOT IN)
SELECT nume FROM cititori 
WHERE id NOT IN (SELECT cititor_id FROM recenzii);

-- d. JOIN pe 3 tabele
SELECT cit.nume, c.titlu, i.data_imprumut
FROM imprumuturi i
JOIN cititori cit ON i.cititor_id = cit.id
JOIN copii_carti cc ON i.copie_id = cc.id
JOIN carti c ON cc.carte_id = c.id;

-- e. Subinterogare cu IN
SELECT nume FROM cititori 
WHERE id IN (SELECT cititor_id FROM recenzii WHERE nota > 3);

-- f. EXISTS
SELECT titlu FROM carti c
WHERE EXISTS (SELECT 1 FROM recenzii r WHERE r.carte_id = c.id AND nota = 5);

-- g. Subinterogare in FROM
SELECT AVG(nota) AS Medie FROM (SELECT nota FROM recenzii) AS temp;

-- h. GROUP BY
SELECT carte_id, AVG(nota) AS Medie FROM recenzii GROUP BY carte_id HAVING AVG(nota) > 3.5;

-- i. ANY/ALL
SELECT titlu FROM carti 
WHERE id = ANY(SELECT carte_id FROM recenzii WHERE nota > 4);

-- View pentru recenzii bune
CREATE VIEW vw_recenzii_bune AS
SELECT c.titlu, r.nota, r.comentariu 
FROM recenzii r
JOIN carti c ON r.carte_id = c.id
WHERE nota >= 4;