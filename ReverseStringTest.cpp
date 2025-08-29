#include <iostream>
#include <cstring>

void ReverseString(char* s, int from, int to) {
    while (from < to){     // 当起始位置小于结束位置时循环
        char t = s[from];  // 临时存储起始位置字符
        s[from++] = s[to]; // 将结束位置字符赋给起始位置，然后from右移
        s[to--] = t;       // 将临时字符赋给结束位置，然后to左移 
    }
}

void LeftRotateString(char* s, int n, int m){
    m %= n;                     //若要左移动大于n位，那么和%n 是等价的
    ReverseString(s, 0, n - m - 1); //反转[0..m - 1]，套用到上面举的例子中，就是X->X^T，即 abc->cba
    ReverseString(s, n - m, n - 1); //反转[m..n - 1]，例如Y->Y^T，即 def->fed
    ReverseString(s, 0, n  -1); //反转[0..n - 1]，即如整个反转，(X^TY^T)^T=YX，即 cbafed->defabc。
}

int main(){
    char str[100]; // 定义一个字符数组来存放输入的字符串
    int n, m;
    std::cout << "请输入字符串: "; 
    std::cin.getline(str, 100); //获取输入的字符串

    n = strlen(str); // 计算字符串长度

    std::cout << "请输入左移位数m: ";
    std::cin >> m;

    LeftRotateString(str, n, m); // 执行操作
                                 //
    std::cout << "结果: " << str << std::endl;

    return 0;
}
