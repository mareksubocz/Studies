<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
<?php
    $login = "<input></input>";
    $passwd = "<input></input>";
    echo "<h1>Nasz system</h1>";
    echo "Login: $login<br/>";
    echo "Hasło: $passwd<br/>";
    echo "<button>zaloguj</button>";
    if (isSet($_POST["login"])){
        echo "mamy zmienną $login";
    }
?>
</body>

</html>