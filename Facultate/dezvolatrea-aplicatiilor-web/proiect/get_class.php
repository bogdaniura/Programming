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

$response = ['success' => false, 'class' => null, 'message' => ''];

if (isset($_GET['id'])) {
    $classId = $_GET['id'];

    $stmt = $conn->prepare("SELECT id, class_name, grade_level FROM classes WHERE id = ?");
    $stmt->bind_param("i", $classId);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        $response['success'] = true;
        $response['class'] = $result->fetch_assoc();
    } else {
        $response['message'] = 'Class not found';
    }

    $stmt->close();
} else {
    $response['message'] = 'Class ID not specified';
}

$conn->close();
echo json_encode($response);
?>
