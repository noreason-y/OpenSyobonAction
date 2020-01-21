#ifndef MAIN_H
#define MAIN_H
#include "DxLib.h"
using namespace std;

#define SHORT

void loadg();
void parseArgs(int argc, char* argv[]);

//String 使用

//プログラム中
//main-10
//タイトル-100

//: This is unexcusable. How could someone in their right mind define
//: a variable called 'main'!?
//: The new define is after the main method
extern int mainZ, maintm ;

//ステージ
extern int stagecolor;
extern int sta, stb, stc;

//クイック
extern int fast;

//トラップ表示
extern int trap;

//中間ゲート
extern int tyuukan;


//スタッフロール
extern int ending;


//ステージ読み込みループ(いじらない)
extern int stagerr, stagepoint;
//オーバーフローさせる
extern int over;

//ステージスイッチ
extern int stageonoff;


//メインプログラム
void Mainprogram();
void rpaint();
extern int maint;


//サブクラス
//(ウエイト系
#define wait(i) SDL_Delay(i)
void wait2(long stime, long etime, int FLAME_TIME);
int rand(int Rand);
// #define end() exit(0)

//描画
extern Uint32 color;
extern Uint32 gfxcolor;
void setfont(int a);
void setcolor(int red, int green, int blue);
void setc0();
void setc1();
void drawpixel(int a, int b);
void drawline(int a, int b, int c, int d);
void drawrect(int a, int b, int c, int d);
void fillrect(int a, int b, int c, int d);
void drawarc(int a, int b, int c, int d);
void fillarc(int a, int b, int c, int d);
void FillScreen();
extern SDL_Surface *grap[161][8];
extern SDL_Surface *mgrap[51];
SDL_Surface *loadimage(string b);
SDL_Surface *loadimage(int a, int x, int y, int r, int z);
extern int mirror;
void drawimage(SDL_Surface * mx, int a, int b);
void drawimage(SDL_Surface * mx, int a, int b, int c, int d, int e, int f);
void setre();
void setre2();
void setno();
extern Mix_Music *otom[6];
extern Mix_Chunk *oto[19];
void ot(Mix_Chunk * x);
void bgmchange(Mix_Music * x);

//文字
void str(string c, int a, int b);


//)

void stagecls();
void stage();
void stagep();





//1-ステージ
//10-ステージ前
//



//ループ
extern int t, tt, t1, t2, t3, t4;


//初期化
extern int zxon, zzxon;

//キーコンフィグ
extern int key, keytm;

//三角関数
extern double pai;


//地面
#define smax 31
extern int sx, sco;
extern int sa[smax], sb[smax], sc[smax], sd[smax], stype[smax], sxtype[smax],
    sr[smax];
extern int sgtype[smax];



//プレイヤー
extern int mainmsgtype;
extern int ma, mb, mnobia, mnobib, mhp;
extern int mc, md, macttype, atkon, atktm, mactsok, msstar, nokori, mactp, mact;

extern int mtype, mxtype, mtm, mzz;
extern int mzimen, mrzimen, mkasok, mmuki, mmukitm, mjumptm, mkeytm, mcleartm;
extern int mmutekitm, mmutekion;
extern int mztm, mztype;
extern int actaon[7];
//メッセージ
extern int mmsgtm, mmsgtype;

extern int mascrollmax;	//9000




//ブロック
void tyobi(int x, int y, int type);
void brockbreak(int t);
#define tmax 641
extern int tco;
extern int ta[tmax], tb[tmax], tc[tmax], td[tmax], thp[tmax], ttype[tmax];
extern int titem[tmax], txtype[tmax];

//メッセージブロック
extern int tmsgtm, tmsgtype, tmsgx, tmsgy, tmsgnobix, tmsgnobiy, tmsg;
void ttmsg();
void txmsg(string x, int a);
void setfont(int x, int y);

//効果を持たないグラ
void eyobi(int xa, int xb, int xc, int xd, int xe, int xf, int xnobia,
	   int xnobib, int xgtype, int xtm);
#define emax 201
extern int eco;
extern int ea[emax], eb[emax], enobia[emax], enobib[emax], ec[emax], ed[emax];
extern int ee[emax], ef[emax], etm[emax];
extern int egtype[emax];



//敵キャラ
void ayobi(int xa, int xb, int xc, int xd, int xnotm, int xtype,
	   int xxtype);
void tekizimen();
#define amax 24
extern int aco;
extern int aa[amax], ab[amax], anobia[amax], anobib[amax], ac[amax], ad[amax];
extern int ae[amax], af[amax], abrocktm[amax];
extern int aacta[amax], aactb[amax], azimentype[amax], axzimen[amax];
extern int atype[amax], axtype[amax], amuki[amax], ahp[amax];
extern int anotm[amax], anx[160], any[160];
extern int atm[amax], a2tm[amax];
extern int amsgtm[amax], amsgtype[amax];

//敵出現
#define bmax 81
extern int bco;
extern int ba[bmax], bb[bmax], btm[bmax];
extern int btype[bmax], bxtype[bmax], bz[bmax];


//背景
#define nmax 41
extern int nxxmax, nco;
extern int na[nmax], nb[nmax], nc[nmax], nd[nmax], ntype[nmax];
extern int ne[nmax], nf[nmax], ng[nmax], nx[nmax];


//リフト
#define srmax 21
extern int srco;
extern int sra[srmax], srb[srmax], src[srmax], srd[srmax], sre[srmax], srf[srmax];
extern int srtype[srmax], srgtype[srmax], sracttype[srmax], srsp[srmax];
extern int srmuki[srmax], sron[srmax], sree[srmax];
extern int srsok[srmax], srmovep[srmax], srmove[srmax];





//スクロール範囲
extern int fx, fy, fzx, fzy, scrollx, scrolly;
//全体のポイント

//: "fma" already exists, so call it something else and add a define
extern int fmaZ , fmb;
#define fma fmaZ

//強制スクロール
extern int kscroll;
//画面サイズ(ファミコンサイズ×2)(256-224)
extern int fxmax, fymax;



//ステージ
extern byte stagedate[17][2001];

//画面黒
extern int blacktm, blackx;



//自由な値
extern int xx[91];
extern double xd[11];
extern string xs[31];


//タイマー測定
//: Do with this what we did with fma
extern long stimeZ;
#define stime stimeZ


#endif // GAME_PLAY_H