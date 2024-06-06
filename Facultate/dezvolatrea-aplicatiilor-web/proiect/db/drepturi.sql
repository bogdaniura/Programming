USE catalog;

-- Create the users table
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    username VARCHAR(50) NOT NULL,
    password VARCHAR(255) NOT NULL,
    user_type ENUM('elev', 'profesor', 'admin', 'any') NOT NULL
);

-- Create the drepturi table
CREATE TABLE drepturi (
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    user_type ENUM('elev', 'profesor', 'admin', 'any') NOT NULL,
    page_name VARCHAR(100) NOT NULL,
    page_link VARCHAR(255) NOT NULL
);

-- Insert sample data into the drepturi table
INSERT INTO drepturi (user_type, page_name, page_link) VALUES 
('elev', 'Acasa', 'start.html'),
('elev', 'Orar', 'elevi_orar.html'),
('elev', 'Note', 'elevi_note.html'),
('elev', 'Absente', 'elevi_absente.html'),
('elev', 'Alte Informatii', 'elevi_alte_informatii.html'),
('profesor', 'Acasa', 'start.html'),
('profesor', 'Catalog', 'profesor_catalog.html'),
('profesor', 'Orar', 'profesor_orar.html'),
('profesor', 'Note', 'profesor_note.html'),
('admin', 'Acasa', 'start.html'),
('admin', 'Utilizatori', 'admin_utilizatori.html'),
('admin', 'Configurari', 'admin_configurari.html');

INSERT INTO users (username, password, user_type) VALUES
("elev1", md5("password1"), "elev"),
("elev2", md5("password2"), "elev"),
("profesor1", md5("password3"), "profesor"),
("profesor2", md5("password4"), "profesor"),
("admin1", md5("password1"), "admin"),
("edmin2", md5("password1"), "admin");
















