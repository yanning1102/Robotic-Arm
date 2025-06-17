<!DOCTYPE html>
<html>
    <head>
       <meta charset="UTF-8"/>
       <title>手動設定</title>
    </head>
    <body>
       
<h1 align="center">設定</h1>

<br/>
<table align="center" border="5" cellpadding="5" cellspacing="0" bordercolor="pink" width="700">
<tbody><tr>
	<th bgcolor="pink" colspan="5">手動更改10組動作</th><!--標題-->
</tr>
<tr>
    <td width="15%"><font size="3"><p align="center">原動作1</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/>馬達2:0度<br/><span style="color:orange;">馬達3:50度</span><br/>
	馬達4: 0度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
    <td width="15%" ><font size="3"><p align="center">更改動作</p></font></td>
    <td width="35%"><font size="3"><p align="center"> <table align="center" border="5" cellpadding="5" cellspacing="0" bordercolor="pink" width="50">
<tbody>

<tr>
    <td>
    <form action="inangle1.php" method="post">
        更改哪組動作: <input type=text name=team placeholder="輸入更改哪組"><br/>
    </br>
   
        更改角度: <input type=text name=angle placeholder="輸入更改角度"><br/>
        </br>
     
        <input type="submit" value="送出">
    
        <input type="reset" value="清除">
	<a href="esp32.php" ><p align="center" target="_blank">送出更改資料給esp32</p></a>
<a href="deletean.php" ><p align="center" target="_blank">刪除手動設定資料</p></a>	
<!--寫12組每個資料庫&他們傳送給esp32的資料-->
        </form>
    </td>
</tr>
</tbody>

</table></p></font></td>
</tr>
<!--2-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作2</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/><span style="color:orange;">馬達2:65度</span><br/>馬達3:50度</span><br/>
	馬達4: 0度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
  
</tr>
<!--3-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作3</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/>馬達2:65度<br/>馬達3:50度<br/><span style="color:orange;">
	馬達4:37度</span><br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
 
 
</tr>
<!--4-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作4</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/>馬達2:60度<br/><span style="color:orange;">馬達3:104度</span><br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
  

</tr>
<!--5-->
<tr>
    <td width="15%"><font size="3"><p align="center">夾取動作</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/>馬達2:65度<br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/><span style="color:orange;">馬達6:120度 爪子夾</span><br/></p></td>


</tr>
<!--6-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作5</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/><span style="color:orange;">馬達2:10度</span><br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6:120度<br/></p></td>
 

</tr>
<!--7-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作6</p></font></td>
	<td align="center" width="35%"><p><span style="color:orange;">馬達1: 0度/180度</span><br/>馬達2:10度<br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6:120度<br/></p></td>


</tr>
<!--8-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作7</p></font></td>
	<td align="center" width="35%"><p>馬達1: 0度/180度<br/><span style="color:orange;">馬達2:65度</span><br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6:120度<br/></p></td>
  
 
</tr>
<!--9-->
<tr>
    <td width="15%"><font size="3"><p align="center">放置動作</p></font></td>
	<td align="center" width="35%"><p>馬達1: 0度/180度<br/>馬達2:65度<br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/><span style="color:orange;">馬達6: 0度 爪子放</span><br/></p></td>


</tr>
<!--10-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作8</p></font></td>
	<td align="center" width="35%"><p>馬達1: 0度/180度<br/><span style="color:orange;">馬達2:10度</span><br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>


</tr>
<!--11-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作9</p></font></td>
	<td align="center" width="35%"><p><span style="color:orange;">馬達1:91度</span><br/>馬達2:10度<br/>馬達3:104度<br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
   

</tr>
<!--12-->
<tr>
    <td width="15%"><font size="3"><p align="center">原動作10</p></font></td>
	<td align="center" width="35%"><p>馬達1:91度<br/>馬達2:10度<br/><span style="color:orange;">馬達3:30度</span><br/>
	馬達4:37度<br/>馬達5: 0度<br/>馬達6: 0度<br/></p></td>
   

</tr>
<!---->




</tbody>

</table>
<br/>
<br/>
<a href="ex.php" ><p align="center">回首頁</p></a>

    </body>



</html>