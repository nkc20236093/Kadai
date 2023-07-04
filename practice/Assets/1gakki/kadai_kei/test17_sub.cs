using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test17_sub : MonoBehaviour
{
    public float height;
    public float weight;
    public string[] obesity;
// Start is called before the first frame update
void Start()
    {
        //課題17
        //①以下のようにpublic変数のheight,weightを宣言(クラスxxx:xxx{の下あたりに書く)
        //[SerializeField][Header("身長m")] public float height = 1.7f;
        //[SerializeField][Header("体重kg")] public float weight = 65.5f;    
        //※値はUnity上でスクリプトをアタッチしたGameObjectのインスペクタで設定可能。

        //②身長と体重を引数にBMI(ボディマス指数)を返すメソッドGetBMIを作成
        //※BMI ＝ 体重kg ÷ (身長mの二乗)
        
        //③Startメソッド内でheightとweightを引数で渡してGetBMIを呼んでDebug.Logで表示。
        //※ 例）身長○○m 体重○○kg BMIは○○です
        //※ インスペクタで設定した値で表示・計算が出来ていれば成功
        Debug.Log("身長は" + height + "cm,体重は" + weight + "kg,BMIは" + GetBMI());
        //④以下のように肥満度の文字列をstring型の配列で宣言(height,weightの上か下あたりに書く)
        //[SerializeField][Header("肥満度")] string[] obesity;

        //⑤肥満度の文字はUnity上でスクリプトをアタッチしたGameObjectのインスペクタで
        //低体重(痩せ型)～肥満(4度)までの6個を入力する。+-で要素の増減が可能。

        //※日本肥満学会の判定基準
        //BMI値            判定
        //18.5未満         低体重(痩せ型)　
        //18.5〜25未満     普通体重
        //25〜30未満       肥満(1度)
        //30〜35未満       肥満(2度)
        //35〜40未満       肥満(3度)
        //40以上           肥満(4度)

        //⑥Startメソッド内で、BMIの値をもとに肥満度を④の配列(テーブル)を使って表示
        //※ 例）肥満(1度)です
        //なお、配列の添え字は今回は直接数値を書いてもよい。もちろん変数を使ってもよい。
        //また、obersityに何も入力されてない場合は処理せずに注意文を表示すること
        //例）if (obesity==null) { Debug.Log("肥満度の文字が何も入力されていません"); } else { 処理 }
        if (GetBMI() < 18.5)
        {
            Debug.Log(obesity[0]);
        }
        else if (GetBMI() < 25)
        {
            Debug.Log(obesity[1]);
        }
        else if (GetBMI() < 30)
        {
            Debug.Log(obesity[2]);
        }
        else if (GetBMI() < 35)
        {
            Debug.Log(obesity[3]); ;
        }
        else if (GetBMI() < 40)
        {
            Debug.Log(obesity[4]);
        }
        else
        {
            Debug.Log(obesity[5]);
        }
        //★適正体重を求めるメソッドも作って表示できればなお良い
    }
    float GetBMI()
    {
        float BMI = weight / Mathf.Pow(height, 2);
        return BMI;
    }
}
