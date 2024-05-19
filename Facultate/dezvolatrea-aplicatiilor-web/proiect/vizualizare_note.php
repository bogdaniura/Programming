<?php
// Conectare la baza de date
$db = mysqli_connect("127.0.0.1", "root", "", "catalog");

// Verificare conexiune
if (!$db) {
    die("Conexiunea a eșuat: " . mysqli_connect_error());
}

// Definirea variabilelor pentru paginare
$limit = 2; // Numărul de rânduri pe pagină
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
$start = ($page - 1) * $limit;

// Interogare pentru extragerea datelor din tabelul "note" cu paginare
$sql = "SELECT nume, materie, nota, data_notare FROM note LIMIT $start, $limit";
$result = mysqli_query($db, $sql);

// Interogare pentru numărarea totalului de rânduri
$total_results = mysqli_num_rows(mysqli_query($db, "SELECT * FROM note"));
$total_pages = ceil($total_results / $limit);

mysqli_close($db);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Vizualizare Note</title>
    <link rel="stylesheet" type="text/css" href="style2.css">    
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="styles.css"> <!-- Stilurile CSS personalizate -->
</head>
<body>
    <!-- Meniul persistent -->
    <nav class="navbar navbar-expand-md navbar-dark bg-dark">
        <a class="navbar-brand" href="#">Catalog Școlar</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav ml-auto">
                <li class="nav-item">
                    <a class="nav-link" href="#">Acasă</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Utilizatori</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Note</a>
                </li>
                <!-- Alte elemente de navigare -->
            </ul>
        </div>
    </nav>

    <!-- Conținutul paginii -->
    <div class="container mt-5">
        <h2 class="text-center">Vizualizare Note</h2>
        <?php if (mysqli_num_rows($result) > 0): ?>
            <table class='table table-bordered'>
                <thead class='thead-dark'>
                    <tr>
                        <th>Nume</th>
                        <th>Materie</th>
                        <th>Nota</th>
                        <th>Data Notării</th>
                    </tr>
                </thead>
                <tbody>
                    <?php while ($row = mysqli_fetch_assoc($result)): ?>
                        <tr>
                            <td><?= htmlspecialchars($row["nume"]) ?></td>
                            <td><?= htmlspecialchars($row["materie"]) ?></td>
                            <td><?= htmlspecialchars($row["nota"]) ?></td>
                            <td><?= htmlspecialchars($row["data_notare"]) ?></td>
                        </tr>
                    <?php endwhile; ?>
                </tbody>
            </table>

            <!-- Linkuri de navigare pentru paginare -->
            <nav aria-label='Page navigation example'>
                <ul class='pagination justify-content-center'>
                    <?php if ($page > 1): ?>
                        <li class='page-item'><a class='page-link' href='?page=<?= ($page - 1) ?>'>Previous</a></li>
                    <?php endif; ?>
                    <?php for ($i = 1; $i <= $total_pages; $i++): ?>
                        <?php if ($i == $page): ?>
                            <li class='page-item active'><a class='page-link' href='#'><?= $i ?></a></li>
                        <?php else: ?>
                            <li class='page-item'><a class='page-link' href='?page=<?= $i ?>'><?= $i ?></a></li>
                        <?php endif; ?>
                    <?php endfor; ?>
                    <?php if ($page < $total_pages): ?>
                        <li class='page-item'><a class='page-link' href='?page=<?= ($page + 1) ?>'>Next</a></li>
                    <?php endif; ?>
                </ul>
            </nav>
        <?php else: ?>
            <p class='text-center'>Nu există note în baza de date.</p>
        <?php endif; ?>
    </div>
    <button id="goBackButton">Înapoi</button>

    <!-- Încarcă Bootstrap JS -->
    <script src="script.js"></script>
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
