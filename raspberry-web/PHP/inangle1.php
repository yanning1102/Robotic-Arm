<html>
<head>
</head>
<body>
<?
	echo "team.: ";
	echo $_POST['team'];
	echo "<br>";
	
	echo "angle1.: ";
	echo $_POST['angle1'];
	echo "<br>";
	
		echo "angle2.: ";
	echo $_POST['angle2'];
	echo "<br>";
	
		echo "angle3.: ";
	echo $_POST['angle3'];
	echo "<br>";
	
		echo "angle4.: ";
	echo $_POST['angle4'];
	echo "<br>";
	
		echo "angle5.: ";
	echo $_POST['angle5'];
	echo "<br>";
	
		echo "angle6.: ";
	echo $_POST['angle6'];
	echo "<br>";
	
	
	$team = $_POST['team'];
	$angle1 = $_POST['angle1'];
	$angle2 = $_POST['angle2'];
	$angle3 = $_POST['angle3'];
	$angle4 = $_POST['angle4'];
	$angle5 = $_POST['angle5'];
	$angle6 = $_POST['angle6'];
	
	$host = "localhost";
	$user = "test";
	$pass = "test";
	$link = mysqli_connect($host, $user, $pass);
	$result = mysqli_select_db($link, "test")
		or die("無法選取資料庫");
	echo "資料庫選取成功";
	
	$str = "insert into aa values(0, '$team','$angle1','$angle2','$angle3','$angle4','$angle5','$angle6')";
	$re1 = mysqli_query($link, $str);
	if ($re1)
		echo "資料加入成功";
	else	echo "資料加入失敗";

	mysqli_close($link);
?>

</body>
</html>