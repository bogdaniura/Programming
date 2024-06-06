<?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");

// Verificare conexiune
if (!$db) {
    die("Conexiunea a eșuat: " . mysqli_connect_error());
}

// Definirea variabilelor pentru căutare și paginare
$search_nume = isset($_GET['nume']) ? mysqli_real_escape_string($db, $_GET['nume']) : '';
$search_materie = isset($_GET['materie']) ? mysqli_real_escape_string($db, $_GET['materie']) : '';
$search_data = isset($_GET['data_notare']) ? mysqli_real_escape_string($db, $_GET['data_notare']) : '';

$limit = 2; // Numărul de rânduri pe pagină
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
$start = ($page - 1) * $limit;

// Construirea interogării SQL cu condiții de căutare
$sql = "SELECT nume, materie, nota, data_notare FROM note WHERE 1=1";
if ($search_nume != '') {
    $sql .= " AND nume LIKE '%$search_nume%'";
}
if ($search_materie != '') {
    $sql .= " AND materie LIKE '%$search_materie%'";
}
if ($search_data != '') {
    $sql .= " AND data_notare = '$search_data'";
}
$sql .= " LIMIT $start, $limit";

$result = mysqli_query($db, $sql);

// Interogare pentru numărarea totalului de rânduri cu condiții de căutare
$count_sql = "SELECT COUNT(*) FROM note WHERE 1=1";
if ($search_nume != '') {
    $count_sql .= " AND nume LIKE '%$search_nume%'";
}
if ($search_materie != '') {
    $count_sql .= " AND materie LIKE '%$search_materie%'";
}
if ($search_data != '') {
    $count_sql .= " AND data_notare = '$search_data'";
}

$count_result = mysqli_query($db, $count_sql);
$total_results = mysqli_fetch_array($count_result)[0];
$total_pages = ceil($total_results / $limit);

mysqli_close($db);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Rezultate Căutare Note</title>
  <link rel="stylesheet" type="text/css" href="style2.css">    
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <link rel="stylesheet" href="styles.css"> <!-- Stilurile CSS personalizate -->
</head>
<body>
  <!-- Meniul persistent -->
  <div id="navbarPlaceholder"></div> <!-- Placeholder for the dynamic navbar -->
    <script src="dynamic_navbar.js"></script><br>

  <!-- Conținutul paginii -->
  <div class="container mt-5">
    <h2 class="text-center">Rezultate Căutare Note</h2>
    <?php
    if (mysqli_num_rows($result) > 0) {
        echo "<table class='table table-bordered'>";
        echo "<thead class='thead-dark'><tr><th>Nume</th><th>Materie</th><th>Nota</th><th>Data Notării</th></tr></thead><tbody>";
        // Afișare date din fiecare rând
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row["nume"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["materie"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["nota"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["data_notare"]) . "</td>";
            echo "</tr>";
          }
        echo "</tbody></table>";

        // Linkuri de navigare pentru paginare
        echo "<nav aria-label='Page navigation example'><ul class='pagination justify-content-center'>";
        if ($page > 1) {
            echo "<li class='page-item'><a class='page-link' href='?page=" . ($page - 1) . "&nume=$search_nume&materie=$search_materie&data_notare=$search_data'>Previous</a></li>";
        }
        for ($i = 1; $i <= $total_pages; $i++) {
            if ($i == $page) {
                echo "<li class='page-item active'><a class='page-link' href='#'>" . $i . "</a></li>";
            } else {
              echo "<li class='page-item'><a class='page-link' href='?page=" . $i . "&nume=$search_nume&materie=$search_materie&data_notare=$search_data'>" . $i . "</a></li>";
            }
        }
        if ($page < $total_pages) {
            echo "<li class='page-item'><a class='page-link' href='?page=" . ($page + 1) . "&nume=$search_nume&materie=$search_materie&data_notare=$search_data'>Next</a></li>";
        }
        echo "</ul></nav>";
    } else {
        echo "<p class='text-center'>Nu există note care să corespundă criteriilor de căutare.</p>";
    }
    ?>
  </div>
  <button id="goBackButton">Înapoi</button>

  <!-- Încarcă Bootstrap JS -->
  <script src="script.js"></script>
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
