#include <stdio.h>
#include <wchar.h>//Needed to access wide characters (cyrillic falls under this category)
#include <locale.h>//Needed to access the setLocale and setConsoleOutputCP function.
#include <windows.h>//Accesses the SetConsoleOutputCP command, though Windows specific.
#define MAX_SIZE 100 //Max size of one word.
/*
This program detects the last two characters of a Russian word and guesses if the word ending is one of the six cases.

Of course, the program is not 100% accurate, as in the Russian language, it is rife with exceptions and exceptions are handled to a certain extent.
To cover every exception cases to a 10,000 word list, the program would need a lot of work and they would need to be added to the list of exceptions.

Problem #1: This program only covers two words, but some words have one ending (Accusative endings, most of nominative endings, prepositional singular, dative singulars, gentive singulars, genitive feminine plural, etc.)
letter while some have three (like the Instrumental Case Plural endings).

REMINDER: The Latin 'a' and the Cyrillic 'a' are two entirely different unicode characters. Same goes for the Latin 'e' and the Cyrillic 'е', Latin 'y' and the Cyrillic 'у' and the Latin 'o' and the Cyrillic 'о'.
If you were to use the Latin 'a' instead of the Cyrillic 'а', the program would not detect the word.

Refer to https://www.russianlessons.net/ for context. */

void declension_noun(const wchar_t *word, char *gender, char *plural) {
    
    printf("The gender is %c, and the plural is %c\n",*gender, *plural);//Debug code


    
    int length = wcslen(word); //Use wcslen instead of strlen because we are dealing with long characters instead of regular characters.
        wchar_t last_two[3]; // Array to store the last two characters
        wcsncpy(last_two, word + length - 2, 2); // wcsncpy is used instead of scncpy because we are dealing with wide characters. Copy the last two wide-characters into the array.
        //last_two[2] = L'\0'; // Null-terminate the string, this line of code is not needed.
        wprintf(L"Last two letters: %lc%lc\n", last_two[0],last_two[1]);   

        //Else-if is used because switch-case does not support logical operators.

        //Nominative Case
        if((last_two[1]==L'б'||last_two[1]==L'г'||last_two[1]==L'д'||last_two[1]==L'ж'||last_two[1]==L'з'||last_two[1]==L'ж'||last_two[1]==L'к'||last_two[1]==L'ж'||last_two[1]==L'л'||last_two[1]==L'н'||last_two[1]==L'п'||last_two[1]==L'р'||last_two[1]==L'с'||last_two[1]==L'т'||last_two[1]==L'ф'||last_two[1]==L'х'||last_two[1]==L'щ'||last_two[1]==L'ц'||last_two[1]==L'ч'||last_two[1]==L'ш'||last_two[1]==L'ь')&&*gender=='m'&&*plural=='s'){
        //Covers almost every consonant and soft sign with exceptions.
        printf("This word's ending is the Nominative Singular Male.\n");
        printf("This word's ending is also the Accusative Inanimate Singular Male.\n");
        }
        else if((last_two[1]==L'а' || last_two[1]==L'я')&&*gender=='f'&&*plural=='s'){
            printf("This word's ending is Nominative Singular Female.\n");
        }else if((last_two[1] == L'е' || last_two[1] == L'о'|| last_two[1] == L'ё')&&*gender=='n'&&*plural=='s'){
            printf("This word's ending is the Nominative Singular Neuter.\n");
            printf("This word's ending is also the Accusative Inanimate Singular Neuter.\n");
        }else if(last_two[1]==L'ы' || last_two[1]==L'и'){
            printf("This word's ending is Nominative Plural.\n");
            printf("This word is also the Accusative Inanimate Plural.\n");
        }else if((last_two[1]==L'а' || last_two[1]==L'я')&&*gender=='n'&&*plural=='p'){
            printf("This word's ending is Nominative Plural Neuter.\n");
            printf("This word's ending is also the Accusative Inanimate Plural Neuter.\n");
        }
        //Genitive case
        if((last_two[1]==L'б'||last_two[1]==L'г'||last_two[1]==L'д'||last_two[1]==L'ж'||last_two[1]==L'з'||last_two[1]==L'ж'||last_two[1]==L'к'||last_two[1]==L'ж'||last_two[1]==L'л'||last_two[1]==L'н'||last_two[1]==L'п'||last_two[1]==L'р'||last_two[1]==L'с'||last_two[1]==L'т'||last_two[1]==L'ф'||last_two[1]==L'х'||last_two[1]==L'щ'||last_two[1]==L'ц'||last_two[1]==L'ч'||last_two[1]==L'ш'||last_two[1]==L'ь')&&(*gender=='f'||*gender=='n')&&*plural=='p'){
        //Covers almost every consonant and soft sign with exceptions.
            printf("This word's ending is the Genitive Plural Female.\n");
            printf("This word's ending is also the Accusative Animate Plural Female.\n");
        }
        else if((last_two[1]==L'а'||last_two[1]==L'я')&&*gender=='m'&&*plural=='s'){
            printf("This word's ending is the Genitive Singular Male.\n");
            printf("This is also the Accusative Animate Male Singular.\n");
        }
        else if((last_two[1]==L'и')&&*gender=='f'&&*plural=='s'){
            printf("This word's ending is the Genitive Singular Female.\n");
        }
        else if((last_two[0]==L'о' && last_two[1]==L'в' || last_two[0]==L'е' && last_two[1]==L'в')){
            printf("This word's ending is the Genitive Masculine & Plural Neuter.\n");
            printf("This word is also the Accusative Animated Plural Male.\n");
        }else if (last_two[0] == L'е' && last_two[1] == L'й'){
            printf("This word's ending is Genitive Plural.\n");
        }
        //Accusative case
                else if((last_two[1] == L'у' || last_two[1] == L'ю') && *gender=='f'){ 
            printf("This word's ending is the Accusative Inanimate Singular Feminine.\n");
        }
        //Dative case
        else if((last_two[1] == L'у' || last_two[1] == L'ю')&& *gender=='m'){ 
            printf("This word's ending is the Dative Singular Male.\n");
        }
        else if (last_two[0] == L'а' && last_two[1] == L'м' || last_two[0] == L'я' && last_two[1] == L'м'){
            printf("This word's ending is Dative Plural.\n");
        }
        //Instrumental Case
        else if (last_two[0] == L'о' && last_two[1] == L'м' || last_two[0] == L'ё' && last_two[1] == L'м'){
            switch(*gender){
            case 'm':
            printf("This word's ending is Instrumental Singular Male.\n");
            break;
            case'n':
            printf("This word's ending is Instrumental Singular Neuter.\n");
            break;
            }
        }else if ((last_two[0] == L'о' && last_two[1] == L'й'|| last_two[0] == L'е' && last_two[1] == L'й'|| last_two[0] == L'о' && last_two[1] == L'ю'|| last_two[0] == L'ё' && last_two[1] == L'й' || last_two[0] == L'ь' && last_two[1] == L'ю')){ // If the last two characters are "ой", "ей", "ою" "ёй" and "ью", output this message.
            printf("This word's ending is Instrumental Singular Female.\n");
        }else if (last_two[0] == L'м' && last_two[1] == L'и'){
            printf("This word's ending is Instrumental Plural.\n");
        }else if (last_two[0] == L'е' && last_two[1] == L'м'){
            printf("This word's ending is Instrumental Neuter.\n");
        }
        //Prepositional case
        else if(last_two[1] == L'е'){ 
            switch(*gender){
            case 'm':
            printf("This word's ending is the Prepositional Singular Male.\n");
            break;
            case 'f':
            printf("This word's ending is the Prepositional Singular Female.\n");
            break;
            case 'n':
            printf("This word's ending is the Prepositional Singular Neuter.\n");
            printf("This word's ending is also the Dative Singular Neuter.\n");
            break;
            }
        }
        else if(last_two[0] == L'а' && last_two[1] == L'х' || last_two[0] == L'я' && last_two[1] == L'х'){
            printf("This word's ending is the Prepositional Plural\n");
        }
        
}

void declension_adjective(const wchar_t *word, char *gender, char *plural){
    printf("The gender is %c, and the plural is %c\n",*gender, *plural);//Debug code


        int length = wcslen(word); //Use wcslen instead of strlen because we are dealing with long characters instead of regular characters.
        wchar_t last_two[3]; // Array to store the last two characters
        wcsncpy(last_two, word + length - 2, 2); // wcsncpy is used instead of scncpy because we are dealing with wide characters. Copy the last two wide-characters into the array.
        //last_two[2] = L'\0'; // Null-terminate the string
        wprintf(L"Last two letters: %lc%lc\n", last_two[0],last_two[1]);

        //Nominative
        if((last_two[0]==L'и'&&last_two[1]==L'й'||last_two[0]==L'ы'&&last_two[1]==L'й')){
            printf("This adjective's ending is the Nominative Singular Male.\n");
            printf("This adjective's ending is also the Accusative Inanimate Singular Male.\n");

        }else if((last_two[0]==L'а'&&last_two[1]==L'я')){
            printf("This adjective's ending is the Nominative Singular Female.\n");

        }else if((last_two[0]==L'о'&&last_two[1]==L'е')){
            printf("This adjective's ending is the Nominative Singular Neuter.\n");
            printf("This adjective's ending is also the Accusative Singular Neuter.\n");

        }else if((last_two[0]==L'ы'&&last_two[1]==L'е')){
            printf("This adjective's ending is the Nominative Plural.\n");

        }
        //Genitive
        else if((last_two[0]==L'г'&&last_two[1]==L'о')){
            switch(*gender){
            case 'm':
            printf("This adjective's ending is the Genitive Male.\n");
            printf("This adjective's ending is also the Accusative Animate Male.\n");
            break;
            case 'n':
            printf("This adjective's ending is the Genitive Neuter.\n");
            break;
            }

        }else if((last_two[0]==L'о'&&last_two[1]==L'й'||last_two[0]==L'е'&&last_two[1]==L'й')){
            printf("This adjective's ending is the Genitive Singular Female.\n");
            printf("This adjective's ending is also the Dative/Instrumental/Prepositional Singular Female.\n");

        }else if(last_two[0]==L'ы'&&last_two[1]==L'х'||last_two[0]==L'и'&&last_two[1]==L'х' ){
            printf("This adjective's ending is the Genitive Plural.\n");
            printf("This adjective's ending is also the Accusative Animate & the Prepositional Plural.\n");
        }
        //Dative
        else if(last_two[0]==L'м'&&last_two[1]==L'у'){
            switch(*gender){
            case'm':
            printf("This adjective's ending is also the Instrumental Singular Male.\n");
            break;
            case 'n':
            printf("This adjective's ending is the Dative Neuter.\n");
            break;
            }
        }else if(last_two[0]==L'ы'&&last_two[1]==L'м'){
            printf("This adjective's ending is the Dative Plural.\n");
        }
        //Accusative
        else if(last_two[0]==L'у'&&last_two[1]==L'ю'){
            printf("This adjective's ending is the Accusative Female.\n");
        }
        //Instrumental
        else if(last_two[0]==L'ы'&&last_two[1]==L'м'||last_two[0]==L'и'&&last_two[1]==L'м'){
            switch(*gender){
            case'm':
            printf("This adjective's ending is the Instrumental Singular Male.\n");
            break;
            case'n':
            printf("This adjective's ending is the Instrumental Singular Neuter.\n");
            break;
            }
        }
        //Prepositional   
        else if(last_two[0]==L'о'&&last_two[1]==L'м'||last_two[0]==L'е'&&last_two[1]==L'м'){
            switch(*gender){
            case'm':
            printf("This adjective's ending is the Prepositional Singular Male.\n");
            break;
            case 'n':
            printf("This adjective's ending is the Prepositional Singular Neuter.\n");
            break;
            }
        }

}

void switch_menu(int *switch_quit, int *quit){
    *switch_quit=0;
    *quit=0;
        do{  //Do-while loop functions to ensure user inputs only 1 and 2.
        scanf("%d",&*quit);//Scan quit flag.
        switch(*quit){

            case 1:
            *quit=1;
            *switch_quit=1;
            break;
            case 0:
            *switch_quit=1;
            break;
            default:
            printf("Invalid number. Number must be 0 or 1.\n");
            printf("\nContinue program? 0=Yes, 1=No\n");
            break;
        }}while(*switch_quit!=1);
}

void main() {  
    
    int quit=0;//flag to exit the program.
    int switch_quit=0;//Flag to exit the switch statements in case 1 and 2.

    wchar_t word[MAX_SIZE];//declares a wide character instead of a regular character. If we use regular character, word would not detect any Cyrillic characters once we input it.
    setlocale(LC_ALL, "russian_russia.866"); // "russian_russia.866" Sets the locale to support the Cyrillic alphabet.
    SetConsoleOutputCP(866);//Sets the terminal's output code page to 866 which properly displays the Cyrillic alphabet.


    do{//Post-test loop for main menu to be used for a menu with an exit.
    printf("Welcome to the Russian Grammar Application!\nPress 1 for the Russian Declension for nouns\nPress 2 for Russian Declension for Adjectives\nPress 3 for Help\nPress 4 to Exit the Program.\n");
    int menu;
    scanf("%d",&menu);

    char gender;
    char plural;
    DWORD dw_read; //Declared DWORD to store the number of characters read. Used to ensure ReadConsoleW works.
    HANDLE h_stdin = GetStdHandle(STD_INPUT_HANDLE);//Gets the standard input straight from the terminal. Used to ensure ReadConsoleW works.

    //This switch statement is used to determine which menu the user wants to go to.
    switch(menu){
        case 1:
        // This code below reads the input from the console and stores it in the word array. Used instead of wscanf because wscanf does not properly read the Cyrillic alphabet.  
        wprintf(L"Type the Russian word: ");

        // 1. Calls ReadConsoleW Function 2. Debug to detect if ReadConsoleW works or not.
        if (!ReadConsoleW(h_stdin, word, MAX_SIZE - 1, &dw_read, NULL)) {
            printf("ReadConsoleW failed\n");
        }

        // This loop removes the newline character from the end of the string. Otherwise, the output would be like this;
        /*Type the Russian word: привет
    Input word: привет
    A
    Last two letters:
    A
    Привет, мир!*/
        for (int i = 0; i < MAX_SIZE; i++) {
        if (word[i] == L'\n' || word[i] == L'\r') {
             word[i] = L'\0';
             break;
            }
        }
        printf("Enter gender (m/f/n):\n");
        scanf(" %c",&gender);//Whitespace before %c to consume \n character
        printf("Enter plurality(s/p), s=singular, p=plural:\n");
        scanf(" %c",&plural);

        declension_noun(word, &gender, &plural); // Call the function to detect the word's ending.
        wprintf(L"Input word: %ls\n", word); // Check if the input word is correctly captured
        printf("\nContinue program? 0=Yes, 1=No\n");
     
        switch_menu(&switch_quit, &quit);//Switch statement that gives the user a choice to continue or exit the program.
        
        break;


        case 2:
        wprintf(L"Type the Russian word: ");
        // 1. Calls ReadConsoleW Function 2. Debug to detect if ReadConsoleW works or not.
        if (!ReadConsoleW(h_stdin, word, MAX_SIZE - 1, &dw_read, NULL)) {
        printf("ReadConsoleW failed\n");
        }
        // This loop removes the newline character from the end of the string.
        for (int i = 0; i < MAX_SIZE; i++) {
        if (word[i] == L'\n' || word[i] == L'\r') {
             word[i] = L'\0';
             break;
            }
        }
        printf("Enter gender (m/f/n):\n");
        scanf(" %c",&gender);//Whitespace before %c to consume \n character
        printf("Enter plurality(s/p), s=singular, p=plural:\n");
        scanf(" %c",&plural);
        declension_adjective(word, &gender, &plural);//Call the function to detect the adjective's ending.
        wprintf(L"Input word: %ls\n", word); // Check if the input word is correctly captured
        printf("\nContinue program? 0=Yes, 1=No\n");

        switch_menu(&switch_quit, &quit);
        break;


        case 3:
        int help;
        printf("Which specific command you want further clarification on? 1-Nouns, 2-Adjectives, 3-Exit\n");
        scanf("%d",&help);
        switch(help){
            case 1:
            wprintf(L"This specific command helps you identify which ending a noun has. This is ONLY for nouns, not adjectives.\n Example input: инженером (Engineer), руках (Hands), россиянцев(Russians).\n");
            break;
            case 2:
            wprintf(L"This specific command helps you identify which ending an adjective has.\n Example input:русском (Russian), этой(This), красывым(Beautiful), моего(My).\n");
            break;
            case 3:
            printf("Exits the program.\n");
            break;
            default:
            printf("Invalid number. Number must be between 1-3\n");
            break;
        }
        break;


        case 4:
        quit=1;
        break;


        default:
        printf("Invalid number. Number must be between 1-4\n");
        break;
    }//End of switch case
    
    
    }while(quit!=1);
}


