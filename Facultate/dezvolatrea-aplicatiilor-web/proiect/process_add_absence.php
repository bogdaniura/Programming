<?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");

if (!$db) {
  die("Conexiunea a eșuat: " . mysqli_connect_error());
}

// Verifica daca datele au fost trimise
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $studentName = mysqli_real_escape_string($db, $_POST['studentName']);
  $subject = mysqli_real_escape_string($db, $_POST['subject']);
  $absenceDate = mysqli_real_escape_string($db, $_POST['absenceDate']);
  $absenceType = mysqli_real_escape_string($db, $_POST['absenceType']);

  // Pregatește interogarea SQL
  $sql = "INSERT INTO absente (nume, materie, data_absenta, tip_absenta) VALUES ('$studentName', '$subject', '$absenceDate', '$absenceType')";

  // Executa interogarea și verifica rezultatul
  if (mysqli_query($db, $sql)) {
    $message = "Absența a fost adaugata cu succes.";
  } else {
    $message = "Eroare: " . $sql . "<br>" . mysqli_error($db);
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
  <link rel="stylesheet" href="styles2.css">
</head>

<body>
  <h2>Procesare Absența</h2>
  <div class="grid-container">
    <div class="callout">
      <?php echo $message; ?>
    </div>
    <a href="add_absence.html" class="button">Înapoi la formular</a>
    <a href="view_absences.php" class="button">Vizualizare Absențe</a>
  </div>
  <button id="goBackButton">Înapoi</button>
  <script src="script.js"></script>
  <script src="js/vendor/jquery.js"></script>
  <script src="js/vendor/what-input.js"></script>
  <script src="js/vendor/foundation.js"></script>
  <script src="js/app.js"></script>
</body>

</html>