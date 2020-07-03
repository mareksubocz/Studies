<?php session_start();?>
<!DOCTYPE html>

<html>

<form method="POST" action="index.php">

<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>

<body>
<?php
    require('funkcje.php');
    $login = test_input($_POST['login']);
    $haslo = test_input($_POST['haslo']);
    $zaloguj = test_input($_POST['zaloguj']);
    if(isSet($zaloguj)){
        // echo "<p>Przesłany login: $login</p>";
        // echo "<p>Przesłany hasło: $haslo</p>";
        if($login == $osoba1->login && $haslo == $osoba1->haslo){
            $_SESSION["zalogowanyImie"] = $osoba1->imieNazwisko;
            $_SESSION["zalogowany"] = 1;
            header("Location: user.php");
        }
        else if($login == $osoba2->login && $haslo == $osoba2->haslo){
            $_SESSION["zalogowanyImie"] = $osoba2->imieNazwisko;
            $_SESSION["zalogowany"] = 1;
            header("Location: user.php");
        }
        else{
            header("Location: index.php");
        }
    }
?>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="haslo"></input><br />
    <button name="zaloguj">zaloguj</button>
    <button name="inny">inny</button>
</body>

</html>