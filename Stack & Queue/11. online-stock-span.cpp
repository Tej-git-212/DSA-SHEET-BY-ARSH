public:
	stack<pair<int,int>>sti;
	StockSpanner() {
	}

    int next(int price) {
        int span = 0;
        while(!sti.empty() && sti.top().first <= price) {
            span += sti.top().second;
            sti.pop();
        }
        sti.push({ price, span + 1 });
        return span + 1;
    }

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
