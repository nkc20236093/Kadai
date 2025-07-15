<html>
<head>
    <title>フォーム</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        学籍番号: <input type="text" name="gakusekiNo" /><br>
        科目コード: <input type="text" name="kamokuCode" /><br>
        得点: <input type="text" name="ten" /><br>
        <input type="submit" />
    </form>

    <?php
    try {
        $pdo = new PDO('mysql:host=localhost;dbname=nkcdb;charset=utf8', 'nkc', 'game1234cg5678');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // エラー詳細を表示
    } catch (Exception $e) {
        exit('データベース接続エラー: ' . $e->getMessage());
    }

    echo '<a href="index.html">ホームへ戻る</a><br>';

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        try {
            $sql = "INSERT INTO seiseki (gakusekiNo, kamokuCode, ten) VALUES (:gakusekiNo, :kamokuCode, :ten)";
            $stmt = $pdo->prepare($sql);
            $stmt->bindValue(':gakusekiNo', $_POST['gakusekiNo']);
            $stmt->bindValue(':kamokuCode', $_POST['kamokuCode']);
            $stmt->bindValue(':ten', $_POST['ten']);
            $stmt->execute();
            echo "登録完了しました。";
        } catch (PDOException $e) {
            echo "登録エラー: " . $e->getMessage();
        }
    }
    ?>
</body>
</html>
