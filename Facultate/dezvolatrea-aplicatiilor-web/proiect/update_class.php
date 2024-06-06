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
    $classId = $_POST['classId'];
    $className = $_POST['className'];
    $gradeLevel = $_POST['gradeLevel'];

    $stmt = $conn->prepare("UPDATE classes SET class_name = ?, grade_level = ? WHERE id = ?");
    $stmt->bind_param("ssi", $className, $gradeLevel, $classId);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = 'Class updated successfully';
    } else {
        $response['message'] = 'Error updating class: ' . $stmt->error;
    }

    $stmt->close();
}

$conn->close();
header('Content-Type: application/json');
echo json_encode($response);
?>
