#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    char s[8][9], ch;
    char so[8][9];
    unsigned short sh_dat[64], sd2[64], r, w;
    char st[9];
    ifstream ifs("in.txt");
    if (!ifs) {
        cout << "File in.txt not open" << endl; return -1;
    }
    ofstream ofs("out.txt");
    ofstream ofsb("outb.txt", ios::out | ios::binary);
    unsigned short i, j, l, b, k, t;
    for (i = 0; i < 8; i++)
    {
        ifs.get(s[i], 9, '\0'); ifs.get(ch);
    }
    j = 0;
    for (i = 0; i < 8; i++)
        for (l = 0; l < 8; l++)
        {
            r = i; 
            w = l << 2;
            r |= w; 
            b = 0; t = 1;
            for (k = 0; k < 6; k++) 
                
            {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            w = 1 << 6;
            if (b) r |= w; 
            w = s[i][l];
            w <<= 7;
            r |= w;
            if (r & 0x4000) r |= 0x8000;
            sh_dat[j] = r;
            j++;
            ofs << hex << r << ' ';
            cout << hex << r << endl;
        }
    ofsb.write((char*)sh_dat, 64 * sizeof(unsigned short));
    ofsb.close();
    ifs.close();
    ifs.open("outb.txt", ios::in | ios::binary);
    ifs.read((char*)sd2, 64 * sizeof(unsigned short));
    short indi, indj;
    for (i = 0; i < 64; i++)
    {
        r = sd2[i];
        indj = r & 0x0038;
        indj >>= 3; 
        indi = r & 0x0007; 
        w = r & 0x7f80; 
        w >>= 7;
        ch = w;
        so[indi][indj] = ch;
    }
    for (i = 0; i < 8; i++) {
        for (l = 0; l < 8; l++)
            cout << so[i][l];
        cout << endl;
    }
    return 0;
}
