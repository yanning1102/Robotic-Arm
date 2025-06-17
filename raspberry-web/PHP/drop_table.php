<html>
<head>
</head>
<body>
Create table...<p>

<?
	$host = "localhost";
	$user = "test";
	$pass = "test";
	$link = mysqli_connect($host, $user, $pass);
	$result = mysqli_select_db($link, "test")
		or die("無法選取資料庫");
	echo "資料庫選取成功";
	
	$str = "drop table angle1";
	$result = mysqli_query($link, $str);
	if ($result)
		echo "表格 test1 drop 成功";
	else	echo "表格 test1 drop 失敗";

	mysqli_close($link);
?>

</body>
</html>
