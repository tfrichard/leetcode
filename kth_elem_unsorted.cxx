void kth_elem(vector<int> &vec, int begin, int end, int k) {
  if (begin < end) {
    int pivot = end - 1;
    int i = begin - 1;
    for (int j = begin; j < end; j++) {
      if (vec[j] <= vec[pivot]) {
	i += 1;
	swap(vec[i], vec[j]);
      }
    }
    if (i < end)
      swap(vec[i+1], vec[pivot]);

    if (i == k - 1) return;
    else if (i < k - 1) kth_elem(vec, i + 1, end, k);
    else kth_elem(vec, begin, i, k);
  }
}
