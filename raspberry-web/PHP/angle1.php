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
	
	$str = "CREATE TABLE angle1 (
		Sid int unsigned auto_increment primary key,
		team char(12),
		angle char(30))";
	$result = mysqli_query($link, $str);
	if ($result)
		echo "表格 angle1 建立成功";
	else	echo "表格 angle1 建立失敗";

	mysqli_close($link);
?>

</body>
</html>