<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die(json_encode(['success' => false, 'message' => 'Connection failed: ' . $conn->connect_error]));
}

$sql = "SELECT id, username, user_type FROM users";
$result = $conn->query($sql);
$response = ['success' => false, 'users' => [], 'message' => 'No users found'];

if ($result && $result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $response['users'][] = $row;
    }
    $response['success'] = true;
    $response['message'] = 'Users loaded successfully';
} else {
    $response['message'] = 'No users found or error in query';
}

$conn->close();
header('Content-Type: application/json');
echo json_encode($response);
?>
