<html>
<head>
</head>
<body>
<?
	echo "Color.: ";
	echo $_POST['color'];
	echo "<br>";
	
	echo "Seat.: ";
	echo $_POST['seat'];
	echo "<br>";
	
	$color = $_POST['color'];
	$seat = $_POST['seat'];
	
	$host = "localhost";
	$user = "test";
	$pass = "test";
	$link = mysqli_connect($host, $user, $pass);
	$result = mysqli_select_db($link, "test")
		or die("無法選取資料庫");
	echo "資料庫選取成功";
	
	$str = "insert into setting values(0, '$color', '$seat')";
	$re1 = mysqli_query($link, $str);
	if ($re1)
		echo "資料加入成功";
	else	echo "資料加入失敗";

	mysqli_close($link);
?>

</body>
</html>
