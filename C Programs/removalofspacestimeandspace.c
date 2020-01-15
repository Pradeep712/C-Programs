// Assumes in-place removal of spaces
// Time O(n) - Space O(1)
void removeSpaces(char* s) {
  if (!s) {
    return;
  }
  char* nonwhite = s - 1;
  char* itr = s;
  while (*itr) {
    if (*itr != ' ') {
      *(++nonwhite) = *itr;
    }
    ++itr;
  }
  *(++nonwhite) = '\0';
}