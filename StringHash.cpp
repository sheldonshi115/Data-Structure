#include <iostream>
#include <vector>
#include <string>

using namespace std;

//==========字符串哈希函数实现==========//
class StringHash {
private:
    static const int base = 131; // 哈希基数
    static const int mod = 1e9 + 7; // 哈希模数
    vector<unsigned long long> hashValues; // 存储前缀哈希值
    vector<unsigned long long> power; // 存储base的幂
public:
    // 构造函数，计算字符串的前缀哈希值和幂
    StringHash(const string& s) {
        int n = s.size();
        hashValues.resize(n + 1, 0);
        power.resize(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            hashValues[i + 1] = (hashValues[i] * base + s[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }
    // 获取子串s[l:r]的哈希值，0-based索引，闭区间
    unsigned long long getHash(int l, int r) {
        unsigned long long hashValue = (hashValues[r + 1] - (hashValues[l] * power[r - l + 1]) % mod + mod) % mod;
        return hashValue;
    }
};

// 测试字符串哈希函数
int main() {
    string s = "hello_world";
    StringHash sh(s);
    cout << "Hash of 'hello': " << sh.getHash(0, 4) << endl; // 哈希值 for "hello"
    cout << "Hash of 'world': " << sh.getHash(6, 10) << endl; // 哈希值 for "world"
    cout << "Hash of 'hello_world': " << sh.getHash(0, 10) << endl; // 哈希值 for "hello_world"
    return 0;
}