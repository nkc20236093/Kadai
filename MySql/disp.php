<html>
<head>
</head>
<body>
[個人別成績一覧] <br><br>
<form action="<?php echo $_SERVER['PHP_SELF']?>" method="POST">
    学生番号：<input type="text" name="gakusekiNo"><br>
    <input type="submit">
</form>
<?php
try {
        $pdo = new PDO('mysql:host=localhost;dbname=nkcdb;charset=utf8', 'nkc', 'game1234cg5678');
} catch (Exception $e) {
    exit("データベース接続失敗");
}
echo "<br>";

// POSTの処理
if($_SERVER["REQUEST_METHOD"]=="POST"){
    $sql="SELECT gakkaMei,name FROM gakuseki_table 
          JOIN gakka_table ON gakuseki_table.gakkaCode = gakka_table.gakkaCode 
          WHERE gakusekiNo='" . $_POST["gakusekiNo"] . "'";

    $stmt = $pdo->query($sql);
    if(!$stmt) echo "該当者なし<br>";
    else {
        $row = $stmt->fetch(PDO::FETCH_ASSOC);
        echo $row["gakkaMei"] . "： " . $row["name"] . "<br><br>";

        $sql = "SELECT kamokuMei, MAX(ten) AS ten FROM seiseki_table 
            JOIN kamoku_table ON seiseki_table.kamokuCode = kamoku_table.kamokuCode 
            WHERE gakusekiNo='" . $_POST["gakusekiNo"] . "'
            GROUP BY kamokuMei";
        
        $stmt = $pdo->query($sql);
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            echo $row["kamokuMei"] . "：" . $row["ten"] . "<br>";
        }

        $sql="SELECT MAX(ten),MIN(ten),AVG(ten) FROM seiseki_table 
              WHERE gakusekiNo='" . $_POST["gakusekiNo"] . "'";
        $stmt = $pdo->query($sql);
        $row = $stmt->fetch(PDO::FETCH_ASSOC);
        echo "<br>最高点：" . $row["MAX(ten)"] . "　最低点：" . $row["MIN(ten)"] . "　平均：" . $row["AVG(ten)"] . "<br>";
    }
}
?>
<br>
<a href="index.html">ホーム</a>
</body>
</html>