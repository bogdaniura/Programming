USE catalog

CREATE TABLE absente (
    nume VARCHAR(255) NOT NULL,
    materie VARCHAR(255) NOT NULL,
    data_absenta DATE NOT NULL,
    tip_absenta VARCHAR(255) NOT NULL
);

INSERT INTO `absente` VALUES ("Iura Bogdan", "Matematica", "2023-10-10", "nemotivata");
INSERT INTO `absente` VALUES ("Iura Bogdan", "Romana", "2023-9-10", "motivata");
