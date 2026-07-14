class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bin = bitset<32>(n).to_string();

        reverse(bin.begin(), bin.end());

        return bitset<32>(bin).to_ulong();
    }
};