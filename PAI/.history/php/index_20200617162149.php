<!DOCTYPE html>
<html>

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
<?php
    echo "<h1>Nasz system</h1>";
    echo "Login: <input name=\"login\"></input><br/>";
    echo "Hasło: <input name=\"passwd\"></input><br/>";
    echo "<button>zaloguj</button>";
    if (isSet(login)) {
        echo "alert($login)"
    }
?>
</body>

</html>