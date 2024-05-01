#include <iostream>
#include <stdio.h>

using namespace std;

void Celect();
void main()
{
	int ent;
	cout << "---自己紹介プログラム開始---\n※ エンターキーを押すと進みます\n";
	while ((ent = cin.get()) == '\n')
	{
		Celect();
	}
}
void Celect()
{
	int x;
	cout << "見たい自己紹介を選択してください\n\n";
	cout << "1. 好きなゲーム : 2. 好きな本: 3. 好きな映画\n\n";
	cin >> x;
	if (x == 1)
	{
		cout << "ghostwireTOKYOですね。\n無人になった東京を取り返す和風要素たんまりなゲームです\n\n";
	}
	else if (x == 2)
	{
		cout << "悲鳴伝ですね\n西尾維新独特の言葉遊びと人の心を持たない故に敵より味方を殺すヒーローとして主人公が暴れてます\n\n";
	}
	else if (x == 3)
	{
		cout << "やっぱりワンピースですね\n最後に見たのはStampedeです\n\n";
	}
	Celect();
}

