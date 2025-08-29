
#include <iostream>
#include <vector>
#include <sstream>

std::string reverseWords(const std::string &s) {
    std::vector<std::string> words;  //将字符串转为字符串流
    std::istringstream iss(s);
    std::string word;
    
    // 分割单词存入vector
    while (iss >> word) {
        words.push_back(word); //存入动态数组
    }
    
    // 逆序拼接
    std::string result;
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        if (!result.empty()) result += " ";
        result += *it;
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "输入英文句子: ";
    std::getline(std::cin, input);
    
    std::cout << "翻转结果: " << reverseWords(input) << std::endl;
    return 0;
}

