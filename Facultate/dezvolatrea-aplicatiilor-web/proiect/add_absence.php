<!DOCTYPE HTML>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Adaugare Absența</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <link rel="stylesheet" href="css/app.css">
</head>

<body>
<div id="navbarPlaceholder"></div> <!-- Placeholder for the dynamic navbar -->
    <script src="dynamic_navbar.js"></script><br>

  <div class="container mt-5">
    <h2 class="mb-4">Adaugare Absența</h2>
    <form action="process_add_absence.php" method="post" enctype="multipart/form-data">
      <div class="form-row">
        <div class="form-group col-md-6">
          <label for="studentName">Nume:</label>
          <input type="text" class="form-control" id="studentName" name="studentName" required>
        </div>
        <div class="form-group col-md-6">
          <label for="subject">Materie:</label>
          <input type="text" class="form-control" id="subject" name="subject" required>
        </div>
        <div class="form-group col-md-6">
          <label for="absenceDate">Data Absenței:</label>
          <input type="date" class="form-control" id="absenceDate" name="absenceDate" required>
        </div>
        <div class="form-group col-md-6">
          <label for="absenceType">Tipul Absenței:</label>
          <select id="absenceType" class="form-control" name="absenceType" required>
            <option value="motivata">Motivata</option>
            <option value="nemotivata">Nemotivata</option>
          </select>
        </div>
        <div class="form-group col-md-12">
          <label for="fileUpload">Upload Document:</label>
          <input type="file" class="form-control-file" id="fileUpload" name="fileUpload">
          <small class="form-text text-muted">Optional. Choose a file to upload.</small>
        </div>
      </div>
      <button type="submit" class="btn btn-primary">Adauga Absența</button>
    </form>
  </div>
  <a href="operatii.html" class="btn btn-secondary mt-3 ml-3">Înapoi la Operații</a>

  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.4/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>
