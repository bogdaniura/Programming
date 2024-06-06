<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die(json_encode(['success' => false, 'message' => 'Database connection failed: ' . $conn->connect_error]));
}

$response = ['success' => false, 'message' => ''];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $className = $_POST['className'];
    $gradeLevel = $_POST['gradeLevel'];

    $stmt = $conn->prepare("INSERT INTO classes (class_name, grade_level) VALUES (?, ?)");
    $stmt->bind_param("ss", $className, $gradeLevel);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = 'Class added successfully';
    } else {
        $response['message'] = 'Error adding class: ' . $stmt->error;
    }

    $stmt->close();
}

$conn->close();
header('Content-Type: application/json');
echo json_encode($response);
?>
