<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die(json_encode(['success' => false, 'message' => 'Database connection failed: ' . $conn->connect_error]));
}

$response = ['success' => false, 'navbar_items' => [], 'message' => ''];

if (isset($_GET['user_type'])) {
    $userType = $_GET['user_type'];

    $stmt = $conn->prepare("SELECT item_name, item_link FROM navbar_items WHERE user_type = ?");
    $stmt->bind_param("s", $userType);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $response['navbar_items'][] = $row;
        }
        $response['success'] = true;
    } else {
        $response['message'] = 'No items found for this user type';
    }

    $stmt->close();
} else {
    $response['message'] = 'User type not specified';
}

$conn->close();
header('Content-Type: application/json');
echo json_encode($response);
?>
