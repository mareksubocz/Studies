<?php session_start(); ?>
<?php 
        // require_once("funkcje.php");
        if(!(isset($_SESSION['zalogowany']) and $_SESSION['zalogowany'] == 1)){
            header("Location: index.php");
        }
?>
<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <?php 
        echo "<h3>Zalogowano</h3>"; 
        echo "Witaj, ";
        echo $_SESSION['zalogowanyImie'];
    ?>    
    <br> <a href="index.php">Strona główna</a> <br><br>
    
    <form action="user.php" method="POST" enctype="multipart/form-data">
    <input name="img" type="file" required/><br>
    <input type="submit" name="upload" value="Dodaj" />
    </form>

    <form action="index.php" method="POST">
        <input type="submit" name="wyloguj" class='logout' value="Wyloguj"/>
    </form>
    

</body>

</html>