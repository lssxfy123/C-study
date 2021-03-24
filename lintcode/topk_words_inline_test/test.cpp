// Copyright(C) 2021 刘珅珅
// Environment: C++
// Date : 2021.3.24
// 最常使用的K个单词II：lintcode 550
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Word {
public:
	Word(int count, string word)
	{
		this->count = count;
		this->word = word;
	}

	int count() const
	{
		return this->count;
	}

	string word() const
	{
		return this->word;
	}
private:
	int count;
	string word;
};

class Compartor {
public:
	bool operator() (Word& word, Word& other_word)
	{
		if (word.count() != other_word.count())
		{
			return word.count() > other_word.count();
		}
		return word.word() < other_word.word();
	}
};

class TopK {
public:
	/*
	* @param k: An integer
	*/
	TopK(int k) {
	    // do intialization if necessary
		this->k = k;
    }

	  /*
	   * @param word: A string
	   * @return: nothing
	   */
	  void add(string &word) {
		  // write your code here
		  
	  }

	  /*
	   * @return: the current top k frequent words.
	   */
	  vector<string> topk() {
		  // write your code here
	  }
private:
	int k;
	unordered_map<string, int> word_freq_;
	priority_queue<Word, vector<Word>, Compartor> data_;
};

int main(int argc, char* argv[])
{
	return 0
}
