# SpeedAndFlipIndicatorPlugin
Rocket League BakkesMod plugin adds speedometer and flip indicator in freeplay and custom training.


Add your path to BakkesModSDK in environment variables as "BakkesModSDK"

Post build command copys .dll file to BakkesModSDK/plugins folder with "bakkes_patchplugin.py" script.

"bakkes_patchplugin.py" script needs one line modification, change example string to your BakkesMod plugin folder.


Once built, load in BakkesMod command terminal with 
-"plugin load SpeedAndFlipIndicatorPlugin"
-"speedandflip_enabled 1"


