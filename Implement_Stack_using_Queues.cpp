class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        //比如push1,2,3,4到stack s里，s=4,3,2,1->这样pop出来时就是4先pop出来，建一个q1使得q1=1,2,3,4->这样q1的front就是4 跟stack的4一样
        //先把q1清空，暂时放在q2里，然后再放回q1 
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
    private:
    queue<int> q1,q2;
};
