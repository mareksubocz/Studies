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
	<link rel="stylesheet">
</head>
<body>
	<a href="form06_post.php">Nowy pracownik</a>
	<h1>Lista pracowników</h1>
	<?php
	if (isset($_SESSION['succeed'])) {
	    echo '<div class="succeed-message">';
	    echo $_SESSION['succeed'] ;
	    echo '</div>';
	    $_SESSION['succeed'] = null;
	}

	$sql = "SELECT * FROM pracownicy";
	$result = $link->query($sql);
	foreach ($result as $res) {
		echo $res["ID_PRAC"];
		echo $res["NAZWISKO"];
		echo "<br>";
	}
	$result->free();
	$link->close();
	?>
</body>
</html>

