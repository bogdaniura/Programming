<?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");

// Verificare conexiune
if (!$db) {
    die("Conexiunea a eșuat: " . mysqli_connect_error());
}

// Verificare dacă datele din formular au fost trimise
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nume = mysqli_real_escape_string($db, $_POST['nume']);
    $materie = mysqli_real_escape_string($db, $_POST['materie']);
    $nota = mysqli_real_escape_string($db, $_POST['nota']);
    $data_notare = mysqli_real_escape_string($db, $_POST['data_notare']);

    // Inserare date în tabelul "note"
    $sql = "INSERT INTO note (nume, materie, nota, data_notare) VALUES ('$nume', '$materie', '$nota', '$data_notare')";

    if (mysqli_query($db, $sql)) {
        echo "<div class='alert alert-success text-center'>Nota a fost adăugată cu succes!</div>";
    } else {
        echo "<div class='alert alert-danger text-center'>Eroare: " . $sql . "<br>" . mysqli_error($db) . "</div>";
    }

    // Închidere conexiune
    mysqli_close($db);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Adăugare Notă</title>
  <link rel="stylesheet" href="styles.css"> <!-- Stilurile CSS personalizate -->
  <link rel="stylesheet" href="styles2.css"> <!-- Stilurile CSS personalizate -->
</head>
<body>
  <!-- Meniul persistent -->
  <div id="navbarPlaceholder"></div> <!-- Placeholder for the dynamic navbar -->
    <script src="dynamic_navbar.js"></script><br>

  <!-- Conținutul paginii -->
  <div class="container mt-5">
    <h2 class="text-center">Adăugare Notă</h2>
    <button id="goBackButton">Înapoi</button>
  </div>

  <!-- Încarcă Bootstrap JS -->
  <script src="script.js"></script>
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
