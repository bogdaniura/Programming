<!DOCTYPE HTML>  
<html>
 <head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stergere</title>
    <link rel="stylesheet" href="css/foundation.css">
    <link rel="stylesheet" href="css/app.css">
  </head>
<body> 
</br>
</br>
</br>

<?php
$db=mysqli_connect("127.0.0.1","root","");
mysqli_select_db($db,"curs");

$email = "";
  if (empty($_POST["email"])) {
    $nameErr = "Este necesar sa introduceti email.";
    echo $nameErr;
  } else {
    $email = $_POST["email"];
  $result= mysqli_query($db,"CALL stergere('$email')");
if (!$result)
 die('Invalid querry:' .mysqli_error($db));
 else 
 {
    echo "   Daca exista o inregistrare cu adresa de email ".$email." , atunci aceasta a fost stearsa";
 }
}

?>
</br>
</br>

<a href="vizualizare.php" class="button">Vizualizare</a></br>
<a href="operatii.html" class="button">Operatii</a>

<script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
  </body>
</html>