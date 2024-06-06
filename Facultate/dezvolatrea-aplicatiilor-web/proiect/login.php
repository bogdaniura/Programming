<?php
session_start();

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$response = ['success' => false, 'message' => ''];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $userType = $_POST['userType'];
  $username = $_POST['username'];
  $password = md5($_POST['password']); // Hash the password with MD5

  $sql = "SELECT * FROM users WHERE user_type = ? AND username = ? AND password = ?";
  $stmt = $conn->prepare($sql);
  $stmt->bind_param("sss", $userType, $username, $password);
  $stmt->execute();
  $result = $stmt->get_result();

  if ($result->num_rows > 0) {
    // User exists, set session
    $_SESSION['user_type'] = $userType;

    // Set the response for successful login
    $response['success'] = true;
    $response['userType'] = $userType;
  } else {
    // User does not exist or wrong credentials
    $response['message'] = 'Nume de utilizator sau parolă incorectă!';
  }

  $stmt->close();
}

$conn->close();

// Return the JSON response
header('Content-Type: application/json');
echo json_encode($response);
?>
