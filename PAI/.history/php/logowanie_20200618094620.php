<?php session_start();?>
<form method="POST" action="logowanie.php">
<?php 
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
?>