#include <bits/stdc++.h>
using namespace std;

int Length(string str)
{
    int length = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

string Substring(string arr, int initial, int length)

{
    char sub[length];
    int st = 0;
    for (int i = initial - 1; i < (initial + length - 1); i++)
    {
        sub[st++] = arr[i];
    }

    return sub;
}

int Indexing(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            return i + 1;
        }
    }

    return -1;
}

string Concate(string str, string add)
{

    string vc = str + add;

    return vc;
}

string Insertion(string str, int atPos, string add)
{
    string fin, final2, final1;

    final1 = str.substr(0, atPos - 1);

    final2 = str.substr(atPos - 1, (str.length() - atPos + 1));

    fin = final1 + add + final2;

    return fin;
}

string Deletion(string str, int position, int length)
{
    string fin;

    string pre, post;
    if (position == 0)
    {
        fin = str.substr(length, str.length());
    }
    else
    {
        pre = str.substr(0, position - 1);
        post = str.substr(position + length - 1, str.length() - (position + length) + 1);
        fin = pre + post;
    }

    return fin;
}

string Replace(string str, string old, string nold)
{
    string fin;
    string f1, f2;

    int x = Indexing(str, old);

    if (x == -1)
    {
        fin = str;
    }
    else
    {
        f1 = str.substr(0, x - 1);
        f2 = str.substr(x + old.length() - 1, (str.length() - (x + old.length()) + 1));

        fin = f1 + nold + f2;
    }

    return fin;
}

int main()
{

    string str;
    getline(cin, str);

    // cin.ignore();

// Length
    // cout << "Length: " << Length(arr) << endl;

// Substring
    // int initial, length;
    // cin >> initial >> length;
    // cout << "Substring: " << Substring(str, initial, length) << endl;
    // cout << Substring(arr, 1, 2) << endl;

// Deletion
    // cout << Deletion(str, initial, length) << endl;

// Indexing
    // string stri;
    // cin >> stri;
    // cout << Indexing(str, stri) << endl;

// Concatenation
    // string add;
    // getline(cin, add);
    // cout << Concate(arr, add) << endl;

// Insertion
    // string str;
    // cin >> str;
    // cin.ignore();
    // int atPos;
    // cin >> atPos;
    // cin.ignore();

    // string add;
    // getline(cin, add);

    // cout << Insertion(str, atPos, add) << endl;


// Replacement
    string old, nold;
    cin >> old >> nold;

    cout << Replace(str, old, nold) << endl;

    return 0;
}
