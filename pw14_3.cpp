
#include <iostream>
using namespace std;

class MinStack {
private:
    int data[1000];
    int mins[1000];
    int size = 0;

public:
    void push(int x) {
        data[size] = x;

        if (size == 0 || x < mins[size - 1]) {
            mins[size] = x;
        }
        else {
            mins[size] = mins[size - 1];
        }

        size++;
    }

    void pop() {
        if (size > 0) {
            size--;
        }
    }

    bool empty() {
        return size == 0;
    }

    int getMin() {
        return mins[size - 1];
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Minimum after removal: " << st.getMin() << endl;

    return 0;
}
