<html>
<head>
</head>
<body>

<?

//////tcp/ip
	error_reporting(E_ALL);

	echo "<h2>TCP/IP Connection</h2>\n";

	// 設定 Server IP address
	$address = "192.168.208.11";
	
	// 設定 Server Port
	$service_port = 10000;

	// 建立連線 socket (TCP)
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	if ($socket === false)
	{
		echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "<br>";
	}
	else
	{
		echo "OK.<br>";
	}

	// 連線至 Server
	echo "Attempting to connect to $address on port $service_port...<br>";
	$result = socket_connect($socket, $address, $service_port);
	if ($result === false)
	{
		echo "socket_connect() failed.<br>Reason: ($result) " . socket_strerror(socket_last_error($socket)) . "<br>";
	}
	else
	{
		echo "OK.<br>";
	}


//////tcp/ip end

//mariadb conn
	$host = "localhost";
	$user = "test";
	$pass = "test";
	$link = mysqli_connect($host, $user, $pass);
	$result = mysqli_select_db($link, "test")
		or die("無法選取資料庫");
	echo "資料庫選取成功<br/>";
	////conn end
	
	//////////抓資料

	
	$str = "select angle from angle1";
	$re = mysqli_query($link, $str);
	$pp = mysqli_fetch_array($re);
	echo "angle= " . $pp[0] . "<br>";
	mysqli_free_result($re);
	mysqli_close($link);
	
	////抓資料end
	
	// 傳送 request
          
	$request =sprintf("%s",$pp[0]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request . "]...<br>";
	socket_write($socket, $request, strlen($request));
	
/*	$request1 =sprintf("%s,%s",$pp1[0],$pp1[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request1 . "]...<br>";
	socket_write($socket, $request1, strlen($request1));
	
	$request2 =sprintf("%s,%s",$pp2[0],$pp2[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request2 . "]...<br>";
	socket_write($socket, $request2, strlen($request2));
	
	$request3 =sprintf("%s,%s",$pp3[0],$pp3[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request3 . "]...<br>";
	socket_write($socket, $request3, strlen($request3));
	
	$request4 =sprintf("%s,%s",$pp4[0],$pp4[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request4 . "]...<br>";
	socket_write($socket, $request4, strlen($request4));
	
	$request5 =sprintf("%s,%s",$pp5[0],$pp5[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request5 . "]...<br>";
	socket_write($socket, $request5, strlen($request5));
	*/
//傳送end
	

	// 接收 response
	$response = "";
	$response = socket_read($socket, 2048);
	echo "Response from server: [" . $response . "]<br>";
	
/*	$response1 = "";
	$response1 = socket_read($socket, 2048);
	echo "Response1 from server: [" . $response1 . "]<br>"; //esp32傳給rpi的資料 有幾個打幾個 超過兩筆會有問題 建議整理成一筆再一起傳過來
	
	$response2 = "";
	$response2 = socket_read($socket, 2048);
	echo "Response2 from server: [" . $response2 . "]<br>";
	
	$response3 = "";
	$response3 = socket_read($socket, 2048);
	echo "Response3 from server: [" . $response3 . "]<br>";
	
	$response4 = "";
	$response4 = socket_read($socket, 2048);
	echo "Response4 from server: [" . $response4 . "]<br>";
	
	$response5 = "";
	$response5 = socket_read($socket, 2048);
	echo "Response5 from server: [" . $response5 . "]<br>";
	*/
	
	
        //接收end
	// 關閉 socket
	echo "Closing socket...";
	socket_close($socket);
	

?>



</body>
</html>