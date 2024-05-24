<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Rezultate Căutare Absențe</title>
  <link rel="stylesheet" type="text/css" href="style2.css">
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>

<body>
  <div class="container mt-5">
    <h2 class="text-center">Rezultate Căutare Absențe</h2>
    <?php
    $db = mysqli_connect("127.0.0.1", "root", "", "catalog");

    if (!$db) {
      die("Conexiunea a eșuat: " . mysqli_connect_error());
    }

    $nume = isset($_GET['nume']) ? mysqli_real_escape_string($db, $_GET['nume']) : '';
    $materie = isset($_GET['materie']) ? mysqli_real_escape_string($db, $_GET['materie']) : '';
    $data_absenta = isset($_GET['data_absenta']) ? mysqli_real_escape_string($db, $_GET['data_absenta']) : '';
    $tip_absenta = isset($_GET['tip_absenta']) ? mysqli_real_escape_string($db, $_GET['tip_absenta']) : '';

    $query = "SELECT nume, materie, data_absenta, tip_absenta FROM absente WHERE 1=1";

    if (!empty($nume)) {
      $query .= " AND nume LIKE '%$nume%'";
    }
    if (!empty($materie)) {
      $query .= " AND materie LIKE '%$materie%'";
    }
    if (!empty($data_absenta)) {
      $query .= " AND data_absenta = '$data_absenta'";
    }
    if (!empty($tip_absenta)) {
      $query .= " AND tip_absenta = '$tip_absenta'";
    }

    $result = mysqli_query($db, $query);

    if (!$result) {
      die('Interogare invalidă: ' . mysqli_error($db));
    } else {
      echo "<table class=\"table table-striped\">";
      echo "<thead><tr><th>Nume</th><th>Materie</th><th>Data Absenței</th><th>tip Absenței</th></tr></thead><tbody>";
      while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr><td>" . $row["nume"] . "</td><td>" . $row["materie"] . "</td><td>" . $row["data_absenta"] . "</td><td>" . $row["tip_absenta"] . "</td></tr>";
      }
      echo "</tbody></table>";
    }

    mysqli_close($db);
    ?>
    <a href="search_absences.html" class="btn btn-secondary mt-3">Înapoi la Căutare</a>
  </div>
  <button id="goBackButton">Înapoi</button>
  <script src="script.js"></script>
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>