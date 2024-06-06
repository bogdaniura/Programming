CREATE TABLE elev_info (
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    user_id INT UNSIGNED NOT NULL,
    full_name VARCHAR(255),
    email VARCHAR(255),
    phone_number VARCHAR(20),
    address VARCHAR(255),
    birth_date DATE,
    class VARCHAR(50) NOT NULL,
    cnp varchar(15),
    parents_phone varchar(20),
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
