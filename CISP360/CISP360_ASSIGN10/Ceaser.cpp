#include <stdio.h>
#include <stdlib.h>

/*  Some info:
//      -The string length is not currently variable but that can be done by allowing the user to input the size
//      -The encryption/decryption functions will handle upper case and lower case letters all others should be unchanged
//      -Convert case is working and included but not used because it's not necessary..
//      -I chose to use fgets because the user input string can contain whitespace and such this way
//      -the encrypt/decrypt idea is kinda neat and took a good bit of wrestling to get right
*/

///some quick helper functions
void ceas_crypt(char*, int, int);
void ceas_decrypt(char*, int, int);
void convert_case(char*, int);
void menu();

int main()
{
    ///a starting value for the size
    int size = 512;
    int shift = -1;

    char choice;
    char ignore;
    do
    {
        char* code = (char*) calloc(size, sizeof(char));    ///this is freed at the end of the loop
        menu();
        scanf("%c",&choice);    /// I feel like this sequence could be wrapped
        scanf("%c",&ignore);    ///pesky trailing newlines
        switch (choice)
        {
        case 'e':
        case 'E':
            printf("Please enter a key for encryption: \n");
            scanf("%d",&shift);
            scanf("%c",&ignore);
            printf("Please enter a message to be encrypted: \n");
            ///using fgets to preserve spaces
            fgets(code,size,stdin);
            ///you can use my convert case function if you want but my code works fine regardless of the case
            ///convert_case(code, size);
            ///printf("%s\n",code);
            ceas_crypt(code,shift,size);
            printf("Encrypted text: %s",code);
            ///this is just extra debug outputs for convenience
            ///ceas_decrypt(code,shift,size);
            ///printf("Decrypted text: %s",code);
            break;
        case 'd':
        case 'D':
            printf("Please enter a key for decryption: \n");
            scanf("%d",&shift);
            scanf("%c",&ignore);
            printf("Please enter a message to be decrypted: \n");
            ///scanf("%s",code);
            ///using fgets to preserve spaces just in case
            fgets(code,size,stdin);
            ///convert_case(code, size);
            ceas_decrypt(code,shift,size);
            printf("Decrypted text: %s",code);
            break;
        case 'q':
        case 'Q':
            printf("Goodbye!\n");
            break;
        default:
            printf("I'm sorry, what did you say?\n");
        }
        free(code);

    }
    while (choice != 'Q' && choice != 'q');

    return 0;
}
void menu()
{
    printf("Option 1: e/E to encrypt\n");
    printf("Option 2: d/D to decrypt\n");
    printf("Option 3: q/Q to quit\n");
}
void convert_case(char* msg, int size)
{
    ///this is pretty linear
    for (int i = 0; i < size; i++)
    {
        if (msg[i] >= 97 && msg[i] <= 122)
            msg[i] = msg[i] - 32;
    }
}

///the basic idea is to bump the ith array elements ascii val down to an offset in an imaginary alphabet where: a=0, b=1, c=2 etc
///then add the users input shift value to get the rotated letter in our imaginary/symbolic alphabet
///then you add back the offset in the table of real ascii values that you subtracted by
/// to bump that array element back up to a real ascii value.
///
///But the process is different for upper and lower case values so we range check to find which case we are dealing with and that
///determines whether we are going to sub and add by 97 before shifting ('a') or by 65 ('A')
///the idea came from this dudes description but I had to modify and poke at it til it worked right
///https://stackoverflow.com/questions/22208139/c-caesar-cipher-ascii-alphabet-wrap
///
///lastly I had some issues with 'z' going out of range so I mod 26 the shift value and treat the two halves of the alphabet
///differently to prevent ever going out of range as well as to ensure proper wrapping of the alphabet no matter what
///the input string or input shift
void ceas_crypt(char* msg, int shift, int size)
{
    ///we don't want to shift too far left or right...
    ///the shifts just loop back around meaning a shift 27 is really a shift 1
    shift = shift % 26;
    for (int i = 0; i < size; i++)
    {
        ///a lower case letter
        if (msg[i] >= 97 && msg[i] <= 122)
        {
            msg[i] = msg[i] - 97;
            if (msg[i] <= 13)   ///thirteen is halfway into the alphabet, we are treating the left half differently
            {
                ///basically we just go one alphabet over and loop back around to the exact same character
                msg[i] += 26;   ///this helped prevent xyz => *garbage-ascii* type issues
                msg[i] = msg[i] + shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 97;
            }
            else
            {
                msg[i] = msg[i] + shift;    ///the right half of the alphabet is more simple
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 97;
            }
        }
        ///an upper case letter
        if (msg[i] >= 65 && msg[i] <= 90)
        {
            msg[i] = msg[i] - 65;
            if (msg[i] <= 13)
            {
                msg[i] += 26;
                msg[i] = msg[i] + shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 65;
            }
            else
            {
                msg[i] = msg[i] + shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 65;
            }
        }
    }
}
///I bet there is a way to modify the previous function to do this too..
void ceas_decrypt(char* msg, int shift, int size)
{
    shift = shift % 26;

    for (int i = 0; i < size; i++)
    {
        ///a lower case letter
        if (msg[i] >= 97 && msg[i] <= 122)
        {
            msg[i] = msg[i] - 97;
            if (msg[i] <= 13)
            {
                msg[i] += 26;
                msg[i] = msg[i] - shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 97;
            }
            else
            {
                msg[i] = msg[i] - shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 97;
            }
        }

        ///an upper case letter
        if (msg[i] >= 65 && msg[i] <= 90)
        {
            msg[i] = msg[i] - 65;
            if (msg[i] <= 13)
            {
                msg[i] += 26;
                msg[i] = msg[i] - shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 65;
            }
            else
            {
                msg[i] = msg[i] - shift;
                msg[i] = msg[i] % 26;
                msg[i] = msg[i] + 65;
            }
        }
    }
}

