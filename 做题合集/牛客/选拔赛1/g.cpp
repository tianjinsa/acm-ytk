#include<bits/stdc++.h>
using namespace std;

// 计算猜测单词与可能答案之间的a和b值
pair<int, int> calculate(const string& guess, const string& answer) {
    int a = 0, b = 0;
    string answer_copy = answer;
    string guess_copy = guess;
    
    // 先匹配位置正确的字符
    for (int i = 0; i < 3; ++i) {
        if (guess_copy[i] == answer_copy[i]) {
            b++;
            // 标记已匹配的字符，防止重复计数
            guess_copy[i] = answer_copy[i] = '#';
        }
    }
    
    // 匹配位置不正确但在答案中的字符
    for (int i = 0; i < 3; ++i) {
        if (guess_copy[i] == '#') continue;  // 跳过已标记为匹配的字符
        for (int j = 0; j < 3; ++j) {
            if (answer_copy[j] == '#') continue;  // 跳过已匹配的字符
            if (guess_copy[i] == answer_copy[j]) {
                a++;
                answer_copy[j] = '#';  // 标记为已匹配
                break;
            }
        }
    }
    
    return {a + b, b};  // a是总匹配数，b是位置正确的字符数
}

int main()
{
    vector<string> guesses(5);
    vector<int> a_values(5), b_values(5);
    
    // 读取输入的5次猜测及对应的a、b值
    for (int i = 0; i < 5; ++i) {
        cin >> guesses[i] >> a_values[i] >> b_values[i];
    }
    
    vector<string> possible_answers;
    
    // 枚举所有可能的3位大写字母单词
    for (char c1 = 'A'; c1 <= 'Z'; ++c1) {
        for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
            for (char c3 = 'A'; c3 <= 'Z'; ++c3) {
                string answer = {c1, c2, c3};
                bool valid = true;
                
                // 检查每个猜测是否符合条件
                for (int i = 0; i < 5; ++i) {
                    auto [a, b] = calculate(guesses[i], answer);
                    if (a != a_values[i] || b != b_values[i]) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    possible_answers.push_back(answer);
                }
            }
        }
    }
    
    // 输出结果
    cout << possible_answers.size() << endl;
    for (const auto& answer : possible_answers) {
        cout << answer << endl;
    }
    
    return 0;
}