TUIC is currently in development by its creator: Journeyman (Daniel Valcour). Journeyman is more than willing to accept help on this project, but no one has come forward to contribute thus far.

# How to help

There are three ways you can contribute to this project in a meaningful way:

 1. Feedback is greatly appreciated, and is used as a tool to get a better idea of what to work on next. If you have a feature idea, or you have constructive criticism, please make a post in the github issues forum or join the discussions in other official channels. Read [this section](#how-to-provide-helpful-feedback) for more information.
 2. If you find a bug or are having an issue with the TUIC library, you can make a bug report in the github issues forum. This is explained in [here](#how-to-report-a-bug).
 3. Code contributions are accepted from anyone. Read [here](#how-to-make-a-pull-request) to learn how to make a pull request.
 
# How to provide helpful feedback

If you want to give feedback, you can do so in the issues forum. Be sure not to create a second issues thread if one already exists about your ideas. If you want to talk more directly, you can communicate via the official Discord server: [https://discord.gg/KbuMynmkRk](https://discord.gg/KbuMynmkRk).

# How to report a bug

If you are having an issue with TUIC, the first thing you should do is setup a debug callback function. The message sent to this callback may explain to you why something is not working the way you expect, and you may find that you don't need to post an issue after all.

Before reporting your bug, it is important for you to prepare an adequate explanation of what is going wrong. If you can, write a short and simple example program that shows the issue, and include it in your issue post. To make your code easier to read, be sure to use github markdown ticks around your code block so that it will be formated with syntax highlighting:

    ```c
    int main()
    {
        return 0;
    }
    ```
	
If you are using C++, you can do this instead:


    ```cpp
    int main()
    {
        return 0;
    }
    ```

Be sure to also include the following additional information in your issue thread:

 - Your operating system (Windows 10 64 bit, OSX, Linux Mint 32 bit, etc) and your build configuration (32 bit Debug, 64 bit Release, etc).
 - The backend you are using, and any third party windowing or graphics loading libraries.
 - The program or setup you are writing your code with, including build systems and package managers if they are relevent.

# How to make a pull request
 
 If you wish to help me with development, please speak to me first. 
