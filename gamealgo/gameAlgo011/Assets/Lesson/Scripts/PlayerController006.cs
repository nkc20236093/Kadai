//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：向いている方向に弾を出す
// 日時：2023.06.02 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerController006 : MonoBehaviour
{
    AudioSource audioSource;
    [SerializeField] AudioClip clip;

    [SerializeField] float Ray_distance;
    [SerializeField] float Jump_power;
    new Rigidbody rigidbody;
    bool Ground;
    public LayerMask lmask;
    public Text speedText;      // UI-TEXTオブジェクトを保存する
    public Text shotLevelText;  // UI-TEXTオブジェクトを保存する
    public Text hakiText;       // UI-TEXTオブジェクトを保存する
    GameObject bulletPre;       // 弾のプレハブを保存する
    GameObject firePre;         // 燃えてるエフェクトのプレハブを帆zン

    Vector3 dir;                // 移動方向を保存する変数
    float speed;                // 移動量を保存する変数
    float axel;                 // 加速度を保存する変数
    int bdash;                  // Bダッシュ係数を保存する変数
    float rad;                  // 回転角度を保存する変数
    float rotSpeed;             // 回転速度を保存する変数
    float timer;                // 弾の発射間隔制御用
    int   power;                // 武器の強さ
    SphereCollider spCollider;  // 覇気用スフィアコライダー保存用
    bool hakiFlg;               // 覇気フラグ
    float hakiSpeed;            // 覇気スピード
    float hakiAccel;            // 覇気加速度

    const float MAX_SPEED = 10;  // スピードの上限値を指定する定数

    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();

        // 各変数初期化
        dir      = Vector3.zero;
        speed    = 0;
        axel     = 0.04f;
        bdash    = 1;
        rad      = 0;
        rotSpeed = 1.5f;
        timer    = 0;
        power    = 0;

        // Resourcesフォルダ内にある弾のプレハブを取得する
        bulletPre = (GameObject)Resources.Load("BulletPre");
        firePre = (GameObject)Resources.Load("MyFireMobile");

        // SphereColliderコンポーネントを取得
        spCollider = GetComponent<SphereCollider>();
        hakiFlg = false;
        hakiSpeed = 3;
        hakiAccel = 0.02f;

    }

    void Update()
    {
        // プレイフラグがOFFになったらこの先の命令は実行しない
        if (GameDirector.isPlaying == false) return;

        // 左右キーで回転
        rad = Input.GetAxisRaw("Horizontal") * rotSpeed;
        transform.Rotate(Vector3.up, rad);

        // ↑キーで前進、↓キーで後退
        float z = Input.GetAxisRaw("Vertical");

        // 上下キーが押されているとき
        if(z != 0)
        {
            // 加速度を増やす
            speed += axel;

            // スピードを増やす（上限設定あり）
            speed = (speed <= MAX_SPEED)? speed : MAX_SPEED;

            // 進行方向をセット
            dir = transform.forward * z;  
        }
        else
        {
            // 減速処理
            speed *= 0.9f;
        }

        // クリックでリスタート
        //if(Input.GetMouseButtonDown(0))
        //{
        //    SceneManager.LoadScene(0); // シーンをリスタート           
        //}

        // Bdash処理
        bdash = (Input.GetKey(KeyCode.B)) ? 2 : 1;

        // 移動量を現在値に加算
        transform.position += dir.normalized * speed * bdash * Time.deltaTime;

        // Zキーが押されているとき弾を発射
        timer += Time.deltaTime;
        if (timer >= 0.3f && Input.GetButton("Fire1"))
        {
            timer = 0;
            audioSource.Play();
            for (int i = -power; i < power + 1; i++)
            {
                // 弾の生成位置はプレーヤーの0.5m上の位置
                Vector3 pos = transform.position + new Vector3(0, 0.5f, 0);

                // プレーヤーの回転角度を取得し、15度ずつずらした方向に弾を回転させる
                Vector3 r = transform.rotation.eulerAngles + new Vector3(0, 15f * i, 0);
                Quaternion rot = Quaternion.Euler(r);

                // 位置と回転情報をセットして生成
                Instantiate(bulletPre, pos, rot);
            }
        }
        Jump();
        // 覇気システム
        if (hakiFlg == false)
        {
            if (Input.GetKeyDown(KeyCode.X))
            {
                hakiFlg = true;
            }
        }
        else
        {
            spCollider.radius += hakiSpeed;
            hakiSpeed += hakiAccel;

            if (spCollider.radius > 50f)
            {
                hakiFlg = false;
                hakiSpeed = 3;
                spCollider.radius = 0.5f;
            }
        }

        // Cキーでpower変更
        if (Input.GetKeyDown(KeyCode.C))
        {
            power = (power + 1) % 13;
        }

        // 速度表示
        float sokudo = speed * bdash;
        speedText.text = "速度 " + sokudo.ToString("F2") + " m/s";
        // ショットレベル表示
        shotLevelText.text = "弾レベル：" + power.ToString("D2");

        hakiText.text = "覇気フラグ：" + hakiFlg.ToString();
        
    }
    void Jump()
    {
        Ray ray = new Ray(transform.position, Vector3.down);
        Debug.DrawRay(ray.origin, ray.direction * Ray_distance, Color.red);
        if (Physics.Raycast(ray, Ray_distance, lmask))
        {
            Ground = true;
            Debug.Log("地面");
        }
        else
        {
            Ground = false;
            Debug.Log("空中");
        }
        Vector3 force = new Vector3(0, Jump_power, 0);
        if (Ground)
        {
            if (Input.GetButtonDown("Jump"))
            {
                Debug.Log("ジャンプ");
                rigidbody.AddForce(force, ForceMode.Impulse);
            }
        }
    }
    void OnTriggerEnter(Collider c)
    {
        // 当たってきたオブジェクトのTagが「Enemy」だったら
        if (c.tag == "Enemy" && hakiFlg == false)
        {
            GameDirector.moveHp -= Random.Range(20, 200);
            GameDirector.moveHp = Mathf.Max(GameDirector.moveHp, 0);

            Vector3 pos = transform.position + new Vector3(0,1,0);
            Instantiate(firePre, pos, transform.rotation);
        }
    }
}
