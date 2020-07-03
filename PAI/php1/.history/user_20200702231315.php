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
    <a href="index.php">Strona główna</a> <br>
    <form action="index.php" method="POST">
        <input type="submit" name="wyloguj" class='logout' value="Wyloguj"/>
    </form>
    
    <form action="user.php" method="POST" enctype="multipart/form-data">
    <div><input name="img" type="file" required/></div>
    <div><input type="submit" name="upload" value="Dodaj" /></div>
    </form>

</body>

</html>