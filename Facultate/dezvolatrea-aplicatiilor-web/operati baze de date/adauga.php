<!DOCTYPE HTML>
<html>

<head>
  <meta charset="utf-8">
  <meta http-equiv="x-ua-compatible" content="ie=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Adaugare in BD</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>

<body>
  <div class="container mt-5">
    <div class="row justify-content-center">
      <div class="col-md-6">
        <h2 class="text-center mb-4">Adaugare in Baza de Date</h2>
        <form method="post">
          <div class="form-group">
            <label for="name">Nume:</label>
            <input type="text" class="form-control" id="name" name="name" required>
          </div>
          <div class="form-group">
            <label for="email">Email:</label>
            <input type="email" class="form-control" id="email" name="email" required>
          </div>
          <button type="submit" class="btn btn-primary">Adauga inregistrare</button>
        </form>
        <?php
        $db = mysqli_connect("127.0.0.1", "root", "");
        mysqli_select_db($db, "catalog");

        if ($_SERVER["REQUEST_METHOD"] == "POST") {
          $name = $_POST["name"];
          $email = $_POST["email"];

          // Validare email
          if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            echo '<div class="alert alert-danger mt-3" role="alert">Adresa de email introdusă nu este validă!</div>';
          } else {
            $sql = "INSERT INTO datepersoane (name, email) VALUES ('$name', '$email')";
            $results = mysqli_query($db, $sql);
            if (!$results) {
              die('Invalid query: ' . mysqli_error($db));
            } else {
              echo '<div class="alert alert-success mt-3" role="alert">Inregistrarea a fost adaugata cu succes!</div>';
            }
          }
        }
        ?>
        <a href="vizualizare.php" class="btn btn-secondary mt-3">Vizualizare</a>
        <a href="operatii.html" class="btn btn-secondary mt-3">Operatii</a>
      </div>
    </div>
  </div>

  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>