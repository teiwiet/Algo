#include<iostream>


bool isPalindrome(std::string s){
    std::string s2 = "";
    for(int i = 0;i<s.length();i++){
        if(std::isalnum(s[i])){
            s2+=std::tolower(s[i]);
        }
    }
    int l = 0;
    int r = s2.length()-1;
    return true;
}

bool PalindromeCheck(std::string s,int start,int end){
    if (start>=end){
        return true;
    }
    return (s[start]==s[end]) && PalindromeCheck(s,start+1,end-1);
}


int main(){
    std::string s = "1";
    std::cout << PalindromeCheck(s, 0, s.length()-1);
}
