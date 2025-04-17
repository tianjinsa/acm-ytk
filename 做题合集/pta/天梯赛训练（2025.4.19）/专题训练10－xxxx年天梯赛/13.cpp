#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    string formatted;
    int indent = 0;  // 当前缩进级别
    bool newLineNeeded = false;  // 是否需要换行
    bool afterKeyword = false;  // 是否在关键字之后
    bool inSemicolon = false;  // 是否在分号之后
    
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        
        if (c == ' ') {
            // 处理空格
            if (!newLineNeeded && formatted.length() > 0 && formatted.back() != ' ') {
                formatted += c;
            }
            continue;
        }
        
        if (newLineNeeded) {
            formatted += '\n';
            // 添加缩进
            for (int j = 0; j < indent * 2; ++j) {
                formatted += ' ';
            }
            newLineNeeded = false;
        }
        
        if (c == '{') {
            // 左花括号单独一行
            if (!formatted.empty() && formatted.back() != '\n') {
                formatted += '\n';
                for (int j = 0; j < indent * 2; ++j) {
                    formatted += ' ';
                }
            }
            formatted += c;
            indent++;
            newLineNeeded = true;
        } else if (c == '}') {
            // 右花括号单独一行
            indent--;
            if (!formatted.empty() && formatted.back() != '\n') {
                formatted += '\n';
            }
            // 添加缩进
            for (int j = 0; j < indent * 2; ++j) {
                formatted += ' ';
            }
            formatted += c;
            
            // 检查是否有else
            if (i + 1 < s.length() && s.substr(i + 1, 5) == " else") {
                i += 5; // 跳过"else"
                formatted += '\n';
                for (int j = 0; j < indent * 2; ++j) {
                    formatted += ' ';
                }
                formatted += "else";
                
                // 检查else后面是否有if
                if (i + 1 < s.length() && s.substr(i + 1, 3) == " if") {
                    i += 3;
                    formatted += " if";
                    afterKeyword = true;
                } else {
                    newLineNeeded = false;
                }
            } else {
                newLineNeeded = true;
            }
        } else if (c == ';') {
            formatted += c;
            newLineNeeded = true;
        } else if (i + 2 < s.length() && 
                  ((c == 'f' && s.substr(i, 3) == "for") || 
                   (c == 'i' && s.substr(i, 2) == "if") || 
                   (c == 'w' && s.substr(i, 5) == "while"))) {
            // 处理关键字
            if (c == 'f') {
                formatted += "for";
                i += 2;
            } else if (c == 'i') {
                formatted += "if";
                i += 1;
            } else {
                formatted += "while";
                i += 4;
            }
            afterKeyword = true;
        } else if (c == 'e' && i + 3 < s.length() && s.substr(i, 4) == "else") {
            // 处理else关键字
            formatted += "else";
            i += 3;
            
            // 检查else后面是否有if
            if (i + 2 < s.length() && s.substr(i + 1, 3) == " if") {
                i += 3;
                formatted += " if";
                afterKeyword = true;
            } else {
                newLineNeeded = false;
            }
        } else {
            formatted += c;
            afterKeyword = false;
        }
    }
    
    cout << formatted << endl;
    return 0;
}