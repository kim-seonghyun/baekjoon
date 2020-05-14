#include <iostream>
#include <string>
using namespace std;


string str;
int max1 =0;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int sameNum =0;
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        for(int j=str.length()-1; j-i>0; j--) {
            if( (j-i+1) < max1 ) //백트래킹? 이라해야되나
                break;
            if(str[i]==str[j]) { //1번째와 n-1번쨰가 같으면 , 2번쨰와 n-2번쨰가 같으면 ...
                if((j-i+1)%2 == 0) { //짝수이면
                    int left = i;
                    int right = j;
                    
                    while(true) { //1번째와 n-1번째,2번째와 n-2번째 ... 가 다르면 break
                        if(str[left] == str[right]) { 
                            sameNum +=2;
                        }
                        else{
                            sameNum=0;
                            break;
                        }
                        left++;
                        right--;

                        if(left>right) { //max값이 더크고 마지막 까지 성공적으로 탐색할경우
                            if(max1 <=sameNum) { 
                                max1 = sameNum; //
                            }
                            sameNum = 0;
                            break;
                        }
                    }
                    
                } else { //홀수이면
                int left = i;
                int right = j;

                while(true) {
                    if(left==right) {
                        sameNum +=1;
                        if(max1 <= sameNum) {
                            max1 = sameNum;
                            sameNum = 0;
                            break;
                        }
                    }
                    if(str[left]==str[right]){
                        sameNum +=2;
                    } else {
                        sameNum =0;
                        break;
                    }
                    left++;
                    right--;
                } 
                }
            }
        }
    }
  if(max1 ==0) {
      cout <<1 << endl;
  } else {
      cout << max1 << endl;
  }
}
