<?php session_start(); ?>
<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <?php 
        require_once("funkcje.php");
        if(!isset($_SESSION['zalogowany']) or $_SESSION['zalogowany'] == 0){
            header("Location: index.php");
        }
        echo "Zalogowano"; 
    ?>
</body>

</html>