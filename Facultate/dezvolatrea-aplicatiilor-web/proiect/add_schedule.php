<?php
header('Content-Type: application/json'); // Ensure the content type is set to JSON

error_reporting(E_ALL);
ini_set('display_errors', '0'); // Turn off error displaying
ini_set('log_errors', '1'); // Turn on error logging
ini_set('error_log', '/path/to/your/error_log.log'); // Set the path to your error log file

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

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $classId = $_POST['classId'];
    $subject = $_POST['subject'];
    $dayOfWeek = $_POST['dayOfWeek'];
    $startTime = $_POST['startTime'];
    $endTime = $_POST['endTime'];

    $stmt = $conn->prepare("INSERT INTO class_schedules (class_id, subject, day_of_week, start_time, end_time) VALUES (?, ?, ?, ?, ?)");
    $stmt->bind_param("issss", $classId, $subject, $dayOfWeek, $startTime, $endTime);

    if ($stmt->execute()) {
        $response['success'] = true;
        $response['message'] = 'Schedule added successfully';
    } else {
        $response['message'] = 'Error adding schedule: ' . $stmt->error;
    }

    $stmt->close();
}

$conn->close();
echo json_encode($response);
?>
