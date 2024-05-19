<!DOCTYPE HTML>  
<html>
 <head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Adaugarea in BD</title>
    <link rel="stylesheet" href="https://dhbhdrzi4tiry.cloudfront.net/cdn/sites/foundation.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/motion-ui@1.2.3/dist/motion-ui.min.css" />
    <link rel="stylesheet" href="css/app.css">
  </head>

<body> 
</br>
</br>
</br>


<?php
$db=mysqli_connect("127.0.0.1","root","");
mysqli_select_db($db,"curs");
$name = $email = "";


if (empty($_POST["name"])) {
    $nameErr = "Este necesar sa introduceti numele.";
    echo $nameErr;
  } else {
    $name = $_POST["name"];
    $email = $_POST["email"];
    
$sql="INSERT INTO datepersoane (name,email) VALUES ('$name','$email')";
echo $sql;
echo "</br>";

$results= mysqli_query($db,$sql);
if (!$results)
 die('Invalid querry:' .mysqli_error($db));
 else 
 {
  echo "Inregistrarea a fost adaugata.</br>";
 }
}
?>

<a href="vizualizare.php" class="button">Vizualizare</a></br>
<a href="operatii.html" class="button">Operatii</a>

<script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>


</body>
</html>

