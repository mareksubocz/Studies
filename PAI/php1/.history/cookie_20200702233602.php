<?php session_start(); ?>
<?php
    require_once("funkcje.php");
    if(isSet($_GET['utworzCookie'])){
        setcookie("cookie", "ciastko", time() +  $_GET["czas"], "/");
        setcookie("nazwa", "wartość", time() + (86400*30),"/");
        echo 'Utworzono cookie';
    }
?>
<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>

</body>

</html>