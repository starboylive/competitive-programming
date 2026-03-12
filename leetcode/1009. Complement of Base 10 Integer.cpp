// 1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        string bin = bitset<32>(n).to_string();

        int firstOne = bin.find('1');
        bin = bin.substr(firstOne);

        for(char &c : bin){
            c = (c == '0') ? '1' : '0';
        }

        return stoi(bin, nullptr, 2);
    }
};