<!DOCTYPE html>
<html>
    <head>
       <meta charset="UTF-8"/>
       <title>設定</title>
    </head>
    <body>
       
<h1 align="center">設定</h1>

<br/>
<table align="center" border="5" cellpadding="5" cellspacing="0" bordercolor="pink" width="700">
<tbody><tr>
	<th bgcolor="pink" colspan="5">手動設定動作 六軸機械手臂與步進馬達</th><!--標題-->
</tr>
<tr>

    <td width="100%"><font size="3"><p align="center"> <table align="center" border="5" cellpadding="5" cellspacing="0" bordercolor="white" width="50">
<tbody>

<tr>

    <td>
    <form action="inangle1.php" method="post">
        第幾組動作: <input type=text name=team placeholder="輸入組別"><br/>
    </br>
   
        角度(馬達1): <input type=text name=angle1 placeholder="輸入設定角度"><br/>
	角度(馬達2): <input type=text name=angle2 placeholder="輸入設定角度"><br/>
	角度(馬達3): <input type=text name=angle3 placeholder="輸入設定角度"><br/>
	角度(馬達4): <input type=text name=angle4 placeholder="輸入設定角度"><br/>
	角度(馬達5): <input type=text name=angle5 placeholder="輸入設定角度"><br/>
	角度(馬達6): <input type=text name=angle6 placeholder="輸入設定角度"><br/>
        </br>
     
        <input type="submit" value="送出">
    
        <input type="reset" value="清除">


        </form>
    </td>   
    
    <td>
    <form action="insertss.php" method="post">
        在動作 <input type=text name=enteam placeholder="輸入動作">之後<br/>
    </br>
   
        步進馬達往<input type=text name=fb placeholder="forward or behind(f、b)"><br/>
	<input type=text name=ss placeholder="輸入步數(1~4900)">步<br/>
	
        </br>
     
        <input type="submit" value="送出">
    
        <input type="reset" value="清除">
	

        </form>
    </td>
    
</tr>
</tbody>

</table></p></font></td>
</tr>

</tbody>

</table>
<br/>
<br/>	
<a href="esp32.php" ><p align="center" target="_blank">送出更改資料給esp32</p></a>
<a href="deletean.php" ><p align="center" target="_blank">刪除手動設定資料</p></a>	
<a href="ex.php" ><p align="center">回首頁</p></a>

    </body>



</html>