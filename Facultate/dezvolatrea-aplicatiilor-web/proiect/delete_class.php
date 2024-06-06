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

$response = ['success' => false, 'message' => ''];

if (isset($_GET['id'])) {
    $classId = $_GET['id'];

    $stmt = $conn->prepare("DELETE FROM classes WHERE id = ?");
    $stmt->bind_param("i", $classId);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = 'Class deleted successfully';
    } else {
        $response['message'] = 'Error deleting class: ' . $stmt->error;
    }

    $stmt->close();
} else {
    $response['message'] = 'Class ID not specified';
}

$conn->close();
echo json_encode($response);
?>
