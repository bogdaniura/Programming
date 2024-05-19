<!DOCTYPE html>
<html lang="ro">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Adăugare Absență</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <link rel="stylesheet" href="styles.css">
  <link rel="stylesheet" href="styles2.css">
</head>

<body>
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

  <div class="container mt-5">
    <h2>Adăugare Absență</h2>
    <form action="process_add_absence.php" method="post">
      <div class="row">
        <div class="col-md-6">
          <div class="form-group">
            <label for="studentName">Nume:</label>
            <input type="text" class="form-control" id="studentName" name="studentName" required>
          </div>
        </div>
        <div class="col-md-6">
          <div class="form-group">
            <label for="subject">Materie:</label>
            <input type="text" class="form-control" id="subject" name="subject" required>
          </div>
        </div>
        <div class="col-md-6">
          <div class="form-group">
            <label for="absenceDate">Data Absenței:</label>
            <input type="date" class="form-control" id="absenceDate" name="absenceDate" required>
          </div>
        </div>
        <div class="col-md-6">
          <div class="form-group">
            <label for="absenceType">Tipul Absenței:</label>
            <select class="form-control" id="absenceType" name="absenceType" required>
              <option value="motivata">Motivată</option>
              <option value="nemotivata">Nemotivată</option>
            </select>
          </div>
        </div>
        <div class="col-md-12">
          <button type="submit" class="btn btn-primary">Adaugă Absența</button>
        </div>
      </div>
    </form>
  </div>
  <button id="goBackButton">Înapoi</button>

  <script src="script.js"></script>
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>
