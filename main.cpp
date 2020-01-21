#include "main.h"

#include <stdlib.h>

extern int maint;

// プログラムは WinMain から始まります
//Changed to ansi c++ main()
int main(int argc, char *argv[])
{
  parseArgs(argc, argv);

  if (DxLib_Init() == -1)
		return 1;

	//全ロード
  loadg();

	//フォント
	SetFontSize(16);
	//SetFontThickness(4) ;

	//ループ
	//for (maint=0;maint<=2;maint++){
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) 
	{
		UpdateKeys();
		maint = 0;
		Mainprogram();

		if (maint == 3)
			break;
	}

	//ＤＸライブラリ使用の終了処理
  // end();
  exit(0);

}
