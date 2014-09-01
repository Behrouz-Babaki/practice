#include <stdio.h>
#include <string.h>

void print_post(char*, size_t, size_t, 
		char*, size_t, size_t);

int main(void) {
  char preorder[27], inorder[27];
  int status;
  status = scanf ("%s %s\n", preorder, inorder);
  while (status != EOF) {
    size_t len = strlen(preorder);
    print_post(preorder, 0, len, inorder, 0, len);
    printf("\n");
    status = scanf ("%s %s\n", preorder, inorder);
  }
  return 0;
}

void print_post(char* preorder, size_t pre_start, size_t pre_end, char* inorder, size_t in_start, size_t in_end) {
  if (pre_start == pre_end)
    return;


  char root = preorder[pre_start];
  int found = 0;
  size_t ch_counter;
  for (ch_counter = in_start; !found && ch_counter < in_end; ch_counter++) 
    if (inorder[ch_counter] == root) {
      found = 1;
      print_post (preorder, pre_start + 1, pre_start + ch_counter - in_start + 1, 
		  inorder, in_start, ch_counter);
      print_post (preorder, pre_start + ch_counter - in_start + 1, pre_end, 
		  inorder, ch_counter+1, in_end);
    }
  printf("%c", root);
}
