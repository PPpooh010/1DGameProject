#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player2_movement.h"
#include "player_movement.h"
#include "gui.h"
#include "math.h"
#include <vector>

class Game
{
public:
	Game(sf::RenderWindow &window); // for init
	gui gui;
	void Update(sf::RenderWindow& window, sf::Event& event);
	void Draw(sf::RenderWindow &window);
	void Loop(sf::RenderWindow& window);


	sf::Clock BG_animation;
	int BGBG = 0;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture playerTexture;
	sf::Sprite  playerSprite;
	PlayerMovement  *playerMv1;

	sf::Texture player2Texture;
	sf::Sprite  player2Sprite;
	Player2Movement* playerMv2;
	

	sf::Texture skill_fire_1;
	sf::Sprite skill_fire;
	bool skill_fire_status;

	sf::Texture skill_fire_2;
	sf::Sprite skill_fire2;
	bool skill_fire2_status;

	int currentFrame;
	sf::Clock frameClock;
	sf::Time frameTime;

	int currentFrame2;
	sf::Clock frameClock2;
	sf::Time frameTime2;

	sf::Clock animationClock;
	sf::Clock testClock;
	sf::Clock animationClock2;
	sf::Clock testClock2;

	int mv1_current ;
	int mv2_current  ;

	int mv1_currentBullet;
	int mv2_currentBullet;

	sf::Clock skillCD;
	sf::Clock skillCD2;
	bool canUseSkill;
	bool canUseSkill2;

	bool isPlayer1Alive;
	bool isPlayer2Alive;

	sf::Clock player1Dead;
	sf::Clock player2Dead;
	int frame_py1D;
	int frame_py2D;

	bool item_drop; 
	bool start_item;
	int random_buff;
	int random_item;
	int position_x_random; 
	int currentframe_item ; 
	float position_y_item ;

	sf::Clock idle_item;

	sf::Clock CD_item_drop;
	sf::Clock start_item_end;

	sf::Sprite item1_sp;
	sf::Texture item1_tex;

	sf::Sprite item2_sp;
	sf::Texture item2_tex;

	sf::Sprite item3_sp;
	sf::Texture item3_tex;

	int pos_y;
	int pos_x;
	int luck_alive;
	sf::Sprite item_alive_sp;
	sf::Texture item_alive_tex;
	bool start_back_alive;
	bool open_item_alive;
	bool one_only_alive;
	bool canfly_P1 = true;
	bool canfly_P2 = true;

	//status-------------------------------------------------
	int point_1;
	int point_2;
	float player1HP;
	float player2HP;
	float player1Damage;
	float player2Damage;
	float Stamina_player1;
	float Stamina_player2;
	float jump_player1;
	float jump_player2;
	

	//skill2 
	sf::Sprite Skill2_fire_SP1;
	sf::Texture Skill2_fire_Tex1;
	float positionx_skill2_player1;
	float positiony_skill2_player1;
	bool open_skill2_P1;
	bool Press_K;
	bool use_skill_P1;
	sf::Clock animation_skill2_P1;
	int currentframe_skill2_P1;
	
	sf::Sprite Skill2_fire_SP2;
	sf::Texture Skill2_fire_Tex2;
	float positionx_skill2_player2;
	float positiony_skill2_player2;
	bool open_skill2_P2;
	bool Press_num2;
	bool use_skill_P2;
	sf::Clock animation_skill2_P2;
	int currentframe_skill2_P2;
	

	//ulti

	float scaleulti_up;
	sf::Clock CD_Ult1_1;
	sf::Clock scale_ult;
	sf::Clock animation1_ult;
	int current_frame1;
	bool Pressed_I;
	bool ult1_open1;
	sf::Texture Ult_1_Tex1;
	sf::Sprite Ult_1_SP1; 
	int pos_x1_ult;
	int pos_y1_ult;
	float scale_x1;
	float scale_y1;
	int current_P1;
	//**************************//
	sf::Clock CD_Ult1_2;
	sf::Clock scale2_ult;
	sf::Clock animation2_ult;
	int current_frame2;
	bool Pressed_numpad5;
	bool ult1_open2;
	sf::Texture Ult_1_Tex2;
	sf::Sprite Ult_1_SP2;
	int pos_x2_ult;
	int pos_y2_ult;
	int a_2;
	float scale_x2;
	float scale_y2;
	int current_P2;


	//BATMAN

	sf::Clock batman_move;
	sf::Clock batgo;
	sf::Sprite batman_sp;
	sf::Clock animation_batman;
	int current_batman;
	float batman_speed;
	sf::Vector2f direction;
	float scalex;
	float scaley;
	float scaleup;
	bool scaleup_on;
	int x_bat;
	int y_bat;
	int gohere_x;
	int gohere_y;
	sf::Texture batman_tex;
	bool batman_on;

	//black hole 
	sf::Clock CD_blackhole;
	sf::Clock start_blackhole;
	int ps_x_blackhole;
	int ps_y_blackhole;
	int ps_x1;
	int ps_y1;
	int ps_x2;
	int ps_y2;
	int down;
	bool blackhole_on;

	//Ultimate 
	float scale1_big;
	float scale2_big;


	// rain 
	sf::Sprite snow_sp;
	sf::Texture snow_tex;
	bool snow_on; 
	sf::Clock snow_time;
	int snow_posx;
	int snow_posy;
	sf::Clock snow_animation;
	int frame_snow;
	bool stun1_on;
	bool stun2_on;

	//sgow score 

	float score_player1;
	float score_player2;
	sf::Clock count_time;
	int total_damage1;
	int total_damage2;
	int time_now;



	//ulti scale big
	bool scale_player1_on;
	float scaleplayer1_up;
	sf::Clock scaleplayer1_clock;
	sf::Clock stmina1_drop_clock;
	float stamina1_drop;
	bool ultisclae1_use;


	bool scale_player2_on;
	float scaleplayer2_up;
	sf::Clock scaleplayer2_clock;
	sf::Clock stmina2_drop_clock;
	float stamina2_drop;
	bool ultisclae2_use;

};

