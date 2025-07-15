<html>
<head>
    <title>成績更新フォーム</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        学籍番号: <input type="text" name="gakusekiNo" required><br>
        科目コード: <input type="text" name="kamokuCode" required><br>
        得点: <input type="text" name="ten" required><br>
        <input type="submit" value="更新">
    </form>

    <?php
    try {
        $pdo = new PDO('mysql:host=localhost;dbname=nkcdb;charset=utf8', 'nkc', 'game1234cg5678');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch (Exception $e) {
        exit('データベース接続エラー: ' . $e->getMessage());
    }

    echo '<a href="index.html">ホームへ戻る</a><br>';

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $sql = "UPDATE seiseki SET ten = :ten WHERE gakusekiNo = :gakusekiNo AND kamokuCode = :kamokuCode";
        $stmt = $pdo->prepare($sql);
        $stmt->bindValue(':ten', $_POST['ten'], PDO::PARAM_INT);
        $stmt->bindValue(':gakusekiNo', $_POST['gakusekiNo']);
        $stmt->bindValue(':kamokuCode', $_POST['kamokuCode']);
        $stmt->execute();
    }
    ?>
</body>
</html>
