<?php
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
  $userId = $_POST['userId'];
  $userType = $_POST['userType'];
  $username = $_POST['username'];
  $password = isset($_POST['password']) ? md5($_POST['password']) : null;

  // Prepare and bind
  if ($password) {
    $stmt = $conn->prepare("UPDATE users SET username = ?, password = ?, user_type = ? WHERE id = ?");
    $stmt->bind_param("sssi", $username, $password, $userType, $userId);
  } else {
    $stmt = $conn->prepare("UPDATE users SET username = ?, user_type = ? WHERE id = ?");
    $stmt->bind_param("ssi", $username, $userType, $userId);
  }

  // Execute the statement
  if ($stmt->execute()) {
    $response['success'] = true;
    $response['message'] = 'Utilizator actualizat cu succes!';
  } else {
    $response['message'] = 'Eroare la actualizarea utilizatorului: ' . $stmt->error;
  }

  $stmt->close();
}

$conn->close();

header('Content-Type: application/json');
echo json_encode($response);
?>
