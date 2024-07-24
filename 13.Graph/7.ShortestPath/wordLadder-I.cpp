#include <bits/stdc++.h>
using namespace std;
//basic undirected graph me shortest path wala chij i.e. BFS
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});//startword is step 1

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.(Visited type krne ke liye)
        //basically usko nikal diye mtlb vo visited hogya
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)//har letter ko a to z sbse replace
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1}); //BFS steps+1 kro
                    }
                }
                word[i] = original; //wapas wo letter ko shi kr diye ab next letter pe kaam
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};
 
int main()
{
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;//all words steps start ->end tak
    cout << endl;
    return 0;
}