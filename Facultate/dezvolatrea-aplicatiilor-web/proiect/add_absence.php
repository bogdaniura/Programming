</nav>
<!DOCTYPE HTML>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Adaugare Absența</title>
  <link rel="stylesheet" href="https://dhbhdrzi4tiry.cloudfront.net/cdn/sites/foundation.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/motion-ui@1.2.3/dist/motion-ui.min.css" />
  <link rel="stylesheet" href="css/app.css">
</head>

<body>
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
        <!-- Alte elemente de navigare -->
      </ul>
    </div>
    <h2>Adaugare Absența</h2>
    <div class="grid-container">
      <form action="process_add_absence.php" method="post" enctype="multipart/form-data">
        <div class="grid-x grid-padding-x">
          <div class="medium-6 cell">
            <label for="studentName">Nume:
              <input type="text" id="studentName" name="studentName" required>
            </label>
          </div>
          <div class="medium-6 cell">
            <label for="subject">Materie:
              <input type="text" id="subject" name="subject" required>
            </label>
          </div>
          <div class="medium-6 cell">
            <label for="absenceDate">Data Absenței:
              <input type="date" id="absenceDate" name="absenceDate" required>
            </label>
          </div>
          <div class="medium-6 cell">
            <label for="absenceType">Tipul Absenței:
              <select id="absenceType" name="absenceType" required>
                <option value="motivata">Motivata</option>
                <option value="nemotivata">Nemotivata</option>
              </select>
            </label>
          </div>
          <div class="medium-6 cell">
            <label for="fileUpload">Upload Document:
              <input type="file" id="fileUpload" name="fileUpload" required>
            </label>
          </div>
          <div class="medium-12 cell">
            <button type="submit" class="button">Adauga Absența</button>
          </div>
        </div>
      </form>
    </div>
    <a href="operatii.html" class="button">Înapoi la Operații</a>
    <script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
</body>

</html>