
// CPP program to find longest common prefix 
// after rotation of second string. 
#include <bits/stdc++.h> 
using namespace std; 
  
// function for KMP search 
void KMP(int m, int n, string str2, string str1) 
{ 
    int pos = 0, len = 0; 
  
    // preprocessing of longest proper prefix 
    int p[m + 1]; 
    int k = 0; 
    p[1] = 0; 
  
    for (int i = 2; i <= n; i++) { 
        while (k > 0 && str1[k] != str1[i - 1]) 
            k = p[k]; 
        if (str1[k] == str1[i - 1]) 
            ++k; 
        p[i] = k; 
    } 
  
    // find out the longest prefix and position 
    for (int j = 0, i = 0; i < m; i++) { 
        while (j > 0 && str1[j] != str2[i]) 
            j = p[j]; 
        if (str1[j] == str2[i]) 
            j++; 
  
        // for new position with longer prefix in str2 
        // update pos and len 
        if (j > len) { 
            len = j; 
            pos = i - j + 1; 
        } 
    } 
  
    // print result 
    cout << "Shift = " << pos << endl; 
    cout << "Prefix = " << str1.substr(0, len); 
} 
  
// driver function 
int main() 
{ 
    string str1 = "geeksforgeeks"; 
    string str2 = "forgeeksgeeks"; 
    int n = str1.size(); 
    str2 = str2 + str2; 
    KMP(2 * n, n, str2, str1); 
    return 0; 
} 
