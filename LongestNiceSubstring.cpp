void testNiceSubstring(string &s, int start, int end, string &result) {
  if (end - start <= 1 || end - start <= result.size())
    return;

  uint32_t lowerPresent = 0;
  uint32_t upperPresent = 0;

  for (int i = start; i < end; i++) {
    if (s[i] >= 'a')
      lowerPresent |= 1 << (s[i] - 'a');
    else
      upperPresent |= 1 << (s[i] - 'A');
  }

  uint32_t lonelyChars = lowerPresent ^ upperPresent;
  if (!lonelyChars) {
    result = s.substr(start, end - start);
    return;
  }

  int startIndex = start;

  for (int i = start; i < end; i++) {
    uint32_t mask;
    if (s[i] >= 'a')
      mask = 1 << (s[i] - 'a');
    else
      mask = 1 << (s[i] - 'A');

    if (lonelyChars & mask) {
      testNiceSubstring(s, startIndex, i, result);
      startIndex = i + 1;
    }
  }
  testNiceSubstring(s, startIndex, end, result);
}

string longestNiceSubstring(string s) {
  string longest = "";
  testNiceSubstring(s, 0, s.size(), longest);
  return longest;
}
