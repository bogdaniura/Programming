use bogdan;
set SESSION TRANSACTION ISOLATION level READ UNCOMMITTED;
update Scoala set NrElevi = 100 where ID=2;

SELECT * from Scoala;