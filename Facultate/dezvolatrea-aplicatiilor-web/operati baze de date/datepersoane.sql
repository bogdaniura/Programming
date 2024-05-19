CREATE TABLE `datepersoane` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) CHARACTER SET latin1 COLLATE latin1_bin NOT NULL,
  `email` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=95 DEFAULT CHARSET=latin1;

INSERT INTO `datepersoane` VALUES (1,'pop','pop@gmail.com'),(2,'vele','v@y.com'),(3,'maier','mai@y.com');
