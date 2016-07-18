// Copyright 2016.刘珅珅
// author：刘珅珅
// map容器的测试
// 说明：从几万个英语单词中查找那些只通过替换一个字母
// 就可以得到15个以上不同单词的单词。

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void PrintHighChangeableWords(const map<string, vector<string> >& adacent_words,
    int min_words = 15)
{
    map<string, vector<string> >::const_iterator iter;
    for (iter = adacent_words.begin(); iter != adacent_words.end(); ++iter)
    {
        const pair<string, vector<string> >& entry = *iter;
        const vector<string>& words = entry.second;

        if (words.size() >= min_words)
        {
            cout << entry.first << " (" << words.size() << ") :";
            for (int i = 0; i < words.size(); ++i)
            {
                cout << " " << words[i];
            }
            cout << endl;
        }
    }
}

// 输入为单词表
map<string, vector<string> > ComputeAdjacentWords(const vector<string>& words)
{
    map<string, vector<string> > adjacent_words;
    map<int, vector<string> > words_by_length;

    // 按照单词的长度进行分组
    for (int i = 0; i < words.size(); ++i)
    {
        words_by_length[words[i].length()].push_back(words[i]);
    }

    for (map<int, vector<string> > ::const_iterator iter = words_by_length.begin();
        iter != words_by_length.end(); ++iter)
    {
        const vector<string>& group_words = iter->second;
        int group_number = iter->first;

        // 在相同长度的单词中指定位置删除一个字母
        // 然后将删除后的结果作为key值，将相同长度的单词进行分类存储
        // 同一个key值中存储的单词，在修改一个字母后肯定能变成另一个单词
        for (int i = 0; i < group_number; ++i)
        {
            map<string, vector<string> > rep_to_word;
            for (int j = 0; j < group_words.size(); ++j)
            {
                string rep = group_words[j];
                rep.erase(i, 1);  // 删除一个字母
                rep_to_word[rep].push_back(group_words[j]);
            }

            map<string, vector<string> >::const_iterator iter2;
            for (iter2 = rep_to_word.begin(); 
                iter2 != rep_to_word.end(); ++iter2)
            {
                const vector<string>& clique = iter2->second;
                if (clique.size() >= 2)
                {
                    // 双重for循环是因为每个符合要求的单词作为key，
                    // 然后将其余的单词存入value中
                    for (int p = 0; p < clique.size(); ++p)
                    {
                        for (int q = p + 1; q < clique.size(); ++q)
                        {
                            adjacent_words[clique[p]].push_back(clique[p]);
                            adjacent_words[clique[q]].push_back(clique[q]);
                        }
                    }
                }
            }
        }
    }
    return adjacent_words;
}

int main(int argc, char* argv[])
{
    return 0;
}

