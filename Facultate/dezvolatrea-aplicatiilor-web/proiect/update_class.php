<?php
require 'db.php';

$classId = $_POST['classId'];
$className = $_POST['className'];
$gradeLevel = $_POST['gradeLevel'];

$sql = "UPDATE classes SET class_name = ?, grade_level = ? WHERE id = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("ssi", $className, $gradeLevel, $classId);

$response = [];
if ($stmt->execute()) {
    $response['success'] = true;
    $response['message'] = "Class updated successfully.";
} else {
    $response['success'] = false;
    $response['message'] = "Error updating class: " . $stmt->error;
}

$stmt->close();
$conn->close();

echo json_encode($response);
?>
