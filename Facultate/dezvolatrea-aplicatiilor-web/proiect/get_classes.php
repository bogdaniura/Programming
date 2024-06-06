<?php
header('Content-Type: application/json'); // Ensure the content type is set to JSON

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    echo json_encode(['success' => false, 'message' => 'Database connection failed: ' . $conn->connect_error]);
    exit;
}

$response = ['success' => false, 'classes' => [], 'message' => 'No classes found'];

$sql = "SELECT id, class_name, grade_level FROM classes";
$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $response['classes'][] = $row;
    }
    $response['success'] = true;
    $response['message'] = 'Classes loaded successfully';
}

$conn->close();
echo json_encode($response);
?>
