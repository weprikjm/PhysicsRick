#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

	float rick_head[76] = {
		0.948718f, 0.233333f,
		0.803419f, 0.260000f,
		0.743590f, 0.026667f,
		0.641026f, 0.213333f,
		0.350427f, 0.000000f,
		0.358974f, 0.106667f,
		0.358974f, 0.253333f,
		0.119658f, 0.233333f,
		0.247863f, 0.413333f,
		0.008547f, 0.500000f,
		0.239316f, 0.593333f,
		0.085470f, 0.680000f,
		0.256410f, 0.760000f,
		0.188034f, 0.820000f,
		0.333333f, 0.840000f,
		0.290598f, 0.906667f,
		0.384615f, 0.880000f,
		0.444444f, 0.940000f,
		0.512821f, 0.973333f,
		0.598291f, 0.986667f,
		0.675214f, 0.986667f,
		0.743590f, 0.966667f,
		0.786325f, 0.933333f,
		0.820513f, 0.886667f,
		0.846154f, 0.846667f,
		0.897436f, 0.806667f,
		0.854701f, 0.773333f,
		0.871795f, 0.733333f,
		0.888889f, 0.700000f,
		0.931624f, 0.666667f,
		0.897436f, 0.626667f,
		0.923077f, 0.593333f,
		0.931624f, 0.553333f,
		0.931624f, 0.493333f,
		0.991453f, 0.446667f,
		0.940171f, 0.420000f,
		0.888889f, 0.386667f,
		0.905983f, 0.346667f
	};
	rickPoints = new float[76];
	rickPoints = rick_head;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	delete[] rickPoints;
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 5: Move all creation of bodies on 1,2,3 key press here in the scene
	
	// TODO 7: Draw all the circles using "circle" texture

	return UPDATE_CONTINUE;
}
