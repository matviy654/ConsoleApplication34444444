#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

void modifyValue(const int* ptr) {
    int* nonConstPtr = const_cast<int*>(ptr);
    *nonConstPtr = 200;
}

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing a Shape" << endl;
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    int a;
    float b;
    cout << "Введіть ціле число a: ";
    cin >> a;
    cout << "Введіть число з плаваючою точкою b: ";
    cin >> b;

    cout << "Сума a + b: " << a + b << endl;
    cout << "Різниця a - b: " << a - b << endl;
    cout << "Множення a * b: " << a * b << endl;
    cout << "Цілочисельне ділення (int)b / a: " << static_cast<int>(b) / a << endl;

    char c;
    cout << "\nВведіть символ: ";
    cin >> c;
    cout << "ASCII-код символу: " << static_cast<int>(c) << endl;

    int asciiCode;
    cout << "Введіть ASCII-код: ";
    cin >> asciiCode;
    cout << "Відповідний символ: " << static_cast<char>(asciiCode) << endl;

    cout << "Рядок символів у ASCII-коди:\n";
    string inputString;
    cout << "Введіть рядок: ";
    cin >> inputString;
    for (char ch : inputString) {
        cout << static_cast<int>(ch) << " ";
    }
    cout << endl;

    float floatResult = static_cast<float>(a) + b;
    int intResult = static_cast<int>(b) * a;
    char charResult = static_cast<char>(a);

    cout << "\nПеретворення за допомогою static_cast:" << endl;
    cout << "Ціле до float + b: " << floatResult << endl;
    cout << "float до int * a: " << intResult << endl;
    cout << "Ціле до char: " << charResult << endl;

    stack<char> parentheses;
    string expression;
    cout << "\nВведіть вираз з дужками: ";
    cin >> expression;

    bool valid = true;
    int openCount = 0, closeCount = 0;

    for (char ch : expression) {
        if (ch == '(') {
            parentheses.push(ch);
            openCount++;
        }
        else if (ch == ')') {
            closeCount++;
            if (parentheses.empty() || parentheses.top() != '(') {
                valid = false;
                break;
            }
            parentheses.pop();
        }
    }

    if (valid && parentheses.empty()) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
    cout << "Кількість відкритих дужок: " << openCount << endl;
    cout << "Кількість закритих дужок: " << closeCount << endl;

    vector<Shape*> shapes = { new Circle(), new Rectangle(), new Shape() };
    cout << "\nDynamic casting with Shapes:" << endl;
    for (Shape* shape : shapes) {
        if (auto* circle = dynamic_cast<Circle*>(shape)) {
            circle->draw();
        }
        else if (auto* rectangle = dynamic_cast<Rectangle*>(shape)) {
            rectangle->draw();
        }
        else {
            cout << "Невірне приведення" << endl;
        }
        delete shape;
    }

    const int value = 100;
    cout << "\nПочаткове значення const int: " << value << endl;
    modifyValue(&value);
    cout << "Значення після виклику modifyValue: " << value << endl;

    return 0;
}
