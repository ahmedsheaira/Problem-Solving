int* getOneBits(int n, int* result_count) {
  int count = 0, len = (log2(n) + 1), i = 0, j;
  int arr[len];
  while (n) {
    if (n&1) {
      count++;
      arr[i] = len;
      i++;
    }
    len--;
    n >>= 1;
  }
  arr[i] = count;
  *result_count = count + 1;
  int* a = malloc(sizeof(int) * (count + 1));
  for (j=0 ; j<=count ; j++) {
    a[j] = arr[i];
    i--;
  }
  return a;
}
