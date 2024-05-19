<!DOCTYPE HTML>  
<html>
 <head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Forme</title>
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
$SW=0;

if ((empty($_POST["name"]))&&(empty($_POST["email"]))) {
    $nameErr = "Este necesar sa introduceti adresa de mail sau numele.";
    echo $nameErr;
  } 

if ((empty($_POST["name"]))&&(!empty($_POST["email"])))
{
    $email = $_POST["email"];
    $sql="SELECT * FROM datepersoane where email='$email' "; 
    $SW=1;
}
if ((!empty($_POST["name"]))&&(empty($_POST["email"])))
{
    $name = $_POST["name"];
    $sql="SELECT * FROM datepersoane where name='$name' "; 
    $SW=1;
}
if ((!empty($_POST["name"]))&&(!empty($_POST["email"])))
{
    $email = $_POST["email"];
    $name = $_POST["name"];
    $sql="SELECT * FROM datepersoane where name='$name' and email='$email'; "; 
    $SW=1;
//    echo $sql;
}

if ($SW==1)
{
$result= mysqli_query($db,$sql);
$nr=$result->num_rows;

if (!$result)
 die('Invalid querry:' .mysqli_error($db));

if ($nr>0)
{
 {
  echo "<table class=\"unstriped\">";
  echo "<tr><thead><th width=\"200\"><b>Id</b></th><th width=\"150\"><b>Nume</b></th><th width=\"150\"><b>Email</b></th></thead></tr><tbody>";
     while ($myrow=mysqli_fetch_array($result,MYSQLI_ASSOC))
     {echo "<tr><td>";
     echo $myrow["id"];
      echo "</td><td>";
      echo $myrow["name"];
      echo "</td><td>";
      echo $myrow["email"];
      echo "</td></tr>"; }
  echo "</tbody></table>";
 }
}
else
{
  echo "</br>Nu s-a gasit nici o inregistrare care sa corespunda cautarii!";
}
}
?>
</br>
<a href="operatii.html" class="button">Operatii</a>

<script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
  </body>
</html>