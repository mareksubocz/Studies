<?php session_start();?>
<!-- <!DOCTYPE html> -->
<!-- <html> -->
<!-- <form method="POST" action="index.php"> -->
<!-- 
<head>
    <title>PHP</title>
    <meta charset='UTF-8' />
</head>
<body> -->
<?php require('funkcje.php');
    $login = test_input($_POST['login']);
    $haslo = test_input($_POST['haslo']);
    $zaloguj = $_POST['zaloguj'];
    if(isSet($zaloguj)){
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
    print('<h1>Nasz system</h1>')
    print('Login: <input name="login"></input><br />')
    print('Hasło: <input name="haslo"></input><br />')
    print('<button name="zaloguj">zaloguj</button>')
?>
<!-- </body> -->
<!-- </html> -->