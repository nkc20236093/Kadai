using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using System.Collections;

public class PlayerController : MonoBehaviourPunCallbacks
{
    public Transform viewPoint;//カメラの位置オブジェクト
    public float mouseSensitivity = 1f;//視点移動の速度
    private Vector2 mouseInput;//ユーザーのマウス入力を格納
    private float verticalMouseInput;//y軸の回転を格納　回転を制限したいから
    private Camera cam;//カメラ



    private Vector3 moveDir;//プレイヤーの入力を格納（移動）
    private Vector3 movement;//進む方向を格納する変数
    private float activeMoveSpeed = 4;//実際の移動速度



    public Vector3 jumpForce = new Vector3(0, 6, 0);//ジャンプ力 
    public Transform groundCheckPoint;//地面に向けてレイを飛ばすオブジェクト 
    public LayerMask groundLayers;//地面だと認識するレイヤー 
    Rigidbody rb;//


    public float walkSpeed = 4f, runSpeed = 8f;//歩きの速度、走りの速度


    private bool cursorLock = true;//カーソルの表示/非表示 


    public List<Gun> guns = new List<Gun>();//武器の格納配列
    private int selectedGun = 0;//選択中の武器管理用数値


    private float shotTimer;//射撃間隔
    [Tooltip("所持弾薬")]
    public int[] ammunition;
    [Tooltip("最高所持弾薬数")]
    public int[] maxAmmunition;
    [Tooltip("マガジン内の弾数")]
    public int[] ammoClip;
    [Tooltip("マガジンに入る最大の数")]
    public int[] maxAmmoClip;


    UIManager uIManager;//UI管理


    SpawnManager spawnManager;//スポーンマネージャー管理


    public Animator animator;//アニメーター


    public GameObject[] playerModel;//プレイヤーモデルを格納
    public Gun[] gunsHolder, OtherGunsHolder;//銃ホルダー


    public int maxHP = 100;//最大HP
    private int currentHp;//現在のHP


    public GameObject hitEffect;//血のエフェクト


    GameManager gameManager;//ゲームマネージャー

    ZoneManager zoneManager;//ゾーンマネージャー

    float Zonetimer = 0;
    bool SafeZone = false;

    float InvincibilityTimer = 0;
    bool Invincibility = true;

    // 無敵時間の点滅用
    SkinnedMeshRenderer Model1;
    SkinnedMeshRenderer Model2;

    // 射程距離減衰(m)
    float[] lenght = new float[3]
    {
       3.5f, 5.75f,10f
    };
    // 射程距離減衰率
    float[] magnification = new float[3]
    {
        1.25f,1.0f,0.5f
    };

    private void Awake()
    {
        //タグからUIManagerを探す
        uIManager = GameObject.FindGameObjectWithTag("UIManager").GetComponent<UIManager>();

        //タグからSpawnManagerを探す
        spawnManager = GameObject.FindGameObjectWithTag("SpawnManager").GetComponent<SpawnManager>();

        //タグからGameManagerを探す
        gameManager = GameObject.FindGameObjectWithTag("GameManager").GetComponent<GameManager>();

        zoneManager = GameObject.FindGameObjectWithTag("Zone").GetComponent<ZoneManager>();

        Model1 = transform.Find("Ch49_nonPBR/Ch49_body1").gameObject.GetComponent<SkinnedMeshRenderer>();
        Model2 = transform.Find("Ch49_nonPBR/Ch49_body2").gameObject.GetComponent<SkinnedMeshRenderer>();
    }

    private void Start()
    {
        currentHp = maxHP;//現在のHPをMAXHPの数値に設定


        //変数にメインカメラを格納
        cam = Camera.main;


        //Rigidbodyを格納
        rb = GetComponent<Rigidbody>();


        //カーソル非表示
        UpdateCursorLock();


        //弾薬テキスト更新
        uIManager.SettingBulletsText(ammoClip[selectedGun], ammunition[selectedGun]);


        //ランダムな位置でスポーンさせる
        //transform.position = spawnManager.GetSpawnPoint().position;


        guns.Clear();//初期化

        if (photonView.IsMine)//自分だったら
        {

            foreach (var model in playerModel)//モデルのパーツ分ループ
            {
                model.SetActive(false);//非表示
            }


            foreach (Gun gun in gunsHolder)//銃の数分ループ
            {
                guns.Add(gun);//リストに追加
            }

            uIManager.UpdateHP(maxHP, currentHp);//HPをスライダーに反映

        }
        else//他人だったらOtherGunsHolderを表示させる
        {
            foreach (Gun gun in OtherGunsHolder)//銃の数分ループ
            {
                guns.Add(gun);//リストに追加
            }
        }

        switchGun();//銃を表示させるため

        // 無敵時間
        StartCoroutine(nameof(InvincibilityTime));
    }

    IEnumerator InvincibilityTime()
    {
        if (!Invincibility) yield break;

        while (InvincibilityTimer < 3)
        {
            Model1.enabled = false;
            Model2.enabled = false;
            InvincibilityTimer += Time.deltaTime;
            yield return new WaitForSeconds(0.2f);
            Model1.enabled = true;
            Model2.enabled = true;
        }
        Invincibility = false;
        yield break;
    }
    private void Update()
    {
        //自分以外は
        if (!photonView.IsMine)
        {
            //戻ってこれ以降の処理を行わない
            return;
        }
        // 安置外ダメージ
        Zone(SafeZone);


        // 落下死
        if (transform.position.y < -10)
        {
            Death("落下死", 00);
        }

        //視点移動関数
        PlayerRotate();

        //移動関数
        PlayerMove();

        //地面についているのか判定をする
        if (IsGround())
        {
            //走りの関数を呼ぶ
            Run();

            //ジャンプ関数を呼ぶ
            Jump();
        }

        //銃の切り替え
        SwitchingGuns();

        //覗き込み
        Aim();

        //射撃関数
        Fire();

        //リロード関数
        Reload();

        //カーソル非表示
        UpdateCursorLock();

        //アニメーター遷移
        AnimatorSet();

        //サウンド止める条件
        if (Input.GetMouseButtonUp(0) || ammoClip[2] <= 0)
        {
            //サウンド止める
            photonView.RPC(nameof(SoundStop), RpcTarget.All);
        }

        OutGame();//
    }

    //Update関数が呼ばれた後に実行される
    private void LateUpdate()
    {
        //自分以外は
        if (!photonView.IsMine)
        {
            //戻ってこれ以降の処理を行わない
            return;
        }

        //カメラをプレイヤーの子にするのではなく、スクリプトで位置を合わせる
        cam.transform.position = viewPoint.position;
        cam.transform.rotation = viewPoint.rotation;
    }

    //初期設定では0.02秒ごとに呼ばれる
    private void FixedUpdate()
    {
        //自分以外は
        if (!photonView.IsMine)
        {
            //戻ってこれ以降の処理を行わない
            return;
        }

        //弾薬テキスト更新
        uIManager.SettingBulletsText(ammoClip[selectedGun], ammunition[selectedGun]);
    }

    void Zone(bool safe)
    {
        uIManager.ZoneWarningChage(safe);
        if (safe)
        {
            Zonetimer = 0;
            return;
        }
        else
        {
            Debug.Log("安置外");
            Zonetimer += Time.deltaTime;
            if (Zonetimer > 2)
            {
                Debug.Log("安置外ダメージ");
                photonView.RPC(nameof(ZoneDamage), RpcTarget.All);
                Zonetimer = 0;
            }
        }
    }

    [PunRPC]
    void ZoneDamage()
    {
        if (photonView.IsMine)//自分なら
        {
            int damage = zoneManager.ZoneDamages[zoneManager.ZoneSequence];
            currentHp -= damage;//ダメージ


            if (currentHp <= 0)//現在のHPが0以下の場合
            {
                Death("安置外ダメージ", 1000);//死亡関数を呼ぶ
            }

            uIManager.UpdateHP(maxHP, currentHp);//HPをスライダーに反映

        }
    }

    /// <summary>
    /// Playerの横回転と縦の視点移動を行う
    /// </summary>
    public void PlayerRotate()
    {
        //変数にユーザーのマウスの動きを格納
        mouseInput = new Vector2(Input.GetAxisRaw("Mouse X") * mouseSensitivity,
            Input.GetAxisRaw("Mouse Y") * mouseSensitivity);

        //横回転を反映(transform.eulerAnglesはオイラー角としての角度が返される)
        transform.rotation = Quaternion.Euler
            (transform.eulerAngles.x,
            transform.eulerAngles.y + mouseInput.x, //マウスのx軸の入力を足す
            transform.eulerAngles.z);


        //変数にy軸のマウス入力分の数値を足す
        verticalMouseInput += mouseInput.y;

        //変数の数値を丸める（上下の視点制御）
        verticalMouseInput = Mathf.Clamp(verticalMouseInput, -60f, 60f);

        //縦の視点回転を反映(-を付けないと上下反転してしまう)
        viewPoint.rotation = Quaternion.Euler
            (-verticalMouseInput,
            viewPoint.transform.rotation.eulerAngles.y,
            viewPoint.transform.rotation.eulerAngles.z);
    }



    /// <summary>
    /// Playerの移動
    /// </summary>
    public void PlayerMove()
    {
        //変数の水平と垂直の入力を格納する（wasdや矢印の入力）
        moveDir = new Vector3(Input.GetAxisRaw("Horizontal"),
            0, Input.GetAxisRaw("Vertical"));

        //Debug.Log(moveDir);説明用

        //ゲームオブジェクトのｚ軸とx軸に入力された値をかけると進む方向が出せる
        movement = ((transform.forward * moveDir.z) + (transform.right * moveDir.x)).normalized;

        //現在位置に進む方向＊移動スピード＊フレーム間秒数を足す
        transform.position += movement * activeMoveSpeed * Time.deltaTime;
    }


    /// <summary>
    /// 地面についているならtrue
    /// </summary>
    /// <returns></returns>
    public bool IsGround()
    {
        return Physics.Raycast(groundCheckPoint.position, Vector3.down, 0.25f, groundLayers);
    }


    public void Jump()
    {
        //ジャンプできるのか判定
        if (IsGround() && Input.GetKeyDown(KeyCode.Space))
        {
            //瞬間的に真上に力を加える
            rb.AddForce(jumpForce, ForceMode.Impulse);
        }
    }


    public void Run()
    {
        //左シフトを押しているときはスピードを切り替える
        if (Input.GetKey(KeyCode.LeftShift))
        {
            activeMoveSpeed = runSpeed;
        }
        else
        {
            activeMoveSpeed = walkSpeed;
        }
    }


    public void UpdateCursorLock()
    {
        //入力しだいでcursorLockを切り替える
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            cursorLock = false;
        }
        else if (Input.GetMouseButton(0))
        {
            cursorLock = true;
        }

        //cursorLock次第でカーソルの表示を切り替える
        if (cursorLock)
        {
            //カーソルを中央に固定し、非表示　https://docs.unity3d.com/ScriptReference/CursorLockMode.html
            Cursor.lockState = CursorLockMode.Locked;
        }
        else
        {
            //表示
            Cursor.lockState = CursorLockMode.None;
        }
    }


    /// <summary>
    /// 銃の切り替えキー入力を検知する
    /// </summary>
    public void SwitchingGuns()
    {
        if (Input.GetAxisRaw("Mouse ScrollWheel") > 0f)
        {
            selectedGun++;//扱う銃を管理する数値を増やす

            //リストより大きい数値になっていないか確認
            if (selectedGun >= guns.Count)
            {
                selectedGun = 0;//リストより大きな数値になれば０に戻す
            }

            //実際に武器を切り替える関数
            //switchGun();

            //銃の切り替え（ルーム内のプレイヤー全員呼び出し）
            photonView.RPC("SetGun", RpcTarget.All, selectedGun);

        }
        else if (Input.GetAxisRaw("Mouse ScrollWheel") < 0f)
        {
            selectedGun--;//扱う銃を管理する数値を減らす


            if (selectedGun < 0)
            {
                selectedGun = guns.Count - 1;//0より小さければリストの最大数－１の数値に設定する
            }

            //実際に武器を切り替える関数
            //switchGun();

            //銃の切り替え（ルーム内のプレイヤー全員呼び出し）
            photonView.RPC("SetGun", RpcTarget.All, selectedGun);
        }

        //数値キーの入力検知で武器を切り替える
        for (int i = 0; i < guns.Count; i++)
        {
            if (Input.GetKeyDown((i + 1).ToString()))//ループの数値＋１をして文字列に変換。その後、押されたか判定
            {
                selectedGun = i;//銃を扱う数値を設定

                //実際に武器を切り替える関数
                //switchGun();

                //銃の切り替え（ルーム内のプレイヤー全員呼び出し）
                photonView.RPC("SetGun", RpcTarget.All, selectedGun);

            }
        }

    }

    /// <summary>
    /// 銃の切り替え
    /// </summary>
    void switchGun()
    {
        foreach (Gun gun in guns)//リスト分ループを回す
        {
            gun.gameObject.SetActive(false);//銃を非表示
        }

        guns[selectedGun].gameObject.SetActive(true);//選択中の銃のみ表示
    }



    /// <summary>
    /// 右クリックで覗き込み
    /// </summary>
    public void Aim()
    {
        //  マウス右ボタン押しているとき
        if (Input.GetMouseButton(1))
        {
            //fieldOfViewコンポーネントの値を変更(開始地点、目的地点、補完数値)　　開始地点から目的地点まで補完数値の割合で徐々に近づける
            cam.fieldOfView = Mathf.Lerp(cam.fieldOfView, guns[selectedGun].adsZoom, guns[selectedGun].adsSpeed * Time.deltaTime);
        }
        else
        {   //60は初期設定数値
            cam.fieldOfView = Mathf.Lerp(cam.fieldOfView, 60f, guns[selectedGun].adsSpeed * Time.deltaTime);
        }
    }



    /// <summary>
    /// 左クリックの検知
    /// </summary>
    public void Fire()
    {

        if (Input.GetMouseButton(0) && ammoClip[selectedGun] > 0 && Time.time > shotTimer)
        {
            FiringBullet();
        }

    }

    /// <summary>
    /// 弾丸の発射
    /// </summary>
    private void FiringBullet()
    {
        //選択中の銃の弾薬減らす
        ammoClip[selectedGun]--;

        //Ray(光線)をカメラの中央からに設定
        Ray ray = cam.ViewportPointToRay(new Vector2(.5f, .5f));//カメラの中心がこの数値


        //レイを飛ばす（開始地点と方向、当たったコライダーの情報格納）
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            //Debug.Log("当たったオブジェクトは" + hit.collider.gameObject.name);

            if (hit.collider.gameObject.tag == "Player")//プレイヤーにぶつかった場合
            {
                //血のエフェクトをネットワーク上に生成
                PhotonNetwork.Instantiate(hitEffect.name, hit.point, Quaternion.identity);

                // ヒット関数を全プレイヤーで呼び出して撃たれたプレイヤーのHPを同期する
                hit.collider.gameObject.GetPhotonView().RPC("Hit", RpcTarget.All, guns[selectedGun].shotDamage, photonView.Owner.NickName, PhotonNetwork.LocalPlayer.ActorNumber);

            }
            else
            {
                //弾痕エフェクト (hit.pointはコライダーにヒットした位置)：hit.point + (hit.normal * .002f)はちらつかないように少し上にしている
                //hit normalは当たったオブジェクトに対して直角の方向が返される
                //LookRotationは指定した方向に回す
                GameObject bulletImpactObject = Instantiate(guns[selectedGun].bulletImpact, hit.point + (hit.normal * .002f), Quaternion.LookRotation(hit.normal, Vector3.up));

                //時間経過で消えるようにする
                Destroy(bulletImpactObject, 10f);
            }



        }

        //射撃間隔を設定
        shotTimer = Time.time + guns[selectedGun].shootInterval;

        //発射音
        photonView.RPC("SoundGeneration", RpcTarget.All);

    }


    /// <summary>
    /// リロード
    /// </summary>
    private void Reload()
    {
        if (Input.GetKeyDown(KeyCode.R))
        {
            //リロードで補充する弾数を取得する
            int amountNeed = maxAmmoClip[selectedGun] - ammoClip[selectedGun];

            //必要な弾薬量と所持弾薬量を比較
            int ammoAvailable = amountNeed < ammunition[selectedGun] ? amountNeed : ammunition[selectedGun];

            //弾薬が満タンの時はリロードできない&弾薬を所持しているとき
            if (amountNeed != 0 && ammunition[selectedGun] != 0)
            {
                //所持弾薬からリロードする弾薬分を引く
                ammunition[selectedGun] -= ammoAvailable;
                //銃に装填する
                ammoClip[selectedGun] += ammoAvailable;
            }
        }
    }


    private void AnimatorSet()
    {
        //walk判定
        if (moveDir != Vector3.zero)
        {
            animator.SetBool("walk", true);

        }
        else
        {
            animator.SetBool("walk", false);
        }

        //run判定
        if (Input.GetKey(KeyCode.LeftShift))
        {
            animator.SetBool("run", true);
        }
        else
        {
            animator.SetBool("run", false);
        }

    }


    [PunRPC]//（同じルームにいる）リモートクライアントに対してのメソッドの呼び出しが可能に
    public void SetGun(int gunNo)
    {
        //銃の切り替え
        if (gunNo < guns.Count)
        {
            selectedGun = gunNo;

            switchGun();
        }

    }


    /// <summary>
    /// 敵の弾に当たったら呼ばれる関数（全プレイヤーで共有するためPunRPC）
    /// </summary>
    [PunRPC]
    public void Hit(int damage, string name, int actor)//ダメージ、撃った奴の名前、撃った奴の番号
    {
        ReceiveDamage(name, damage, actor);//ダメージ関数呼び出し

    }


    /// <summary>
    /// ダメージを受ける関数
    /// </summary>
    public void ReceiveDamage(string name, int damage, int actor)
    {
        if (photonView.IsMine)//自分なら
        {
            currentHp -= damage;//ダメージ


            if (currentHp <= 0)//現在のHPが0以下の場合
            {
                Death(name, actor);//死亡関数を呼ぶ
            }

            uIManager.UpdateHP(maxHP, currentHp);//HPをスライダーに反映

        }

    }

    //死亡処理
    public void Death(string name, int actor)
    {
        currentHp = 0;

        //死亡関数を呼ぶ
        spawnManager.Die();
        uIManager.UpdateDeathUI(name);


        //自分のデス数を上昇させる(自分の識別番号、デス、加算数値)
        gameManager.ScoreGet(PhotonNetwork.LocalPlayer.ActorNumber, 1, 1);

        //撃ってきた相手のキル数を上昇する(撃ってきた敵の識別番号、キル、加算数値)
        gameManager.ScoreGet(actor, 0, 1);

    }


    public override void OnDisable()
    {
        //マウス表示
        cursorLock = false;
        Cursor.lockState = CursorLockMode.None;
    }


    //音の発生
    [PunRPC]
    public void SoundGeneration()
    {
        if (selectedGun == 2)//アサルトライフルなら
        {
            guns[selectedGun].LoopON_SubmachineGun();//ループして鳴らす
        }
        else//違うなら
        {
            guns[selectedGun].SoundGunShot();//単発で鳴らす
        }
    }

    //音を止める関数
    [PunRPC]
    public void SoundStop()
    {
        guns[2].LoopOFF_SubmachineGun();//アサルトライフルのSEループを止める
    }


    /// <summary>
    /// Mを押したらメニューに戻る
    /// </summary>
    public void OutGame()
    {
        if (Input.GetKeyDown(KeyCode.M))
        {
            //プレイヤーデータ削除
            gameManager.OutPlayerGet(PhotonNetwork.LocalPlayer.ActorNumber);

            PhotonNetwork.AutomaticallySyncScene = false;//同期オフ

            PhotonNetwork.LeaveRoom();//部屋を抜ける

        }
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Zone"))
        {
            // 安置外にいる
            SafeZone = false;
        }
    }
    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.CompareTag("Zone"))
        {
            // 安置内にいる
            SafeZone = true;
        }
    }

}