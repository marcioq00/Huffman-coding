#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout<<"Podaj tekst do skompresowania: ";
    string tekst;
    cin >> tekst;
    int charCount[26] = {};
    for(char c : tekst) {
        if(c >= 'a' && c <= 'z') {
            charCount[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0) {
            char c = 'a' + i;
            std::cout << "Litera " << c << " wystapila " << charCount[i] << " razy." << std::endl;
        }
    }

    /*for(int i=0; i < tekst.length(); i++) {
        cout << tekst[i] << endl;
    }*/
    return 0;
}
