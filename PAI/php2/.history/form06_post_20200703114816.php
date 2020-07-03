<?php session_start(); ?>
<html>
<head>
    <meta charset="utf-8"/>
</head>

<body>
<a href="form06_get.php">Lista pracowników</a>
<!-- <?php
    if (isset($_SESSION['failed'])) {
        echo $_SESSION['failed'] ;
        echo '</div>';
        $_SESSION['failed'] = null;
    }
?> -->
<div class='adding-form'>
    <h1>Dodaj nową osobę</h1>
<form action="form06_redirect.php" method="POST">
    id_prac: <input type="text" name="id_prac">
    nazwisko: <input type="text" name="nazwisko">
    <input type="reset" value="Wyczysc">
    <input type="submit" value="Wstaw">
</form>
</body>
</html>