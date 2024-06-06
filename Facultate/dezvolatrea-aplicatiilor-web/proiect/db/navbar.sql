use catalog;
CREATE TABLE navbar_items (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_type ENUM('elev', 'profesor', 'admin') NOT NULL,
    item_name VARCHAR(50) NOT NULL,
    item_link VARCHAR(255) NOT NULL
);

INSERT INTO navbar_items (user_type, item_name, item_link) VALUES
('elev', 'Acasa', './start.html'),
('elev', 'Elevi', './elevi.html'),
('elev', 'Profesori', './profesori.html'),
('elev', 'Contact', './contact.html'),
('profesor', 'Acasa', './start.html'),
('profesor', 'Profesori', './profesori.html'),
('profesor', 'Contact', './contact.html'),
('admin', 'Acasa', './start.html'),
('admin', 'Admin', './admin.html'),
('admin', 'Contact', './contact.html');