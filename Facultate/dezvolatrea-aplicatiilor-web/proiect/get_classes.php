<?php
require 'db.php';

$sql = "SELECT * FROM classes";
$result = $conn->query($sql);

$response = [];
if ($result->num_rows > 0) {
    $classes = [];
    while($row = $result->fetch_assoc()) {
        $classes[] = $row;
    }
    $response['success'] = true;
    $response['classes'] = $classes;
} else {
    $response['success'] = false;
    $response['message'] = "No classes found.";
}

$conn->close();

echo json_encode($response);
?>
