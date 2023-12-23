#include <iostream>

#include <string>
#include <vector>
#include <sstream>

#include <algorithm>

using namespace std;

void tokenize(string const &str, const char delim, vector<string> &out) {
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

template<typename T>
class Element {
    int id;
    int accessCount;
    T data;
public:
    Element(int id, T &data) {
        this->id = id;
        this->accessCount = 0;
        this->data = data;
    }

    int getId() {
        return id;
    }

    int getAccessCount() {
        return accessCount;
    }

    void increaseAccessCount() {
        accessCount++;
    }

    void setData(T& data) {
        this->data = data;
    }

    T getData() {
        return data;
    }

    void print() {
        cout<<"{"<<id<<" "<<accessCount<<" "<<data<<"}";
    }
};

template<typename T>
class MyList {
    vector<Element<T>> elements;

    void sortElements() {
        sort(elements.begin(), elements.end(), [](Element<T> first, Element<T> second) {
            return first.getAccessCount() >= second.getAccessCount();
        });
    }

public:

    void setData(int id, T& data) {
        for(int i = 0; i < elements.size(); i++) {
            Element<T> &element = elements.at(i);
            if (element.getId() == id) {
                element.setData(data);
                return;
            }
        }
        elements.push_back(*new Element<T>(id, data));
    }
    void printById(int id) {
        for(int i = 0; i < elements.size(); i++) {
            Element<T> &element = elements.at(i);
            if(element.getId() == id) {
                element.increaseAccessCount();
                element.print();
                cout<<endl;
                sortElements();
                return;
            }
        }
    }

    void findElementByData(T& data) {
        for(int i = 0; i < elements.size(); i++) {
            Element<T> &element = elements.at(i);
            if(element.getData() == data) {
                element.increaseAccessCount();
                cout<<"YES"<<endl;
                sortElements();
                return;
            }
        }
        cout<<"NO"<<endl;
    }

    void printAll() {
        for(int i = 0; i < elements.size(); i++) {
            Element<T> &element = elements.at(i);
            element.print();
            cout<<" ";
        }
        cout<<endl;
    }
};



int main() {

    int elemCount = 0, commandCount = 0;
    cin >> elemCount;
    cin.get();

    auto *list = new MyList<int>();
    for(int i = 0; i < elemCount; i++) {
        string input;
        getline(cin, input);

        vector<string> strings;
        tokenize(input, ' ', strings);
        int data = stoi(strings.at(1));
        list->setData(stoi(strings.at(0)), data);
    }

    cin >> commandCount;
    cin.get();

    for(int i = 0; i < commandCount; i++) {
        string input;
        getline(cin, input);

        vector<string> strings;
        tokenize(input, ' ', strings);
        switch (stoi(strings.at(0))) {
            case 1: {
                int data = stoi(strings.at(2));
                list->setData(stoi(strings.at(1)),data);
                break;
            }

            case 2:
                list->printById(stoi(strings.at(1)));
                break;
            case 3: {
                int data = stoi(strings.at(1));
                list->findElementByData(data);
                break;
            }

            case 4:
                list->printAll();
                break;
            
        }
    }

    return 0;
}
