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
	
	$str = "CREATE TABLE aa (
		Sid int unsigned auto_increment primary key,
		team char(10),
		servo1 char(12),servo2 char(12),servo3 char(12),servo4 char(12),servo5 char(12),servo6 char(12))";
	$result = mysqli_query($link, $str);
	if ($result)
		echo "表格 aa 建立成功";
	else	echo "表格 aa 建立失敗";

	mysqli_close($link);
?>

</body>
</html>
