#include <bits/stdc++.h>
using namespace std;

int HexToDec(char input){
	int k;
	if(isalpha(input)){
		k=10+input-'A';
	}
	else{
		k=input-'0';
	}
	return k;
}

vector<int> HexToBin(string keyHex) { // hex to bin
	vector<int> res;
	int lookUp[16][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
	
	for(int i = 0; i < keyHex.length(); i++) {
		int idx;
		
		if(isalpha(keyHex[i])) 
			idx = keyHex[i] - 'A' + 10;
		else
			idx = keyHex[i] - '0';
			
		for(int j = 0; j < 4; j++) 
			res.push_back(lookUp[idx][j]);
	}
	return res;
}

string BinToHex(vector<int> word){ // bin to hex
	string res = "";
	int temp = 0;
	string ref[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	for(int i = 0;i < word.size(); i += 4){
		temp = 0;
		for(int j = 0; j < 4; j++){
			temp += (pow(2, 3-j) * word[i + j]);
		}
		res += ref[temp];
	}
	return res;
}

string rotWord(string a) {
	char temp = a[0];
	for(int i = 1; i < a.length(); i++) 
		a[i - 1] = a[i];
	a[a.length() - 1] = temp;
		
	temp = a[0];
	for(int i = 1; i < a.length(); i++) 
		a[i - 1] = a[i];
	a[a.length() - 1] = temp;
		
	return a;
}

string subWord(string a) {
	char table[16][16][2]={
        { {'6','3'}, {'7','C'}, {'7','7'}, {'7','B'}, {'F','2'}, {'6','B'}, {'6','F'}, {'C','5'},{'3','0'}, {'0','1'}, {'6','7'}, {'2','B'}, {'F','E'}, {'D','7'}, {'A','B'}, {'7','6'} },
        { {'C','A'}, {'8','2'}, {'C','9'}, {'7','D'}, {'F','A'}, {'5','9'}, {'4','7'}, {'F','0'}, {'A','D'}, {'D','4'}, {'A','2'}, {'A','F'}, {'9','C'}, {'A','4'}, {'7','2'}, {'C','0'} },
        { {'B','7'}, {'F','D'}, {'9','3'}, {'2','6'}, {'3','6'}, {'3','F'}, {'F','7'}, {'C','C'}, {'3','4'}, {'A','5'}, {'E','5'}, {'F','1'}, {'7','1'}, {'D','8'}, {'3','1'}, {'1','5'} },
		{ {'0','4'}, {'C','7'}, {'2','3'}, {'C','3'}, {'1','8'}, {'9','6'}, {'0','5'}, {'9','A'}, {'0','7'}, {'1','2'}, {'8','0'}, {'E','2'}, {'E','B'}, {'2','7'}, {'B','2'}, {'7','5'} },
		{ {'0','9'}, {'8','3'}, {'2','C'}, {'1','A'}, {'1','B'}, {'6','E'}, {'5','A'}, {'A','0'}, {'6','3'}, {'3','B'}, {'D','6'}, {'B','3'}, {'2','9'}, {'E','3'}, {'2','F'}, {'8','4'} },
		{ {'5','3'}, {'D','1'}, {'0','0'}, {'E','D'}, {'2','0'}, {'F','C'}, {'B','1'}, {'5','B'}, {'6','A'}, {'C','B'}, {'B','E'}, {'3','9'}, {'4','A'}, {'4','C'}, {'5','8'}, {'C','F'} },
		{ {'D','0'}, {'E','F'}, {'A','A'}, {'F','B'}, {'4','3'}, {'4','D'}, {'3','3'}, {'8','5'}, {'4','5'}, {'F','9'}, {'0','2'}, {'7','F'}, {'5','0'}, {'3','C'}, {'9','F'}, {'A','8'} },
		{ {'5','1'}, {'A','3'}, {'4','0'}, {'8','F'}, {'9','2'}, {'9','D'}, {'3','8'}, {'F','5'}, {'B','C'}, {'B','6'}, {'D','A'}, {'2','1'}, {'1','0'}, {'F','F'}, {'F','3'}, {'D','2'} },
		{ {'C','D'}, {'0','C'}, {'1','3'}, {'E','C'}, {'5','F'}, {'9','7'}, {'4','4'}, {'1','7'}, {'C','4'}, {'A','7'}, {'7','E'}, {'3','D'}, {'6','4'}, {'5','D'}, {'1','9'}, {'7','3'} },
		{ {'6','0'}, {'8','1'}, {'4','F'}, {'D','C'}, {'2','2'}, {'2','A'}, {'9','0'}, {'8','8'}, {'4','6'}, {'E','E'}, {'B','8'}, {'1','4'}, {'D','E'}, {'5','E'}, {'0','B'}, {'D','B'} },
		{ {'E','0'}, {'3','2'}, {'3','A'}, {'0','A'}, {'4','9'}, {'0','6'}, {'2','4'}, {'5','C'}, {'C','2'}, {'D','3'}, {'A','C'}, {'6','2'}, {'9','1'}, {'9','5'}, {'E','4'}, {'7','9'} },
		{ {'E','7'}, {'C','8'}, {'3','7'}, {'6','D'}, {'8','D'}, {'D','5'}, {'4','E'}, {'A','9'}, {'6','C'}, {'5','6'}, {'F','4'}, {'E','A'}, {'6','5'}, {'7','A'}, {'A','E'}, {'0','8'} },
		{ {'B','A'}, {'7','8'}, {'2','5'}, {'2','E'}, {'1','C'}, {'A','6'}, {'B','4'}, {'C','6'}, {'E','8'}, {'D','D'}, {'7','4'}, {'1','F'}, {'4','B'}, {'B','D'}, {'8','B'}, {'8','A'} },
		{ {'7','0'}, {'3','E'}, {'B','5'}, {'6','6'}, {'4','8'}, {'0','3'}, {'F','6'}, {'0','E'}, {'6','1'}, {'3','5'}, {'5','7'}, {'B','9'}, {'8','6'}, {'C','1'}, {'1','D'}, {'9','E'} },
		{ {'E','1'}, {'F','8'}, {'9','8'}, {'1','1'}, {'6','9'}, {'D','9'}, {'8','E'}, {'9','4'}, {'9','B'}, {'1','E'}, {'8','7'}, {'E','9'}, {'C','E'}, {'5','5'}, {'2','8'}, {'D','F'} },
		{ {'8','C'}, {'A','1'}, {'8','9'}, {'0','D'}, {'B','F'}, {'E','6'}, {'4','2'}, {'6','8'}, {'4','1'}, {'9','9'}, {'2','D'}, {'0','F'}, {'B','0'}, {'5','4'}, {'B','B'}, {'1','6'} },
    };
    
    for(int i = 0; i < a.length(); i += 2) {
    	char rowHex = a[i];
    	char colHex = a[i + 1];
    	
    	int row = HexToDec(rowHex);
    	int col = HexToDec(colHex);
    	
    	char p = table[row][col][0];
    	char q = table[row][col][1];
    	
    	a[i] = p;
    	a[i + 1] = q;
    }
    
    return a;
}

string XoR(string a, string b) {
	vector<int> a8 = HexToBin(a);
	vector<int> b8 = HexToBin(b);
	
	vector<int> res8;
	for(int i = 0; i < a8.size(); i++) {
		int res = (a8[i] == b8[i] ? 0 : 1);
		res8.push_back(res);
	}
	
	string resFinal = BinToHex(res8);
	return resFinal;
}

void AESKeyExpansion(string key) {

	string RCon[10] = {
		{'0','1','0','0','0','0','0','0','\0'},
		{'0','2','0','0','0','0','0','0','\0'},
		{'0','4','0','0','0','0','0','0','\0'},
		{'0','8','0','0','0','0','0','0','\0'},
		{'1','0','0','0','0','0','0','0','\0'},
		{'2','0','0','0','0','0','0','0','\0'},
		{'4','0','0','0','0','0','0','0','\0'},
		{'8','0','0','0','0','0','0','0','\0'},
		{'1','B','0','0','0','0','0','0','\0'},
		{'3','6','0','0','0','0','0','0','\0'},
	};
	
	
	string words[11][4];
	
	
	int count = 0;
	for(int i = 0;  i < 4; i++) {
		for(int j = 0;  j < 8; j++) {
			words[0][i] += key[count++];
		}
	}
	
	//cout << words[0][0] << words[0][1] << words[0][2] << words[0][3] << endl; 
	
	for(int i = 1; i < 11; i++) {
		for(int j = 0; j < 4; j++) {
			if(j != 0) {
				words[i][j] = XoR(words[i][j - 1], words[i - 1][j]);
			}
			else {
				string op1 = subWord(rotWord(words[i - 1][3]));
				string op2 = RCon[i - 1];
				string t = XoR(op1, op2);
				
				words[i][j] = XoR(t, words[i - 1][j]);
			}
		
			cout << words[i][j] << " ";	
		}
		
		cout << endl; 
	}
}

int main() {
	string initialKeyHex32;
	cout << "Enter the 128-bit Cipher key in Hex: ";
	cin >> initialKeyHex32;
	
	AESKeyExpansion(initialKeyHex32);
			
	cout << endl;
	return 0;
}

