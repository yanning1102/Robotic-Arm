<html>
<head>
</head>
<body>
<?
	echo "enteam: ";
	echo $_POST['enteam'];
	echo "<br>";
	
	echo "fb: ";
	echo $_POST['fb'];
	echo "<br>";
	
	echo "step: ";
	echo $_POST['ss'];
	echo "<br>";
	
	$enteam= $_POST['enteam'];
	$fb = $_POST['fb'];
	$ss = $_POST['ss'];
	
	
	$host = "localhost";
	$user = "test";
	$pass = "test";
	$link = mysqli_connect($host, $user, $pass);
	$result = mysqli_select_db($link, "test")
		or die("無法選取資料庫");
	echo "資料庫選取成功";
	
	
	mysqli_query($link, "ALTER TABLE ins AUTO_INCREMENT = 1");  //使sid固定從1開始
	
	$str = "insert into ins values(0, '$enteam', '$fb', '$ss')";
	$re1 = mysqli_query($link, $str);
	if ($re1)
		echo "資料加入成功";
	else	echo "資料加入失敗";

	mysqli_close($link);
?>

</body>
</html>