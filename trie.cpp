#include <iostream>
using namespace std;
#include <utility>
#include <memory>
#include <vector>
#include "trie.h"
int main()
{
    Trie obj;
    obj.addWord("hello");
    obj.addWord("world");
    obj.addWord("hell");
    Trie* ob2 = new Trie;
    ob2 = &obj;
    string str;
    int ans = 1;
    while(ans)
    {
	std::cout << "continue: ";
	std::cin >> ans;
	if(ans == 1)
	{
	    std::cout << "string: ";
	    std::cin >> str;
	}
	if(obj.isWord(str))
	{
    	    std::cout << "obj has " << str << std::endl;
	}
	if(ob2->isWord(str))
	{
	    std::cout << "ob2 has " << str << std::endl;
	}
    }    
return 0; 
}
