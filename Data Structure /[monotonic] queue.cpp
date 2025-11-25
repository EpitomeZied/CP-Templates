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
 
template<typename T>
struct MonoQueue {
    MonoStack<T> in, out;
 
    void push(const T &x) {
        in.push(x);
    }
 
    void pop() {
        if (out.empty())
            moveInToOut();
        out.pop();
    }
 
    T top() {
        if (out.empty())
            moveInToOut();
        return out.top();
    }
 
    bool empty() {
        return in.empty() && out.empty();
    }
 
    size_t size() {
        return in.size() + out.size();
    }
 
    T getMax() {
        if (in.empty())
            return out.getMax();
        if (out.empty())
            return in.getMax();
        return max(in.getMax(), out.getMax());
    }
 
    void moveInToOut() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
};