<?php session_start(); ?>
<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <?php
			if(isset($_POST['wyloguj'])){
				$_SESSION['zalogowany'] = 0;
				$_SESSION['zalogowanyImie'] = "";
		}
    ?>
    
    <a href="user.php">Konto użytkownika</a>
    <form action="logowanie.php" method="POST">
    <h1>Nasz system</h1>
    Login: <input type="text" name="login"/> <br>
    Hasło: <input type="password" name="haslo"/> <br>
    <input type="submit" value="Zaloguj" name="zaloguj">
    </form>

    <br><br>
    <form action="cookie.php" method="GET">
    Czas trwania ciasteczka w sekundach: <input type="number" name="czas" value=0 min=0 required><br>
	<input type="submit" value="Utwórz ciasteczko" name="utworzCookie">
	</form>

    <!-- <?php
			
		?> -->
    <?php
        require('funkcje.php');
        if(isset($_POST['zaloguj'])){
            $login = test_input($_POST['login']);
            $haslo = test_input($_POST['haslo']);
        }

        if(isset($_COOKIE['nazwa'])){
            echo "Wartość Cookie: " . $_COOKIE['cookie'];
        }
    ?>

</body>

</html>