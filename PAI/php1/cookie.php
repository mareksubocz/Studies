<?php session_start(); ?>
<?php
    require_once("funkcje.php");
    if(isSet($_GET['utworzCookie'])){
        setcookie("nazwa", "słodką", time() + $_GET['czas'],"/");
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
<a href="index.php">wstecz</a><br/>
</body>

</html>