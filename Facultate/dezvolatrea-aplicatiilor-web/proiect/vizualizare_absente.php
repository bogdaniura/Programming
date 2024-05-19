<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Vizualizare Absențe</title>
    <link rel="stylesheet" type="text/css" href="style2.css">    
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="styles.css"> <!-- Încarcă stilurile CSS personalizate -->
</head>

<body>
    <!-- Meniul persistent -->
    <nav class="navbar navbar-expand-md navbar-dark bg-dark">
        <a class="navbar-brand" href="#">Catalog Școlar</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
            aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
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
                <li class="nav-item">
                    <a class="nav-link" href="#">Absențe</a>
                </li>
                <!-- Alte elemente de navigare -->
            </ul>
        </div>
    </nav>

    <!-- Conținutul paginii -->
    <div class="container mt-5">
        <div class="row justify-content-center">
            <div class="col-md-10">
                <h2 class="text-center">Vizualizare Absențe</h2>
                <?php
                $db = mysqli_connect("127.0.0.1", "root", "", "catalog");

                if (!$db) {
                    die("Conexiunea a eșuat: " . mysqli_connect_error());
                }

                $start = 0;
                $limit = 2;
                $id = 1;
                if (isset($_GET['id'])) {
                    $id = $_GET['id'];
                    $start = ($id - 1) * $limit;
                }

                $sql = "SELECT * FROM absente LIMIT $start, $limit";
                $result = mysqli_query($db, $sql);

                if (!$result) {
                    die('Interogare invalidă: ' . mysqli_error($db));
                } else {
                    echo "<table class=\"table table-striped\">";
                    echo "<thead><tr><th>Nume</th><th>Materie</th><th>Data Absenței</th><th>Tipul Absenței</th></tr></thead><tbody>";
                    while ($row = mysqli_fetch_assoc($result)) {
                        echo "<tr><td>" . $row["nume"] . "</td><td>" . $row["materie"] . "</td><td>" . $row["data_absenta"] . "</td><td>" . $row["tip_absenta"] . "</td></tr>";
                    }
                    echo "</tbody></table>";

                    $rows = mysqli_num_rows(mysqli_query($db, "SELECT * FROM absente"));
                    $total = ceil($rows / $limit);

                    echo "<nav aria-label='Page navigation'>";
                    echo "<ul class='pagination justify-content-center'>";
                    if ($id > 1) {
                        echo "<li class='page-item'><a class='page-link' href='?id=" . ($id - 1) . "'>Previous</a></li>";
                    }
                    for ($i = 1; $i <= $total; $i++) {
                        if ($i == $id) {
                            echo "<li class='page-item active'><span class='page-link'>" . $i . "</span></li>";
                        } else {
                            echo "<li class='page-item'><a class='page-link' href='?id=" . $i . "'>" . $i . "</a></li>";
                        }
                    }
                    if ($id != $total) {
                        echo "<li class='page-item'><a class='page-link' href='?id=" . ($id + 1) . "'>Next</a></li>";
                    }
                    echo "</ul>";
                    echo "</nav>";
                }

                mysqli_close($db);
                ?>
                <a href="operatii.html" class="btn btn-secondary mt-3">Înapoi la Operații</a>
            </div>
        </div>
    </div>
    <button id="goBackButton">Înapoi</button>

    <!-- Încarcă Bootstrap JS -->
    <script src="script.js"></script>
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>