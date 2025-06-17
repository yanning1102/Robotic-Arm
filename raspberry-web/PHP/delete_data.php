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
	
	$str = "delete from setting";
	$re1 = mysqli_query($link, $str);
	if ($re1)
		echo "資料 delete 成功";
	else	echo "資料 delete 失敗";


	mysqli_close($link);
?>

</body>
</html>
