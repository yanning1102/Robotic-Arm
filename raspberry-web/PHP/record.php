<html>
<head>
<title>記錄</title>
<head/>

<body>
<?


 error_reporting(E_ALL);

 //echo "<h2>記錄物件放置情形</h2>\n";

 // 設定 Server IP address
 $address = "192.168.201.179";
 
 // 設定 Server Port
 $service_port = 10000;

 // 建立連線 socket (TCP)
 $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
 //echo "連線情形<br>";
 if ($socket === false)
 {
  //echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "<br>";
 }
 else
 {
  //echo "OK.<br>";
 // echo "-------------------------<br>";
  
 }

 // 連線至 Server
 //echo "Attempting to connect to $address on port $service_port...<br>";
 $result = socket_connect($socket, $address, $service_port);
 if ($result === false)
 {
 // echo "socket_connect() failed.<br>Reason: ($result) " . socket_strerror(socket_last_error($socket)) . "<br>";
 }
 else
 {
  //echo "OK.<br>";
//  echo "-----------------------------------------------------<br>";
  
 }

 // 傳送 request
 $request = "|  red  | orange | yellow | green |  blue  |  purple |";
// echo "  $request <br>";
 //echo "-----------------------------------------------------<br>";
 socket_write($socket, $request, strlen($request));

 // 接收 response
 $response = "";
 $response = socket_read($socket, 2048);
// echo " $response <br>";
 


// 使用 explode 函數拆分字符串
$numbers = explode("//", $response);

// 列印拆分後的數字
foreach ($numbers as $key => $number) {
    // 宣告獨立變數
    ${"var{$key}"} = $number;
}
 
 echo "<br>";
  echo "<br>";
//echo "esp32重開機才能清除<br>";
 // 關閉 socket
 //echo "Closing socket...";
 socket_close($socket);

?>
<h1 align="center">記錄</h1>
<table align="center" border="5" cellpadding="5" cellspacing="0" bordercolor="pink" width="700">
<tbody><tr>
	<th bgcolor="pink" colspan="6">記錄物件夾取數量</th><!--標題-->
</tr>

<tr>
<td align="center"><a>red</a></td>
<td align="center"><a>orange</a></td>
<td align="center"><a>yellow</a></td>
<td align="center"><a>green</a></td>
<td align="center"><a>blue</a></td>
<td align="center"><a>purple</a></td>
  
</tr>


<tr>
<td align="center"><a><?php echo $var0; ?></a></td>
<td align="center"><a><?php echo $var1; ?></a></td>
<td align="center"><a><?php echo $var2; ?></a></td>
<td align="center"><a><?php echo $var3; ?></a></td>
<td align="center"><a><?php echo $var4; ?></a></td>
<td align="center"><a><?php echo $var5; ?></a></td>

</tr>
</tbody>

</table>

<body/>

<html/>