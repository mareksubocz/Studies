<?php session_start(); ?>
<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <a href="index.php">Strona główna</a>
    <?php 
        require_once("funkcje.php");
        if(!(isset($_SESSION['zalogowany']) and $_SESSION['zalogowany'] == 1)){
            header("Location: index.php");
        }
        echo "<h3>Zalogowano</h3>"; 
        echo "Witaj, ";
        echo $_SESSION['zalogowanyImie'];
    ?>
    <form action="index.php" method="POST">
        <input type="submit" name="wyloguj" class='logout' value="Wyloguj"/>
    </form>
    
</body>

</html>