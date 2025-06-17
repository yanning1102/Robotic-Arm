<html>
<head>
<title>Web</title>
</head>
<body>
<?
	$host = "localhost";		// 連線主機名稱
	$user = "test";		// MySQL 使用者名稱 
	$pass = "test";		// 使用者密碼
	$link = mysqli_connect($host, $user, $pass)
		or die("MySQL 連線失敗。");

	echo "連線成功。";
	mysqli_close($link);
?>


</body>
</html>
