<?php session_start();?>
<form method="POST" action="index.php">
    <?php require('funkcje.php');
    $login = test_input($_POST['login']);
    $haslo = test_input($_POST['haslo']);
    $zaloguj = $_POST['zaloguj'];
    if(isSet($zaloguj)){
        if($login == $osoba1->login && $haslo == $osoba1->haslo){
            $_SESSION["zalogowanyImie"] = $osoba1->imieNazwisko;
            $_SESSION["zalogowany"] = 1;
            header("location: user.php");
        }
        else if($login == $osoba2->login && $haslo == $osoba2->haslo){
            $_SESSION["zalogowanyImie"] = $osoba2->imieNazwisko;
            $_SESSION["zalogowany"] = 1;
            header("location: user.php");
        }
        else{
            header("location: index.php");
        }
    }
    ?>

<!DOCTYPE html>
<html>
<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>
<body>
    <h1>Nasz system</h1>
    Login: <input name="login"></input><br />
    Hasło: <input name="haslo"></input><br />
    <button name="zaloguj">zaloguj</button>
</body>
</html>