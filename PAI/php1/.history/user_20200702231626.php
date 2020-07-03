<?php session_start(); ?>
<?php 
        // require_once("funkcje.php");
        if(!(isset($_SESSION['zalogowany']) and $_SESSION['zalogowany'] == 1)){
            header("Location: index.php");
        }
        if(isSet($_POST['upload'])){
            $currentDir = getcwd();
            $uploadDirectory = "/img/";
            $fileName = $_FILES['img']['name'];
            $fileSize = $_FILES['img']['size'];
            $fileTmpName = $_FILES['img']['tmp_name'];
            $fileType = $_FILES['img']['type'];
            if($fileName != "" and
                    ($fileType == 'image/png' or $fileType == 'image/jpeg'
                    or $fileType == 'image/JPEG' or $fileType == 'image/PNG'))
            {
                $uploadPath = $currentDir."\\".$fileName;
                if(move_uploaded_file($fileTmpName, $currentDir."\\".$fileName))
                echo "<div class ='alert'>Zdjecie zostalo zaladowane na serwer </div>";
            }
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
    <br>

    <form action="index.php" method="POST">
        <input type="submit" name="wyloguj" class='logout' value="Wyloguj"/>
    </form>
    

</body>

</html>