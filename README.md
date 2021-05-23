# SpeedAndFlipIndicatorPlugin
Rocket League BakkesMod plugin adds speedometer and flip indicator in freeplay and custom training.


Add your path to BakkesModSDK in environment variables as "BakkesModSDK"

Post build command copys .dll file to BakkesModSDK/plugins folder with "bakkes_patchplugin.py" script.

"bakkes_patchplugin.py" script needs one line modification, change example string to your BakkesMod plugin folder.


Once built, load in BakkesMod command terminal with 
-"plugin load SpeedAndFlipIndicatorPlugin"
-"speedandflip_enabled 1"


![Screenshot (1)](https://user-images.githubusercontent.com/37971619/119270524-087b8500-bbcb-11eb-8be1-e6d1fea44352.png)


Screenshot above shows what indicator will look like. Useful for practicing flip resets.
