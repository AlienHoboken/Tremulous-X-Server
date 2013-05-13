Tremulous X Server
==================
Here lies the source code for the very popular X gameplay mod for Tremulous.

The X mod has existed for over 5 years, and has been one of the highest ranking servers in the entire game throughout its existence, I cannot remember a time it was not in the top 5 ranks.

Following is information on running this mod.

Extra Dependencies
-----------------------
The X QVM depends on MySQL/MySQL development libraries. Ensure these are installed before attempting to build.

Building
-----------------------
You can build the X QVM the same way you build normally.

Make sure that the `MAKE_GAME_QVM` flag is set in the Makefile before building.

As normal there are shell scripts for building on Windows and Mac OSX. Windows requires MingW be used.

Disable MySQL before building if you do not wish to use the MySQL offerings of the X mod.

Configuration
-----------------------
If you are using the MySQL offerings, you will also need to specify your credentials in the server's config file.

Running
-----------------------
The X QVM requires the xserverx customized tremulous dedicated server to run. You can find the code for this server here: https://github.com/AlienHoboken/Tremulous-xserverx-tremded

Furthermore, when running the X mod will attempt to communicate with a MySQL database. Make sure you disable MySQL if you do cannot support this behavior.

Branches
-----------------------
The development branch contains upcoming features that have not been deemed stable for use in the server yet.

Contributing
-----------------------
If you wish to contribute, please fork the branch you wish to work on, make your changes, and submit a pull request for review.

Also, please report all bugs you encounter!
