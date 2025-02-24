class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int i = 0, j = 31;
    while (i < 16) {
      if (((n >> i) & 1) != ((n >> j) & 1))
        n ^= (1 << i) ^ (1 << j);
      i++, j--;
    }
    return n;
  }
};
