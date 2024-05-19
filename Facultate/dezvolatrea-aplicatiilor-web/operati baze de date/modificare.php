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
$id=$_GET['id'];

$sql="SELECT * FROM datepersoane where id=$id; "; 

$result= mysqli_query($db,$sql);
if (!$result)
 die('Invalid querry:' .mysqli_error($db));
$nr=$result->num_rows;

if ($nr==1)
{
$myrow=mysqli_fetch_array($result,MYSQLI_ASSOC);
echo "<form method=\"post\" action=\"modificare.php?id=".$id."\">";
echo "<div class=\"row\">";
echo "<div class=\"large-8 medium-8 small-12 columns\">";
echo "Nume:  <input type=\"text\" name=\"name\" value=".$myrow["name"]." >";
echo "Email: <input type=\"text\" name=\"email\" value=".$myrow["email"].">";
echo "</div>";
echo "<div class=\"large-8 medium-8 small-8 columns\">";
echo "<button type=\"submit\" class=\"success button\" name=\"btnSubmit\">Modifica</button>";
echo "</div>";
echo "</div>";
    
}
else
{
  echo "</br>Nu s-a gasit nici o inregistrare care sa corespunda acestui id!";
}

if (isset($_POST["btnSubmit"]))
{
  $nume=$_POST['name'];
  $email=$_POST['email'];
  
  $sql_upd="UPDATE datepersoane SET name='$nume', email ='$email' where id=$id;"; 
  
  echo "</br>";
  $result_upd= mysqli_query($db,$sql_upd);
  if (!$result_upd)
  die('Invalid querry:' .mysqli_error($db));
  else 
    echo "Inregistrarea a fost updatata.";
}
?>
</br>
<a href="vizualizare.php" class="button">Vizualizare</a></br>
<a href="operatii.html" class="button">Operatii</a>

<script src="js/vendor/jquery.js"></script>
    <script src="js/vendor/what-input.js"></script>
    <script src="js/vendor/foundation.js"></script>
    <script src="js/app.js"></script>
  </body>
</html>