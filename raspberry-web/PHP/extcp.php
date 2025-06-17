<html>
<head>
</head>
<body>

<?


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

 // 傳送 request
 $request = "Test for PHP";
 echo "Sending request to server: [" . $request . "]...<br>";
 socket_write($socket, $request, strlen($request));

 // 接收 response
 $response = "";
 $response = socket_read($socket, 2048);
 echo "Response from server: [" . $response . "]<br>";

 // 關閉 socket
 echo "Closing socket...";
 socket_close($socket);

?>



</body>
</html>