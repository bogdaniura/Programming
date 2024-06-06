use catalog;
-- Crearea tabelului pentru clase
CREATE TABLE classes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    class_name VARCHAR(50) NOT NULL,
    grade_level VARCHAR(20) NOT NULL
);

-- Crearea tabelului pentru elevi
CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    student_name VARCHAR(100) NOT NULL,
    class_id INT,
    FOREIGN KEY (class_id) REFERENCES classes(id)
);

-- Crearea tabelului pentru orar
CREATE TABLE schedules (
    id INT AUTO_INCREMENT PRIMARY KEY,
    subject VARCHAR(100) NOT NULL,
    day_of_week VARCHAR(20) NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL
);

-- Crearea tabelului pentru legătura între clase și orar
CREATE TABLE class_schedules (
    class_id INT,
    schedule_id INT,
    PRIMARY KEY (class_id, schedule_id),
    FOREIGN KEY (class_id) REFERENCES classes(id),
    FOREIGN KEY (schedule_id) REFERENCES schedules(id)
);

INSERT INTO classes (class_name, grade_level) VALUES
('Class 1A', 'Grade 1'),
('Class 2A', 'Grade 2'),
('Class 3A', 'Grade 3');

INSERT INTO students (student_name, class_id) VALUES
('John Doe', 1),  -- John Doe este în Class 1A
('Jane Smith', 1),  -- Jane Smith este în Class 1A
('Tom Brown', 2),  -- Tom Brown este în Class 2A
('Alice Johnson', 3);  -- Alice Johnson este în Class 3A

INSERT INTO schedules (subject, day_of_week, start_time, end_time) VALUES
('Mathematics', 'Monday', '08:00:00', '09:30:00'),
('Science', 'Tuesday', '10:00:00', '11:30:00'),
('History', 'Wednesday', '12:00:00', '13:30:00');

INSERT INTO class_schedules (class_id, schedule_id) VALUES
(1, 1),  -- Class 1A are Mathematics
(2, 2),  -- Class 2A are Science
(3, 3);  -- Class 3A are History

