<?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");

if (!$db) {
  die("Conexiunea a eșuat: " . mysqli_connect_error());
}

$message = ""; // Initialize message variable

// Verifica daca datele au fost trimise
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $studentName = mysqli_real_escape_string($db, $_POST['studentName']);
  $subject = mysqli_real_escape_string($db, $_POST['subject']);
  $absenceDate = mysqli_real_escape_string($db, $_POST['absenceDate']);
  $absenceType = mysqli_real_escape_string($db, $_POST['absenceType']);

  // Check if a file has been uploaded
  if (isset($_FILES['fileUpload']) && $_FILES['fileUpload']['error'] == 0) {
    $fileName = $_FILES['fileUpload']['name'];
    $fileTmpName = $_FILES['fileUpload']['tmp_name'];
    $fileSize = $_FILES['fileUpload']['size'];
    $fileError = $_FILES['fileUpload']['error'];
    $fileType = $_FILES['fileUpload']['type'];

    // Specify the location where the file will be saved
    $fileDestination = 'uploads/' . $fileName;

    // Move the uploaded file to the specified location
    if (move_uploaded_file($fileTmpName, $fileDestination)) {
      // Prepare the SQL query
      $sql = "INSERT INTO absente (nume, materie, data_absenta, tip_absenta, file_path) VALUES ('$studentName', '$subject', '$absenceDate', '$absenceType', '$fileDestination')";

      // Execute the query and check the result
      if (mysqli_query($db, $sql)) {
        $message = "Absența a fost adaugata cu succes.";
      } else {
        $message = "Eroare: " . $sql . "<br>" . mysqli_error($db);
      }
    } else {
      $message = "Eroare la încărcarea fișierului.";
    }
  } else {
    // If no file is uploaded, proceed with adding absence without a file
    // Prepare the SQL query without file path
    $sql = "INSERT INTO absente (nume, materie, data_absenta, tip_absenta) VALUES ('$studentName', '$subject', '$absenceDate', '$absenceType')";

    // Execute the query and check the result
    if (mysqli_query($db, $sql)) {
      $message = "<div class='callout success'>Absența a fost adaugată cu succes.</div>"; // Set success message
    } else {
      $message = "Eroare: " . $sql . "<br>" . mysqli_error($db);
    }
  }

  // Închide conexiunea
  mysqli_close($db);
}
?>

<!DOCTYPE HTML>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Procesare Absența</title>
  <link rel="stylesheet" href="https://dhbhdrzi4tiry.cloudfront.net/cdn/sites/foundation.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/motion-ui@1.2.3/dist/motion-ui.min.css" />
  <link rel="stylesheet" href="css/app.css">
</head>
<body>
  <h2>Procesare Absența</h2>
  <div class="grid-container">
    <div class="callout">
      <?php echo $message; ?> <!-- Display message here -->
    </div>
    <a href="add_absence.html" class="button">Înapoi la formular</a>
    <a href="view_absences.php" class="button">Vizualizare Absențe</a>
  </div>
  <script src="js/vendor/jquery.js"></script>
  <script src="js/vendor/what-input.js"></script>
  <script src="js/vendor/foundation.js"></script>
  <script src="js/app.js"></script>
</body>
</html>
