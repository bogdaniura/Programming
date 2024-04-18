<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rezultat Formular</title>
</head>

<body>
    <h2>Rezultatul formularului:</h2>
    <?php
    $nume = $_GET['nume'];
    $email = $_GET['email'];
    $telefon = $_GET['telefon'];
    $gen = $_GET['gen'];
    $interese = isset($_GET['interese']) ? $_GET['interese'] : [];
    $descriere = $_GET['descriere'];
    $oras = $_GET['oras'];

    echo "<p>Nume: $nume</p>";
    echo "<p>Email: $email</p>";
    echo "<p>Telefon: $telefon</p>";
    echo "<p>Gen: $gen</p>";
    echo "<p>Interese: " . implode(", ", $interese) . "</p>";    
    echo "<p>Descriere: $descriere</p>";
    echo "<p>Oraș: $oras</p>";

    ?>
</body>

</html>