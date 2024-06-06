USE catalog;

CREATE TABLE users (
  id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
  user_type ENUM('elev', 'profesor') NOT NULL,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(255) NOT NULL
);

INSERT INTO users (user_type, username, password) VALUES
('elev', 'elev1', MD5('password1')),
('profesor', 'profesor1', MD5('password2'));
