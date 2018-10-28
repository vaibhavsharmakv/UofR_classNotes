#include<iostream>
#include<math.h>
using namespace std;

struct Rnum {
    int Num;
    int Den;
Rnum(int a, int b) {
    Num = a;
    Den = b;}

};

int converting(int x, int y) {while (y != 0) {
int r = x % y;
    x = y;
    y = r;
    }
            return x;

Rnum Rnumsadd(ratNum r1, ratNum r2) {
    int Num, Den;
    Num = r1.Num * r2.Den + r1.Den * r2.Num;
Den = r1.Den * r2.Den;
int conversion = converting(Num, Den);
Num /= conversion;

    Den /= conversion;
    ratNum r3(Num, Den);

    return r3;
}
void RnumPrint(ratNum r) {

    cout << r.Num << "/" << r.Den << endl;

}
int main() {
int s1, s2;
    cout << "enter first numenator" << endl;
    cin >> s1;
    cout << "enter first denumenator" << endl;
    cin >> s2;
    
int t1,t2;
    
    cout << "enter second numenator" << endl;
    cin >> t1;
    
    cout << "enter second denumenator" << endl;
    cin >> t2;
    ratNum r1(s1, s2);
    ratNum r2(t1, t2);
ratNum r3 = Rnumadd(r1, r2);
RnumPrint(r3);

}
