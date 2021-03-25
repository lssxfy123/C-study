// Copyright(C) 2021 ���|�|
// Environment: C++
// Date : 2021.3.24
// �ʹ�õ�K������II��lintcode 550
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Word {
public:
	Word(int count, string word)
	{
		this->count_ = count;
		this->word_ = word;
	}

	int count()  const
	{
		return this->count_;
	}

	string word() const
	{
		return this->word_;
	}

	// �Ƚ�set��������Ƿ���ȣ��������������"<"��Ҳ����ʹ�ñȽ�������Compartor
	//bool operator < (const Word& other_word) const
	//{
	//	if (count_ != other_word.count())
	//	{
	//		return count_ > other_word.count();
	//	}
	//	return word_ < other_word.word();
	//}
private:
	int count_;
	string word_;
};

class Compartor {
public:
	bool operator() (const Word& word, const Word& other_word) const
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
		  // tmp�����������ж��Ƿ�����ͬ��Word������set�У����ܲ��뵽set��
		  Word tmp(word_freq_[word], word);
		  word_freq_[word]++;
		  auto itor = data_.find(tmp);

		  // �������ͬ��Ԫ�ش��ھ���ɾ���ٲ���
		  // set�޷�ֱ���޸�
		  if (itor != data_.end())
		  {
			  data_.erase(itor);
		  }
		  // ����set�е�Word����Ҫ������Ƶ�ʺ�
		  data_.insert(Word(word_freq_[word], word));

		  // ɾ��ʹ��Ƶ����͵�Ԫ��
		  if (data_.size() > k)
		  {
			  data_.erase(--data_.end());
		  }
	  }

	  /*
	   * @return: the current top k frequent words.
	   */
	  vector<string> topk() {
		  // write your code here
		  vector<string> k_top_words;
		  for (set<Word, Compartor>::iterator itor = data_.begin(); itor != data_.end(); ++itor)
		  {
			  k_top_words.push_back(itor->word());
		  }
		  return k_top_words;
	  }
private:
	int k;
	unordered_map<string, int> word_freq_;
	// C++��set��map��������ģ��ײ��Ǻ������������logn��ʱ�临�Ӷ��ڲ���ɾ������
	set<Word, Compartor> data_;
};

int main(int argc, char* argv[])
{
	TopK top_k(2);
	string s1 = "lint";
	top_k.add(s1);
	string s2 = "code";
	top_k.add(s2);
	top_k.add(s2);
	auto result = top_k.topk();
	for (auto s : result)
	{
		cout << s << endl;
	}
	return 0;
}
