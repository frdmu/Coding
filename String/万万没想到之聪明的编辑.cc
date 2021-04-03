// https://www.nowcoder.com/test/question/42852fd7045c442192fa89404ab42e92?pid=16516564&tid=42864963
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string str;
    cin >> n;
    while (n-- > 0) {
        cin >> str;
        
        for(int i = 0; i < str.size(); i++) {
            while(i+2 < str.size() && str[i] == str[i+1] && str[i] == str[i+2]) {
                str.erase(str.begin()+i+2);
            }
            while(i+3 < str.size() && str[i] == str[i+1] && str[i+1] != str[i+2] && str[i+2] == str[i+3]) {
                str.erase(str.begin()+i+3);
            }
        }
        
        cout << str << endl;
    }
    return 0;
}