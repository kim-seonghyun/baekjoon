#include <iostream>
#include <string>

using namespace std;
bool str[100001][100001];
string a;
int max1 =0;
int main(){
    cin >> a;
    for(int i=0; i<a.length(); i++) {
        str[i][i] = true;
    }

    for(int i=0; i<a.length()-1; i++){
        if(a[i] == a[i+1]) {
            str[i][i+1] =true;
        }
    }

    for (int k=2; k<a.length(); k++){
        for(int i=0; i<a.length()-k; i++) {
            int j = i+k;
            if(a[i]==a[j] && str[i+1][j-1] == true) {
                str[i][j] =true;
                max1 = k;
            }
        }
    }
    cout << max1;
}