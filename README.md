# ratatouille
Rattish interpreter written in c++, for linux and windows machines. This is first 100% feacherfull implementation of RATTISH v1.0. For guide how to start writting something in rattish see https://github.com/Sarverott/rattish-manuals
```
@@@@@@@@@@@@@@%*======+++*#%%%=-:=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
@@@@@@@@@@%#*+=-------===*###+--:=@@@@@@@@@@@@@@@@@@@@@@%%##********=----+@@@@@@@@@@@@@@@%
@@@@@@@@%#=--::-::------=+**+---:+@@@@@@@@@@@@@@@@%*+===++**#######*:....-*##%@@@@@@@@@@@%
@@@@@@#+=-:::::::::::---=+++=--:=*@@@@@@@@@@                                      @@@@@@@%
@@@@%*-:::::::::::::::--===+=:=+*#@@@@@@@@   ░█▀▄░█▀█░▀█▀░█▀█░▀█▀░█░█░▀█▀░█░░░█▀▀  @@@@@@%
@@%*=-::::::::::::::::--===---=**%@@@@@@@@   ░█▀▄░█▀█░░█░░█▀█░░█░░█░█░░█░░█░░░█▀▀  +@@@@@%
@#=-:::::::::::::::::----=---=+*+@@@@@@@@@   ░▀░▀░▀░▀░░▀░░▀░▀░░▀░░▀▀▀░▀▀▀░▀▀▀░▀▀▀  *%@@@@%
+-::::::::::::::::::--==--:--+++*@@@@@@@@@@%                                      #*@@@@@%
--::::::::::::::::::-==+-::-++==#@@@@@@@@@@@@###%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###%@@@@@@%
:::::::::::::::::::--+*==--=+==-@@@@@@@@@@@@@@@@#**#%%%%%%%%%%%%%%%%%%%%%%%####%@@@@@@@@@%
::::::::::::::::::--+#*=-=+++=-=@@@@@@@%%@@@@@@@@@@@%##################%%#%@@@@@@@@@@@@@@%
::::::::::::::::---=%+++=+++=--#@@@@@%#*+=====+++++*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
-:::::::::::::::-==#**+=++++=--#@%#******++=--:--:::.:-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
--::-:::::::::---=##+++++====-=**#%###%####*+++=---:::::-@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
==-:::::::::---==*%#+++++==+#%%%%%%%%%%####****+==--::-:-+%@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
*+=---:::-----=++%%#+++*+#@@@@%%@@@@@@@@@@@%###***=---==*+*+*#@@@@@@@@@@@@@@@@@@@@@@@@@@@%
%#*+=-------==++#%#####%@@@@@@@@@@@@@@@@@@@%%%%%*++=--+**++==+==*%@@@@@@@@@@@@@@@@@@@@@@@%
+#%%#*+====++**##@@%%@@@@@%@@@@@@%#+=====+*%@%#*%%+=-=**+--=++=--::=+%@@@@@@@@@@@@@@@@@@@%
--=#%@%#*++**##%%@@@@@@@@@@@@@#+-::.........-*@%+#%+=*#**-:==++++++==-=%@@@@@@@@@@@@@@@@@%
%*=-:=+#%#%#%%%@@@@@@@@@@@@@#=:::.............:%%*##*****+==++*+++***+=-*@@@@@@@@@@@@@@@@%
@@%%*+-:-+*@@@@@@@@@@@@@@@#=::.................:@%%%*****+*%%%%%%%**+**=-*@@@@@@@@@@@@@@@%
@@@@@@%##**+#@@%@@@@@@@@@*-::...................+@@%*****%@%%%%%%####**+=-%@@@@@@@@@@@@@@%
@@@@@@@@###@@@@%*%@@@@@@*::......-*@@@@#=:......-@@#+*###@%@#+++*%@%#%#**==@@@@@@@@@@@@@@%
@@@@@@@@@@@#*#@%###%@@@#-:.....:*@@@@@@@@==.....=@%###*+%@#-......-+%@%%**=+@@@@@@@@@@@@@%
%@@@@@@@@@@@@*=+**+*%@@=::.....%@@@@@@@@@%@.....%@@@%#*#@#..........:#@@%*+-*@@@@@@@@@@@@%
#%%%%@@@@@@@%##+--=++##+-::....%@@@@@@@@@@@...:#@@@@#**#@-...........:*@@#*==%@@@@@@@@@@@%
%%###%%#####%%**++==++======-===**#####%%%*+*%##%%%%#++*%=++++-........#@%#*=#@@@@@@@@@@@#
@@@@@#*#%%%%#***####+=+++===-==+++*********#####%%%%#****%@@@@@@+......:@@%%#*@@@@@@%%%%#+
%%%@@@@%###%@@@%#***#+==+=-====++++****#####%%#%%%%%####***%@@@**+......=@%%#*##%%%%%%#**-
@@@%###@%%%%##%@@%%*+**+==+==++=+******+#####%%%%%%#####**++%@@@@%.......@%%%***###***+++=
@%%%%%#####*##**#####*+++++**=+**++*#####*#####%%%%##%###**++#%@@*.......%@@%#*********#*=
@@@@@@@#**++=**#@#**####*+*++++**#######****######%#####**++++==+........%@@%%#*****#**+=-
@@@@@@@@@@@@#++-:=+***##%#*+*****#####***#***+***%#######*++==++==-::..:-@@%#####*#*+===-:
@@@@@@@@@@@@@@@@@#*==+*+*####*###%%#%############*######*++=+====-===:::%@@%%%%%##*+==--::
@@@@@@@@@@@@@@@@@@@@@*+=+**####%%#%#%###%%@@%%#####*******++==----=----=#####%%##**+=--:::
@@@@@@@@@@@@@@@@@@@@%##%%#####%%%%%##%@@@@%****++======++**+=-:---:::--::::=++++*++=--::::
@@@@@@@@@@@@@@@@@@@@@@%#%%#%%%%%%%%%%@@@%#+++===---:::----==+-:::::::::::::::::+##+=--::::
@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%@@@@%*++===---:::::::::::---:::::::::::::-::::-==--::::
@@@@@@@@@@@@@@@@@@@@@@@@@%%%%@%%%%@@@@%+=======---:::::::::::::::-:::::::::-::::::---=--::
@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%@@@@+======-==---:::::::::::..::::::::::::-==========--:
@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%@@@*==-==+====-=-::::::::::....::::..::----+++**++++==--
#@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%@@@@@@+--=====+====--::::::::::...::::::::::-==++++**=====-
*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=----===++====--:::::::::...:::....::---===++*+=+===-
*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+::--=+++++++==---:-:::::...:::...::-=++*#%###%#**+++
+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-::-===++++=+==-----::::.:::..:.:::-=++*%%%%%@@%#**=
+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+::-==+=+==+===---::::.::::...:::-+**+**+*#%@@%%%#*
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=---======---::::::-:::::..:-=*##%%%%@@@@@%@%#*+
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+=--:---:::::.-==-:::::-=*%@@@@@@@@%%%%@@@@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*++=-===**==-:-==+*#@@@@@@%@#-::::-+%@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@###*+++=+*#@@@@@@@@@@*:::::::::@@@
+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%*####@@@@@@@@@@@@*::::::.::@@@
=@@@@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@%@@%%#%#%@@@@@@@@@@%%@@@@=::::::-*@@@
-@@@@@@@@@@@@@@@@@@@@@@@@+::-+#%@@@@@@@@@@@@@@@@@@@@@@%@%%@@@@@@@@@@@@##@@@@@@@#****#@@@@@
-@@@@@@@@@@@@@@@@@@@@@@@@+:::::::*=+**#%%%@@@@@@@@@@@@@@@@@@@@%%%#*#%%*##@@@@@@@@*=@@@@@@@
-@@@@@@@@@@@@@@@@@@@@@@@@#::::::--::::::-+@@@@@@@@@@@@@@@@@@%*+++++*#**%%%@@@@@@=::-@@@@@@
-@@@@@@@@@@@@@@@@@@@@@@@@@@%#+=-+:::::-+#@@@@@@@@@@@@@@@@%%#+=-=-==+#**@%@@@@@@-::::-*@@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%####*+----=-=*##*#%%@@@@-::.:-::=@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#**++++*+-::==++=#*#*%%%@@%-:::::::::=@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##*+===-==*=::-=+=+###**%%@%@@@@@@@@@@@@@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%##*+=++--=-++==-==++=#%##*#%@@@@@#***%##**@@@
=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%#++++==-+=:=+**--===-==#**#**##@@@@#=::::-++@@@
=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%##**+-==+-===+=*#*==-=-==+#*+*#%###%@@%*++-:+#@@@@

```
