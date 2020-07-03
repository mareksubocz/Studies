<?php session_start(); ?>
<?php

function alert($msg) {
    echo "<script type='text/javascript'>alert('$msg');</script>";
}

require('funkcje.php');
if(!isset($_SESSION['zalogowany'])){
	$_SESSION['zalogowany'] = 0;
}
if(isset($_POST['zaloguj'])){
    $login = test_input($_POST['login']);
    $haslo = test_input($_POST['haslo']);
    if($login == $osoba1->login and $haslo == $osoba1->haslo) {
        $_SESSION['zalogowanyImie'] = $osoba1->imieNazwisko;
        $_SESSION['zalogowany'] = 1;
        alert("adam");
    }
    if($login == $osoba2->login and $haslo == $osoba2->haslo) {
        $_SESSION['zalogowanyImie'] = $osoba2->imieNazwisko;
        $_SESSION['zalogowany'] = 1;
        alert("agata");
    }
    if($_SESSION['zalogowany'] == 1){
        header("Location: user.php");
    }else{
        header("Location: index.php");
    }
}
?>
