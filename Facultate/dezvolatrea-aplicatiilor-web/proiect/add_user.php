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
  $userType = $_POST['userType'];
  $username = $_POST['username'];
  $password = md5($_POST['password']); // Hash the password with MD5

  // Prepare and bind
  $stmt = $conn->prepare("INSERT INTO users (username, password, user_type) VALUES (?, ?, ?)");
  $stmt->bind_param("sss", $username, $password, $userType);

  // Execute the statement
  if ($stmt->execute()) {
    $response['success'] = true;
    $response['message'] = 'Utilizator adăugat cu succes!';
  } else {
    $response['message'] = 'Eroare la adăugarea utilizatorului: ' . $stmt->error;
  }

  $stmt->close();
}

$conn->close();

header('Content-Type: application/json');
echo json_encode($response);
?>
