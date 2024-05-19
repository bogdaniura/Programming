<!DOCTYPE HTML>  
<html>
 <head>
    <meta charset="utf-8">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Vizualizare</title>
    <link rel="stylesheet" href="https://dhbhdrzi4tiry.cloudfront.net/cdn/sites/foundation.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/motion-ui@1.2.3/dist/motion-ui.min.css" />
    <link rel="stylesheet" href="css/app.css">
  </head>
<body> 
<h2>Vizualizare</h2>
</br>

<?php
$db=mysqli_connect("127.0.0.1","root","");
mysqli_select_db($db,"curs");

$name = $email = "";
$start=0;
$limit=2;
$id=1;
if(isset($_GET['id']))
{
$id=$_GET['id'];
$start=($id-1)*$limit;
}

$sqlv="SELECT * FROM datepersoane LIMIT $start, $limit"; 

$resultv= mysqli_query($db,$sqlv);
 if (!$resultv)
 die('Invalid querry:' .mysqli_error($db));
 else 
 {
  echo "<table class=\"unstriped\">";
  echo "  <thead><tr><th width=\"200\"><b>Id</b></th><th width=\"150\"><b>Nume</b></th><th width=\"150\"><b>Email</b></th></tr></thead> <tbody>";
     while ($myrow=mysqli_fetch_array($resultv,MYSQLI_ASSOC))
     {echo "<tr><td>";
     echo $myrow["id"];
      echo "</td><td>";
      echo $myrow["name"];
      echo "</td><td>";
      echo $myrow["email"];
      echo "</td></tr>"; }
  echo " </tbody></table>";

$rows= mysqli_num_rows(mysqli_query($db,"SELECT * FROM datepersoane "));
$total=ceil($rows/$limit);

if($id>1)
{
echo "<a href='?id=".($id-1)."' class='button'>PREVIOUS </a>";
}

if($id!=$total)
{
echo "<a href='?id=".($id+1)."' class='button'> NEXT</a>";
}

echo "<ul class='page'>";
for($i=1;$i<=$total;$i++)
  {
    if($i==$id) 
      { echo "<li class='current'>".$i."</li>"; }
      else 
      { echo "<li><a href='?id=".$i."'>".$i."</a></li>"; }
  }
echo "</ul>";

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