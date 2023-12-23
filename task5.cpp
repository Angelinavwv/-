#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

struct Element {
    string name;
    int len;
    int width;
    int height;
    float weight;
    Element(string &name,
            int len,
            int width,
            int height,
            float weight) {
        this->name = name;
        this->len = len;
        this->width = width;
        this->height = height;
        this->weight = weight;
    }

    Element(const Element &element) {
        this->name = element.name;
        this->len = element.len;
        this->width = element.width;
        this->height =element.height;
        this->weight = element.weight;
    }
};

void tokenize(string const &str, const char delim, vector<string> &out) {
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

vector<Element> copy(vector<Element> const&elements) {
    vector<Element> newVector;
    for (const auto &item: elements){
        newVector.push_back(Element(item));
    }
    return newVector;
}

void fillElements(int size, vector<Element> &elements) {
    if(size != 0) {
        for(int i = 0; i < size; i++) {
            string input;
            getline(cin, input);

            vector<string> strings;
            tokenize(input, ' ', strings);
            elements.emplace_back(strings.at(0), stoi(strings.at(1)), stoi(strings.at(2)), stoi(strings.at(3)), stof(strings.at(4))
            );
        }
    }
}

void printElements(vector<Element> const&elements) {
    if (elements.empty()) {
        cout<<"empty"<<endl;
    } else {
        for(auto & element : elements) {
            cout<<element.name<<" "<<element.len<< " "<<element.width<<" "<<element.height<<" "<<element.weight<<endl;
        }
    }
}

void filterByArgs(vector<Element> &mutableElements, vector<string> const&input) {
    vector<Element> result;
    int command = stoi(input.at(1));
    string equalSymbol = input.at(2);
    string equalTo = input.at(3);
    switch (command) {
        case 1: {
            if (equalSymbol == "<" || equalSymbol == ">") {
                result = mutableElements;
            } else if(equalSymbol == "=") {
                for(auto & element : mutableElements) {
                    if (element.name == equalTo) {
                        result.push_back(element);
                    }
                }
            }
            break;
        }

        case 2: {
            int asInt = stoi(equalTo);
            if (equalSymbol == "<") {
                for(auto & element : mutableElements) {
                    if (element.len < asInt) {
                        result.push_back(element);
                    }
                }
            } else if(equalSymbol == "=") {
                for(auto & element : mutableElements) {
                    if (element.len == asInt) {
                        result.push_back(element);
                    }
                }
            }else if(equalSymbol == ">") {
                for(auto & element : mutableElements) {
                    if (element.len > asInt) {
                        result.push_back(element);
                    }
                }
            }
            break;
        }

        case 3: {
            int asInt = stoi(equalTo);
            if (equalSymbol == "<") {
                for(auto & element : mutableElements) {
                    if (element.width < asInt) {
                        result.push_back(element);
                    }
                }
            } else if(equalSymbol == "=") {
                for(auto & element : mutableElements) {
                    if (element.width == asInt) {
                        result.push_back(element);
                    }
                }
            }else if(equalSymbol == ">") {
                for(auto & element : mutableElements) {
                    if (element.width > asInt) {
                        result.push_back(element);
                    }
                }
            }
            break;
        }
        case 4: {
            int asInt = stoi(equalTo);
            if (equalSymbol == "<") {
                for(auto & element : mutableElements) {
                    if (element.height < asInt) {
                        result.push_back(element);
                    }
                }
            } else if(equalSymbol == "=") {
                for(auto & element : mutableElements) {
                    if (element.height == asInt) {
                        result.push_back(element);
                    }
                }
            }else if(equalSymbol == ">") {
                for(auto & element : mutableElements) {
                    if (element.height > asInt) {
                        result.push_back(element);
                    }
                }
            }
            break;
        }
        case 5: {
            float asInt = stof(equalTo);
            if (equalSymbol == "<") {
                for(auto & element : mutableElements) {
                    if (element.weight < asInt) {
                        result.push_back(element);
                    }
                }
            } else if(equalSymbol == "=") {
                for(auto & element : mutableElements) {
                    if (element.weight == asInt) {
                        result.push_back(element);
                    }
                }
            } else if(equalSymbol == ">") {
                for(auto & element : mutableElements) {
                    if (element.weight > asInt) {
                        result.push_back(element);
                    }
                }
            }
            break;

        }
        default:
            result = mutableElements;
            break;
    }
    mutableElements = result;
}

void processCommand(vector<Element> const&elements, vector<Element> &mutableElements) {
    string input;
    getline(cin, input);

    vector<string> strings;
    tokenize(input, ' ', strings);

    switch (stoi(strings.at(0))) {
        case 1:
            filterByArgs(mutableElements, strings);
            break;
        case 2:
            printElements(mutableElements);
            break;
        case 3:
            mutableElements = copy(elements);
            break;
    }
}

int main() {

    int elemCount = 0, commandCount = 0;
    cin >> elemCount;
    cin.get();

    vector<Element> elements;

    fillElements(elemCount, elements);

    cin >> commandCount;
    cin.get();

    vector<Element> mutableElements = copy(elements);

    for(int i = 0; i < commandCount; i++) {
        processCommand(elements, mutableElements);
    }


    return 0;
}
