<?php
require 'db.php';

$classId = $_GET['id'];

$sql = "SELECT * FROM classes WHERE id = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $classId);
$stmt->execute();
$result = $stmt->get_result();

$response = [];
if ($result->num_rows > 0) {
    $response['success'] = true;
    $response['class'] = $result->fetch_assoc();
} else {
    $response['success'] = false;
    $response['message'] = "Class not found.";
}

$stmt->close();
$conn->close();

echo json_encode($response);
?>
