<?php session_start();?>
<!-- <!DOCTYPE html> -->
<!-- <html> -->
<form method="POST" action="index.php">
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
    require_once('logowanie.php');
    print('<h1>Nasz system</h1>');
    print('Login: <input name="login"></input><br />');
    print('Hasło: <input name="haslo"></input><br />');
    print('<button name="zaloguj">zaloguj</button>');
?>
<!-- </body> -->
<!-- </html> -->