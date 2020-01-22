#include "game_progress.h"

//メインプログラム
void Mainprogram()
{
	stime = long (GetNowCount());
	
	if (ending == 1)
		mainZ = 2;

	//キー
	if (mainZ == 1 && tmsgtype == 0) 
	{
		if (zxon == 0) 
		{
	    zxon = 1;
	    mainmsgtype = 0;

	    stagecolor = 1;
	    ma = 5600;
	    mb = 32000;
	    mmuki = 1;
	    mhp = 1;
	    mc = 0;
	    md = 0;
	    mnobia = 3000;
	    mnobib = 3600;

	    mtype = 0;

	    fx = 0;
	    fy = 0;
	    fzx = 0;
	    stageonoff = 0;

			//チーターマン　入れ
	    bgmchange(otom[1]);

	    stagecls();

	    stage();

			//ランダムにさせる
	    if (over == 1) 
			{
				for (t = 0; t < tmax; t++) 
				{
					if (rand(3) <= 1) 
					{
						ta[t] = (rand(500) - 1) * 29 * 100;
						tb[t] = rand(14) * 100 * 29 - 1200;
						ttype[t] = rand(142);

						if (ttype[t] >= 9 && ttype[t] <= 99) 
						{
							ttype[t] = rand(8);
						}
						txtype[t] = rand(4);
					}
				}

				for (t = 0; t < bmax; t++) 
				{
					if (rand(2) <= 1) 
					{
						ba[t] = (rand(500) - 1) * 29 * 100;
						bb[t] = rand(15) * 100 * 29 - 1200 - 3000;
						
						if (rand(6) == 0) 
						{
							btype[t] = rand(9);
						}
					}
				}

				srco = 0;
				t = srco;
				sra[t] = ma + fx;
				srb[t] = (13 * 29 - 12) * 100;
				src[t] = 30 * 100;
				srtype[t] = 0;
				sracttype[t] = 0;
				sre[t] = 0;
				srsp[t] = 0;
				srco++;

				if (rand(4) == 0)
					stagecolor = rand(5);
	    }
		}	// zxon

		//プレイヤーの移動
		xx[0] = 0;
		actaon[2] = 0;
		actaon[3] = 0;
		if (mkeytm <= 0) 
		{
			if (CheckHitKey(KEY_INPUT_LEFT) && keytm <= 0) 
			{
				actaon[0] = -1;
				mmuki = 0;
				actaon[4] = -1;
			}

			if (CheckHitKey(KEY_INPUT_RIGHT) && keytm <= 0) 
			{
				actaon[0] = 1;
				mmuki = 1;
				actaon[4] = 1;
			}
			
			if (CheckHitKey(KEY_INPUT_DOWN)) 
			{
				actaon[3] = 1;
			}
		}

		//if (CheckHitKey(KEY_INPUT_F1)==1){end();}
		if (CheckHitKey(KEY_INPUT_F1) == 1) 
		{
			mainZ = 100;
		}

		//if (CheckHitKey(KEY_INPUT_Q)==1){mkeytm=0;}
		if (CheckHitKey(KEY_INPUT_O) == 1) 
		{
			if (mhp >= 1)
				mhp = 0;
			if (stc >= 5) 
			{
				stc = 0;
				stagepoint = 0;
			}
		}

		if (mkeytm <= 0) 
		{
			if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_UP) == 1
					|| SDL_JoystickGetButton(joystick, JOYSTICK_JUMP)) 
			{
				if (actaon[1] == 10) 
				{
					actaon[1] = 1;
					xx[0] = 1;
				}
				actaon[2] = 1;
			}
		}

		if (CheckHitKey(KEY_INPUT_Z) == 1
				|| CheckHitKey(KEY_INPUT_UP) == 1
				|| SDL_JoystickGetButton(joystick, JOYSTICK_JUMP)) 
		{
			if (mjumptm == 8 && md >= -900) 
			{
				md = -1300;

				//ダッシュ中
				xx[22] = 200;
				if (mc >= xx[22] || mc <= -xx[22]) 
				{
					md = -1400;
				}

				xx[22] = 600;
				if (mc >= xx[22] || mc <= -xx[22]) 
				{
					md = -1500;
				}
			}

			// && xx[0]==0 && md<=-10

			//if (mjumptm==7 && md>=-900){}
			if (xx[0] == 0)
				actaon[1] = 10;
		}
		//if (( key & PAD_INPUT_UP) && keytm<=0){actaon[0]=-1;mmuki=0;}

		//xx[0]=200;
		//if (actaon[0]==-1){ma-=xx[0];}
		//if (actaon[0]==1){ma+=xx[0];}

		//加速による移動
		xx[0] = 40;
		xx[1] = 700;
		xx[8] = 500;
		xx[9] = 700;
		xx[12] = 1;
		xx[13] = 2;

		//すべり補正
		if (mrzimen == 1) 
		{
				xx[0] = 20;
				xx[12] = 9;
				xx[13] = 10;
		}

	//if (mzimen==0){xx[0]-=15;}
	if (actaon[0] == -1) 
	{
		if (!(mzimen == 0 && mc < -xx[8])) 
		{
			if (mc >= -xx[9]) 
			{
		    mc -= xx[0];
		    if (mc < -xx[9]) 
				{
					mc = -xx[9] - 1;
		    }
			}

			if (mc < -xx[9] && atktm <= 0)
		    mc -= xx[0] / 10;
		}

		if (mrzimen != 1) 
		{
			if (mc > 100 && mzimen == 0) 
			{
		    mc -= xx[0] * 2 / 3;
			}

			if (mc > 100 && mzimen == 1) 
			{
		    mc -= xx[0];
		    if (mzimen == 1) 
				{
					mc -= xx[0] * 1 / 2;
		    }
			}

			actaon[0] = 3;
			mkasok += 1;
		}
	}

	if (actaon[0] == 1) 
	{
		if (!(mzimen == 0 && mc > xx[8])) 
		{
			if (mc <= xx[9]) 
			{
		    mc += xx[0];
		    if (mc > xx[9]) 
				{
					mc = xx[9] + 1;
		    }
			}

			if (mc > xx[9] && atktm <= 0)
		    mc += xx[0] / 10;
	  }

		if (mrzimen != 1) 
		{
			if (mc < -100 && mzimen == 0) 
			{
		    mc += xx[0] * 2 / 3;
			}

			if (mc < -100 && mzimen == 1) 
			{
		    mc += xx[0];
		    if (mzimen == 1) 
				{
					mc += xx[0] * 1 / 2;
		    }
			}
			actaon[0] = 3;
			mkasok += 1;
	  }
	}

	if (actaon[0] == 0 && mkasok > 0) 
	{
		mkasok -= 2;
	}

	if (mkasok > 8) 
	{
		mkasok = 8;
	}

	//すべり補正初期化
	if (mzimen != 1)
		mrzimen = 0;

	//ジャンプ
	if (mjumptm >= 0)
	    mjumptm--;

	if (actaon[1] == 1 && mzimen == 1) 
	{
		mb -= 400;
		md = -1200;
		mjumptm = 10;

		//PlaySound( "jump.mp3" , DX_PLAYTYPE_NORMAL ) ;

		//PlayMusic( "SE/jump.mp3" , DX_PLAYTYPE_NORMAL ) ;

		//PlaySoundMem( oto[1], DX_PLAYTYPE_NORMAL ) ;

		//PlaySoundMem( oto[1], DX_PLAYTYPE_BACK) ;
		ot(oto[1]);

		/*
		md=-1040;
		xx[1]=600;if (mc>xx[1] || mc<=-xx[1]){md=-1400;}
		xx[1]=7;xx[2]=400;
		if (mkasok>xx[1] && (mc>xx[2] || mc<=-xx[2])){
		md=-1600;
		if (mc>=800 || mc<=-800){md=-1800;}
		}
		*/

		mzimen = 0;
	}

	if (actaon[1] <= 9)
		actaon[1] = 0;

	//if (actaon[1]==1){my+=xx[1];actaon[1]=0;}

	//}//陸地

	if (mmutekitm >= -1)
	    mmutekitm--;

	//HPがなくなったとき
	if (mhp <= 0 && mhp >= -9) 
	{
		mkeytm = 12;
		mhp = -20;
		mtype = 200;
		mtm = 0;
		Mix_HaltChannel(-1);
		Mix_HaltMusic();
		ot(oto[12]);
		StopSoundMem(oto[16]);
	}	//mhp

	//if (mhp<=-10){
	if (mtype == 200) 
	{
		if (mtm <= 11) 
		{
			mc = 0;
			md = 0;
		}

		if (mtm == 12) 
		{
			md = -1200;
		}

		if (mtm >= 12) 
		{
			mc = 0;
		}

		if (mtm >= 100 || fast == 1) 
		{
			zxon = 0;
			mainZ = 10;
			mtm = 0;
			mkeytm = 0;
			nokori--;
			if (fast == 1)
				mtype = 0;
		}	//mtm>=100
	}	//mtype==200

	//音符によるワープ
	if (mtype == 2) 
	{
		mtm++;

		mkeytm = 2;
		md = -1500;

		if (mb <= -6000) 
		{
			blackx = 1;
			blacktm = 20;
			stc += 5;
			stagerr = 0;
			Mix_HaltMusic();
			mtm = 0;
			mtype = 0;
			mkeytm = -1;
		}
	}	// 2

	//ジャンプ台アウト
	if (mtype == 3) 
	{
		md = -2400;
		if (mb <= -6000) 
		{
			mb = -80000000;
			mhp = 0;
		}
	}

	//mtypeによる特殊的な移動
	if (mtype >= 100) 
	{
		mtm++;

		//普通の土管
		if (mtype == 100) 
		{
			if (mxtype == 0) 
			{
		    mc = 0;
		    md = 0;
		    t = 28;
		    if (mtm <= 16) 
				{
					mb += 240;
					mzz = 100;
		    }

		    if (mtm == 17) 
				{
					mb = -80000000;
		    }

		    if (mtm == 23) 
				{
					sa[t] -= 100;
		    }

		    if (mtm >= 44 && mtm <= 60) 
				{
					if (mtm % 2 == 0)
						sa[t] += 200;

					if (mtm % 2 == 1)
						sa[t] -= 200;
		    }

		    if (mtm >= 61 && mtm <= 77) 
				{
					if (mtm % 2 == 0)
						sa[t] += 400;
					if (mtm % 2 == 1)
						sa[t] -= 400;
		    }

		    if (mtm >= 78 && mtm <= 78 + 16) 
				{
					if (mtm % 2 == 0)
						sa[t] += 600;

					if (mtm % 2 == 1)
						sa[t] -= 600;
		    }

		    if (mtm >= 110) 
				{
					sb[t] -= mzz;
					mzz += 80;
					
					if (mzz > 1600)
						mzz = 1600;
		    }

		    if (mtm == 160) 
				{
					mtype = 0;
					mhp--;
		    }
			} // ふっとばし
				else 
				if (mxtype == 10) 
				{
		    	mc = 0;
		    	md = 0;
		    	if (mtm <= 16) 
					{
						ma += 240;
					}		//mzz=100;}

					if (mtm == 16)
						mb -= 1100;

					if (mtm == 20)
						ot(oto[10]);

					if (mtm >= 24) 
					{
						ma -= 2000;
						mmuki = 0;
		    	}

					if (mtm >= 48) 
					{
						mtype = 0;
						mhp--;
					}
				} else {
					mc = 0;
					md = 0;

					if (mtm <= 16 && mxtype != 3) 
					{
						mb += 240;
					}	// mzz=100;}

					if (mtm <= 16 && mxtype == 3) 
					{
						ma += 240;
					}

					if (mtm == 19 && mxtype == 2) 
					{
						mhp = 0;
						mtype = 2000;
						mtm = 0;
						mmsgtm = 30;
						mmsgtype = 51;
					}

					if (mtm == 19 && mxtype == 5) 
					{
						mhp = 0;
						mtype = 2000;
						mtm = 0;
						mmsgtm = 30;
						mmsgtype = 52;
					}

					if (mtm == 20) 
					{
						if (mxtype == 6) 
						{
							stc += 10;
						} else {
							stc++;
						}
						mb = -80000000;
						mxtype = 0;
						blackx = 1;
						blacktm = 20;
						stagerr = 0;
						Mix_HaltMusic();
					}
				}
	    }	// 00

	    if (mtype == 300) 
			{
				mkeytm = 3;
				if (mtm <= 1) 
				{
					mc = 0;
					md = 0;
				}
				if (mtm >= 2 && mtm <= 42) 
				{
					md = 600;
					mmuki = 1;
				}
				if (mtm > 43 && mtm <= 108) 
				{
					mc = 300;
				}

				if (mtm == 110) 
				{
					mb = -80000000;
					mc = 0;
				}

				if (mtm == 250) 
				{
					stb++;
					stc = 0;
					zxon = 0;
					tyuukan = 0;
					mainZ = 10;
					maintm = 0;
				}
	    }	// mtype==300

	    if (mtype == 301 || mtype == 302) 
			{
				mkeytm = 3;

				if (mtm <= 1) 
				{
					mc = 0;
					md = 0;
				}

				if (mtm >= 2 && (mtype == 301 && mtm <= 102 || mtype == 302 && mtm <= 60)) 
				{
					xx[5] = 500;
					ma -= xx[5];
					fx += xx[5];
					fzx += xx[5];
				}

				if ((mtype == 301 || mtype == 302) && mtm >= 2 && mtm <= 100) 
				{
					mc = 250;
					mmuki = 1;
				}

				if (mtm == 200) 
				{
					ot(oto[17]);
					if (mtype == 301) 
					{
						na[nco] = 117 * 29 * 100 - 1100;
						nb[nco] = 4 * 29 * 100;
						ntype[nco] = 101;
						nco++;

						if (nco >= nmax)
							nco = 0;
							na[nco] = 115 * 29 * 100 - 1100;
							nb[nco] = 6 * 29 * 100;
							ntype[nco] = 102;
							nco++;

						if (nco >= nmax)
							nco = 0;
					} else {
						na[nco] = 157 * 29 * 100 - 1100;
						nb[nco] = 4 * 29 * 100;
						ntype[nco] = 101;
						nco++;
						if (nco >= nmax)
							nco = 0;

						na[nco] = 155 * 29 * 100 - 1100;
						nb[nco] = 6 * 29 * 100;
						ntype[nco] = 102;
						nco++;

						if (nco >= nmax)
							nco = 0;
					}
				}

				//スタッフロールへ
				if (mtm == 440) 
				{
					if (mtype == 301) 
					{
						ending = 1;
					} else {
						sta++;
						stb = 1;
						stc = 0;
						zxon = 0;
						tyuukan = 0;
						mainZ = 10;
						maintm = 0;
					}
				}

				/*
				if (mtm<=1){mc=0;md=0;}
				if (mtm>=2 && mtm<=42){md=600;mmuki=1;}
				if (mtm>43 && mtm<=108){mc=300;}
				if (mtm==110){mb=-80000000;mc=0;}
				if (mtm==250)end();
				*/
			}	// mtype==301
		}	//mtype>=100

	//移動
	if (mkeytm >= 1) 
	{
		mkeytm--;
	}	// mc=0;}

	ma += mc;
	mb += md;
	if (mc < 0)
		mactp += (-mc);
	if (mc >= 0)
		mactp += mc;

	if (mtype <= 9 || mtype == 200 || mtype == 300 || mtype == 301 || mtype == 302)
		md += 100;

	//走る際の最大値
	if (mtype == 0) 
	{
		xx[0] = 800;
		xx[1] = 1600;

		if (mc > xx[0] && mc < xx[0] + 200) 
		{
			mc = xx[0];
		}

		if (mc > xx[0] + 200) 
		{
			mc -= 200;
		}

		if (mc < -xx[0] && mc > -xx[0] - 200) 
		{
			mc = -xx[0];
		}
		if (mc < -xx[0] - 200) 
		{
			mc += 200;
		}
		if (md > xx[1]) 
		{
			md = xx[1];
		}
	}

	//プレイヤー
	//地面の摩擦
	if (mzimen == 1 && actaon[0] != 3) 
	{
		if ((mtype <= 9) || mtype == 300 || mtype == 301 || mtype == 302) 
		{
			if (mrzimen == 0) 
			{
		    xx[2] = 30;
		    xx[1] = 60;
		    xx[3] = 30;
		    if (mc >= -xx[3] && mc <= xx[3]) 
				{
					mc = 0;
		    }

		    if (mc >= xx[2]) 
				{
					mc -= xx[1];
		    }

		    if (mc <= -xx[2]) 
				{
					mc += xx[1];
		    }
			}
			if (mrzimen == 1) 
			{
		    xx[2] = 5;
		    xx[1] = 10;
		    xx[3] = 5;
		    if (mc >= -xx[3] && mc <= xx[3]) 
				{
					mc = 0;
		    }
				
		    if (mc >= xx[2]) 
				{
					mc -= xx[1];
		    }

		    if (mc <= -xx[2]) 
				{
					mc += xx[1];
		    }
			}
	  }
	}

	//地面判定初期化
	mzimen = 0;

	//場外
	if (mtype <= 9 && mhp >= 1) 
	{
		if (ma < 100) 
		{
			ma = 100;
			mc = 0;
		}
		if (ma + mnobia > fxmax) 
		{
			ma = fxmax - mnobia;
			mc = 0;
		}
	}

	//if (mb>=42000){mb=42000;mzimen=1;}
	if (mb >= 38000 && mhp >= 0 && stagecolor == 4) 
	{
		mhp = -2;
		mmsgtm = 30;
		mmsgtype = 55;
	}

	if (mb >= 52000 && mhp >= 0) 
	{
		mhp = -2;
	}

	//ブロック
	//1-れんが、コイン、無し、土台、7-隠し

	xx[15] = 0;
	for (t = 0; t < tmax; t++) 
	{
		xx[0] = 200;
		xx[1] = 3000;
		xx[2] = 1000;
		xx[3] = 3000;	//xx[2]=1000
		xx[8] = ta[t] - fx;
		xx[9] = tb[t] - fy;	//xx[15]=0;

		if (ta[t] - fx + xx[1] >= -10 - xx[3] && ta[t] - fx <= fxmax + 12000 + xx[3]) 
		{
			if (mtype != 200 && mtype != 1 && mtype != 2) 
			{
		    if (ttype[t] < 1000 && ttype[t] != 800 && ttype[t] != 140 && ttype[t] != 141) 
				{	// && ttype[t]!=5){

					//if (!(mztm>=1 && mztype==1 && actaon[3]==1)){
					if (!(mztype == 1)) 
					{
						xx[16] = 0;
						xx[17] = 0;

						//上
						if (ttype[t] != 7 && ttype[t] != 110 && !(ttype[t] == 114)) 
						{
							if (ma + mnobia > xx[8] + xx[0] * 2 + 100 && ma < xx[8] + xx[1] - xx[0] * 2 - 100 && mb + mnobib > xx[9] && mb + mnobib < xx[9] + xx[1] && md >= -100) 
							{
								if (ttype[t] != 115 && ttype[t] != 400
										&& ttype[t] != 117
										&& ttype[t] != 118
										&& ttype[t] != 120) 
								{
									mb = xx[9] - mnobib + 100;
									md = 0;
									mzimen = 1;
									xx[16] = 1;
								} else 
									if (ttype[t] == 115) 
									{
										ot(oto[3]);
										eyobi(ta[t] + 1200, tb[t] + 1200, 300, -1000, 0, 160, 1000, 1000, 1, 120);
										eyobi(ta[t] + 1200, tb[t] + 1200, -300, -1000, 0, 160, 1000, 1000, 1, 120); 
										eyobi(ta[t] + 1200, tb[t] + 1200, 240, -1400, 0, 160, 1000, 1000, 1, 120);
										eyobi(ta[t] + 1200, tb[t] + 1200, -240, -1400, 0, 160, 1000, 1000, 1, 120); 
										brockbreak(t);
									} //Pスイッチ
										else 
										if (ttype[t] == 400) 
										{
											md = 0;
											ta[t] = -8000000;
											ot(oto[13]);

											for (tt = 0; tt < tmax; tt++) 
											{
												if (ttype[tt] != 7) 
												{
													ttype[tt] = 800;
												}
											}
											Mix_HaltMusic();
										} //音符+
											else 
											if (ttype[t] == 117) 
											{
												ot(oto[14]);
												md = -1500;
												mtype = 2;
												mtm = 0;
												if (txtype[t] >= 2 && mtype == 2) 
												{
													mtype = 0;
													md = -1600;
													txtype[t] = 3;
												}
											if (txtype[t] == 0) txtype[t] = 1;
											} //ジャンプ台
												else 
												if (ttype[t] == 120) 
												{
													//txtype[t]=0;
													md = -2400;
													mtype = 3;
													mtm = 0;
												}

							}
						}
					}	//!

					//sstr=""+mjumptm;
					//ブロック判定の入れ替え
					if (!(mztm >= 1 && mztype == 1)) 
					{
						xx[21] = 0;
						xx[22] = 1;	//xx[12]=0;
						if (mzimen == 1 || mjumptm >= 10) 
						{
							xx[21] = 3;
							xx[22] = 0;
						}

						for (t3 = 0; t3 <= 1; t3++) 
						{
							//下
							if (t3 == xx[21] && mtype != 100 && ttype[t] != 117) 
							{	// && xx[12]==0){
								if (ma + mnobia > xx[8] + xx[0] * 2 + 800 && ma < xx[8] + xx[1] - xx[0] * 2 - 800 && mb > xx[9] - xx[0] * 2 && mb < xx[9] + xx[1] - xx[0] * 2 && md <= 0) 
								{
									xx[16] = 1;
									xx[17] = 1;
									mb = xx[9] + xx[1] + xx[0];
									if (md < 0) 
									{
										md = -md * 2 / 3;
									}	//}

									//壊れる
									if (ttype[t] == 1 && mzimen == 0) 
									{
										ot(oto[3]);
										eyobi(ta[t] + 1200, tb[t] + 1200, 300, -1000, 0, 160, 1000, 1000, 1, 120); 
										eyobi(ta[t] + 1200, tb[t] + 1200, -300, -1000, 0, 160, 1000, 1000, 1, 120);
										eyobi(ta[t] + 1200, tb[t] + 1200, 240, -1400, 0, 160, 1000, 1000, 1, 120);
										eyobi(ta[t] + 1200, tb[t] + 1200, -240, -1400, 0, 160, 1000, 1000, 1, 120);
										brockbreak(t);
									}

									//コイン
									if (ttype[t] == 2 && mzimen == 0) 
									{
										ot(oto[4]);
										eyobi(ta[t] + 10, tb [t], 0, -800, 0, 40, 3000, 3000, 0, 16);
										ttype[t] = 3;
									}

									//隠し
									if (ttype[t] == 7) 
									{
										ot(oto[4]);
										eyobi(ta[t] + 10, tb [t], 0, -800, 0, 40, 3000, 3000, 0, 16);
										mb = xx[9] + xx[1] + xx[0];
										ttype[t] = 3;

										if (md < 0) 
										{
											md = -md * 2 / 3;
										}
									}

									// トゲ
									if (ttype[t] == 10) 
									{
										mmsgtm = 30;
										mmsgtype = 3;
										mhp--;
									}
								}
							}

							//左右
							if (t3 == xx[22] && xx[15] == 0) 
							{
								if (ttype[t] != 7 && ttype[t] != 110 && ttype[t] != 117) 
								{
									if (!(ttype[t] == 114)) 
									{	// && txtype[t]==1)){
										if (ta[t] >= -20000) 
										{
											//if (ma+mnobia>xx[8] && ma<xx[8]+xx[2] && mb+mnobib>xx[9]+xx[1]/2-xx[0] &&){
											if (ma + mnobia > xx[8] && ma < xx[8] + xx[2] && mb + mnobib > xx[9] + xx[1] / 2 - xx[0] && mb < xx[9] + xx[2] && mc >= 0) 
											{
												ma = xx[8] - mnobia;
												mc = 0;
												xx[16] = 1;
												//if (ttype[t]!=4){ma=xx[8]-mnobia;mc=0;xx[16]=1;}
												//if (ttype[t]==4){ma=xx[8]-mnobia;mc=-mc*4/4;}
											}

											if (ma + mnobia > xx[8] + xx[2] && ma < xx[8] + xx[1] && mb + mnobib > xx[9] + xx[1] / 2 - xx[0] && mb < xx[9] + xx[2] && mc <= 0) 
											{
												ma = xx[8] + xx[1];
												mc = 0;
												xx[16] = 1;	//end();
												//if (ttype[t]!=4){ma=xx[8]+xx[1];mc=0;xx[16]=1;}
												//if (ttype[t]==4){ma=xx[8]+xx[1];mc=-mc*4/4;}
											}
										}
									}
								}
							}
						}	//t3
					}	//!
		    }	// && ttype[t]<50

		    if (ttype[t] == 800) 
				{
					//if (xx[0]+xx[2]>=-xx[14] && xx[0]<=fxmax+xx[14] && xx[1]+xx[3]>=-10-9000 && xx[1]<=fymax+10000){
					if (mb > xx[9] - xx[0] * 2 - 2000 && mb < xx[9] + xx[1] - xx[0] * 2 + 2000 && ma + mnobia > xx[8] - 400 && ma < xx[8] + xx[1]) 
					{
			    ta[t] = -800000;
			    ot(oto[4]);
					}
		    }

				//剣とってクリア
		    if (ttype[t] == 140) 
				{
					if (mb > xx[9] - xx[0] * 2 - 2000 && mb < xx[9] + xx[1] - xx[0] * 2 + 2000 && ma + mnobia > xx[8] - 400 && ma < xx[8] + xx[1]) 
					{
						ta[t] = -800000;	//ot(oto[4]);
						sracttype[20] = 1;
						sron[20] = 1;
						Mix_HaltMusic();
						mtype = 301;
						mtm = 0;
						ot(oto[16]);
					}
		    }

				//特殊的
		    if (ttype[t] == 100) 
				{	//xx[9]+xx[1]+3000<mb && // && mb>xx[9]-xx[0]*2
					if (mb > xx[9] - xx[0] * 2 - 2000 && mb < xx[9] + xx[1] - xx[0] * 2 + 2000 && ma + mnobia > xx[8] - 400 && ma < xx[8] + xx[1] && md <= 0) 
					{
						if (txtype[t] == 0) 
							tb[t] = mb + fy - 1200 - xx[1];
					}

					if (txtype[t] == 1) 
					{
						if (xx[17] == 1) 
						{
							if (ma + mnobia > xx[8] - 400 && ma < xx[8] + xx[1] / 2 - 1500) 
							{
								ta[t] += 3000;
							} else 
								if (ma + mnobia >= xx[8] + xx[1] / 2 - 1500 && ma < xx[8] + xx[1]) 
								{
									ta[t] -= 3000;
								}
						}
					}

					if (xx[17] == 1 && txtype[t] == 0) 
					{
						ot(oto[4]);
						eyobi(ta[t] + 10, tb[t],
						0, -800, 0, 40, 3000, 3000, 0, 16);
						ttype[t] = 3;
					}
				}		//100

				//敵出現
		    if (ttype[t] == 101) 
				{	
					//xx[9]+xx[1]+3000<mb && // && mb>xx[9]-xx[0]*2
					if (xx[17] == 1) 
					{
						ot(oto[8]);
						ttype[t] = 3;
						abrocktm[aco] = 16;
						if (txtype[t] == 0)
							ayobi(ta[t], tb[t], 0, 0, 0, 0, 0);

						if (txtype[t] == 1)
							ayobi(ta[t], tb[t], 0, 0, 0, 4, 0);

						if (txtype[t] == 3)
							ayobi(ta[t], tb[t], 0, 0, 0, 101, 0);
							
						if (txtype[t] == 4) 
						{
							abrocktm[aco] = 20;
							ayobi(ta[t] - 400, tb[t] - 1600, 0, 0, 0, 6, 0);
						}

			    	if (txtype[t] == 10)
						ayobi(ta[t], tb[t], 0, 0, 0, 101, 0);
					}
		    }	// 101

				//おいしいきのこ出現
		    if (ttype[t] == 102) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[8]);
						ttype[t] = 3;
						abrocktm[aco] = 16;

						if (txtype[t] == 0)
							ayobi(ta[t], tb[t], 0, 0, 0, 100, 0);

						if (txtype[t] == 2)
							ayobi(ta[t], tb[t], 0, 0, 0, 100, 2);

						if (txtype[t] == 3)
							ayobi(ta[t], tb[t], 0, 0, 0, 102, 1);
					}
		    }	// 102

				//まずいきのこ出現
		    if (ttype[t] == 103) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[8]);
						ttype[t] = 3;
						abrocktm[aco] = 16;
						ayobi(ta[t], tb[t], 0, 0, 0, 100, 1);
					}
		    }	// 103

				//悪スター出し
		    if (ttype[t] == 104) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[8]);
						ttype[t] = 3;
						abrocktm[aco] = 16;
						ayobi(ta[t], tb[t], 0, 0, 0, 110, 0);
					}
		    }	// 104

				//毒きのこ量産
		    if (ttype[t] == 110) 
				{
					if (xx[17] == 1) 
					{
						ttype[t] = 111;
						thp[t] = 999;
					}
		    }	// 110

		    if (ttype[t] == 111 && ta[t] - fx >= 0) 
				{
					thp[t]++;
					if (thp[t] >= 16) 
					{
						thp[t] = 0;
						ot(oto[8]);
						abrocktm[aco] = 16;
						ayobi(ta[t], tb[t], 0, 0, 0, 102, 1);
					}
		    }

				//コイン量産
		    if (ttype[t] == 112) 
				{
					if (xx[17] == 1) 
					{
						ttype[t] = 113;
						thp[t] = 999;
						titem[t] = 0;
					}
		    }	// 110

		    if (ttype[t] == 113 && ta[t] - fx >= 0) 
				{
					if (titem[t] <= 19)
			    	thp[t]++;

					if (thp[t] >= 3) 
					{
						thp[t] = 0;
						titem[t]++;
						ot(oto[4]);
						eyobi(ta[t] + 10, tb[t], 0, -800, 0, 40, 3000, 3000, 0, 16);
						//ttype[t]=3;
					}
		    }

				//隠し毒きのこ
		    if (ttype[t] == 114) 
				{
					if (xx[17] == 1) 
					{
			    	if (txtype[t] == 0) 
						{
							ot(oto[8]);
							ttype[t] = 3;
							abrocktm[aco] = 16;
							ayobi(ta[t], tb[t], 0, 0, 0, 102, 1);
						}

						if (txtype[t] == 2) 
						{
							ot(oto[4]);
							eyobi(ta[t] + 10, tb[t], 0, -800, 0, 40, 3000, 3000, 0, 16);
							ttype[t] = 115;
							txtype[t] = 0;
						}

						if (txtype[t] == 10) 
						{
							if (stageonoff == 1) 
							{
								ttype[t] = 130;
								stageonoff = 0;
								ot(oto[13]);
								txtype[t] = 2;

								for (t = 0; t < amax; t++) 
								{
									if (atype[t] == 87 || atype[t] == 88) 
									{
										if (axtype[t] == 105) 
										{
											axtype[t] = 110;
										}
									}
								}
							} else {
								ot(oto[4]);
								eyobi(ta[t] + 10, tb [t], 0, -800, 0, 40, 3000, 3000, 0, 16);
								ttype[t] = 3;
							}
						}
					}
		    }	// 114

				//もろいブロック
		    if (ttype[t] == 115) 
				{

		    }	//115

				//Pスイッチ
		    if (ttype[t] == 116) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[8]);
						//ot(oto[13]);
						ttype[t] = 3;	//abrocktm[aco]=18;ayobi(ta[t],tb[t],0,0,0,104,1);
						tyobi(ta[t] / 100, (tb[t] / 100) - 29, 400);
					}
		    }	// 116

				//ファイアバー強化
		    if (ttype[t] == 124) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[13]);
						for (t = 0; t < amax; t++) 
						{
							if (atype[t] == 87 || atype[t] == 88) 
							{
								if (axtype[t] == 101) 
								{
									axtype[t] = 120;
								}
							}
						}
						ttype[t] = 3;
					}
		    }

				//ONスイッチ
		    if (ttype[t] == 130) 
				{
					if (xx[17] == 1) 
					{
						if (txtype[t] != 1) 
						{
							stageonoff = 0;
							ot(oto[13]);
						}
					}
		    } else 
					if (ttype[t] == 131) 
					{
						if (xx[17] == 1 && txtype[t] != 2) 
						{
							stageonoff = 1;
							ot(oto[13]);
							if (txtype[t] == 1) 
							{
								for (t = 0; t < amax; t++) 
								{
									if (atype[t] == 87 || atype[t] == 88) 
									{
										if (axtype[t] == 105) 
										{
											axtype[t] = 110;
										}
									}
								}
								bxtype[3] = 105;
							}
						}
					}

				//ヒント
		    if (ttype[t] == 300) 
				{
					if (xx[17] == 1) 
					{
						ot(oto[15]);
						if (txtype[t] <= 100) 
						{
							tmsgtype = 1;
							tmsgtm = 15;
							tmsgy = 300 + (txtype[t] - 1);
							tmsg = (txtype[t]);
						}

						if (txtype[t] == 540) 
						{
							tmsgtype = 1;
							tmsgtm = 15;
							tmsgy = 400;
							tmsg = 100;
							txtype[t] = 541;
						}
					}
		    }	// 300

		    if (ttype[t] == 301) 
				{
					if (xx[17] == 1) 
					{ 
						ot(oto[3]);
						eyobi(ta[t] + 1200, tb[t] + 1200, 300, -1000, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, -300, -1000, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, 240, -1400, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, -240, -1400, 0, 160, 1000, 1000, 1, 120);
						brockbreak(t);
					}
		    }	// 300

			} else 
				if (mtype == 1) 
				{
					if (ma + mnobia > xx[8] && ma < xx[8] + xx[1] && mb + mnobib > xx[9] && mb < xx[9] + xx[1]) 
					{
						ot(oto[3]);
						eyobi(ta[t] + 1200, tb[t] + 1200, 300, -1000, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, -300, -1000, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, 240, -1400, 0, 160, 1000, 1000, 1, 120);
						eyobi(ta[t] + 1200, tb[t] + 1200, -240, -1400, 0, 160, 1000, 1000, 1, 120);
						brockbreak(t);
					}
				}

			//ONOFF
			if (ttype[t] == 130 && stageonoff == 0) 
			{
		    ttype[t] = 131;
			}

			if (ttype[t] == 131 && stageonoff == 1) 
			{
		    ttype[t] = 130;
			}

			//ヒント
			if (ttype[t] == 300) 
			{
		    if (txtype[t] >= 500 && ta[t] >= -6000) 
				{	// && ta[t]>=-6000){
					if (txtype[t] <= 539)
						txtype[t]++;
					if (txtype[t] >= 540) 
					{
						ta[t] -= 500;
					}
		    }
			}	// 300

		}
	}	//ブロック

	//壁
	for (t = 0; t < smax; t++) 
	{
	  if (sa[t] - fx + sc[t] >= -12000 && sa[t] - fx <= fxmax) 
		{
			xx[0] = 200;
			xx[1] = 2400;
			xx[2] = 1000;
			xx[7] = 0;

			xx[8] = sa[t] - fx;
			xx[9] = sb[t] - fy;
			if ((stype[t] <= 99 || stype[t] == 200) && mtype < 10) 
			{

				//おちるブロック
		    if (stype[t] == 51) 
				{
					if (ma + mnobia > xx[8] + xx[0] + 3000 && ma < xx[8] + sc[t] - xx[0] && mb + mnobib > xx[9] + 3000 && sgtype[t] == 0) 
					{
						if (sxtype[t] == 0) 
						{
							sgtype[t] = 1;
							sr[t] = 0;
						}
					}

					if (ma + mnobia > xx[8] + xx[0] + 1000 && ma < xx[8] + sc[t] - xx[0] && mb + mnobib > xx[9] + 3000 && sgtype[t] == 0) 
					{
						if ((sxtype[t] == 10) && sgtype[t] == 0) 
						{
							sgtype[t] = 1; sr[t] = 0;
						}
					}

					if ((sxtype[t] == 1) && sb[27] >= 25000 && sa[27] > ma + mnobia && t != 27 && sgtype[t] == 0) 
					{
						sgtype[t] = 1;
						sr[t] = 0;
					}

					if (sxtype[t] == 2 && sb[28] >= 48000 && t != 28 && sgtype[t] == 0 && mhp >= 1) 
					{
						sgtype[t] = 1;
						sr[t] = 0;
					}

					if ((sxtype[t] == 3
							&& mb >= 30000
							|| sxtype[t] == 4 && mb >= 25000)
							&& sgtype[t] == 0
							&& mhp >= 1
							&& ma + mnobia > xx[8] + xx[0] + 3000 - 300
							&& ma < xx[8] + sc[t] - xx[0]) 
					{
						sgtype[t] = 1;
						sr[t] = 0;
						if (sxtype[t] == 4)
						sr[t] = 100;
					}

					if (sgtype[t] == 1 && sb[t] <= fymax + 18000) 
					{
						sr[t] += 120;
						if (sr[t] >= 1600) 
						{
							sr[t] = 1600;
						}

						sb[t] += sr[t];
						if (ma + mnobia > xx[8] + xx[0]
								&& ma < xx[8] + sc[t] - xx[0]
								&& mb + mnobib > xx[9]
								&& mb < xx[9] + sd[t] + xx[0]) 
						{
							mhp--;
							xx[7] = 1;
						}
					}
		    }

				//おちるブロック2
		    if (stype[t] == 52) 
				{
					if (sgtype[t] == 0
							&& ma + mnobia > xx[8] + xx[0] + 2000
							&& ma < xx[8] + sc[t] - xx[0] - 2500
							&& mb + mnobib > xx[9] - 3000) 
					{
						sgtype[t] = 1;
						sr[t] = 0;
					}

					if (sgtype[t] == 1) 
					{
						sr[t] += 120;
						if (sr[t] >= 1600) 
						{
							sr[t] = 1600;
			    	}

						sb[t] += sr[t];
					}
		    }

				//通常地面
		    if (xx[7] == 0) 
				{
					if (ma + mnobia > xx[8] + xx[0]
							&& ma < xx[8] + sc[t] - xx[0]
							&& mb + mnobib > xx[9]
							&& mb + mnobib < xx[9] + xx[1]
							&& md >= -100) 
					{
						mb = sb[t] - fy - mnobib + 100;
						md = 0;
						mzimen = 1;
					}
					
					if (ma + mnobia > xx[8] - xx[0]
							&& ma < xx[8] + xx[2]
							&& mb + mnobib >
							xx[9] + xx[1] * 3 / 4
							&& mb < xx[9] + sd[t] - xx[2]) 
					{
						ma = xx[8] - xx[0] - mnobia;
						mc = 0;
					}

					if (ma + mnobia > xx[8] + sc[t] - xx[0]
							&& ma < xx[8] + sc[t] + xx[0]
							&& mb + mnobib >
							xx[9] + xx[1] * 3 / 4
							&& mb < xx[9] + sd[t] - xx[2]) 
					{
						ma = xx[8] + sc[t] + xx[0];
						mc = 0;
					}

					if (ma + mnobia > xx[8] + xx[0] * 2
							&& ma < xx[8] + sc[t] - xx[0] * 2
							&& mb > xx[9] + sd[t] - xx[1]
							&& mb < xx[9] + sd[t] + xx[0]) 
					{
			    	mb = xx[9] + sd[t] + xx[0];
			    	if (md < 0) 
						{
							md = -md * 2 / 3;
			  	  }
					}
		    }	// xx[7]

				//入る土管
		    if (stype[t] == 50) 
				{
					if (ma + mnobia > xx[8] + 2800
							&& ma < xx[8] + sc[t] - 3000
							&& mb + mnobib > xx[9] - 1000
							&& mb + mnobib < xx[9] + xx[1] + 3000
							&& mzimen == 1
							&& actaon[3] == 1 && mtype == 0) 
					{
						//飛び出し
						if (sxtype[t] == 0) 
						{
							mtype = 100;
							mtm = 0;
							ot(oto[7]);
							mxtype = 0;
						}

						//普通
						if (sxtype[t] == 1) 
						{
							mtype = 100;
							mtm = 0;
							ot(oto[7]);
							mxtype = 1;
						}

						//普通
						if (sxtype[t] == 2) 
						{
							mtype = 100;
							mtm = 0;
							ot(oto[7]);
							mxtype = 2;
						}

						if (sxtype[t] == 5) 
						{
							mtype = 100;
							mtm = 0;
							ot(oto[7]);
							mxtype = 5;
						}

						// ループ
						if (sxtype[t] == 6) 
						{
							mtype = 100;
							mtm = 0;
							ot(oto[7]);
							mxtype = 6;
						}
					}
				}	// 50

				// 入る土管(左から)
				if (stype[t] == 40) 
				{
					if (ma + mnobia > xx[8] - 300 && ma < xx[8] + sc[t] - 1000 
							&& mb > xx[9] + 1000 && mb + mnobib < xx[9] + xx[1] + 4000 
							&& mzimen == 1 && actaon[4] == 1 && mtype == 0) 
					{	//end();

						//飛び出し
						if (sxtype[t] == 0) 
						{
							mtype = 500;
							mtm = 0;
							ot(oto[7]);	//mxtype=1;
							mtype = 100;
							mxtype = 10;
						}

						if (sxtype[t] == 2) 
						{
							mxtype = 3;
							mtm = 0;
							ot(oto[7]);	//mxtype=1;
							mtype = 100;
						}

						// ループ
						if (sxtype[t] == 6) 
						{
							mtype = 3;
							mtm = 0;
							ot(oto[7]);
							mxtype = 6;
						}
					}
				}	// 40
			}	//stype
				else {

		  	if (ma + mnobia > xx[8] + xx[0]
						&& ma < xx[8] + sc[t] - xx[0]
						&& mb + mnobib > xx[9]
						&& mb < xx[9] + sd[t] + xx[0]) 
				{
					if (stype[t] == 100) 
					{
						if (sxtype[t] == 0 || sxtype[t] == 1 && ttype[1] != 3) 
						{
							ayobi(sa[t] + 1000, 32000, 0, 0, 0, 3, 0);
							sa[t] = -800000000;
							ot(oto[10]);
						}
					}

					if (stype[t] == 101) 
					{
							ayobi(sa[t] + 6000, -4000, 0, 0, 0, 3, 1);
							sa[t] = -800000000;
							ot(oto[10]);
					}

					if (stype[t] == 102) 
					{
						if (sxtype[t] == 0) 
						{
							for (t3 = 0; t3 <= 3; t3++) 
							{
									ayobi(sa[t] + t3 * 3000, -3000, 0, 0, 0, 0, 0);
							}
						}

						if (sxtype[t] == 1 && mb >= 16000) 
						{
							ayobi(sa[t] + 1500, 44000, 0, -2000, 0, 4, 0);
						} else 
							if (sxtype[t] == 2) 
							{
								ayobi(sa[t] + 4500, 30000, 0, -1600, 0, 5, 0); ot(oto[10]);
								sxtype[t] = 3;
								sa[t] -= 12000;
							} else 
								if (sxtype[t] == 3) 
								{
									sa[t] += 12000;
									sxtype[t] = 4;
								} else 
									if (sxtype[t] == 4) 
									{
										ayobi(sa[t] + 4500, 30000, 0, -1600, 0, 5, 0);
										ot(oto[10]);
										sxtype[t] = 5;
										sxtype[t] = 0;
									} else 
										if (sxtype[t] == 7) 
										{
											mainmsgtype = 1;
										} else 
											if (sxtype[t] == 8) 
											{ 
												ayobi(sa[t] - 5000 - 3000 * 1, 26000, 0, -1600, 0, 5, 0);
												ot(oto[10]);
											} else 
												if (sxtype[t] == 9) 
												{
													for (t3 = 0; t3 <= 2; t3++) 
													{
														ayobi(sa[t] + t3 * 3000 + 3000, 48000, 0, -6000, 0, 3, 0);
													}
												}

						if (sxtype[t] == 10) 
						{
							sa[t] -= 5 * 30 * 100;
							stype[t] = 101;
						}

						if (sxtype[t] == 12) 
						{
							for (t3 = 1; t3 <= 3; t3++) 
							{
								ayobi(sa[t] + t3 * 3000 - 1000, 40000, 0, -2600, 0, 9, 0);
							}
						}

						//スクロール消し
						if (sxtype[t] == 20) 
						{
							scrollx = 0;
						}

						//クリア
						if (sxtype[t] == 30) 
						{
							sa[t] = -80000000;
							md = 0;
							Mix_HaltMusic();
							mtype = 302;
							mtm = 0;
							ot(oto[16]);
						}

						if (sxtype[t] != 3
								&& sxtype[t] != 4 && sxtype[t] != 10) 
						{
							sa[t] = -800000000;
						}
					}

					if (stype[t] == 103) 
					{
						if (sxtype[t] == 0) 
						{
							amsgtm[aco] = 10;
							amsgtype[aco] = 50;
							ayobi(sa[t] + 9000, sb[t] + 2000, 0, 0, 0, 79, 0);
							sa[t] = -800000000;
						}

						if (sxtype[t] == 1 && ttype[6] <= 6) 
						{
							amsgtm[aco] = 10;
							amsgtype[aco] = 50;
							ayobi(sa[t] - 12000, sb[t] + 2000, 0, 0, 0, 79, 0);
							sa[t] = -800000000;
							txtype[9] = 500;	//ttype[9]=1;
						}
					}	//103

					if (stype[t] == 104) 
					{
						if (sxtype[t] == 0) 
						{
							ayobi(sa[t] + 12000, sb[t] + 2000 + 3000, 0, 0, 0, 79, 0);
							ayobi(sa[t] + 12000, sb[t] + 2000 + 3000, 0, 0, 0, 79, 1);
							ayobi(sa[t] + 12000, sb[t] + 2000 + 3000, 0, 0, 0, 79, 2);
							ayobi(sa[t] + 12000, sb[t] + 2000 + 3000, 0, 0, 0, 79, 3);
							ayobi(sa[t] + 12000, sb[t] + 2000 + 3000, 0, 0, 0, 79, 4);
							sa[t] = -800000000;
						}
					}

					if (stype[t] == 105 && mzimen == 0 && md >= 0) 
					{
						ta[1] -= 1000;
						ta[2] += 1000;
						sxtype[t]++;
						if (sxtype[t] >= 3)
						sa[t] = -8000000;
					}

					if (stype[t] == 300
							&& mtype == 0
							&& mb < xx[9] + sd[t] + xx[0] - 3000 && mhp >= 1) 
					{
						Mix_HaltMusic();
						mtype = 300;
						mtm = 0;
						ma = sa[t] - fx - 2000;
						ot(oto[11]);
					}
				
					//中間ゲート
					if (stype[t] == 500 && mtype == 0 && mhp >= 1) 
					{
						tyuukan += 1;
						sa[t] = -80000000;
					}
		    }

		    if (stype[t] == 180) 
				{
					sr[t]++;
					if (sr[t] >= sgtype[t]) 
					{
						sr[t] = 0;
						ayobi(sa[t], 30000,
						rand(600) - 300,
						-1600 - rand(900), 0, 84, 0);
					}
		    }
			}
		}
	}	// 壁

	//キー入力初期化
	//for (t=0;t<=6;t++)
	actaon[0] = 0;
	actaon[4] = 0;

	//リフト
	for (t = 0; t < srmax; t++) 
	{
		xx[10] = sra[t];
		xx[11] = srb[t];
		xx[12] = src[t];
		xx[13] = srd[t];
		xx[8] = xx[10] - fx;
		xx[9] = xx[11] - fy;
		if (xx[8] + xx[12] >= -10 - 12000 && xx[8] <= fxmax + 12100) 
		{
			xx[0] = 500;
			xx[1] = 1200;
			xx[2] = 1000;
			xx[7] = 2000;
			if (md >= 100) 
			{
		    xx[1] = 900 + md;
			}

			//if (srtype[t]==1){xx[0]=600;}
			if (md > xx[1])
		    xx[1] = md + 100;
				
			//xx[18]=0;

			srb[t] += sre[t];
			sre[t] += srf[t];
			//if (srf[t]>=500)srf[t]=0;

			//動き
			switch (sracttype[t]) 
			{
				case 1:
					if (sron[t] == 1)
					srf[t] = 60;
					break;

				case 2:
					/*
					if (sra[t]<=srmovep[t]-srmove[t])srmuki[t]=1;
					if (sra[t]>=srmovep[t]+srmove[t])srmuki[t]=0;
					*/
					break;

				case 3:
					/*
					if (srb[t]<=srmovep[t]-srmove[t])srmuki[t]=1;
					if (srb[t]>=srmovep[t]+srmove[t])srmuki[t]=0;
					*/
					break;

					/*
					case 4:
					if (srmove[t]==0){srmuki[t]=0;}else{srmuki[t]=1;}
					if (sra[t]-fx<-1100-src[t]){sra[t]=fymax+fx+scrollx;}
					if (sra[t]-fx>24000+scrollx){sra[t]=-1100-src[t]+fx;}
					break;
					*/

				case 5:
					if (srmove[t] == 0) 
					{
						srmuki[t] = 0;
					} else {
						srmuki[t] = 1;
					}

					if (srb[t] - fy < -2100) 
					{
						srb[t] = fymax + fy + scrolly + 2000;
					}

					if (srb[t] - fy > fymax + scrolly + 2000) 
					{
						srb[t] = -2100 + fy;
					}
					break;

				case 6:
						if (sron[t] == 1)
					srf[t] = 40;
						break;

				case 7:
						break;
		}	// sw

		//if (srtype[t]==1){sre[10]=300;sre[11]=300;}

		//乗ったとき
		if (!(mztm >= 1 && mztype == 1 && actaon[3] == 1) && mhp >= 1) 
		{
			if (ma + mnobia > xx[8] + xx[0]
					&& ma < xx[8] + xx[12] - xx[0]
					&& mb + mnobib > xx[9]
					&& mb + mnobib < xx[9] + xx[1]
					&& md >= -100) 
			{
				mb = xx[9] - mnobib + 100;
				//if (sracttype[t]!=7)mzimen=1;

				if (srtype[t] == 1) 
				{
					sre[10] = 900;
					sre[11] = 900;
				}

				if (srsp[t] != 12) 
				{
					mzimen = 1;
					md = 0;
				} else {
					//すべり
					//md=0;mrzimen=1;mzimen=1;
					md = -800;
				}

				/*
				md=0;
				if ((sracttype[t]==1 || sracttype[t]==6) && sron[t]==1)mb+=sre[t];

				if (sracttype[t]==2 || sracttype[t]==4){
				if (srmuki[t]==0)ma-=srsok[t];
				if (srmuki[t]==1)ma+=srsok[t];
				}
				*/

				//落下
				if ((sracttype[t] == 1)
					&& sron[t] == 0)
					sron[t] = 1;

				if (sracttype[t] == 1
						&& sron[t] == 1
						|| sracttype[t] == 3 || sracttype[t] == 5) 
				{
					mb += sre[t];
					//if (srmuki[t]==0)
					//if (srf[t]<0)
					//if (srmuki[t]==1)
					//if (srf[t]>0)
					//mb+=srsok[t];
				}

				if (sracttype[t] == 7) 
				{
					if (actaon[2] != 1) 
					{
						md = -600;
						mb -= 810;
					}

					if (actaon[2] == 1) 
					{
						mb -= 400;
						md = -1400;
						mjumptm = 10;
					}
				}

				//特殊
				if (srsp[t] == 1) 
				{
					ot(oto[3]);
					eyobi(sra[t] + 200,
					srb[t] - 1000, -240, -1400, 0, 160, 4500, 4500, 2, 120);
					eyobi(sra[t] + 4500 - 200, srb[t] - 1000, 240, -1400, 0, 160, 4500, 4500, 3, 120);
					sra[t] = -70000000;
				}

				if (srsp[t] == 2) 
				{
					mc = -2400;
					srmove[t] += 1;
					if (srmove[t] >= 100) 
					{
						mhp = 0;
						mmsgtype = 53;
						mmsgtm = 30;
						srmove[t] = -5000;
					}
				}

				if (srsp[t] == 3) 
				{
					mc = 2400;
					srmove[t] += 1;
					if (srmove[t] >= 100) 
					{
						mhp = 0;
						mmsgtype = 53;
						mmsgtm = 30;
						srmove[t] = -5000;
					}
				}
				//if (srtype[t]==1){md=-600;mb-=610;mhp-=1;if (mmutekion!=1)mmutekitm=40;}
			}	//判定内

			//疲れ初期化
			if ((srsp[t] == 2 || srsp[t] == 3) && mc != -2400 && srmove[t] > 0) 
			{
				srmove[t]--;
			}

			if (srsp[t] == 11) 
			{
				if (ma + mnobia >
					xx[8] + xx[0] - 2000
					&& ma < xx[8] + xx[12] - xx[0]) 
				{
					sron[t] = 1;
				}	// && mb+mnobib>xx[9]-1000 && mb+mnobib<xx[9]+xx[1]+2000)

				if (sron[t] == 1) 
				{
					srf[t] = 60;
					srb[t] += sre[t];
				}
			}
		
				//トゲ(下)
				if (ma + mnobia > xx[8] + xx[0]
						&& ma < xx[8] + xx[12] - xx[0]
						&& mb > xx[9] - xx[1] / 2
						&& mb < xx[9] + xx[1] / 2) 
				{
					if (srtype[t] == 2) 
					{
						if (md < 0) 
						{
							md = -md;
						}
						mb += 110;
						if (mmutekitm <= 0)
							mhp -= 1;
						if (mmutekion != 1)
							mmutekitm = 40;
					}
				}

				//落下
				if (sracttype[t] == 6) 
				{
					if (ma + mnobia > xx[8] + xx[0] && ma < xx[8] + xx[12] - xx[0]) 
					{
						sron[t] = 1;
					}
				}
			}	// !

			/*
			//ジャンプ台
			if (sracttype[t]==7){
			if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+xx[12]-xx[0] && mb+mnobib>xx[9]+xx[1]/2 && mb+mnobib<xx[9]+xx[1]*3/2 && md>=-100){
			if (actaon[2]!=1){md=-600;mb-=810;}
			if (actaon[2]==1){mb-=400;md=-1400;mjumptm=10;}
			}}
			*/

			if (sracttype[t] == 2 || sracttype[t] == 4) 
			{
				if (srmuki[t] == 0)
					sra[t] -= srsok[t];
				if (srmuki[t] == 1)
					sra[t] += srsok[t];
			}

			if (sracttype[t] == 3 || sracttype[t] == 5) 
			{
				if (srmuki[t] == 0)
					srb[t] -= srsok[t];
				if (srmuki[t] == 1)
					srb[t] += srsok[t];
			}
	
			//敵キャラ適用
			for (tt = 0; tt < amax; tt++) 
			{
				if (azimentype[tt] == 1) 
				{
					if (aa[tt] + anobia[tt] - fx > xx[8] + xx[0]
							&& aa[tt] - fx < xx[8] + xx[12] - xx[0]
							&& ab[tt] + anobib[tt] >
							xx[11] - 100 && ab[tt] + anobib[tt] < xx[11] + xx[1] + 500 && ad[tt] >= -100) 
					{
						ab[tt] = xx[9] - anobib[tt] + 100;
						ad[tt] = 0;
						axzimen[tt] = 1;
					}
				}
			}
	  }
	}	//リフト

	//グラ
	for (t = 0; t < emax; t++) 
	{
		xx[0] = ea[t] - fx;
		xx[1] = eb[t] - fy;
		xx[2] = enobia[t] / 100;
		xx[3] = enobib[t] / 100;
		if (etm[t] >= 0)
			etm[t]--;

		if (xx[0] + xx[2] * 100 >= -10 && xx[1] <= fxmax
				&& xx[1] + xx[3] * 100 >= -10 - 8000
				&& xx[3] <= fymax && etm[t] >= 0) 
		{
			ea[t] += ec[t];
			eb[t] += ed[t];
			ec[t] += ee[t];
			ed[t] += ef[t];
		} else {
			ea[t] = -9000000;
		}

	}			//emax

	//敵キャラの配置
	for (t = 0; t < bmax; t++) 
	{
		if (ba[t] >= -80000) 
		{

			if (btm[t] >= 0) 
			{
		    btm[t] = btm[t] - 1;
			}

			for (tt = 0; tt <= 1; tt++) 
			{
		    xx[0] = 0;
		    xx[1] = 0;

		    if (bz[t] == 0 && btm[t] < 0
						&& ba[t] - fx >= fxmax + 2000
						&& ba[t] - fx < fxmax + 2000 + mc && tt == 0) 
				{
					xx[0] = 1;
					amuki[aco] = 0;
		    }	// && mmuki==1

		    if (bz[t] == 0 && btm[t] < 0
						&& ba[t] - fx >= -400 - anx[btype[t]] + mc
						&& ba[t] - fx < -400 - anx[btype[t]]
						&& tt == 1) 
				{
					xx[0] = 1;
					xx[1] = 1;
					amuki[aco] = 1;
		    }	// && mmuki==0

		    if (bz[t] == 1 && ba[t] - fx >= 0 - anx[btype[t]]
						&& ba[t] - fx <= fxmax + 4000
						&& bb[t] - fy >= -9000
						&& bb[t] - fy <= fymax + 4000 && btm[t] < 0) 
				{
					xx[0] = 1;
					bz[t] = 0;
		    }	// && xza<=5000// && tyuukan!=1
					//if (bz[t]==2){xx[0]=0;xx[1]=0;}
					//if (btype[t]>=100){bz[t]=2;}

		    if (xx[0] == 1) 
				{	//400
					btm[t] = 401;
					xx[0] = 0;	//if (btype[t]>=20 && btype[t]<=23){btm[t]=90000;}

					if (btype[t] >= 10) 
					{
						btm[t] = 9999999;
					}
					//10
					ayobi(ba[t], bb[t], 0, 0, 0, btype[t], bxtype[t]);
		    }
			}	// tt
		}
	}	// t

	//敵キャラ
	for (t = 0; t < amax; t++) 
	{
		xx[0] = aa[t] - fx;
		xx[1] = ab[t] - fy;
		xx[2] = anobia[t];
		xx[3] = anobib[t];
		xx[14] = 12000 * 1;

		if (anotm[t] >= 0)
			anotm[t]--;

		if (xx[0] + xx[2] >= -xx[14] && xx[0] <= fxmax + xx[14] && xx[1] + xx[3] >= -10 - 9000 && xx[1] <= fymax + 20000) 
		{
			aacta[t] = 0;
			aactb[t] = 0;

			xx[10] = 0;

			switch (atype[t]) 
			{
				case 0:
					xx[10] = 100;
					break;

				//こうらの敵

				case 1:
					xx[10] = 100;
					break;

				//こうら
				case 2:
					xx[10] = 0;
					xx[17] = 800;
					if (axtype[t] >= 1)
						xx[10] = xx[17];

					//if (axtype[t]==1)xx[10]=xx[17];
					//if (axtype[t]==2)xx[10]=-xx[17];
					//他の敵を倒す
					if (axtype[t] >= 1) 
					{
						for (tt = 0; tt < amax; tt++) 
						{
							xx[0] = 250;
							xx[5] = -800;
							xx[12] = 0;
							xx[1] = 1600;
							xx[8] = aa[tt] - fx;
							xx[9] = ab[tt] - fy;
							if (t != tt) 
							{
								if (aa[t] + anobia[t] - fx > xx[8] + xx[0] * 2 && aa[t] - fx < xx[8] + anobia[tt] - xx[0] * 2 
										&& ab[t] + anobib[t] - fy > xx[9] + xx[5] && ab[t] + anobib[t] - fy < xx[9] + xx[1] * 3 + xx[12] + 1500) 
								{
									aa[tt] = -800000;
									ot(oto[6]);
								}
							}
						}
					}

					break;

				//あらまき
				case 3:
					azimentype[t] = 0;	//end();
					if (axtype[t] == 0) 
					{
						ab[t] -= 800;
					}

					if (axtype[t] == 1)
						ab[t] += 1200;

					//xx[10]=100;
					break;

				//スーパージエン
				case 4:
					xx[10] = 120;
					xx[0] = 250;
					xx[8] = aa[t] - fx;
					xx[9] = ab[t] - fy;
					if (atm[t] >= 0)
						atm[t]--;
					if (abs(ma + mnobia - xx[8] - xx[0] * 2) < 9000 
							&& abs(ma < xx[8] - anobia[t] + xx[0] * 2) < 3000
							&& md <= -600 && atm[t] <= 0) 
					{
						if (axtype[t] == 1
								&& mzimen == 0 && axzimen[t] == 1) 
						{
							ad[t] = -1600;
							atm[t] = 40;
							ab[t] -= 1000;
						}
					}	//
					break;

				//クマー
				case 5:
					xx[10] = 160;
					//azimentype[t]=2;
					break;

				//デフラグさん
				case 6:
					if (azimentype[t] == 30) 
					{
						ad[t] = -1600;
						ab[t] += ad[t];
					}

					xx[10] = 120;
					if (atm[t] >= 10) 
					{
						atm[t]++;
						if (mhp >= 1) 
						{
							if (atm[t] <= 19) 
							{
								ma = xx[0];
								mb = xx[1] - 3000;
								mtype = 0;
							}

							xx[10] = 0;
							if (atm[t] == 20) 
							{
								mc = 700;
								mkeytm = 24;
								md = -1200;
								mb = xx[1] - 1000 - 3000;
								amuki[t] = 1;
								if (axtype[t] == 1) 
								{
									mc = 840;
									axtype[t] = 0;
								}
							}

							if (atm[t] == 40) 
							{
								amuki[t] = 0;
								atm[t] = 0;
							}
						}
					}

				//ポール捨て
		    if (axtype[t] == 1) 
				{
					for (tt = 0; tt < smax; tt++) 
					{
						if (stype[tt] == 300) 
						{
							//sa[sco]=xx[21]*100;sb[sco]=xx[22]*100;sc[sco]=3000;sd[sco]=(12-t)*3000;stype[sco]=300;sco++;
							if (aa[t] - fx >= -8000 && aa[t] >= sa[tt] + 2000
									&& aa[t] <= sa[tt] + 3600 && axzimen[t] == 1) 
							{
								sa[tt] = -800000;
								atm[t] = 100;
							}
						}
					}

					if (atm[t] == 100) 
					{
						eyobi(aa[t] + 1200 - 1200, ab[t] + 3000 - 10 * 3000 - 1500, 0, 0, 0, 0, 1000, 10 * 3000 - 1200, 4, 20);
						if (mtype == 300) 
						{
							mtype = 0;
							StopSoundMem(oto[11]);
							bgmchange(otom[1]);
						}

						for (t1 = 0; t1 < smax; t1++) 
						{
							if (stype[t1] == 104)
								sa[t1] = -80000000;
						}
					}

					if (atm[t] == 120) 
					{
						eyobi(aa[t] + 1200 - 1200, ab[t] + 3000 - 10 * 3000 - 1500, 600, -1200, 0, 160, 1000, 10 * 3000 - 1200, 4, 240);
						amuki[t] = 1;
					}

					//mc=700;mkeytm=24;md=-1200;mb=xx[1]-1000-3000;amuki[t]=1;if (axtype[t]==1){mc=840;axtype[t]=0;}}
					if (atm[t] == 140) 
					{
						amuki[t] = 0;
						atm[t] = 0;
					}
				}

		    if (atm[t] >= 220) 
				{
					atm[t] = 0;
					amuki[t] = 0;
		    }

				//他の敵を投げる
		    for (tt = 0; tt < amax; tt++) 
				{
					xx[0] = 250;
					xx[5] = -800;
					xx[12] = 0;
					xx[1] = 1600;
					xx[8] = aa[tt] - fx;
					xx[9] = ab[tt] - fy;
					if (t != tt && atype[tt] >= 100) 
					{
						if (aa[t] + anobia[t] - fx > xx[8] + xx[0] * 2 && aa[t] - fx < xx[8] + anobia[tt] - xx[0] * 2
								&& ab[t] + anobib[t] - fy > xx[9] + xx[5]
								&& ab[t] + anobib[t] - fy < xx[9] + xx[1] * 3 + xx[12] + 1500) 
						{
							//aa[tt]=-800000;
							amuki[tt] = 1;
							aa[tt] = aa[t] + 300;
							ab[tt] = ab[t] - 3000;
							abrocktm[tt] = 120;	//aa[tt]=0;
							atm[t] = 200;
							amuki[t] = 1;
						}
					}
		    }
		    break;

				//ジエン大砲
				case 7:
					azimentype[t] = 0;
					xx[10] = 0;
					xx[11] = 400;
					if (axtype[t] == 0)
						xx[10] = xx[11];
					if (axtype[t] == 1)
						xx[10] = -xx[11];
					if (axtype[t] == 2)
						ab[t] -= xx[11];
					if (axtype[t] == 3)
						ab[t] += xx[11];
						break;

				//スーパーブーン
				case 8:
					azimentype[t] = 0;
					xx[22] = 20;
					if (atm[t] == 0) 
					{
						af[t] += xx[22];
						ad[t] += xx[22];
					}

					if (atm[t] == 1) 
					{
						af[t] -= xx[22];
						ad[t] -= xx[22];
					}

					if (ad[t] > 300)
						ad[t] = 300;

					if (ad[t] < -300)
						ad[t] = -300;

					if (af[t] >= 1200)
						atm[t] = 1;

					if (af[t] < -0)
						atm[t] = 0;

					ab[t] += ad[t];

					//atype[t]=151;
					break;

				//ノーマルブーン
				case 151:
					azimentype[t] = 2;
					break;

				//ファイアー玉
				case 9:
					azimentype[t] = 5;
					ab[t] += ad[t];
					ad[t] += 100;
					if (ab[t] >= fymax + 1000) 
					{
						ad[t] = 900;
					}

					if (ab[t] >= fymax + 12000) 
					{
						ab[t] = fymax;
						ad[t] = -2600;
					}
					break;

				//ファイアー
				case 10:
					azimentype[t] = 0;
					xx[10] = 0;
					xx[11] = 400;
					if (axtype[t] == 0)
						xx[10] = xx[11];
					if (axtype[t] == 1)
						xx[10] = -xx[11];
					break;

				//モララー
				case 30:
					atm[t] += 1;
					if (axtype[t] == 0) 
					{
						if (atm[t] == 50 && mb >= 6000) 
						{
							ac[t] = 300;
							ad[t] -= 1600;
							ab[t] -= 1000;
						}

						for (tt = 0; tt < amax; tt++) 
						{
							xx[0] = 250;
							xx[5] = -800;
							xx[12] = 0;
							xx[1] = 1600;
							xx[8] = aa[tt] - fx;
							xx[9] = ab[tt] - fy;
							if (t != tt && atype[tt] == 102) 
							{
								if (aa[t] + anobia[t] - fx > xx[8] + xx[0] * 2 
										&& aa[t] - fx < xx[8] + anobia[tt] - xx[0] * 2
										&& ab[t] + anobib[t] - fy > xx[9] + xx[5] 
										&& ab[t] + anobib[t] - fy < xx[9] + xx[1] * 3 + xx[12] + 1500) 
								{ 
									aa[tt] = -800000;
									axtype[t] = 1;
									ad[t] = -1600; 
									amsgtm[t] = 30;
									amsgtype[t] = 25;
								}
							}
						}
					}

					if (axtype[t] == 1) 
					{
						azimentype[t] = 0;
						ab[t] += ad[t];
						ad[t] += 120;
					}

					break;

				//レーザー
				case 79:
					azimentype[t] = 0;
					xx[10] = 1600;
					if (axtype[t] == 1) 
					{
						xx[10] = 1200;
						ab[t] -= 200;
					}

					if (axtype[t] == 2) 
					{
						xx[10] = 1200;
						ab[t] += 200;
					}

					if (axtype[t] == 3) 
					{
						xx[10] = 900;
						ab[t] -= 600;
					}

					if (axtype[t] == 4) 
					{
						xx[10] = 900;
						ab[t] += 600;
					}
					break;

				//雲の敵
				case 80:
					azimentype[t] = 0;
					//xx[10]=100;
					break;

				case 81:
					azimentype[t] = 0;
					break;
					
				case 82:
					azimentype[t] = 0;
					break;

				case 83:
					azimentype[t] = 0;
					break;

				case 84:
					azimentype[t] = 2;
					break;

				case 85:
					xx[23] = 400;
					if (axtype[t] == 0) 
					{
						axtype[t] = 1;
						amuki[t] = 1;
					}

					if (mb >= 30000
							&& ma >= aa[t] - 3000 * 5 - fx
							&& ma <= aa[t] - fx && axtype[t] == 1) 
					{
						axtype[t] = 5;
						amuki[t] = 0;
					}

					if (mb >= 24000
							&& ma <= aa[t] + 3000 * 8 - fx
							&& ma >= aa[t] - fx && axtype[t] == 1) 
					{
						axtype[t] = 5;
						amuki[t] = 1;
					}

					if (axtype[t] == 5)
						xx[10] = xx[23];
						break;

				case 86:
					azimentype[t] = 4;
					xx[23] = 1000;

					if (ma >= aa[t] - fx - mnobia - xx[26]
							&& ma <= aa[t] - fx + anobia[t] + xx[26]) 
					{
						atm[t] = 1;
					}

					if (atm[t] == 1) 
					{
						ab[t] += 1200;
					}
					break;

				//ファイアバー
				case 87:
					azimentype[t] = 0;
					if (aa[t] % 10 != 1)
						atm[t] += 6;
					else {
						atm[t] -= 6;
					}

					xx[25] = 2;
					if (atm[t] > 360 * xx[25])
						atm[t] -= 360 * xx[25];

					if (atm[t] < 0)
						atm[t] += 360 * xx[25];

					for (tt = 0; tt <= axtype[t] % 100; tt++) 
					{
						xx[26] = 18;
						xd[4] = tt * xx[26] * cos(atm[t] * pai / 180 / 2);
						xd[5] = tt * xx[26] * sin(atm[t] * pai / 180 / 2);

						xx[4] = 1800;
						xx[5] = 800;
						xx[8] = aa[t] - fx + int (xd[4]) * 100 - xx[4] / 2;
						xx[9] = ab[t] - fy + int (xd[5]) * 100 - xx[4] / 2;

						if (ma + mnobia > xx[8] + xx[5]
								&& ma < xx[8] + xx[4] - xx[5]
								&& mb + mnobib > xx[9] + xx[5]
								&& mb < xx[9] + xx[4] - xx[5]) 
						{
							mhp -= 1;
							mmsgtype = 51;
							mmsgtm = 30;
						}
					}

					break;

				case 88:
					azimentype[t] = 0;
					if (aa[t] % 10 != 1)
						atm[t] += 6;
					else {
						atm[t] -= 6;
					}

					xx[25] = 2;
					if (atm[t] > 360 * xx[25])
						atm[t] -= 360 * xx[25];
					if (atm[t] < 0)
						atm[t] += 360 * xx[25];

					for (tt = 0; tt <= axtype[t] % 100; tt++) 
					{
						xx[26] = 18;
						xd[4] = -tt * xx[26] * cos(atm[t] * pai / 180 / 2);
						xd[5] = tt * xx[26] * sin(atm[t] * pai / 180 / 2);

						xx[4] = 1800;
						xx[5] = 800;
						xx[8] = aa[t] - fx + int (xd[4]) * 100 - xx[4] / 2;
						xx[9] = ab[t] - fy + int (xd[5]) * 100 - xx[4] / 2;

						if (ma + mnobia > xx[8] + xx[5]
								&& ma < xx[8] + xx[4] - xx[5]
								&& mb + mnobib > xx[9] + xx[5]
								&& mb < xx[9] + xx[4] - xx[5]) 
						{
							mhp -= 1;
							mmsgtype = 51;
							mmsgtm = 30;
						}
					}
					break;

				case 90:
					xx[10] = 160;
					//azimentype[t]=0;
					break;

				//おいしいキノコ
				case 100:
					azimentype[t] = 1;
					xx[10] = 100;

					//ほかの敵を巨大化
					if (axtype[t] == 2) 
					{
						for (tt = 0; tt < amax; tt++) 
						{
							xx[0] = 250;
							xx[5] = -800;
							xx[12] = 0;
							xx[1] = 1600;
							xx[8] = aa[tt] - fx;
							xx[9] = ab[tt] - fy;
							if (t != tt) 
							{
								if (aa[t] + anobia[t] - fx > xx[8] + xx[0] * 2 
										&& aa[t] - fx < xx[8] + anobia[tt] - xx[0] * 2
										&& ab[t] + anobib[t] - fy > xx[9] + xx[5] 
										&& ab[t] + anobib[t] - fy < xx[9] + xx[1] * 3 + xx[12]) 
								{
									if (atype[tt] == 0 || atype[tt] == 4) 
									{
										atype[tt] = 90;	//ot(oto[6]);
										anobia[tt] = 6400;
										anobib[tt] = 6300;
										axtype[tt] = 0;
										aa[tt] -= 1050;
										ab[tt] -= 1050;
										ot(oto[9]);
										aa[t] = -80000000;
									}
								}
							}
						}
					}

					break;

				//毒キノコ
				case 102:
					azimentype[t] = 1;
					xx[10] = 100;
					if (axtype[t] == 1)
						xx[10] = 200;

					break;

				//悪スター
				case 110:
					azimentype[t] = 1;
					xx[10] = 200;
					if (axzimen[t] == 1) 
					{
						ab[t] -= 1200;
						ad[t] = -1400;
					}

					break;

				case 200:
					azimentype[t] = 1;
					xx[10] = 100;
					break;

				/*
				case 1:
				xx[10]=180;
				if (axtype[t]==2)xx[10]=0;
				if (axzimen[t]==1){
				ab[t]-=1000;ad[t]=-1200;
				if (axtype[t]==1)ad[t]=-1600;
				if (axtype[t]==2){
				atm[t]+=1;
				if (atm[t]>=2){atm[t]=0;ad[t]=-1600;}else{ad[t]=-1000;}
				}
				}

				break;

				case 2:
				xx[10]=160;
				if (axtype[t]==1)azimentype[t]=2;xx[10]=100;
				if (axtype[t]==2)xx[10]=0;
				break;

				case 3:
				xx[10]=180;
				if (ae[t]==0)ad[t]+=10;
				if (ae[t]==1)ad[t]-=10;
				if (ad[t]>=100)ae[t]=1;
				if (ad[t]<=-100)ae[t]=0;
				ab[t]+=ad[t];//ad[t]+=

				if (axtype[t]==1){
				if (ab[t]<mb){ab[t]+=100;}
				}
				if (axtype[t]==2)xx[10]=0;
				break;

				case 4:
				if (ae[t]==0)ad[t]+=8;
				if (ae[t]==1)ad[t]-=8;
				if (ad[t]>=80)ae[t]=1;
				if (ad[t]<=-80)ae[t]=0;
				ab[t]+=ad[t];

				//sstr=""+atm[t];
				if (axtype[t]>=1){
				xx[22]=200;xx[21]=3600;

				if (atm[t]==0){atm[t]=ab[t]%2+1;a2tm[t]=aa[t];if (axtype[t]%2==0)a2tm[t]=ab[t];}

				if (axtype[t]%2==1){
				if (aa[t]<a2tm[t]-xx[21]){atm[t]=2;}
				if (aa[t]>a2tm[t]+xx[21]){atm[t]=1;}
				if (atm[t]==1){aa[t]-=xx[22];amuki[t]=0;}
				if (atm[t]==2){aa[t]+=xx[22];amuki[t]=1;}
				}
				if (axtype[t]%2==0){
				if (ab[t]<a2tm[t]-xx[21]){atm[t]=2;}
				if (ab[t]>a2tm[t]+xx[21]){atm[t]=1;}
				if (atm[t]==1){ab[t]-=xx[22];}
				if (atm[t]==2){ab[t]+=xx[22];}
				}

				}//axtype1

				break;

				case 5:
				xx[10]=120;atm[t]++;
				if (axtype[t]==2){xx[10]=200;azimentype[t]=2;}
				if (ma+mnobia>=aa[t]-fx && ma<=aa[t]+anobia[t]-fx && mb+mnobib+1000<ab[t]-fy){
				xx[10]=300;
				if (axtype[t]>=1){
				//xx[10]=240;
				if (atm[t]>=16){amuki[t]+=1;if (amuki[t]>=2)amuki[t]=0;atm[t]=0;
				//if (axtype[t]==2){ab[t]-=600;ad[t]=-900;}
				}}
				}
				break;

				case 6:
				atm[t]+=1;xx[10]=0;
				if (axtype[t]==1)atm[t]+=(rand(9)-4);
				if (axtype[t]==2)xx[10]=100;
				if (atm[t]>=40){
				xx[22]=360;if (amuki[t]==0)xx[22]=-xx[22];
				cyobi(aa[t]+amuki[t]*anobia[t],ab[t]+1600,xx[22],0,0,0,0,60);
				atm[t]=0;
				}

				if (axtype[t]!=2){
				if (ma+mnobia/2<=aa[t]+anobia[t]/2-fx){amuki[t]=0;}else{amuki[t]=1;}
				}
				break;

				case 7:
				xx[10]=160;
				if (axtype[t]==1)xx[10]=240;
				if (axtype[t]==2)xx[10]=60;
				break;

					case 8:
					atm[t]+=1;xx[10]=0;
					xx[15]=12;xx[17]=0;
					if (axtype[t]==1)xx[15]=8;
					if (axtype[t]==2){xx[15]=40;xx[17]=3;}

					if (atm[t]>=xx[15]){
					for (t3=0;t3<=xx[17];t3++){
					xx[16]=300;xx[22]=rand(xx[16])*5/4-xx[16]/4;
					a2tm[t]+=1;if (a2tm[t]>=1){xx[22]=-xx[22];a2tm[t]=-1;}
					cyobi(aa[t]+amuki[t]*anobia[t]/2,ab[t]+600,xx[22],-400-rand(600),0,80,1,60);
					//if ((xx[16]==0) || t3==xx[16])atm[t]=0;
					}//t
					atm[t]=0;
					}

					break;


					*/

			}	//sw

			if (abrocktm[t] >= 1)
					xx[10] = 0;

			if (amuki[t] == 0)
					aacta[t] -= xx[10];

			if (amuki[t] == 1)
					aacta[t] += xx[10];

			//最大値
			xx[0] = 850;
			xx[1] = 1200;

			//if (mc>xx[0]){mc=xx[0];}
			//if (mc<-xx[0]){mc=-xx[0];}
			if (ad[t] > xx[1] && azimentype[t] != 5) 
			{
				ad[t] = xx[1];
			}

			//行動
			aa[t] += aacta[t];	//ab[t]+=aactb[t];

			if ((azimentype[t] >= 1 || azimentype[t] == -1) && abrocktm[t] <= 0) 
			{
				//if (atype[t]==4)end();

				//移動
				aa[t] += ac[t];
				if (azimentype[t] >= 1 && azimentype[t] <= 3) 
				{
					ab[t] += ad[t];
					ad[t] += 120;
				}		//ad[t]+=180;

				if (axzimen[t] == 1) 
				{
					xx[0] = 100;
					if (ac[t] >= 200) 
					{
						ac[t] -= xx[0];
					} else 
						if (ac[t] <= -200) 
						{
							ac[t] += xx[0];
						} else {
							ac[t] = 0;
						}
				}

				axzimen[t] = 0;

				//地面判定
				if (azimentype[t] != 2) 
				{
					tekizimen();
				}
			}	// azimentype[t]>=1

			//ブロックから出現するさい
			if (abrocktm[t] > 0) 
			{
		    abrocktm[t]--;
		    if (abrocktm[t] < 100) 
				{
					ab[t] -= 180;
		    }

		    if (abrocktm[t] > 100) 
				{

				}

		    if (abrocktm[t] == 100) 
				{
					ab[t] -= 800;
					ad[t] = -1200;
					ac[t] = 700;
					abrocktm[t] = 0;
		    }
			}	// abrocktm[t]>0

			//プレイヤーからの判定
			xx[0] = 250;
			xx[1] = 1600;
			xx[2] = 1000;
			xx[4] = 500;
			xx[5] = -800;

			xx[8] = aa[t] - fx;
			xx[9] = ab[t] - fy;
			xx[12] = 0;

			if (md >= 100)
					xx[12] = md;

			xx[25] = 0;

			if (ma + mnobia > xx[8] + xx[0] * 2
					&& ma < xx[8] + anobia[t] - xx[0] * 2
					&& mb + mnobib > xx[9] - xx[5]
					&& mb + mnobib < xx[9] + xx[1] + xx[12]
					&& (mmutekitm <= 0 || md >= 100)
					&& abrocktm[t] <= 0) 
			{
				if (atype[t] != 4 && atype[t] != 9 && atype[t] != 10 && (atype[t] <= 78 || atype[t] == 85) && mzimen != 1 && mtype != 200) 
				{	// && atype[t]!=4 && atype[t]!=7){

					if (atype[t] == 0) 
					{
						if (axtype[t] == 0)
							aa[t] = -900000;

						if (axtype[t] == 1) 
						{
							ot(oto[5]);
							mb = xx[9] - 900 - anobib[t];
							md = -2100;
							xx[25] = 1;
							actaon[2] = 0;
						}
					}

					if (atype[t] == 1) 
					{
						atype[t] = 2;
						anobib[t] = 3000;
						axtype[t] = 0;
					} //こうら
						else 
						if (atype[t] == 2 && md >= 0) 
						{
							if (axtype[t] == 1 || axtype[t] == 2) 
							{
								axtype[t] = 0;
							} else 
								if (axtype[t] == 0) 
								{
									if (ma + mnobia > xx[8] + xx[0] * 2 && ma < xx[8] + anobia[t] / 2 - xx[0] * 4) 
									{
										axtype[t] = 1; amuki[t] = 1;
									} else {
										axtype[t] = 1; amuki[t] = 0;
									}
								}
						}

					if (atype[t] == 3) 
					{
						xx[25] = 1;
					}

					if (atype[t] == 6) 
					{
						atm[t] = 10;
						md = 0;
						actaon[2] = 0;
					}

					if (atype[t] == 7) 
					{
						aa[t] = -900000;
					}

					if (atype[t] == 8) 
					{
						atype[t] = 151;
						ad[t] = 0;
					}

					//if (atype[t]==4){
					//xx[25]=1;
					//}

					if (atype[t] != 85) 
					{
						if (xx[25] == 0) 
						{
							ot(oto[5]);
							mb = xx[9] - 1000 - anobib[t];
							md = -1000;
						}
					}

					if (atype[t] == 85) 
					{
						if (xx[25] == 0) 
						{
							ot(oto[5]);
							mb = xx[9] - 4000;
							md = -1000;
							axtype[t] = 5;
						}
					}

					if (actaon[2] == 1) 
					{
						md = -1600;
						actaon[2] = 0;
					}
				}
				//if (atype[t]==200){mb=xx[9]-900-anobib[t];md=-2400;}
			}

			//if (aa[t]+anobia[t]-fx>xx[8]-xx[0] && aa[t]-fx<xx[8]){md=-1000;}//aa[t]=-9000000;
			// && ab[t]-fy<xx[9]+xx[1]/2 && ab[t]+anobib[t]-fy>xx[9]+mnobib-xx[2]

			xx[15] = -500;

			//プレイヤーに触れた時
			xx[16] = 0;
			if (atype[t] == 4 || atype[t] == 9 || atype[t] == 10)
					xx[16] = -3000;

			if (atype[t] == 82 || atype[t] == 83 || atype[t] == 84)
					xx[16] = -3200;
					
			if (atype[t] == 85)
					xx[16] = -anobib[t] + 6000;

			if (ma + mnobia > xx[8] + xx[4]
					&& ma < xx[8] + anobia[t] - xx[4]
					&& mb < xx[9] + anobib[t] + xx[15]
					&& mb + mnobib > xx[9] + anobib[t] - xx[0] + xx[16]
					&& anotm[t] <= 0 && abrocktm[t] <= 0) 
			{
		    if (mmutekion == 1) 
				{
					aa[t] = -9000000;
		    }

		    if (mmutekitm <= 0 && (atype[t] <= 99 || atype[t] >= 200)) 
				{
					if (mmutekion != 1 && mtype != 200) 
					{
						//if (mmutekitm<=0)

						//ダメージ
						if ((atype[t] != 2 || axtype[t] != 0) && mhp >= 1) 
						{
							if (atype[t] != 6) 
							{
								mhp -= 1;
								//mmutekitm=40;
							}
						}

						if (atype[t] == 6) 
						{
							atm[t] = 10;
						}

						//せりふ
						if (mhp == 0) 
						{

							if (atype[t] == 0 || atype[t] == 7) 
							{ 
								amsgtm[t] = 60; amsgtype[t] = rand(7) + 1 + 1000 + (stb - 1) * 10;
							}

							if (atype[t] == 1) 
							{
								amsgtm[t] = 60;
								amsgtype[t] = rand(2) + 15;
							}

							if (atype[t] == 2 && axtype[t] >= 1 && mmutekitm <= 0) 
							{
								amsgtm[t] = 60;
								amsgtype[t] = 18;
							}

							if (atype[t] == 3) 
							{
								amsgtm[t] = 60;
								amsgtype[t] = 20;
							}

							if (atype[t] == 4) 
							{
								amsgtm[t] = 60;
								amsgtype[t] = rand(7) + 1 + 1000 + (stb - 1) * 10;
							}

							if (atype[t] == 5)
							{
								amsgtm[t] = 60;
								amsgtype[t] = 21;
							}

							if (atype[t] == 9 || atype[t] == 10) 
							{
								mmsgtm = 30;
								mmsgtype = 54;
							}

							if (atype[t] == 31) 
							{
								amsgtm[t] = 30;
								amsgtype[t] = 24;
							}

							if (atype[t] == 80 || atype[t] == 81) 
							{
								amsgtm[t] = 60;
								amsgtype[t] = 30;
							}

							if (atype[t] == 82) 
							{
								amsgtm[t] = 20;
								amsgtype[t] = rand(1) + 31; xx[24] = 900; atype[t] = 83;
								aa[t] -= xx[24] + 100;
								ab[t] -= xx[24] - 100 * 0;
							}	//82

							if (atype[t] == 84) 
							{
								mmsgtm = 30;
								mmsgtype = 50;
							}

							if (atype[t] == 85) 
							{
								amsgtm[t]
								= 60;
									amsgtype[t]
								= rand(1)
								+ 85;
							}
							//雲
							if (atype[t] == 80) 
							{
								atype[t] = 81;
							}
						}	//mhp==0

						//こうら
						if (atype[t] == 2) 
						{
							//if (axtype[t]==1 || axtype[t]==2){axtype[t]=0;}
							if (axtype[t] == 0) 
							{
								if (ma + mnobia > xx[8] + xx[0] * 2 && ma < xx[8] + anobia[t] / 2 - xx[0] * 4) 
								{
									axtype[t] = 1;
									amuki[t] = 1;
									aa[t] = ma + mnobia + fx + mc;
									mmutekitm = 5; 
								} else {
									axtype[t] = 1;
									amuki[t] = 0;
										aa[t] = ma - anobia[t] + fx - mc;
										mmutekitm = 5;
								}
							} else {
								mhp -= 1;
							}	// mmutekitm=40;}
						}
					}
		    }
				
					//else if (mmutekitm>=0 && mmutekitm<=2){mmutekitm+=1;}
					//アイテム
					if (atype[t] >= 100 && atype[t] <= 199) 
					{
						if (atype[t] == 100 && axtype[t] == 0) 
						{
							mmsgtm = 30;
							mmsgtype = 1;
							ot(oto[9]);
						}

						if (atype[t] == 100 && axtype[t] == 1) 
						{
							mmsgtm = 30;
							mmsgtype = 2;
							ot(oto[9]);
						}

						if (atype[t] == 100 && axtype[t] == 2) 
						{
							mnobia = 5200;
							mnobib = 7300;
							ot(oto[9]);
							ma -= 1100;
							mb -= 4000;
							mtype = 1;
							mhp = 50000000;
						}

						if (atype[t] == 101) 
						{
							mhp -= 1;
							mmsgtm = 30;
							mmsgtype = 11;
						}

						if (atype[t] == 102) 
						{
							mhp -= 1;
							mmsgtm = 30;
							mmsgtype = 10;
						}

						//?ボール
						if (atype[t] == 105) 
						{
							if (axtype[t] == 0) 
							{
								ot(oto[4]);
								sgtype[26] = 6;
							}

							if (axtype[t] == 1) 
							{
								txtype[7] = 80;
								ot(oto[4]);

								//ayobi(aa[t]-6*3000+1000,-3*3000,0,0,0,110,0);
								ayobi(aa[t] - 8 * 3000 - 1000, -4 * 3000, 0, 0, 0, 110, 0);
								ayobi(aa[t] - 10 * 3000 + 1000, -1 * 3000, 0, 0, 0, 110, 0);

								ayobi(aa[t] + 4 * 3000 + 1000, -2 * 3000, 0, 0, 0, 110, 0);
								ayobi(aa[t] + 5 * 3000 - 1000, -3 * 3000, 0, 0, 0, 110, 0);
								ayobi(aa[t] + 6 * 3000 + 1000, -4 * 3000, 0, 0, 0, 110, 0);
								ayobi(aa[t] + 7 * 3000 - 1000, -2 * 3000, 0, 0, 0, 110, 0);
								ayobi(aa[t] + 8 * 3000 + 1000, -2 * 3000 - 1000, 0, 0, 0, 110, 0);
								tb[0] += 3000 * 3;
							}
						}	//105

						if (atype[t] == 110) 
						{
							mhp -= 1;
							mmsgtm = 30;
							mmsgtype = 3;
						}

						/*
						if (atype[t]==101){mmutekitm=120;mmutekion=1;}
						if (atype[t]==102){mhp-=1;mmutekitm=20;}
						if (atype[t]==103){
						//xx[24]=2400;
						eyobi(aa[t]-500,ab[t],0,-600,0,80,2500,1600,2,32);
						}
						if (atype[t]==104){mztm=120;mztype=1;}
						if (atype[t]==105){mztm=160;mztype=2;}

						if (atype[t]==120){mtype=3;mnobia=3800;mnobib=2300;}

						if (atype[t]==130){msoubi=1;}
						if (atype[t]==131){msoubi=2;}
						if (atype[t]==132){msoubi=3;}
						if (atype[t]==133){msoubi=4;}

						*/
							aa[t] = -90000000;
						}
					}	//(ma
				} else {
					aa[t] = -9000000;
				}

		}	// t

			//スクロール
			//xx[0]=xx[0];
			//x

		if (kscroll != 1 && kscroll != 2) 
		{
			xx[2] = mascrollmax;
			xx[3] = 0;
			xx[1] = xx[2];
			if (ma > xx[1] && fzx < scrollx) 
			{
				xx[5] = ma - xx[1];
				ma = xx[1];
				fx += xx[5];
				fzx += xx[5];

				if (xx[1] <= 5000)
					xx[3] = 1;
			}
			//if (kscroll!=5){//戻りなし
			//xx[1]=xx[2]-500;if (ma<xx[1] && fzx>700){xx[5]=xx[1]-ma;ma=xx[1];fx-=xx[5];fzx-=xx[5];}
			//}
			//if (xx[3]==1){if (tyuukan==1)tyuukan=1;}
		}	// kscroll

	}	//if (mainZ==1){

	//スタッフロール
	if (mainZ == 2) 
	{
		maintm++;

		xx[7] = 46;
		if (CheckHitKey(KEY_INPUT_1) == 1) 
		{
	    // end();
	    exit(0);
		}

		if (CheckHitKey(KEY_INPUT_SPACE) == 1) 
		{
	    for (t = 0; t <= xx[7]; t += 1) {
				xx[12 + t] -= 300;
	    }
		}

		if (maintm <= 1) 
		{
	    maintm = 2;
	    bgmchange(otom[5]);
	    xx[10] = 0;
	    for (t = 0; t <= xx[7]; t += 1) 
			{
				xx[12 + t] = 980000;
	    }

			//for (t=0;t<=xx[7];t+=2){xx[12+t]=46000;}
	    xx[12] = 460;
	    xx[13] = 540;
	    xx[14] = 590;
	    xx[15] = 650;
	    xx[16] = 700;
	    xx[17] = 760;
	    xx[18] = 810;
	    xx[19] = 870;
	    xx[20] = 920;

	    xx[21] = 1000;
	    xx[22] = 1050;
	    xx[23] = 1100;
	    xx[24] = 1180;
	    xx[25] = 1230;

	    xx[26] = 1360;
	    xx[27] = 1410;
	    xx[28] = 1540;
	    xx[29] = 1590;

	    xx[30] = 1800;

	    for (t = 0; t <= xx[7]; t += 1) 
			{
				xx[12 + t] *= 100;
	    }
		}

		xx[10] += 1;
		for (t = 0; t <= xx[7]; t += 1) 
		{
	    xx[12 + t] -= 100;
		}	// t

		if (xx[30] == -200) 
		{
			bgmchange(otom[5]);
		}

		if (xx[30] <= -400) 
		{
	    mainZ = 100;
	    nokori = 2;
	    maintm = 0;
	    ending = 0;
		}

	}				//mainZ==2

	if (mainZ == 10) 
	{
		maintm++;

		if (fast == 1)
	    maintm += 2;

		if (maintm >= 30) 
		{
	    maintm = 0;
	    mainZ = 1;
	    zxon = 0;
		}
	}				//if (mainZ==10){

	//タイトル
	if (mainZ == 100) 
	{
		maintm++;
		xx[0] = 0;
		if (maintm <= 10) 
		{
	    maintm = 11;
	    sta = 1;
	    stb = 1;
	    stc = 0;
	    over = 0;
		}

		if (CheckHitKey(KEY_INPUT_1) == 1) 
		{
	    sta = 1;
	    stb = 1;
	    stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_2) == 1) 
		{
	    sta = 1;
	    stb = 2;
	    stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_3) == 1) 
		{
			sta = 1;
			stb = 3;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_4) == 1) 
		{
			sta = 1;
			stb = 4;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_5) == 1) 
		{
			sta = 2;
			stb = 1;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_6) == 1) 
		{
			sta = 2;
			stb = 2;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_7) == 1) 
		{
			sta = 2;
			stb = 3;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_8) == 1) {
			sta = 2;
			stb = 4;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_9) == 1) 
		{
			sta = 3;
			stb = 1;
			stc = 0;
		}

		if (CheckHitKey(KEY_INPUT_0) == 1) 
		{
			xx[0] = 1;
			over = 1;
		}

		//if (CheckHitKeyAll() == 0){end();}
		if (CheckHitKey(KEY_INPUT_RETURN) == 1) 
		{
			xx[0] = 1;
		}

		//if (CheckHitKey(KEY_INPUT_SPACE)==1){xx[0]=1;}
		if (CheckHitKey(KEY_INPUT_Z) == 1) 
		{
			xx[0] = 1;
		}

		if (xx[0] == 1) 
		{
			mainZ = 10;
			zxon = 0;
			maintm = 0;
			nokori = 2;

			fast = 0;
			trap = 0;
			tyuukan = 0;
		}

	}	//100

	//描画
	rpaint();

	//30-fps
	xx[0] = 30;
	if (CheckHitKey(KEY_INPUT_SPACE) == 1) 
	{
		xx[0] = 60;
	}

	wait2(stime, long (GetNowCount()), 1000 / xx[0]);

	//wait(20);

}	//Mainprogram()