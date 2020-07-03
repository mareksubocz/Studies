<?php
session_start(); 
$link = mysqli_connect("localhost", "scott", "tiger", "instytut");
if (!$link) {
    printf("Connect failed: %s\n", mysqli_connect_error());
    exit();
}
?>
<html>
<head>
	<meta charset="utf-8"/>
	<link rel="stylesheet" href="style.css">
</head>
<body>
	<div class='bimg'>
	<div class='container'>
	<div class='nav-button'>
	<a href="form06_post.php">Dodaj pracownika</a>
	</div>
		<h1>Lista pracowników</h1>
	<div class='employees-list-container'>
	<?php
	if (isset($_SESSION['succeed'])) {
	    echo '<div class="succeed-message">';
	    echo $_SESSION['succeed'] ;
	    echo '</div>';
	    $_SESSION['succeed'] = null;
	}

	$sql = "SELECT * FROM pracownicy";
	$result = $link->query($sql);
	echo "<div>";
	foreach ($result as $v) {
	    echo $v["ID_PRAC"] . " " . $v["NAZWISKO"] . "<br/>";
	}
	echo "</div>";
	$result->free();
	$link->close();
	?>

</div>
</div>
</body>
</html>

