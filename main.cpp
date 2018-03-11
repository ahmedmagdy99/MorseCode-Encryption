// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: Encryption Problem.cpp
// Last Modification Date: 3/4/2018
// Author1 and ID and Group: ahmed magdy 20170027
// Author2 and ID and Group: ahmed mostafa 20170033
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include <iostream>
#include <string>
using namespace std;

string MorseCode [28] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "   "};
char MorseAlpha [28] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '   '};
string test;//empty string to append in
int main()
{
    bool flag=true;
    int Need=0, cont=0 ;
    string word;
    cout<<"in cipher encryption you should enter alphabet only in decipher enter the code and a space between each char and 3 spaces between each word "<<endl<<endl;
    cout<<"ahlan ya user ya 7abeby"<<endl;
    cout<<"what do you like to do today ?"<<endl<<endl;
loop :
    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;
    cout<<"3- End"<<endl;
    cin>>Need;//what would like to do
    while (flag)//big loop for the need that the user want
    {
        if (Need == 1)//if want to cipher
        {
            cout<<"Enter the message you want to cipher : ";
            cin.ignore();
            getline(cin,word);
            for (int i = 0 ; i<word.size(); i++)//check that the input is valid
            {
                if (!isalpha(word[i]) and word[i]!=' ')
                {
                    cout << "invalid";
                    return 0;
                }
            }
            for(int i=0 ; i<word.length() ; i++)
            {
                if (word[i]==' ')//check that if inputted char is space to print 3 spaces
                    cout << "   " ;
                else
                    cout << MorseCode[int(toupper(word[i])-'A')]<<" ";//ciphering the message

            }
            flag=false;//stop the while loop
        }
        if(Need==2)//if want to decipher
        {
            cout<<"Enter the message you want to decipher : ";
            cin.ignore();
            getline(cin,word);
            for (int i = 0 ; i<word.size(); i++)//
            {
                if (word[i]!= '-' and word[i]!= '.' and word[i]!= ' ')//check that the input is valid
                {
                    cout << "invalid";
                    return 0;
                }
            }
            for(int i=0 ; i<word.size() ; i++)
            {
                if(word[i] != ' ')//check if the char is space or not
                {
                    test+=word[i];
                }
                if(word[i] == ' ' || i==word.size()-1)//if one space print the alphabet char behind each other
                {
                    for (int j=0 ; j < 27 ; j++)
                    {
                        if (test == MorseCode[j])
                        {
                            cout << MorseAlpha[j];
                            test="";
                        }
                    }
                }
                if (word[i]==' ' && word[i+1]==' ' && word[i+2]==' ')//if three spaces print space then the alphabet
                {
                    cout<<" ";
                    for (int z=0 ; z < 27 ; z++)
                    {
                        if (test == MorseCode[z])
                        {
                            cout << MorseAlpha[z];
                            test="";
                        }
                    }
                }
            }
            flag=false;//stop the while loop
        }
        if (Need == 3)//ending the program
        {
            return 0;
        }
        else
        {
            while(flag)//check that the input is 1,2 or 3 only
            {
                cout<<"please enter 1,2 or 3 only"<<endl;
                cout<<"1- Cipher a message"<<endl;
                cout<<"2- Decipher a message"<<endl;
                cout<<"3- End"<<endl;
                cin>>Need;
                if (Need==1 or Need==3 or Need==2)
                {
                    break;
                    flag=false;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    cout<<endl<<"if you want to continue using the program press 1 if you want to end press 2: ";
    cin>>cont;
    if (cont==1)
    {
        flag=true;
        goto loop;

    }
    if (cont=2)
    {
        return 0;
    }
    return 0;

}
