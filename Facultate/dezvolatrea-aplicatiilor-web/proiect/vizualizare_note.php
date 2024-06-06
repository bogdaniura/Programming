<!DOCTYPE HTML>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Vizualizare Note</title>
  <link rel="stylesheet" href="https://dhbhdrzi4tiry.cloudfront.net/cdn/sites/foundation.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/motion-ui@1.2.3/dist/motion-ui.min.css" />
  <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">

  <link rel="stylesheet" href="css/app.css">
  <link rel="stylesheet" type="text/css" href="style.css">

</head>

<body>
  <div id="navbarPlaceholder"></div> <!-- Placeholder for the dynamic navbar -->
    <script src="dynamic_navbar.js"></script><br>
  <h2>Vizualizare Note</h2>
  <div class="grid-container">

    <?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");
if (!$db) {
    die("Conexiunea a eșuat: " . mysqli_connect_error());
}

// Verificare dacă s-a trimis o cerere POST pentru ștergerea unei note
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['deleteButton'])) {
    $studentName = mysqli_real_escape_string($db, $_POST['studentName']);
    $subject = mysqli_real_escape_string($db, $_POST['subject']);
    $gradeDate = mysqli_real_escape_string($db, $_POST['gradeDate']);
    $grade = mysqli_real_escape_string($db, $_POST['grade']);

    // Pregătirea interogării SQL pentru ștergerea notei
    $sql = "DELETE FROM note WHERE nume='$studentName' AND materie='$subject' AND data_notare='$gradeDate' AND nota='$grade'";
    if (mysqli_query($db, $sql)) {
        echo "<div class='callout success'>Nota a fost ștearsă cu succes.</div>";
    } else {
        echo "<div class='callout alert'>Eroare la ștergerea notei: " . mysqli_error($db) . "</div>";
    }
}

// Setarea variabilelor pentru paginare
$limit = 2; // Număr de înregistrări pe pagină
$page = isset($_GET['page']) ? (int) $_GET['page'] : 1;
$start = ($page - 1) * $limit;

// Interogare pentru a obține notele cu paginare
$sql = "SELECT * FROM note LIMIT $start, $limit";
$result = mysqli_query($db, $sql);

// Interogare pentru a obține numărul total de note
$total_results = mysqli_query($db, "SELECT COUNT(*) AS total FROM note");
$total_rows = mysqli_fetch_assoc($total_results)['total'];
$total_pages = ceil($total_rows / $limit);

if (mysqli_num_rows($result) > 0) {
    echo "<table class='unstriped'>";
    echo "<thead><tr><th>Nume</th><th>Materie</th><th>Nota</th><th>Data Notării</th><th>Acțiuni</th></tr></thead><tbody>";
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['nume']) . "</td>";
        echo "<td>" . htmlspecialchars($row['materie']) . "</td>";
        echo "<td>" . htmlspecialchars($row['nota']) . "</td>";
        echo "<td>" . htmlspecialchars($row['data_notare']) . "</td>";
        echo "<td>
                <form method='post' onsubmit='return confirm(\"Sigur doriți să ștergeți această notă?\");'>
                  <input type='hidden' name='studentName' value='" . htmlspecialchars($row['nume']) . "'>
                  <input type='hidden' name='subject' value='" . htmlspecialchars($row['materie']) . "'>
                  <input type='hidden' name='grade' value='" . htmlspecialchars($row['nota']) . "'>
                  <input type='hidden' name='gradeDate' value='" . htmlspecialchars($row['data_notare']) . "'>
                  <button type='submit' name='deleteButton' class='button alert'>Șterge</button>
                </form>
              </td>";
        echo "</tr>";
    }
    echo "</tbody></table>";

    // Afișare paginare
    echo "<ul class='pagination' role='navigation' aria-label='Pagination'>";
    if ($page > 1) {
        echo "<li class='pagination-previous'><a href='?page=" . ($page - 1) . "'>Înapoi</a></li>";
    } else {
        echo "<li class='pagination-previous disabled'>Înapoi</li>";
    }

    for ($i = 1; $i <= $total_pages; $i++) {
        if ($i == $page) {
            echo "<li class='current'>$i</li>";
        } else {
            echo "<li><a href='?page=$i'>$i</a></li>";
        }
    }

    if ($page < $total_pages) {
        echo "<li class='pagination-next'><a href='?page=" . ($page + 1) . "'>Înainte</a></li>";
    } else {
        echo "<li class='pagination-next disabled'>Înainte</li>";
    }
    echo "</ul>";

} else {
    echo "<div class='callout'>Nu există note în baza de date.</div>";
}

// Închiderea conexiunii
mysqli_close($db);
?>

    <a href="operatii.html" class="button">Înapoi la Operații</a>
  </div>

  <script src="js/vendor/jquery.js"></script>
  <script src="js/vendor/what-input.js"></script>
  <script src="js/vendor/foundation.js"></script>
  <script src="js/app.js"></script>
</body>

</html>
