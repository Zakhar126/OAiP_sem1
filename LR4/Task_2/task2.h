

int findRowMax(int arr[4]) {
    int max_elem = arr[0];
    for (int j = 1; j < 4; j++) {
        if (arr[j] > max_elem) {
            max_elem = arr[j];
        }
    }
    return max_elem;
}