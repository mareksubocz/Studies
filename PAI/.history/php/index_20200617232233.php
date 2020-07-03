<!DOCTYPE html>
<html>

<form method="POST" action="index.php">

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="haslo"></input><br />
    <button name="zaloguj">zaloguj</button>
    <button name="inny">inny</button>
<?php
    require('funkcje.php');
    $login = test_input($_POST['login']);
    $haslo = test_input($_POST['haslo']);
    $zaloguj = test_input($_POST['zaloguj']);
    if(isSet($zaloguj)){
        echo "<p>Przesłany login: $login</p>";
        echo "<p>Przesłany hasło: $haslo</p>";
    }
?>
</body>

</html>