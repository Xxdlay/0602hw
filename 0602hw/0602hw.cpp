#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Завдання 1
void RemoveLastLine(const string& sourceFile, const string& destFile) {
    ifstream fin(sourceFile);
    if (!fin.is_open()) return;

    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    ofstream fout(destFile);
    if (!fout.is_open()) return;

    for (int i = 0; i < (int)lines.size() - 1; i++) {
        fout << lines[i] << endl;
    }
    fout.close();
}

// Завдання 2
int GetLongestLineLength(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return 0;

    int maxLength = 0;
    string line;
    while (getline(fin, line)) {
        if ((int)line.length() > maxLength) {
            maxLength = (int)line.length();
        }
    }
    fin.close();
    return maxLength;
}

// Завдання 3
int CountWord(const string& filename, const string& word) {
    ifstream fin(filename);
    if (!fin.is_open()) return 0;

    int count = 0;
    string currentWord;
    while (fin >> currentWord) {
        if (currentWord == word) {
            count++;
        }
    }
    fin.close();
    return count;
}

// Завдання 4
void ReplaceWord(const string& filename, const string& target, const string& replacement) {
    ifstream fin(filename);
    if (!fin.is_open()) return;

    vector<string> words;
    string w;
    while (fin >> w) {
        if (w == target) {
            words.push_back(replacement);
        }
        else {
            words.push_back(w);
        }
    }
    fin.close();

    ofstream fout(filename);
    if (!fout.is_open()) return;

    for (int i = 0; i < (int)words.size(); i++) {
        fout << words[i] << " ";
    }
    fout.close();
}