<?php session_start(); ?>
<html>
<head>
    <meta charset="utf-8"/>
    <link rel="stylesheet" href="style.css">
</head>

<body>
<div class='bimg'>
<div class='container'>
<div class='nav-button'>
<a href="form06_get.php">Lista pracowników</a>
</div>
<?php
    if (isset($_SESSION['failed'])) {
        echo '<div class="failed-message">';
        echo $_SESSION['failed'] ;
        echo '</div>';
        $_SESSION['failed'] = null;
    }
?>
<div class='adding-form'>
    <h1>Dodaj nową osobę</h1>
<form action="form06_redirect.php" method="POST">
    <span class=form-content>id_prac: <input type="text" name="id_prac"></span>
    <span class="form-content">nazwisko: <input type="text" name="nazwisko"></span>
    <span class="form-content"><input type="reset" value="Wyczysc"></span>
    <div><input type="submit" value="Wstaw"></div>
    
</form>
</div>
</div>
</div>
</body>
</html>