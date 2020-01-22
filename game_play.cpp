#include "game_play.h"

void tekizimen()
{

//壁
    for (tt = 0; tt < smax; tt++) {
	if (sa[tt] - fx + sc[tt] >= -12010
	    && sa[tt] - fx <= fxmax + 12100 && stype[tt] <= 99) {
	    xx[0] = 200;
	    xx[2] = 1000;
	    xx[1] = 2000;	//anobia[t]

	    xx[8] = sa[tt] - fx;
	    xx[9] = sb[tt] - fy;
	    if (aa[t] + anobia[t] - fx > xx[8] - xx[0]
		&& aa[t] - fx < xx[8] + xx[2]
		&& ab[t] + anobib[t] - fy > xx[9] + xx[1] * 3 / 4
		&& ab[t] - fy < xx[9] + sd[tt] - xx[2]) {
		aa[t] = xx[8] - xx[0] - anobia[t] + fx;
		amuki[t] = 0;
	    }
	    if (aa[t] + anobia[t] - fx > xx[8] + sc[tt] - xx[0]
		&& aa[t] - fx < xx[8] + sc[tt] + xx[0]
		&& ab[t] + anobib[t] - fy > xx[9] + xx[1] * 3 / 4
		&& ab[t] - fy < xx[9] + sd[tt] - xx[2]) {
		aa[t] = xx[8] + sc[tt] + xx[0] + fx;
		amuki[t] = 1;
	    }
//if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+sc[tt]-xx[0] && ab[t]+anobib[t]-fy>xx[9] && ab[t]+anobib[t]-fy<xx[9]+xx[1] && ad[t]>=-100){ab[t]=sb[tt]-fy-anobib[t]+100+fy;ad[t]=0;}//mzimen=1;}
	    if (aa[t] + anobia[t] - fx > xx[8] + xx[0]
		&& aa[t] - fx < xx[8] + sc[tt] - xx[0]
		&& ab[t] + anobib[t] - fy > xx[9]
		&& ab[t] + anobib[t] - fy < xx[9] + sd[tt] - xx[1]
		&& ad[t] >= -100) {
		ab[t] = sb[tt] - fy - anobib[t] + 100 + fy;
		ad[t] = 0;
		axzimen[t] = 1;
	    }

	    if (aa[t] + anobia[t] - fx > xx[8] + xx[0]
		&& aa[t] - fx < xx[8] + sc[tt] - xx[0]
		&& ab[t] - fy > xx[9] + sd[tt] - xx[1]
		&& ab[t] - fy < xx[9] + sd[tt] + xx[0]) {
		ab[t] = xx[9] + sd[tt] + xx[0] + fy;
		if (ad[t] < 0) {
		    ad[t] = -ad[t] * 2 / 3;
		}		//axzimen[t]=1;
	    }

	}
    }

//ブロック
    for (tt = 0; tt < tmax; tt++) {
	xx[0] = 200;
	xx[1] = 3000;
	xx[2] = 1000;
	xx[8] = ta[tt] - fx;
	xx[9] = tb[tt] - fy;
	if (ta[tt] - fx + xx[1] >= -12010 && ta[tt] - fx <= fxmax + 12000) {
	    if (atype[t] != 86 && atype[t] != 90 && ttype[tt] != 140) {

//上
		if (ttype[tt] != 7) {
//if (ttype[tt]==117 && txtype[t]==1){ad[t]=-1500;}
		    if (!(ttype[tt] == 117)) {
//if (!(ttype[tt]==120 && txtype[t]==0)){
			if (aa[t] + anobia[t] - fx > xx[8] + xx[0]
			    && aa[t] - fx <
			    xx[8] + xx[1] - xx[0] * 1
			    && ab[t] + anobib[t] - fy > xx[9]
			    && ab[t] + anobib[t] - fy < xx[9] + xx[1]
			    && ad[t] >= -100) {
			    ab[t] = xx[9] - anobib[t] + 100 + fy;
			    ad[t] = 0;
			    axzimen[t] = 1;
//ジャンプ台
			    if (ttype[tt] == 120) {
				ad[t] = -1600;
				azimentype[t] = 30;
			    }
//}

			}
		    }
		}
//下
		if (ttype[tt] != 117) {
		    if (aa[t] + anobia[t] - fx > xx[8] + xx[0]
			&& aa[t] - fx <
			xx[8] + xx[1] - xx[0] * 1
			&& ab[t] - fy > xx[9] + xx[1] - xx[1]
			&& ab[t] - fy < xx[9] + xx[1] + xx[0]) {
			ab[t] = xx[9] + xx[1] + xx[0] + fy;
			if (ad[t] < 0) {
			    ad[t] = 0;
			}	//=-ad[t]*2/3;}
//if (ttype[t]==7){
//for (t2=0;t2<tmax;t2++){if (ttype[t2]==5){ttype[t2]=6;}else if (ttype[t2]==6){ttype[t2]=5;}}
//}
		    }
		}
//左右
		xx[27] = 0;
		if ((atype[t] >= 100
		     || (ttype[tt] != 7 || ttype[tt] == 7
			 && atype[t] == 2))
		    && ttype[tt] != 117) {
		    if (aa[t] + anobia[t] - fx > xx[8]
			&& aa[t] - fx < xx[8] + xx[2]
			&& ab[t] + anobib[t] - fy >
			xx[9] + xx[1] / 2 - xx[0]
			&& ab[t] - fy < xx[9] + xx[2]) {
			aa[t] = xx[8] - anobia[t] + fx;
			ac[t] = 0;
			amuki[t] = 0;
			xx[27] = 1;
		    }
		    if (aa[t] + anobia[t] - fx >
			xx[8] + xx[1] - xx[0] * 2
			&& aa[t] - fx < xx[8] + xx[1]
			&& ab[t] + anobib[t] - fy >
			xx[9] + xx[1] / 2 - xx[0]
			&& ab[t] - fy < xx[9] + xx[2]) {
			aa[t] = xx[8] + xx[1] + fx;
			ac[t] = 0;
			amuki[t] = 1;
			xx[27] = 1;
		    }
//こうらブレイク
		    if (xx[27] == 1 && (ttype[tt] == 7 || ttype[tt] == 1)
			&& atype[t] == 2) {
			if (ttype[tt] == 7) {
			    ot(oto[4]);
			    ttype[tt] = 3;
			    eyobi(ta[tt] + 10,
				  tb[tt], 0, -800,
				  0, 40, 3000, 3000, 0, 16);
			} else if (ttype[tt] == 1) {
			    ot(oto[3]);
			    eyobi(ta[tt] + 1200,
				  tb[tt] + 1200,
				  300, -1000, 0, 160, 1000, 1000, 1, 120);
			    eyobi(ta[tt] + 1200,
				  tb[tt] + 1200,
				  -300, -1000, 0, 160, 1000, 1000, 1, 120);
			    eyobi(ta[tt] + 1200,
				  tb[tt] + 1200,
				  240, -1400, 0, 160, 1000, 1000, 1, 120);
			    eyobi(ta[tt] + 1200,
				  tb[tt] + 1200,
				  -240, -1400, 0, 160, 1000, 1000, 1, 120);
			    brockbreak(tt);
			}

		    }
		}
	    }
	    if (atype[t] == 86 || atype[t] == 90) {
		if (aa[t] + anobia[t] - fx > xx[8]
		    && aa[t] - fx < xx[8] + xx[1]
		    && ab[t] + anobib[t] - fy > xx[9]
		    && ab[t] - fy < xx[9] + xx[1]) {
		    ot(oto[3]);
		    eyobi(ta[tt] + 1200, tb[tt] + 1200, 300,
			  -1000, 0, 160, 1000, 1000, 1, 120);
		    eyobi(ta[tt] + 1200, tb[tt] + 1200,
			  -300, -1000, 0, 160, 1000, 1000, 1, 120);
		    eyobi(ta[tt] + 1200, tb[tt] + 1200, 240,
			  -1400, 0, 160, 1000, 1000, 1, 120);
		    eyobi(ta[tt] + 1200, tb[tt] + 1200,
			  -240, -1400, 0, 160, 1000, 1000, 1, 120);
		    brockbreak(tt);

		}
	    }			//90

	}
//剣とってクリア
	if (ttype[tt] == 140) {
	    if (ab[t] - fy > xx[9] - xx[0] * 2 - 2000
		&& ab[t] - fy < xx[9] + xx[1] - xx[0] * 2 + 2000
		&& aa[t] + anobia[t] - fx > xx[8] - 400
		&& aa[t] - fx < xx[8] + xx[1]) {
		ta[tt] = -800000;	//ot(oto[4]);
		sracttype[20] = 1;
		sron[20] = 1;
	    }
	}
    }				//tt

}				//tekizimen

//タイマー測定
void wait2(long stime, long etime, int FLAME_TIME)
{
    if (etime - stime < FLAME_TIME)
	wait(FLAME_TIME - (etime - stime));
}

//乱数作成
int rand(int Rand)
{
    return rand() % Rand;
}

//終了
void deinit()
{
    setc0();
    FillScreen();
    DrawString(200, 200, "EXITING...", GetColor(255, 255, 255));
    SDL_Flip(screen);

//SURFACES
    for (t = 0; t < 51; t++)
	SDL_FreeSurface(mgrap[t]);
    for (int i = 0; i < 161; i++)
	for (int j = 0; j < 8; j++)
	    SDL_FreeSurface(grap[i][j]);
//--

//SOUNDS
    for (int i = 1; i < 6; i++)
	Mix_FreeMusic(otom[i]);
    for (int i = 1; i < 19; i++)
	Mix_FreeChunk(oto[i]);
//--

//Font
    for (int i = 0; i < FONT_MAX; i++)
	TTF_CloseFont(font[i]);

//Joystick
    SDL_JoystickClose(joystick);

//Close libraries
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

//画像関係
//{
//色かえ(指定)
void setcolor(int red, int green, int blue)
{
    color = GetColor(red, green, blue);
    gfxcolor = red << 8 * 3 | green << 8 * 2 | blue << 8 | 0xFF;
}

//色かえ(黒)(白)
void setc0()
{
    setcolor(0, 0, 0);
}

void setc1()
{
    setcolor(255, 255, 255);
}

//点
void drawpixel(int a, int b)
{
    pixelColor(screen, a, b, gfxcolor);
}

//線
void drawline(int a, int b, int c, int d)
{
    lineColor(screen, a, b, c, d, gfxcolor);
}

//四角形(塗り無し)
void drawrect(int a, int b, int c, int d)
{
    rectangleColor(screen, a, b, a + c - 1, b + d - 1, gfxcolor);
}

//四角形(塗り有り)
void fillrect(int a, int b, int c, int d)
{
    boxColor(screen, a, b, a + c - 1, b + d - 1, gfxcolor);
}

//円(塗り無し)
void drawarc(int a, int b, int c, int d)
{
    ellipseColor(screen, a, b, c, d, gfxcolor);
}

//円(塗り有り)
void fillarc(int a, int b, int c, int d)
{
    filledEllipseColor(screen, a, b, c, d, gfxcolor);
}

void FillScreen()
{
    SDL_FillRect(screen, 0, color);
}

//画像の読み込み
SDL_Surface *loadimage(string x)
{
//mgrap[a]=LoadGraph(b);
    return LoadGraph(x.c_str());
}

SDL_Surface *loadimage(SDL_Surface * a, int x, int y, int r, int z)
{
    return DerivationGraph(x, y, r, z, a);
}

//画像表示
void drawimage(SDL_Surface * mx, int a, int b)
{
    if (mirror == 0)
	DrawGraph(a, b, mx, TRUE);
    if (mirror == 1)
	DrawTurnGraph(a, b, mx, TRUE);
}

void drawimage(SDL_Surface * mx, int a, int b, int c, int d, int e, int f)
{
    SDL_Surface *m;
    m = DerivationGraph(c, d, e, f, mx);
    if (mirror == 0)
	DrawGraph(a, b, m, TRUE);
    if (mirror == 1)
	DrawTurnGraph(a, b, m, TRUE);
    SDL_FreeSurface(m);
}

/*
//文字
void str(char d[],int a,int b){
//char d[]=c;
DrawString(a,b,d,color);
}
*/

//文字
void str(string x, int a, int b)
{
//char d[]="あ";
    DrawString(a, b, x.c_str(), color);
//DrawString(10,10,xs[3].c_str(),color);

    xx[2] = 4;

}

/*
//数値を文字に変換
void strchange(string x,int a){
}
*/

/*
//中央にあわせる//(font)
void str1(String c,int r,int b){
int a=0,x=0;
int d=6;

//x=c.length()*d;//tiny.6
x=r*d;
a=120-x/2;

g.drawString(c,a,b);
}
*/

//string→int
/*
char str[] = "12345";
int num;

num = atoi(str);
*/

//文字ラベル変更
void setfont(int a)
{
/*
if (a==0)g.setFont(Font.getFont(Font.SIZE_TINY));
if (a==1)g.setFont(Font.getFont(Font.SIZE_SMALL));
if (a==2)g.setFont(Font.getFont(Font.SIZE_MEDIUM));
if (a==3)g.setFont(Font.getFont(Font.SIZE_LARGE));
*/
}

//音楽再生
void ot(Mix_Chunk * x)
{
    PlaySoundMem(x, DX_PLAYTYPE_BACK);
}

void stagecls()
{
    for (t = 0; t < smax; t++) {
	sa[t] = -9000000;
	sb[t] = 1;
	sc[t] = 1;
	sd[t] = 1;
	sgtype[t] = 0;
	stype[t] = 0;
	sxtype[t] = 0;
    }
//for (t=0;t<spmax;t++){spa[t]=-9000000;szyunni[t]=t;spb[t]=1;spc[t]=1;spd[t]=1;sptype[t]=0;spgtype[t]=0;}
    for (t = 0; t < tmax; t++) {
	ta[t] = -9000000;
	tb[t] = 1;
	tc[t] = 1;
	td[t] = 1;
	titem[t] = 0;
	txtype[t] = 0;
    }
    for (t = 0; t < srmax; t++) {
	sra[t] = -9000000;
	srb[t] = 1;
	src[t] = 1;
	srd[t] = 1;
	sre[t] = 0;
	srf[t] = 0;
	srmuki[t] = 0;
	sron[t] = 0;
	sree[t] = 0;
	srsok[t] = 0;
	srmove[t] = 0;
	srmovep[t] = 0;
	srsp[t] = 0;
    }
//for (t=0;t<sqmax;t++){sqa[t]=-9000000;sqb[t]=1;sqc[t]=1;sqd[t]=1;sqgtype[t]=0;sqtype[t]=0;}
//for (t=0;t<kmax;t++){ka[t]=-9000000;kmuki[t]=0;ksoka[t]=0;ksokb[t]=0;kxsoka[t]=0;kxsokb[t]=0;}
//for (t=0;t<imax;t++){ia[t]=-9000000;ib[t]=1;ic[t]=1;id[t]=1;}
    for (t = 0; t < amax; t++) {
	aa[t] = -9000000;
	ab[t] = 1;
	ac[t] = 0;
	ad[t] = 1;
	azimentype[t] = 0;
	atype[t] = 0;
	axtype[t] = 0;
	ae[t] = 0;
	af[t] = 0;
	atm[t] = 0;
	a2tm[t] = 0;
	abrocktm[t] = 0;
	amsgtm[t] = 0;
    }
    for (t = 0; t < bmax; t++) {
	ba[t] = -9000000;
	bb[t] = 1;
	bz[t] = 1;
	btm[t] = 0;
	bxtype[t] = 0;
    }
    for (t = 0; t < emax; t++) {
	ea[t] = -9000000;
	eb[t] = 1;
	ec[t] = 1;
	ed[t] = 1;
	egtype[t] = 0;
    }
    for (t = 0; t < nmax; t++) {
	na[t] = -9000000;
	nb[t] = 1;
	nc[t] = 1;
	nd[t] = 1;
	ne[t] = 1;
	nf[t] = 1;
	ng[t] = 0;
	ntype[t] = 0;
    }
//for (t=0;t<cmax;t++){ca[t]=-9000000;cb[t]=1;contm[t]=0;ctype[t]=0;ce[t]=0;cf[t]=0;}
//for (t=0;t<vmax;t++){va[t]=-9000000;vtype[t]=0;vb[t]=0;vc[t]=1;vd[t]=1;}
//for (t=0;t<gmax;t++){ga[t]=-9000000;gx[t]=0;gstring[t]="";}

    sco = 0;
    tco = 0;
    aco = 0;
    bco = 0;
    eco = 0;
    nco = 0;
//haikeitouroku();
}				//stagecls()

//ステージロード
void stage()
{
	//fzx=6000*100;
	scrollx = 3600 * 100;

	//byte stagedate[16][801];
	//byte stagedate2[16][801];

	//1-レンガ,2-コイン,3-空,4-土台//5-6地面//7-隠し//

	stagep();

	for (tt = 0; tt <= 1000; tt++) {
		for (t = 0; t <= 16; t++) 
		{
	    xx[10] = 0;
	    if (stagedate[t][tt] >= 1 && stagedate[t][tt] <= 255)
				xx[10] = (int) stagedate[t][tt];

			xx[21] = tt * 29;
			xx[22] = t * 29 - 12;
			xx[23] = xx[10];

	    if (xx[10] >= 1 && xx[10] <= 19 && xx[10] != 9) 
			{
				tyobi(tt * 29, t * 29 - 12, xx[10]);
	    }

	    if (xx[10] >= 20 && xx[10] <= 29) 
			{
				sra[srco] = xx[21] * 100;
				srb[srco] = xx[22] * 100;
				src[srco] = 3000;
				srtype[srco] = 0;
				srco++;

				if (srco >= srmax)
					srco = 0;
	    }

	    if (xx[10] == 30) 
			{
				sa[sco] = xx[21] * 100;
				sb[sco] = xx[22] * 100;
				sc[sco] = 3000;
				sd[sco] = 6000;
				stype[sco] = 500;
				sco++;
				if (sco >= smax)
						sco = 0;
	    }

	    if (xx[10] == 40) 
			{
				sa[sco] = xx[21] * 100;
				sb[sco] = xx[22] * 100;
				sc[sco] = 6000;
				sd[sco] = 3000;
				stype[sco] = 1;
				sco++;
				if (sco >= smax)
					sco = 0;
	    }
	    if (xx[10] == 41) 
			{
				sa[sco] = xx[21] * 100 + 500;
				sb[sco] = xx[22] * 100;
				sc[sco] = 5000;
				sd[sco] = 3000;
				stype[sco] = 2;
				sco++;
				if (sco >= smax)
					sco = 0;
	    }

	    if (xx[10] == 43) {
				sa[sco] = xx[21] * 100;
				sb[sco] = xx[22] * 100 + 500;
				sc[sco] = 2900;
				sd[sco] = 5300;
				stype[sco] = 1;
				sco++;
				if (sco >= smax)
					sco = 0;
	    }

	    if (xx[10] == 44) 
			{
				sa[sco] = xx[21] * 100;
				sb[sco] = xx[22] * 100 + 700;
				sc[sco] = 3900;
				sd[sco] = 5000;
				stype[sco] = 5;
				sco++;
				if (sco >= smax)
					sco = 0;
	    }

			//これなぜかバグの原因ｗ
	    if (xx[10] >= 50 && xx[10] <= 79) 
			{
				ba[bco] = xx[21] * 100;
				bb[bco] = xx[22] * 100;
				btype[bco] = xx[23] - 50;
				bco++;
				if (bco >= bmax)
					bco = 0;
	    }

	    if (xx[10] >= 80 && xx[10] <= 89) 
			{
				na[nco] = xx[21] * 100;
				nb[nco] = xx[22] * 100;
				ntype[nco] = xx[23] - 80;
				nco++;
				if (nco >= nmax)
					nco = 0;
	    }

			//コイン
	    if (xx[10] == 9) 
			{
				tyobi(tt * 29, t * 29 - 12, 800);
	    }

	    if (xx[10] == 99) 
			{
				sa[sco] = xx[21] * 100;
				sb[sco] = xx[22] * 100;
				sc[sco] = 3000;
				sd[sco] = (12 - t) * 3000;
				stype[sco] = 300;
				sco++;
				if (sco >= smax)
					sco = 0;
	    }
		}
	}

	if (tyuukan >= 1) 
	{
		xx[17] = 0;
		for (t = 0; t < smax; t++) 
		{
			if (stype[t] == 500 && tyuukan >= 1) 
			{
				fx = sa[t] - fxmax / 2;
				fzx = fx;
				ma = sa[t] - fx;
				mb = sb[t] - fy;
				tyuukan--;
				xx[17]++;

				sa[t] = -80000000;
			}
		}
		tyuukan += xx[17];
	}
	//tyobi(1,2,3);
}				//stage()



//BGM変更
void bgmchange(Mix_Music * x)
{
    Mix_HaltMusic();
//otom[0]=0;
    otom[0] = x;
    Mix_PlayMusic(otom[0], -1);;
    if(x == otom[2]) Mix_VolumeMusic(MIX_MAX_VOLUME * 40 / 100);
    else Mix_VolumeMusic(MIX_MAX_VOLUME * 50 / 100);
}				//bgmchange()

//ブロック出現

void tyobi(int x, int y, int type)
{

    ta[tco] = x * 100;
    tb[tco] = y * 100;
    ttype[tco] = type;

    tco++;
    if (tco >= tmax)
	tco = 0;
}				//tyobi

//ブロック破壊
void brockbreak(int t)
{
    if (titem[t] == 1) {
//eyobi(ta[t],tb[t],0,-800,0,80,xx[1],xx[1],titem[t],8);
//hosico++;
    }
    if (titem[t] >= 2 && titem[t] <= 7) {
//ayobi(ta[t],tb[t],-800,10,100+(titem[t]-2),0);//end();
    }

    ta[t] = -800000;
//}//ty==1
}				//brock

//メッセージ
void ttmsg()
{
    xx[1] = 6000 / 100;
    xx[2] = 4000 / 100;
    if (tmsgtype == 1 || tmsgtype == 2) {
	setc0();
	fillrect(xx[1], xx[2], 360, tmsgy / 100);
	setc1();
	drawrect(xx[1], xx[2], 360, tmsgy / 100);
    }
    if (tmsgtype == 2) {
//フォント
	setfont(20, 5);

	if (tmsg == 0) {
	    setc1();
//フォント
	    setfont(20, 5);
	    txmsg("テスト　hoge", 0);
	}

	if (tmsg == 1) {
	    setc1();
	    txmsg("", 0);
	    txmsg("ステージ 1 より", 0);
	    txmsg("特殊的なものが増えたので", 1);
	    txmsg("気をつけてくれよ〜", 2);
	    txmsg
		("後、アイテムの一部を利用するかも…", 4);
	    txmsg("                       ちく より", 6);
	}

	if (tmsg == 2) {
	    txmsg("            ？が必要です ", 3);
	    txmsg("                         m9(^Д^)", 6);
	}

	if (tmsg == 3) {
	    txmsg("   別にコインに意味ないけどね ", 3);
	    txmsg("                      (・ω・ )ﾉｼ", 6);
	}

	if (tmsg == 4) {
	    txmsg("この先に隠しブロックがあります ", 2);
	    txmsg("注意してください !!", 4);
	}

	if (tmsg == 5) {
	    txmsg("", 0);
	    txmsg(" 前回よりも難易度を下げましたので", 1);
	    txmsg(" 気楽にプレイしてください    ", 3);
	    txmsg("                       ちく より", 6);
	}

	if (tmsg == 6) {
	    txmsg("", 0);
	    txmsg(" そこにいる敵のそばによると、      ", 1);
	    txmsg
		(" 自分と一緒にジャンプしてくれます。",
		 2);
	    txmsg("   可愛いですね。                  ", 3);
	}

	if (tmsg == 7) {
	    txmsg("", 0);
	    txmsg(" あの敵は連れて来れましたか?、     ", 1);
	    txmsg(" 連れて来れなかった貴方は、        ", 2);
	    txmsg(" そこの落とし穴から Let's dive!    ", 3);
	}

	if (tmsg == 8) {
	    txmsg("そんな容易に", 1);
	    txmsg("ヒントに頼るもんじゃないぜ", 2);
	    txmsg("ほら、さっさと次行きな!!", 3);
	}

	if (tmsg == 9) {
	    txmsg(" 正真正銘のファイナルステージ。    ", 1);
	    txmsg(" クリアすれば遂にエンディング!!    ", 2);
	    txmsg(" その土管から戻ってもいいんだぜ?   ", 3);
	}

	if (tmsg == 10) {
	    txmsg
		(" 床が凍ってるから、すっごい滑るよ。",
		 1);
	    txmsg(" ", 2);
	    txmsg(" 　                      ", 3);
	}

	if (tmsg == 100) {
	    txmsg("え？私ですか？ ", 0);
	    txmsg("いやぁ、ただの通りすがりの", 2);
	    txmsg("ヒントブロックですよ〜", 3);
	    txmsg
		("決して怪しいブロックじゃないですよ", 5);
	    txmsg("                          (…チッ)", 6);
	}

	setfont(16, 4);
    }				//2

    if (tmsgtype == 3) {
	xx[5] = (((15 - 1) * 1200 + 1500) / 100 - tmsgy / 100);
	if (xx[5] > 0) {
	    setc0();
	    fillrect(xx[1], xx[2] + tmsgy / 100, 360, xx[5]);
	    setc1();
	    drawrect(xx[1], xx[2] + tmsgy / 100, 360, xx[5]);
	}
    }

}				//ttmsg

void txmsg(string x, int a)
{
    int xx = 6;

    str(x, 60 + xx, 40 + xx + a * 24);

}				//txmsg

//フォント変更
void setfont(int x, int y)
{
    SetFontSize(x);
    SetFontThickness(y);
}

//グラ作成
void eyobi(int xa, int xb, int xc, int xd, int xe, int xf, int xnobia, int xnobib, int xgtype, int xtm)
{
	ea[eco] = xa;
	eb[eco] = xb;
	ec[eco] = xc;
	ed[eco] = xd;
	ee[eco] = xe;
	ef[eco] = xf;
	egtype[eco] = xgtype;
	etm[eco] = xtm;
	enobia[eco] = xnobia;
	enobib[eco] = xnobib;

  eco++;
  if (eco >= emax)
		eco = 0;

} // eyobi

//敵キャラ、アイテム作成
void ayobi(int xa, int xb, int xc, int xd, int xnotm, int xtype, int xxtype)
{
    int rz = 0;
    for (t1 = 0; t1 <= 1; t1++) {
	t1 = 2;
	if (aa[aco] >= -9000 && aa[aco] <= 30000)
	    t1 = 0;
	rz++;

	if (rz <= amax) {
	    t1 = 3;

	    aa[aco] = xa;
	    ab[aco] = xb;	//ag[aco]=0;ah[aco]=0;ai[aco]=bb[t];//ad[t]=0;aeon[t]=1;
	    ac[aco] = xc;
	    ad[aco] = xd;
	    if (xxtype > 100)
		ac[aco] = xxtype;
//ae[aco]=0;af[aco]=0;
	    atype[aco] = xtype;
	    if (xxtype >= 0 && xxtype <= 99100)
		axtype[aco] = xxtype;	//ahp[aco]=iz[bxtype[t]];aytm[aco]=0;
//if (xxtype==1)end();
	    anotm[aco] = xnotm;
	    if (aa[aco] - fx <= ma + mnobia / 2)
		amuki[aco] = 1;
	    if (aa[aco] - fx > ma + mnobia / 2)
		amuki[aco] = 0;
	    if (abrocktm[aco] >= 1)
		amuki[aco] = 1;
	    if (abrocktm[aco] == 20)
		amuki[aco] = 0;

	    anobia[aco] = anx[atype[aco]];
	    anobib[aco] = any[atype[aco]];

//大砲音
	    if (xtype == 7 && CheckSoundMem(oto[10]) == 0) {
		ot(oto[10]);
	    }
//ファイア音
	    if (xtype == 10 && CheckSoundMem(oto[18]) == 0) {
		ot(oto[18]);
	    }

	    azimentype[aco] = 1;

//if (atype[aco]<=30 && atype[aco]!=4)atm[aco]=20;

//azimentype[aco]=1;

	    switch (atype[aco]) {
/*
case 0:case 1:case 2:case 5:case 6:case 7:case 8:
azimentype[aco]=2;
break;

case 3:case 4:
azimentype[aco]=0;
break;

case 49:case 50://case 2:case 5:case 6:
azimentype[aco]=4;
break;

case 80:case 81:case 82:case 83:case 84:case 85:
azimentype[aco]=1;
break;

case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:
azimentype[aco]=1;
break;

case 120:case 121:case 122:
azimentype[aco]=1;
break;

case 130:case 131:case 132:case 133:case 134:
azimentype[aco]=1;
break;
*/
	    }

	    if (xtype == 87) {
		atm[aco] = rand(179) + (-90);
	    }

	    aco += 1;
	    if (aco >= amax - 1) {
		aco = 0;
	    }
	}			//t1

//if (bz[t]==1){bz[t]=0;}
    }				//rz

}				//ayobi
