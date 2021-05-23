#include "SpeedAndFlipIndicatorPlugin.h"
#include "bakkesmod\wrappers\includes.h"
#include "utils/parser.h"
BAKKESMOD_PLUGIN(SpeedAndFlipIndicatorPlugin, "SpeedAndFlipIndicator plugin", "0.1", PLUGINTYPE_FREEPLAY | PLUGINTYPE_CUSTOM_TRAINING)
std::ofstream interaction_file;


void SpeedAndFlipIndicatorPlugin::onLoad()
{
	cvarManager->registerCvar("speedandflip_enabled", "1", "Enable or Disable the Speed and Flip Indicator Plugin", true, true, 0, true, 1, true);
	gameWrapper->RegisterDrawable(std::bind(&SpeedAndFlipIndicatorPlugin::Render, this, std::placeholders::_1));

}

void SpeedAndFlipIndicatorPlugin::onUnload()
{
}


void SpeedAndFlipIndicatorPlugin::Render(CanvasWrapper canvas)
{
	bool isEnabled = cvarManager->getCvar("speedandflip_enabled").getBoolValue();
	if (!isEnabled)
		return;
	if (!gameWrapper->IsInGame() )
		return;
	auto game = gameWrapper->GetGameEventAsServer();
	if (game.GetCars().Count() == 0)
		return;
	auto car = game.GetCars().Get(0);
	Vector speed_vect = car.GetRBState().LinearVelocity;

	float speed = sqrt(pow(speed_vect.X, 2) + pow(speed_vect.Y, 2) + pow(speed_vect.Z, 2));

	float kmh = (speed * 60 * 60) / 100000;
	std::string speedString;
	speedString = to_string_with_precision(kmh, 2) + " km/h";
	Vector2 screen = canvas.GetSize();
	float fontSize = (float)screen.X / (float)1500;
	canvas.SetColor(255, 255, 255, 255);
	canvas.SetPosition(Vector2{ int(screen.X * .8) , int(screen.Y * .1) });
	canvas.DrawString(speedString, 2 * fontSize, 2 * fontSize);
	canvas.SetPosition(Vector2{ int(screen.X * .8) , int(screen.Y * .15) });
	std::string flip_string;
	if (car.HasFlip()) {
		flip_string = "FLIP";
		canvas.SetColor(0, 255, 0, 255);
	}
	else {
		flip_string = "NO FLIP";
		canvas.SetColor(255, 0, 0, 255);
	}
	canvas.DrawString(flip_string, 2 * fontSize, 2 * fontSize);
}
