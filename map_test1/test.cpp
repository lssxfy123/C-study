// Copyright 2016.���|�|
// author�����|�|
// map�����Ĳ���
// ˵�����Ӽ����Ӣ�ﵥ���в�����Щֻͨ���滻һ����ĸ
// �Ϳ��Եõ�15�����ϲ�ͬ���ʵĵ��ʡ�

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

// ����Ϊ���ʱ�
map<string, vector<string> > ComputeAdjacentWords(const vector<string>& words)
{
    map<string, vector<string> > adjacent_words;
    map<int, vector<string> > words_by_length;

    // ���յ��ʵĳ��Ƚ��з���
    for (int i = 0; i < words.size(); ++i)
    {
        words_by_length[words[i].length()].push_back(words[i]);
    }

    for (map<int, vector<string> > ::const_iterator iter = words_by_length.begin();
        iter != words_by_length.end(); ++iter)
    {
        const vector<string>& group_words = iter->second;
        int group_number = iter->first;

        // ����ͬ���ȵĵ�����ָ��λ��ɾ��һ����ĸ
        // Ȼ��ɾ����Ľ����Ϊkeyֵ������ͬ���ȵĵ��ʽ��з���洢
        // ͬһ��keyֵ�д洢�ĵ��ʣ����޸�һ����ĸ��϶��ܱ����һ������
        for (int i = 0; i < group_number; ++i)
        {
            map<string, vector<string> > rep_to_word;
            for (int j = 0; j < group_words.size(); ++j)
            {
                string rep = group_words[j];
                rep.erase(i, 1);  // ɾ��һ����ĸ
                rep_to_word[rep].push_back(group_words[j]);
            }

            map<string, vector<string> >::const_iterator iter2;
            for (iter2 = rep_to_word.begin(); 
                iter2 != rep_to_word.end(); ++iter2)
            {
                const vector<string>& clique = iter2->second;
                if (clique.size() >= 2)
                {
                    // ˫��forѭ������Ϊÿ������Ҫ��ĵ�����Ϊkey��
                    // Ȼ������ĵ��ʴ���value��
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

