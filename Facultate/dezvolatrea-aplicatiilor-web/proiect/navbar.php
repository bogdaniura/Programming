<?php

// Start the session to store user information
session_start();

// Check if the user is logged in, if not redirect to the login page
if (!isset($_SESSION['username'])) {
  header("Location: login.html"); // Redirect to the login page
  exit();
}

// Database connection details
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "catalog";

// Create a connection to the database
$conn = new mysqli($servername, $username, $password, $dbname);

// Check if the connection was successful
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error); // Die and display the error message if the connection fails
}

// Fetch the user type from the session
$userType = $_SESSION['user_type'];

// Prepare and execute a SQL query to fetch the page names from the "drepturi" table based on the user type
$sql = "SELECT page_name FROM drepturi WHERE user_type = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $userType);
$stmt->execute();
$result = $stmt->get_result();

// Store the fetched page names in an array
$pages = [];
while ($row = $result->fetch_assoc()) {
  $pages[] = $row['page_name'];
}

// Close the statement and the database connection
$stmt->close();
$conn->close();
?>

<!-- Create a navigation bar -->
<nav class="navbar navbar-expand-md navbar-dark bg-dark fixed-top">
  <a class="navbar-brand" href="#">Catalog Scolar</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <div class="collapse navbar-collapse" id="navbarNav">
    <ul class="navbar-nav ml-auto">
      <li class="nav-item"><a class="nav-link" href="start.php">Acasa</a></li>

      <!-- Loop through the fetched page names and create navigation links -->
      <?php foreach ($pages as $page): ?>
        <li class="nav-item"><a class="nav-link" href="<?php echo $page; ?>.php"><?php echo ucfirst($page); ?></a></li>
      <?php endforeach; ?>

      <li class="nav-item"><a class="nav-link" href="logout.php">Logout</a></li>
    </ul>
  </div>
</nav>

