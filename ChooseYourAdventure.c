#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Most of this code uses puts() and delay() functions.
//Sometimes, I will interchange puts() and printf() if I want to print the user's name
//or when the user's name appears in dialogue

//Most of the time, I use switch functions for determining choices because in terms of run time, it's a lot faster to use than using an if-else statement.
//The only time I use if-else statements is if I need a string to match.

//Function to delay output
//That's to make sure the user has time to read the dialogue
void delay (int seconds)
{
    int ms = 1000 * seconds;
    clock_t startTime = clock();
    while (clock() < startTime + ms);
}

//Function to terminate the program.
//Used when the user reaches the end of the story in any route.
void theEnd()
{
    puts("The end!");
    exit(0);
}

int main ()
{
    //Leave the time delay constant. Two seconds is slow enough for the user to glance the dialogue.
    //The user can also re-read the dialogue once you reach a choice.
    const int DELAY = 2;
    //Strings are used as a marker when the user picks a choice.
    //They will affect the story route and the dialogues.
    //Originally, I would design the program to ask the user what they want in the first choice, but
    //that would make the code even longer than it should.
    //It will be a feature that I will implement later down the line.
    char openingChoice[20], name[11];

    //Int instances to store the input of the user.
    //1 or 2 must be entered.
    int choice;

    //Later in the story, the user will need to input the password.
    //Initialized so I don't get confused.
    int password;
    //Create a boolean instance to initiate a loop
    bool isBellAlive, finished = false, finishedLast = false;
    //I initialized a boolean when it prompts the user to input a password so I don't get confused if I'm using a choice boolean or a password boolean.
    bool riddleSolved = false;

    //Welcomes the user.
    puts("Before we start, enter your name (Enter no more than 10 characters).");
    //In case someone exceeds the character limit, I set it to prompt the user to keep entering names until a name with a valid number of characters is reached.
    while (!finished)
    {
        //I want to avoid white spaces by using the gets() function. It breaks the code if a white space is entered using scanf().
        gets(name);
        if (strlen(name) < sizeof(name))
        {
            //Easter egg 1.
            if (strcasecmp(name, "Rekha") == 0 || strcasecmp(name, "Rani") == 0)
            {
                puts("Hey professor!");
                finished = true;
            }
            //These name cannot be chosen because they are also names of several characters you'll meet in the story.
            else if (strcasecmp(name, "Ionamp") == 0)
            {
                puts("There\'s a possibility that the name you picked could a potential partner\'s name.");
                delay(DELAY);
                puts("In other words, please pick a different name.");
            }
            else if (strcasecmp(name, "Amelia") == 0)
            {
                puts("My foretelling powers tell me you share the same name as another adventurer we\'ll meet in the future.");
                delay(DELAY);
                puts("What I\'m saying is to please pick a different name.");
            }
            else if(strcasecmp(name, "Bell") == 0)
            {
                printf("That name sounds like a traitor.\n", name);
                delay(DELAY);
                puts("Please pick a different name. A certain someone is scared of traitors.");
            }
            else if(strcasecmp(name, "Vails") == 0)
            {
                printf("%s? Why does your name sound so menacing?\n", name);
                delay(DELAY);
                puts("Please pick a different name unless you want to be a main villain (You can\'t for now).");
            }
            //Default option.
            else
            {
                //AS I stated in an earlier comment, I used printf since i need to display the user's name.
                printf("Welcome, %s.\n", name);
                finished = true;
            }
        }
        else
        {
            puts("Name exceeds character limit.");
        }
    }
    finished = false;
    delay(DELAY);
    puts("Let\'s get started.");
    delay(DELAY);
    //Opening
    puts("You can\'t even remember the last time you looked forward to tomorrow.");
    delay(DELAY);
    puts("Everyday is the same humdrum tasks over and over again: wake up; alternate between eating, working, and wasting time; go to sleep.");
    delay (DELAY);
    puts("Some say life is all about the mundane, that it\'s the most normal of days in which you find the most dear.");
    delay(DELAY);
    puts("But what\'s so dear about normal days when it seems like your whole life is just one big normal day?");
    delay(DELAY);
    puts("Where did the exciting days, the passionate days, the joyful days, which were so abundant before, run off to?");
    delay(DELAY);
    puts("Well...");
    delay(DELAY);
    puts("What if I said they will come bounding back to you if you just step out of the prison constructed by your fear?");
    delay(DELAY);
    puts("All you have to do is focus on what you want the most:");
    puts("1. love");
    puts("2. self-actualization");
    //Goes on a loop until the user has inputted a valid option.
    while (!finished)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //Option 1 has been chosen.
            strcpy(openingChoice, "love");
            finished = true;
            break;
        case 2: //Option 2 has been chosen.
            strcpy(openingChoice, "self-actualization");
            finished = true;
            break;
        default: //User inputs an invalid option (User inputs a number that is neither 1 or 2).
            puts("Invalid option.");
        }
    }
    //Finished boolean resets to false once the loop is exited for further reuse of the variable.
    finished = false;
    printf("So it is %s that you desire?\n", openingChoice);
    delay(DELAY);
    puts("Very well.");
    delay(DELAY);
    puts("You feel a little tingle in the back of your head.");
    delay(DELAY);
    puts("You start to open your eyes, ready for what the voice promised you, ready for the vibrant fantasy worlds you\'ve read about when you were younger...");
    delay(DELAY);
    puts("Your heart plummets straight down.");
    delay(DELAY);
    puts("All you can see is a bright, cloudy sky, the perfect backdrop for the nothing in front of you.");
    delay(DELAY);
    puts("You take a step forward in desperation.");
    delay(DELAY);
    puts("Surely...Ouch! You trip over something the most annoyingly sized.");
    delay(DELAY);
    puts("It looks to be a sleeping fairy?");
    delay(DELAY);
    puts("You just stepped on a magical fairy.");
    delay(DELAY);
    puts("What do you do?");
    delay(DELAY);
    puts("1. It could blast you with its magical fairy powers. Run away! You\'ll find another way to get what you\'re looking for.");
    puts("2. What else are you going to do? Talk to some dirt? Befriend it! Maybe you\'ll find what you\'re looking for.");
    //Like the first loop, these choice loops will function similarly.
    while (!finished)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            puts("You carefully tiptoe away.");
            delay(DELAY);
            puts("Maybe it won\'t notice you just stepped on it three seconds ago.");
            delay(DELAY);
            puts("Fairy: \"(Yawwwn) I just had the strangest dream: I was out playing with some fireflies, but then a big, fat, smelly ogre just came out of nowhere and stepped on me!\"");
            delay(DELAY);
            puts("She turns around, eyes wide when she sees you.");
            delay(DELAY);
            puts("Fairy: \"AHHH!\"");
            delay(DELAY);
            puts("Fairy: \"AN OGRE!\"");
            delay(DELAY);
            puts("Fairy: \"Wait a second.\"");
            delay(DELAY);
            puts("Fairy: \"You\'re WAY too small to be an ogre.\"");
            delay(DELAY);
            puts("Fairy: \"Although...\"");
            delay(DELAY);
            puts("Fairy: \"Sorry, just some bad dreams from a bit before.\"");

            finished = true;
            break;
        case 2:
            puts("You greet it and apologized to it for stepping on you.");
            delay(DELAY);
            puts("It slowly open its eyes.");
            delay(DELAY);
            puts("A bit TOO slow in fact.");
            delay(DELAY);
            puts("Maybe you damaged it.");
            delay(DELAY);
            puts("Fairy: \"Yawwwn\"");
            delay(DELAY);
            puts("Fairy: \"Why is there a shoe mark on my clothes!?\"");
            delay(DELAY);
            puts("The fairy frantically glances around.");
            delay(DELAY);
            puts("Fairy: \"YOU! Did you do this? It looks amazing! Wow! Thank you so much for adding this amazing design.\"");
            delay(DELAY);
            puts("Fairy: \"Now I look cool and dangerous instead of just a cute little fairy. Yay!\"");
            delay(DELAY);
            puts("You felt a slight relief, as you thought the fairy will do something bad to you.");
            finished = true;
            break;
        default:
            puts("Invalid option.");
        }
    }
    //Reset finished boolean to false.
    finished = false;
    delay(DELAY);
    puts("Ionamp: \"Anyways, my name is Ionamp.\"");
    delay(DELAY);
    puts("You tell her your name.");
    delay(DELAY);
    //Easter egg 2
    if(strcasecmp(name, "Paimon")== 0)
    {
        puts("Ionamp: \"That\'s my best friend\'s name!\"");
        delay(DELAY);
        puts("Ionamp: \"What a coincidence. I like you already.\"");
    }
    else
    {

        printf("Ionamp: \"%s. Hm. Your name needs some work!\"\n", name);
        delay(DELAY);
        puts("Ionamp: \"That\'s it! I have decided you will be my apprentice!\"");
    }
    delay(DELAY);
    puts ("With nothing better to do in this desolate wasteland, you let Ionamp lead you around.");
    delay(DELAY);
    puts("Ionamp: \"First things first, we have to get you some better clothes!\"");
    delay(DELAY);
    puts("She flies towards you, foot first. You feel a small smack on your cheek, and all your senses seem to stop working.");
    delay(DELAY);
    delay(DELAY);
    puts("As your senses slowly come back, you already can feel the dull drone of Ionamp lecturing...");
    delay(DELAY);
    puts("Ionamp: \"...And that\'s why you should be thankful I decided to nap there.\"");
    delay(DELAY);
    puts("However, you weren\'t really listening. Somehow, your brain has already figured out how to filter Ionamp\'s rambling.");
    delay(DELAY);
    puts("What you were focused on is the hustle and bustle of the city gates, each person seems to be walking with such intense purpose.");
    delay(DELAY);
    puts("You asked where we are.");
    delay(DELAY);
    puts("Ionamp: \"We\'re at Monste! The best place to find a suitable outfit that is befitting of Ionamp\'s apprentice!\"");
    delay(DELAY);
    puts("Out of the blue, you see a young woman sprint-walk to you, eyes full of zeal,\nlike she just saw an iPhone 12 being sold for $200 on Black Friday, but she has to push through a sea of people to get to it.");
    delay(DELAY);
    puts("Amelia: \"He-Hello there, traveler! My name is Amelia. You look like you are in need of help. What's your name?\"");
    delay(DELAY);
    puts("Ionamp: \"See. I told you you need some new clothes.\"");
    delay(DELAY);
    puts("Ignoring Ionamp, you give the lady your name.");
    delay(DELAY);
    printf("Amelia: \"%s, you say? That name sounds foreign. You must be an outsider.\"\n", name);
    delay(DELAY);
    puts("Amelia: \"About your sassy fairy companion, what's up with her?\"");
    delay(DELAY);
    //Hope someone gets this reference.
    puts("1. She\'s a mascot.");
    puts("2. She\'s emergency food.");
    while (!finished)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            puts("Ionamp: \"Hey! That's worse than being emergency food!\"");
            delay(DELAY);
            puts("Ionamp: \"Oh, they grow up so fast! Already thinking he's too cool for me.\"D:");
            finished = true;
            break;
        case 2:
            puts("Ionamp: \"Hey! That's worse than being a mascot!\"");
            delay(DELAY);
            puts("Ionamp: \"Oh, they grow up so fast! Already thinking he's too cool for me.\" D:");
            finished = true;
            break;
        default:
            puts("Invalid option.");
        }
    }
    //Reset boolean variable.
    finished = false;
    delay(DELAY);
    puts("Amelia: \"Haha, that's hilarious.\"");
    delay(DELAY);
    puts("Amelia: \"Anyways. I'm an adventurer, so it's my job to help people in need like you two!\"");
    delay(DELAY);
    puts("Ionamp: \"Wait! He's the one-\"");
    delay(DELAY);
    puts("Amelia: \"Woohoo! Then it\'s settled. Let\'s go!\"");
    delay(DELAY);
    puts("Ionamp: \"Woo.Hoo.\"");
    delay(DELAY);
    puts("You, Amelia, and Ionamp journey together in this world for about a couple of days.");
    delay(DELAY);
    puts("Or perhaps weeks. Possibly months.");
    delay(DELAY);
    puts("It's not possible to tell the time when everyday is fresh and exciting.");
    delay(DELAY);
    puts("During that time, you got to know one another and even perhaps teased Ionamp about being eating her at some point.");
    delay(DELAY);
    //Dialogue path based on opening choice.
    if (strcmp(openingChoice, "love") == 0)
    {
        puts("You start to develop possible feelings for Amelia.");
        delay(DELAY);
        puts("You\'ve always admired how willing she is to help others.");

    }
    else
    {
        puts("The time you\'ve spent with them almost made you realize what you came to this world for.");
    }
    delay(DELAY);
    puts("One day, while traveling to the hills, you meet a strange person wearing a mask.");
    delay(DELAY);
    puts("He\'s well armed with a sword and looks like he will strike you if you approach him.");
    delay(DELAY);
    puts("Amelia and Ionamp can the danger in the air as well.");
    delay(DELAY);
    puts("Both Amelia and Ionamp: \"What do you think?\"");
    delay(DELAY);
    puts("1. Attack the stranger head on.");
    puts("2. Try to ignore the stranger and walk past him peacefully.");
    while (!finished)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            puts("You and Amelia get your weapons ready while Ionamp gets ready for magical fairy pewpews.");
            delay(DELAY);
            puts("You charge at the stranger with Amelia right beside you and Ionamp having your back. You won't let anyone destroy what you\'ve built up.");
            delay(DELAY);
            puts("Caught off guard, the stranger sloppily parries your attack, but fell victim to Amelia, and she knocks him out.");
            delay(DELAY);
            finished = true;
            break;
        case 2:
            //Bad ending number 1.
            puts("You and your group attempt to bypass the stranger. Maybe the stranger is just in an attack stance to look cool. As Ionamp always says, \"You gotta look cool for every occasion!\"");
            delay(DELAY);
            puts("At your dismay, right as Amelia, you, and Ionamp were about to walk past him, he turns around and attacks, striking Amelia, the closest one to him.");
            delay(DELAY);
            puts("You could feel the life draining out of her as if you were the one stabbed.");
            delay(DELAY);
            puts("You glare at the stranger, the guilt of being unable to protect and the pain of loss apparent in your eyes.");
            delay(DELAY);
            puts("Stranger: \"I...I... was just following orders. I'm sorry!");
            delay(DELAY);
            puts("He runs away, eyes glued to the ground, like a coward.");
            delay(DELAY);
            puts("Revenge comes later. You have to say a proper goodbye first.");
            delay(DELAY);
            puts("You hold her in your arms, and your eyes soften as the feeling of losing a friend that has shared the pinnacle of your life with you washes over your heart.");
            if (strcmp(openingChoice, "love") == 0)
            {
                delay(DELAY);
                puts("What hurts more is the potential future of love that can never be realized.");
            }
            delay(DELAY);
            puts("She looks at you, and smiles.");
            delay(DELAY);
            puts("Amelia: \"You looked so cool glaring at him like that... Your 'master' taught you well...haha...\"");
            delay(DELAY);
            puts("She closes her eyes, and the last of her moves on to a better place.");
            delay(DELAY);
            puts("Enraged, saddened, and frustrated, you black out.");
            delay(DELAY);
            puts(".");
            delay(DELAY);
            puts(".");
            delay(DELAY);
            puts(".");
            delay(DELAY);
            puts("You open your eyes to see the same old room before your epic journey.");
            delay(DELAY);
            puts("You\'ve never felt so alone in your life.");
            delay(DELAY);
            theEnd();
            finished = true;
            break;
        default:
            puts("Invalid option.");
        }
    }
    //Reset boolean variable.
    finished = false;
    puts("With Ionamp\'s magic string, she ties the masked stranger up, preventing even the thought of escape.");
    delay(DELAY);
    puts("You asked why the stranger tried to attack your group.");
    delay(DELAY);
    puts("Stranger: \"Heh. You think I\'m that easy? I\'m not telling you a single thing.\"");
    delay(DELAY);
    puts("Amelia: \"We have to make him talk. He was going to attack us. I could feel it.\"");
    delay(DELAY);
    puts("Amelia: \"We have to figure out why.\"");
    delay(DELAY);
    puts("You asked how you will be able to do that.");
    delay(DELAY);
    puts("Amelia: \"Well, I can try to bribe him. I\'ve come across lots of people like him. All we need is something he wants.\"");
    delay(DELAY);
    puts("Ionamp: \"I\'m a cool, stylish fairy, so naturally I have ways of making people look very, very uncool.\"");
    delay(DELAY);
    puts("If there's one thing you\'ve learned while traveling with them, it\'s that they are both very capable.");
    delay(DELAY);
    puts("So the hard question is, who's method should you use?");
    delay(DELAY);
    puts("1. I should follow Amelia's idea.");
    puts("2. I should follow Ionamp's idea.");
    while(!finished)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            puts("You slightly hesitated at first, but you decided to go with Amelia\'s suggestion.");
            delay(DELAY);
            puts("Amelia: \"Perhaps there is something that I can give you in exchange.\"");
            delay(DELAY);
            puts("You notice a strange hunger flash in the stranger's eyes.");
            delay(DELAY);
            puts("Stranger: \"Wh-What are you talking about?\"");
            delay(DELAY);
            puts("Amelia slowly reaches into her backpack, and pulls out a small, red box.");
            delay(DELAY);
            puts("Amelia: \"That\'s right, pocky.\"");
            delay(DELAY);
            puts("Amelia: \"She waves the pocky tantalizingly in front of the stranger's eyes.\"");
            delay(DELAY);
            puts("Amelia: \"Now tell me eeeeverything you know...\"");
            delay(DELAY);
            puts("The stranger's bulging eyes could not stop following the little, red box.");
            delay(DELAY);
            puts("Stranger: \"M-m-my name is Bell, a-a-and I was sent by the Demon Lord. PLEASE GIVE ME THE POCKY NOW.\"");
            delay(DELAY);
            puts("Amelia smiles slightly.");
            delay(DELAY);
            puts("Amelia: \"That's all you need to tell us.\"");
            delay(DELAY);
            finished = true;
            break;
        case 2:
            puts("You hesitated at first, but you decide to go with Ionamp\'s suggestion.");
            delay(DELAY);
            puts("Ionamp smiles wide innocently as she flies towards the stranger, hands outstretched.");
            delay(DELAY);
            puts("Stranger: \"Wait, what are your do-\"");
            delay(DELAY);
            puts("The peaceful chirping of the birds abruptly go silent as the stranger's scream cuts through the air.");
            delay(DELAY);
            puts("Stranger: \"AHHHHHH! PLEASE MAKE IT STOP. I'LL TELL YOU EVERYTHING.\"");
            delay(DELAY);
            puts("Ionamp: \"Hehe. That was easier than I thought. I\'ve always wanted to do something cool like that.\"");
            delay(DELAY);
            puts("The stranger seems to have finally caught his breath.");
            delay(DELAY);
            puts("Stranger: \"M-m-my name is Bell, a-a-and I was sent by the Demon Lord.\"");
            delay(DELAY);
            puts("Ionamp: \"Perfect!\"");
            delay(DELAY);
            finished = true;
            break;
        default:
            puts("Invalid option.");

        }
    }
    //Reset boolean variable.
    finished = false;
    puts("Bell: \"And another thing... You guys are really strong, and I don\'t want to be his slave anymore.\"");
    delay(DELAY);
    puts("Bell: \"Please. Can I join you?\"");
    delay(DELAY);
    puts("How shall you deal with Bell?");
    delay(DELAY);
    puts("1. Kill him. Death is the fate of anyone who dares hurt you and your group.");
    puts("2. Accept his plea. He might have some useful information.");
    while(!finished)
    {
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            puts("You pull out your sword.");
            delay(DELAY);
            puts("Bell: \"No please, I-\"");
            delay(DELAY);
            puts("You drive your sword through Bell's beating heart.");
            delay(DELAY);
            puts("Well. It WAS beating.");
            isBellAlive = false;
            finished = true;
            break;
        case 2:
            //will lead to bad ending number 2.
            puts("You pull out your sword.");
            delay(DELAY);
            puts("Bell: \"No, wait-\"");
            delay(DELAY);
            puts("You cut the enchanted string tying Bell up.");
            delay(DELAY);
            puts("Bell lets out a huge sigh of relief. ");
            delay(DELAY);
            puts("Bell: \"Thank you.\"");
            delay(DELAY);
            puts("You give Bell a hand up.");
            delay(DELAY);
            puts("You: \"Let's do this.\"");
            isBellAlive = true;
            finished = true;
            break;
        default:
            puts("Invalid option");

        }
    }
    //Reset boolean variable.
    finished = false;
    delay(DELAY);
    if (!isBellAlive)
    {
        puts("You, Amelia, and Ionamp head towards the gate of the demon lord\'s castle.");
        delay(DELAY);
        puts("Someone so vile should not be allowed to do as he pleases.");
        delay(DELAY);
        puts("The gate is locked by a passcode.");
        delay(DELAY);
        puts("Ionamp: \"Isn\'t the password based off his name?\"");
        delay(DELAY);
        puts("Amelia: \"Yeah... he told us that right before you killed him.\"");
        delay(DELAY);
        puts("Enter the password: (Hint: A or a = 1, B or b = 2, ..., Z or z = 26. Bell represented by numbers must be: )");
        //A different boolean variable is used.
        while (!riddleSolved)
        {
            //A different int variable is used too.
            scanf("%d", &password);
            if (password == 251212)
            {
                puts("Amelia: \"Bingo!\"");
                riddleSolved = true;
            }
            else
            {
                puts("Amelia: \"Nope. That password doesn't work.\"");
            }
        }
        delay(DELAY);
        puts("You and your group walk through the gate into a grandiose but empty room. It reminds you of the emptiness you saw and felt when you first arrived here.");
        delay(DELAY);
        puts("Before you could even wonder why there aren\'t any guards, a masked stranger appears. Again. These guys sure love their masks.");
        delay(DELAY);
        puts("Stranger: \"Ah, so you must be the people who killed one of my important subordinates.\"");
        delay(DELAY);
        puts("Stranger: \"Such a shame that I don\'t get to deal with his weakness myself.\"");
        delay(DELAY);
        puts("The stranger said \"weakness\" with such disgust that a glistening light flew from his mouth on to the floor.");
        delay(DELAY);
        puts("The servant takes off the mask.");
        delay(DELAY);
        puts("Amelia: \"Lord Valis?\"");
        delay(DELAY);
        printf("Lord Vails: \"Why yes %s, Amelia, and Ionamp, I\'ve been watching you through Bell all along.\"\n", name);
        delay(DELAY);
        //Dialogue path based on opening choice.
        delay(DELAY);
        //Dialogue path based on opening choice.
        if(strcmp(openingChoice, "love") == 0)
        {
            puts("Lord Vails: \"I\'d hate to destroy the people you love. Oh, did I say 'hate'? I meant enjoy every last second of it.\"");
        }
        else
        {
            puts("Lord Vails: \"I\'d hate to destroy whatever self-actualization and progress you\'ve gained. Oh, did I say 'hate'? I meant enjoy every last second of it.\"");
        }
        delay(DELAY);
        puts("He smiles as evil final bosses do when they\'ve just finished their monologue.");
        delay(DELAY);
        puts("You, Amelia, and Ionamp brandish your weapons.");
        delay(DELAY);
        puts("Lord Vails: \"Come. The more you struggle. The more I feast. That is the only reason why you are here.\"");
        delay(DELAY);
        puts("You and Amelia attempt to strike Lord Vails, while Ionamp strengthens you and Amelia with her blessings.");
        delay(DELAY);
        puts("However, without even batting an eye at anyone else, Lord Valis directs his sword and hunger to you.");
        delay(DELAY);
        puts("You block the attack with your sword just in time to only be knocked back a few feet.");
        delay(DELAY);
        puts("Amelia, recognizing Lord Valis\'s mistake, decisively goes in for a backstab, dealing moderate damage.");
        delay(DELAY);
        puts("Lord Vails: \"Arrgh! That hurts.\"");
        delay(DELAY);
        puts("You really don\'t care Lord Vails was hurt, but evil bosses and their need for announcing every little thing that happens to them.");
        delay(DELAY);
        puts("Channeling his pain into strength, Lord Valis gets in position to unleash a devastating attack.");
        delay(DELAY);
        puts("Ionamp: \"This isn\'t good! I can already feel the energy he\'s gathering for this.\"");
        delay(DELAY);
        printf("Amelia: \"Quick, %s. What shall we do?\"\n", name);
        delay(DELAY);
        puts("1. Go all in for the blow.");
        puts("2. Prepare for defense.");
        while(!finished)
        {
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                //Bad ending number 3.
                puts("You and Amelia attempt a charge sword-first before Lord Valis could strike.");
                delay(DELAY);
                puts("Lord Vails: \"Heh. Was that supposed to stop my ultimate move? Pathetic! Little do you know I have spent years collecting...\"");
                delay(DELAY);
                delay(DELAY);
                delay(DELAY);
                puts("Your brain helpfully tunes Lord Valis\'s monologue out.");
                delay(DELAY);
                puts("Lord Vails: \"That is why, you will never defeat me!\"");
                delay(DELAY);
                puts("Lord Vails carries out a calculated dance of unrelenting steel, decimating you, Amelia, and even Ionamp.");
                delay(DELAY);
                theEnd();
                finished = true;
                break;
            case 2:
                puts("You and Amelia use your swords to block Lord Vails\'s incoming attacks while Ionamp shields the two of you, leaving you all only moderately injured.");
                delay(DELAY);
                puts("Lord Vails: \"I see you were quite smart to block my attack.\"");
                delay(DELAY);
                puts("Lord Vails: \"Perhaps I shouldn\'t have used my strongest attack first.\"");
                delay(DELAY);
                puts("Lord Vails: \"You do not know how long I have been waiting for this moment...Ever since you accepted my offer, I was already watching, waiting for you to be ripe...\"");
                delay(DELAY);
                puts("Lord Vails: \"...\"");
                delay(DELAY);
                puts("Your brain helpfully tunes Lord Valis\'s monologue out.");
                delay(DELAY);
                puts("Lord Vails: \"...\"");
                delay(DELAY);
                puts("Lord Vails: \"HAHA. AND NOW THE FINAL BATTLE.\"");
                delay(DELAY);
                puts("Lord Vails: \"I  W I L L  S E E  T H E  F R U I T S  O F  M Y  L A B O R.\"");
                delay(DELAY);
                puts("You and Amelia, with the aid of Ionamp, continue to battle Lord Vails, trading blow after blow.\"");
                delay(DELAY);
                puts("However, each time the battle slows, your mind races.");
                delay(DELAY);
                puts("What are you doing here? Can you even defeat such a strong opponent? Maybe it\'s just easier to not want to defeat him, so you can just leave.");
                delay(DELAY);
                puts("Maybe it\'s just easier to not want anything, so you don\'t have to do anything.");
                delay(DELAY);
                if (strcmp(openingChoice, "love") == 0)
                {
                        puts("No... You can\'t leave. You want to be someone strong enough to protect Amelia, to protect anyone you cared about.");
                        delay(DELAY);
                        puts("With that realization, you land a decisive strike on to Lord Valis.");

                }
                else
                {
                        puts("No... You can\'t just leave. You\'d be breaking your promise to yourself. What would the ideal version of yourself do in this situation?");
                        delay(DELAY);
                        puts("Mind clear with the answer to that question, you land a decisive strike on to Lord Valis.");
                }
                delay(DELAY);
                printf("Lord Vails: \"%s, you put up quite a good show.\"\n", name);
                delay(DELAY);
                puts("Lord Vails: \"Never have I ever enjoyed such a battle for a millenium.\"");
                delay(DELAY);
                puts("Perhaps if you can let me live, I\'ll leave you and your friends alone.");
                delay(DELAY);
                puts("1. Kill the demon lord.");
                puts("2. Spare the demon lord.");
                //I cannot reset the finished boolean variable to false since it's still being used.
                //So that's where the finishedLast boolean comes into play.
                //The choice variable however can still be used.
                while (!finishedLast)
                {
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        //The good ending.
                        puts("With no remorse, you kill Lord Vails.");
                        delay(DELAY);
                        puts("With Ionamp's help, your group teleports outside the castle.");
                        delay(DELAY);
                        puts("Ionamp: \"We did it!\"");
                        delay(DELAY);
                        puts("Amelia: \"It\'s finally over.\"");
                        delay(DELAY);
                        //Dialogue path based on opening choice.
                        if (strcmp(openingChoice, "love") == 0)
                        {
                            puts("You look at Amelia nervously.");
                            delay(DELAY);
                            puts("And tell her what you\'ve been dying to tell her since you\'ve realized what you wanted was right in front of you.");
                            delay(DELAY);
                            puts("You\'re not going to make the same mistake again.");
                            delay(DELAY);
                            puts("Amelia blushes a little and looks down at her feet.");
                            delay(DELAY);
                            puts("Realizing the bond she shares with you, she accepts your confession.");
                        }
                        else
                        {
                            puts("You feel on top of the world.");
                            delay(DELAY);
                            puts("No...you feel on top of yourself. Like you are in full control of who you want to be.");

                        }
                        delay(DELAY);
                        printf("The thing you wanted has been earned: %s.\n", openingChoice);
                        delay(DELAY);
                        puts("The fake promise the Demon Lord gave you was fulfilled by your own doing.");
                        delay(DELAY);
                        puts("You, Amelia, and Ionamp lived happily ever after.");
                        delay(DELAY);
                        puts("Ionamp: \"Well, sort of.\"");
                        delay(DELAY);
                        theEnd();
                        finishedLast = true;
                        break;
                    case 2:
                        //Ambiguous ending, but the user assumes it's a bad ending.
                        puts("You put away your sword and leave Lord Vails to be...");
                        delay(DELAY);
                        delay(DELAY);
                        delay(DELAY);
                        delay(DELAY);
                        puts("which gives him just enough time to muster strength for his last trick.");
                        delay(DELAY);
                        printf("Lord Vails: \"Thank you very much, %s.\"\n", name);
                        delay(DELAY);
                        puts("Lord Vails: \"However, there\'s one condition.\"");
                        delay(DELAY);
                        puts("Ionamp: \"What do you mean?\"");
                        delay(DELAY);
                        puts("Amelia: \"Yeah, what more could you want after we\'ve spared your life?\"");
                        delay(DELAY);
                        puts("Suddenly, Lord Vails snaps his fingers and teleports Amelia away from the castle, presumably her home.");
                        delay(DELAY);
                        puts("Lord Vails: \"You and your little fairy companion will have to serve with me for the rest of your life.\"");
                        delay(DELAY);
                        puts("Lord Vails: \"Don\'t worry, you\'ll get some food for being good little servants.\"");
                        delay(DELAY);
                        puts("Ionamp: \"Hey, that\'s not fair!\"");
                        delay(DELAY);
                        puts("Lord Vails: \"Well sometimes, life isn\'t fair.\"");
                        delay(DELAY);
                        puts("The chains on your hands click.");
                        delay(DELAY);
                        delay(DELAY);
                        delay(DELAY);
                        delay(DELAY);
                        delay(DELAY);
                        puts("As the realization of \"forever\" hits you, a wave of despair washes through your entire being.");
                        delay(DELAY);
                        //Dialogue path based on opening choice.
                        if (strcmp(openingChoice, "love") == 0)
                        {
                            puts("You thought about Amelia.");
                            delay(DELAY);
                            delay(DELAY);
                            delay(DELAY);
                            puts("With the fact that you\'ll never going to see her again.");
                            delay(DELAY);
                            puts("You thought this is what you get for doing something good.");
                            delay(DELAY);
                            puts("A tear born of frustration squeezes itself out.");
                        }
                        else
                        {
                            puts("You thought what\'s so different about this life from your previous life.");
                            delay(DELAY);
                            puts("Working for someone else. For the promise of something always far ahead of you.");
                            delay(DELAY);
                            puts("And when you get it, it\'s the same thing all over again.");
                            delay(DELAY);
                            puts("Even worse is all that you\'ve become was reduced to nothing in an instant.");
                        }
                        delay(DELAY);
                        puts("And you don\'t even know what Lord Vails will do to you.");
                        delay(DELAY);
                        puts("Sure Ionamp can use their powers, but Lord Vails is not affected by fairy magic.");
                        delay(DELAY);
                        printf("Lord Vails: \"Come, %s. We got a lot of work to do.\"\n", name);
                        delay(DELAY);
                        theEnd();
                        finishedLast = true;
                        break;
                    default:
                        puts("Invalid choice.");
                    }
                }
                finished = true;
                break;
            default:
                puts("Invalid choice.");
            }
        }
    }
    else
    {
        //Bad ending number 2.
        puts("You, Amelia, Ionamp, and Bell head towards the gate of the demon lord\'s castle.");
        delay(DELAY);
        puts("However, the gate is locked by a passcode.");
        delay(DELAY);
        puts("Bell: \"The password is based off my name.\"");
        delay(DELAY);
        puts("Amelia: \"Uh... Why is the password to the demon lord\'s castle based off YOUR name?\"");
        delay(DELAY);
        puts("Bell blushes and runs away out of embarrassment.");
        delay(DELAY);
        puts("Amelia: \"Uh... Okay then, let\'s just head in and ignore that.\"");
        delay(DELAY);
        puts("As you walk in, you feel a chill crawling underneath your skin. Something\'s not right.");
        delay(DELAY);
        puts("Ionamp: \"Hellooo? Anybody home?\"");
        delay(DELAY);
        puts("Bell appears out of nowhere and stabs you in the hip.");
        delay(DELAY);
        puts("Amelia: \"Bell, what the-\"");
        delay(DELAY);
        puts("Amelia was cut off by an explosive projectile hitting the gate, blocking the path.");
        delay(DELAY);
        puts("A swarm of figures rush into the room, attacking from all angles.");
        delay(DELAY);
        puts("Amelia tries to pull you to safety while Ionamp wards off the servants.");
        delay(DELAY);
        printf("Amelia: \"Hang in there, %s.\"\n", name);
        delay(DELAY);
        puts("Amelia ties a cloth around your waist in a futile effort to stop the bleeding.");
        delay(DELAY);
        printf("Ionamp: \"Please %s, don\'t give up on us yet.\"\n", name);
        delay(DELAY);
        puts("One of the demon lord\'s servants head towards Bell.");
        delay(DELAY);
        puts("The masked servant to Bell: \"Get up, my friend. It\'s time for your justice to be served.\"");
        delay(DELAY);
        puts("While Amelia was attending to you and Ionamp was warding off the servants, Bell sneaks in and hits Amelia with his sword, causing her to black out.");
        delay(DELAY);
        puts("Ionamp, seeing that this battle cannot be won, teleports to safety.");
        delay(DELAY);
        puts("All you can do is lay there, sprawled on the ground, half dead.");
        delay(DELAY);
        printf("Bell: \"Hey %s, don\'t take this too personally.\"\n", name);
        delay(DELAY);
        puts("He inspects his bloodied daggers and scoffs.");
        delay(DELAY);
        puts("Bell: \"Kinda was your fault for putting too much trust in me.\"");
        delay(DELAY);
        puts("Bell effortlessly finishes you off.");
        delay(DELAY);
        puts("The masked servant takes off his mask; it is demon lord Vails himself, the orchestrator who \"invited\" you into this world.");
        delay(DELAY);
        puts("Lord Vails: \"You did a great job baiting them, Bell.\"");
        delay(DELAY);
        puts("Bell: \"Thank you, my lord. I needed to finish the job.\"");
        delay(DELAY);
        puts("Lord Vails: \"Come Bell, a feast on a foreign soul is sure to delight.\"");
        delay(DELAY);
        theEnd();
    }

    return 0;
}
