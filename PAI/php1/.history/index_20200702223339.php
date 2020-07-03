<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
	<form action="index.php" method="POST">
    <h1>Nasz system</h1>
    Login: <input type="text" name="login"/> <br>
    Hasło: <input type="password" name="haslo"/> <br>
    <input type="submit" value="Zaloguj" name="zaloguj">

    <?php
        require('funkcje.php');
        if(isset($_POST['zaloguj'])){
            $login = $_POST['login'];
            $haslo = $_POST['haslo'];
            echo $login;
            echo $haslo;
        }
    ?>
</body>

</html>