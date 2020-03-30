using namespace std;

class RC{
private:
    int count; // Reference count
public:
    void AddRef(){
        // Increment the reference count
        count++;
    }
    int Release(){
        // Decrement the reference count and
        // return the reference count.
        int value = count;
        cout << " Disminuyendo RC de: " << count << " a: " << --value << endl;
        return --count;
    }
    int getCount(){
        return count;
    }
};
