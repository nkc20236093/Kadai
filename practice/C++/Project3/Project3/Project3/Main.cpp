// オブジェクト指向
// C++はオブジェクト指向型プログラム
// クラス、継承、カプセル化、ポリモーフィズムなど
// そういった要素を取り入れる

// クラスのおさらい
#include <iostream>
using namespace std;

// クラスの定義
class Stdunt
{
	// アクセス指定子を設定	
	// privateは非公開、publicは公開
public:
	int year = 0;			// 学年
	string className;		// クラス名
	int studentNo = 0;		// 出席番号
	//ここから非公開(何も定義がないとprivate)になる
private:
	string studentName;		// 氏名
public:
	void SetStudentName(string name)
	{
		studentName = name;
	}
	string GetStudentName()
	{
		return studentName;
	}
};

//機造対について
//データ（変数）をまとめられる型(c言語)
//今は関数も持てる
//アクセス指定はデフォルトでpublic
struct Teacher
{
	int year = 0;
	string className = "";
};
int main()
{
	cout << "クラスのおさらい\n";
	Stdunt s1;
	// 公開部(public)に値を設定
	s1.year = 2;
	s1.className = "ゲーム総合学科";
	s1.studentNo = 29;
	s1.SetStudentName("滝 瑛太");
	// 表示
	cout << "year = " << s1.year << "\n";
	cout << "className = " << s1.className << "\n";
	cout << "studentNo = " << s1.studentNo << "\n";
	cout << "studentName = " << s1.GetStudentName() << "\n";

	Teacher t1;
	t1.year = 2;
	t1.className = "ゲーム総合学科2年A組";

	cout << "TeacherYear = " << t1.year << "\n";
	cout << "className = " << t1.className << "\n";
}