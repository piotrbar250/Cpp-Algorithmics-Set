#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
int q;
vector <string> wordp = {"Tad","Sop","Wojski","Teli","Podk","Gerw","Kluc","Roba","Rej","Dobrzy","Moska","Sedzie","Ryko","Ase","Hore","Hrabie","Maciej","Litwie","Zosia","Stoln","Kropi","wten","Rzekl","Scyz","Chrzc","Jace","Protaz","Dabrows","Mack","sej","Jank","jegr","litew","Buc","strzelb","zasci","wlosc","Brzyt","Jack","Maciek","Strzel","Zosie","kwestarz","Kus","ptast","Kone","Soko","Dowe","Krzyk","Ojczy","charty","karabe","konfed","Sak","Zof","bernardyna","rzecze","strzelcy","strzelec","Bart","Myslil","Wiln","grzed","krzykneli","Domey","Hre","Kn","Majorz","Reb","biezy","charto","galk","polowanie","powiec","zajaz","zwad","Lach","Litwa","Skol","duman","kic","klod","muraw","postrze","psiarn","rury","strzech","szczw","wicin","zadziwie","Doby","Ked","Kosciu","Polko","Rozec","Suw","Wten","drazk","klos","kni"};
vector <string> wordq = {"Winic","Lig","Petr","Chil","Nero","cezara","Aul","albow","Urs","Tyge","Pomp","uczyni","Akte","Glau","Popp","pretor","aug","Eun","Anc","Kroto","Grek","Krys","chrzescijanie","Cez","atri","lekt","Ostri","Sene","Palat","Lin","Plau","Apostola","czynil","niewolnicy","Grecy","wyzwole","Zaty","bogowi","igrz","Zali","patryc","Marku","Westy","Nazar","Tars","mniem","chrzescijanine","areni","Chryz","Waty","cezare","cezarowi","tog","wyznawc","Mir","tun","chrzescijana","Jowis","tric","Grecj","arene","centur","zakladn","Miedzi","cub","zaul","Achai","odrzekla","pochodn","Nea","Eury","Tybe","amfiteatrz","wiezieniu","chrze","Kary","Ruf","cezarz","miluj","Ahe","Alba","Luka","lutn","milow","areny","gladiatoro","rozpoz","sest","willi","Uczyn","Via","Witel","dziewice","odnajdz","odnalezc","Scew","przeto","Ag","Barank","Niewo"};
vector <string> wordl = {"Woku","Iza","rubli","Rzeck","Ign","Stach","barono","Staws","Ochoc","Leck","Starsk","Szlan","Waso","Krzesz","prezes","Szuma","Maru","hrabin","Gei","subi","Mra","fot","spolk","Minc","kuz","Flore","procen","Klej","Baro","wted","Suz","Natural","Lisi","klacz","Misi","doroz","Fel","Katz","Wegi","odparla","lalk","licy","Wirs","Ross","space","Helu","kamienice","Ewel","Stanislawi","Zaslaw","kobiete","awant","saloni","1","Wysoc","fizj","radc","stude","gabinet","staruszka","stosunki","Paryzu","kanap","przedp","Hop","Stas","Mik","rezu","arystokrac","galan","wago","Mel","fab","Belu","Mol","Stawk","kupca","kwadran","Kazi","Laz","Patk","herbat","preten","Marian","fak","lokal","pietn","Leon","Ludw","kupu","mezczyzna","spodn","wtracila","baba","diabla","frank","ory","Szpr","adwokata","naturalni"};
vector <string> keyw = {"ab","ad","albow","am","are","au","aze","bar","ber","bia","bieg","bly","bog","bok","bos","bow","brac","bro","ce","cha","chlop","chr","chwila","cial","czarn","czym","czyn","dlat","dod","dum","dusz","dwo","dzied","dzies","gad","gdyz","ge","gos","grz","hr","int","izb","jednak","jesl","jez","klo","kob","kraj","krzy","ksiaz","ksie","ksz","ktoreg","ktorz","kul","kup","kur","las","lew","low","majat","mias","milo","mlodz","modl","mogla","mor","mru","myslal","nast","nau","niedz","nieprz","niew","odez","odn","odpa","odr","ofia","oki","pan","pare","pas","pien","pio","ple","poc","pokoj","polow","pols","pomysla","powia","powoz","powta","poza","pozo","prac","pret","prez","przyje","ps","pt","pusz","robi","rok","rowniez","rub","rus","sal","sas","skl","skrz","slaw","smier","spiew","spol","spost","spytal","sr","stru","strz","suk","swiaty","szepn","szl","szp","szt","traw","troc","twar","twoj","tys","uczy","uda","ujr","wiat","wido","wieks","wiez","wio","wk","wn","woj","wow","wpr","wraz","wre","wsr","wte","wydal","wyzn","zaczal","zaja","zamk","zapy","zaraze","zbo","zbr","zgo","ziel","zob","zrob","zupel","zwa","zycia"};

vector <double> wsp = {0.153,0.0963,0,0.107,0.138,0.0254,0.118,0.192,0.951,0.601,0.611,0.628,0.157,0.728,0.0421,0,0.663,0.678,0.156,0.678,0.655,0.106,0.0914,0.122,0.636,0.148,0.252,0,0.0621,0.749,0.211,0.715,0.81,0.184,0.755,0.0191,0.61,0.652,0.666,0.0501,0.146,0.754,0,0.26,0.255,0.802,0.203,0.619,0.616,0.347,0.605,0.68,0.126,0.0475,0.813,0.148,0.681,0.645,0.602,0.952,0.109,0.11,0.14,0.811,0.0852,0.118,0.219,0.165,0.0115,0.0882,0.153,0.797,0.21,0.213,0.0469,0.0272,0.00943,0.0262,0.0354,0.741,0.217,0.111,0.607,0.136,0.666,0.692,0.151,0.293,0.633,0.794,0.0185,0.785,0.0563,0.104,0.148,0.187,0.229,0.0229,0.0462,0.193,0.654,0.727,0.768,0.255,0.216,0.0445,0.0797,0.685,0.254,0.79,0.23,0.628,0.703,0.126,0.23,0.192,0.0999,0.0103,0.629,0.752,0.761,0.657,0.0956,0.129,0.757,0.762,0.67,0.878,0.17,0.183,0.221,0.173,0.136,0.157,0.326,0.677,0.161,0.169,0.15,0.631,0.695,0.636,0.651,0.0487,0.131,0.0727,0.181,0.0923,0.606,0.0218,0.219,0.35,0.818,0.665,0.103,0.0514,0.69,0.294,0.719,0.709,0.0487,0.313,0.02,0.658,0.0739};
vector <double> wsq = {0.697,0,1,0.713,0.81,0.828,0.0057,0.16,0,0.261,0.161,0.209,0.726,0.135,0.802,0.724,0.219,0.179,0.726,0.118,0.0895,0.835,0.739,0.774,0.143,0.663,0.648,0.749,0.256,0.149,0.607,0.21,0.0501,0.126,0.0311,0.624,0.156,0.108,0.229,0,0.00479,0.203,0.658,0.738,0.11,0.0503,0.177,0.0991,0.264,0.0286,0.16,0.278,0.616,0.634,0.0173,0.0735,0.0672,0.173,0.081,0.0418,0.0158,0.766,0.638,0.057,0.787,0.636,0.616,0.0971,0.257,0.607,0.684,0.123,0.608,0.647,0.0679,0.846,0.0478,0.84,0.705,0.0363,0.0726,0.0537,0.242,0.172,0.146,0.129,0.653,0.087,0.0994,0.0185,0.376,0.159,0.0612,0.656,0.721,0.648,0.11,0.789,0.0502,0.204,0.179,0.135,0.147,0.043,0.0482,0.693,0.00361,0.152,0.0702,0.0245,0.108,0.124,0.174,0.701,0.672,0.0521,0.261,0.365,0.191,0.17,0.11,0.0317,0.857,0.0666,0.112,0.069,0.115,0.0502,0.178,0.6,0.618,0.203,0.79,0.602,0.64,0.224,0.647,0.636,0.747,0.229,0.21,0.217,0.186,0.717,0.665,0.665,0.645,0.789,0.095,0.75,0.698,0.0493,0.0624,0.126,0.276,0.888,0.206,0.654,0.193,0.108,0.335,0.0618,0.602,0.252,0.643};
vector <double> wsl = {0.151,0.904,0,0.181,0.0513,0.147,0.876,0.648,0.0493,0.138,0.228,0.163,0.117,0.137,0.156,0.276,0.118,0.143,0.118,0.204,0.255,0.0585,0.169,0.104,0.222,0.19,0.1,0.251,0.682,0.102,0.182,0.0751,0.14,0.69,0.214,0.357,0.234,0.24,0.105,0.95,0.85,0.0431,0.342,0.00222,0.635,0.147,0.62,0.282,0.12,0.624,0.235,0.0426,0.258,0.319,0.17,0.779,0.252,0.182,0.317,0.00641,0.875,0.124,0.222,0.132,0.128,0.246,0.165,0.738,0.731,0.305,0.163,0.0797,0.182,0.14,0.885,0.127,0.943,0.134,0.26,0.223,0.71,0.835,0.151,0.692,0.188,0.179,0.196,0.62,0.267,0.188,0.605,0.0564,0.882,0.24,0.132,0.166,0.661,0.188,0.904,0.603,0.167,0.138,0.0853,0.702,0.736,0.262,0.917,0.163,0.676,0.186,0.662,0.248,0.123,0.173,0.0982,0.756,0.639,0.625,0.18,0.0783,0.129,0.311,0.0478,0.805,0.131,0.169,0.215,0.0719,0.652,0.217,0.161,0.624,0.074,0.241,0.0341,0.0989,0.192,0.195,0.103,0.14,0.0956,0.147,0.163,0.234,0.204,0.262,0.174,0.119,0.299,0.228,0.0827,0.601,0.12,0.209,0.622,0.0609,0.104,0.0523,0.0881,0.183,0.616,0.625,0.378,0.0903,0.283};

map <string, double> mpr[4];

vector <string> words;
set <string> input;
map <string,int> dia;
int ac[M];

void res(int n)
{
    if(n==1)
        cout<<"Mickiewicz"<<endl;
    if(n==2)
        cout<<"Sienkiewicz"<<endl;
    if(n==3)
        cout<<"Prus"<<endl;
}

void select_pref(string &s)
{
    string cs = "";
    int idp = 0;
    for(int i=0; i<s.size(); i++)
    {
        int var = (int)(s[i]);
        if((var >= 97 && var <= 122) || (var >= 65 && var <= 90) || (var >= 48 && var <= 57)) 
        {
            cs += s[i];
            input.insert(cs);
        }
        else if(var == 63 || var == 59 || var == 58 || var  == 45 || var == 44 || var == 40 || var == 41 || var == 33)
        {
            string pom = "";
            pom += s[i];
            if(dia.find(pom) == dia.end())
                dia[pom] = ++idp;
            ac[dia[pom]]++;
        }
        else
        {
            words.push_back(cs);
            cs = "";
        }
    }
}

int main()
{
    for(auto q: wordp)
        mpr[1][q] = -1;
      
    for(auto q: wordq)
        mpr[2][q] = -1;

    for(auto q: wordl)
        mpr[3][q] = -1;

    for(int i=0; i<keyw.size(); i++)
    {
        string q = keyw[i];
        if(mpr[1].find(q) != mpr[1].end() || mpr[2].find(q) != mpr[2].end() || mpr[3].find(q) != mpr[3].end())
            continue;
        mpr[1][q] = wsp[i]; 
        mpr[2][q] = wsq[i];
        mpr[3][q] = wsl[i];
    }
    string qu;
    getline(cin,qu);
    q = atoi(qu.c_str());
    for(int i=1; i<=q; i++)
    {
        input.clear();
        string s = "";
        bool found = false;
        double t = 0, q = 0, l = 0;
        getline(cin,s);
        select_pref(s);
        for(auto it = input.begin(); it != input.end(); it++)
        {
            string w = *it;
            if(mpr[1].find(w) != mpr[1].end())
            {
                if(mpr[1][w] == -1)
                {
                    res(1);
                    found = true;
                    break;
                }
                t += mpr[1][w];
            }
            if(mpr[2].find(w) != mpr[2].end())
            {
                if(mpr[2][w] == -1)
                {
                    res(2);
                    found = true;
                    break;
                }
                q += mpr[2][w];
            }
            if(mpr[3].find(w) != mpr[3].end())
            {
                if(mpr[3][w] == -1)
                {
                    res(3);
                    found = true;
                    break;
                }
                l += mpr[3][w];
            }
        } 
        if(found == true)
            continue;
        double maks = max(t,max(q,l));
        if(maks == 0)
        {
            srand(time(0));
            int p = rand() % 2 + 1;
            if(p == 1)
                res(1);
            if(p == 2)
                res(2);
            if(p == 3)
                res(3);
        }
        
        else if(maks == t)
            res(1);
        else if(maks == q)
            res(2);
        else if(maks == l)
            res(3);
    }
}