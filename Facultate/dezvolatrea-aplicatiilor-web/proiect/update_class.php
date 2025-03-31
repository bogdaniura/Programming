<?php
require 'db.php';

header('Content-Type: application/json');

$classId = $_POST['classId'];
$className = $_POST['className'];
$gradeLevel = $_POST['gradeLevel'];
$formationYear = $_POST['formationYear'];

$response = [];

if ($classId && $className && $gradeLevel && $formationYear) {
    $sql = "UPDATE classes SET class_name = ?, grade_level = ?, formation_year = ? WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssii", $className, $gradeLevel, $formationYear, $classId);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = "Class updated successfully.";
    } else {
        $response['success'] = false;
        $response['message'] = "Error updating class: " . $stmt->error;
    }

    $stmt->close();
} else {
    $response['success'] = false;
    $response['message'] = "Invalid input.";
}

$conn->close();

echo json_encode($response);
?>
