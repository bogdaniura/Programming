# Host: 127.0.0.1  (Version 5.5.5-10.1.16-MariaDB)
# Date: 2018-10-24 11:13:58
# Generator: MySQL-Front 5.4  (Build 2.5)
# Internet: http://www.mysqlfront.de/

/*!40101 SET NAMES utf8 */;

#
# Procedure "stergere"
#

CREATE PROCEDURE `stergere`(IN Param varchar(30))
BEGIN
DELETE
FROM datepersoane
WHERE email=Param;
END;
