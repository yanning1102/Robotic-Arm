<html>
<head>
</head>
<body>

<?

//////tcp/ip
	error_reporting(E_ALL);

	echo "<h2>TCP/IP Connection</h2>\n";

	// 設定 Server IP address
	$address = "192.168.201.179";
	
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
	echo "|";
	echo "color";
	echo "||";
	echo "seat";
	echo "|";
	echo "<br/>";
	
	$str = "select color,seat from setting where color= 'red' ";
	$re = mysqli_query($link, $str);
	$pp = mysqli_fetch_array($re);
	echo "color= " . $pp[0] . "<br>";
	echo "seat= " . $pp[1] . "<br>";
	mysqli_free_result($re);
	//mysqli_close($link);
	
	$str1 = "select color,seat from setting where color= 'orange' ";
	$re1 = mysqli_query($link, $str1);
	$pp1 = mysqli_fetch_array($re1);
	echo "color= " . $pp1[0] . "<br>";
	echo "seat= " . $pp1[1] . "<br>";
	mysqli_free_result($re1);
	
	
	
	$str2 = "select color,seat from setting where color= 'yellow' ";
	$re2 = mysqli_query($link, $str2);
	$pp2 = mysqli_fetch_array($re2);
	echo "color= " . $pp2[0] . "<br>";
	echo "seat= " . $pp2[1] . "<br>";
	mysqli_free_result($re2);
	
	$str3 = "select color,seat from setting where color= 'green' ";
	$re3 = mysqli_query($link, $str3);
	$pp3 = mysqli_fetch_array($re3);
	echo "color= " . $pp3[0] . "<br>";
	echo "seat= " . $pp3[1] . "<br>";
	mysqli_free_result($re3);
	
	$str4 = "select color,seat from setting where color= 'blue' ";
	$re4 = mysqli_query($link, $str4);
	$pp4 = mysqli_fetch_array($re4);
	echo "color= " . $pp4[0] . "<br>";
	echo "seat= " . $pp4[1] . "<br>";
	mysqli_free_result($re4);
	
	$str5 = "select color,seat from setting where color= 'purple' ";
	$re5 = mysqli_query($link, $str5);
	$pp5 = mysqli_fetch_array($re5);
	echo "color= " . $pp5[0] . "<br>";
	echo "seat= " . $pp5[1] . "<br>";
	mysqli_free_result($re5);
	echo "<br>";
	
	$sta1 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '1' ";
	$ra1 = mysqli_query($link, $sta1);
	$pa1 = mysqli_fetch_array($ra1);
	echo "team= " . $pa1[0] . "<br>";
	echo "angle1= " . $pa1[1] . "<br>";
	echo "angle2= " . $pa1[2] . "<br>";
	echo "angle3= " . $pa1[3] . "<br>";
	echo "angle4= " . $pa1[4] . "<br>";
	echo "angle5= " . $pa1[5] . "<br>";
	echo "angle6= " . $pa1[6] . "<br>";
	mysqli_free_result($ra1);
	echo "<br>";
	if($pa1[0]==0){
	$pa1[1]=500;
	$pa1[2]=500;
	$pa1[3]=500;
	$pa1[4]=500;
	$pa1[5]=500;
	$pa1[6]=500;
	}
	
	$sta2 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '2'";
	$ra2 = mysqli_query($link, $sta2);
	$pa2 = mysqli_fetch_array($ra2);
	echo "team= " . $pa2[0] . "<br>";
	echo "angle1= " . $pa2[1] . "<br>";
	echo "angle2= " . $pa2[2] . "<br>";
	echo "angle3= " . $pa2[3] . "<br>";
	echo "angle4= " . $pa2[4] . "<br>";
	echo "angle5= " . $pa2[5] . "<br>";
	echo "angle6= " . $pa2[6] . "<br>";
	mysqli_free_result($ra2);
	echo "<br>";
	if($pa2[0]==0){
	$pa2[1]=500;
	$pa2[2]=500;
	$pa2[3]=500;
	$pa2[4]=500;
	$pa2[5]=500;
	$pa2[6]=500;	
		
	}
	
	$sta3 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '3'";
	$ra3 = mysqli_query($link, $sta3);
	$pa3 = mysqli_fetch_array($ra3);
	echo "team= " . $pa3[0] . "<br>";
	echo "angle1= " . $pa3[1] . "<br>";
	echo "angle2= " . $pa3[2] . "<br>";
	echo "angle3= " . $pa3[3] . "<br>";
	echo "angle4= " . $pa3[4] . "<br>";
	echo "angle5= " . $pa3[5] . "<br>";
	echo "angle6= " . $pa3[6] . "<br>";
	mysqli_free_result($ra3);
	echo "<br>";
	if($pa3[0]==0){
	$pa3[1]=500;
	$pa3[2]=500;
	$pa3[3]=500;
	$pa3[4]=500;
	$pa3[5]=500;
	$pa3[6]=500;	
		
	}
	$sta4 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '4'";
	$ra4 = mysqli_query($link, $sta4);
	$pa4 = mysqli_fetch_array($ra4);
	echo "team= " . $pa4[0] . "<br>";
	echo "angle1= " . $pa4[1] . "<br>";
	echo "angle2= " . $pa4[2] . "<br>";
	echo "angle3= " . $pa4[3] . "<br>";
	echo "angle4= " . $pa4[4] . "<br>";
	echo "angle5= " . $pa4[5] . "<br>";
	echo "angle6= " . $pa4[6] . "<br>";
	mysqli_free_result($ra4);
	echo "<br>";
	if($pa4[0]==0){
	$pa4[1]=500;
	$pa4[2]=500;
	$pa4[3]=500;
	$pa4[4]=500;
	$pa4[5]=500;
	$pa4[6]=500;	
		
	}
	$sta5 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '5'";
	$ra5 = mysqli_query($link, $sta5);
	$pa5 = mysqli_fetch_array($ra5);
	echo "team= " . $pa5[0] . "<br>";
	echo "angle1= " . $pa5[1] . "<br>";
	echo "angle2= " . $pa5[2] . "<br>";
	echo "angle3= " . $pa5[3] . "<br>";
	echo "angle4= " . $pa5[4] . "<br>";
	echo "angle5= " . $pa5[5] . "<br>";
	echo "angle6= " . $pa5[6] . "<br>";
	mysqli_free_result($ra5);
	echo "<br>";
	if($pa5[0]==0){
	$pa5[1]=500;
	$pa5[2]=500;
	$pa5[3]=500;
	$pa5[4]=500;
	$pa5[5]=500;
	$pa5[6]=500;	
		
	}
	$sta6 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '6'";
	$ra6 = mysqli_query($link, $sta6);
	$pa6 = mysqli_fetch_array($ra6);
	echo "team= " . $pa6[0] . "<br>";
	echo "angle1= " . $pa6[1] . "<br>";
	echo "angle2= " . $pa6[2] . "<br>";
	echo "angle3= " . $pa6[3] . "<br>";
	echo "angle4= " . $pa6[4] . "<br>";
	echo "angle5= " . $pa6[5] . "<br>";
	echo "angle6= " . $pa6[6] . "<br>";
	mysqli_free_result($ra6);
	echo "<br>";
	if($pa6[0]==0){
	$pa6[1]=500;
	$pa6[2]=500;
	$pa6[3]=500;
	$pa6[4]=500;
	$pa6[5]=500;
	$pa6[6]=500;	
		
	}
	$sta7 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '7'";
	$ra7 = mysqli_query($link, $sta7);
	$pa7 = mysqli_fetch_array($ra7);
	echo "team= " . $pa7[0] . "<br>";
	echo "angle1= " . $pa7[1] . "<br>";
	echo "angle2= " . $pa7[2] . "<br>";
	echo "angle3= " . $pa7[3] . "<br>";
	echo "angle4= " . $pa7[4] . "<br>";
	echo "angle5= " . $pa7[5] . "<br>";
	echo "angle6= " . $pa7[6] . "<br>";
	mysqli_free_result($ra7);
	echo "<br>";
	if($pa7[0]==0){
	$pa7[1]=500;
	$pa7[2]=500;
	$pa7[3]=500;
	$pa7[4]=500;
	$pa7[5]=500;
	$pa7[6]=500;	
	}
	$sta8 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '8'";
	$ra8 = mysqli_query($link, $sta8);
	$pa8 = mysqli_fetch_array($ra8);
	echo "team= " . $pa8[0] . "<br>";
	echo "angle1= " . $pa8[1] . "<br>";
	echo "angle2= " . $pa8[2] . "<br>";
	echo "angle3= " . $pa8[3] . "<br>";
	echo "angle4= " . $pa8[4] . "<br>";
	echo "angle5= " . $pa8[5] . "<br>";
	echo "angle6= " . $pa8[6] . "<br>";
	mysqli_free_result($ra8);
	echo "<br>";
	if($pa8[0]==0){
	$pa8[1]=500;
	$pa8[2]=500;
	$pa8[3]=500;
	$pa8[4]=500;
	$pa8[5]=500;
	$pa8[6]=500;	
	}
	$sta9 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '9'";
	$ra9 = mysqli_query($link, $sta9);
	$pa9 = mysqli_fetch_array($ra9);
	echo "team= " . $pa9[0] . "<br>";
	echo "angle1= " . $pa9[1] . "<br>";
	echo "angle2= " . $pa9[2] . "<br>";
	echo "angle3= " . $pa9[3] . "<br>";
	echo "angle4= " . $pa9[4] . "<br>";
	echo "angle5= " . $pa9[5] . "<br>";
	echo "angle6= " . $pa9[6] . "<br>";
	mysqli_free_result($ra9);
	echo "<br>";
	if($pa9[0]==0){
	$pa9[1]=500;
	$pa9[2]=500;
	$pa9[3]=500;
	$pa9[4]=500;
	$pa9[5]=500;
	$pa9[6]=500;	
		
	}
	$sta10 = "select team,servo1,servo2,servo3,servo4,servo5,servo6 from aa where team= '10'";
	$ra10 = mysqli_query($link, $sta10);
	$pa10 = mysqli_fetch_array($ra10);
	echo "team= " . $pa10[0] . "<br>";
	echo "angle1= " . $pa10[1] . "<br>";
	echo "angle2= " . $pa10[2] . "<br>";
	echo "angle3= " . $pa10[3] . "<br>";
	echo "angle4= " . $pa10[4] . "<br>";
	echo "angle5= " . $pa10[5] . "<br>";
	echo "angle6= " . $pa10[6] . "<br>";
	mysqli_free_result($ra10);
echo "<br>";
	if($pa10[0]==0){
	$pa10[1]=500;
	$pa10[2]=500;
	$pa10[3]=500;
	$pa10[4]=500;
	$pa10[5]=500;
	$pa10[6]=500;	
	}
	
	$sts1 = "select enteam,fb,step from ins where Sid= '1'";
	$rs1 = mysqli_query($link, $sts1);
	$ps1 = mysqli_fetch_array($rs1);
	echo "enteam= " . $ps1[0] . "<br>";
	echo "fb= " . $ps1[1] . "<br>";
	echo "ss= " . $ps1[2] . "<br>";
	mysqli_free_result($rs1);
echo "<br>";

	$sts2 = "select enteam,fb,step from ins where Sid= '2'";
	$rs2 = mysqli_query($link, $sts2);
	$ps2 = mysqli_fetch_array($rs2);
	echo "enteam= " . $ps2[0] . "<br>";
	echo "fb= " . $ps2[1] . "<br>";
	echo "ss= " . $ps2[2] . "<br>";
	mysqli_free_result($rs2);
echo "<br>";

	$sts3 = "select enteam,fb,step from ins where Sid= '3'";
	$rs3= mysqli_query($link, $sts3);
	$ps3 = mysqli_fetch_array($rs3);
	echo "enteam= " . $ps3[0] . "<br>";
	echo "fb= " . $ps3[1] . "<br>";
	echo "ss= " . $ps3[2] . "<br>";
	mysqli_free_result($rs3);
echo "<br>";

	$sts4 = "select enteam,fb,step from ins where Sid= '4'";
	$rs4 = mysqli_query($link, $sts4);
	$ps4 = mysqli_fetch_array($rs4);
	echo "enteam= " . $ps4[0] . "<br>";
	echo "fb= " . $ps4[1] . "<br>";
	echo "ss= " . $ps4[2] . "<br>";
	mysqli_free_result($rs4);
echo "<br>";

	$sts5 = "select enteam,fb,step from ins where Sid= '5'";
	$rs5= mysqli_query($link, $sts5);
	$ps5 = mysqli_fetch_array($rs5);
	echo "enteam= " . $ps5[0] . "<br>";
	echo "fb= " . $ps5[1] . "<br>";
	echo "ss= " . $ps5[2] . "<br>";
	mysqli_free_result($rs5);
echo "<br>";

	$sts6 = "select enteam,fb,step from ins where Sid= '6'";
	$rs6= mysqli_query($link, $sts6);
	$ps6 = mysqli_fetch_array($rs6);
	echo "enteam= " . $ps6[0] . "<br>";
	echo "fb= " . $ps6[1] . "<br>";
	echo "ss= " . $ps6[2] . "<br>";
	mysqli_free_result($rs6);
echo "<br>";

	$sts7 = "select enteam,fb,step from ins where Sid= '7'";
	$rs7= mysqli_query($link, $sts7);
	$ps7 = mysqli_fetch_array($rs7);
	echo "enteam= " . $ps7[0] . "<br>";
	echo "fb= " . $ps7[1] . "<br>";
	echo "ss= " . $ps7[2] . "<br>";
	mysqli_free_result($rs7);
echo "<br>";

	$sts8 = "select enteam,fb,step from ins where Sid= '8'";
	$rs8= mysqli_query($link, $sts8);
	$ps8 = mysqli_fetch_array($rs8);
	echo "enteam= " . $ps8[0] . "<br>";
	echo "fb= " . $ps8[1] . "<br>";
	echo "ss= " . $ps8[2] . "<br>";
	mysqli_free_result($rs8);
echo "<br>";

	$sts9 = "select enteam,fb,step from ins where Sid= '9'";
	$rs9= mysqli_query($link, $sts9);
	$ps9 = mysqli_fetch_array($rs9);
	echo "enteam= " . $ps9[0] . "<br>";
	echo "fb= " . $ps9[1] . "<br>";
	echo "ss= " . $ps9[2] . "<br>";
	mysqli_free_result($rs9);
echo "<br>";

	$sts10 = "select enteam,fb,step from ins where Sid= '10'";
	$rs10= mysqli_query($link, $sts10);
	$ps10 = mysqli_fetch_array($rs10);
	echo "enteam= " . $ps10[0] . "<br>";
	echo "fb= " . $ps10[1] . "<br>";
	echo "ss= " . $ps10[2] . "<br>";
	mysqli_free_result($rs10);
echo "<br>";


	mysqli_close($link);//只要關一次就好
	


	////抓資料end
	
	// 傳送 request
          
	$request =sprintf("%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//
	%s//%s//%s//",
	$pp[1],$pp1[1],$pp2[1],$pp3[1],$pp4[1],$pp5[1],
	$pa1[1],$pa1[2],$pa1[3],$pa1[4],$pa1[5],$pa1[6],
	$pa2[1],$pa2[2],$pa2[3],$pa2[4],$pa2[5],$pa2[6],
	$pa3[1],$pa3[2],$pa3[3],$pa3[4],$pa3[5],$pa3[6],
	$pa4[1],$pa4[2],$pa4[3],$pa4[4],$pa4[5],$pa4[6],
	$pa5[1],$pa5[2],$pa5[3],$pa5[4],$pa5[5],$pa5[6],
	$pa6[1],$pa6[2],$pa6[3],$pa6[4],$pa6[5],$pa6[6],
	$pa7[1],$pa7[2],$pa7[3],$pa7[4],$pa7[5],$pa7[6],
	$pa8[1],$pa8[2],$pa8[3],$pa8[4],$pa8[5],$pa8[6],
	$pa9[1],$pa9[2],$pa9[3],$pa9[4],$pa9[5],$pa9[6],
	$pa10[1],$pa10[2],$pa10[3],$pa10[4],$pa10[5],$pa10[6],
	$ps1[0],$ps1[1],$ps1[2],
	$ps2[0],$ps2[1],$ps2[2],
	$ps3[0],$ps3[1],$ps3[2],
	$ps4[0],$ps4[1],$ps4[2],
	$ps5[0],$ps5[1],$ps5[2],
	$ps6[0],$ps6[1],$ps6[2],
	$ps7[0],$ps7[1],$ps7[2],
	$ps8[0],$ps8[1],$ps8[2],
	$ps9[0],$ps9[1],$ps9[2],
	$ps10[0],$ps10[1],$ps10[2]);
	//$request="test from rpi";
	echo strlen($request);
	echo "Sending request to server: [" . $request . "]...<br>";
	socket_write($socket, $request, strlen($request));
	
/*	$request1 =sprintf("%s,%s",$pp1[0],$pp1[1]);
	//$request="test from rpi";
	echo "Sending request to server: [" . $request1 . "]...<br>";
	socket_write($socket, $request1, strlen($request1));

	*/
//傳送end
	

	// 接收 response
	//$response = "";
	//$response = socket_read($socket, 2048);
	//echo "Response from server: [" . $response . "]<br>";
	
/*	$response1 = "";
	$response1 = socket_read($socket, 2048);
	echo "Response1 from server: [" . $response1 . "]<br>"; //esp32傳給rpi的資料 有幾個打幾個 超過兩筆會有問題 建議整理成一筆再一起傳過來
	

	*/
	
	
        //接收end
	// 關閉 socket
	echo "Closing socket...";
	socket_close($socket);
	

?>



</body>
</html>