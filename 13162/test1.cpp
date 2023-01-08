#include <iostream>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

int T,L,R,LI,DN,n;
int ans;
queue<int> S[15];
string str;

int main(void)
{
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> L >> R;
        for (int j = 0; j < R; j++) {
            cin >> LI;
            while (1) {
                str = getchar();
                if (str == "\n") break;
                if (str != " ") {
                    DN = stoi(str);
                    S[LI].push(DN);  
                        
                }
            }
        }
        for (int j = 0; j < L; j++) {
            while (S[j].size() > 0) {
                if ((L - j - 1) == 0) {
                    ans = ans + S[j].front();
                }
                else {
                    ans = ans +( (S[j].front())*pow(10, (L - j - 1)) ) ;
                }
                S[j].pop();
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
