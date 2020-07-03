<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="password"></input><br />
    <button name="submit" type="submit" value="Submit">zaloguj</button>
<?php
    $login = $_POST['login'];
    $password = $_POST['password'];
    $submit = $_POST['submit'];
    if(isSet($login)){
        echo "<p>siemanko</p>";
    }
?>
</body>

</html>