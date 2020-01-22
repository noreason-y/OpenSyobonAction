#include "game_graphic.h"

void rpaint()
{
	//ダブルバッファリング
  setcolor(0, 0, 0);
	//if (stagecolor==1)setcolor(170,170,255);
    
if (stagecolor == 1)
		setcolor(160, 180, 250);

	if (stagecolor == 2)
		setcolor(10, 10, 10);

  if (stagecolor == 3)
		setcolor(160, 180, 250);

  if (stagecolor == 4)
		setcolor(10, 10, 10);

  if (stagecolor == 5) 
	{
		setcolor(160, 180, 250);
		mrzimen = 1;
  } else {
		mrzimen = 0;
  }

	//: Clear screen
  FillScreen();

  if (mainZ==1 && zxon>=1) 
	{

		//背景
		for (t = 0; t < nmax; t++) 
		{
			xx[0] = na[t] - fx;
			xx[1] = nb[t] - fy;
			xx[2] = ne[ntype[t]] * 100;
			xx[3] = nf[ntype[t]] * 100;
			xx[2] = 16000;
			xx[3] = 16000;

			if (xx[0] + xx[2] >= -10 && xx[0] <= fxmax && xx[1] + xx[3] >= -10 && xx[3] <= fymax) 
			{
				if (ntype[t] != 3) 
				{
					if ((ntype[t] == 1 || ntype[t] == 2) && stagecolor == 5) 
					{
						drawimage(grap[ntype[t] + 30]
						[4], xx[0] / 100, xx[1] / 100);
					} else {
						drawimage(grap[ntype[t]][4],
						xx[0] / 100, xx[1] / 100);
					}
				}

			if (ntype[t] == 3)
				drawimage(grap[ntype[t]][4], xx[0] / 100 - 5, xx[1] / 100);

			//51
			if (ntype[t] == 100) 
			{
				DrawFormatString(xx[0] / 100 + fma, xx[1] / 100 + fmb, GetColor(255, 255, 255), "51");
			}

			if (ntype[t] == 101)
					DrawFormatString(xx[0] / 100 + fma, xx[1] / 100 + fmb, GetColor(255, 255, 255),  "ゲームクリアー");

			if (ntype[t] == 102)
					DrawFormatString(xx[0] / 100 + fma, xx[1] / 100 + fmb, GetColor(255, 255, 255), "プレイしてくれてありがとー");
			}
		}	//t

		//グラ
		for (t = 0; t < emax; t++) 
		{
			xx[0] = ea[t] - fx;
			xx[1] = eb[t] - fy;
			xx[2] = enobia[t] / 100;
			xx[3] = enobib[t] / 100;

			if (xx[0] + xx[2] * 100 >= -10 && xx[1] <= fxmax && xx[1] + xx[3] * 100 >= -10 - 8000 && xx[3] <= fymax) 
			{

			//コイン
			if (egtype[t] == 0)
					drawimage(grap[0][2], xx[0] / 100, xx[1] / 100);

			//ブロックの破片
			if (egtype[t] == 1) 
			{
				if (stagecolor == 1 || stagecolor == 3 || stagecolor == 5)
					setcolor(9 * 16, 6 * 16, 3 * 16);
					
				if (stagecolor == 2)
					setcolor(0, 120, 160);
				
				if (stagecolor == 4)
					setcolor(192, 192, 192);

				fillarc(xx[0] / 100, xx[1] / 100, 7, 7);
				setcolor(0, 0, 0);
				drawarc(xx[0] / 100, xx[1] / 100, 7, 7);
			}

			//リフトの破片
			if (egtype[t] == 2 || egtype[t] == 3) 
			{
				if (egtype[t] == 3)
					mirror = 1;

				drawimage(grap[0][5], xx[0] / 100, xx[1] / 100);
				mirror = 0;
			}
			
			//ポール
			if (egtype[t] == 4) 
			{
				setc1();
				fillrect((xx[0]) / 100 + 10, (xx[1]) / 100, 10, xx[3]);
				setc0();
				drawrect((xx[0]) / 100 + 10, (xx[1]) / 100, 10, xx[3]);
				setcolor(250, 250, 0);
				fillarc((xx[0]) / 100 + 15 - 1, (xx[1]) / 100, 10, 10);
				setc0();
				drawarc((xx[0]) / 100 + 15 - 1, (xx[1]) / 100, 10, 10);
			}	// 4

		}
	}

	//リフト
		for (t = 0; t < srmax; t++) {
			xx[0] = sra[t] - fx;
			xx[1] = srb[t] - fy;
			if (xx[0] + src[t] >= -10 && xx[1] <= fxmax + 12100 && src[t] / 100 >= 1) 
			{
				xx[2] = 14;
				if (srsp[t] == 1) 
				{
					xx[2] = 12;
				}

			if (srsp[t] <= 9 || srsp[t] >= 20) 
			{
				setcolor(220, 220, 0);
				if (srsp[t] == 2 || srsp[t] == 3) 
				{
					setcolor(0, 220, 0);
				}

				if (srsp[t] == 21) 
				{
					setcolor(180, 180, 180);
				}

				fillrect((sra[t] - fx) / 100, (srb[t] - fy) / 100, src[t] / 100, xx[2]);

				setcolor(180, 180, 0);
				if (srsp[t] == 2 || srsp[t] == 3) 
				{
					setcolor(0, 180, 0);
				}

				if (srsp[t] == 21) 
				{
					setcolor(150, 150, 150);
				}
				
				drawrect((sra[t] - fx) / 100, (srb[t] - fy) / 100, src[t] / 100, xx[2]);
			} else 
				if (srsp[t] <= 14) 
				{
					if (src[t] >= 5000) 
					{
						setcolor(0, 200, 0);
						fillrect((sra[t] - fx) / 100, (srb[t] - fy) / 100, src[t] / 100, 30);
						setcolor(0, 160, 0);
						drawrect((sra[t] - fx) / 100, (srb[t] - fy) / 100, src[t] / 100, 30);

						setcolor(180, 120, 60);
						fillrect((sra[t] - fx) / 100 + 20, (srb[t] - fy) / 100 + 30, src[t] / 100 - 40, 480);
						setcolor(100, 80, 20);
						drawrect((sra[t] - fx) / 100 + 20, (srb[t] - fy) / 100 + 30, src[t] / 100 - 40, 480);
					}
				}
				
				if (srsp[t] == 15) 
				{
					for (t2 = 0; t2 <= 2; t2++) 
					{
						xx[6] = 1 + 0;
						drawimage(grap[xx[6]][1], (sra[t] - fx) / 100 + t2 * 29, (srb[t] - fy) / 100);
					}
				} //15
			}
		} //t

		//プレイヤー描画
		setcolor(0, 0, 255);

		if (mactp >= 2000) 
		{
			mactp -= 2000;
			if (mact == 0) 
			{
				mact = 1;
			} else {
				mact = 0;
			}
		}

		if (mmuki == 0)
			mirror = 1;

		if (mtype != 200 && mtype != 1) 
		{
			if (mzimen == 1) 
			{
				// 読みこんだグラフィックを拡大描画
				if (mact == 0)
					drawimage(grap[0][0], ma / 100, mb / 100);
					
				if (mact == 1)
					drawimage(grap[1][0], ma / 100, mb / 100);
			}

			if (mzimen == 0) 
			{
				drawimage(grap[2][0], ma / 100, mb / 100);
			}
		} //巨大化
			else 
			if (mtype == 1) 
			{
				drawimage(grap[41][0], ma / 100, mb / 100);
			} else 
				if (mtype == 200) 
				{
					drawimage(grap[3][0], ma / 100, mb / 100);
				}

		mirror = 0;

		//敵キャラ
		for (t = 0; t < amax; t++) 
		{
			xx[0] = aa[t] - fx;
			xx[1] = ab[t] - fy;
			xx[2] = anobia[t] / 100;
			xx[3] = anobib[t] / 100;
			xx[14] = 3000;
			xx[16] = 0;

			if (xx[0] + xx[2] * 100 >= -10 - xx[14] && xx[1] <= fxmax + xx[14] && xx[1] + xx[3] * 100 >= -10 && xx[3] <= fymax) 
			{
				if (amuki[t] == 1) 
				{
					mirror = 1;
				}

				if (atype[t] == 3 && axtype[t] == 1) 
				{
					DrawVertTurnGraph(xx[0] / 100 + 13, xx[1] / 100 + 15, grap[atype[t]][3]);
					xx[16] = 1;
				}

				if (atype[t] == 9 && ad[t] >= 1) 
				{
					DrawVertTurnGraph(xx[0] / 100 + 13, xx[1] / 100 + 15, grap[atype[t]][3]);
					xx[16] = 1;
				}
				
				if (atype[t] >= 100 && amuki[t] == 1)
					mirror = 0;

				//メイン
				if (atype[t] < 200 && xx[16] == 0
						&& atype[t] != 6 && atype[t] != 79
						&& atype[t] != 86 && atype[t] != 30)
				{
					if (!((atype[t] == 80 || atype[t] == 81)
							&& axtype[t] == 1)) 
					{
						drawimage(grap[atype[t]][3],
						xx[0] / 100, xx[1] / 100);
					}
				}

				//デフラグさん
				if (atype[t] == 6) 
				{
					if (atm[t] >= 10 && atm[t] <= 19 || atm[t] >= 100 && atm[t] <= 119 || atm[t] >= 200) 
					{
						drawimage(grap[150][3], xx[0] / 100, xx[1] / 100);
					} else {
						drawimage(grap[6][3], xx[0] / 100, xx[1] / 100);
					}
				}
			
				//モララー
				if (atype[t] == 30) 
				{
					if (axtype[t] == 0)
						drawimage(grap[30][3], xx[0] / 100, xx[1] / 100);

					if (axtype[t] == 1)
						drawimage(grap[155][3], xx[0] / 100, xx[1] / 100);
				}

				//ステルス雲
				if ((atype[t] == 81) && axtype[t] == 1) 
				{
					drawimage(grap[130][3], xx[0] / 100, xx[1] / 100);
				}

				if (atype[t] == 79) 
				{
					setcolor(250, 250, 0);
					fillrect(xx[0] / 100, xx[1] / 100, xx[2], xx[3]);
					setc0();
					drawrect(xx[0] / 100, xx[1] / 100, xx[2], xx[3]);
				}

				if (atype[t] == 82) 
				{
					if (axtype[t] == 0) 
					{
						xx[9] = 0;
						if (stagecolor == 2) 
						{
							xx[9] = 30;
						}

						if (stagecolor == 4) 
						{
							xx[9] = 60;
						}
					
						if (stagecolor == 5) 
						{
							xx[9] = 90;
						}

						xx[6] = 5 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
					}

					if (axtype[t] == 1)
					{
						xx[9] = 0;
						if (stagecolor == 2)
						{
							xx[9] = 30;
						}

						if (stagecolor == 4)
						{
							xx[9] = 60;
						}

						if (stagecolor == 5)
						{
							xx[9] = 90;
						}
						
						xx[6] = 4 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
					}

					if (axtype[t] == 2) 
					{
						drawimage(grap[1][5], xx[0] / 100, xx[1] / 100);
					}
				}

				if (atype[t] == 83) 
				{
					if (axtype[t] == 0) 
					{
						xx[9] = 0;
						if (stagecolor == 2) 
						{
							xx[9] = 30;
						}
						
						if (stagecolor == 4) 
						{
							xx[9] = 60;
						}

						if (stagecolor == 5) 
						{
							xx[9] = 90;
						}
						xx[6] = 5 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100 + 10, xx[1] / 100 + 9);
					}

					if (axtype[t] == 1) 
					{
						xx[9] = 0;
						if (stagecolor == 2) 
						{
							xx[9] = 30;
						}

						if (stagecolor == 4) 
						{
							xx[9] = 60;
						}
						
						if (stagecolor == 5) 
						{
							xx[9] = 90;
						}

						xx[6] = 4 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100 + 10, xx[1] / 100 + 9);
					}
				}

				//偽ポール
				if (atype[t] == 85) 
				{
					setc1();
					fillrect((xx[0]) / 100 + 10, (xx[1]) / 100, 10, xx[3]);
					setc0();
					drawrect((xx[0]) / 100 + 10, (xx[1]) / 100, 10, xx[3]);
					setcolor(0, 250, 200);
					fillarc((xx[0]) / 100 + 15 - 1, (xx[1]) / 100, 10, 10);
					setc0();
					drawarc((xx[0]) / 100 + 15 - 1, (xx[1]) / 100, 10, 10);
				}	//85

				//ニャッスン
				if (atype[t] == 86) 
				{
					if (ma >= aa[t] - fx - mnobia - 4000 && ma <= aa[t] - fx + anobia[t] + 4000) 
					{
						drawimage(grap[152][3], xx[0] / 100, xx[1] / 100);
					} else {
						drawimage(grap[86][3], xx[0] / 100, xx[1] / 100);
					}
				}

				if (atype[t] == 200)
					drawimage(grap[0][3], xx[0] / 100, xx[1] / 100);

				mirror = 0;

			}
		}

		//ブロック描画
		for (t = 0; t < tmax; t++) 
		{
			xx[0] = ta[t] - fx;
			xx[1] = tb[t] - fy;
			xx[2] = 32;
			xx[3] = xx[2];
			
			if (xx[0] + xx[2] * 100 >= -10 && xx[1] <= fxmax) 
			{
				xx[9] = 0;
				if (stagecolor == 2) 
				{
					xx[9] = 30;
				}

				if (stagecolor == 4) 
				{
					xx[9] = 60;
				}

				if (stagecolor == 5) 
				{
					xx[9] = 90;
				}

				if (ttype[t] < 100) 
				{
					xx[6] = ttype[t] + xx[9];
					drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
				}

				if (txtype[t] != 10) 
				{
					if (ttype[t] == 100 || ttype[t] == 101
							|| ttype[t] == 102
							|| ttype[t] == 103
							|| ttype[t] == 104 && txtype[t] == 1
							|| ttype[t] == 114 && txtype[t] == 1
							|| ttype[t] == 116) 
					{
						xx[6] = 2 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
					}

					if (ttype[t] == 112 || ttype[t] == 104
							&& txtype[t] == 0 || ttype[t] == 115
							&& txtype[t] == 1) 
					{
						xx[6] = 1 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
					}

					if (ttype[t] == 111 || ttype[t] == 113
							|| ttype[t] == 115 && txtype[t] == 0
							|| ttype[t] == 124) 
					{
						xx[6] = 3 + xx[9];
						drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
					}
				}

				if (ttype[t] == 117 && txtype[t] == 1) 
				{
					drawimage(grap[4][5], xx[0] / 100, xx[1] / 100);
				}

				if (ttype[t] == 117 && txtype[t] >= 3) 
				{
					drawimage(grap[3][5], xx[0] / 100, xx[1] / 100);
				}

				if (ttype[t] == 115 && txtype[t] == 3) 
				{
					xx[6] = 1 + xx[9];
					drawimage(grap[xx[6]][1], xx[0] / 100, xx[1] / 100);
				}

				//ジャンプ台
				if (ttype[t] == 120 && txtype[t] != 1) 
				{
					drawimage(grap[16][1], xx[0] / 100 + 3, xx[1] / 100 + 2);
				}
				//ON-OFF
				if (ttype[t] == 130)
					drawimage(grap[10][5], xx[0] / 100, xx[1] / 100);

				if (ttype[t] == 131)
					drawimage(grap[11][5], xx[0] / 100, xx[1] / 100);

				if (ttype[t] == 140)
					drawimage(grap[12][5], xx[0] / 100, xx[1] / 100);
				if (ttype[t] == 141)
					drawimage(grap[13][5], xx[0] / 100, xx[1] / 100);
				if (ttype[t] == 142)
					drawimage(grap[14][5], xx[0] / 100, xx[1] / 100);

				if (ttype[t] == 300 || ttype[t] == 301)
					drawimage(grap[1][5], xx[0] / 100, xx[1] / 100);

				//Pスイッチ
				if (ttype[t] == 400) 
				{
					drawimage(grap[2][5], xx[0] / 100, xx[1] / 100);
				}

				//コイン
				if (ttype[t] == 800) 
				{
					drawimage(grap[0][2], xx[0] / 100 + 2, xx[1] / 100 + 1);
				}
			}
		}

		//地面(壁)//土管も
		for (t = 0; t < smax; t++) 
		{
			if (sa[t] - fx + sc[t] >= -10 && sa[t] - fx <= fxmax + 1100) 
			{
				if (stype[t] == 0) 
				{
					setcolor(40, 200, 40);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, sc[t] / 100, sd[t] / 100);
					drawrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, sc[t] / 100, sd[t] / 100);
				}

				//土管
				if (stype[t] == 1) 
				{
					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, sc[t] / 100, sd[t] / 100);
					setc0();
					drawrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, sc[t] / 100, sd[t] / 100);
				}

				//土管(下)
				if (stype[t] == 2) 
				{
					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, sc[t] / 100, sd[t] / 100);
					setc0();
					drawline((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, (sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + sd[t] / 100);
					drawline((sa[t] - fx) / 100 + fma + sc[t] / 100, (sb[t] - fy) / 100 + fmb, (sa[t] - fx) / 100 + fma + sc[t] / 100, (sb[t] - fy) / 100 + fmb + sd[t] / 100);
				}
				
				//土管(横)
				if (stype[t] == 5) 
				{
					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, sc[t] / 100, sd[t] / 100);
					setc0();
					drawline((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, (sa[t] - fx) / 100 + fma + sc[t] / 100, (sb[t] - fy) / 100 + fmb);
					drawline((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + sd[t] / 100, (sa[t] - fx) / 100 + fma + sc[t] / 100, (sb[t] - fy) / 100 + fmb + sd[t] / 100);
				}
				
				//落ちてくるブロック
				if (stype[t] == 51) 
				{
					if (sxtype[t] == 0) 
					{
						for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
						{
							drawimage(grap[1][1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb); 
						}
					}

					if (sxtype[t] == 1 || sxtype[t] == 2) 
					{
						for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
						{
							drawimage(grap[31][1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb);
						}
					}

					if (sxtype[t] == 3 || sxtype[t] == 4) 
					{
						for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
						{
							for (t2 = 0; t2 <= sd[t] / 3000; t2++) 
							{
								drawimage(grap[65] [1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + 29 * t2 + fmb);
							}
						}
					}

					if (sxtype[t] == 10) 
					{
						for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
						{
							drawimage(grap[65][1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb);
						}
					}
				}	//51

				//落ちるやつ
				if (stype[t] == 52) 
				{
					xx[29] = 0;
					if (stagecolor == 2) 
					{
						xx[29] = 30;
					}
					
					if (stagecolor == 4) 
					{
						xx[29] = 60;
					}
					if (stagecolor == 5) 
					{
						xx[29] = 90;
					}

					for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
					{
						if (sxtype[t] == 0) 
						{
							drawimage(grap [5 + xx[29]][1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb);
							if (stagecolor != 4) 
							{
								drawimage(grap[6 + xx[29]] [1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb + 29);
							} else {
								drawimage(grap[5 + xx[29]] [1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb + 29);
							}
						}
						
						if (sxtype[t] == 1) 
						{
							for (t2 = 0; t2 <= sd[t] / 3000; t2++) 
							{
								drawimage(grap[1 + xx[29]] [1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb + 29 * t2);
							}
						}

						if (sxtype[t] == 2) 
						{
							for (t2 = 0; t2 <= sd[t] / 3000; t2++) 
							{
								drawimage(grap[5 + xx[29]] [1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + fmb + 29 * t2);
							}
						}
					}
				}
				
				//ステージトラップ
				if (trap == 1) 
				{
					if (stype[t] >= 100 && stype[t] <= 299) 
					{
						if (stagecolor == 1 || stagecolor == 3 || stagecolor == 5) 
							setc0();
							
						if (stagecolor == 2 || stagecolor == 4)
							setc1();

						drawrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb, sc[t] / 100, sd[t] / 100);
					}
				}
				
				//ゴール
				if (stype[t] == 300) 
				{
					setc1();
					fillrect((sa[t] - fx) / 100 + 10, (sb[t] - fy) / 100, 10, sd[t] / 100 - 8);
					setc0();
					drawrect((sa[t] - fx) / 100 + 10, (sb[t] - fy) / 100, 10, sd[t] / 100 - 8);
					setcolor(250, 250, 0);
					fillarc((sa[t] - fx) / 100 + 15 - 1, (sb[t] - fy) / 100, 10, 10);
					setc0();
					drawarc((sa[t] - fx) / 100 + 15 - 1, (sb[t] - fy) / 100, 10, 10);
				}

				//中間
				if (stype[t] == 500) 
				{
					drawimage(grap[20][4], (sa[t] - fx) / 100, (sb[t] - fy) / 100);
				}
			}
		}	//t

		//描画上書き(土管)
		for (t = 0; t < smax; t++) 
		{
			if (sa[t] - fx + sc[t] >= -10 && sa[t] - fx <= fxmax + 1100) 
			{
				//入る土管(右)
				if (stype[t] == 40) 
				{
					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, sc[t] / 100, sd[t] / 100);
					setc0();
					drawrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, sc[t] / 100, sd[t] / 100);
				}

				//とぶ土管
				if (stype[t] == 50) 
				{
					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma + 5, (sb[t] - fy) / 100 + fmb + 30, 50, sd[t] / 100 - 30);
					setc0();
					drawline((sa[t] - fx) / 100 + 5 + fma, (sb[t] - fy) / 100 + fmb + 30, (sa[t] - fx) / 100 + fma + 5, (sb[t] - fy) / 100 + fmb + sd[t] / 100);
					drawline((sa[t] - fx) / 100 + 5 + fma + 50, (sb[t] - fy) / 100 + fmb + 30, (sa[t] - fx) / 100 + fma + 50 + 5, (sb[t] - fy) / 100 + fmb + sd[t] / 100);

					setcolor(0, 230, 0);
					fillrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, 60, 30);
					setc0();
					drawrect((sa[t] - fx) / 100 + fma, (sb[t] - fy) / 100 + fmb + 1, 60, 30);
				}

				//地面(ブロック)
				if (stype[t] == 200) 
				{
					for (t3 = 0; t3 <= sc[t] / 3000; t3++) 
					{
						for (t2 = 0; t2 <= sd[t] / 3000; t2++) 
						{
							drawimage(grap[65][1], (sa[t] - fx) / 100 + fma + 29 * t3, (sb[t] - fy) / 100 + 29 * t2 + fmb);
						}
					}
				}
			}
		}	// t

		//ファイアバー
		for (t = 0; t < amax; t++) 
		{
			xx[0] = aa[t] - fx;
			xx[1] = ab[t] - fy;
			xx[14] = 12000;
			xx[16] = 0;

			if (atype[t] == 87 || atype[t] == 88) 
			{
				if (xx[0] + xx[2] * 100 >= -10 - xx[14]
						&& xx[1] <= fxmax + xx[14]
						&& xx[1] + xx[3] * 100 >= -10 && xx[3] <= fymax) 
				{
					for (tt = 0; tt <= axtype[t] % 100; tt++) 
					{
						xx[26] = 18;
						xd[4] = tt * xx[26] * cos(atm[t] * pai / 180 / 2);
						xd[5] = tt * xx[26] * sin(atm[t] * pai / 180 / 2);
						xx[24] = (int) xd[4];
						xx[25] = (int) xd[5];
						setcolor(230, 120, 0);
						xx[23] = 8;

						if (atype[t] == 87) 
						{
							fillarc(xx[0] / 100 + xx[24], xx[1] / 100 + xx[25], xx[23], xx[23]);
							setcolor(0, 0, 0);
							drawarc(xx[0] / 100 + xx[24], xx[1] / 100 + xx[25], xx[23], xx[23]);
						} else {
							fillarc(xx[0] / 100 - xx[24], xx[1] / 100 + xx[25], xx[23], xx[23]);
							setcolor(0, 0, 0);
							drawarc(xx[0] / 100 - xx[24], xx[1] / 100 + xx[25], xx[23], xx[23]);
						}
					}
				}
			}
		}

		//プレイヤーのメッセージ
		setc0();

		if (mmsgtm >= 1) 
		{
			mmsgtm--;
			xs[0] = "";

			if (mmsgtype == 1)
				xs[0] = "お、おいしい!!";

			if (mmsgtype == 2)
				xs[0] = "毒は無いが……";

			if (mmsgtype == 3)
				xs[0] = "刺さった!!";

			if (mmsgtype == 10)
				xs[0] = "食べるべきではなかった!!";

			if (mmsgtype == 11)
				xs[0] = "俺は燃える男だ!!";

			if (mmsgtype == 50)
				xs[0] = "体が……焼ける……";

			if (mmsgtype == 51)
				xs[0] = "たーまやー!!";

			if (mmsgtype == 52)
				xs[0] = "見事にオワタ";

			if (mmsgtype == 53)
				xs[0] = "足が、足がぁ!!";

			if (mmsgtype == 54)
				xs[0] = "流石は摂氏800度!!";

			if (mmsgtype == 55)
				xs[0] = "溶岩と合体したい……";

			setc0();
			str(xs[0], (ma + mnobia + 300) / 100 - 1, mb / 100 - 1);
			str(xs[0], (ma + mnobia + 300) / 100 + 1, mb / 100 + 1);
			setc1();
			str(xs[0], (ma + mnobia + 300) / 100, mb / 100);
		}	//mmsgtm

		//敵キャラのメッセージ
		setc0();
		for (t = 0; t < amax; t++) 
		{
			if (amsgtm[t] >= 1) 
			{
				amsgtm[t]--;	//end();

				xs[0] = "";

				if (amsgtype[t] == 1001)
					xs[0] = "ヤッフー!!";

				if (amsgtype[t] == 1002)
					xs[0] = "え?俺勝っちゃったの?";

				if (amsgtype[t] == 1003)
					xs[0] = "貴様の死に場所はここだ!";

				if (amsgtype[t] == 1004)
					xs[0] = "二度と会う事もないだろう";

				if (amsgtype[t] == 1005)
					xs[0] = "俺、最強!!";

				if (amsgtype[t] == 1006)
					xs[0] = "一昨日来やがれ!!";

				if (amsgtype[t] == 1007)
					xs[0] = "漢に後退の二文字は無い!!";

				if (amsgtype[t] == 1008)
					xs[0] = "ハッハァ!!";

				if (amsgtype[t] == 1011)
					xs[0] = "ヤッフー!!";

				if (amsgtype[t] == 1012)
					xs[0] = "え?俺勝っちゃったの?";

				if (amsgtype[t] == 1013)
					xs[0] = "貴様の死に場所はここだ!";

				if (amsgtype[t] == 1014)
					xs[0] = "身の程知らずが……";

				if (amsgtype[t] == 1015)
					xs[0] = "油断が死を招く";

				if (amsgtype[t] == 1016)
					xs[0] = "おめでたい奴だ";

				if (amsgtype[t] == 1017)
					xs[0] = "屑が!!";

				if (amsgtype[t] == 1018)
					xs[0] = "無謀な……";

				if (amsgtype[t] == 1021)
					xs[0] = "ヤッフー!!";

				if (amsgtype[t] == 1022)
					xs[0] = "え?俺勝っちゃったの?";

				if (amsgtype[t] == 1023)
					xs[0] = "二度と会う事もないだろう";

				if (amsgtype[t] == 1024)
					xs[0] = "身の程知らずが……";

				if (amsgtype[t] == 1025)
					xs[0] = "僕は……負けない!!";

				if (amsgtype[t] == 1026)
					xs[0] = "貴様に見切れる筋は無い";

				if (amsgtype[t] == 1027)
					xs[0] = "今死ね、すぐ死ね、骨まで砕けろ!!";
						
				if (amsgtype[t] == 1028)
					xs[0] = "任務完了!!";

				if (amsgtype[t] == 1031)
					xs[0] = "ヤッフー!!";
					
				if (amsgtype[t] == 1032)
					xs[0] = "え?俺勝っちゃったの?";
					
				if (amsgtype[t] == 1033)
					xs[0] = "貴様の死に場所はここだ!";

				if (amsgtype[t] == 1034)
					xs[0] = "身の程知らずが……";

				if (amsgtype[t] == 1035)
					xs[0] = "油断が死を招く";

				if (amsgtype[t] == 1036)
					xs[0] = "おめでたい奴だ";

				if (amsgtype[t] == 1037)
					xs[0] = "屑が!!";

				if (amsgtype[t] == 1038)
					xs[0] = "無謀な……";

				if (amsgtype[t] == 15)
					xs[0] = "鉄壁!!よって、無敵!!";

				if (amsgtype[t] == 16)
					xs[0] = "丸腰で勝てるとでも?";

				if (amsgtype[t] == 17)
					xs[0] = "パリイ!!";
					
				if (amsgtype[t] == 18)
					xs[0] = "自業自得だ";

				if (amsgtype[t] == 20)
					xs[0] = "Zzz";

				if (amsgtype[t] == 21)
					xs[0] = "ク、クマー";

				if (amsgtype[t] == 24)
					xs[0] = "?";

				if (amsgtype[t] == 25)
					xs[0] = "食べるべきではなかった!!";

				if (amsgtype[t] == 30)
					xs[0] = "うめぇ!!";

				if (amsgtype[t] == 31)
					xs[0] = "ブロックを侮ったな?";

				if (amsgtype[t] == 32)
					xs[0] = "シャキーン";

				if (amsgtype[t] == 50)
					xs[0] = "波動砲!!";
					
				if (amsgtype[t] == 85)
					xs[0] = "裏切られたとでも思ったか?";

				if (amsgtype[t] == 86)
					xs[0] = "ポールアターック!!";

				if (amsgtype[t] != 31) 
				{
					xx[5] = (aa[t] + anobia[t] + 300 - fx) / 100;
					xx[6] = (ab[t] - fy) / 100;
				} else {
					xx[5] = (aa[t] + anobia[t] + 300 - fx) / 100;
					xx[6] = (ab[t] - fy - 800) / 100;
				}

				ChangeFontType(DX_FONTTYPE_EDGE);
				setc1();
				str(xs[0], xx[5], xx[6]);
				ChangeFontType(DX_FONTTYPE_NORMAL);
			}	// amsgtm
		}	// amax

		//メッセージブロック
		if (tmsgtm > 0) 
		{
			ttmsg();
			if (tmsgtype == 1) 
			{
				xx[0] = 1200;
				tmsgy += xx[0];

				if (tmsgtm == 1) 
				{
					tmsgtm = 80000000;
					tmsgtype = 2;
				}
			}	// 1
				else 
				if (tmsgtype == 2) 
				{
					tmsgy = 0;
					tmsgtype = 3;
					tmsgtm = 15 + 1;
				}	else 
					if (tmsgtype == 3) 
					{
						xx[0] = 1200;
						tmsgy += xx[0];
						if (tmsgtm == 15)
							WaitKey();

						if (tmsgtm == 1) 
						{
							tmsgtm = 0;
							tmsgtype = 0;
							tmsgy = 0;
						}
					}	// 1

			tmsgtm--;
		}	// tmsgtm

		//メッセージ
		if (mainmsgtype >= 1) 
		{
			setfont(20, 4);
			if (mainmsgtype == 1) 
			{
				DrawFormatString(126, 100, GetColor(255, 255, 255), "WELCOME TO OWATA ZONE");
			}
			if (mainmsgtype == 1) 
			{
				for (t2 = 0; t2 <= 2; t2++)
					DrawFormatString(88 + t2 * 143, 210, GetColor(255, 255, 255), "1");
			}
			setfont(20, 5);
		}	// mainmsgtype>=1

		//画面黒
		if (blacktm > 0) 
		{
			blacktm--;
			fillrect(0, 0, fxmax, fymax);
			if (blacktm == 0) 
			{
				if (blackx == 1) 
				{
					zxon = 0;
				}
			}
		} // blacktm
	}

  if (mainZ == 2) 
	{
		setcolor(255, 255, 255);
		str("制作・プレイに関わった方々", 240 - 13 * 20 / 2, xx[12] / 100);
		str("ステージ１　プレイ", 240 - 9 * 20 / 2, xx[13] / 100);
		//Theres an encoding error here, this is only temporary
		//str("æy@]`y",240-6*20/2,xx[14]/100);
		str("TODO: Fix this encoding error...",240-6*20/2,xx[14]/100);
		str("ステージ２　プレイ", 240 - 9 * 20 / 2, xx[15] / 100);
		str("友人　willowlet ", 240 - 8 * 20 / 2, xx[16] / 100);
		str("ステージ３　プレイ", 240 - 9 * 20 / 2, xx[17] / 100);
		str("友人　willowlet ", 240 - 8 * 20 / 2, xx[18] / 100);
		str("ステージ４　プレイ", 240 - 9 * 20 / 2, xx[19] / 100);
		str("友人２　ann ", 240 - 6 * 20 / 2, xx[20] / 100);
		str("ご協力", 240 - 3 * 20 / 2, xx[21] / 100);
		str("Ｔ先輩", 240 - 3 * 20 / 2, xx[22] / 100);
		str("Ｓ先輩", 240 - 3 * 20 / 2, xx[23] / 100);
		str("動画技術提供", 240 - 6 * 20 / 2, xx[24] / 100);
		str("Ｋ先輩", 240 - 3 * 20 / 2, xx[25] / 100);
		str("動画キャプチャ・編集・エンコード", 240 - 16 * 20 / 2, xx[26] / 100);
		str("willowlet ", 240 - 5 * 20 / 2, xx[27] / 100);
		str("プログラム・描画・ネタ・動画編集", 240 - 16 * 20 / 2, xx[28] / 100);
		str("ちく", 240 - 2 * 20 / 2, xx[29] / 100);
		str("プレイしていただき　ありがとうございました〜", 240 - 22 * 20 / 2, xx[30] / 100);
  }
	
	//Showing lives
	if (mainZ == 10) 
	{
		setc0();
		FillScreen();

		SetFontSize(16);
		SetFontThickness(4);

		drawimage(grap[0][0], 190, 190);
		DrawFormatString(230, 200, GetColor(255, 255, 255), " × %d", nokori);
  }

	//タイトル
	if (mainZ == 100) 
	{
		setcolor(160, 180, 250);
		fillrect(0, 0, fxmax, fymax);

		drawimage(mgrap[30], 240 - 380 / 2, 60);

		drawimage(grap[0][4], 12 * 30, 10 * 29 - 12);
		drawimage(grap[1][4], 6 * 30, 12 * 29 - 12);

		//プレイヤー
		drawimage(grap[0][0], 2 * 30, 12 * 29 - 12 - 6);
		for (t = 0; t <= 16; t++) 
		{
			drawimage(grap[5][1], 29 * t, 13 * 29 - 12);
			drawimage(grap[6][1], 29 * t, 14 * 29 - 12);
		}

		setcolor(0, 0, 0);
		str("Enterキーを押せ!!", 240 - 8 * 20 / 2, 250);

  }

  ScreenFlip();
}	// rpaint()