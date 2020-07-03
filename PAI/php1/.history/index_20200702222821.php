<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <h1>Nasz systemm</h1>
    Login: <input type="text" name="login"/> <br>
    Hasło: <input type="password" name="haslo"/> <br>
    <button type="submit" value="zaloguj" name="zaloguj">Zaloguj</button>

    <?php
        if(isset($_POST['zaloguj'])){
            $login = test_input($_POST['login']);
            $haslo = test_input($_POST['haslo']);
            echo "no elo";
            echo $login;
            echo $haslo;
        }
    ?>
</body>

</html>