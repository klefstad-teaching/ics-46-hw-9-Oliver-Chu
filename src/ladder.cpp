#include "ladder.h"
#include <stack>

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "Same word.");
        return {};
    }

    queue<vector<string>> ladderq;
    ladderq.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladderq.empty()) {
        vector<string> ladder = ladderq.front();
        ladderq.pop();
        string last_word = ladder.back();

        for (auto word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    visited.insert(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladderq.push(new_ladder);
                }
            }
        }
    }
    return {};
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int str_len1 = str1.size();
    int str_len2 = str2.size();
    if (abs(str_len1 - str_len2) > 1) {
        return false;
    }

    int diff = 0;
    int i1 = 0;
    int i2 = 0;
    while (i1 < str_len1 && i2 < str_len2) {
        if (str1[i1] == str2[i2]) {
            ++i1;
            ++i2;
        }
        else {
            ++diff;
            if (str_len1 > str_len2) {
                ++i1;
            }
            else if (str_len1 < str_len2) {
                ++i2;
            }
            else {
                ++i1;
                ++i2;
            }

        }
    }
    return diff <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

void error(string word1, string word2, string msg) {
    cout << word1 << " : " << word2 << msg << endl;
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() == 0) {
        cout << "No word ladder found.";
    }
    else {
        for (int i = 0; i < ladder.size(); ++i) {
            cout << ladder[i] << " ";
        }
    }
    cout << endl;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(file_name);
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

void my_assert(bool check) {
    if (!check) {
        cerr << "FAILED CHECK!" << endl;
    }

}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}