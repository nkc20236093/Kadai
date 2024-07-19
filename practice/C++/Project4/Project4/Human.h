//Human h
#pragma once  //インクルードガード
#include <iostream>

class Human    //人間クラス
{
private:       //アクセス指定子:以下private
    int age;            //年齢
    std::string gender; //性別 
    std::string name; //名前 
public:        //アクセス指定子:以下public
    //コンストラクタを設定
    //(クラスには必ずコンストラクタがある)
    //クラスと同じ名前の関数
    //コンストラクタには返却値は無い
    //引数がないコンストラクタを
    //デフォルトコンストラクタという
    Human()
    {
        std::cout << "コンストラクタの実装\n";
        //コンストラクタではクラスの変数の初期化を行う
        age = 0;
        name = "名無し";
        gender = "男";
    }
    //引数があるコンストラクタの多重定義（オーバーロード）
    Human(int _age, std::string _name, std::string _gender)
    {
        std::cout << "引数ありコンストラクタ実行\n";
        age = _age;
        name = _name;
        gender = _gender;
    }


    //表示用の関数
    void DispSpace()
    {
        std:: cout << "年齢 = " << age << "\n";
        std:: cout << "名前 = " << name << "\n";
        std:: cout << "性別 = " << gender << "\n";
    }
};