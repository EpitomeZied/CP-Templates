template<typename T>
struct MonoStack {
    stack<pair<T, T>> st;
 
    void push(const T &x) {
        T mx = st.empty() ? x : max(x, st.top().second);
        st.emplace(x, mx);
    }
 
    void pop() {
        st.pop();
    }
 
    T top() { return st.top().first; }
 
    bool empty() { return st.empty(); }
 
    size_t size() { return st.size(); }
 
    T getMax() { return st.top().second; }
};