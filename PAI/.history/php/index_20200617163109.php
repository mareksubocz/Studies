<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="passwd"></input><br />
    <button name="submit">zaloguj</button>
<?php
    if(isSet($_POST["login"])){
        echo "siemanko"
    }
?>
</body>

</html>