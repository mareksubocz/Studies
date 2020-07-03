<!DOCTYPE html>
<html>

<form method="post" action="index.php">

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="haslo"></input><br />
    <button name="zaloguj">zaloguj</button>
<?php
    $login = $_POST['login'];
    $haslo = $_POST['haslo'];
    $zaloguj = $_POST['zaloguj'];
    if(isset($login)){
        echo "<p>siemanko</p>";
    }
?>
</body>

</html>