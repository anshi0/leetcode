class StockSpanner {
public:
    vector<int> arr;
    vector<int> spans;  // Stores span values for each stock price

    StockSpanner() {}

    int next(int price) {
        arr.push_back(price);
        int cnt = 1; // Start with 1 (current stock itself)

        // Traverse backwards to calculate span
        for (int i = arr.size() - 2; i >= 0; i -= spans[i]) {
            if (arr[i] <= price) {
                cnt += spans[i]; // Add previous span (jump over counted values)
            } else {
                break; // Stop when we find a larger price
            }
        }

        spans.push_back(cnt); // Store the computed span
        return cnt;
    }
};
