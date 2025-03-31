<?php
require 'db.php';

header('Content-Type: application/json');

$className = isset($_POST['className']) ? $_POST['className'] : null;
$gradeLevel = isset($_POST['gradeLevel']) ? $_POST['gradeLevel'] : null;
$formationYear = isset($_POST['formationYear']) ? $_POST['formationYear'] : null;

$response = [];

if ($className && $gradeLevel && $formationYear) {
    $sql = "INSERT INTO classes (class_name, grade_level, formation_year) VALUES (?, ?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssi", $className, $gradeLevel, $formationYear);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = "Class added successfully.";
    } else {
        $response['success'] = false;
        $response['message'] = "Error adding class: " . $stmt->error;
    }

    $stmt->close();
} else {
    $response['success'] = false;
    $response['message'] = "Invalid input.";
}

$conn->close();

echo json_encode($response);
?>
