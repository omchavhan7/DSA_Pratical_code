#include <iostream>
using namespace std;

class my_string
{
private:
    char str[100];

public:
    void set(const char src[])
    {
        int i = 0;
        while (src[i] != '\0')
        {
            str[i] = src[i];
            i++;
        }
        str[i] = '\0';
    }

    void input()
    {
        cout << "Enter string: ";
        cin.getline(str, 100);
    }

    int my_str_len()
    {
        int i = 0;
        while (str[i] != '\0')
        {
            i++;
        }
        return i;
    }

    void str_copy(char dest[])
    {
        int i = 0;
        while (str[i] != '\0')
        {
            dest[i] = str[i];
            i++;
        }
        dest[i] = '\0';
    }

    void str_concat(const char src[])
    {
        int len = my_str_len();
        int i = 0;

        while (src[i] != '\0')
        {
            str[len + i] = src[i];
            i++;
        }
        str[len + i] = '\0';
    }

    void str_rev()
    {
        int left = 0;
        int right = my_str_len() - 1;

        while (left < right)
        {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;

            left++;
            right--;
        }
    }

    void display()
    {
        cout << str << endl;
    }

    const char *getStr()
    {
        return str;
    }
};

int main()
{
    my_string s1, s2;
    char temp[100];
    int choice;

    cout << "Enter first string:\n";
    cin.getline(temp, 100);
    s1.set(temp);

    cout << "Enter second string:\n";
    cin.getline(temp, 100);
    s2.set(temp);

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Length of Strings\n";
        cout << "2. Copy String 1 to Temp\n";
        cout << "3. Concatenate String 2 to String 1\n";
        cout << "4. Reverse String 1\n";
        cout << "5. Display Strings\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Length of string 1 = " << s1.my_str_len() << endl;
            cout << "Length of string 2 = " << s2.my_str_len() << endl;
            break;

        case 2:
            s1.str_copy(temp);
            cout << "Copied string (from s1): " << temp << endl;
            break;

        case 3:
            s1.str_concat(s2.getStr());
            cout << "After concatenation, String1 = ";
            s1.display();
            break;

        case 4:
            s1.str_rev();
            cout << "After reverse, String1 = ";
            s1.display();
            break;

        case 5:
            cout << "String 1: ";
            s1.display();
            cout << "String 2: ";
            s2.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } whil  e (choice != 6);

    return 0;
}
