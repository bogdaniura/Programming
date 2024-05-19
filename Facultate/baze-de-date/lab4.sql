use bogdan

INSERT into clienti 
values (1, "Iura Bogdan", "RO")
values (2, "Pop Bogdan", "GB")
values (3, "Gavaller Ariana", "HU")
values (4, "Marina Andrei", "IT")
values (5, "Leordean Luca", "RO")
values (6, "Elicopter Adrian", "RO");

SELECT clienti.nume
FROM clienti
LEFT JOIN comenzi ON clienti.nume = comenzi.client
ORDER BY clienti.nume;
