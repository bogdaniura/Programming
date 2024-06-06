<?php
header('Content-Type: application/json'); // Ensure the content type is set to JSON

error_reporting(E_ALL);
ini_set('display_errors', '0'); // Turn off error displaying
ini_set('log_errors', '1'); // Turn on error logging
ini_set('error_log', '/opt/lampp/htdocs/proiect/error_log.log'); // Set the path to your error log file

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

$response = ['success' => false, 'schedules' => [], 'message' => 'No schedules found'];

$sql = "SELECT cs.id, c.class_name, cs.subject, cs.day_of_week, cs.start_time, cs.end_time 
        FROM class_schedules cs
        JOIN classes c ON cs.class_id = c.id";
$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $response['schedules'][] = $row;
    }
    $response['success'] = true;
    $response['message'] = 'Schedules loaded successfully';
}

$conn->close();
echo json_encode($response);
?>
