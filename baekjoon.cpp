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
            if( (j-i+1) < max1 ) //��Ʈ��ŷ? �̶��ؾߵǳ�
                break;
            if(str[i]==str[j]) { //1��°�� n-1������ ������ , 2������ n-2������ ������ ...
                if((j-i+1)%2 == 0) { //¦���̸�
                    int left = i;
                    int right = j;
                    
                    while(true) { //1��°�� n-1��°,2��°�� n-2��° ... �� �ٸ��� break
                        if(str[left] == str[right]) { 
                            sameNum +=2;
                        }
                        else{
                            sameNum=0;
                            break;
                        }
                        left++;
                        right--;

                        if(left>right) { //max���� ��ũ�� ������ ���� ���������� Ž���Ұ��
                            if(max1 <=sameNum) { 
                                max1 = sameNum; //
                            }
                            sameNum = 0;
                            break;
                        }
                    }
                    
                } else { //Ȧ���̸�
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
