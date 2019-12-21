#include<sstream>


//1. String line input:
string s;
getline(cin,s);

char s[100];
cin.getline(s,sizeof(s));




//2. Breaking a string into words:
stringstream ss(s);
string word;
while(ss>>word)
    cout<<word<<" "<<endl;




//3. Tokenize a string using a delimitter:
string s="what-ever-lol";
stringstream ss(s);
string token;
while(getline(ss,token,'-'))
    cout<<token;




//4. Convert string to int from input:
string input="12 23 45";
int x,y;
stringstream sss(input);
sss>>x;
sss>>y;

//OR

//convert first occurence of a number:
int n = stoi(string);
int n = atoi(char*);




//5. Covert string to int:
string s = to_string(int);
//OR
stringstream ss;
int x=123;
string s;
ss<<x;
ss>>s;




//6. Convert string to (const char*):
string.c_str();

//7. Convert string to char*:
char* c = &*string.begin();

//8. char* to string:
string s(char*);




//9. String comparison:
//for char*:
strcmp(char* , char*)

//for string:
if(str1 == str2)




//10. Check number and alphabets:
isalpha(char);
isdigit(char);




//11. find() in a string:
string s="ancd1234";
cout<<s.find('a');          //returns index of first occurence of 'a'

if(s.find('z')== -1)        //returns -1 if not found
    cout<<"not found";

cout<<s.find("cd");
