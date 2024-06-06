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

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $userType = $_POST['userType'];
  $username = $_POST['username'];
  $password = md5($_POST['password']); // Hash the password with MD5

  // Prepare and bind
  $stmt = $conn->prepare("INSERT INTO users (username, password, user_type) VALUES (?, ?, ?)");
  $stmt->bind_param("sss", $username, $password, $userType);

  // Execute the statement
  if ($stmt->execute()) {
    echo "<div class='alert alert-success' role='alert'>Utilizator adăugat cu succes!</div>";
  } else {
    echo "<div class='alert alert-danger' role='alert'>Eroare la adăugarea utilizatorului: " . $stmt->error . "</div>";
  }

  $stmt->close();
}

$conn->close();
?>
