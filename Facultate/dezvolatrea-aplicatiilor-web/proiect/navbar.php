<?php
session_start();

// Redirect to login page if not logged in
if (!isset($_SESSION['username'])) {
  header("Location: login.html");
  exit();
}

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

$userType = $_SESSION['user_type'];

// Fetch permissions from the "drepturi" table
$sql = "SELECT page_name FROM drepturi WHERE user_type = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $userType);
$stmt->execute();
$result = $stmt->get_result();

$pages = [];
while ($row = $result->fetch_assoc()) {
  $pages[] = $row['page_name'];
}

$stmt->close();
$conn->close();
?>

<nav class="navbar navbar-expand-md navbar-dark bg-dark fixed-top">
  <a class="navbar-brand" href="#">Catalog Scolar</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <div class="collapse navbar-collapse" id="navbarNav">
    <ul class="navbar-nav ml-auto">
      <li class="nav-item"><a class="nav-link" href="start.php">Acasa</a></li>
      <?php foreach ($pages as $page): ?>
        <li class="nav-item"><a class="nav-link" href="<?php echo $page; ?>.php"><?php echo ucfirst($page); ?></a></li>
      <?php endforeach; ?>
      <li class="nav-item"><a class="nav-link" href="logout.php">Logout</a></li>
    </ul>
  </div>
</nav>
