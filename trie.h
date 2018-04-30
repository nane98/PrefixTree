
struct Node
{
    char key;
    vector<Node*> kids;  
    bool isWordEnd;  
    Node():key(){}
    Node(char key, bool isWordEnd):key(key)
    {
 	if(this->isWordEnd != true)
	{
            this->isWordEnd = isWordEnd;
	}
    }
    ~Node(){}

    void makeTrue()
    {
        this->isWordEnd = true;
    }
    std::pair<Node*, bool> addKid(char key, bool isWordEnd)
    {
        Node* temp = new Node(key, isWordEnd);
        kids.push_back(temp);
	return std::make_pair(temp, true);
    }
    std::pair<Node*, bool> hasKid(char key)
    {
        int i = 0;
        for(i = 0; i < kids.size(); ++i)
        {
            if(kids[i]->key == key)
            {
                return std::make_pair(kids[i], true);
            }
        }
        return std::make_pair(nullptr, false);
    }
};
class Trie
{
public:
    Trie()
    {
        root = new Node;
	//std::cout << "root made\n";
    }
    bool addWord(std::__cxx11::string word)
    {
        size_t i = 0;
        Node* temp = new Node;
        temp = root;
	std::pair<Node*, bool> current;
	while(i<word.length())
        {
	  //  std::cout << "letter: " << word[i] << std::endl; 
	    current  = temp->hasKid(word[i]);
            if(current.second == false)
            {
                if(i < word.length()-1)
                {
                    current = temp->addKid(word[i], false);
		   // std::cout << "add " << word[i] << "\n";
                }
                else
                {
                    current = temp->addKid(word[i], true);
                 //   std::cout << "add " << word[i] << "\n";
		}
            }
	    

	   // std::cout << "temp.key: " << temp->key << std::endl;
	   // std::cout << "current.f, s: " << current.first << " "  << current.second << std::endl; 
            temp = current.first;
	  //  std::cout << "temp.key: " << temp->key << std::endl;
            ++i;
	   // std::cout << "incremant i\n";
        }
	temp->makeTrue();
        return true;
    }
    std::pair<Node*, bool> find(std::__cxx11::string word)
    {
        size_t i = 0;
        Node* temp = new Node;
        temp = root;
	std::pair<Node*, bool> current;
        while(i < word.length())
        {
            current = temp->hasKid(word[i]);
	   // std::cout << "current: " << current.first->key << " " << current.second << std::endl;
            if(current.second == false)
            {
                return std::make_pair(nullptr, false);
            }
            temp = current.first;
	    ++i;
	   // std::cout << "temp: " << temp->key << std::endl;
        }
        return std::make_pair(temp, true);
    }
    bool isWord(std::__cxx11::string word)
    {
	std::pair<Node*, bool> temp = find(word);
	//std::cout << temp.first->key << " " << temp.first->isWordEnd << std::endl;
	if(temp.second == true)
	{
	    if(temp.first->isWordEnd == true)
	    {
		return true;
	    }
	}
	return false;
    }

private:
    Node* root;
};








