<?php
require 'db.php';

$classId = $_GET['id'];

$sql = "DELETE FROM classes WHERE id = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $classId);

$response = [];
if ($stmt->execute()) {
    $response['success'] = true;
    $response['message'] = "Class deleted successfully.";
} else {
    $response['success'] = false;
    $response['message'] = "Error deleting class: " . $stmt->error;
}

$stmt->close();
$conn->close();

echo json_encode($response);
?>
