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

  // Verifica daca fisierul a fost incarcat
  if (isset($_FILES['fileUpload']) && $_FILES['fileUpload']['error'] == 0) {
    $fileName = $_FILES['fileUpload']['name'];
    $fileTmpName = $_FILES['fileUpload']['tmp_name'];
    $fileSize = $_FILES['fileUpload']['size'];
    $fileError = $_FILES['fileUpload']['error'];
    $fileType = $_FILES['fileUpload']['type'];

    // Specifica locatia unde fisierul va fi salvat
    $fileDestination = 'uploads/' . $fileName;

    // Muta fisierul incarcat in locatia specificata
    if (move_uploaded_file($fileTmpName, $fileDestination)) {
      // Pregatește interogarea SQL
      $sql = "INSERT INTO absente (nume, materie, data_absenta, tip_absenta, file_path) VALUES ('$studentName', '$subject', '$absenceDate', '$absenceType', '$fileDestination')";

      // Executa interogarea și verifica rezultatul
      if (mysqli_query($db, $sql)) {
        $message = "Absența a fost adaugata cu succes.";
      } else {
        $message = "Eroare: " . $sql . "<br>" . mysqli_error($db);
      }
    } else {
      $message = "Eroare la încărcarea fișierului.";
    }
  } else {
    $message = "Trebuie să selectați un fișier de încărcat.";
  }

  // Închide conexiunea
  mysqli_close($db);
}
?>