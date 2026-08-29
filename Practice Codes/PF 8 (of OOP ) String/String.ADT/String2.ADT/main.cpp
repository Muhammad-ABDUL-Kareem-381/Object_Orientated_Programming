#include "String.h"
int main()
{
	int a = 9;
	(++a)++;
	cout << a;
	return 0;
	String s;
	s.input();
	s.display();
}

// prob 1 use strsize in at() instead of strLen to set values of characters at null or higher index

// why I can't input directly in data[i] character by character instead of taking input in char temp and then storing it in our String in input()??

/* At some places we had String* subStr in parameter ie. a pointer to String.Then to the sentence, "Use const everywhere you can use it." we could use
const String * substr as an argument ie we could make the pointer constant like this. We also could make this pointer more noble by making it 
const String * const subStr. So we had these options then why we use alias method like const String & subStr in parameter? Any special reason?
I'm not confident .Maybe its answer is that: no doubt we could achieve the same behaviour of constness of parameter using above told pointers (const String * and const String * const ) 
but pointer will take 8 bytes in memory and alias will not take any byte. So preserve memory and use it. And be happy.

One more reason to use alias method is that if const alias is used (jo k hm hr alias ki jaga const alias hi use kr rhy hein) then i can pass an object of String , 
also can pass String in forms like "abc" , "" . and as a result a nameless obj of String will be created whose alias is received as argument.
but in case of pointer i cannot pass String in form like &"abc" etc. to use it i will have to create an object first then i can use it in such case.
*/