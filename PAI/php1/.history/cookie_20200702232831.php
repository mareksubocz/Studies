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
    if(isSet($_GET['utworzCookie'])){
        setcookie("cookie", "ciastko", time() +  $_GET["czas"], "/");
        echo 'Utworzono cookie';
    }
?>
</body>

</html>