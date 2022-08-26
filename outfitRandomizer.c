/**
 * @file outfitRandomizer.c
 * @author Sean Pourgoutzidis
 * @brief This application helps to randomly select an outfit for me
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//Import statements
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function Declaration
void welcomePage();
int outfitType ();
bool printFit(char **outfit, int numComponents);
void farewellPage ();

//Main Function
int main () {

    const MAX_LENGTH = 4022;
    
    //Welcomes the user
    welcomePage();

    //User Picks their Outfit
    int outfitT = outfitType();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    //All of the clothes currently in possession classified by type
    char jackets [][MAX_LENGTH] = {{"Overshirt"}, {"Button Up"}, {"Cordurouy Overshirt"}, {"Vest"}};
    char shirts [][MAX_LENGTH] = {{"White Tee"}, {"Navy Waffle Tee"}, {"Black Tee"}, {"Purple Tee"}, {"Teal Tee"}, {"Tan Shirt"}, {"Yellow Tee"}};
    char pants [][MAX_LENGTH] = {{"Khaki Cargos"}, {"Black Chino Pants"}, {"Navy Pants"}, {"Grey Pants"}};
    char shorts [][MAX_LENGTH] = {{"Black Chino"}, {"Navy Chinos"}, {"Black Shorts"}, {"Navy Shorts"}, {"  Black Active Shorts"}};
    char shoes [][MAX_LENGTH] = {{"Black & Gold AirMax 90s"}, {"Black Huaraches"}, {"Green AirMax 90s"}, {"Green Huaraches"}, {"Navy and White Nikes"}};
    char boots [][MAX_LENGTH] = {{"Formal Timberlands"}};
    char sweaters [][MAX_LENGTH] = {{"Green Crewneck"}, {"Navy Crewneck"}, {"UofT Crewneck"}, {"Fleece"}, {"Yellow Hoodie"}, {"White Hoodie"}, {"Green Hoodie"}, {"Red Hoodie"}};
    char coats [][MAX_LENGTH] = {{"Black Puffer"}};

    //To enable the rand() function
    srand(time(NULL));

    //Controls if the user would like to roll again
    bool reroll = false;

    //Do-while iterates while the user would like to reroll their outfit
    do {

        //Random initialization of the clothing article

        char jacket [MAX_LENGTH];  
        strcpy(jacket, jackets[(rand() % (sizeof(jackets)/sizeof(jackets[0])))]);
        
        char shirt [MAX_LENGTH];
        strcpy(shirt, shirts[(rand() % (sizeof(shirts)/sizeof(shirts[0])))]);
        
        char pant [MAX_LENGTH];
        strcpy(pant, pants[(rand() % (sizeof(pants)/sizeof(pants[0])))]);

        char shortPant [MAX_LENGTH]; 
        strcpy(shortPant, shorts[(rand() % (sizeof(shorts)/sizeof(shorts[0])))]);

        char shoe [MAX_LENGTH];
        strcpy(shoe, shoes[(rand() % (sizeof(shoes)/sizeof(shoes[0])))]);
        
        char boot [MAX_LENGTH];
        strcpy(boot, boots[(rand() % (sizeof(boots)/sizeof(boots[0])))]);

        char sweater [MAX_LENGTH];
        strcpy(sweater, sweaters[(rand() % (sizeof(sweaters)/sizeof(sweaters[0])))]);
        
        char coat [MAX_LENGTH];
        strcpy(coat, coats[(rand() % (sizeof(coats)/sizeof(coats[0])))]);
    
        //Sweater Weather
        if (outfitT == 1) {
            char *outfit [3] = {sweater, pant, shoe};
            reroll = printFit(outfit, 3);
        }

        //Light Jacket w/ Shirt
        else if (outfitT == 2) {
            char *outfit [4] = {jacket, shirt, pant, shoe};
            reroll = printFit(outfit, 4);
        }

        //Light Jacket w/ Sweater
        else if (outfitT == 3) {
            char *outfit [4] = {jacket, sweater, pant, shoe};
            reroll = printFit(outfit, 4);
        }
        
        //Winter Time
        else if (outfitT == 4) {
            char *outfit [4] = {coat, sweater, pant, boot};
            reroll = printFit(outfit, 4);
        }

        //Summa Time
        else if (outfitT == 5) {
            char *outfit [3] = {shirt, shortPant, shoe};
            reroll = printFit(outfit, 3);
        }

        //Sweater w/ Shorts
        else if (outfitT == 6) {
            char *outfit [3] = {sweater, shortPant, shoe};
            reroll = printFit(outfit, 3);
        }
    
    }while (reroll);

    //Says farewell to the user
    farewellPage();
    
    return 0;
}

/**
 * @brief This funciton welcomes the user to the program
 * 
 */
void welcomePage () {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                               Welcome to........\n\n");
    printf("                                         ______   __     ______      ______   __     ______     __  __    \n");
    printf("                                        /\\  ___\\ /\\ \\   /\\__  _\\    /\\  == \\ /\\ \\   /\\  ___\\   /\\ \\/ /    \n");
    printf("                                        \\ \\  __\\ \\ \\ \\  \\/_/\\ \\/    \\ \\  _-/ \\ \\ \\  \\ \\ \\____  \\ \\  _\"-.  \n");
    printf("                                         \\ \\_\\    \\ \\_\\    \\ \\_\\     \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ \n");
    printf("                                          \\/_/     \\/_/     \\/_/      \\/_/     \\/_/   \\/_____/   \\/_/\\/_/ \n");
    printf("\n");
    printf("\n");
    printf("                                                       Please Press Enter to Continue!\n\n\n\n\n\n\n\n\n");
    printf("");
    
    char pause = 'z';
    scanf("%c", &pause);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/**
 * @brief Allows the user to pick out their outfit type for the day
 * 
 * @return The number representing the outfit type of the user
 */
int outfitType () {
    int outfitType = 0;

    printf("What type of outfit are we wearing today?\n");
    printf("-----------------------------------------\n");
    printf("1) Sweater Weather\n");
    printf("2) Light Jacket w/ Shirt\n");
    printf("3) Light Jacket w/ Sweater\n");
    printf("4) Winter Time\n");
    printf("5) Summa Time (Shorts and Tee)\n");
    printf("6) Sweater w/ Shorts \n");
    printf("\n\n");
    printf("Please pick a number from above: ");
    scanf("%d", &outfitType);

    return outfitType;
}

/**
 * @brief This funciton prints the outfit to the user and prompts them if they would like to reroll
 * 
 * @param outfit 
 * @return true 
 * @return false 
 */
bool printFit (char **outfit, int numComponents) {

    printf("Your Outfit of the Day:\n");
    printf("-------------------------------------------------\n");
    
    //Prints outfit components in bulleted list
    for (int i = 0; i < numComponents; i++) {
        printf("• ");
        puts(outfit[i]);
    }

    char input = 'z';
    printf("\nWould you like to reroll? (y/n): ");
    scanf(" %c", &input);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    if (input == 'Y' || input == 'y') {//if they want to reroll
        return true;
    }

    return false;//otherwise return false
}

/**
 * @brief This function bids the user farewell
 * 
 */
void farewellPage () {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                           Thank you for using.....\n\n");
    printf("                                         ______   __     ______      ______   __     ______     __  __    \n");
    printf("                                        /\\  ___\\ /\\ \\   /\\__  _\\    /\\  == \\ /\\ \\   /\\  ___\\   /\\ \\/ /    \n");
    printf("                                        \\ \\  __\\ \\ \\ \\  \\/_/\\ \\/    \\ \\  _-/ \\ \\ \\  \\ \\ \\____  \\ \\  _\"-.  \n");
    printf("                                         \\ \\_\\    \\ \\_\\    \\ \\_\\     \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ \n");
    printf("                                          \\/_/     \\/_/     \\/_/      \\/_/     \\/_/   \\/_____/   \\/_/\\/_/ \n");
    printf("\n");
    printf("                                                 Come back soon! Or not, we really don't care!");
    printf("\n\n\n\n\n\n\n\n\n\a");
}
