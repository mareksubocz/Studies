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
    Hasło: <input name="password"></input><br />
    <button name="sakdj">zaloguj</button>
<?php
    $login = $_POST['login'];
    $password = $_POST['password'];
    $submit = $_POST['submit'];
    if(isset($login)){
        echo "<p>siemanko</p>";
    }
?>
</body>

</html>